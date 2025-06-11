#include "food_order.h"

// Checks if the restaurant is open based on the order. Returns 1 if open, 0 if closed.
int check_restaurant_status(struct OrderRequest *request)
{
	if ((request->time_of_day >=12,00 && request->time_of_day <= 15,00) || \
		(request->time_of_day >=20,00 && request->time_of_day <= 23,00))
		return (1);
	else
		return (0);
}

// Creates a confirmation for an immediate order. Returns NULL on failure.
struct OrderConfirmation *create_standard_confirmation(void)
{
	OrderConfirmation *confirmation;

	confirmation->confirmation_message = STANDARD;
	return (confirmation);
}

// Creates a confirmation for a future (pre-order). Returns NULL on failure.
struct OrderConfirmation *create_preorder_confirmation(void)
{
	OrderConfirmation *confirmation;

	confirmation->confirmation_message = PREORDER;
	return (confirmation);
}

// Sends the confirmation to the user.
void send_confirmation_notification(struct OrderConfirmation *confirmation)
{
	OrderConfirmation *confirmation;
}


int process_food_order(struct OrderRequest *request)
{
	OrderConfirmation *confirmation = NULL;

	if (check_restaurant_status(request))
		confirmation = create_standard_confirmation();
	else
		confirmation = create_preorder_confirmation();

	send_confirmation_notification(confirmation);

	if (confirmation != NULL)
		return (1);
	else
		return (0);
}

int main()
{
	OrderRequest	*request;

	request->order = "Panino sbrodolino";
	request->time_of_day = 12,30;

	if (process_food_order(request))
	{}
}