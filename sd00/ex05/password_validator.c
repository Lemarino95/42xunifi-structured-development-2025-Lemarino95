//         Written by: giusnob and lemarino

#include "password_validator.h"

// Verifies that the new password is long at least 8 characters long.
static bool pw_len (const char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
		if (i >= 8)
			return (1);
	}
	return (0);
}

// Verifies that the new password has at least one low case letter.
static bool	ft_haslowcase(const char *new_pw)
{
	int	i = 0;

	while (new_pw[i])
	{
		if ((new_pw[i] >= 'a' && new_pw[i] <= 'z'))
			return (1);
		i++;
	}
	return (0);
}

// Verifies that the new password has at least one up case letter.
static bool	ft_hasupcase(const char *new_pw)
{
	int	i = 0;

	while (new_pw[i])
	{
		if ((new_pw[i] >= 'A' && new_pw[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

// Verifies that the new password has at least one digit.
static bool	ft_hasdigit(const char *new_pw)
{
	int	i = 0;

	while (new_pw[i])
	{
		if ((new_pw[i] >= '0' && new_pw[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

// Verifies wether the new password cointans at least one
//  special character (@, #, $, %, ^, &, *)
static bool	ft_hasspecialc(const char *new_pw)
{
	int	i = 0;

	while (new_pw[i])
	{
		if ((new_pw[i] >= '#' && new_pw[i] <= '&') || \
								new_pw[i] == '*' || \
								new_pw[i] == '@' || \
								new_pw[i] == '^')
			return (1);
		i++;
	}
	return (0);
}

// Compares the new and old passwords.
//  Returns 0 if they are equal.
bool	pw_cmp(const char *new_pw, const char *old_pw)
{
	size_t	i;

	i = 0;
	while (new_pw[i] && old_pw[i])
	{
		if ((unsigned char)new_pw[i] - (unsigned char)old_pw[i] != 0)
			return (1);
		else
			i++;
	}
	return ((unsigned char)new_pw[i] - (unsigned char)old_pw[i]);
}

// Implement a password validation system that enforces the following strength rules for a
// new password:
// • At least 8 characters long
// • At least one uppercase letter
// • At least one lowercase letter
// • At least one digit
// • At least one special character (@#$%ˆ&*)
// • Must differ from current password
// The validation function returns one of two states:
// • ‘0 = VALID‘
// • ‘1 = INVALID‘ (fails any of the rules above)
PwStatus validate_password(const char *new_pw, const char *curr_pw)
{
	if (pw_len(new_pw) && ft_haslowcase(new_pw) &&  \
				ft_hasupcase(new_pw) && ft_hasdigit(new_pw) && \
				ft_hasspecialc(new_pw) && pw_cmp(new_pw, curr_pw))
		{
			return (VALID);
		}
	else
		return (INVALID);
}

/* int main()
{
	const char *old_pw = "Radyk7a3";
	const char *new_pw = "eGokuf9@";

	printf(BRCYAN"Pw status: %d\n"NO_ALL, validate_password(new_pw, old_pw));
} */