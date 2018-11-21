#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;
struct frame{
	int data=0;
	int sq=0;
};
frame *ss=new frame; 
frame *rs; 
bool ak=false;
int max2=0,rsq=1,n=0,akno=1;
unsigned long beg=0;

void Sender(int x){
	Sleep(1000);
	ss->data=x;
	ss->sq++;
	cout<<"\n\nData Sent: "<<ss->data<<" sq:"<<ss->sq;
	Sleep(1000);
	ak=false;
}

void Receiver(frame *ss)
{
	
	if(rs[rsq-1].sq==ss->sq){
		
		cout<<"\nNeglected";
		return;
	}
	rs[ss->sq-1].data=ss->data;
	rs[ss->sq-1].sq=ss->sq;
	rsq++;
	Sleep(1000);
	cout<<"\n\nData Received: "<<ss->data<<" sq:"<<ss->sq<<"\n***********************";

	if(max2<rsq)
	{
		exit(0);
	}
	ak=true;
	for (int i = 0; i <rsq ; i++)
	{
		if(rs[i].data==0)
		{
			akno=i+1;
			break;
		}
	}
	Sleep(1000);
}

int main()
{
	cout<<"\nEnter no. of Frames:";
	int n2;
	cin>>n;
	max2=n;
	cout<<"\nEnter Frame Window size:";
	cin>>n2;
	int a[n];
	rs=new frame[n];
	for (int i = 0; i <n ; i++)
	{
		cout<<"\nEnter Frame "<<i<<" Data:";
		cin>>a[i];
	}
	int i=0,k=0,w=0,count2=0;
	bool flag2=false,start=true;
	beg=(unsigned long)clock();
	int c=0;
	int q[100];
	while(i<n || rs[n-1].data!=0)
	{
		if(!start)
			for (int i = 0; i<c ; i++)
			{
				ss->sq=q[i];
				Sender(a[q[i]]);
				Receiver(ss);
			}
		cout<<"\n\nWindow "<<w;
		k=i;
		int y=n2+k;
		ss->sq=k;
		c=0;
		while (k<(y))
		{
			Sender(a[k]);
			if((difftime(clock(),beg)<=2000) || flag2 || start)
			{
				Receiver(ss);
				start=false;
			}
			else
			{
				cout<<"\n\nTimer Expired!! No Acknowledgement";
				q[c++]=(ss->sq)-1;
				count2++;
				if(count2<n2)
					flag2=false;
				else
					flag2=true;
			}
			k++;
		}
		i=k++;
		w++;
	}
	for (int i = 0; i < n; i++)
	{
		cout<<"\n rs:data: "<<rs[i].data<<"\n rs:sq: "<<rs[i].sq;
	}
	
	return 0;
}



