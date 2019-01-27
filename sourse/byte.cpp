#include<iostream>
#include <vector>
 
using namespace std;
 
int main()
{

	unsigned long long value;
	vector<uint8_t> myVector(7);
	vector<uint8_t> myVector2(7);
	cout<<"enter integer:\t";
	cin>>value;
	uint8_t test;
	
	//вывод unsigned long long побитово
	cout<<"unsigned long long as bites\n";
	//for(int i=sizeof(value)*8-1; i>=0; --i)
	for(int i=sizeof(value)*8-1; i>=0; --i)
	{
	   int k=value&(1ULL<<i)?1:0;
	   cout<<k;

    }
	cout<<"\n";
		
	//заполнение векторов побитово
	for (int i=8;i>0;--i)
	{
		for (int j=0;j<8;j++)
		{
			if (value&(1ULL<<(8*i-j-1))) 
			{
				myVector[i-1]|=1<<7-j;//myVector[i-1]|=u1<<7-j u1 вместо 1, не компилируется

			}
			
		}		

	}
	//просто сдвиг на 8 битов в исходной переменной
	for (int k=0; k<8; k++)
	{
		myVector2[k] = (uint8_t)(value>>(8*k));
	}	
		
	//вывод векторов в 16ти ричном виде, десятичном и побитово

	cout<<"crazy very hard method\n";
	cout<<"Vectors as\t"<<"hex\t"<<"decimal\t"<<"bites\n";
	for (int l=myVector.size();l>=0;l--)
	{
		cout<<"Vector ["<<l<<"]\t"<<hex<<int(myVector[l])<<"\t"<<dec<<int(myVector[l])<<"\t";
		for(int i=sizeof(myVector[0])*8-1; i>=0; --i)
		{
		   int k=myVector[l]&(1<<i)?1:0;
		   cout<<k;
		}
		std::cout<<"\n";
	}
	
	cout<<"simple method\n";
	cout<<"Vectors as\t"<<"hex\t"<<"decimal\t"<<"bites\n";
	for (int l=myVector2.size();l>=0;l--)
	{
		cout<<"Vector2 ["<<l<<"]\t"<<hex<<int(myVector2[l])<<"\t"<<dec<<int(myVector2[l])<<"\t";
		for(int i=sizeof(myVector2[0])*8-1; i>=0; --i)
		{
		   int k=myVector2[l]&(1<<i)?1:0;
		   cout<<k;
		}
		std::cout<<"\n";
	}
	
	
	cout<<"end";
	//cout<<int(test);
	
    return 0;	
}
