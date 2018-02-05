#include <iostream>
#include <fstream>
#include "StringSplitter.h"
#include <string>
#include <stack>

using namespace std;

bool isOperator(string possible_operator);
double evaluatePostFixExpression(string postfix_string);

int main(void) 
{
	//prompt user for file to open
	string file_to_open;
	cout << "Enter file name: ";
	getline(cin, file_to_open);

	//open the file
	ifstream input_file{ file_to_open };

	//safety checking
	if (input_file.is_open()) 
	{
		//read from the file as long as more content is available
		while(input_file.good())
		{
			string current_line;
			getline(input_file, current_line);
			//vector<string> pieces = StringSplitter::split(current_line, " ");
			double result = evaluatePostFixExpression(current_line);
			cout << current_line << " = " << result << endl;
		}
	}
}

double evaluatePostFixExpression(string postfix_string)
{
	double result = -1;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");

	//TODO: evaluate pieces as a postfix expression.
	for (auto piece : pieces)
	{
		double right_num;
		double left_num;

		if (isOperator(piece))
		{
			right_num = postfix_stack.top();
			left_num = postfix_stack.top();
		}
		else
		{
			postfix_stack.push(stod(piece));
		}
	}

	/*while (postfix_stack.empty() == false)
	{
	//in STL, we use top() to get the top item, pop() returns nothing
	cout << postfix_stack.top();

	//pop is only used to remove the top-most item from the stack
	postfix_stack.pop();
	}*/

	return result;
}

bool isOperator(string possible_operator)
{
	bool is_operator = false;

	if (possible_operator == "+")
	{
		is_operator = true;
		return is_operator;
	}
	else if (possible_operator == "-")
	{
		is_operator = true;
		return is_operator;
	}
	else if (possible_operator == "*")
	{
		is_operator = true;
		return is_operator;
	}
	if (possible_operator == "/")
	{
		is_operator = true;
		return is_operator;
	}
	else
	{
		is_operator = false;
		return is_operator;
	}
}