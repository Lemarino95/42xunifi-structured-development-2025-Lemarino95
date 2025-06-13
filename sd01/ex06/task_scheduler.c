/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "task_scheduler.h"


// A simulated task scheduler for a multicore CPU system.
struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile		*profile;
	struct PriorityMap		*priorities;
	struct ScheduleResult	*result;
	int						cores_count;
	int						best_taskID;

	profile = profile_tasks(tasks);
	if (!tasks)
		return (NULL);

	priorities = compute_priorities_mock(profile);
	if (!priorities)
	{
		free_task_profile(profile);
		return (NULL);
	}

	cores_count = get_available_core_count();
	result = create_schedule_result(cores_count);
	if (!result)
	{
		free_task_profile(profile);
		free_priority_map(priorities);
		return (NULL);
	}

	int coreID = 0;
	while (coreID < cores_count)
	{
		best_taskID = select_best_task_for_current_priorities(profile, priorities);
		if (best_taskID < 0)
			update_schedule_entry(result, coreID, best_taskID);
		coreID++;
	}

	free_task_profile(profile);
	free_priority_map(priorities);
	return (result);
}

