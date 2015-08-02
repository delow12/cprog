#include <iostream>
#include <bitset>
#include <stdio.h>

#ifdef DEBUG
#define DBG(x) cout<<#x <<" = " << x << endl;
#else
#define DBG(x) 
#endif

using namespace std;
int main()
{
	int arr[3001];
	int i,j,k;
	bitset<3000> bits;
	
whilel:
	while(scanf("%d", &i) != EOF)
	{
		int no = i;
		bits.reset();

		int total = no;
		
		if (no < 1)
		{
			cout<<"Not jolly"<<endl;
			continue;
		}
		int last;
		scanf("%d", &last);
		i--;
		/*
		if(no == 1 && last != 0)
		{
			cout<<"Not jolly"<<endl;
			continue;
		}
		else */
		if(no == 1)
		{
			cout<<"Jolly"<<endl;
			continue;
		}
		int v;
		while(i--)
		{
			int now;
			scanf("%d", &now);

			v = now - last;
			if (v < 0) v *= -1;

			DBG(v);

			last = now;

			if(bits[v])
			{
				cout<<"Not jolly"<<endl;
				while(i--) if(scanf("%d", &now) == EOF) goto whilel;
				goto whilel;
			}
			else
			{
				bits[v] = true;
				total--;
				DBG(total);
			}
		}
		if(total == 1)
		{
			//if(no > 2 || (no == 2 && v == 1))
			bool is = true;
			for(i = 1; i < no; i ++)
				if(!bits[i]) is = false;

			if(is)
			cout<<"Jolly"<<endl;
			else
			cout<<"Not jolly"<<endl;
		}
		
	}
}
