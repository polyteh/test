#include<iostream>
#include <vector>
 
using namespace std;
 
int main()
{

	unsigned long long value;
	vector<uint8_t> myVector(7);
	cout<<"enter integer:\t";
	cin>>value;
	
	//вывод unsigned long long побитово
	cout<<"unsigned long long as bites\n";
	for(int i=sizeof(value)*8-1; i>=0; --i)
	{
	   int k=value&(1<<i)?1:0;
	   cout<<k;

    }
	cout<<"\n";
		
	//заполнение векторов побитово
	for (int i=8;i>0;--i)
	{
		for (int j=0;j<8;j++)
		{
			if (value&(1<<(8*i-j-1))) 
			{
				myVector[i-1]|=1<<7-j;//myVector[i-1]|=u1<<7-j u1 вместо 1, не компилируется

			}
			
		}		
	}
		
	//вывод векторов в 16ти ричном виде, десятичном и побитово

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
	

	
    return 0;	
}
