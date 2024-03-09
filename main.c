#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>
int main_exit;
void menu_admin();
void menu_client();
void erase();
void close();
struct date{
    int month,day,year;

    };
struct TimeRange {
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
};
struct {

    char name[60];
    char password[10];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction,receiver,sender;
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void setColor(int textColor, int bgColor) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console, textColor | (bgColor << 4));
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void getPassword(char password[],int taille) {
    int i = 0;
    char ch;
    while (i<taille-1) {
        ch = getchar();
        if (ch == '\r') {
            break;
        } else if (ch =='\b' && i > 0) {
            printf("\b\b");
            i--;
        } else  {
            password[i]=ch;
            printf("*");
            i++;
        }
}
password[i]='\0';
}
void new_acc()

{
    int choice;
    FILE *ptr;

    ptr=fopen("record.dat","a+");
    account_no:
    system("cls");
    printf("\t\t\t\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the account number:");
    scanf("%d",&check.acc_no);
    while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
    {
        if (check.acc_no==add.acc_no)
            {printf("Account no. already in use!");
            fordelay(1000000000);
                goto account_no;

            }
    }
    add.acc_no=check.acc_no;
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the citizenship number:");
    scanf("%s",add.citizenship);
    printf("\nEnter the phone number: ");
    scanf("%lf",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f",&add.amt);
    printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
    scanf("%s",add.acc_type);
    printf("enter the password of account ");
    scanf("%s",add.password);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_admin();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void view_list()
{
    FILE *view;
    view=fopen("record.dat","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

    while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
       {
           printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
    fclose(view);
    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");}

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_admin();
        else if(main_exit==0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
                {printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2)
                {
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
                system("cls");
                printf("\t\t\t\t\t\t\t\t\t\tChanges saved!");
                }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
    }

fclose(newrec);
fclose(old);
remove("record.dat");
rename("new.dat","record.dat");
if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu_admin();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    edit();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_admin();
        else
            close();
        }
}
void erase(void)
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
                 if (main_exit==1)
                    menu_admin();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_admin();
        else
            close();
        }

}
void transact_admin(void) {
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    if (old == NULL || newrec == NULL) {
        printf("Error opening files.");
        exit(1);
    }

    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);

    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password) != EOF) {
        if (add.acc_no==transaction.acc_no) {
            test = 1;

            if (strcasecmp(add.acc_type, "fixed1") == 0 || strcasecmp(add.acc_type, "fixed2") == 0 || strcasecmp(add.acc_type, "fixed3") == 0) {
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
                fordelay(1000000000);
                system("cls");
                menu_admin();
            }

            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice (1 for deposit and 2 for withdraw):");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                printf("\n\nDeposited successfully!");
            } else {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%f", &transaction.amt);
                if (transaction.amt > add.amt) {
                    printf("Insufficient funds!");
                    fclose(old);
                    fclose(newrec);
                    remove("new.dat");
                    menu_admin();
                }
                add.amt -= transaction.amt;
                printf("\n\nWithdrawn successfully!");
            }

            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year, add.password);
        } else {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n", add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year, add.password);
        }
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat", "record.dat");

    if (test != 1) {
        printf("\n\nRecord not found!!");
        transact_invalid:
        printf("\n\n\nEnter 0 to try again, 1 to return to main menu and 2 to exit:");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 0)
            transact_admin();
        else if (main_exit == 1)
            menu_admin();
        else if (main_exit == 2)
            close();
        else {
            printf("\nInvalid!");
            goto transact_invalid;
        }
    } else {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 1)
            menu_admin();
        else
            close();
    }
}

void see_deletion_request() {
    printf("Here you can find customer account deletion requests\n");

    FILE *pr = fopen("request.txt", "r");
    if (pr == NULL) {
        printf("There are no existing requests");
        de_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_admin();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto de_invalid;
        }
    }
    char request[150], reason[150];
   while (fscanf(pr, "%s %s %d", request, reason, &add.acc_no) == 3) {
    // Print each request and reason inside the loop
    printf("Request: %s\n", request);
    printf("Reason: %s\n", reason);
    printf("Account Number: %d\n\n", add.acc_no);
}

if (feof(pr)) {
    printf("End of file reached\n");
} else if (ferror(pr)) {
    perror("Error reading from file");
}

fclose(pr);


    fclose(pr);

    erase_invalid:
    printf("\nEnter 0 to delete, 1 to return to the main menu, and 2 to exit: ");
    scanf("%d", &main_exit);

    switch (main_exit) {
        case 1:
            menu_admin();
            break;
        case 2:
            close();
            break;
        case 0:
            erase();
            break;
        default:
            printf("\nInvalid!\a");
            goto erase_invalid;
    }
}
  fclose(pr);
