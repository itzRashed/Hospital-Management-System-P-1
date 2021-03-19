#include<stdio.h>//Use for standard I/O Operation
#include<windows.h>
#include<conio.h>//Use for delay(),getch(),gotoxy(),etc.
#include<ctype.h>//se for toupper(), tolower(),etc
#include<string.h>
#include<stdlib.h>
#include<time.h> //for time

char ans=0;
int ok;
int b, valid=0;
char result=0;
int temp;
int count=0;
int i,j,num;
FILE *signUp;
void WelcomeScreen(void);//WelcomeScreen function decleration
void Title(void);//Title function decleration
void Patient(void);
void LoginScreen(void);//LoginScreen function decleration
void Add_patient_rec(void);//Add_rec function declaration
void patient_list(void);//function to list the details
void Search_patient_rec(void);//Search_rec function declaration
void Edit_patient_rec(void);//Edit_rec function declaration
void Dlt_patient_rec(void);//Dlt_rec function declaration
void staff(void);
void Add_staff_rec(void);//Add_rec function declaration
void staff_list(void);//function to list the patient details
void Search_staff_rec(void);//Search_rec function declaration
void Edit_staff_rec(void);//Edit_rec function declaration
void Dlt_staff_rec(void);
void MainMenu(void);
void doctor_information();
void Medicine();
void Cancer();
void Thyroid();
void Diabetes();
void Heart_problem();
void Back2();
void nurse(void);
void Add_nurse_rec(void);//Add_rec function declaration
void nurse_list(void);//function to list the  details
void Search_nurse_rec(void);//Search_rec function declaration
void Edit_nurse_rec(void);//Edit_rec function declaration
void Dlt_nurse_rec(void);
void patient_profile(void);
void add_appointment();
void Medicine2();
void Cancer2();
void Thyroid2();
void Diabetes2();
void Heart_problem2();
void Search_appointment_rec();
void Edit_appointment();
void user(void);
void Cancel_appointment();
void signup(void );
void signin( void);
void user_panel();
void Appointment_information();
int t();

struct patient
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[20];
};
struct patient  p,temp_c;
struct staff
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char deg[20];
    char Position[20];
};
struct staff  s,temp_t;
struct nurse
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Shift[20];
};
struct nurse n,temp_u;
struct info_patient
{
    int age;
    char Gender;
    char First_Name[20];
    char Last_Name[20];
    char phone_no[15];
    char Address[30];
    char Email[30];
    char Doctor_Name[20];
    char Problem[20];
};
struct info_patient person;
typedef struct
{

    char first_name[20];
    char last_name[20];
    char username[20];
    char password[20];


} login_screen;
login_screen pi;

struct meroDate
{
int mm,dd,yy;
};

int t(void) //for time
{
time_t t;
time(&t);
printf("Date & Time : %s\n",ctime(&t));
}

