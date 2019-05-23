#include<stdio.h>

unsigned long AccountBalance = 5000;
int temp = 0;

int Withdraw();
int Deposit();
int BalanceInquiry();
int MoneyTransfer();
int CarryTransaction();

int MainMenu()
{
	int choice;
	
	printf("*********** Welcome to ITS ATM Machine ***********\n\n");
	printf("1. WITHDRAW\n");
	printf("2. DEPOSIT\n");
	printf("3. BALANCE INQUIRY\n");
	printf("4. MONEY TRANSFER\n\n");
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
	
}

int CarryTransaction()
{
	//function to carry out another transaction after one.
	printf("Do you want to carry another transcation ?\n ");
	printf("Press \n 1.- Yes \n 2.- No \n");
	scanf("%d" , &temp);
	if(temp == 1)
	MainMenu();
	
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
	
	else
	//Eject the cash and Update the account balance
	
	AccountBalance = AccountBalance - WithdrawalAmount;
	printf("\n\n*** Please collect the cash ***\n\n");
	printf("Current account balance is %lu \n\n", AccountBalance);
	CarryTransaction();
	
}

int Deposit()
{
	
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
