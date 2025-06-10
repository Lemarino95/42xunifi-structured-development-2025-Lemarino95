#ifndef PASSWORD_VALIDATOR_H
# define PASSWORD_VALIDATOR_H

#include <stdio.h>
#include <stdbool.h>

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

typedef struct	pwstatus
{
	bool		validity;
}				PwStatus;

#endif