void gotoxy(short x, short y)
{
    COORD pos = {x, y};//sets co-ordinates in (x,y).
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
main(void)
{
    system("COLOR 71");
    WelcomeScreen();//Use to call WelcomeScreen function
    Title();//Use to call Title function
    Panel();
}
void WelcomeScreen(void) //function for welcome screen
{

    printf("\n\n\n\n\n\n\n\t\t\t\t###############################################################################################################");
    printf("\n\t\t\t\t*\t\t\t\t\t\t\tWELCOME TO\t\t                              *");
    printf("\n\t\t\t\t*                                                 HOSPITAL MANAGEMENT SYSTEM                                  *");
    printf("\n\t\t\t\t###############################################################################################################");
    printf("\n\n\n\n\n\n\t\t\t\t");
    t();
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t  SQUARE HOSPITALS  LTD. \n\n\n\t\t\t\t\t\t\t\t\t\t\tMIRPUR ");
    printf("\n\t\t\t\t\t\t\t\t\t\tPlot # 9/2, Avenue # 5,\n\t\t\t\t\t\t\t\t\t\tSection # 6,");
    printf("Block # B,\n\t\t\t\t\t\t\t\t\t\tMirpur, Dhaka- 1216\n\t\t\t\t\t\t\t\t\t\tContact: 01313718686");
    printf("\n\n\n\n\n\t\t\t\t\t Press any key to continue......");
    getch();//Use to holds screen for some seconds
    system("cls");//Use to clear screen

}
void Title(void)//function for title screen
{
    printf("\n\n\t\t------------------------------------------------------------------------------------------------------------------------------------------------");
    printf("\n\t\t\t\t                                                   SQUARE HOSPITALS  LTD.        ");
    printf("\n\t\t------------------------------------------------------------------------------------------------------------------------------------------------");
}
void Panel()
{
    int c;
    printf("\n\n\t\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOG IN AS \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\n\n\n\t\t\t\t1.ADMIN\n");
    printf("\n\t\t\t\t2.USER\n");

    printf("\n\n\n\n\t\t\t\t\t\tEnter option : ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        LoginScreen();
        break;
    case 2:
        printf("User:");
        user();
        break;

    default:
        ex_it();

    }
}
void LoginScreen(void)//function for login screen
{
    system("cls");
    printf("\n\n\t\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADMIN LOG IN \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    int e=0	;
    char Username[15];
    char Password[15];
    char original_Username[25]="Team3";
    char original_Password[15]="TZR";

    do
    {
        printf("\n\n\n\n\t\t\t\tEnter your Username and Password .....");
        printf("\n\n\n\t\t\t\t\tUSERNAME : ");
        scanf("%s",&Username);

        printf("\n\n\t\t\t\t\tPASSWORD : ");
        scanf("%s",&Password);

        if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)
        {
            printf("\n\n\n\t\t\t\t\t...Login Successful...");


            getch();
            admin();
            break;
        }
        else
        {
            printf("\n\t\t\tPassword in incorrect. Try Again ");
            e++;
            getch();
        }

    }
    while(e<=2);
    if(e>2)
    {
        printf("You have cross the limit. You cannot login.");
        getch();
        ex_it();
    }

    system("cls");
}

void admin()
{
    system("cls");
    char choice;
    Title();// call Title function
    printf("\n\n\t\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 ADMIN PANEL \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t\t\t1.PATIENT'S INFORMATION");
    printf("\n\n\t\t\t\t2.STAFF'S INFORMATION");
    printf("\n\n\t\t\t\t3.DOCTOR'SINFORMATION");
    printf("\n\n\t\t\t\t4.NURSE'S INFORMATION");
    printf("\n\n\t\t\t\t5.APPOINTMENT INFORMATION");
    printf("\n\n\t\t\t\t6.BACK");
    printf("\n\n\t\t\t\t7.EXIT");
    printf("\n\n\n\t\t\t\t\tEnter your choice : ");
    fflush(stdin);
    choice=getche();
    switch(choice)
    {
    case '1':
        Patient();
        break;
    case '2':
        staff();
        break;
    case '3':
        MainMenu();
        break;
    case '4':
        nurse();
        break;
    case '5':
        Appointment_information();
        break;
    case '6':
        system("cls");
        Panel();
        break;
    case '7':
        ex_it();
        break;
    }
}
void Patient()
{
    system("cls");
    int choose;
    Title();// call Title function
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 PATIENT'S INFORMATION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
    printf("\n\t\t\t\t2. List Patients Record\n");
    printf("\n\t\t\t\t3. Search Patients Record\n");
    printf("\n\t\t\t\t4. Edit Patients Record\n");
    printf("\n\t\t\t\t5. Delete Patients Record\n");
    printf("\n\t\t\t\t6. Back\n");
    printf("\n\t\t\t\t7.Exit\n");
    printf("\n\n\n \n\t\t\t\t\t\tChoose from 1 to 7 : ");
    scanf("%i", &choose);

    switch(choose)//switch to different case
    {

    case 1:
        Add_patient_rec();//Add_rec function is called
        break;
    case 2:
        patient_list();//View_rec function is call
        break;
    case 3:
        Search_patient_rec();//search_rec function is call
        break;
    case 4:
        Edit_patient_rec();//Edit_rec function is call
        break;
    case 5:
        Dlt_patient_rec();//Dlt_rec function is call
        break;
    case 6:
    {
        system("cls");
        admin();
        break;
    }
    case 7:
        ex_it();//ex_it function is call
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getch();//holds screen
    }//end of switch


}

void Add_patient_rec()
{
    system("cls");
    char ans;
    FILE*ek;//file pointer
    ek=fopen("Patient_Record.txt","a");//open file in write mode
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Patients Record \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


    /* **************************First Name*********************************** */
A:
    printf("\n\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",p.First_Name);
    p.First_Name[0]=toupper(p.First_Name[0]);
    if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
    {
        printf("\n\t Invalid . \t The max range for first name is 20 and min range is 2 :");
        goto A;
    }
    else
    {
        for (b=0; b<strlen(p.First_Name); b++)
        {
            if (isalpha(p.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character :( Enter again ");
            goto A;
        }
    }

    /* ********************************************** Last name ************************************************ */
B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
    {
        printf("\n\t Invalid ..... \t The max range for last name is 20 and min range is 2 .");
        goto B;
    }
    else
    {
        for (b=0; b<strlen(p.Last_Name); b++)
        {
            if (isalpha(p.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character : ( Enter again.");
            goto B;
        }
    }
    /* ******************************************* Gender ************************************************************** */
    do
    {
        printf("\n\t\t\tGender[F/M] : ");
        scanf(" %c",&p.Gender);
        if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :( Enter either F or M :)");
        }
    }
    while(!ok);
    /* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge : ");
    scanf(" %i",&p.age);
    /* **************************************** Address ******************************************************************* */
    do
    {
C:
        printf("\n\t\t\tAddress : ");
        scanf("%s",p.Address);
        p.Address[0]=toupper(p.Address[0]);
        if(strlen(p.Address)>20||strlen(p.Address)<4)
        {
            printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
            goto C;
        }

    }
    while(!valid);
    /* ******************************************* Contact no. ***************************************** */
    do
    {
D:
        printf("\n\t\t\tContact no : ");
        scanf("%s",p.Contact_no);
        if(strlen(p.Contact_no)>11||strlen(p.Contact_no)!=11)
        {
            printf("\n\t Sorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
            goto D;
        }
        else
        {
            for (b=0; b<strlen(p.Contact_no); b++)
            {
                if (!isalpha(p.Contact_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    }
    while(!valid);
    /* ************************************************** Email ******************************************** */
    do
    {
        printf("\n\t\t\tEmail : ");
        scanf("%s",p.Email);
        if (strlen(p.Email)>30||strlen(p.Email)<8)
        {
            printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
        }
    }
    while(strlen(p.Email)>30||strlen(p.Email)<8);
    /* ********************************************************* Problem *********************************************** */
E:
    printf("\n\t\t\tProblem : ");
    scanf("%s",p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>15||strlen(p.Problem)<3)
    {
        printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
        goto E;
    }
    else
    {
        for (b=0; b<strlen(p.Problem); b++)
        {
            if (isalpha(p.Problem[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
            goto E;
        }
    }
    /* ********************************************** Prescribed Doctor **************************************** */
F:
    printf("\n\t\t\tPrescribed Doctor : ");
    scanf("%s",p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<3)
    {
        printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 3 :)");
        goto F;
    }
    else
    {
        for (b=0; b<strlen(p.Doctor); b++)
        {
            if (isalpha(p.Doctor[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
            goto F;
        }
    }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]  = ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
    {
        Add_patient_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\n\n\n\n\t\t\t\t\t\t Thank you :) :)");
        getch();
        Patient();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}

void patient_list()
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Patient_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  List Patients Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contact No.");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Problem");
    gotoxy(98,15);
    printf("Prescribed Doctor\n");
    printf("=================================================================================================================");
    row=17;
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name,
                 &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",p.First_Name, p.Last_Name);
        gotoxy(20,row);
        printf("%c",p.Gender);
        gotoxy(32,row);
        printf("%i",p.age);
        gotoxy(37,row);
        printf("%s",p.Address);
        gotoxy(49,row);
        printf("%s",p.Contact_no);
        gotoxy(64,row);
        printf("%s",p.Email);
        gotoxy(88,row);
        printf("%s",p.Problem);
        gotoxy(98,row);
        printf("%s",p.Doctor);
        row++;
    }
    fclose(ek);
    getch();
    Patient();
}
void Search_patient_rec(void)
{
    char name[20];
    system("cls");
    Title();// call Title function
    FILE *ek;
    ek=fopen("Patient_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Search Patients Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter Patient First Name to be viewed : ");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        if(strcmp(p.First_Name,name)==0)
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(25,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(52,15);
            printf("Contact No.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(80,15);
            printf("Problem");
            gotoxy(95,15);
            printf("Prescribed Doctor\n");
            printf("=================================================================================================================");
            gotoxy(1,18);
            printf("%s %s",p.First_Name, p.Last_Name);
            gotoxy(25,18);
            printf("%c",p.Gender);
            gotoxy(32,18);
            printf("%i",p.age);
            gotoxy(37,18);
            printf("%s",p.Address);
            gotoxy(52,18);
            printf("%s",p.Contact_no);
            gotoxy(64,18);
            printf("%s",p.Email);
            gotoxy(80,18);
            printf("%s",p.Problem);
            gotoxy(95,18);
            printf("%s",p.Doctor);
            printf("\n");
            break;
        }
    }
    if(strcmp(p.First_Name,name)!=0)
    {
        gotoxy(5,10);
        printf("Record not found!");
        getch();
    }
    fclose(ek);
L:
    getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N]  = ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_patient_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t\t\t Thank you :) :)");
        getch();
        Patient();
    }
    else
    {
        printf("\n\tInvalid Input.\n");
        goto L;
    }
}
void Edit_patient_rec(void)
{
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char name[20];

    system("cls");
    Title();// call Title function
    ft=fopen("Edit_Patient_Record.txt","w+");
    ek=fopen("Patient_Record.txt","r");
    if(ek==NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
        Patient();
    }
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Edit Patients Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(12,13);
    printf("\n\n\n\t\tEnter the First Name of the Patient : ");
    scanf(" %s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);

    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        Patient();
    }
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        if(strcmp(p.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("*** Existing Record ***");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
            gotoxy(12,22);
            printf("Enter New First Name : ");
            scanf("%s",p.First_Name);
            gotoxy(12,24);
            printf("Enter Last Name : ");
            scanf("%s",p.Last_Name);
            gotoxy(12,26);
            printf("Enter Gender : ");
            scanf(" %c",&p.Gender);
            p.Gender=toupper(p.Gender);
            gotoxy(12,28);
            printf("Enter age : ");
            scanf(" %i",&p.age);
            gotoxy(12,30);
            printf("Enter Address : ");
            scanf("%s",p.Address);
            p.Address[0]=toupper(p.Address[0]);
            gotoxy(12,32);
            printf("Enter Contact no : ");
            scanf("%s",p.Contact_no);
            gotoxy(12,34);
            printf("Enter New email : ");
            scanf("%s",p.Email);
            gotoxy(12,36);
            printf("Enter Problem : ");
            scanf("%s",p.Problem);
            p.Problem[0]=toupper(p.Problem[0]);
            gotoxy(12,38);
            printf("Enter Doctor Name : ");
            scanf("%s",p.Doctor);
            p.Doctor[0]=toupper(p.Doctor[0]);
            printf("\n\n\n\t\tPress U charecter for the Updating operation : ");
            ch=getche();
            if(ch=='u' || ch=='U')
            {
                printf("\n\n");
                fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
                printf("\n\n\t\t\tPatient record updated successfully...");
            }
        }
        else
        {
            printf("\n\n");
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",p.First_Name,p.Last_Name,p.Gender, p.age,p.Address,p.Contact_no,p.Email,p.Problem,p.Doctor);
        }
    }
    if(!valid)
        printf("\n\n\n\t\t\tNO RECORD FOUND...");
    fclose(ft);
    fclose(ek);
    remove("Patient_Record.txt");
    rename("Edit_Patient_Record.txt","Patient_Record.txt");
    getch();
    Patient();
}
void Dlt_patient_rec()
{
    char name[20];
    int found=0;
    system("cls");
    Title();// call Title function
    FILE *ek, *ft;
    ft=fopen("Delete_Patient_record.txt","w+");
    ek=fopen("Patient_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Delete Patients Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    gotoxy(12,8);
    printf("\n\n\n\t\tEnter Patient First Name to delete : ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", p.First_Name, p.Last_Name, &p.Gender,
                  &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        if (strcmp(p.First_Name,name)!=0)
        {
            printf("\n\n");

            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
        }
        else
        {
            printf("\n\n");
            printf("%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
            found=1;
        }
    }//while loop ends
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        Patient();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Patient_Record.txt");
        rename("Delete_Patient_record.txt","Patient_record.txt");
        printf("\n\n\t\t\t Record deleted successfully :) ");
        getch();
        Patient();
    }
}
void staff()//function decleration
{
    system("cls");
    int choose;
    Title();// call Title function
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  STAFF INFORMATION  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\t\t\t\t1. Add Staff Information\n");
    printf("\n\t\t\t\t2. List of staff Information\n");
    printf("\n\t\t\t\t3. Search staff information\n");
    printf("\n\t\t\t\t4. Edit staff information\n");
    printf("\n\t\t\t\t5. Delete staff information\n");
    printf("\n\t\t\t\t6. Back\n");
    printf("\n\t\t\t\t7.Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 7 : ");
    scanf("%i", &choose);

    switch(choose)//switch to differeht case
    {

    case 1:
        Add_staff_rec();//Add_rec function is called
        break;
    case 2:
        staff_list();//view_rec function is call
        break;
    case 3:
        Search_staff_rec();//search_rec function is call
        break;
    case 4:
        Edit_staff_rec();//Edit_rec function is call
        break;
    case 5:
        Dlt_staff_rec();//Dlt_rec function is call
        break;
    case 6:
    {
        system("cls");
        admin();
        break;
    }
    case 7:
        ex_it();//ex_it function is call
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getch();//holds screen
    }
}
//end of switch
void Add_staff_rec()
{
    system("cls");
    char ans;
    FILE*ek;//file pointer
    ek=fopen("Staff_Record.txt","a");//open file in write mode
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Staff Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    /* **************************First Name*********************************** */
A:
    printf("\n\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",s.First_Name);
    s.First_Name[0]=toupper(s.First_Name[0]);
    if(strlen(s.First_Name)>20||strlen(s.First_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
        goto A;
    }
    else
    {
        for (b=0; b<strlen(s.First_Name); b++)
        {
            if (isalpha(s.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character :(  Enter again :)");
            goto A;
        }
    }

    /* ********************************************** Last name ************************************************ */
B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",s.Last_Name);
    s.Last_Name[0]=toupper(s.Last_Name[0]);
    if(strlen(s.Last_Name)>20||strlen(s.Last_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
        goto B;
    }
    else
    {
        for (b=0; b<strlen(s.Last_Name); b++)
        {
            if (isalpha(s.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
            goto B;
        }
    }
    /* ******************************************* Gender ************************************************************** */
    do
    {
        printf("\n\t\t\tGender[F/M] : ");
        scanf(" %c",&s.Gender);
        if(toupper(s.Gender)=='M'|| toupper(s.Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
    }
    while(!ok);
    /* ***************************************** Age ********************************************************************** */
    printf("\n\t\t\tAge :");
    scanf(" %i",&s.age);
    /* **************************************** Address ******************************************************************* */
    do
    {
C:
        printf("\n\t\t\tAddress : ");
        scanf("%s",s.Address);
        s.Address[0]=toupper(s.Address[0]);
        if(strlen(s.Address)>20||strlen(s.Address)<4)
        {
            printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
            goto C;
        }

    }
    while(!valid);
    /* ******************************************* Contact no. ***************************************** */
    do
    {
D:
        printf("\n\t\t\tContact no : ");
        scanf("%s",s.Contact_no);
        if(strlen(s.Contact_no)>11||strlen(s.Contact_no)!=11)
        {
            printf("\n\t Sorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
            goto D;
        }
        else
        {
            for (b=0; b<strlen(s.Contact_no); b++)
            {
                if (!isalpha(s.Contact_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    }
    while(!valid);
    /* ************************************************** Email ******************************************** */
    do
    {
        printf("\n\t\t\tEmail : ");
        scanf("%s",s.Email);
        if (strlen(s.Email)>30||strlen(s.Email)<8)
        {
            printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
        }
    }
    while(strlen(s.Email)>30||strlen(s.Email)<8);
    /* ********************************************************* Position *********************************************** */
E:
    printf("\n\t\t\tPosition : ");
    scanf("%s",s.Position);
    s.Position[0]=toupper(s.Position[0]);
    if(strlen(s.Position)>15||strlen(s.Position)<3)
    {
        printf("\n\t Invalid :( \t The max range for Position is 15 and min range is 3 :)");
        goto E;
    }
    else
    {
        for (b=0; b<strlen(s.Position); b++)
        {
            if (isalpha(s.Position[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Position contain Invalid character :(  Enter again :)");
            goto E;
        }
    }
    /* ********************************************** Designation **************************************** */
F:
    printf("\n\t\t\t Designation :");
    scanf("%s",s.deg);
    s.deg[0]=toupper(s.deg[0]);
    if(strlen(s.deg)>30||strlen(s.deg)<3)
    {
        printf("\n\t Invalid :( \t The max range for Designation is 30 and min range is 3 :)");
        goto F;
    }
    else
    {
        for (b=0; b<strlen(s.deg); b++)
        {
            if (isalpha(s.deg[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Designation contain Invalid character :(  Enter again :)");
            goto F;
        }
    }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name, s.Gender, s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]  = ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Add_staff_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\n\t\t\t\t\t\t\t Thank you :) :)");
        getch();
        staff();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
void staff_list()
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Staff_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Staff List  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contact No.");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Position");
    gotoxy(98,15);
    printf("Designation\n");
    printf("=================================================================================================================");
    row=17;
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name,
                 &s.Gender, &s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",s.First_Name, s.Last_Name);
        gotoxy(20,row);
        printf("%c",s.Gender);
        gotoxy(32,row);
        printf("%i",s.age);
        gotoxy(37,row);
        printf("%s",s.Address);
        gotoxy(49,row);
        printf("%s",s.Contact_no);
        gotoxy(64,row);
        printf("%s",s.Email);
        gotoxy(88,row);
        printf("%s",s.Position);
        gotoxy(98,row);
        printf("%s",s.deg);
        row++;
    }
    fclose(ek);
    getch();
    staff();
}
void Search_staff_rec(void)
{
    char name[20];
    system("cls");
    Title();// call Title function
    FILE *ek;
    ek=fopen("Staff_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Search Staff Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter staff Name to be viewed : ");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name, &s.Gender, &s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg)!=EOF)
    {
        if(strcmp(s.First_Name,name)==0)
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(25,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(52,15);
            printf("Contact No.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(80,15);
            printf("Position");
            gotoxy(95,15);
            printf("Designation\n");
            printf("=================================================================================================================");
            gotoxy(1,18);
            printf("%s %s",s.First_Name, s.Last_Name);
            gotoxy(25,18);
            printf("%c",s.Gender);
            gotoxy(32,18);
            printf("%i",s.age);
            gotoxy(37,18);
            printf("%s",s.Address);
            gotoxy(52,18);
            printf("%s",s.Contact_no);
            gotoxy(64,18);
            printf("%s",s.Email);
            gotoxy(80,18);
            printf("%s",s.Position);
            gotoxy(95,18);
            printf("%s",s.deg);
            printf("\n");
            break;
        }
    }
    if(strcmp(s.First_Name,name)!=0)
    {
        gotoxy(5,10);
        printf("Record not found!");
        getch();
    }
    fclose(ek);
L:
    getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N]  = ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_staff_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\n\t\t\t\t\t Thank you :) :)");
        getch();
        staff();
    }
    else
    {
        printf("\n\tInvalid Input.\n");
        goto L;
    }
}

void Edit_staff_rec(void)
{
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char name[20];

    system("cls");
    Title();// call Title window
    ft=fopen("Edit_staff_Record.txt","w+");
    ek=fopen("Staff_Record.txt","r");
    if(ek==NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
        staff();
    }
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Edit Staff Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,13);
    printf("\n\n\n\t\tEnter the First Name of the staff : ");
    scanf(" %s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);

    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        staff();
    }
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name, &s.Gender, &s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg)!=EOF)
    {
        if(strcmp(s.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("*** Existing Record ***");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",s.First_Name,s.Last_Name,s.Gender, s.age,s.Address,s.Contact_no,s.Email,s.Position,s.deg);
            gotoxy(12,22);
            printf("Enter New First Name : ");
            scanf("%s",s.First_Name);
            gotoxy(12,24);
            printf("Enter Last Name : ");
            scanf("%s",s.Last_Name);
            gotoxy(12,26);
            printf("Enter Gender : ");
            scanf(" %c",&s.Gender);
            p.Gender=toupper(s.Gender);
            gotoxy(12,28);
            printf("Enter age : ");
            scanf(" %i",&s.age);
            gotoxy(12,30);
            printf("Enter Address : ");
            scanf("%s",s.Address);
            s.Address[0]=toupper(s.Address[0]);
            gotoxy(12,32);
            printf("Enter Contact no : ");
            scanf("%s",s.Contact_no);
            gotoxy(12,34);
            printf("Enter New email : ");
            scanf("%s",s.Email);
            gotoxy(12,36);
            printf("Enter Position : ");
            scanf("%s",s.Position);
            s.Position[0]=toupper(s.Position[0]);
            gotoxy(12,38);
            printf("Enter Designation : ");
            scanf("%s",s.deg);
            s.deg[0]=toupper(s.deg[0]);
            printf("\n\n\n\t\tPress U charecter for the Updating operation : ");
            ch=getche();
            if(ch=='u' || ch=='U')
            {
                fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",s.First_Name,s.Last_Name,s.Gender, s.age,s.Address,s.Contact_no,s.Email,s.Position,s.deg);
                printf("\n\n\t\t\t Staff record updated successfully...");
            }
        }
        else
        {
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",s.First_Name,s.Last_Name,s.Gender, s.age,s.Address,s.Contact_no,s.Email,s.Position,s.deg);
        }
    }
    if(!valid)
        printf("\n\t\tNO RECORD FOUND...");
    fclose(ft);
    fclose(ek);
    remove("Staff_Record.txt");
    rename("Edit_Staff_Record.txt","Staff_Record.txt");
    getch();
    staff();
}
void Dlt_staff_rec()
{
    char name[20];
    int found=0;
    system("cls");
    Title();// call Title function
    FILE *ek, *ft;
    ft=fopen("Delete_Staff_record.txt","w+");
    ek=fopen("Staff_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Delete Staff Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter Staff Name to delete : ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(ek,"%s %s %c %i %s %s %s %s %s", s.First_Name, s.Last_Name, &s.Gender,
                  &s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg)!=EOF)
    {
        if (strcmp(s.First_Name,name)!=0)
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name, s.Gender, s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg);
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", s.First_Name, s.Last_Name, s.Gender, s.age, s.Address, s.Contact_no, s.Email, s.Position, s.deg);
            found=1;
        }
    }//while loop ends
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        staff();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Staff_Record.txt");
        rename("Delete_Staff_record.txt","Staff_record.txt");
        printf("\n\n\t\t\t Record deleted successfully :) ");
        getch();
        staff();
    }
}
void MainMenu()
{
    int choice;
    system("cls");
    Title();
    FILE *menu_file;
    menu_file = fopen("Main Menu.txt","r");
    char ch;
    while (!feof(menu_file))
    {
        ch = fgetc(menu_file);
        printf("%c",ch);
    }
    fclose(menu_file);
    doctor_information();
}
void doctor_information()
{
    int choice;
    system("cls");
    Title();
    FILE *diseases_file;
    diseases_file = fopen("Diseases name.txt","r");
    printf("\n");
    char ch;
    while (!feof(diseases_file))
    {
        ch = fgetc(diseases_file);
        printf("%c",ch);
    }
    fclose(diseases_file);

    printf("\n\n\n\t Which department doctor do you want to see choose by your own diseases : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Medicine();
        break;
    case 2:
        Cancer();
        break;
    case 3:
        Thyroid();
        break;
    case 4:
        Diabetes();
        break;
    case 5:
        Heart_problem();
        break;
    case 6:
        admin();
        break;
    case 7:
        ex_it();
        break;

    default:
    {
        system("cls");
        Title();
        printf("\n\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\t\t\t\tTry Again .........\n\n");
        doctor_information();
    }
    }
}
void Medicine()
{
    system("cls");
    Title();
    FILE *medicine;
    medicine=fopen("1.Doctor info of Medicine.txt","r");
    if ( medicine == NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t    File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        char ch;
        printf("\n\n\n\n");
        ch = fgetc(medicine);
        while(!feof(medicine))
        {

            printf("%c",ch);
            ch = fgetc(medicine);

        }

    }

    fclose(medicine);

    // This block is using for returning to the doctor info menu
    int n;
    printf("\n\n\n\t\t\t\t 1.Back\n");
    printf("\n\n\t\t\t\t 2.Exit\n");
    printf("\n\t\tWhich section do you want to return : ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        Back2();
        break;
    case 2:
        ex_it();
        break;
    default :
    {
        system("cls");
        Title();
        printf("\n\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\t\t\t\tTry Again .........\n\n");
        Sleep(2000);
        Medicine();
    }
    }

}
void Cancer()
{
    system("cls");
    Title();
    FILE * cancer;
    cancer=fopen("2.Doctor info of Cancer.txt","r");


    if (cancer==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t    File is not found..\n\n");
    }

    else
    {
        system("cls");
        Title();
        char ch;
        printf("\n");
        ch = fgetc(cancer);
        while(!feof(cancer))
        {

            printf("%c",ch);
            ch = fgetc(cancer);

        }

    }

    fclose(cancer);
    // This block is using for returning to the  doctor info menu
    int n;
   printf("\n\n\n\t\t\t\t 1.Back\n");
    printf("\n\n\t\t\t\t 2.Exit\n");
    printf("\n\t\tWhich section do you want to return : ");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        Back2();
        break;
    case 3:
        ex_it();
        break;
    default :
        system("cls");
        Title() ;
        printf("\n\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\t\t\t\tTry Again .........\n\n");
        Sleep(2000);
        Cancer();
    }

}
void Thyroid()
{
    system("cls");
    Title();
    FILE * thyroid;
    thyroid=fopen("3.Doctor info of Thyroid.txt","r");


    if (thyroid == NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t    File is not found..\n\n");
    }

    else
    {
        system("cls");
        Title();
        char ch;
        printf("\n");
        ch = fgetc(thyroid);
        while(!feof(thyroid))
        {

            printf("%c",ch);
            ch = fgetc(thyroid);

        }

    }

    fclose(thyroid);
//this block is using for returning to the doctor info menu
    int n;
   printf("\n\n\n\t\t\t\t 1.Back\n");
    printf("\n\n\t\t\t\t 2.Exit\n");
    printf("\n\t\tWhich section do you want to return : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        Back2();
        break;
    case 3:
        ex_it();
        break;
    default:
    {
        system("cls");
        Title();
        printf("\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\n\n\n\t\t Try again......\n");
        Sleep(2000);
        Thyroid();
        break;
    }
    }
}
void Diabetes()
{
    system("cls");
    Title();
    FILE *diabetes;
    diabetes=fopen("4.Doctor info of Diabetes.txt","r");
    if(diabetes==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");

    }
    else
    {
        system("cls");
        Title();
        char ch;
        printf("\n");
        ch=fgetc(diabetes);
        while(!feof(diabetes))
        {
            printf("%c",ch);
            ch=fgetc(diabetes);
        }
    }
    fclose(diabetes);
//this block is using for returning to the doctor info menu
    int n;
    printf("\n\n\n\t\t\t\t 1.Back\n");
    printf("\n\n\t\t\t\t 2.Exit\n");
    printf("\n\t\tWhich section do you want to return : ");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        Back2();
        break;
    case 3:
        ex_it();
        break;
    default:
        system("cls");
        Title();
        printf("\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\n\n\n\t\t Try again......\n");
        Sleep(2000);
        Diabetes();
        break;
    }
}
void Heart_problem()
{
    system("cls");
    Title();
    FILE *heart_problem;
    heart_problem=fopen("5.Doctor info of Heart problem.txt","r");
    if(heart_problem==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        char ch;
        printf("\n");
        ch=fgetc(heart_problem);
        while(!feof(heart_problem))
        {
            printf("%c",ch);
            ch=fgetc(heart_problem);
        }
    }
    fclose(heart_problem);
//this block is using for returning to the doctor info menu
    int n;
    printf("\n\n\n\t\t\t\t 1.Back\n");
    printf("\n\n\t\t\t\t 2.Exit\n");
    printf("\n\t\tWhich section do you want to return : ");
    scanf("%d",&n);
//switch(n)
    switch(n)
    {
    case 1:
        Back2();
        break;
    case 3:
        ex_it();
        break;
    default:
    {
        system("cls");
        Title();
        printf("\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\n\n\n\t\t Try again......\n");
        Sleep(2000);
        Heart_problem();
        break;
    }
    }
}

//Back in the doctor information
void Back2()
{
    doctor_information();
}

void nurse()//function decleration
{
    system("cls");
    int choose;
    Title();// call Title function
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  NURSE INFORMATION  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\t\t\t\t1. Add Nurse Information\n");
    printf("\n\t\t\t\t2. List of Nurse Information\n");
    printf("\n\t\t\t\t3. Search Nurse information\n");
    printf("\n\t\t\t\t4. Edit Nurse information\n");
    printf("\n\t\t\t\t5. Delete Nurse information\n");
    printf("\n\t\t\t\t6.Back\n");
    printf("\n\t\t\t\t7.Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 7 : ");
    scanf("%i", &choose);

    switch(choose)//switch to differeht case
    {

    case 1:
        Add_nurse_rec();//Add_rec function is called
        break;
    case 2:
        nurse_list();//View_rec function is call
        break;
    case 3:
        Search_nurse_rec();//search_rec function is call
        break;
    case 4:
        Edit_nurse_rec();//Edit_rec function is call
        break;
    case 5:
        Dlt_nurse_rec();//Dlt_rec function is call
        break;
    case 6:
    {
        system("cls");
        admin();
        break;
    }
    case 7:
        ex_it();//ex_it function is call
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getch();//holds screen
    }//end of switch
}
void Add_nurse_rec()
{
    system("cls");
    char ans;
    FILE*ek;//file pointer
    ek=fopen("Nurse_Record.txt","a");//open file in write mode
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Nurse Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");


A:
    printf("\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",n.First_Name);
    n.First_Name[0]=toupper(n.First_Name[0]);
    if(strlen(n.First_Name)>20||strlen(n.First_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
        goto A;
    }
    else
    {
        for (b=0; b<strlen(n.First_Name); b++)
        {
            if (isalpha(n.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character :(  Enter again :)");
            goto A;
        }
    }


B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",n.Last_Name);
    n.Last_Name[0]=toupper(n.Last_Name[0]);
    if(strlen(n.Last_Name)>20||strlen(n.Last_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
        goto B;
    }
    else
    {
        for (b=0; b<strlen(n.Last_Name); b++)
        {
            if (isalpha(n.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
            goto B;
        }
    }

    do
    {
        printf("\n\t\t\tGender[F/M] : ");
        scanf(" %c",&n.Gender);
        if(toupper(n.Gender)=='M'|| toupper(n.Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
    }
    while(!ok);
    /* ***************************************** Age **********************************************************************/
    printf("\n\t\t\tAge : ");
    scanf(" %i",&n.age);
    /* **************************************** Address *******************************************************************/
    do
    {
C:
        printf("\n\t\t\tAddress : ");
        scanf("%s",n.Address);
        n.Address[0]=toupper(n.Address[0]);
        if(strlen(n.Address)>20||strlen(n.Address)<4)
        {
            printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
            goto C;
        }

    }
    while(!valid);
    /* ******************************************* Contact no. *****************************************/
    do
    {
D:
        printf("\n\t\t\tContact no : ");
        scanf("%s",n.Contact_no);
        if(strlen(n.Contact_no)>11||strlen(n.Contact_no)!=11)
        {
            printf("\n\t Sorry :( Invalid. Contact no. must contain 11 numbers. Enter again :)");
            goto D;
        }
        else
        {
            for (b=0; b<strlen(n.Contact_no); b++)
            {
                if (!isalpha(n.Contact_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
                goto D;
            }
        }
    }
    while(!valid);
    /* ************************************************** Email ********************************************/
    do
    {
        printf("\n\t\t\tEmail : ");
        scanf("%s",n.Email);
        if (strlen(n.Email)>30||strlen(n.Email)<8)
        {
            printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
        }
    }
    while(strlen(n.Email)>30||strlen(n.Email)<8);
    /* ********************************************************* Shift ***********************************************/
E:
    printf("\n\t\t\tShift : ");
    scanf("%s",n.Shift);
    n.Shift[0]=toupper(n.Shift[0]);
    if(strlen(n.Shift)>15||strlen(n.Shift)<3)
    {
        printf("\n\t Invalid :( \t The max range for Shift is 15 and min range is 3 :)");
        goto E;
    }
    else
    {
        for (b=0; b<strlen(n.Shift); b++)
        {
            if (isalpha(n.Shift[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Shift contain Invalid character :(  Enter again :)");
            goto E;
        }
    }

    fprintf(ek," %s %s %c %i %s %s %s %s\n", n.First_Name, n.Last_Name, n.Gender, n.age, n.Address, n.Contact_no, n.Email, n.Shift);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N] =  ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
    {
        Add_nurse_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\n\t\t\t\t\t\t\t Thank you :) :)");
        getch();
        nurse();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
void nurse_list()
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Nurse_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Nurse List  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Contact No.");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Shift\n");

    printf("================================================================================================");
    row=17;
    while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", n.First_Name, n.Last_Name,
                 &n.Gender, &n.age, n.Address, n.Contact_no, n.Email,n.Shift)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",n.First_Name, n.Last_Name);
        gotoxy(20,row);
        printf("%c",n.Gender);
        gotoxy(32,row);
        printf("%i",n.age);
        gotoxy(37,row);
        printf("%s",n.Address);
        gotoxy(49,row);
        printf("%s",n.Contact_no);
        gotoxy(64,row);
        printf("%s",n.Email);
        gotoxy(88,row);
        printf("%s",n.Shift);

        row++;
    }
    fclose(ek);
    getch();
    nurse();
}
void Search_nurse_rec(void)
{
    char name[20];
    system("cls");
    Title();// call Title function
    FILE *ek;
    ek=fopen("Nurse_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Search Nurse Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter Nurse First Name to be viewed : ");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", n.First_Name, n.Last_Name, &n.Gender, &n.age, n.Address, n.Contact_no, n.Email, n.Shift)!=EOF)
    {
        if(strcmp(n.First_Name,name)==0)
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(25,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(52,15);
            printf("Contact No.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(80,15);
            printf("Shift\n");
            printf("===============================================================================================");
            gotoxy(1,18);
            printf("%s %s",n.First_Name, n.Last_Name);
            gotoxy(25,18);
            printf("%c",n.Gender);
            gotoxy(32,18);
            printf("%i",n.age);
            gotoxy(37,18);
            printf("%s",n.Address);
            gotoxy(52,18);
            printf("%s",n.Contact_no);
            gotoxy(64,18);
            printf("%s",n.Email);
            gotoxy(80,18);
            printf("%s",n.Shift);
            printf("\n");
            break;
        }
    }
    if(strcmp(n.First_Name,name)!=0)
    {
        gotoxy(5,10);
        printf("\n\n\t\tRecord not found!");
        getch();
    }
    fclose(ek);
L:
    getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N] = ");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_nurse_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\n\t\t\t\t\t\t\t Thank you :) :)");
        getch();
        nurse();
    }
    else
    {
        printf("\n\tInvalid Input.\n");
        goto L;
    }
}
void Edit_nurse_rec(void)
{
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char name[20];

    system("cls");
    Title();// call Title window
    ft=fopen("Edit_Nurse_Record.txt","w+");
    ek=fopen("Nurse_Record.txt","r");
    if(ek==NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
        nurse();
    }
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Nurse Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,13);
    printf("\n\n\n\t\tEnter the First Name of the Nurse : ");
    scanf(" %s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);

    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        staff();
    }
    while(fscanf(ek,"%s %s %c %i %s %s %s %s\n", n.First_Name, n.Last_Name, &n.Gender, &n.age, n.Address, n.Contact_no, n.Email, n.Shift)!=EOF)
    {
        if(strcmp(n.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("*** Existing Record ***");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s\n",n.First_Name,n.Last_Name,n.Gender, n.age,n.Address,n.Contact_no,n.Email,n.Shift);
            gotoxy(12,22);
            printf("Enter New First Name : ");
            scanf("%s",n.First_Name);
            gotoxy(12,24);
            printf("Enter Last Name : ");
            scanf("%s",n.Last_Name);
            gotoxy(12,26);
            printf("Enter Gender : ");
            scanf(" %c",&n.Gender);
            n.Gender=toupper(n.Gender);
            gotoxy(12,28);
            printf("Enter age : ");
            scanf(" %i",&n.age);
            gotoxy(12,30);
            printf("Enter Address : ");
            scanf("%s",n.Address);
            n.Address[0]=toupper(n.Address[0]);
            gotoxy(12,32);
            printf("Enter Contact no : ");
            scanf("%s",n.Contact_no);
            gotoxy(12,34);
            printf("Enter New email : ");
            scanf("%s",n.Email);
            gotoxy(12,36);
            printf("Enter Shift : ");
            scanf("%s",n.Shift);
            n.Shift[0]=toupper(n.Shift[0]);

            printf("\n\n\n\t\tPress U charecter for the Updating operation : ");
            ch=getche();
            if(ch=='u' || ch=='U')
            {
                fprintf(ft,"%s %s %c %i %s %s %s %s\n",n.First_Name,n.Last_Name,n.Gender, n.age,n.Address,n.Contact_no,n.Email,n.Shift);
                printf("\n\n\t\t\t Nurse record updated successfully...");
            }
        }
        else
        {
            fprintf(ft,"%s %s %c %i %s %s %s %s\n",n.First_Name,n.Last_Name,n.Gender, n.age,n.Address,n.Contact_no,n.Email,n.Shift);
        }
    }
    if(!valid)
        printf("\n\t\tNO RECORD FOUND...");
    fclose(ft);
    fclose(ek);
    remove("Nurse_Record.txt");
    rename("Edit_Nurse_Record.txt","Nurse_Record.txt");
    getch();
    nurse();
}
void Dlt_nurse_rec()
{
    char name[20];
    int found=0;
    system("cls");
    Title();// call Title function
    FILE *ek, *ft;
    ft=fopen("Delete_Nurse_record.txt","w+");
    ek=fopen("Nurse_Record.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Delete Nurse Record  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter Nurse First Name to delete : ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(ek,"%s %s %c %i %s %s %s %s", n.First_Name, n.Last_Name, &n.Gender,
                  &n.age, n.Address, n.Contact_no, n.Email, n.Shift)!=EOF)
    {
        if (strcmp(n.First_Name,name)!=0)
            fprintf(ft,"%s %s %c %i %s %s %s %s\n", n.First_Name,n.Last_Name, n.Gender, n.age, n.Address, n.Contact_no, n.Email, n.Shift);
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", n.First_Name, n.Last_Name, n.Gender, n.age, n.Address, n.Contact_no, n.Email, n.Shift);
            found=1;
        }
    }//while loop ends
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        nurse();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Nurse_Record.txt");
        rename("Delete_Nurse_record.txt","Nurse_record.txt");
        printf("\n\n\t\t\t Record deleted successfully :) ");
        getch();
        nurse();
    }
}
void Appointment_information()//function decleration
{
    system("cls");
    int choose;
    Title();// call Title function
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  APPOINTMENT  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\t\t\t\t1. Add Appointment\n");
    printf("\n\t\t\t\t2. List of Appointment\n");
    printf("\n\t\t\t\t3. Edit Appointment\n");
    printf("\n\t\t\t\t4. Cancel Appointment\n");
    printf("\n\t\t\t\t5. Back\n");
    printf("\n\t\t\t\t6. Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 6 : ");
    scanf("%i", &choose);

    switch(choose)//switch to differeht case
    {

    case 1:
        add_appointment_a();//Add_rec function is called
        break;
    case 2:
        patient_profile();//View_rec function is call
        break;
    case 3:
        Edit_appointment_a();//edit_rec function is call
        break;
    case 4:
        Cancel_appointment_a();//cancel_rec function is call
        break;
    case 5:
    {
        system("cls");
        admin();
        break;
    }
    case 6:
        ex_it();//ex_it function is call
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option : ");
        getch();//holds screen
    }//end of switch
}
void patient_profile()
{
    int row;
    system ("cls");
    Title();
    FILE *ek;
    ek=fopen("Appointment File.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Appointment List  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(1,15);
    printf("Full Name");
    gotoxy(20,15);
    printf("Gender");
    gotoxy(32,15);
    printf("Age");
    gotoxy(37,15);
    printf("Address");
    gotoxy(49,15);
    printf("Phone Number");
    gotoxy(64,15);
    printf("Email");
    gotoxy(88,15);
    printf("Problem");
    gotoxy(98,15);
    printf("Doctor Name\n");
    printf("=================================================================================================================");
    row=17;

    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name,&person.Gender, &person.age,
                 person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name)!=EOF)
    {
        gotoxy(1,row);
        printf("%s %s",person.First_Name, person.Last_Name);
        gotoxy(20,row);
        printf("%c",person.Gender);
        gotoxy(32,row);
        printf("%i",person.age);
        gotoxy(37,row);
        printf("%s",person.Address);
        gotoxy(49,row);
        printf("%s",person.phone_no);
        gotoxy(64,row);
        printf("%s",person.Email);
        gotoxy(88,row);
        printf("%s",person.Problem);
        gotoxy(98,row);
        printf("%s",person.Doctor_Name);
        row++;
    }
    fclose(ek);
    printf("\n\nEnter Any Key.......\n");
    getch();
    Appointment_information();

}


void user()
{
    system("cls");

    int choice;
     printf("\n\n\t\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 USER LOG IN \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t1.Sign Up");
    printf("\n\n\t\t\t\t\t\t\t\t2.Sign In");
    printf("\n\n\t\t\t\t\t\t\t\t3.Back\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\tChoose Option : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1 :
        system("cls");
        Title ( ) ;
        signup( );
        break;
    case 2 :
        system("cls");
        Title ( ) ;
        signin( );
        break;
    case 3:
        system("cls");
        Panel();
        break;
    default :
        system("cls");
        Title ( );
        printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tEnter wrong key!!!\n\n");
    }

    getch();
}
void signup( )
{
    system("cls");
    Title ( ) ;

    signUp=fopen("SignUp file.txt","w");


    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  USER SIGN UP  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\tSet user name and password\n\n");
    printf("\t\t\t***************************\n");

    printf("\n\t\t\tEnter First Name : ");
    fflush(stdin);
    gets(pi.first_name);
    printf("\n\t\t\tEnter Last Name : ");
    fflush(stdin);
    gets(pi.last_name);

    printf("\n\n\t\t\tEnter User Name : ");
    scanf("%s",pi.username);
    printf("\n\n\t\t\tEnter Password : ");
    scanf("%s",pi.password);

    fwrite(&pi,sizeof(pi),1,signUp);

    fclose(signUp);

    printf("\n\n\n\t\t\tLoading....................");
    Sleep(500);

    signin( );

}


//********************************* Function for SignIn **********************************

void signin( )
{
    system("cls");
    Title ( ) ;
    char username[20];
    char password[20];
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  USER SIGN IN  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    printf("\n\n\n\n\n\n\t\t\t\tEnter User Name : ");
    fflush(stdin);
    gets(username);
    printf("\n\n\t\t\t\tEnter Password : ");
    fflush(stdin);
    gets(password);

    signUp=fopen("SignUp file.txt","r");
    while(fread(&pi,sizeof(pi),1,signUp))
    {
        for( i = 2 ; i>=1 ; i--)
        {
            if(strcmp(username,pi.username)==0 && strcmp(password,pi.password)==0)
            {
                printf("\n\n\n\t\t\tLoading..............");
                Sleep(500);
                system("cls");
                Title ( ) ;
                printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tSuccessfully login.........\n\n\n\n");
                Sleep(500);
                user_panel();
                break;
            }
            else
            {
                system("cls");
                Title ( );

                temp = 1;

                printf("\n\n\n\n\n\t\t\t\t\t\t\tWrong Password !!!\n\n");
                printf("\n\t\t\t\t\t\t\t%d Chance's left !! \n", temp);

                printf("\n\n\t\t\tEnter User Name : ");
                gets(username);
                printf("\n\n\t\t\tEnter Password : ");
                gets(password);
            }

        }         // if user did not enter right password within 3 times then code will enter this block



        if ( i<= 0 )
        {
            system("cls");
            Title ( ) ;
            printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tFailed to login !!!\n\n\n\n");
            getch();
        }
    }

    fclose(signUp);
}
void user_panel()
{
    system("cls");
    int c;
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  USER   \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\n\t\t\t\t1.DOCTOR INFORMATION \n");
    printf("\n\t\t\t\t2.ADD APPOINTMENT \n");
    printf("\n\t\t\t\t3.EDIT APPOINTMENT \n");
    printf("\n\t\t\t\t4.CANCEL APPOINTMENT \n");
    printf("\n\t\t\t\t5.HOSPITAL INFORMATION \n");
    printf("\n\t\t\t\t6.Back\n");
    printf("\n\t\t\t\t7.Exit\n");
    printf("\n\t\t\t\t\t\tEnter option : ");
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        doctor_information_u();
        break;
    case 2:
        add_appointment();
        break;
    case 3:
        Edit_appointment();
        break;
    case 4:
        Cancel_appointment();
        break;
    case 5:
        About();
        break;
    case 6:
        user();
        break;
    case 7:
        ex_it();
        break;

    }
}
void MainMenu2()
{
    int choice;
    system("cls");
    Title();
    FILE *menu_file;
    menu_file = fopen("Main Menu_u.txt","r");
    char ch;
    while (!feof(menu_file))
    {
        ch = fgetc(menu_file);
        printf("%c",ch);
    }
    fclose(menu_file);
    doctor_information_u();
}
void doctor_information_u()
{
    int choice;
    system("cls");
    Title();
    FILE *diseases_file;
    diseases_file = fopen("Diseases name_u.txt","r");
    printf("\n");
    char ch;
    while (!feof(diseases_file))
    {
        ch = fgetc(diseases_file);
        printf("%c",ch);
    }
    fclose(diseases_file);

    printf("\n\n\n\t Which department doctor do you want to see choose by your own diseases : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Medicine();
        break;
    case 2:
        Cancer();
        break;
    case 3:
        Thyroid();
        break;
    case 4:
        Diabetes();
        break;
    case 5:
        Heart_problem();
        break;
    case 6:
        user_panel();
        break;
    case 7:
        ex_it();
        break;

    default:
    {
        system("cls");
        Title();
        printf("\n\n\n\n\n\n\t\t\t\tEnter wrong key !!!\n\n");
        printf("\n\n\t\t\t\tTry Again .........\n\n");
        doctor_information_u();
    }
    }
}

void add_appointment()
{
    system("cls");
    char ans;
    FILE*ek;//file pointer
    ek=fopen("Appointment File.txt","a");//open file in write mode
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    /* *************************First Name********************************** */
A:
    printf("\n\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",person.First_Name);
    person.First_Name[0]=toupper(person.First_Name[0]);
    if(strlen(person.First_Name)>20||strlen(person.First_Name)<2)
    {
        printf("\n\t Invalid  \t The max range for first name is 20 and min range is 2 ......");
        goto A;
    }
    else
    {
        for (b=0; b<strlen(person.First_Name); b++)
        {
            if (isalpha(person.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character ... Enter again .");
            goto A;
        }
    }

    /* ******************************************** Last name ********************************************** */
B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",person.Last_Name);
    person.Last_Name[0]=toupper(person.Last_Name[0]);
    if(strlen(person.Last_Name)>20||strlen(person.Last_Name)<2)
    {
        printf("\n\t Invalid ..... \t The max range for last name is 20 and min range is 2 .......");
        goto B;
    }
    else
    {
        for (b=0; b<strlen(person.Last_Name); b++)
        {
            if (isalpha(person.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character ...  Enter again .....");
            goto B;
        }
    }
    /* ***************************************** Gender ************************************************************ */
    do
    {
        printf("\n\t\t\tGender[F/M] : ");
        scanf(" %c",&person.Gender);
        if(toupper(person.Gender)=='M'|| toupper(person.Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character ......  Enter either F or M .....");
        }
    }
    while(!ok);
    /* *************************************** Age ******************************************************************** */
    printf("\n\t\t\tAge : ");
    scanf(" %i",&person.age);
    /* ************************************** Address ***************************************************************** */
    do
    {
C:
        printf("\n\t\t\tAddress: ");
        scanf("%s",person.Address);
        person.Address[0]=toupper(person.Address[0]);
        if(strlen(person.Address)>20||strlen(person.Address)<4)
        {
            printf("\n\t Invalid .. \t The max range for address is 20 and min range is 4 ......");
            goto C;
        }

    }
    while(!valid);
    /* ***************************************** Contact no. *************************************** */
    do
    {
D:
        printf("\n\t\t\tContact no : ");
        scanf("%s",person.phone_no);
        if(strlen(person.phone_no)>11||strlen(person.phone_no)!=11)
        {
            printf("\n\t Sorry ... Invalid. Contact no. must contain 11 numbers. Enter again ...");
            goto D;
        }
        else
        {
            for (b=0; b<strlen(person.phone_no); b++)
            {
                if (!isalpha(person.phone_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\t\t Contact no. contain Invalid character...... Enter again .......");
                goto D;
            }
        }
    }
    while(!valid);
    /* ************************************************ Email ****************************************** */
    do
    {
        printf("\n\t\t\tEmail : ");
        scanf("%s",person.Email);
        if (strlen(person.Email)>30||strlen(person.Email)<8)
        {
            printf("\n\t Invalid .... \t The max range for email is 30 and min range is 8 .....");
        }
    }
    while(strlen(person.Email)>30||strlen(person.Email)<8);
    /* ******************************************************* Problem ********************************************* */
E:
    printf("\n\t\t\tProblem : ");
    scanf("%s",person.Problem);
    person.Problem[0]=toupper(person.Problem[0]);

    if(strcmp (person.Problem, "Medicine") == 0)
    {
        system("cls");
        Title();
        Medicine2();
    }

    if(strcmp (person.Problem, "Cancer") == 0)
    {
        system("cls");
        Title();
        Cancer2();
    }

    if(strcmp (person.Problem, "Thyroid") == 0)
    {
        system("cls");
        Title();
        Thyroid2();
    }

    if(strcmp (person.Problem, "Diabetes") == 0)
    {
        system("cls");
        Title();
        Diabetes2();
    }

    if(strcmp (person.Problem, "Heart Problem") == 0)
    {
        system("cls");
        Title();
        Heart_problem2();
    }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, person.Gender, person.age,
            person.Address, person.phone_no, person.Email, person.Problem,person.Doctor_Name);

    fclose(ek);//file is closed

    //when appointment is succefullly done the this section will work
    Sleep(2000);
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCongratulation Succefully Your Appointment is Done........\n\n");
    Sleep(4000);
    ex_it();
    getch();
    user_panel();

}
void add_appointment_a()
{
    system("cls");
    char ans;
    FILE*ek;//file pointer
    ek=fopen("Appointment File.txt","a");//open file in write mode
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Add Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    /* *************************First Name********************************** */
A:
    printf("\n\n\n\n\n\n\t\t\tFirst Name : ");
    scanf("%s",person.First_Name);
    person.First_Name[0]=toupper(person.First_Name[0]);
    if(strlen(person.First_Name)>20||strlen(person.First_Name)<2)
    {
        printf("\n\t Invalid .... \t The max range for first name is 20 and min range is 2 ......");
        goto A;
    }
    else
    {
        for (b=0; b<strlen(person.First_Name); b++)
        {
            if (isalpha(person.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character .... Enter again .......");
            goto A;
        }
    }

    /* ******************************************** Last name ********************************************** */
B:
    printf("\n\t\t\tLast Name : ");
    scanf("%s",person.Last_Name);
    person.Last_Name[0]=toupper(person.Last_Name[0]);
    if(strlen(person.Last_Name)>20||strlen(person.Last_Name)<2)
    {
        printf("\n\t Invalid ... \t The max range for last name is 20 and min range is 2 ......");
        goto B;
    }
    else
    {
        for (b=0; b<strlen(person.Last_Name); b++)
        {
            if (isalpha(person.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character ......  Enter again .......");
            goto B;
        }
    }
    /* ***************************************** Gender ************************************************************ */
    do
    {
        printf("\n\t\t\tGender[F/M] : ");
        scanf(" %c",&person.Gender);
        if(toupper(person.Gender)=='M'|| toupper(person.Gender)=='F')
        {
            ok =1;
        }
        else
        {
            ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character ... Enter either F or M....");
        }
    }
    while(!ok);
    /* *************************************** Age ******************************************************************** */
    printf("\n\t\t\tAge : ");
    scanf(" %i",&person.age);
    /* ************************************** Address ***************************************************************** */
    do
    {
C:
        printf("\n\t\t\tAddress : ");
        scanf("%s",person.Address);
        person.Address[0]=toupper(person.Address[0]);
        if(strlen(person.Address)>20||strlen(person.Address)<4)
        {
            printf("\n\t Invalid ...... \t The max range for address is 20 and min range is 4 .......");
            goto C;
        }

    }
    while(!valid);
    /* ***************************************** Contact no. *************************************** */
    do
    {
D:
        printf("\n\t\t\tContact no : ");
        scanf("%s",person.phone_no);
        if(strlen(person.phone_no)>11||strlen(person.phone_no)!=11)
        {
            printf("\n\t Sorry .......Invalid. Contact no. must contain 11 numbers. Enter again ....");
            goto D;
        }
        else
        {
            for (b=0; b<strlen(person.phone_no); b++)
            {
                if (!isalpha(person.phone_no[b]))
                {
                    valid=1;
                }
                else
                {
                    valid=0;
                    break;
                }
            }
            if(!valid)
            {
                printf("\n\t\t Contact no contain Invalid character .... Enter again = ");
                goto D;
            }
        }
    }
    while(!valid);
    /* ************************************************ Email ****************************************** */
    do
    {
        printf("\n\t\t\tEmail : ");
        scanf("%s",person.Email);
        if (strlen(person.Email)>30||strlen(person.Email)<8)
        {
            printf("\n\t Invalid ... \t The max range for email is 30 and min range is 8 ....  ");
        }
    }
    while(strlen(person.Email)>30||strlen(person.Email)<8);
    /* ******************************************************* Problem ********************************************* */
E:
    printf("\n\t\t\tProblem : ");
    scanf("%s",person.Problem);
    person.Problem[0]=toupper(person.Problem[0]);

    if(strcmp (person.Problem, "Medicine") == 0)
    {
        system("cls");
        Title();
        Medicine2();
    }

    if(strcmp (person.Problem, "Cancer") == 0)
    {
        system("cls");
        Title();
        Cancer2();
    }

    if(strcmp (person.Problem, "Thyroid") == 0)
    {
        system("cls");
        Title();
        Thyroid2();
    }

    if(strcmp (person.Problem, "Diabetes") == 0)
    {
        system("cls");
        Title();
        Diabetes2();
    }

    if(strcmp (person.Problem, "Heart Problem") == 0)
    {
        system("cls");
        Title();
        Heart_problem2();
    }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, person.Gender, person.age,
            person.Address, person.phone_no, person.Email, person.Problem,person.Doctor_Name);

    fclose(ek);//file is closed

    //when appointment is succefullly done the this section will work
    Sleep(1000);
    system("cls");
    Title();
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tCongratulation Succefully Your Appointment is Done!!!!\n\n");
    Sleep(1000);
    ex_it();
    getch();
    Appointment_information();

}

void Medicine2()
{

    system("cls");
    Title();
    FILE *medicine;
    medicine=fopen("1.Doctor info of Medicine.txt","r");
    if(medicine==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        printf("\n");
        char ch;
        ch=fgetc(medicine);
        while(!feof(medicine))
        {
            printf("%c",ch);
            ch=fgetc(medicine);
        }
    }
    fclose(medicine);
    printf("\n\n\t\tWhich doctor do you want ?");
    printf("\n\n\t\tWrite His /Her Name : " );
    fflush(stdin);
    gets(person.Doctor_Name);
    person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
}
void Cancer2()
{
    system("cls");
    Title();
    FILE *cancer;
    cancer=fopen("2.Doctor info of Cancer.txt","r");
    if(cancer==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        printf("\n");
        char ch;
        ch=fgetc(cancer);
        while(!feof(cancer))
        {
            printf("%c",ch);
            ch=fgetc(cancer);
        }
    }
    fclose(cancer);
    printf("\n\n\t\tWhich doctor do you want ?");
    printf("\n\n\t\tWrite His /Her Name : " );
    fflush(stdin);
    gets(person.Doctor_Name);
    person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
}

void Thyroid2()
{
    system("cls");
    Title();
    FILE *thyroid;
    thyroid=fopen("3.Doctor info of Thyroid.txt","r");
    if(thyroid==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        printf("\n");
        char ch;
        ch=fgetc(thyroid);
        while(!feof(thyroid))
        {
            printf("%c",ch);
            ch=fgetc(thyroid);
        }
    }
    fclose(thyroid);
    printf("\n\n\t\tWhich doctor do you want ?");
    printf("\n\n\t\tWrite His /Her Name : " );
    fflush(stdin);
    gets(person.Doctor_Name);
    person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
}
void Diabetes2()
{
    system("cls");
    Title();
    FILE *diabetes;
    diabetes=fopen("4.Doctor info of Diabetes.txt","r");
    if(diabetes==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        printf("\n");
        char ch;
        ch=fgetc(diabetes);
        while(!feof(diabetes))
        {
            printf("%c",ch);
            ch=fgetc(diabetes);
        }
    }
    fclose(diabetes);
    printf("\n\n\t\tWhich doctor do you want ?");
    printf("\n\n\t\tWrite His /Her Name : " );
    fflush(stdin);
    gets(person.Doctor_Name);
    person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
}
void Heart_problem2()
{
    system("cls");
    Title();
    FILE *heart_problem;
    heart_problem=fopen("5.Doctor info of Heart problem.txt","r");
    if(heart_problem==NULL)
    {
        system("cls");
        Title();
        printf("\n\n\n\t\t\t File is not found..\n\n");
    }
    else
    {
        system("cls");
        Title();
        printf("\n");
        char ch;
        ch=fgetc(heart_problem);
        while(!feof(heart_problem))
        {
            printf("%c",ch);
            ch=fgetc(heart_problem);
        }
    }
    fclose(heart_problem);
    printf("\n\n\t\tWhich doctor do you want ?");
    printf("\n\n\t\tWrite His /Her Name : " );
    fflush(stdin);
    gets(person.Doctor_Name);
    person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
}
void Edit_appointment(void)
{
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char name[20];

    system("cls");
    Title();// call Title window
    ft=fopen("temporary File.txt","w+");
    ek=fopen("Appointment File.txt","r");
    if(ek==NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
        user_panel();
    }
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,13);
    printf("\n\n\n\t\tEnter the First Name of the Patient : ");
    scanf(" %s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);

    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        user_panel();
    }
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, &person.Gender, &person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name)!=EOF)
    {
        if(strcmp(person.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("* Existing Record *");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",person.First_Name,person.Last_Name,person.Gender, person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
            gotoxy(12,22);
            printf("Enter New First Name : ");
            scanf("%s",person.First_Name);
            gotoxy(12,24);
            printf("Enter Last Name : ");
            scanf("%s",person.Last_Name);
            gotoxy(12,26);
            printf("Enter Gender : ");
            scanf(" %c",&person.Gender);
            person.Gender=toupper(person.Gender);
            gotoxy(12,28);
            printf("Enter Age : ");
            scanf(" %i",&person.age);
            gotoxy(12,30);
            printf("Enter Address : ");
            scanf("%s",person.Address);
            person.Address[0]=toupper(person.Address[0]);
            gotoxy(12,32);
            printf("Enter Contact no : ");
            scanf("%s",person.phone_no);
            gotoxy(12,34);
            printf("Enter New email : ");
            scanf("%s",person.Email);
            gotoxy(12,36);
            printf("Enter Problem : ");
            scanf("%s",person.Problem);
            person.Problem[0]=toupper(person.Problem[0]);
            gotoxy(12,38);
            printf("Enter Doctor : ");
            scanf("%s",person.Doctor_Name);
            person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
            printf("\n\t\tPress U charecter for the Updating operation : ");
            ch=getche();
            if(ch=='u' || ch=='U')
            {
                fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender, person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
                printf("\n\n\t\t\tAppointment updated successfully...");
            }
        }
        else
        {
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender,person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
        }
    }
    if(!valid)
        printf("\n\t\tNO RECORD FOUND...");
    fclose(ft);
    fclose(ek);
    remove("Appointment File.txt");
    rename("temporary File.txt","Appointment File.txt");
    getch();
    user_panel();
}
void Edit_appointment_a(void)
{
    FILE *ek, *ft;
    int i,b, valid=0;
    char ch;
    char name[20];

    system("cls");
    Title();// call Title window
    ft=fopen("temporary File.txt","w+");
    ek=fopen("Appointment File.txt","r");
    if(ek==NULL)
    {
        printf("\n\t Can not open file!! ");
        getch();
        Appointment_information();
    }

    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Edit Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,13);
    printf("\n\n\n\t\tEnter the First Name of the Patient : ");
    scanf(" %s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);

    if(ft==NULL)
    {
        printf("\n Can not open file");
        getch();
        Appointment_information();
    }
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, &person.Gender, &person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name)!=EOF)
    {
        if(strcmp(person.First_Name, name)==0)
        {
            valid=1;
            gotoxy(25,17);
            printf("* Existing Record *");
            gotoxy(10,19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s \t%s \t%s\n",person.First_Name,person.Last_Name,person.Gender, person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
            gotoxy(12,22);
            printf("Enter New First Name : ");
            scanf("%s",person.First_Name);
            gotoxy(12,24);
            printf("Enter Last Name : ");
            scanf("%s",person.Last_Name);
            gotoxy(12,26);
            printf("Enter Gender : ");
            scanf(" %c",&person.Gender);
            person.Gender=toupper(person.Gender);
            gotoxy(12,28);
            printf("Enter age : ");
            scanf(" %i",&person.age);
            gotoxy(12,30);
            printf("Enter Address : ");
            scanf("%s",person.Address);
            person.Address[0]=toupper(person.Address[0]);
            gotoxy(12,32);
            printf("Enter Contact no : ");
            scanf("%s",person.phone_no);
            gotoxy(12,34);
            printf("Enter New email : ");
            scanf("%s",person.Email);
            gotoxy(12,36);
            printf("Enter Problem : ");
            scanf("%s",person.Problem);
            person.Problem[0]=toupper(person.Problem[0]);
            gotoxy(12,38);
            printf("Enter Doctor : ");
            scanf("%s",person.Doctor_Name);
            person.Doctor_Name[0]=toupper(person.Doctor_Name[0]);
            printf("\n\t\tPress U charecter for the Updating operation : ");
            ch=getche();
            if(ch=='u' || ch=='U')
            {
                fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender, person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
                printf("\n\n\t\t\tPatient record updated successfully...");
            }
        }
        else
        {
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender,person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
        }
    }
    if(!valid)
        printf("\n\t\tNO RECORD FOUND...");
    fclose(ft);
    fclose(ek);
    remove("Appointment File.txt");
    rename("temporary File.txt","Appointment File.txt");
    getch();
    Appointment_information();
}
/************************Function for cancel appointment****************/
void Cancel_appointment()
{
    char name[20];
    int found=0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft=fopen("temporary File.txt","w+");
    ek=fopen("Appointment File.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Cancel Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\n\t\t Enter Patient First Name to Cancel : ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name,
                  &person.Gender, &person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name)!=EOF)
    {
        if (strcmp(person.First_Name,name)!=0)
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender,
                    person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, person.Gender, person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name);
            found=1;
        }
    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        admin();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Appointment File.txt");
        rename("temporary File.txt","Appointment File.txt");
        printf("\n\n\t\t\t Successfully cancel appointment ... ");
        getch();
        user_panel();
    }
}
void Cancel_appointment_a()
{
    char name[20];
    int found=0;
    system("cls");
    Title();
    FILE *ek, *ft;
    ft=fopen("temporary File.txt","w+");
    ek=fopen("Appointment File.txt","r");
    printf("\n\n\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2  Cancel Appointment  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(12,8);
    printf("\n\n\n\t\t Enter Patient First Name to Cancel : ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);

    while (fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name,
                  &person.Gender, &person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name)!=EOF)
    {
        if (strcmp(person.First_Name,name)!=0)
            fprintf(ft,"%s %s %c %i %s %s %s %s %s\n",person.First_Name,person.Last_Name,person.Gender,
                    person.age,person.Address,person.phone_no,person.Email,person.Problem,person.Doctor_Name);
        else
        {
            printf("%s %s %c %i %s %s %s %s %s\n", person.First_Name, person.Last_Name, person.Gender, person.age, person.Address, person.phone_no, person.Email, person.Problem, person.Doctor_Name);
            found=1;
        }
    }
    if(found==0)
    {
        printf("\n\n\t\t\t Record not found....");
        getch();
        Appointment_information();
    }
    else
    {
        fclose(ek);
        fclose(ft);
        remove("Appointment File.txt");
        rename("temporary File.txt","Appointment File.txt");
        printf("\n\n\t\t\t Successfully cancel appointment......... ");
        getch();
        Appointment_information();
    }
}

void About()
{
    int choice;
    system("cls");
    Title();
    FILE *ek;
    ek = fopen("Hospital Information.txt","r");
    printf("\n");
    char ch;
    while (!feof(ek))
    {
        ch = fgetc(ek);
        printf("%c",ch);
    }
    fclose(ek);
     printf("\n\n\n\n\n\t\tPress Any Key to Back......");
    getch();
    user_panel();
}
void ex_it()//function to exit
{
    system("cls");
    Title();// call Title function
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING SQUARE HOSPITAL LTD.");
    getch();//holds screen

}
