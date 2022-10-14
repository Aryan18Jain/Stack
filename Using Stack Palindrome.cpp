#include<iostream>
using namespace std;
#include<stack>
int main()
{
	stack<char> st;
	int i,n,count=0;
	cout<<"Enter size of array";
	cin>>n;
	char arr[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter "<<i+1<<" element";
		cin>>arr[i];
	}
	if(n%2!=0)
	{
		for(i=0;i<=n/2;i++)
		{
			st.push(arr[i]);
		}
		for(i=n/2;i<n;i++)
		{
			if(st.top()==arr[i])
			{
				st.pop();
				count++;	
			}	
		}
		if(count==(n/2)+1)
		cout<<"Palindrome";
		else
		cout<<"Not Palindrome";
	}
	else
	{
		for(i=0;i<n/2;i++)
		{
			st.push(arr[i]);
		}
		for(i=n/2;i<n;i++)
		{
			if(st.top()==arr[i])
			{
				st.pop();
				count++;	
			}	
		}
		if(count==n/2)
		cout<<"Palindrome";
		else
		cout<<"Not Palindrome";
	}
	return 0;
}

