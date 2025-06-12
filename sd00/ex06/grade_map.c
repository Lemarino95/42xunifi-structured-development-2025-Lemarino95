/*--------------------------------------------------\\
||         Written by: giusnob and lemarino         ||
||                                                  ||
||            Special thanks to: plichota           ||
\\--------------------------------------------------*/

#include "grade_map.h"

void plusminus_mapper(const int *scores, int size, const char **str)
{
	int i = 0;

	while (i < size)
	{
		if (scores[i] <= 59)
			str[i] = F1;
		else if (scores[i] <= 62)
			str[i] = D3;
		else if (scores[i] <= 66)
			str[i] = D2;
		else if (scores[i] <= 69)
			str[i] = D1;
		else if (scores[i] <= 72)
			str[i] = C3;
		else if (scores[i] <= 76)
			str[i] = C2;
		else if (scores[i] <= 79)
			str[i] = C1;
		else if (scores[i] <= 82)
			str[i] = B3;
		else if (scores[i] <= 86)
			str[i] = B2;
		else if (scores[i] <= 89)
			str[i] = B1;
		else if (scores[i] <= 92)
			str[i] = A3;
		else if (scores[i] <= 96)
			str[i] = A2;
		else if (scores[i] <= 100)
			str[i] = A1;
		i++;
	}
	str[i] = NULL;
}

void standard_mapper(const int *scores, int size, const char **str)
{int i = 0;

	while (i < size)
	{
		if (scores[i] <= 59)
			str[i] = F;
		else if (scores[i] <= 69)
			str[i] = D;
		else if (scores[i] <= 79)
			str[i] = C;
		else if (scores[i] <= 89)
			str[i] = B;
		else if (scores[i] <= 100)
			str[i] = A;
		i++;
	}
}

void passfail_mapper(const int *scores, int size, const char **str)
{
	int i = 0;

	while (i < size)
	{
		if (scores[i] <= 60)
			str[i] = FAILED;
		else
			str[i] = PASSED;
		i++;
	}
}

// A program that converts an array of integer scores into an array of grade strings
//  using a dynamic mapping strategy.
// Supports :
//  plusminus method (F to A+);
//  passfail method (P or F);
//  standard method (F to A);
void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades)
{
	if (mapper == PLUSMINUS)
		plusminus_mapper(scores, size, mapped_grades);
	else if (mapper == STANDARD)
		standard_mapper(scores, size, mapped_grades);
	else if (mapper == PASSFAIL)
		passfail_mapper(scores, size, mapped_grades);
}

/* int main()
{
	int scores[8] = {80, 25, 69, 73, 100, 74, 64, 95};
	int size = 8;
	const char **mapgrade = malloc((size + 1) * sizeof(char *));

	map_scores(scores, size, PLUSMINUS, mapgrade);
	for (int i = 0; i < size; i++)
	{
		printf(GREEN"points: %d, Grade: %s\n"NO_ALL, scores[i], mapgrade[i]);
	}
	map_scores(scores, size, STANDARD, mapgrade);
	for (int i = 0; i < size; i++)
	{
		printf("points: %d, Grade: %s\n", scores[i], mapgrade[i]);
	}
	map_scores(scores, size, PASSFAIL, mapgrade);
	for (int i = 0; i < size; i++)
	{
		printf(RED"points: %d, Grade: %s\n"NO_ALL, scores[i], mapgrade[i]);
	}
} */
