#ifndef RECIPE_H
#define RECIPE_H
#include <vector>
#include <string>

using namespace std;

class Recipe
{
public:
	vector<string> ingredients;
	string name;
	string instruction;
	int score;
	
	Recipe(string nam, vector<string> ingred, string instruct)
	{
		name = nam;
		//vector<string>::iterator it;
		//for(it = ingred.begin(); it != ingred.end(); it++)
		//{	ingredients.push_back(ingred.at(it)); }
		for(int i = 0; i < ingred.size(); i++)
			ingredients.push_back(ingred.at(i));
		instruction = instruct;
		score = 0;
	}
};

#endif