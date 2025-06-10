#include "password_validator.h"

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
{}
