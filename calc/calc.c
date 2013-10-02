/* This is a simple calculator program which 
takes input from the user and prints the output
continuously until an invalid input is received */
#include "stdio.h"
#include "math.h"
int main()
{
	char operator;
	int oprnd1,oprnd2;
	int result=0;
	int flag=0; // flag=1 indicates that an invalid input is obtained
	//Repeat until an invalid input is obtained
	while(1)
	{
		// Get the input from the user
	   	if( scanf("%d %c %d", &oprnd1, &operator, &oprnd2) != 3)
			break;
		
		// switch based on the operator
		switch(operator)
		{
			case '+': 
				result = add(oprnd1,oprnd2);
				break;
			case '-':
				result = sub(oprnd1,oprnd2);
				break;
			case '*':
               			result = mul(oprnd1,oprnd2);
                			break;
			case '/':
				if(oprnd2==0)
				{
					flag=1;
					break;
				}
				result = div(oprnd1,oprnd2);
				break;
			case '%':
				if(oprnd2==0)
				{
					flag=1;
					break;
				}
				result = mod(oprnd1,oprnd2);
				break;
			default:
				flag = 1;
				break;
		}
		if(flag==1) // Indicates an invalid input
			break;
		printf("%d\n",result);
	}
	return 0;
}
