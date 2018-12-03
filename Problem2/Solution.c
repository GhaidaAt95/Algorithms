/*
*   Name : Ghaida Al-Atoum         ID#: **********
*                            HW02
*   Compile Using : gcc -std = c99 Solution.c
*   asymptotic worst-case time is theta((m^2)n)
*/
#include <stdio.h>
#include <stdlib.h>

int *s, **c, **a;
int n;
int m=0;
int solution=0;
void subsetSum()
{ 
	int i = 0, j = 0, k = 1;
	int left;
	for (i = 0; i < m + 1; i++)
	{
		if (i == 0) j = 1;
		else j = i;
		for (; j < m + 1; j++) 
		{
			for (k = 1; k <= n; k++) 
			{
				left = j - s[k];
				if (left >= 0 && c[i][left] < k) 
				{
					break;
				}
			}//K_loop
			c[i][j] = k;
			c[j][i] = k;
		}//J_loop	
	}//I_lopp
	if (c[m][m] == n + 1) 
	{
		printf(" No Solution \n");
	}
	else 
	{
		// Backtracing 
			solution=1;   // There Is A solution 
			i = m; j = m;
		a[0][c[i][j]] = s[c[i][j]]; // To get the first m we take the value saved in index s[c[m][m]] in the first set 
		j = j - s[c[i][j]];         
		while (i != 0 || j != 0) 
		{   // backtrace tell both are equal to zero 
			if (i > j) 
			{                  // if what left of i is greater than what is in j then backtrace for it 
				a[2][c[i][j]] = s[c[i][j]];
				i -= s[c[i][j]];
			}
			else 
			{                        // if what left of j is greater than what is in i then backtrace for it 
				a[0][c[i][j]] = s[c[i][j]];
				j -= s[c[i][j]];
			}
		}
		for (i = 1; i <= n; i++) 
		{       // third set creation 
			if (a[0][i] == 0 && a[2][i] == 0)
				a[1][i] = s[i];
		}
	}

}
void print_array( )
{
	// print array By replacing zeros with spaces 

	if(m <= 10) 
	{
		for (int i = 0; i < m + 1; i++) 
		{
			printf("%d   ",i);
			for (int j = 0; j < m + 1; j++) 
			{
				printf("  %d  ",c[i][j]);
			}
			printf("\n");
		}
	}
	printf("********************************\n");
	if(solution)
	{
				printf(" \t0\t1\t2\n");
		for (int g = 1; g <= n; g++) 
		{
			printf("%d",g);
			printf("\t");
			if(a[0][g]){
			printf("%d",a[0][g]);
			}
			printf("\t");
			if(a[1][g]){
			printf("%d",a[1][g]);
			}
			printf("\t");
			if(a[2][g]){
			printf("%d",a[2][g]);
			}			
			 printf("\n");				
		}

		}	  
}
// READ INPUT FUNCTION 
int read_input(){
	int i;
	scanf("%d",&n);
	s = (int*)calloc( (n+1), sizeof(int)); // s[n+1]
	s[0]=0;
	for (i = 1; i <= n; i++) 
	{
	scanf("%d",&s[i]);
		m += s[i];
	}
	if (m % 3 != 0) 
	{
		printf(" Sum %d Not Divisible by three \n",m);
		return 0;
	}
	 
	printf("\t %d/3 = %d \n",m,m/3);
	m = m / 3;

	c=(int**)calloc((m+1), sizeof(int*));  // c[m+1][m+1];
	for (i = 0; i < (m + 1); i++) 
	{
		c[i] = (int*)calloc((m + 1), sizeof(int));
	}

	a = (int**)calloc((3), sizeof(int*));  // a[3][n+1];
	for (i = 0; i < 3; i++) 
	{
		a[i] = (int*)calloc(n+1, sizeof(int));
	}
	for(i=0;i < 3;i++)
	{
		  for(int j=0;j<=n;j++)
		{
		  a[i][j]=0;
		}
	}
	return 1;
	
}
int main() {
 int i=0;
	 if( read_input()) {	
		c[0][0] = 0;
		subsetSum();   
		// Printing The Input 
		  printf("\ti\ts\n\t---------\n");
		  for ( i=0 ; i<=n ; i++){
				printf("\t%d\t%d\n",i,s[i]);
				 }
		 print_array();
	
	 }
	// Free Memory 			
   free(s);
	   for(i=0 ; i< m+1 ; i++)
	   {
		   free(c[i]);
	   }
	   free(c);
	   for(i=0;i<3;i++)
	   {
		  free(a[i]);
	   }
	   free(a);

 
	return 0;
}