void see_creation_request(){
         printf("\t\t\t\t\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
FILE *fp=fopen("recordC.dat","r");
FILE *ptr=fopen("record.dat","a+");
        while(fscanf(fp, "%s %d/%d/%d %d %s %s %lf %s %f\n", add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt)!=EOF){
    printf("\n\n%s %d/%d/%d %d %s %s %lf %s %f \n",add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt);
    printf("\n\n\nEnter today's date(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
    printf("\nEnter the num of account:");
    scanf("%d",&add.acc_no);
    printf("\nEnter the password :");
    scanf("%s",add.password);
    fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
    printf("\nAccount created successfully!");
}
fclose(fp);
fclose(ptr);
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu_admin();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void virement_admin(void) {
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    if (old == NULL || newrec == NULL) {
        perror("Error opening files");
        return;
    }

    int test1 = 0, test2 = 0;

    printf("Enter the sender's account number: ");
    scanf("%d", &sender.acc_no);

    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password) != EOF) {
        if (add.acc_no == sender.acc_no) {
            test1 = 1;
            sender=add;
            printf("Enter the receiver's account number: ");
            scanf("%d", &receiver.acc_no);

             while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password) != EOF) {
                if (add.acc_no == receiver.acc_no) {
                    test2 = 1;
                     receiver=add;
                    break; // Exit the inner loop once the receiver is found
                }
            }

            if (test1 == 1 && test2 == 1) {
                printf("Enter the amount you wish to transfer: ");
                scanf("%f", &transaction.amt);

                // Update sender's and receiver's amounts
                sender.amt -= transaction.amt;
                receiver.amt += transaction.amt;

                // Write updated information to the new file
                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",
                        sender.acc_no, sender.name, sender.dob.month, sender.dob.day, sender.dob.year,
                        sender.age, sender.address, sender.citizenship, sender.phone,
                        sender.acc_type, sender.amt, sender.deposit.month, sender.deposit.day, sender.deposit.year, sender.password);

                fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",
                        receiver.acc_no, receiver.name, receiver.dob.month, receiver.dob.day, receiver.dob.year,
                        receiver.age, receiver.address, receiver.citizenship, receiver.phone,
                        receiver.acc_type, receiver.amt, receiver.deposit.month, receiver.deposit.day, receiver.deposit.year, receiver.password);

                printf("Transaction completed successfully!");
            } else {
                printf("Sender or receiver account not found. Transaction canceled.");
            }
        } else {
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s \n",
                    add.acc_no, add.name, add.dob.month, add.dob.day, add.dob.year,
                    add.age, add.address, add.citizenship, add.phone,
                    add.acc_type, add.amt, add.deposit.month, add.deposit.day, add.deposit.year, add.password);
        }
    }

    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

    printf("\nEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d", &main_exit);
    system("cls");

    if (main_exit == 1)
        menu_admin();
    else
        close();
}

void deletion_request() {
    char request[150];
    char reason[150];
    char response[10];

    FILE *pr = fopen("request.txt", "a+");
    FILE *ptr = fopen("record.dat", "r");

    if (pr == NULL || ptr == NULL) {
        perror("Error opening files");
        return;
    }

    printf("Enter the account number: ");
    scanf("%d", &check.acc_no);

    int account_found = 0;

    while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %d\n",
                  &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age,
                  add.address, add.citizenship, &add.phone, add.acc_type, &add.amt,
                  &add.deposit.month, &add.deposit.day, &add.deposit.year, &add.password) != EOF) {
          // int account_found = 0;
	    if (check.acc_no == add.acc_no) {
            account_found = 1;

            printf("Are you sure you want to delete your account? (Enter 'yes' to confirm or 'no' to cancel): ");
            scanf("%9s", response);

            if (strcmp(response, "yes") == 0) {
                printf("Enter your request for deletion: ");
                scanf("%s", request);
                printf("Enter your reason for deletion: ");
                scanf("%s", reason);

                fprintf(pr,"%s %s %d\n", request, reason, add.acc_no);

                printf("Your account deletion request has been recorded. An administrator will review your request.\n");
                fclose(pr);
                fclose(ptr);


                demande_invalid:
                printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
                scanf("%d", &main_exit);
                system("cls");

                if (main_exit == 1)
                    menu_client();
                else if (main_exit == 0)
                    close();
                else {
                    printf("\nInvalid!\a");
                    goto demande_invalid;
                }
            }else {
                printf("Your account deletion request has been canceled.\n");
                dm_invalid:
                printf("\n\nEnter 1 to go to the main menu and 0 to exit: ");
                scanf("%d", &main_exit);
                system("cls");

                if (main_exit == 1)
                    menu_client();
                else if (main_exit == 0)
                    close();
                else {
                    printf("\nInvalid!\a");
                    goto dm_invalid;
                }

            }
        }
    }
    if (!account_found) {
        printf("Client not found.\n");
        printf("Please check your account number.\n");
        system("cls");

        retour_invalid:
        printf("\n\nEnter 1 to repeat your request and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 1)
            deletion_request();
        else if (main_exit == 0)
            close();
        else {
            printf("\nInvalid!\a");
            goto retour_invalid;
        }
    }

    fclose(ptr);
}
void see(void)
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu_admin();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu_admin();
        }

        else
           {

             system("cls");
            close();
            }

}

