//ATM Machine C Mini Project

#include<stdio.h>
#include<stdlib.h>
#include<string.h>  

/**************************************** All Global variables are declared here *********************************************************/

int a=0,b=0,c=0,d=0,Chance=0,tempo=0; 

FILE *fp,*ftemp;

/*****************************************************************************************************************************************/

/************************************* Structure to store the details of Active user *****************************************************/

/* Here we define an active user as a user, who is currently doing a transaction in ATM 
It means a user who entered his/her Account number and PIN CORRECT , His/Her details got verified with the help of this structure and 
later stored in this , and as soon as he/she completes the transaction , the structure will also update his/her account details.
*/

struct AccountHolder
{
    char name[50] ;
	char AccountNumber[50];
    int pin;
    float balance;
};
struct AccountHolder s,r;

/*******************************************************************************************************************************************/

/********************************************* FUNCTION PROTOTYPES *************************************************************************/

int MainMenu();           				    // Main Menu of ATM
int Withdraw();            					// Withdraw function
int Deposit();            					// Deposite Function
int BalanceInquiry();      					// Balance Inquiry Function
int MoneyTransfer();       					// Money Transfer Function
int SecurityCheck();       					// This function will ask for card and PIN
int EnhancedSecurity();    					// This will take care of users who will select other options than provided ones only.
int CardVerification();    					//This function will verify the card credentials entered by the user
void update_file(struct AccountHolder);     //This will update the bank records of Account Holder after  Transaction.

/******************************************************************************************************************************************/

void update_file(struct AccountHolder a){

	FILE *accounts, *temp;
	struct AccountHolder b;

	accounts = fopen("Account_Details.dat","rb+");
	temp = fopen("temp.dat","wb+");

	while(fread(&b, sizeof(struct AccountHolder), 1, accounts)){
		if(strcmp(b.AccountNumber , a.AccountNumber) != 0){
			fwrite(&b,sizeof(struct AccountHolder),1,temp);
		}
	}
	fwrite(&a,sizeof(struct AccountHolder),1,temp);

	fclose(accounts);
    fclose(temp);
	remove("Account_Details.dat");
    int error = rename("temp.dat","Account_Details.dat");
    if(error)
    	printf("\n\nFile Update failed with error code %d\n", error);
	else
		tempo=1;
}

