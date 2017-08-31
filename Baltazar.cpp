#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;


double f(double x, double y)
{
	return (-y+ x * sin(x))/x;//функция	производной
}

double ft(double x)
{
	return (sin(x) - x*cos(x))/x;
}




int menu()
{	
	int variant;
	cout << "1.Ввод исходных данных. \n"
	     << "2.Метод Эйлера\n"
	     << "3.Метод Эйлера-Коши \n"
	     << "4.Выход\n"
	     << ">>> ";
	cin >> variant;
	return variant;
}


int main()
{
	setlocale (0, "rus");
	double Xi[100], Yi[100], Yit[100],n,h,E[100];
	setlocale(LC_ALL,"RUS");
	int variant;
	start: variant = menu();
	switch(variant)
	{
		case 1:
		{
			system("cls");
			double x0,x1,xn,xk;
			cout << "\n Введите шаг: \n";
		//	cin >> h;
			h=0.1;
			cout << "\n Введите первый узел:\n";
			//cin >> x0;
			x0=1;
			cout << " Введите последний узел:\n";
		//	cin >> x1;
			x1=2;
			cout << " Введите y(1)";
		//	cin >> Yi[0];
			Yi[0]=0.3011687;
			n=(x1-x0)/h+1;
			xn=x0;
			Xi[0]=x0;
			xk=x1;
			Yit[0]=ft(Xi[0]);
			for(int i=1; i<n;i++)
			{
				Xi[i]=Xi[i-1]+h;
			}
			system("pause");
			system("cls");
			goto start;
		}
		case 2:
    	{	
    		system("cls");
    		
    		Yit[0]=ft(Xi[0]);
    		E[0]=abs(Yit[0]-Yi[0]);
    		for(int i=1; i<n;i++)
			{
				Yi[i]=Yi[i-1]+h*f(Xi[i-1],Yi[i-1]);
				Yit[i]=ft(Xi[i]);
				E[i]=abs(Yit[i]-Yi[i]);
			}
    		cout << "\n i\t"<<setprecision(15)<<"xi     \t"<<setprecision(15)<<"Yi             \t"<<setprecision(15)<<"    Yiточное   \t"
			<<setprecision(15)<<"  Погрешность  \n";
			for(int i=0; i<n;i++)
			{
			 cout <<i<<"\t" <<setprecision(10)<< Xi[i]<<"\t" << setprecision(10) 
			 << Yi[i]<<"\t" << setprecision(10) <<Yit[i]<<"\t" << setprecision(10)<< E[i]<<"\t" <<setprecision(10)<<"\n";	
			}
    		system("pause");
    		system("cls");
    		goto start;
    	}

    	case 3:
    	{
    		system("cls");
			double Yiv[100];
    		Yit[0]=ft(Xi[0]);
    		E[0]=abs(Yit[0]-Yi[0]);
    		for(int i=1; i<n;i++)
			{
				Yit[i]=ft(Xi[i]);
				Yiv[i]=Yi[i-1]+h*f(Xi[i-1],Yi[i-1]);
				Yi[i]=Yi[i-1]+h*(f(Xi[i-1],Yi[i-1])+f(Xi[i],Yiv[i]))/2;
				E[i]=abs(Yit[i]-Yi[i]);
			}
    		cout << "\n i\t"<<setprecision(15)<<"xi     \t"<<setprecision(15)<<"Yi             \t"<<setprecision(15)<<"    Yiточное   \t"
			<<setprecision(15)<<"  Погрешность  \n";
			for(int i=0; i<n;i++)
			{
			 cout <<i<<"\t" <<setprecision(10)<< Xi[i]<<"\t" << setprecision(10) 
			 << Yi[i]<<"\t" << setprecision(10) <<Yit[i]<<"\t" << setprecision(10)<< E[i]<<"\t" <<setprecision(10)<<"\n";	
			}
			system("pause");
    		system("cls");
    		goto start;	
		}
		
		case 4:
		{
			default:
	    	system("cls");
			return 0;
		}
	}
}
