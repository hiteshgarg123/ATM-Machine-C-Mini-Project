#include<stdio.h>
#include<stdlib.h>

unsigned long AccountBalance = 50000; 
int i=0,j=0,k=0,l=0;

int Withdraw();
int Deposit();
int BalanceInquiry();
int MoneyTransfer();
int CarryTransaction();
int SecurityCheck();

int MainMenu()
{
	int choice; 

	printf("*********** Welcome to ITS ATM Machine *************\n\n");
	printf("*            <1>. WITHDRAW MONEY                   *\n");
	printf("*            <2>. DEPOSIT MONEY                    *\n");
	printf("*            <3>. BALANCE ENQUIRY                  *\n");
	printf("*            <4>. MONEY TRANSFER                   *\n\n");
	printf("****************************************************\n\n");
	
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

int Withdraw()
{
	SecurityCheck();
	int WithdrawalAmount;			
	printf("\nEnter amount to be withdrawn\n");
	scanf("%d" , &WithdrawalAmount);
	
	//if account balance is not sufficient to withdraw the entered amount

	if(WithdrawalAmount>(AccountBalance)) {
		
		printf("\nYou do not have sufficient acccount balance\n\n");
		CarryTransaction();
	}
	
	else if(WithdrawalAmount>20000)
	{
		printf("Cannot withdraw more than 10 notes at a time\n");
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
	SecurityCheck();
	int DepositAmount , temp1;
	printf("\nEnter the amount to be deposited\n");
	scanf("%d", &DepositAmount);
	
	//Deposit amount cannot be greater than 20000
	
	if(DepositAmount>20000)
	printf("You cannot deposit more than 20,000 at a time\n");
	
	else
	//Update the balance and eject the recipt 
	AccountBalance += DepositAmount;
	printf("Balance has been updated \nDo you want the recipt ?\n");
	printf("\n<1>. YES \n<2>. NO\n");
	scanf("%d", &temp1);
	if(temp1==1)
	{
		printf("Please Collect the Recipt\n");
		CarryTransaction();
	}
	else
	CarryTransaction();
}

int BalanceInquiry()
{
	SecurityCheck();
	int temp2;
	printf("Do you want to check the current balance of your account ?\n");
	printf("<1>. YES \n<2>. NO\n");
	scanf("%d",&temp2);
	
	if(temp2==1)
	{
		printf("%lu\n", AccountBalance);
		CarryTransaction();
	}
	
	else if(temp2==2)
	exit(0);
	
	else
	{
		i++;
		while(i!=3)
		{
			printf("\nYou have made a wrong choice , Please try again\n\n ");
			BalanceInquiry();	
		}
		
		if(i==3)
		exit(0);
	}
}

int MoneyTransfer()
{
	int TransferAmount=0,temp3=0,temp4=0;
	SecurityCheck();
	printf("Enter the amount you want to transfer\n");
	scanf("%d", &TransferAmount);
	if(TransferAmount>250000)
	{
		printf("You cannot transfer more than 50,000\n");
		CarryTransaction();
	}
	else if(TransferAmount>AccountBalance)
	{
		printf("Insufficient Account Balance");
		CarryTransaction();
	}
	else
	{
		printf("Are you sure you want to transfer %d amount", TransferAmount);
		printf("<1>. YES \n<2>. NO\n");
		scanf("%d",&temp3);
		if(temp3==1)
		{
			printf("%d Amount has been Succesfully Transferred\n",TransferAmount);
			printf("Do you want the recipt?\n");
			printf("<1>. YES \n<2>. NO	 \n");
			scanf("%d",&temp4);
			if(temp4==1)
			{
				printf("Please collect the recipt\n\n");
				CarryTransaction();
			}
			
			else if(temp4==2)
			{
				printf("Thank you for saving paper\n");
				CarryTransaction();
			}
			
			else
			{
				j++;
				while(j!=3)
				{
					printf("\nYou have made a wrong choice , Please try again\n\n ");
					BalanceInquiry();	
				}
		
				if(j==3)
				exit(0);
		    }

		}
		else if(temp3==2)
		{
			
			printf("Transaction Cancelled\n\n");
			printf("*** THANKYOU FOR USING ATM ***");
			exit(0);
			
		}
			
		else
		{
			k++;
			while(k!=3)
			{
				printf("\nYou have made a wrong choice , Please try again\n\n ");
				BalanceInquiry();	
			}
		
			if(k==3)
			exit(0);
		}
	
		printf("Current balance is %d", AccountBalance);
			
	}
}


int CarryTransaction()
{
	//function to carry out another transaction after one.
	int temp=0;
	printf("Do you want to carry another transacation ?\n ");
	printf("Press \n 1.- Yes \n 2.- No \n");
	scanf("%d" , &temp);
	if(temp == 1)
	{
		system("CLS");
		MainMenu();
	}
	else if(temp == 2)
	printf("*** THANKYOU FOR USING ATM ***");
	
	else
	{
		l++;
		while(l!=3)
		{
			printf("\nYou have made a wrong choice , Please try again\n\n ");
			BalanceInquiry();	
		}
		
		if(l==3)
		exit(0);
	}	  
}	

int SecurityCheck()
{
	int i=0;
	while(i<3)
	{
		int SecretePIN = 0 , attempt=1;
		printf("Enter your PIN Number\n");
		scanf("%d", &SecretePIN);
		if(SecretePIN == 1992)
		break;
		else
        {
			printf("Incorrect PIN, Please try again\n\n");
			i+=1;
			
			if(i==3)
			exit(0);
		}
	}  
	
}

int main()
{
	MainMenu();
	return 0;
}
