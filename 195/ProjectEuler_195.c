/* Question Hackerrank  Project Euler #195: Inscribed circles of triangles with one angle of 60 degrees
This problem is a programming version of Problem 195 from projecteuler.net

Let's call an integer sided triangle with exactly one angle of  degrees a -degree triangle.

Let  be the radius of the inscribed circle of such a -degree triangle.

There are  -degree triangles for which .

Let  be the number of -degree triangles for which , so ,  , and  .

Find  for some .

Input Format

First line of each test file contains a single integer  which is the number of queries in the file.  lines follow with a single integer  on each.

Constraints

Sum of all  in a test file 
Output Format

Output exactly  lines with a single integer on each. The integer of the -th line should be the answer for the query with  as an input.

Sample Input 0

3
100
1000
10000
Sample Output 0

1234
22767
359912





*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

float calculateRadius(int a,int b,float c)
{
	float r;
	r=((sqrt(3)*.5*a*b)/(a+b+c));
	return r;
}
float calculateC(int a,int b)
{	
	int temp;
	temp =(a*a)+(b*b)-(a*b);
		return (sqrt(temp));


}
int verifyTriangle(int a,int b,float c)
{
	//this triangle will verify 60 degree ange criteria
	int calculated_c_square;
     	calculated_c_square = (a*a)+(b*b)-(a*b);
     	if ( ceilf(c) == c)
     	{

     		if ((int)c*(int)c == calculated_c_square )
			{

				//printf("%d   %d    verified  ",calculated_c_square,((int)c*(int)c));
				return 1;
			}
			else
			{
				return 0;
			}
     	}
     	else 
     		return 0;	
	
}
int calculate(float n)
{
//calculate T[n]
	int flag=0;
	int a,b,bmax;
	float r,c;
	for(a=1;1;a++)
	{

		for(b=(a+1);1;b++)
		{
			
			c=calculateC(a,b);
			int v;

				r=calculateRadius(a,b,c);
				if(r<=n)
				{
					v=verifyTriangle(a,b,c);
					if (v==1)
					{
						flag++;
						//printf("a == %d b ==  %d c == %d r== %f\n", a,b,(int)c,r);
					}
				}
				else
				{
					printf("a == %d b ==  %d c == %f r== %f\n", a,b,c,r);
					bmax=b;
					break;
				}
				
		}
		if(bmax==(a+1))
		{
			break;

		}


	}

	return flag;
}



int main()
{
	//Number of query = nq
	int nq;
	scanf("%d",&nq);
	float n[nq]; 
	int T[nq];  //r=redius
	int i;
	for(i=0;i<nq;i++)
	{	
		scanf("%f",&n[i]);
	}
	for(i=0;i<nq;i++)
	{	
		int ni = n[i];
		T[i]=calculate(ni); 
		printf("%d\n",T[i] );
	}

}
