#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int info[20][7],transaction[20][20];
int date[20][20]={0}, j[20] = {0};
char name[20][30], address[20][30], phone[20][12], citynum[20][15];
static int user =0,a[20]={0};
int index, temp, mexit,x[6];
void eree(int i){
	time_t ;
    date[i][j[i]]= time(NULL);
    j[i]++;
}
void print_time(int t){
    int i;
    t+=7200+86400+2629800-31557600*30;
	int div[6]={31557600,2629800,86400,3600,60,1};
	for(i=0;i<5;i++){
        x[i]=t/div[i];
        t-=x[i]*div[i];
	}
	if(x[3]>12)
    x[3]-=12;
    printf("at %d:%d on %d/%d/20%d \n",x[3],x[4],x[2],x[1],x[0]);
}
void infopage(){
    printf("\n\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t      ACCOUNT TYPES\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    puts("  1.Saving bank account is a regular deposit account, where you earn 9%/12 rate of interest on the same day of \n    deposit of every month.\n\n");
    puts("  2.Current bank account is a deposit account for traders who need to make and receive payments more often than \n    others, these accounts are zero-interest bearing accounts.\n\n");
    puts("  3.Investment bank account is a regular deposit account, where you earn 13% rate of interest after 3 years from \n    date of deposition.\n\n");
}
float interest(float time,float balance,int rate){
    float I;
    I=(rate*time*balance)/100.0;
    return (I);

}
void check(){

    printf("\nPlease enter Account ID: ");
    scanf("%d",&temp);
    fflush(stdin);
    index = temp % 100 ;
    if(index<0 || index>=user || temp!=info[index][6]){
        puts("invalid bank ID");
        checkagain:
        printf("\n\t\t\tEnter 1 to tryagain, any number to go to main menu: ");
        scanf("%d",&mexit);
        if (mexit==1){
            fflush(stdin);
            system("cls");
            check();
        }
        else{
            system("cls");
            menu();
        }
    }
}
void typedec(int y ){
    if(y == 1){
        printf("Saving\n");
    }else if(y == 2){
        printf("Current\n");
    }else if(y == 3){
        printf("Investment\n");
    }
}
void delay(long long j){
       int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void new_acc(){
    int size,x;
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t     CREATE NEW ACCOUNT\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\nPlease enter your name: ");
    scanf(" %[^\n]s", &name[user]);
    printf("\n\t\t\t\t  MAKE SURE YOU ARE AT LEAST 18 YEARS OLD");
    do{
        printf("\nEnter the date of birth (dd/mm/yyyy):");
        scanf("%d/%d/%d", &info[user][0],&info[user][1],&info[user][2]);
        fflush(stdin);
    }while(info[user][0]<1 || info[user][0]>31 || info[user][1]<1 || info[user][1]>12 || info[user][2]>2004 || info[user][2]<1900);
    printf("\nPlease enter your age: ");
    scanf("%d", &info[user][3]);
    fflush(stdin);
    if(info[user][3]<17 || info[user][3] > 120){
        system("cls");
        printf("\n\t\t\t\t  YOU ARE NOT ELIGBLE FOR CREATING AN ACCOUNT\n");
        delay(1800000000);
        menu();
    }
    do{
        printf("\nEnter your citizenship number:");
        scanf("%s", &citynum[user]);
        size = strlen(citynum[user]);
    }while(size != 14);
    do{
        printf("\nEnter your phone number: ");
        scanf("%s", &phone[user]);
        size = strlen(phone[user]);
    }while(size != 11);
    printf("\nEnter your address:");
    scanf(" %[^\n]s" , &address[user]);
    info:
    do{
        printf("\nType of account:\n\t1.Saving\n\t2.Current\n\t3.Investmint\n\t4.For more information about account types.\n\n\tEnter your choice(1~4):");
        scanf("%d", &info[user][5]);
        fflush(stdin);
        if(info[user][5] == 4){
            infopage();
            delay(1000000000);
            goto info;
        }
    }
    while(info[user][5] < 1 || info[user][5] > 4);
    do{
        printf("\t\t\tTo create an account you must deposit minimum of $100\nEnter the amount to deposit: $");
        scanf("%d", &info[user][4]);
        fflush(stdin);
        transaction[user][0]=info[user][4];
    }while(info[user][4]<100);
    eree(user);
    info[user][6]=1200000+(info[user][2]%100)*1000+info[user][5]*100+user;
    //    info[user][6] is the bank ID
    printf("your account has been created successfully!\n");
    printf("\t\t\tyour bank ID is: %d\n",info[user][6]);
    user++;
    system("pause");
    system("cls");
    menu();
}
void view_list(){

    int j;
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t   VIEW CUSTOMER'S LIST\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    if(user>0){
        for(j=0;j<user;j++){
            if(info[j][3]==0){
                continue;
            }else{
                printf("Account number: %d\n",j+1);
                printf("Name: %s\n",name[j]);
                printf("Citizenship number: %s\n", citynum[j]);
                printf("Age: %d\n", info[j][3]);
                printf("Phone Number: %s\n",phone[j]);
                printf("Account type: "); typedec(info[j][5]);
                printf("Address: %s\n", address[j]);
                printf("Account ID: %d\n", info[j][6]);
                printf("----------------------------\n");
            }
        }
        printf("\n\tNo more Users\n\n");
    }else{
        printf("\n\n\tNo Users found\n\n");
    }
    system("pause");
    system("cls");
    menu();
}
void edit(){
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t   UPDTAE INFORMATION OF EXISTING ACCOUNT\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    check();
    int x,size;
    do{
        printf("\n\nDo you want to edit:\n1.Address.\n2.Phone number.\n3.Both.\n\n\n\t Choose your operation from 1 ~ 3:");
        scanf("%i",&x);
        fflush(stdin);
    }while(x!=1&&x!=2&&x!=3);
    if(x==1){
        printf("\nEnter your new address: ");
        scanf(" %[^\n]s" , &address[index]);
        printf("\nThe new address is: %s\n", address[index]);
    }else if(x==2){
        do{
            printf("\nEnter your new phone number: ");
            scanf("%s", &phone[index]);
            size = strlen(phone[index]);
        }while(size != 11);
    printf("\nThe new phone number is: %s\n", phone[index]);
    }else{
        printf("\nEnter your new address: ");
        scanf(" %[^\n]s" , &address[index]);
        do{
            printf("\nEnter your new phone number: ");
            scanf("%s", &phone[index]);
            size = strlen(phone[index]);
        }while(size != 11);
        printf("\nThe new phone number is: %s\n", phone[index]);
        printf("\nThe new address is: %s\n", address[index]);
    }
    printf("\n\n\t\t\tEnter 1 to edit again, any number to return to main menu: ");
    scanf("%d",&mexit);
    fflush(stdin);
    if (mexit==1){
        system("cls");
        edit();
    }
    else{
        system("cls");
        menu();
        }
}
void transact(){
    int y,money;
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t       TRANSACTIONS\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    check();
    do{
        printf("\n\nDo you want to\n\t1.Deposit\n\t2.Withdraw?\n\nEnter your choice:");
        scanf("%d",&y);
        fflush(stdin);
    }while(y!=1&&y!=2);
    a[index]++;
    eree(index);
    if(y==1){
        printf("Please enter the amount of money you want to deposit: $");
        scanf("%d",&money);
        fflush(stdin);
        printf("\n\nDeposited successfully!\n");
        transaction[index][a[index]]=transaction[index][a[index]-1]+money;
    }else{
        printf("Please enter the amount of money you want to withdraw: $");
        scanf("%d",&money);
        fflush(stdin);
         if(money > transaction[index][a[index]-1]){
            printf("No suffecient balance to withdraw.");
            a[index]--;
        }
        else{
        printf("\n\nWithdrawn successfully!\n");
        transaction[index][a[index]]=transaction[index][a[index]-1]-money;
        }
    }
    printf("\t\t\t\t\t----------------------------\n");
    printf("\t\t\t\t\tYour current balance  = $%d \n",transaction[index][a[index]]);
    printf("\t\t\t\t\t----------------------------\n");
    printf("\n\n\t\t\tEnter 1 to make another transaction, any number to return to main menu: ");
    scanf("%d",&mexit);
    fflush(stdin);
    if (mexit==1){
            system("cls");
            transact();
    }
    else{
        system("cls");
        menu();
        }
}
void erase(){
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t  REMOVING EXISTING ACCOUNT\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    check();
    int i;

    strcpy(name[index],"0");
    for (i=0;i<7;i++){
        info[index][i]=0;
    }

    printf("\n\t\t\t\t    User has been deleted successfully!");
    printf("\n\n\t\t\tEnter 1 to delete another account, any number to return to main menu: ");
    scanf("%d",&mexit);
    fflush(stdin);
    if (mexit==1){
            system("cls");
            erase();
    }
    else{
        system("cls");
        menu();
        }
}
void see(){
    int i,rate;
    float time, intrst;
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t      CHECK DETAILS OF EXISTING ACCOUNT\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    check();
    if(info[index][3]==0){
        printf("\nNo user found with this ID \n");
    }else{
        printf("Account ID: %d\n", info[index][6]);
        printf("Name: %s\n",name[index]);
        printf("Citizenship number: %s \n", citynum[index]);
        printf("Age: %d\n", info[index][3]);
        printf("Phone Number: %s\n",phone[index]);
        printf("Account type: "); typedec(info[index][5]);
        printf("Address: %s\n", address[index]);
        printf("Your starting balance = $%d \n",transaction[index][0]);
        print_time(date[index][0]);
        if(info[index][5]==1){
                time=(1.0/12.0);
                rate=9;
                intrst=interest(time,transaction[index][a[index]],rate);
                printf("\nYou will get $%.2f as interest on day %d of every month\n",intrst,x[2]);

        }else if(info[index][5] == 3){
                time=3.0;
                rate=13;
                intrst=interest(time,transaction[index][a[index]],rate);
                printf("\nYou will get $%.2f as interest on %d/%d/20%d\n",intrst,x[2],x[1],x[0]);
        }else if(info[index][5]==2){
                printf("\nYou will get no interest\n");
        }
        printf("\t***Account history*** \n");
    for(i=1;i<a[index];i++){
        int delta = transaction[index][i] - transaction[index][i-1];
        if(delta>0){
            printf("The user has deposited $%d ",delta);
        }else{
            printf("The user has withdrawn  $%d ",0-delta);
        }
        print_time(date[index][i]);
        printf("\nBalance became = $%d \n",transaction[index][i]);
        }
    int delta = transaction[index][a[index]] - transaction[index][a[index]-1];
    if(delta>0){
        printf("The user has deposited $%d ",delta);
    }else{
        printf("The user has withdrawn  $%d ",0-delta);
    }
    print_time(date[index][a[index]]);
    printf("\nBalance became = $%d \n",transaction[index][a[index]]);
    printf("----------------------------\n");
    }
    printf("\n\t\t\tEnter 1 to check for another user, any number to main menu: ");
    scanf("%d",&mexit);
    fflush(stdin);
    if (mexit==1){
        system("cls");
        see();
    }
    else{
        system("cls");
        menu();
            }
}
void search(){
    int choice,i,checker=0;
    char name_check[30];
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\tSEARCH FOR AN EXISTING USER\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\nPlease enter the user's name: ");
    scanf(" %[^\n]s", &name_check);
    for(i = 0; i<user; ++i){
    if(strcmp(name_check,name[i]) == 0){
            printf("\nAccount ID: %d\n", info[i][6]);
            printf("Name: %s\n",name[i]);
            printf("Citizenship number: %s \n", citynum[i]);
            printf("Age: %d\n", info[i][3]);
            printf("Phone Number: %s\n",phone[i]);
            printf("Account type: "); typedec(info[index][5]);
            printf("Address: %s\n\n", address[i]);
            printf("-----------------\n");
            checker++;
    }else{
        if(i==user-1&&checker==0){
              printf("\n\t\tNo Users with this name\n");
              goto tryagain3;
        }
        continue;
    }
    }
    tryagain3:
    printf("\n\t\t\tEnter 1 to search again, any number to main menu: ");
    scanf("%d",&mexit);
    fflush(stdin);
    if (mexit==1){
        system("cls");
        search();
    }
    else{
        system("cls");
        menu();
    }
}
void sort(){
    int i,j,k;
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\t\t  SORT ALL USERS BY NAME\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    char s[20],temp[20][20];
    for(i=0;i<user;++i){
        strcpy(temp[i],name[i]);
    }
    for(i=0;i<user;i++){
        for(j=i+1;j<user;j++){
            if(strcmp(temp[i],temp[j])>0){
            //change name
            strcpy(s,temp[i]);
            strcpy(temp[i],temp[j]);
            strcpy(temp[j],s);
            }
        }
    }
    for(j=0;j<user;j++){
        for(i = 0; i<user; ++i){
            if(strcmp(temp[j],name[i]) == 0){
                if(info[j][3]==0){
                    continue;
                }else{
                    if(strcmp(name[i],"0") == 0){
                        continue;
                    }
                    printf("\nName: %s\n",name[i]);
                    printf("Citizenship number: %s \n", citynum[i]);
                    printf("Age: %d\n", info[i][3]);
                    printf("Phone Number: %s\n",phone[i]);
                    printf("Account type: "); typedec(info[i][5]);
                    printf("Address: %s\n", address[i]);
                    printf("Account ID: %d\n\n", info[i][6]);
                    printf("-----------------\n");
                }
            }
        }
    }
    system("pause");
    system("cls");
    menu();
}
void close_program(){
    printf("\n\nThank you for using our program!\n\n");
    }
void menu(){
    void (*mptr[9])()= {new_acc, edit, transact, see, erase, view_list, search, sort, close_program};
    int choice = -1;
    system("cls");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\t\t\t\t\t WELCOME TO THE MAIN MENU\n");
    printf("\t\t\t-----------------------------------------------------------\n");
    printf("\n\n1.Create new account.\n2.Update information of existing account.\n3.Transactions.\n4.Check the details of existing account.\n5.Removing existing account.\n6.View customer's list.\n7.Search for an existing user.\n8.Sort all users by name.\n9.Exit\n\n\n\t Choose your operation from 1 ~ 9 :");
    scanf("%d",&choice);
    fflush(stdin);
    if(choice >= 1 && choice <= 9){
        system("cls");
        mptr[choice -1]();
        return 0;
    }else{
    printf("\tPLEASE SELECT OPERATION FROM THE VIEWED LIST!!");
    delay(1500000000);
    menu();
    }
}
int main(){
    char word[10],password[10]="agmdteam";
    int i=0,mexit;
    printf("\nEnter the password to login:");
    scanf("%s",word);
    if (strcmp(word,password)==0){
        printf("\n\nChecking");
        for(i=0;i<=4;i++){
            delay(100000000);
            printf(".");
        }
        printf("\n\nPassword Match!");
        delay(100000000);
        system("cls");
        menu();
    }else{
        printf("\n\nChecking");
        for(i=0;i<=4;i++){
                delay(100000000);
                printf(".");
        }
        printf("\n\nWrong password!!\n\n");
        tryagain:
        printf("\n\tEnter 1 to try again and 0 to exit:");
        scanf("%d",&mexit);
        fflush(stdin);
        if (mexit==1){
            system("cls");
            main();
        }else if (mexit==0){
            system("cls");
            printf("\n\nThank you for using our program!\n\n");
        }else{
            printf("\nInvalid, please try again.");
            delay(1000000000);
            system("cls");
            goto tryagain;
        }
    }
	
    return 0;
}