void creation_request()
{
    FILE *fp = fopen("recordC.dat", "a+");
    char response[10];
    printf("Do you want to create a new account?\n(yes/no): ");
    scanf("%s", response);
    if (strcmp(response, "yes") == 0)
    {
        printf("\nEnter your information:\n");
        printf("Enter the name: ");
        scanf("%s", add.name);
        printf("Enter the date of birth (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
        printf("Enter the age: ");
        scanf("%d", &add.age);
        printf("Enter the address: ");
        scanf("%s", add.address);
        printf("Enter the phone number: ");
        scanf("%lf", &add.phone);
        printf("Enter your citizenship: ");
        scanf("%s", add.citizenship);
        printf("Enter the amount to deposit: $");
        scanf("%f", &add.amt);
        printf("Type of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice: ");
        scanf("%s", add.acc_type);
        fprintf(fp, "%s %d/%d/%d %d %s %s %lf %s %f\n", add.name, add.dob.month, add.dob.day, add.dob.year, add.age, add.address, add.citizenship, add.phone, add.acc_type, add.amt);
        fclose(fp);
        printf("\nAccount created successfully.\n");
        printf("Visit your AGENCE BANK to get the password AND account number.\n");
        add_invalid:
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");
        if (main_exit == 1)
            menu_client();
        else if (main_exit == 0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
    }
    else if (strcmp(response, "no") == 0)
    {
        printf("\n\t\tThanks for visiting! Please consider creating an account.\t\t\n");

        ad_invalid:
        printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 1)
            menu_client();
        else if (main_exit == 0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto ad_invalid;
        }
    }
    else
    {
        printf("\nInvalid input.\n");

        dd_invalid:
        printf("\nEnter 1 to try again, 2 to go to the main menu, and 0 to exit: ");
        scanf("%d", &main_exit);
        system("cls");

        if (main_exit == 1)
            creation_request();
        else if (main_exit == 2)
            menu_client();
        else if (main_exit == 0)
            close();
        else
        {
            printf("\nInvalid!\a");
            goto dd_invalid;
        }
    }
    fclose(fp);
}
void see_client(void)
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("record.dat","r");
    printf("Do you want to check by\n1.Account no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {   printf("Enter the account number:");
        scanf("%d",&check.acc_no);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
        {
            if(add.acc_no==check.acc_no)
            {   system("cls");
                test=1;

                printf("\nAccount NO.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$ %.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);


            }
        }
    }
    else if (choice==2)
    {   printf("Enter the name:");
        scanf("%s",check.name);
        while (fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
        {
            if(strcmp(add.name,check.name)==0)
            {   system("cls");
                test=1;
                printf("\nAccount No.:%d\nName:%s \nDOB:%d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

            }
        }
    }

    fclose(ptr);
     if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            see_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)
                    menu_client();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see_client();
                else
                    {
                        system("cls");
                        printf("\nInvalid!\a");
                        goto see_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);}
        if (main_exit==1)
        {
            system("cls");
            menu_client();
        }

        else
           {

             system("cls");
            close();
            }

}
void update_ifo(){
    int test=0;
    int choice;
    FILE *old=fopen("record.dat","r");
    FILE *newrec=fopen("new.dat","w");
    printf("\nEnter the account no. of the account ");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year,add.password)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {   test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1){printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
                system("cls");
                printf("Changes saved!");
                }
            else if(choice==2){
                printf("Enter the new phone number:");
                scanf("%lf",&upd.phone);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
                system("cls");
                printf("Changes saved!");
                }
        }
        else
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year,add.password);
    }
    fclose(old);
    fclose(newrec);
    remove("record.dat");
    rename("new.dat","record.dat");

