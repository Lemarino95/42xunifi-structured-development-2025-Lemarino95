/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#ifndef WORKOUT_SCHEDULER_H
# define WORKOUT_SCHEDULER_H

#include <stdlib.h>

typedef enum	Preference
{
	NO_PREF,
	CARDIO,
	POWERLIFT,
	BODYBUILDING,
	WEIGHT_LOSS,
	BOXING,
	KICKBOXING
}				Preference;

typedef enum	Injury
{
	NO_INJURY,
	NECK_INJURY,
	SHOULDER_INJURY,
	ARM_INJURY,
	ELBOW_INJURY,
	HAND_INJURY,
	HIPS_INJURY,
	LEG_INJURY,
	KNEE_INJURY,
	FOOT_INJURY
}				Injury;

typedef struct	UserData
{
	int			age;
	int			weight;// kg
	int			height;// cm
	float		bmi;//    Body Mass Index
	Preference	preference;
	Injury		injury;
} 				UserData;

typedef struct	WorkoutPlan
{
	char		**exercises;
	int			sets;
	int			repetitions;
	int			duration;
	struct WorkoutPlan *next_day;
}				WorkoutPlan;


// Returns a new UserData (mocked). Returns NULL on failure.
struct UserData *get_user_data(char *username);

// Build a base WorkoutPlan from raw user data. Returns NULL on failure.
struct WorkoutPlan *build_base_plan(struct UserData *data);

// Optionally refine an existing plan. Returns the same pointer (or a new one) or NULL on failure.
struct WorkoutPlan *refine_plan(struct WorkoutPlan *plan, struct UserData *data);

// Determine how many days the workout schedule should span. Returns positive int, or <=0 on failure.
int determine_duration(struct WorkoutPlan *plan);

// Assign daily exercises for the next day into the plan.
void assign_daily_exercises(struct WorkoutPlan *plan, int day);

// Assign daily tips for the next day into the plan.
void assign_daily_tips(struct WorkoutPlan *plan, int day);

// Free functions for cleanup.
void free_user_data(struct UserData *data);
void free_workout_plan(struct WorkoutPlan *plan);

// Schedules a workout plan based on the user's data and needs,
//  in form of a linked list
struct WorkoutPlan *create_workout_schedule(char *username);

#endif