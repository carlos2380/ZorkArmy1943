#ifndef __GLOBALS__
#define __GLOBALS__

#include <string>
#include <vector>
using namespace std;

//Functions
void UpdateInput(string &intputLine, bool &isEndLine);
void Tokenize(const string& line, vector<string>& tokens);
int RandomNumber(int max, int min);
//Variables
#define SCREEN_WIDTH 384

//Sentences
static string FOREST = "forest";
#endif