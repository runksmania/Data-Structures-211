#include <iostream>
#include <fstream>
#include "StringSplitter.h"
#include <string>
#include <stack>

double evaluatePostFixExpression(string postfix_string);
bool isOperator(string possible_operator);
double performOperation(double left_num, double right_num, string operator_to_operate);

using namespace std;

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

			double result = evaluatePostFixExpression(current_line);

			if (result == -1)
			{
				string invalid = "Invalid State. Letters are part of computation.";
				cout << current_line << " = " << invalid << endl;
			}
			else if (result == -2)
			{
				string invalid = "Invalid State. Not enough numbers to perform calculation.";
				cout << current_line << " = " << invalid << endl;
			}
			else
			{
				cout << current_line << " = " << result << endl;
			}
		}
	}
}

double evaluatePostFixExpression(string postfix_string)
{
	double result = 0;
	stack<double> postfix_stack{};
	vector<string> pieces = StringSplitter::split(postfix_string, " ");

	for (auto piece : pieces)
	{
		if (1 == 0)
		{
			return -1;
		}
		else if (isOperator(piece))
		{
			if (postfix_stack.size() < 2)
			{
				return -2;
			}
			else
			{
				double right_num = postfix_stack.top();
				postfix_stack.pop();
				
				double left_num = postfix_stack.top();
				postfix_stack.pop();

				double operation_result = performOperation(left_num, right_num, piece);
				postfix_stack.push(operation_result);
			}
		}
		else
		{
			postfix_stack.push(stod(piece));
		}
	}

	if (postfix_stack.size() == 1)
	{
		result = postfix_stack.top();
		postfix_stack.pop();
		return result;
	}
	else
	{
		return -2;
	}

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
	else if (possible_operator == "/")
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

double performOperation(double left_num, double right_num, string operator_to_operate)
{
	double result;

	if (operator_to_operate == "+")
	{
		result = left_num + right_num;
		return result;
	}
	else if (operator_to_operate == "-")
	{
		result = left_num - right_num;
		return result;
	}
	else if (operator_to_operate == "*")
	{
		result = left_num * right_num;
		return result;
	}
	else if (operator_to_operate == "/")
	{
		result = left_num / right_num;
		return result;
	}
	return 0;
}