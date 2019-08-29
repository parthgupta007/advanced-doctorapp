#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>

void userlogin(void);

struct user{
    char username[10];
    char password[10];
    char name;
	int number;
	long int adno;
	float time;
	int ch;
     int d;
}*pUser;

int main()
{
    userlogin ( );
    userbook ( );
    }
    int userbook(void)
{
   int ch,d;
    printf("choose your city to look for the nearest doctor 1.jaipur\n 2.dehradun\n 3.Mumbai\n 4.New delhi\n ");
     scanf("%d",&ch);

     
     switch( ch )
     {
        case 1 : printf( "you needed doctors in jaipur\n" );
        
        			 printf("choose your category to look for the nearest doctor 1.Internal Medicine Physician\n 2.Pediatrician\n 3.Surgeon\n 4.Cardiologist\n ");
     scanf("%d",&d);
     
     			
     				switch( ch )
     {
        case 1 : printf( "you needed doctors in jaipur\n" );
        
        			 printf("the timings are these");
        			
                   break;

        /* TODO (#1#): talk to team */
        case 2 : printf( "the timings are these" );
                   break;

        case 3 : printf( "the timings are these\n" );
                   break;

        case 4 : printf( "You needed doctors in delhi\n" );
                   break;


        default  : printf( "SORRY ! we are not currently available in your city . A city suggestion is sent. \n" );
                   break;
     }
     
     getch();
        			
                   break;

        /* TODO (#1#): talk to team */
        case 2 : printf( "You needed doctors in dehradun\n" );
                   break;

        case 3 : printf( "You needed doctors in Mumbai\n" );
                   break;

        case 4 : printf( "You needed doctors in delhi\n" );
                   break;


        default  : printf( "SORRY ! we are not currently available in your city . A city suggestion is sent. \n" );
                   break;
     }
     
     getch();
     MessageBox(0,"Your appontment is booked! Click on OK to get verification meesage ","Welcome Message",1);
     
     printf("your city is %ch and your category is %d");
     //check this please
     //we have to work on this as we will have to get the names from above and get these printed
     //then we will sk for the other details and addhar info
     
}

void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10];int i;char c;
    int ch;
     int d;

    pUser=(struct user *)malloc(sizeof(struct user));

    printf("1. Login Through An Existing Account\n2. Create New account\n");
    scanf("%d",& i);
    system("cls");
    switch(i){
        case 1:
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("The user does not exist, create a new user\n");
                    exit ( 1);
                }
            }
            printf("Username: ");
            scanf("%9s",uName);
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0 ) {
                    printf ("Match username\n");
                    if( strcmp ( pUser->password, pwd) == 0) {
                        printf ("Match password\n");
                        
                        userbook();
                
                    }
                }
            }
            break;

        case 2:
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        printf ("USer does not exist\n");
                        exit ( 1);
                    }
                }
                printf("Choose A Username: ");
                scanf("%9s",pUser->username);
                printf("Choose A Password: ");
                scanf("%9s",pUser->password);
                fwrite (pUser, sizeof(struct user), 1, fp);
               printf("Add another account? (Y/N): ");
                scanf(" %c",&c);//skip leading whitespace
               userlogin();

    
            }while(c=='Y'||c=='y');
            break;
            
             
    }
    free ( pUser);//free allocated memory
    fclose(fp);
}


