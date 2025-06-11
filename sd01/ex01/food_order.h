#ifndef FOOD_ORDER_H
# define FOOD_ORDER_H

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

# define STANDARD "Your food will be ready soon!"
# define PREORDER "Your food will be ready tomonorrow!"
# define FAILURE  "We couldn't process your order, please try again later."

typedef struct	OrderRequest
{
	char	*order;
	float	time_of_day;
}
				OrderRequest;

typedef struct	OrderConfirmation
{
	char	*confirmation_message;
}
				OrderConfirmation;


// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(struct OrderRequest *request);

// Creates a confirmation for an immediate order. Returns NULL on failure.
struct OrderConfirmation *create_standard_confirmation(void);

// Creates a confirmation for a future (pre-order). Returns NULL on failure.
struct OrderConfirmation *create_preorder_confirmation(void);

// Sends the confirmation to the user.
void send_confirmation_notification(struct OrderConfirmation *confirmation);


int process_food_order(struct OrderRequest *request);

#endif