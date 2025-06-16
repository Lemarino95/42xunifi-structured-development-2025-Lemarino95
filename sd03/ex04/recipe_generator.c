/*--------------------------------------------------\\
||                                                  ||
||         Written by: lemarino                     ||
||                                                  ||
\\--------------------------------------------------*/

#include "recipe_generator.h"


struct Recipe *recipe_creator(struct Ingredients *ingredients, struct TasteProfile *taste)
{
	struct Recipe	*recipe;

	ingredients = get_current_ingredients();
	if (!ingredients)
		return (NULL);

	taste = get_user_taste_profile();
	if (!taste)
	{
		free_ingredients(ingredients);
		return (NULL);
	}

	recipe = create_recipe(ingredients, taste);
	if(!recipe)
	{
		free_ingredients(ingredients);
		free_taste_profile(taste);
		return (NULL);
	}

	return (recipe);
}

// You are building an interactive recipe generator that creates recipes based on the user’s
// current ingredients and taste profile, repeating the generation process until the user ap-
// proves the result. The program should:
// 1. Fetch the current fridge ingredients.
// 2. Fetch the user’s taste profile.
// 3. Iteratively generate a recipe candidate:
// • Produce a new recipe.
// • Ask for user approval.
// • Repeat until approved.
// 4. Return the final approved recipe.
struct Recipe *create_custom_recipe(void)
{
	struct Ingredients	*ingredients = NULL;
	struct TasteProfile	*taste = NULL;
	struct Recipe		*recipe = NULL;

	recipe = recipe_creator(ingredients, taste);
	while (recipe == NULL || get_user_approval(recipe) == 0)
	{
		free_ingredients(ingredients);
		free_taste_profile(taste);
		free_recipe(recipe);
		recipe = recipe_creator(ingredients, taste);
	}

	free_ingredients(ingredients);
	free_taste_profile(taste);
	return (recipe);
}
