#include<iostream>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
#include<cassert>

using namespace std;

bool isValid(string infix)
{
	int ocount = 0, ecount=0;
	bool ans = true;
	for (size_t i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			ocount++;
		}
		if (infix[i] == ')')
		{
			ecount++;
		}

	}
	if (ecount != ocount)
	{
		ans = false;
	}

	for (size_t i = 0; i < infix.size(); i++)
	{
		if (infix[i] == 'T' || infix[i] == 'F')
		{
			if (infix[i + 1] != '|' && infix[i + 1] != '&' && infix[i + 1] != ')')
			{
				ans = false;
			}
		}
		if (infix[i] == '&' || infix[i] == '!' || infix[i] == '|')
		{
			if (!(infix[i + 1] != 'T'&&infix[i + 1] != 'F'&&infix[i + 1] != '('))
			{
				ans = false;
			}
		}
		if (infix[i] == '(')
		{
			if (infix[i + 1] != 'T' && infix[i + 1]!='F')
			{
				ans = false;
			}
		}
	}
	return ans;
}

bool count(string postfix)
{
	stack<bool> o_stack;

	for (size_t i = 0; i < postfix.size(); i++)
	{
		if (postfix[i] == 't' || postfix[i] == 'T' || postfix[i] == 'f' || postfix[i] == 'F')
		{
			if (postfix[i] == 't' || postfix[i] == 'T')
			{
				o_stack.push(true);
			}
			else
			{
				o_stack.push(false);
			}
		}
		else
		{
			bool op2 = o_stack.top();
			o_stack.pop();
			bool op1 = o_stack.top();
			o_stack.pop();

			if (postfix[i] == '|')
			{
				o_stack.push(op1 || op2);
			}
			if (postfix[i] == '&')
			{
				o_stack.push(op1&&op2);
			}
			if (postfix[i] == '!')
			{
				o_stack.push(!op1);
			}
		}
	}

	return o_stack.top();
}

int evaluate(string infix, string& postfix, bool& result)
{
	int ans;
	if (isValid(infix))
	{
		int m_or = 1, m_and = 2, m_not = 3;
		int m_curr;
		postfix = "";
		stack<char> m_op;
		for (size_t i = 0; i < infix.size(); i++)
		{
			m_curr = 0;
			if (infix[i] == '!' || infix[i] == '&' || infix[i] == '|')
			{
				if (infix[i] == '!')
				{
					m_curr = m_not;
				}
				if (infix[i] == '&')
				{
					m_curr = m_and;
				}
				else
				{
					m_curr = m_or;
				}
			}

			char ch = infix[i];

			switch (ch)
			{
			case 't':
			case 'T':
			case 'f':
			case 'F':
				postfix += ch;
				break;

			case '(':
				m_op.push(ch);
				break;

			case ')':
				while ((!m_op.empty()) && (m_op.top() != '('))
				{
					postfix += m_op.top();
					m_op.pop();
				}
				m_op.pop();
				break;

			case '|':
			case '&':
				int m_top;
				if (infix[i] == '|')
				{
					m_top = m_or;
				}
				else
				{
					m_top = m_and;
				}
				while ((!m_op.empty()) && (m_op.top() != '(') && (m_curr <= m_top))
				{
					postfix += m_op.top();
					m_op.pop();
				}
				m_op.push(ch);
				break;

			default:
				break;
			}
		}
		while (!m_op.empty())
		{
			postfix += m_op.top();
			m_op.pop();
		}

		result = count(postfix);
		ans = 0;
	}
	else
	{
		ans = 1;
	}

	return ans;

}

int main()
{
	string pf;
	bool answer;
	assert(evaluate("T| F", pf, answer) == 0 && pf == "TF|"  &&  answer);
	assert(evaluate("T|", pf, answer) == 1);
	//assert(evaluate("F F", pf, answer) == 1);
	//assert(evaluate("TF", pf, answer) == 1);
	//assert(evaluate("()", pf, answer) == 1);
	//assert(evaluate("T(F|T)", pf, answer) == 1);
	//assert(evaluate("T(&T)", pf, answer) == 1);
	//assert(evaluate("(T&(F|F)", pf, answer) == 1);
	//assert(evaluate("", pf, answer) == 1);
	//assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
		//&& pf == "FF!TF&&|"  &&  !answer);
	//assert(evaluate(" F  ", pf, answer) == 0 && pf == "F"  &&  !answer);
	//assert(evaluate("((T))", pf, answer) == 0 && pf == "T"  &&  answer);
	cout << "Passed all tests" << endl;
}