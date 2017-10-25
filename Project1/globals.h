#ifndef __GLOBALS__
#define __GLOBALS__

#include <string>
#include <vector>
using namespace std;

//Functions
void UpdateInput(string &intputLine, bool &isEndLine);
void Tokenize(const string& line, vector<string>& tokens);
//Variables
#define SCREEN_WIDTH 384


#endif