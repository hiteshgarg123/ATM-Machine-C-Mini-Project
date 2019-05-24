#include<stdio.h>
#include<stdlib.h>

unsigned long AccountBalance = 50000; 
int temp = 0;

int Withdraw();
int Deposit();
int BalanceInquiry();
int MoneyTransfer();
int CarryTransaction();

int MainMenu()
{
	int i=0;
	while(i<3)
	{
		int SecretePIN = 0 , attempt=1;
		printf("Enter your PIN Number");
		scanf("%d", &SecretePIN);
		if(SecretePIN == 1992)
		{
			int choice; 
		
			printf("*********** Welcome to ITS ATM Machine ***********\n\n");
			printf("<1>. WITHDRAW\n");
			printf("<2>. Deposit\n");
			printf("<3>. Balance ENQUIRY\n");
			printf("<4>. MONEY TRANSFER\n\n");
			printf("***************************************************\n\n");
			
			printf("\nEnter your choice\n");
			scanf("%d", &choice);
			
			switch(choice)
			{
				case 1: Withdraw();
				        break;
				case 2: Deposit();
				        break;
				case 3: BalanceInquiry();
				        break;
				case 4: MoneyTransfer();
			            break;
			    default: printf("Wrong Choice , Try Again\n\n");
			             MainMenu();
			}
			break;
		}
		else
		{
			i+=1;  
			printf("Incorrect PIN, Please try again\n\n");
		}
	}
}
	

int CarryTransaction()
{
	//function to carry out another transaction after one.
	printf("Do you want to carry another transcation ?\n ");
	printf("Press \n 1.- Yes \n 2.- No \n");
	scanf("%d" , &temp);
	if(temp == 1)
	{
		system("CLS");
		MainMenu();
	}
	else if(temp == 2)
	printf("*** THANKYOU FOR USING ATM***");
	
	else
	{
		printf(" Wrong Choice , Please try again");
		CarryTransaction();
	}	  
}	

int Withdraw()
{
	int WithdrawalAmount;			
	printf("Enter amount to be withdrawn\n");
	scanf("%d" , &WithdrawalAmount);
	
	//if account balance is not sufficient to withdraw the entered amount

	if(WithdrawalAmount>(AccountBalance)) {
		
		printf("\nYou do not have sufficient acccount balance\n\n");
		CarryTransaction();
	}
	
	else if(WithdrawalAmount>20000)
	{
		printf("Cannot withdraw more than 20000 at a time");
		CarryTransaction();
	}
	else
	//Eject the cash and Update the account balance
	
	AccountBalance = AccountBalance - WithdrawalAmount;
	printf("\n\n*** Please collect the cash ***\n\n");
	printf("Current account balance is %lu \n\n", AccountBalance);
	CarryTransaction();
	
}

int Deposit()
{
	int DepositAmount , temp1;
	printf("Enter the amount to be deposited");
	scanf("%d", &DepositAmount);
	
	//Deposit amount cannot be greater than 20000
	
	if(DepositAmount>20000)
	printf("You cannot deposit more than 20,000 at a time");
	
	else
	//Update the balance and eject the recipt 
	AccountBalance += DepositAmount;
	printf("Balance has been updated \n Do you want the recipt ?");
	printf("<1>. YES \n <2>. NO\n");
	scanf("%d", &temp1);
	if(temp1==1)
	{
		printf("Please Collect the Recipt");
		CarryTransaction();
	}
	else
	CarryTransaction();
}

int BalanceInquiry()
{
	
}

int MoneyTransfer()
{
	
}

int main()
{
	MainMenu();
	return 0;
}
