#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
using namespace std;


double f(double x)
{
	return x*x*x*sqrt(4+x*x);//�������	
}


double x12(double x1, double x2)
{
	return (x2-x1)/2;
}


double y12(double y1, double y2, double x1)
{
	double y21;
	y21=x1+x12(y1,y2);
	return f(y21);
}



int menu()
{	
	int variant;
	cout << "1.���� �������� ������. \n"
	     << "2.�������\n"
	     << "3.����� ���������������\n"
	     << "4.����� ��������.\n"
	     << "5.����� ��������\n"
	     << "6.�����\n"
	     << ">>> ";
	cin >> variant;
	return variant;
}


int main()
{
	setlocale (0, "rus");
	double Xi[100], Yi[100], Xi12[100], Yi12[100],n,h,Yk;
	setlocale(LC_ALL,"RUS");
	int variant;
	start: variant = menu();
	switch(variant)
	{
		case 1:
		{
			system("cls");
			double x0,x1,xn,xk;
			cout << "\n ������� ���: \n";
			cin >> h;
			cout << "\n ������� ������ ����:\n";
			cin >> x0;
			cout << " ������� ��������� ����:\n";
			cin >> x1;
			xn=x0;
			xk=x0;
			Xi[0]=x0;
			Yi[0]=f(x0);
			n=(x1-x0)/h+1;
			Xi12[0]=0;
			Yi12[0]=0;
			for(int i=1; i<n;i++)
			{
				Xi[i]=0;
				Yi[i]=0;
				Xi12[i]=0;
				Yi12[i]=0;
			}
			for(int i=1; i<n;i++)
			{
				Xi[i]=xn+h;
				xn=Xi[i];
				Yi[i]=f(xn);
				Xi12[i]=xk+x12(xk,xn);
				Yi12[i]=y12(xk,xn,xk);
				xk=Xi[i];
				Yk=Yi[i];
			}
			
			system("pause");
			system("cls");
			goto start;
		}
		case 2:
    	{	
    		system("cls");
    		cout << "\n "<<setprecision(4)<<"i\t"<<setprecision(5)<<"xi\t"<<setprecision(5)<<"y0\t"<<setprecision(5)<<"xi-1/2\t"
			<<setprecision(5)<<"yi-1/2\n ";
			for(int i=0; i<n;i++)
			{
			 cout << setprecision(4)<<i<<"\t" <<setprecision(5)<< Xi[i]<<"\t" << setprecision(5) 
			 << Yi[i]<<"\t" << setprecision(5) << Xi12[i]<<"\t" << setprecision(5)<< Yi12[i]<<"\t" <<setprecision(5)<<"\n";	
			}
    		system("pause");
    		system("cls");
    		goto start;
    	}

    	case 3:
    	{
    		system("cls");
    		double I1  ;
    		for(int i=1; i<n;i++)
    		{
    			I1=I1+Yi12[i];
			}
			I1=I1*h;
			cout << "�� �������� �������� ������� ��������������� \n I1 = "<<I1<<"\n�� �������� �������� �����������\n(��� ����� ������� ������ �������� ���������� � ������� ������������)\n";
			I1=0;
			system("pause");
    		system("cls");
    		goto start;	
		}
		case 4:
    	{
    		system("cls");
    		double I2;
    		for(int i=1; i<n-1;i++)
    		{
    			I2=I2+Yi[i];
			}
			I2=(I2+(Yi[0]+Yk)/2)*h;
			cout << "�� �������� �������� ������� ��������������� \n I2 = "<<I2<<"\n�� �������� �������� �����������\n(��� ����� ������� ������ �������� ���������� � ������� ������������)\n";
			I2=0;
			system("pause");
    		system("cls");
    		goto start;	
		}
		case 5:
    	{
    		system("cls");
    		double I3,y0,y1,y2,yn;
    		for(int i=1;i<n-1;i=i+2)
    		{
    			y1=y1+Yi[i];
			}
			for(int i=2;i<n-2;i=i+2)
    		{
    			y2=y2+Yi[i];
    		}
    		I3=h*(Yi[0]+4*y1+2*y2+Yk)/3;
    		cout << "�� �������� �������� ������� ��������(�������) \n I3 = "<<setprecision(10)<<I3<<"\n�� �������� �������� �����������\n(��� ����� ������� ������ �������� ���������� � ������� ������������)\n ����� ��������� ������������� �������� ������������";
			I3=0;
			system("pause");
    		system("cls");
    		goto start;	
		}
		case 6:
		{
			default:
	    	system("cls");
			return 0;
		}
	}
}
