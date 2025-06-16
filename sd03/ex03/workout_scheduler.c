/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "workout_scheduler.h"

// Schedules a workout plan based on the user's data and needs,
//  in form of a linked list
struct WorkoutPlan *create_workout_schedule(char *username)
{
	struct	WorkoutPlan	*plan;
	struct	UserData	*data;
	int		duration = 0;
	int		day = 0;

	data = get_user_data(username);
	if (!data)
		return (NULL);

	plan = define_plan(data);
	if (!plan)
		return (NULL);

	duration = determine_duration(plan);
	if (duration <= 0)
	{
		free_user_data(data);
		free_workout_plan(plan);
		return (NULL);
	}

	while (day < duration)
	{
		assign_daily_exercises(plan, day);
		assign_daily_tips(plan, day);
		day++;
	}

	free_user_data(data);
	return (plan);
}
