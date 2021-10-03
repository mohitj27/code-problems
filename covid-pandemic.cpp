#include<iostream>
using namespace std;

int main() {
    int t,count1,n,num,count0;
    bool flag;
	cin>>t;
	while(t--)
	{
	   count0=0,count1=0,flag=true;
	    cin>>n;
	     for(int i=0;i<n;i++)
	     {
	        cin>>num;
	        if(num==1)
	        {
	           count1++;
	           if(count1>1 && count0<6 )
	           {flag=false;}
	           count0=1;
	        }
	        else
	        count0++;
	      }
	     if(flag==true)
	      cout<<"AFFIRMATIVE\n";
	     else
	      cout<<"NEGATIVE\n";
	}

	return 0;
}
