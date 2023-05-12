#include<stdio.h>
void deposit();
void withdrawal();
void balance();
void pinchange();
int validate(int account_temp,int passwd_temp);
int i,x;
int account_temp;
int amount_temp;
int passwd_temp,pinc;

struct account_details
{
	int account_no;
	int password;
	int amount;
};
struct account_details s[3]={{12343432,1234,1000},{12343433,5678,2000},{89877182,1098,5000}};	
int main()
{
	while(1)
	{
		int choice;
		printf("\n****WELCOME TO ATM*****\n");
		printf("1. DEPOSIT\n2. WITHDRAWAL\n3. BALANCE ENQUIRY\n4.CHANGE PIN\n5.EXIT\nEnter Your Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			{
				deposit();
				break;	
			}
			case 2:
			{
				withdrawal();
				break;	
			}	
			case 3:
			{
				balance();
				break;		
			}
			case 4:
			{
				pinchange();
				break;	
			}	
		}	
	}		
}
int validate(int account_temp,int passwd_temp)
{
	for(i=0;i<3;i++)
	{
		if(s[i].account_no==account_temp)
		{
			if(s[i].password==passwd_temp)
			{
				return i;
				break;	
			}
			else
			{
				printf("\nPassword Mismatch");
				break;		
			}	
		}	
	}
}
void deposit()
{
	printf("Enter the account number:\n");
	scanf("%d",&account_temp);
	printf("Enter the amount to deposit:\n");
	scanf("%d",&amount_temp);
	printf("Enter the password:\n");
	scanf("%d",&passwd_temp);
	x=validate(account_temp,passwd_temp);
	s[x].amount+=amount_temp;
	printf("Rs:%d is successfully deposited into your account\nNow your balance is %d",amount_temp,s[x].amount);
}
void withdrawal()
{
	printf("Enter the account number:\n");
	scanf("%d",&account_temp);
	printf("Enter the amount to withdraw:\n");
	scanf("%d",&amount_temp);
	printf("Enter the password:\n");
	scanf("%d",&passwd_temp);
	x=validate(account_temp,passwd_temp);
	if(s[x].amount<amount_temp)
	{
		printf("Unable to withdraw from your account. Your balance is lower than your request");	
	}
	else
	{
		s[x].amount-=amount_temp;
		printf("Rs:%d is successfully withdrawn from your account\nNow your balance is %d",amount_temp,s[x].amount);		
	}	
}
void balance()
{
	printf("Enter the account number:\n");
	scanf("%d",&account_temp);
	printf("Enter the password:\n");
	scanf("%d",&passwd_temp);
	x=validate(account_temp,passwd_temp);
	printf("Your account No:%d contains Rs:%d",account_temp,s[x].amount);	
}
void pinchange(){
    printf("Enter the account number:\n");
	scanf("%d",&account_temp);
	printf("Enter the password:\n");
	scanf("%d",&passwd_temp);
	x=validate(account_temp,passwd_temp);
	printf("Enter new pin:\n");
	scanf("%d",&pinc);
	s[x].password=pinc;
	printf("New password is %d:",s[x].password);}
