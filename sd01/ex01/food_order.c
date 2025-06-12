/*--------------------------------------------------\\
||                                                  ||
||         Written by: giusnob and lemarino         ||
||                                                  ||
\\--------------------------------------------------*/

#include "food_order.h"

static void delete_order(struct OrderRequest *request)
{
	free(request->order);
	free(request);
}

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

int main()
{
	OrderRequest	*request;

	request->order = "Panino sbrodolino";
	request->time_of_day = 12,30;

	printf("%d\n", process_food_order(request));

}