/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "food_order.h"

static void delete_order(struct OrderRequest *request)
{
	free(request->order);
	free(request);
}

// Automated processor of restaurant orders.
// Fills a standard request during working hours,
//  otherwise a preorder.
// On completion, sends a notification to the user.
int process_food_order(struct OrderRequest *request)
{
	OrderConfirmation *confirmation = NULL;

	if (!request)
		return (0);

	if (check_restaurant_status(request))
		confirmation = create_standard_confirmation();
	else
		confirmation = create_preorder_confirmation();

	if (confirmation != NULL)
	{
		delete_order(request);
		return (0);
	}
	send_confirmation_notification(confirmation);

	return (1);
}