int MainMenu()
{
	//Main menu starts from here
	int choice; 
	
	printf("\n\n");
	printf("\t\t***************** WELCOME TO ITS ATM *******************\n");
	printf("\t\t*                                                      *\n");
	printf("\t\t*              <1>. WITHDRAW MONEY                     *\n");
	printf("\t\t*              <2>. DEPOSIT MONEY                      *\n");
	printf("\t\t*              <3>. BALANCE ENQUIRY                    *\n");
	printf("\t\t*              <4>. MONEY TRANSFER                     *\n");
	printf("\t\t*                                                      *\n");
	printf("\t\t********************************************************\n\n");
	
	printf("Enter your choice\n");
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
	
	int WithdrawalAmount,temp5=0;			
	printf("\nEnter amount to be withdrawn\n");
	scanf("%d" , &WithdrawalAmount);
	
	//if account balance is not sufficient to withdraw the entered amount

	printf("Are you sure want to withdraw %d amount?\n ", WithdrawalAmount);
	printf("<1>. YES\n <2>. NO\n");
	scanf("%d", &temp5);
	
	if(temp5==1)
	{
		
		if(WithdrawalAmount>(s.balance)) 
		{
			printf("\nCan't Withdraw %d Rupee\n\n",WithdrawalAmount);
		}
	
		else if(WithdrawalAmount>20000)
		{
			printf("Cannot withdraw more than 10 notes at a time\n");
		}
		else
		{
			//Eject the cash and Update the account balance
		
			s.balance -= WithdrawalAmount;
			
			update_file(s);
			
			if(tempo==1)
			{
				printf("\nTransaction Failed\n");
			}
			
			else
			{
				printf("\n\n*** Please collect the cash ***\n\n");
				printf("Current account balance is %.2f \n\n", s.balance);
				printf("**** THANK YOU FOR USING ATM ****\n");
			}
		}
    }
	else if(temp5==2)
	{
		printf("**** THANK YOU FOR USING ATM ****\n");
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
	
	int DepositAmount , temp1 , temp6=0;
	printf("\nEnter the amount to be deposited\n");
	scanf("%d", &DepositAmount);
	
	/*Deposit amount cannot be greater than 20,000.
	This is the max possible condition as biggest note as per Indian Currency is
	of 2000 and machine can eject/accept maximum of 10 notes at a time.
	So max amount that can be deposited or withdrawn is 20,000. */
	
	printf("Are you sure , you want to deposit %d amount ?\n", DepositAmount);
	printf("<1>. YES\n<2>. NO\n");
	scanf("%d", &temp6);
	
	if(temp6==1)
	{
		if(DepositAmount>20000)
		printf("You cannot deposit more than 10 notes at a time\n");
		
		else
		{
			//Update the balance and eject the recipt 
			 
			s.balance += DepositAmount;
			update_file(s);
			
			if(tempo==1)
			{
				printf("\nTransaction Failed\n");
			}
			
			else
			{
				printf("Balance has been updated \nDo you want the recipt ?\n");
				printf("\n<1>. YES \n<2>. NO\n");
				scanf("%d", &temp1);
				if(temp1==1)
				{
					printf("Please Collect the Recipt\n");
				}
				
				else if(temp1==2)
				{
					printf("Thank You for saving paper\n\n");
					printf("**** THANK YOU FOR USING ATM ****\n");
				}
				else
				{
					b=1;
					EnhancedSecurity();
				}
			}
		}
	}

	else if(temp6==2)
	{
		printf("**** THANK YOU FOR USING ATM ****\n");
	}
	
	else
	{
		b=1;
		EnhancedSecurity();
	}
}

int BalanceInquiry()
{
	//Balance Inquiry function starts from here.
	
	int temp2;
	printf("Do you want to check the current balance of your account ?\n");
	printf("<1>. YES \n<2>. NO\n");
	scanf("%d",&temp2);
	
	if(temp2==1)
	{
		//prints the current account balance.
		
		printf("%.2f\n", s.balance);
	}
	
	else if(temp2==2)
	{
		printf("**** THANK YOU FOR USING ATM ****\n");
	}
	 
	else
	{
		c=1;
		EnhancedSecurity();
	}
}

int MoneyTransfer()
{
	//Money Transfer Function starts from here.
	
	int TransferAmount=0 , temp3=0 , temp4=0;
	char TransferAccount[50];
	
	printf("Enter the Account in which you want to transfer the amount\n");
	fflush(stdin);
	gets(TransferAccount);
	
	printf("\nEnter the amount you want to transfer\n");
	scanf("%d", &TransferAmount);
	if(TransferAmount>40000) 
	{
		// Daily limit of transferring amount as per Reserve Bank of India is 40,000
		
		printf("You cannot transfer %d amount\n", TransferAmount);
	}
	else if(TransferAmount>s.balance)
	{
		// Condition of Insufficient Balance.
		
		printf("Can''t transfer money\n");
	}
	else
	{
		printf("Are you sure you want to transfer %d amount", TransferAmount);
		printf("\n<1>. YES \n<2>. NO\n");
		scanf("%d",&temp3);
		int flg = 0;
		if(temp3==1)
		{
			fp = fopen("Account_Details.dat","rb+");
			while( fread(&r, sizeof(struct AccountHolder), 1, fp))
			{
				if(strcmp(TransferAccount , r.AccountNumber)==0)
				{
					flg = 1;
					break;	
				} 
			}
			fclose(fp);
			
			if(flg == 1)
			{
				r.balance = r.balance + TransferAmount;
				s.balance = s.balance - TransferAmount;
				update_file(r);
				update_file(s);

				if(tempo==1)
				{
					printf("\nTransaction Failed\n");
				}
				else
				{
					printf("\n%d Amount has been Succesfully Transferred\n",TransferAmount);
					printf("Do you want the recipt?\n");
					printf("<1>. YES \n<2>. NO	 \n");
					scanf("%d",&temp4);
					if(temp4==1) 
					{
						printf("Please collect the recipt\n\n");
					}
					
					else if(temp4==2)
					{
						printf("Thank you for saving paper\n");
					}
					
					else
					{
						printf(" *** THANKYOU FOR USING ATM ***");
			    	}
				}
			}
			
			else
			{
				printf("\nAccount not found !\n");
			}
		}
		else if(temp3==2)
		{
			printf("Transaction Cancelled\n\n");
			printf(" *** THANKYOU FOR USING ATM ***");
		}
			
		else
		{
			d=1;
			EnhancedSecurity();
		}
	
	}
}

int SecurityCheck()
{
	// Function to ask PIN and card
	
	int i=0;
	while(i<3)
	{
		int SecretePIN = 0 , attempt=1;
		printf("Enter your PIN Number\n");
		scanf("%d", &SecretePIN);
		if(SecretePIN == s.pin)
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
		{
			Withdraw();
			break;
		}
		
		else if(b==1)
		{
			Deposit();
			break;
		}
		     
		else if(c==1)
		{
			BalanceInquiry();
			break;
		}
		
		else if(d==1)
		{
			MoneyTransfer();
			break;
		}
	}

	if(Chance==3)
	{
		printf("Please try again after some time\n\n");
		printf("**** THANKYOU FOR USING ATM ****\n");
	}
}

int CardVerification()
{

    char AcNo[50];
    int pin=0 , flag=0 , count=0  ;
    
    fp = fopen("Account_Details.dat", "ab+");
 
    if(fp == NULL)
    {
        exit(1);
    }
  
	printf("Enter your account number");
    fflush(stdin);
    gets(AcNo);
    
    
    while( fread(&s, sizeof(struct AccountHolder), 1, fp) == 1 )
    {
		if(strcmp(AcNo , s.AccountNumber)==0)
		{
			flag=1;
			break;
		}
	}

	fclose(fp);
	
	if(flag==0)
	{
		printf("Please enter a valid card number\n");
	}
	else{

		printf("\nWelcome %s\n",s.name);
			
		PINMenu:
		printf("\nPlease enter your PIN\n");
		scanf("%d",&pin);
		
		if(pin==s.pin)
		{
			MainMenu();  
		}
		
		else
		{
			printf("Wrong pin , Please try again\n");
			count++;
			if(count!=3)
				goto PINMenu;
			else
				printf("\nPlease try again after some time.\n");
		}
	}
}

int main()
{
	CardVerification();
	return 0;
}