if(test!=1)
        {   system("cls");
            printf("\nRecord not found!!\a\a\a");
            edit_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);
              system("cls");
                 if (main_exit==1)

                    menu_client();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    update_ifo();
                else
                    {printf("\nInvalid!\a");
                    goto edit_invalid;}
        }
    else
        {printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu_client();
        else
            close();
        }
}
// Fonction pour afficher l'horaire de la banque et les coordonnées
void displayBankSchedule() {
    // Define time ranges
    struct TimeRange morningSchedule = {9, 0, 12, 0};
    struct TimeRange afternoonSchedule = {14, 0, 17, 0};

    // Get the current time
    time_t currentTime = time(NULL);
    struct tm *timeInfo = localtime(&currentTime);
    int currentHour = timeInfo->tm_hour;
    int currentMinute = timeInfo->tm_min;

    // Check if the bank is open
    if ((currentHour > morningSchedule.startHour || (currentHour == morningSchedule.startHour && currentMinute >= morningSchedule.startMinute)) &&
        (currentHour < morningSchedule.endHour || (currentHour == morningSchedule.endHour && currentMinute <= morningSchedule.endMinute)) ||
        (currentHour > afternoonSchedule.startHour || (currentHour == afternoonSchedule.startHour && currentMinute >= afternoonSchedule.startMinute)) &&
        (currentHour < afternoonSchedule.endHour || (currentHour == afternoonSchedule.endHour && currentMinute <= afternoonSchedule.endMinute))) {
        printf("The bank is open.\n");
        // Coordonnées de la banque (fictives)
        printf("Contact Information:\n");
        printf("Phone: +1 (555) 123-4567\n");
        printf("Address: 123 SIDI ABID, EL HOCEIMA, MAROC\n");
        printf("Email: Bankati@gmail.com\n");
        // Ajoutez d'autres informations de contact au besoin
    } else {
        printf("The bank is closed.\n");
        printf("Contact Information:\n");
        printf("Phone: +1 (555) 123-4567\n");
        printf("Address: 123 SIDI ABID, EL HOCEIMA, MAROC\n");
        printf("Email: Bankati@gmail.com\n");
    }

    // Afficher les heures de travail de la banque dans la console
    printf("Bank's Working Hours:\n");
    printf("Morning: %02d:%02d - %02d:%02d\n", morningSchedule.startHour, morningSchedule.startMinute, morningSchedule.endHour, morningSchedule.endMinute);
    printf("Afternoon: %02d:%02d - %02d:%02d\n", afternoonSchedule.startHour, afternoonSchedule.startMinute, afternoonSchedule.endHour, afternoonSchedule.endMinute);

    // Ajouter la gestion du retour au menu principal
    int main_exit;
    printf("\nEnter 1 to return to the main menu and 2 to exit:");
    scanf("%d", &main_exit);
    if (main_exit == 1)
        menu_client();
    else if (main_exit == 2)
        close();
    else {
        printf("\nInvalid!\a");
        goto edi_invalid;
    }

edi_invalid:
    return;
}
void close(void)
{
    printf("\n\n\n\n\t\t\t\tThank you for using our service. See you soon!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    main();
}
void menu_admin(void)
{   int choice;
    system("cls");
    system("color 3");
     printf("\n\n\t\t\t              CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\n\t\t\t\t      \xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 1. Create new account             *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 2. Update information of          *\n");
    printf("                        \t\t*    existing account               *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 3. For transactions               *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 4. Money transfer                 *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 5. Check details of existing      *\n");
    printf("                        \t\t*    account                        *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 6. Removing existing account      *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 7. View customer's list           *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 8. View account deletion requests *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 9. View account creation requests *\n");
    printf("                        \t\t*************************************\n");
    printf("                        \t\t* 10.Exit                           *\n");
    printf("                        \t\t*************************************\n\n");
    printf("\t\t\t Enter your choice:");
    scanf("%d",&choice);

    system("cls");
    switch(choice)
    {
        case 1:new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact_admin();
        break;
        case 4:virement_admin();
        break;
        case 5:see();
        break;
        case 6:erase();
        break;
        case 7:view_list();
        break;
        case 8:see_deletion_request();
        break;
        case 9:see_creation_request();
        break;
        case 10:close();
        break;

    }
}
void menu_client(void)
{   int choice;
    system("cls");
    system("color 3");
    printf("\n\n\t\t\t              CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\n\t\t\t\t      \xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 1. Create new account          *\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 2. Update information of       *\n");
    printf("                        \t\t*    existing account            *\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 3. Check details of existing   *\n");
    printf("                        \t\t*    account                     *\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 4. Account deletion request    *\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 5. Bank working hours          *\n");
    printf("                        \t\t**********************************\n");
    printf("                        \t\t* 6. Exit                        *\n");
    printf("                        \t\t**********************************\n\n");
    printf("\t\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:creation_request();
        break;
        case 2:update_ifo();
        break;
        case 3:see_client();
        break;
        case 4:deletion_request();
        break;
        case 5:displayBankSchedule();
        break;
        case 6:close();
        break;

    }
}
int main(void) {
    FILE *ptr = fopen("record.dat", "r");
    char pass[10], password1[10] = "A1S2D3", password2[10] = "B2R3T4";
    int i;
    int found =0;
    int choice;
    system("color 9");
    printf("                             +---------------------------------------------------------+\n");
    printf("                             |                                                         |\n");
    printf("                             |           \xB2\xB2\xB2   Welcome to our service  \xB2\xB2\xB2             |\n");
    printf("                             |                                                         |\n");
    printf("                             +---------------------------------------------------------+\n");
    printf("\n\n\n");
    printf("                                          Are you an Admin or a Client?\n\n\n ");
    printf("                                     +-------------------------------+\n");
    printf("                                      |             0:CLIENT          |\n");
    printf("                                      +-------------------------------+\n");
    printf("                                      +-------------------------------+\n");
    printf("                                      |             1:ADMIN           |\n");
    printf("                                      +-------------------------------+\n\n\n\n\n\n");
    printf("                                                    Enter your choice: ");
    scanf("%d", &choice);
      if (choice == 0) {
         //printf("\n\n\t\Enter your name :") ;
         //scanf("%s",check.name);
    printf("\n\t\t\t\t\t\t\tEnter the password to login:");
    scanf("%s",check.password);
    //getPassword(check.password,sizeof(check.password));
     while (fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d %s", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year, add.password) != EOF) {
      if (strcmp(check.password, add.password) == 0) {
            printf("\nPassword Match!\nLOADING");

            for (i = 0; i <= 6; i++) {
                fordelay(100000000);
                printf(".");
            }
        found = 1;
        fclose(ptr);
        menu_client();
        break; // Sortie de la boucle une fois que le mot de passe est trouvé
    }
}

if (!found) {
    printf("\n\nWrong password!!\a\a\a");
    login_try:
    printf("\nEnter 1 to try again and 0 to exit: ");
    scanf("%d", &main_exit);

    if (main_exit == 1) {
        system("cls");
        main();
    } else if (main_exit == 0) {
        system("cls");
        close();
    } else {
        printf("\nInvalid!");
        fordelay(100000000);
        system("cls");
        goto login_try;
    }
}
}
    else if (choice == 1) {
        printf("\n\t\t\t\t\t\t\tEnter the password to login: ");
        scanf("%s", pass);

        if (strcmp(pass, password1) == 0 || strcmp(pass, password2) == 0) {
            printf("\nPassword Match!\nLOADING");

            for (i = 0; i <= 6; i++) {
                fordelay(100000000);
                printf(".");
            }

            system("cls");
            a_login:
            printf("\n\t\t\t\t\tEnter 1 to go to the menu and 0 to exit: ");
            scanf("%d", &main_exit);
            if (main_exit == 1) {
                system("cls");
                menu_admin();
            } else if (main_exit == 0) {
                system("cls");
                close();
            } else {
                printf("\nInvalid!");
                fordelay(100000000);
                system("cls");
                goto a_login;
            }
        } else {
            printf("\nWrong password!!\a\a\a");
            lo_try:
            printf("\nEnter 1 to try again and 0 to exit: ");
            scanf("%d", &main_exit);

            if (main_exit == 1) {
                system("cls");
                main();
            } else if (main_exit == 0) {
                system("cls");
                close();
            } else {
                printf("\nInvalid!");
                fordelay(100000000);
                system("cls");
                goto lo_try;
            }
        }
    } else {
        r_login:
        printf("\nEnter 1 to try again and 0 to exit: ");
        scanf("%d", &main_exit);

        if (main_exit == 1) {
            system("cls");
            main();
        } else if (main_exit == 0) {
            system("cls");
            close();
        } else {
            printf("\nInvalid!");
            fordelay(100000000);
            system("cls");
            goto r_login;
        }
    }
    fclose(ptr);
    return 0;
}
