#include <iostream>

#include <string>

using namespace std;



bool 
Nedelia (string d)
{

  string a[]
  {

  "Понедельник","Вторник","Среда","Четверг","Пятница","Суббота","Воскресенье"};

  int c = 0;

  for (int i = 0; i < 7; i++)
    {

      if (d == a[i])
	{

	  c++;
	}
    }

  if (c > 0)
    return true;

  else
    return false;
}



int
 main ()
{

  setlocale (LC_ALL, "Russian");

  int n;

  string d;

  string a[]
  {

  "Понедельник","Вторник","Среда","Четверг","Пятница","Суббота","Воскресенье"};

  cout <<
    "Введите день недели с какой начинается год : ";

  cin >> d;

  if (Nedelia (d))
    {

      int s;

      cout << "Введите день года : ";

      cin >> n;

      if (n > 366 || n < 1) {

          cout << "Ограничение в числах";

          return 0;
      }

      else {

      for (int i = 0; i < 7; i++)
	{

	  if (a[i] == d)
	    {

	      s = (n + i) % 7;

	      if (s == 0)
		cout << a[6];

	      else
		cout << a[s - 1];

	      return 0;
	    }

	}

    }

    }

  else
    cout << "Ты с какой планеты?";

  return 0;

}