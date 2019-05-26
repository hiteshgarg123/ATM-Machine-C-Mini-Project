#include<stdio.h>
#include<stdlib.h>

unsigned long AccountBalance = 50000; 
int a=0,b=0,c=0,d=0,e=0,Chance=0;

int MainMenu();
int Withdraw();
int Deposit();
int BalanceInquiry();
int MoneyTransfer();
int CarryTransaction();
int SecurityCheck();
int EnhancedSecurity();

int MainMenu()
{
	//Main menu starts from here
	int choice; 
	
	printf("***************** WELCOME TO ITS ATM *******************\n");
	printf("*                                                      *\n");
	printf("*              <1>. WITHDRAW MONEY                     *\n");
	printf("*              <2>. DEPOSIT MONEY                      *\n");
	printf("*              <3>. BALANCE ENQUIRY                    *\n");
	printf("*              <4>. MONEY TRANSFER                     *\n");
	printf("*                                                      *\n");
	printf("********************************************************\n\n");
	
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
	//Withdraw function starts from here.
	
	SecurityCheck();
	int WithdrawalAmount,temp5=0;			
	printf("\nEnter amount to be withdrawn\n");
	scanf("%d" , &WithdrawalAmount);
	
	//if account balance is not sufficient to withdraw the entered amount

	printf("Are you sure want to withdraw %d amount?\n ", WithdrawalAmount);
	printf("<1>. YES\n <2>. NO\n");
	scanf("%d", &temp5);
	
	if(temp5==1)
	{
		if(WithdrawalAmount>(AccountBalance)) 
		{
		
			printf("\nYou do not have sufficient acccount balance\n\n");
			CarryTransaction();
		}
	
		else if(WithdrawalAmount>20000)
		{
			printf("Cannot withdraw more than 10 notes at a time\n");
			CarryTransaction();
		}
		else
		{
		//Eject the cash and Update the account balance
	
		AccountBalance = AccountBalance - WithdrawalAmount;
		printf("\n\n*** Please collect the cash ***\n\n");
		printf("Current account balance is %lu \n\n", AccountBalance);
		CarryTransaction();
	
		}
    }
	else if(temp5==2)
	{
		printf("**** THANK YOU FOR USING ATM ****\n");
		exit(0);
	}
	else
	{
		/* If user wants to enjoy with machine i.e. if user enters other choice
		than YES and NO , This function will take care of it. */
		
		a=1;
		EnhancedSecurity();
	}
}

int Deposit()
{
	//Deposit function starts from here.
	
	SecurityCheck();
	int DepositAmount , temp1 , temp6=0;
	printf("\nEnter the amount to be deposited\n");
	scanf("%d", &DepositAmount);
	
	/*Deposit amount cannot be greater than 20,000.
	This is the max possible condition as biggest note as per Indian Currency is
	of 2000 and machine can eject/accept maximum of 10 notes at a time.
	So max amount that can be deposited or withdrawn is 20,000. */
	
	printf("Are you sure , you want to deposit %d amount ?\n", DepositAmount);
	printf("<1>. YES\n <2>. NO\n");
	scanf("%d", &temp6);
	
	if(temp6==1)
	{
		if(DepositAmount>20000)
		printf("You cannot deposit more than 10 notes at a time\n");
		
		else
		{
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
			else if(temp1==2)
			{
				printf("Thankyou for saving paper\n\n")
				printf("**** THANK YOU FOR USING ATM ****\n");
		        exit(0);
			}
			else
			{
				g=1;
				EnhancedSecurity();
			}
		}
	}

	else if(temp6==2)
	{
		printf("**** THANK YOU FOR USING ATM ****\n");
		exit(0);
	}
	
	else
	{
		b=1;
		EnhancedSecurity();
	}
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
		c=1;
		EnhancedSecurity();
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
		printf("You cannot transfer more than 2,50,000\n");
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
				d=1;
				EnhancedSecurity();
		    }

		}
		else if(temp3==2)
		{
			printf("Transaction Cancelled\n\n");
			printf(" *** THANKYOU FOR USING ATM ***");
			exit(0);
		}
			
		else
		{
			d=1;
			EnhancedSecurity();
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
		e=1;
		EnhancedSecurity();
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

int EnhancedSecurity()
{
	Chance++;
	while(Chance!=3)
	{
		printf("\nYou have made a wrong choice , Please try again\n\n ");
		if(a==1)
		Withdraw();
		
		else if(b==1)
		Deposit();
		     
		else if(c==1)
		BalanceInquiry();
		
		else if(d==1)
		MoneyTransfer();
		
		else if(e==1)
		CarryTransaction();
		 	
	}

	if(Chance==3)
	{
		printf("Please try again after some time\n\n");
		printf("**** THANKYOU FOR USING ATM ****\n");
		exit(0);
	}
	
}

int main()
{
	MainMenu();
	return 0;
}
