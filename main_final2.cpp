//
//  main.cpp
//  
//
//  Created by Melody Chang on 5/8/16.
//
//

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "recipe.h"
#include <ctype.h>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>

using namespace std;

Recipe findMax(vector<Recipe> &vec)
{
	int max = (vec.at(0)).score;	// set it equal to the first item
	
	
	for(int i = 0; i < vec.size(); i++)
	{
		if((vec.at(i)).score > max)
			max = (vec.at(i)).score;
	}
	// printf ("line: %d\n",__LINE__);
	
	for(int i=0; i < vec.size(); i++)
	{
		if((vec.at(i)).score == max)
        {
            vec.at(i).score = 0;
            return(vec.at(i));
        }
	}
	return(vec.at(0));
}

void print(Recipe rep)
{
    cout << "============================================" << endl;
	cout << rep.name << endl;
	cout << endl;
	//cout << "Score: " << rep.score << endl;
	cout << "Ingredients:" << endl;
	//int i;
	//cout << rep.ingredients[0] << endl;
	for(int i = 0; i < (rep.ingredients).size(); i++)
	{	cout << " - " << rep.ingredients[i] << endl;	}
	cout << endl;
      //           printf ("line: %d\n",__LINE__);
	
	cout << "Procedure: "<< endl;
	cout << rep.instruction << endl;
	
	//cout<< "YOU HAVE TO EAT THIS. NO OTHER CHOICE. OR YOU DIE." << endl;

}

bool search(string ingredient, vector<string> userIn)
{
	bool included = 0;
	vector<string>::iterator it;
	for(int i = 0; i < userIn.size() && !included; i++)
	{

    //     printf ("line: %d\n",__LINE__);

		if(ingredient == userIn.at(i))
			return(included=1);
		//included = strcmp(ingredient, userIn.at(i));
		}
		return(included);
		}

int setScore(Recipe rep, vector<string> userIngred)
{
	vector<string>::iterator it;
	int score = 0;
	
	for(int i = 0; i < (rep.ingredients).size(); i++)
	{
		if(search(rep.ingredients[i], userIngred))
			score += 10;
                
  //       printf ("line: %d\n",__LINE__);

	}
	return score;
}

int main () {

//Recipe best(NULL, NULL, NULL);	// the best recipe aka highest score 
vector<Recipe> recipeList; // vector of all the recipes inside the file
vector<string> userIngredients;
vector<string> recipeIngredients; 

ifstream data("Cheese2.tsv");   
string line;
 while (getline(data,line)) {
   // ifstream data("test.csv");
   // string line;
   // getline(data, line);
    
  // cout >> getline(data,line) >> endl;
    int pos;
    pos = line.find("\t");
	//cout << "HIHIHIHI" << endl;
    string left = line.substr(0, pos);
    string right = line.substr(pos+1);
//    cout << "left: " << left << endl;


    int pos2;
    pos2 = right.find("\t");
    string middle = right.substr(0,pos2);
    
    string last = right.substr(pos2+1);

    int pos3;
    pos3 = middle.find(",");
        // printf ("line: %d\n",__LINE__);
    
    string ingredient;
    string leftover = middle;
    //printf("hi %d\n", __LINE__);
    int count=0;

    for (int i = 0; i < middle.length(); i++) {
    	if (middle[i]== ',')
    		count++;  
	}

   //pos3 = leftover.find(",");  
 
   for (int j = 0; j<=count; j++){
  	 pos3 = leftover.find(",");
   	ingredient = leftover.substr(0, pos3);
        recipeIngredients.push_back(ingredient);
   //	cout << ingredient << endl;
   	leftover = leftover.substr(pos3+1);
   //	cout << "leftover " << leftover << endl;
   
   if (pos3 == -1)
   break; 
        // printf ("line: %d\n",__LINE__);

   //cout << pos3 << endl;
   } 
 // cout << left << middle << last << endl; 
      
   /* while (leftover.find(",")){
    ingredient = leftover.substr(temp,pos3);
    cout << ingredient << "yay" << endl;
    leftover = leftover.substr(pos3+1);
    temp = pos3+1;
    pos3 = leftover.find(",");
    } 
    printf("hi %d\n", __LINE__);
    cout << left << "," << middle <<"," << last<< "\n";
   }
*/
   Recipe temp(left, recipeIngredients, last); 
   recipeList.push_back(temp);
   //cout << recipeList.size() << endl;
   //cout << left << last << endl;
        // printf ("line: %d\n",__LINE__);
    recipeIngredients.clear();
   
    }
    
   /* while (result!=NULL) {
        result = line.rfind( "\t");
        cout << result << "\n";
    }*/
   string userInput;
    cout << endl;
   cout << "Please enter ingredients (type done when done!):" << "\n";

while(userInput != "done"){
	cin >> userInput;
	if(userInput == "done")
		break;
	userIngredients.push_back(userInput);
         //printf ("line: %d\n",__LINE__);

	}
    cout << endl;
cout << "@@@ % $ / Calculating... boop beep boop @@@" << "\n\n";

	/*cout << "These are the ingredients you listed: "<< endl;
	for(int k = 0; k < userIngredients.size(); k++)
		cout << "  " << userIngredients.at(k) << endl;
	cout <<endl;
        // printf ("line: %d\n",__LINE__);
//cout << recipeList.size() << endl;*/

for(int i = 0; i < recipeList.size(); i++)
	{
        // printf ("line: %d\n",__LINE__);
	
       (recipeList[i]).score = setScore(recipeList[i], userIngredients);
//	cout << i <<". Score: " << recipeList[i].score << endl;
       
}

	Recipe best = findMax(recipeList);
    cout << "1.";
	print(best);
    cout << "\n";
    best.score = 0;
    
   // std::nth_element(recipeList.begin(), recipeList.begin()+1, recipeList.end(), true);

    best = findMax(recipeList);
    cout << "2.";
    print(best);
    cout << "\n";
    best.score = 0;
    
    best = findMax(recipeList);
    cout << "3.";
    print(best);
    cout << "\n";
    best.score = 0;
    
	return 0;

}
