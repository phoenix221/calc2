#include <iostream>
using namespace std;

float bukvi()
{
    int res = 0;
    for(;;)
    {
        char str = cin.get();
        if(str >= 'a' && str <= 'z')
            cout << "neverniy vvod!" << endl;
        else{
            cin.putback(str);
            return res;
        }
    }

}

float number()
{
	float x = bukvi();
	int res = 0;
	for(;;)
	{
		char str = cin.get();
		if (str >= '0' && str <= '9')
			res = res * 10 + str - '0';
		else
		{
			cin.putback(str);
			return res;
		}
	}
}

float expr();

float skobki()
{
	char str = cin.get();
	if(str == '(')
	{
		float x = expr();
		cin.get();
		return x;
	}
	else
	{
		cin.putback(str);
		return number();
	}
}

float factor()
{
	float x = skobki();
	for(;;)
	{
		char str = cin.get();
		switch(str)
		{
			case '*':
				x*= skobki();
				break;
			case '/':
				x/= skobki();
				break;
			default:
				cin.putback(str);
				return x;
		}
	}
}

float expr()
{
	float x = factor();
	for(;;)
	{
		char str = cin.get();
		switch(str)
		{
			case '+':
				x+= factor();
				break;
			case '-':
				x-= factor();
				break;
			default:
				cin.putback(str);
				return x;
		}
	}
}

int main()
{
	cout << "Vvediti virajenie: ";
	float res = expr();
	cout << "Result: " << res << endl;
}
