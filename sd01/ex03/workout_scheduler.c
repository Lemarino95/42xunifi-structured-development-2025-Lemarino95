/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "workout_scheduler.h"


static WorkoutPlan	*define_plan(struct UserData *data)
{
	WorkoutPlan	*plan;

	plan = build_base_plan(data);
	if (!plan)
	{
		free_user_data(data);
		return (NULL);
	}
	if (data->injury != NO_INJURY && data->preference != NO_PREF)
	{
		if (!refine_plan(plan, data))
		{
			free_user_data(data);
			return (NULL);
		}
	}

	return (plan);
}

// Schedules a workout plan based on the user's data and needs,
//  in form of a linked list
struct WorkoutPlan *create_workout_schedule(char *username)
{
	WorkoutPlan	*plan;
	UserData	*data;
	int			day = 0;

	data = get_user_data(username);
	if (!data)
		return (NULL);

	plan = define_plan(data);
	if (!plan)
		return (NULL);

	plan->duration = determine_duration(plan);
	if (plan->duration <= 0)
	{
		free_user_data(data);
		free_workout_plan(plan);
		return (NULL);
	}

	WorkoutPlan	*current = plan;
	while (day <= plan->duration)
	{
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
		current = current->next_day;
	}

	free_user_data(data);
	return (plan);
}
