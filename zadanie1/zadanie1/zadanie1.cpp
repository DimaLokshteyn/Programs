#include "stdafx.h"
#include <iostream>
#include <functional>

using namespace std;
/////////////////////////////////////////////////////////////
int f(int n)
{
	if (n == 1) return 1;
	else return f(n - 1)*n;

}
int fib(int n)
{
	if (n <= 2) return 1;
	else return fib(n - 2)+fib(n - 1);
}
int fib_fast(int n)
{
	int a=1, b=1, r;
	if (n <= 2)
		return 1;
	else
	{
		for (int i = 3; i <= n; i++)
		{
			r = a + b;
			a = b;
			b = r;
		}
		return r;
	}
}
int fib3(int n)
{
	int *a;
	a = new int[n + 1];
	a[1] = 1; a[2] = 1;
	for (int i = 3; i <= n; i++)
		a[i] = a[i - 2] + a[i - 1];
	return a[n];
}
int fib4(int n)
{
	int *a;
		a = new int[n + 2];
		a[1] = 1;
		for (int i = 2; i <= n; i++)
			a[i] = 0;
		for (int i = 1; i < n; i++)
		{
			a[i + 1] = a[i + 1] + a[i];
			a[i + 2] = a[i + 2] + a[i];
		}
		return a[n];
}
int memrecfib(int n)
{
	static int a[100];
	static int f = 0;
	if (f == 0)
	{
		a[1] = 1;
		a[2] = 1;
		for (int i = 3; i <= 100; i++)
			a[i] = 0;
		f = 1;
	}
	if (a[n]==0)
	a[n] = memrecfib(n - 2) + memrecfib(n - 1);
	return a[n];
};
int memrecfact(int n)
{
	static int a[100];
	static int f = 0;
	if (f == 0)
	{
		a[0] = 1;
		a[1] = 1;

		for (int i = 2; i <= 100; i++)
			a[i] = 0;
		f = 1;
	}
	if (a[n] == 0)
		a[n] = memrecfact(n - 1)*n;
	return a[n];
}
int sigma(int m, int n, int(*pf)(int))
{
	int s = 0;
	for (int i = m; i <= n; i++)
		s = s + pf(i);
	return s;
}
/////////////////////////////////////////////////////////////
int trib(int n)
{
		int a = 1, b = 1, c = 2, r;
		if (n <= 2)
			return 1;
		else if (n == 3)	
			return 2;
		else
		{
				for (int i = 4; i <= n; i++)
				{
					r = a + b + c;
					a = b;
					b = c;
					c = r;
				}
				return r;
		}
	
}
/////////////////////////////////////////////////////////////
int pi(int m, int n, int(*pf)(int))
{
	int p = 1;
	for (int i = m; i <= n; i++)
		p *= pf(i);
	return p;
}

int summa(int m, int n, int(*pf)(int))
{
	int s=0;
	for (int i = m; i <= n; i++)
		s =s + pf(i);
	return s;
}
int simple(int k)
{
	return k;
}
int new_fact(int n)
{
	return pi(1,n,simple);
}

int sum(int a, int b)
{
	return a+b;
}
int mult(int a, int b)
{
	return a*b;
}

int alpha(int m, int n, int start, int(*pf)(int), int(*po)(int, int))
{
	int res;
	res = start;
	for (int i = m; i <= n; i++)
		res = po(res, pf(i));
	return res;
}
int fact(int n)
{
	return alpha(1, n, 1, simple, mult);
}

int memorize(int n, int array[100], int(*pf)(int))
{
	if (array[n] == 0)
		array[n] = pf(n);
	return (array[n]);
}
int factmem(int n)
{
	static int f = 0;
	static int a[100];
	if (f == 0)
	{
		a[0] = 1;
		a[1] = 1;
		for (int i = 2; i <= 100; i++)
			a[i] = 0;
		f = 1;
	}
	return memorize(n, a, fact);
}

/////////////////////////////////////////////////////////////
int recurse(int n, function<int(int)> pf, function<int(int, int)> po)
{
	if (n == 1)
		return pf(1);
	else
		return po(recurse(n - 1, pf, po), pf(n));
}
int recfact(int n)
{
	return recurse(n, [](int n) {return n; }, [](int a, int b) {return a*b; });
}
int recsumfact(int n)
{
	return recurse(n, recfact, [](int a, int b) {return a + b; });
}

/////////////////////////////////////////////////////////////
int Stepen_fast(int a, int b)
{
	int r;
	if (b == 1)
		return a;
	else if (b % 2 == 1)
		return a*Stepen_fast(a, b - 1);
	else
	{
		r = Stepen_fast(a, b / 2);
		return r*r;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, p, m, a, b, k, z;

	cout << "������� �����: \n";
	cin >> k;
	cout << k << " ����� ��������� = " << trib(k) <<"\n";

	cout << "****************************************************" << "\n";

	cout << "������� �����: \n";
	cin >> n;
	cout <<" ����� "<< n <<" ����������� = " << sigma(1, n, memrecfact) << "\n"; // ������ ����� �� ������� ��� ������������ �����������
	cout<<  summa(1, n, new_fact) << "\n"; // ������� ������ ����������� � ������� ������� pi
	cout << "****************************************************" << "\n";
	cin >> m;
	cout << alpha(1, m, 0, fact, sum) << "\n";
	cout << alpha(1, m, 1, fact, mult) << "\n";
	cout << "****************************************************" << "\n";
    cout << alpha(1, m, 0, factmem, sum) << "\n";
	cout << alpha(1, m, 1, factmem, mult) << "\n";
	cout << "****************************************************" << "\n";
	cin >> a;
	cin >> b;
	cout << Stepen_fast(a, b) << "\n";
	cout << "****************************************************" << "\n";
	cin >> p;
	cout << fib(p) << "\n";
	cout << fib_fast(p) << "\n";
	cout << fib3(p) << "\n";
	cout << fib4(p) << "\n";
	cout << memrecfib(p) << "\n";
	cout << "****************************************************"<<"\n";
	cin >> z;
	cout << recsumfact(z) << "\n";
	cout << "****************************************************" << "\n";


	system ("pause");
    return 0;
}

