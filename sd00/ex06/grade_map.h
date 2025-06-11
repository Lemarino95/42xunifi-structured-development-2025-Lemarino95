#ifndef GRADE_MAP_H
# define GRADE_MAP_H

#include <stdio.h>
#include <stdlib.h>

# define NO_ALL "\033[0m"
# define NO_COLOR "\e[39m"
# define BLACK "\e[30m"
# define RED "\033[31m"
# define GREEN "\e[32m"
# define BRGREEN "\033[32;1m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[95m"
# define BRCYAN "\033[96m"

//__________________________ plusminus mapper __________________________//
# define A1 "A+"	//97~100
# define A2 "A"		//93~96
# define A3 "A-"	//90~92
# define B1 "B+" 	//87~89
# define B2 "B" 	//83~86
# define B3 "B-"	//80~82
# define C1 "C+"	//77~79
# define C2 "C" 	//73~76
# define C3 "C-"	//70~72
# define D1 "D+"	//67~69
# define D2 "D"		//63~66
# define D3 "D-"	//60~62
# define F1 "F" 	//0~59
//______________________________________________________________________//

//__________________________ standard mapper __________________________//
# define A "A" 		//90~100
# define B "B" 		//80~89
# define C "C" 		//70~79
# define D "D" 		//60~69
# define F "F" 		//0~59
//______________________________________________________________________//

//___________________________ passfail mapper __________________________//
# define PASSED "P" //60~100
# define FAILED "F" //0~60
//______________________________________________________________________//


typedef enum	mapper
{
	PLUSMINUS,
	PASSFAIL,
	STANDARD
}				GradeMapper;


void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
