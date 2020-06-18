/* HEADER FILES USED */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

/* STRUCTURES USED */

/*Structure - 1 : Structure denoting a purchase notification :
  brno - Buyer's roll number
  bname - Buyer's name
  pname - Product name
  stat - Status of sale
  pr - Price of the product.
*/
struct notif
{
 char brno[10] , bname[50] , pname[50];
 int stat;
 float pr;
};

/*Structure - 2 : Structure denoting a student :
  name - Student name
  rno - Student roll number
  pwd - Password
  not - Array to store notifications, of type struct notif.
*/
struct student
{
 char name[50] , rno[10] , pwd[11];
 struct notif not[20];
};


/* Structure - 3 : Structure denoting a product.
   Members :
   price - Price in rupees
   usage - String to store NEW or USED
   srno - Seller's roll number
   cat - Product Category
   name - Product name
   des - Product description
*/
struct product
{
 float price;
 char usage[6] , srno[10] , cat[20] ,  name[50] , des[150];
};

/* FUNCTIONS USED */

/* Function - 1 : For entering a password where the
   function returns the entered password, stored in the parameter passed */
char* enterpwd ( char* str )
{
 int i=0;
 char c;
 printf ( "\nEnter password :\n" );
 //Taking character-wise input of the password and printing '*' to hide each character
 for ( ; i<10 ; i++ )
 {
  bs:
  c=getch();
  if ( c=='\b' )
  {
   fflush ( stdin );
   i--;
   printf ( "\b \b" );
   goto bs;
  }
  fflush ( stdin );
  if ( (c!='\r')&&(c!='\b') )
  {
   str[i]=c;
   printf ( "*" );
  }
  else
   break;
 }
 str[i]='\0';
 return str;
}

/* Function - 2 : To check if a student roll number (passed as parameter)
   is valid. 1 is returned if valid, 0 is returned otherwise */
int validrno ( char* str )
{
 int i;
 char s[3];
 s[0]=str[3]; s[1]=str[4]; s[2]='\0';
 //Loop to check if a non-digit character is present where a digit must be present
 for ( i=0 ; i<9 ; i++ )
 {
  if ( ((i>=0)&&(i<=2))||((i>=5)&&(i<=7)) )
  {
   if ( !((str[i]>='0')&&(str[i]<='9')) )
    return 0;
  }
 }
 //Validating branch code in the roll number string.
 if (!strcmp ( s , "CH") || !strcmp ( s , "CV" ) || !strcmp ( s , "ME" ) || !strcmp ( s , "EE" ) ||
     !strcmp ( s , "EC" ) || !strcmp ( s , "IT" ) || !strcmp ( s , "CS" ) || !strcmp ( s , "MN" ) ||
     !strcmp ( s , "MT" ) || !strcmp ( s , "AM") || !strcmp ( s , "MA" ) || !strcmp ( s , "CY") || !strcmp ( s , "PH") || !strcmp ( s , "SM") )
  return 1;
 else
  return 0;
 return 1;
}

/*Function - 3 : For entering the details of a student.
  The details entered are stored in the student object
  passed as parameter, which will be returned with the entered
  details. */
struct student enter ( struct student s )
{
 char st[11] , st1[11];
 /* Inputting student's name and roll number */
 printf ( "\nEnter name = " );
 gets ( s.name );
 printf ( "\nEnter roll number = " );
 gets ( s.rno );
 while ( validrno ( s.rno ) == 0 )   //Checking if roll number is valid
 {
  printf ( "\nINVALID ROLL NUMBER!!!!\nEnter valid roll number = " );
  gets ( s.rno );
 }
 int i;
 //Loop to initialize notification attributes to default values.
 for ( i=0 ; i<20 ; i++ )
 {
  strcpy ( s.not[i].brno , "" );
  strcpy ( s.not[i].bname , "" );
  strcpy ( s.not[i].pname , "" );
  s.not[i].stat=0;
  s.not[i].pr=0.0;
 }
 fflush ( stdin );
 strcpy ( st , enterpwd ( st ) );  //Entering password
 printf ( "\nConfirm password :\n"); //Confirming password
 strcpy ( st1 , enterpwd ( st1 ) );
 //Password is to be re-entered till confirmed.
 while ( strcmp ( st , st1 ) != 0 )
 {
  printf ( "\nRe-enter password = " );
  strcpy ( st1 , "" );
  strcpy ( st1 , enterpwd ( st1 ) );
 }
 strcpy ( s.pwd , st );
 return s;
}

/* Function - 4 : To check whether 2 products are the same. The parameters
   passed are the 2 products whose equality is to be checked */
int samepr ( struct product p1 , struct product p2 )
{
 if ( (strcmp(p1.usage,p2.usage)==0) && (strcmp(p1.srno,p2.srno)==0) && (strcmp(p1.cat,p2.cat)==0) && (strcasecmp(p1.name,p2.name)==0)  )
  return 1;
 return 0;
}

/* Function - 5 : To enter the details of a product.
   The entered details will be stored in the parameter passed,
   which will be returned. */
struct product enterp ( struct product p )
{
 int ch;
 /* Inputting product category, name, usage, price and description */
 printf ( "\nChoose product category from the following :\n" );
 printf ( "\n1. Bicycles\n2. Books & Stationery\n3. Sports Equipment\n4. Electronics\n5. Others" );
 printf ( "\nEnter your choice = " );
 scanf ( "%d" , &ch );
 while ( (ch!=1)&&(ch!=2)&&(ch!=3)&&(ch!=4)&&(ch!=5) )
 {
  printf ( "\nINVALID CHOICE!!!!\nEnter valid choice = " );
  scanf ( "%d" , &ch );
 }
 if ( ch==1 )
  strcpy ( p.cat , "Bicycles" );
 else if ( ch==2 )
  strcpy ( p.cat , "Books & Stationery" );
 else if ( ch==3 )
  strcpy ( p.cat , "Sports equipment" );
 else if ( ch==4 )
  strcpy ( p.cat , "Electronics" );
 else
  strcpy ( p.cat , "Others" );
 fflush ( stdin );
 printf ( "\nEnter product name = " );
 gets ( p.name );
 printf ( "\nIs the product new or used?" );
 printf ( "\n1. New\n2. Used\nEnter your choice = " );
 scanf ( "%d" , &ch );
 while ( (ch!=1)&&(ch!=2) )
 {
  printf ( "\nINVALID CHOICE!!!!\nEnter valid choice = " );
  scanf ( "%d" , &ch );
 }
 if ( ch==1 )
  strcpy ( p.usage , "NEW" );
 else
  strcpy ( p.usage , "USED" );
 printf ( "\nEnter the price quoted for this product ( in Rupees ) = " );
 int in=scanf ( "%f" , &p.price );
 while ( (p.price<=0)||(in!=1) )
 {
  printf ( "\nINVALID INPUT!!!!\nEnter valid price = " );
  in=scanf( "%f" , &p.price );
 }
 fflush ( stdin );
 strcpy ( p.des , " " );
 printf ( "\nEnter the other features of the product : ( note : pressing the enter key stops input ) \n" );
 gets ( p.des );
 return p;
};

/* Function - 6 : To display the details of a product passed as parameter */
void disppr( struct product p )
{
 printf ( "\nProduct category :\t%s" , p.cat );
 printf ( "\nProduct name :\t%s" , p.name );
 printf ( "\nPrice :\tRs. %.2f" , p.price );
 printf ( "\nUsage :\t%s" , p.usage );
 printf ( "\nProduct description :\n%s" , p.des );
 printf ( "\nSeller's roll number :\t%s" , p.srno );
}

/* Function - 7 : To add a student to the file "STUDENTS.DAT",
   which has the details of students registered and each record is of type student */
void addst ( struct student s )
{
 FILE *f = fopen ( "STUDENTS.DAT" , "ab" );
 fwrite ( &s , sizeof ( s ) , 1 , f );
 fclose ( f );
}

/* Function - 8 : To add a product to the file "SALES.DAT", which has the list of products for sale
   and each record is of type product */
void addpr ( struct product p )
{
 FILE *f = fopen ( "SALES.DAT" , "ab" );
 fwrite ( &p , sizeof ( p ) , 1 , f );
 fclose ( f );
}

/* Function - 9 : To search for a student's record in the file "STUDENTS.DAT",
   based on roll number (passed as parameter). The record of the student is returned as a
   result of searching. If the student is not found, an object of type student is returned
   where name, pwd and rno are set to NULL (empty strings) */
struct student searchrno ( char r[10] )
{
 struct student s;
 FILE *f = fopen ( "STUDENTS.DAT" , "rb" ); //Opening the file.
 while ( feof(f) == 0 )                     //Loop to traverse through all records.
 {
  fread ( &s , sizeof ( s ) , 1 , f );
  if ( strcmp ( s.rno , r ) == 0 )
  {
   fclose ( f );
   return s;                                //Requested record is returned if found.
  }
  else if ( feof(f) != 0 )
   break;
 }
 fclose ( f );                              //Closing the file.
 strcpy ( s.name , "" );
 strcpy ( s.pwd , "" );
 strcpy ( s.rno , "" );
 return s;                                  //This is returned if the record is not found.
}

/* Function - 10 : For searching a product in the file "SALES.DAT", on the basis of product category,
   passed as a parameter to the function. If at least one product with the requested product category
   is present, the function returns 1 otherwise -1 is returned. */
int searchcat ( char *c , char *r )
{
 int i=0;
 long int size;
 FILE *f = fopen ( "SALES.DAT" , "rb" );    //Opening the file.
 struct product p;
 fseek ( f , 0 , 2 );
 size = ftell ( f );
 size=(size/sizeof(struct product));        //Determining the number of records.
 fseek ( f , 0 , 0 );
 while ( i<=size-1 )                        //Loop to search for the record.
 {
  fread ( &p , sizeof ( p ) , 1 , f );
  ++i;
  if ( (strcmp ( p.cat , c ) == 0)&&(strcmp(p.srno,r)!=0) )
  {
   fclose(f);
   return 1;                                //Returning 1 when record is found.
  }
 }
 fclose ( f );
 return -1;                                 //This is returned if record is not found.
}

/*Function - 11 : To delete the record of a particular product in the file
  "SALES.DAT". The parameter passed is the product to be deleted.*/
void delrec( struct product p )
{
 /* Opening the required files.
    f2 points to SALES.DAT,
    f3 points to a temporary file into which only the required records from
    SALES.DAT will be copied */
 FILE *f2 = fopen ( "SALES.DAT" , "rb" ) , *f3 = fopen ( "SALES1.DAT" , "wb" );
 struct product t;
 long int pos=0 , size;
 fseek ( f2 , 0 , 2 );
 size=ftell(f2);                            //Finding file size.
 fseek ( f2 , 0 , 0 );
 /*Loop to copy all records except the one to be deleted, to SALES1.DAT*/
 while ( pos<size )
 {
  fread ( &t , sizeof(t) , 1 , f2 );
  pos=ftell(f2);
  if ( samepr ( p , t )== 0 )
   fwrite ( &t , sizeof(t) , 1 , f3 );
 }
 pos=0;
 /*Closing both the files*/
 fclose ( f3 );
 fclose ( f2 );
 remove ( "SALES.DAT" );                    //Deleting original file.
 rename ( "SALES1.DAT" , "SALES.DAT" );     //Renaming SALES1.DAT as SALES.DAT
}

/*Function - 12 : To search a product p in the file "SALES.DAT"
 return value is 1 if found, 0 otherwise*/
int searchpr ( struct product p )
{
 FILE *f=fopen ( "SALES.DAT" , "rb" );      //Opening the file.
 struct product p1;
 long int pos=0 , size;
 fseek ( f , 0 , 2 );
 size=ftell(f);                             //Finding file size.
 fseek ( f , 0 , 0 );
 while ( pos<size )                         //Loop to search for the product.
 {
  fread ( &p1 , sizeof(p1) , 1 , f );
  pos=ftell(f);
  if ( samepr(p1,p)==1 )
  {
   fclose ( f );
   return 1;                                //Returning 1 if the product is found.
  }
 }
 fclose(f);                                 //Closing the file.
 return 0;                                  //This is returned if the product is not found.
}

/* Function - 13 : To find the number of products that can still be sold
   by a particular student. Roll number of the student is passed as
   the parameter. This is to ensure that a student can sell a maximum of 20 products,
   because the memory allocation is so in this program */
int prodsell ( char* r )
{
 long int pos=0 , size;
 struct product pr;
 FILE *f = fopen ( "SALES.DAT" , "rb" );    //Opening the file.
 int c=0;
 fseek ( f , 0 , 2 );
 size=ftell(f);                             //Finding the file size.
 fseek ( f , 0 , 0 );
 while ( pos<size )                         //Loop to count the number of products sold by the user.
 {
  fread ( &pr , sizeof(struct product) , 1 , f );
  pos=ftell(f);
  if ( strcmp ( pr.srno , r ) == 0 )
   ++c;
 }
 fclose ( f );                              //Closing the file.
 return 20-c;                               //Returning the number of products that can still be sold.
}

/* Function - 14 : The main menu of the application */
int n;                                      //Global variable to store number of notifications.
void menu()
{
 //Declaring variables that will be needed everywhere in this function
 int ch , ch1 , t , i=0 , ch2, back=0, a=0;
 long int size , size1;
 struct student s , s1 , s2;
 char st[10] , st1[11] , cate[20] , ch3;
 struct product p1 , p;
 //Loop for main menu
 for ( ; ; )
 {
  fflush ( stdin );
  system ( "cls" );
  printf ( "\nE-MARKETPLACE NITK\nMAIN MENU:\n\n1. Buy products\n2. Sell products\n3. Show purchase requests" );
  printf ( "\n4. Register\n5. Help\n6. Exit\n(ENSURE THAT YOU READ \"Help\" IF YOU ARE USING THIS APPLICATION FOR THE FIRST TIME)\nEnter your choice = " );
  scanf ( "%d" , &ch );
  fflush ( stdin );
  switch ( ch )
  {
   case 1: system ( "cls" );
           fflush ( stdin );
           ch1=0;
           /* Inputting and validating credentials */
           printf ( "\nEnter your roll number = " );
           gets ( st );                     //Inputting roll number
           fflush ( stdin );
           while ( validrno(st) == 0 )      //Checking if roll number is valid.
           {
            printf ( "\nINVALID ROLL NUMBER!!!!\nEnter valid roll number = " );
            gets ( st );
           }
           s1=searchrno ( st );             //Checking if roll number is registered.
           if ( strcmp ( s1.name , "" ) == 0 )
           {
            printf ( "\nTHIS ROLL NUMBER IS NOT REGISTERED!!!!" );
            getchar();
            fflush(stdin);
           }
           else
           {
            strcpy ( st1 , enterpwd ( st1 ) );      //Inputting password.
             if ( strcmp ( st1 , s1.pwd ) != 0 )
             {
              printf ( "\nINCORRECT PASSWORD!!!!" );
              getchar();
              fflush ( stdin );
             }
             else
             {
               while ( ch1!=6 )
               {
               system ( "cls" );
               /* Inputting product category */
               printf ( "\nChoose product category from the following :\n" );
               printf ( "\n1. Bicycles\n2. Books & Stationery\n3. Sports equipment\n4. Electronics\n5. Others\n6. Return to main menu\n" );
               printf ( "\nEnter your choice = " );
               scanf ( "%d" , &ch1 );
               fflush ( stdin );
               while ( (ch1!=1)&&(ch1!=2)&&(ch1!=3)&&(ch1!=4)&&(ch1!=5)&&(ch1!=6) )
               {
                printf ( "\nINVALID INPUT!!!!\nEnter valid choice = " );
                scanf ( "%d" , &ch1 );fflush ( stdin );
               }
               switch ( ch1 )
               {
                case 1 : strcpy ( cate , "Bicycles" );
                         break;
                case 2 : strcpy ( cate , "Books & Stationery" );
                         break;
                case 3 : strcpy ( cate , "Sports equipment" );
                         break;
                case 4 : strcpy ( cate , "Electronics" );
                         break;
                case 5 : strcpy ( cate , "Others" );
                         break;
                case 6 : goto back;
                         break;
               }
               /* Checking there are any products with the requested category */
               t = searchcat ( cate , st );
               if ( t==-1 )
               {
                printf ( "\nNO PRODUCTS FOR SALE UNDER THIS CATEGORY....." );
                getchar();
                fflush ( stdin );
               }
               else
               {
                FILE *f = fopen ( "SALES.DAT" , "rb" );    //Opening SALES.DAT.
                fseek ( f , 0 , 2 );
                size=ftell ( f );
                size=(size/(sizeof(struct product)));      //Finding the number of records.
                fseek ( f , 0 , 0 );
                i=0;
                int map[100] , m=0;
                /* "map" will be used to store the record numbers of
                   products with the requested category. This enables easy
                   access and decreases the time complexity of displaying items. */
                system ( "cls" );
                printf ( "\nITEMS FOR SALE UNDER THIS CATEGORY :\n" );
                 while ( i<size )
                 {
                  fread ( &p , sizeof(p) , 1 , f );
                  ++i;
                  if ( (strcmp ( p.cat , cate ) == 0)&&( strcmp ( p.srno , st )!=0 ) )
                  {
                   map[m]=i;
                   ++m;
                  }
                 }
                int j=0;
                /* Loop to display products under requested category
                   The last option in this menu is to return to menu of
                   product categories if the user is not interested in
                   any of the displayed products. */
                 for ( j=0 ; j<m ; j++ )
                 {
                  fseek ( f , (map[j]-1)*sizeof(struct product) , 0 );
                  fread ( &p , sizeof(p) , 1 , f );
                  printf ( "\n[%d] %s put for sale by roll number %s" , j+1 , p.name , p.srno );
                 }
                printf ( "\n[%d] Not interested in any of these products" , m+1 );
                printf ( "\nEnter your choice :\n" );
                scanf ( "%d" , &ch2 );
                if ( ch2==m+1 )             //If user chooses to go back.
                {
                 fclose(f);
                 goto back;
                }
                fflush ( stdin );
                /* If user does not choose to go back, the requested product is
                   displayed */
                long int fskr=fseek ( f , (map[ch2-1]-1)*sizeof(struct product) , 0 );
                fread ( &p , sizeof(p) , 1 , f );
                fseek(f,0,0);
                fclose(f);
                if ( (fskr==-1)||(strcmp ( p.cat , cate ) != 0)||(ch2>(m+1))||(ch2<=0) )
                {
                 printf ( "\nINVALID INPUT!!!!" );
                 getchar();
                 fflush ( stdin );
                }
                else
                {
                 system ( "cls" );
                 printf ( "\nFull product details :\n" );
                 disppr ( p );
                 printf ( "\nDo you want to buy this product?(y/n)" );
                 scanf ( "%c" , &ch3 );
                 fflush ( stdin );
                  while ( (ch3!='y')&&(ch3!='Y')&&(ch3!='n')&&(ch3!='N') )
                  {
                   printf ( "\nINVALID INPUT!!!!\nEnter a valid choice = " );
                   scanf ( "%c" , &ch3 );
                   fflush ( stdin );
                  }
                 if ( (ch3 == 'y')||(ch3=='Y') )
                 {
                 FILE *f1 = fopen ( "STUDENTS.DAT" , "rb+" );     //Opening STUDENTS.DAT.
                 fseek ( f1 , 0 , 2 );
                 size1=ftell(f1);
                 size1=(size1/sizeof(struct student));
                 int j=0;
                 fseek ( f1 , 0 , 0 );
                  while ( j<size1 )
                  {
                   fread ( &s2 , sizeof (s2) , 1 , f1 );
                   ++j;
                   /*If the seller's record is found, a notification
                     is added to that account*/
                    if ( strcmp ( p.srno , s2.rno ) == 0 )
                    {
                     fseek ( f1 , (-1)*sizeof(struct student) , 1 );
                     int k;
                      for ( k=0 ; k<20 ; k++ )
                       if ( strcmp ( s2.not[k].brno , "" ) == 0 )
                       {
                        strcpy ( s2.not[k].brno , s1.rno );
                        strcpy ( s2.not[k].bname , s1.name );
                        strcpy ( s2.not[k].pname , p.name );
                        s2.not[k].pr=p.price;
                        break;
                       }
                     fwrite ( &s2 , sizeof(s2) , 1 , f1 );
                     break;
                    }
                  }
                 fclose ( f1 );
                 delrec ( p );              //Removing product from the file SALES.DAT.
                }
               }
              }
            back:
            if ( ch1==6 )
             break;
             }
            }

           }
           break;
   case 2: system ( "cls" );
           int input;
           fflush ( stdin );
           /* Inputting and validating credentials as in previous case */
           printf ( "\nEnter your roll number = " );
           gets ( st );
            while ( validrno ( st ) == 0 )
           {
            printf ( "\nINVALID ROLL NUMBER!!!!\nEnter valid roll number = " );
            gets ( st );
           }
           s1 = searchrno( st );
           if ( strcmp ( s1.name , "" ) == 0 )
           {
            printf ( "\nTHIS ROLL NUMBER IS NOT REGISTERED!!!!" );
            getchar();
            fflush(stdin);
           }
           else
           {
            strcpy ( st1 , enterpwd ( st1 ) );
             if ( strcmp ( st1 , s1.pwd ) != 0 )
             {
              printf ( "\nINCORRECT PASSWORD!!!!" );
              getchar();
              fflush ( stdin );
             }
             else
             {
              char res='y';
              if ( prodsell( st ) == 0 )       //Checking if the user can sell more products.
              {
               nomore:
               printf ( "\nYou have sold 20 products......." );
              }
              else
              {
               while ( (res=='y')||(res=='Y') )
               {
                system ( "cls" );
                printf ( "\nEnter product details :\n" );
                p = enterp ( p );              //Inputting product details.
                strcpy ( p.srno , st );
                if ( searchpr(p) == 1 )        //Checking if this product is already sold by the same student.
                {
                 printf ( "\nThis product has already been put for sale by you........" );
                 printf ( "\nDo you want to sell a different product?(y/n)" );
                 fflush(stdin);
                 input=scanf ( "%c" , &res );
                  while ( ((res!='y')&&(res!='Y')&&(res!='n')&&(res!='N'))||(input!=1) )
                  {
                   printf ( "\nEnter a valid choice = " );
                   fflush ( stdin );
                   scanf ( "%c" , res );
                  }
                }
                else
                {
                 addpr ( p );                  //Adding product to SALES.DAT.
                 int ps;
                 /*If the user can't sell any more products,
                   the message under the "nomore" label is displayed,
                   otherwise, the user is asked if he/she wnats to
                   sell more products.*/
                 if ( (ps=prodsell(st)) == 0 )
                  goto nomore;
                 printf ( "\nYou can sell %d more product(s)" , ps );
                 printf ( "\nDo you want to sell another product?(y/n)" );
                 input=scanf ( "%c" , &res );
                  while ( ((res!='y')&&(res!='Y')&&(res!='n')&&(res!='N'))||(input!=1) )
                  {
                   printf ( "\nEnter valid choice = " );
                   fflush ( stdin );
                   scanf ( "%c" , &res );
                  }
                 }
              }
             }
            }
           }
           break;
   case 3: system ( "cls" );
           strcpy ( st , "" );strcpy ( st1 , "" );
           /* Inputting and validating credentials as in previous case */
           printf ( "\nEnter your roll number :\n" );
           fflush ( stdin );
           gets ( st );
            while ( validrno ( st ) == 0 )
            {
             printf ( "\nINVALID ROLL NUMBER!!!!\nEnter valid roll number = " );
             gets ( st );
            }
           s1 = searchrno ( st );
            if ( strcmp(s1.name,"")==0 )
            {
             printf ( "\nTHIS ROLL NUMBER IS NOT REGISTERED!!!!" );
             getchar();
             fflush( stdin );
            }
            else
            {
             strcpy ( st1 , enterpwd ( st1 ) );
             if ( strcmp ( st1 , s1.pwd ) != 0 )
             {
              printf ( "\nINCORRECT PASSWORD!!!!" );
              getchar();
              fflush ( stdin );
             }
             else
             {
              system ( "cls" );
              int i;
              /*Loop to count the number of purchase requests/notifications
                in the user's account */
              for ( i=0 ; i<20 ; i++ )
               if ( strcmp( s1.not[i].brno , "" ) == 0 )
                break;
              n=i;
              noreq:
              if ( n==0 )
              {
               printf ( "\nYou have no purchase requests\nPress any key to return to main menu....." );
               getch();
              }
              else
              {
               int chr , in;
               char res;
                while ( chr!=(n+1) )
                {
                 bk:
                 system ( "cls" );
                 printf ( "\nYOUR PURCHASE REQUESTS :\n" );
                 for ( i=0 ; i<n ; i++ )              //Loop to view notifications.
                  printf ( "\n[%d] %s" , i+1 , s1.not[i].pname );
                 printf ( "\n[%d] Return to main menu" , n+1 );
                 printf ( "\nEnter your choice = " );
                 in=scanf ( "%d" , &chr );
                 fflush ( stdin );
                 while ( (chr<=0)||(chr>(n+1) )||(in!=1) )
                 {
                  printf ( "\nINVALID CHOICE!!!!" );
                  printf ( "\nEnter valid choice = " );
                  in=scanf ( "%d" , &chr );
                  fflush ( stdin );
                 }
                 if ( chr==(n+1))
                  break;
                 else
                 {
                  system ( "cls" );
                  /*Displaying requested notification.*/
                  printf ( "\n%s, roll number %s wants to purchase" , s1.not[chr-1].bname , s1.not[chr-1].brno );
                  printf ( "\n%s sold for Rs. %.2f by you.\nIs the amount of Rs. %.2f paid (y/l/b)?" , s1.not[chr-1].pname , s1.not[chr-1].pr , s1.not[chr-1].pr );
                  printf ( "\nEnter 'y' if the amount is paid, 'l' if the buyer has agreed to pay the amount later," );
                  printf ( "'b' to return to menu of purchase requests" );
                  printf ( "\nEnter your choice = " );
                  fflush ( stdin );
                  int inp=scanf ( "%c" , &res );   //Inputting action to be taken by user.
                  fflush ( stdin );
                  while ( ((res!='y')&&(res!='Y')&&(res!='l')&&(res!='L')&&(res!='b')&&(res!='B'))||(inp!=1) )
                  {
                   printf ( "\nINVALID CHOICE!!!!\nEnter valid choice = " );
                   inp=scanf ( "%c" , &res );
                   fflush ( stdin );
                  }
                  /*If amount is not yet paid or user wants to return to notification menu*/
                  if ( (res=='b')||(res=='B')||(res=='l')||(res=='L') )
                   goto bk;
                  /* If amount is paid */
                  else
                  {
                   int k;
                   long int pos=0 , sz;
                   struct student stu;
                   /*Deleting notification of this product from list of notifications*/
                   for ( k=chr ; k<n ; k++ )
                    s1.not[k-1]=s1.not[k];
                   /*Assigning default values to attributes of last record*/
                   strcpy ( s1.not[n-1].bname , "" );
                   strcpy ( s1.not[n-1].brno , "" );
                   strcpy ( s1.not[n-1].pname , "" );
                   s1.not[n-1].pr=0.0;
                   s1.not[n-1].stat=0;
                   FILE *f = fopen ( "STUDENTS.DAT" , "rb+" );   //Opening STUDENTS.DAT.
                   fseek ( f , 0 , 2 );
                   sz=ftell(f);                                  //Finding file size.
                   fseek ( f , 0 , 0 );
                    while ( pos<sz )                             //Loop to modify the record of the user.
                    {
                     fread ( &stu , sizeof(stu) , 1 , f );
                     pos=ftell(f);
                      if ( strcmp ( stu.rno , s1.rno ) == 0 )
                      {
                       fseek ( f , (-1)*sizeof(struct student) , 1 );
                       fwrite ( &s1 , sizeof(s1) , 1 , f );
                       break;
                      }
                    }
                   --n;               //Decrementing number of notifications as one has been removed.
                   fclose(f);
                   /* If there are no more notifications,
                      the command under the label "noreq" is executed */
                   if ( n==0 )
                   {
                    system ( "cls" );
                    goto noreq;
                   }
                  }
                 }
                }
               }
              }
             }
            break;
   case 4: system ( "cls" );
           printf ( "\nEnter student details :\n" );
           fflush ( stdin );
           s=enter ( s );                   //Inputting student details.
           s1=searchrno ( s.rno );          //Checking if student is already registered.
           /*If the student has already registered, an error message is printed.*/
            if ( strcmp ( s1.rno , s.rno ) == 0 )
            {
             printf ( "\nYou are already registered!!!!" );
             getchar();
             fflush ( stdin );
            }
            /* Otherwise, the student's record is added to STUDENTS.DAT */
            else
            {
             addst ( s );
             printf ( "\nYour account has been created!!!!" );
             getch();
             fflush ( stdin );
            }
           break;
   case 5: /*This section consists of the instructions to a new
             user on how to use this application. */
           while ( back!=6 )
           {
            system ( "cls" );
            printf( "Welcome to help section menu of E-MarketPlace NITK\n");
            printf("Press any of the given options to know more about it.");
            printf( "\n\n1. About the project\n2. Buying a product\n3. Selling a product" );
            printf( "\n4. Purchase requests\n5. How to register\n6. Return to main menu" );
            printf("\n\nEnter your choice: ");
            scanf("%d",&back);
            fflush ( stdin );
            if(back==1)
            {
             system ( "cls" );
             printf("\n\t\tAbout the project\n\n");
             printf("This project is intended to serve as a platform for the students of NITK in\n");
             printf("buying/selling usable products from other students of NITK. Upon opening the\n");
             printf("application, a student has the choice of performing 4 operations: buying products,\n");
             printf("selling products, registering, viewing purchase requests. If the student chooses" );
             printf(" to buy a product, the student is asked to choose\n");
             printf("the category of the item to be bought. If the item is available, it can be bought\n");
             printf("from the seller and the item will be removed from the list of items for sale.\n");
             printf("If the student chooses to sell a product, he/she can add the product to the list\n");
             printf("of products for sale, with the product description in detail.\n");
             printf("\nPress any key to go to main menu........ ");
             getchar();
             fflush ( stdin );
            }
            else if(back==2)
            {
             system ( "cls" );
             printf("\n\t\tBuying a product\n\n");
             printf("(i) For buying a product, you need to first enter your registered roll no. in the\n");
             printf("format of xxx(CH)xxx. Eg. 191CH036 or 191ME222\n");
             printf("(ii) Enter your registered password. Remember that the password can be upto 10 characters.\n");
             printf("(iii) Now, choose the type of product you want to buy and see the details of\n");
             printf("products and who is selling it, or, you can also return to the main menu by\n");
             printf("choosing choice 6\n");
             printf("(iv) If you want any of the products, go to it's details by typing the respective\n");
             printf("serial number for the product.\n");
             printf("(v) Press 'y' if you want to buy it. Otherwise press 'n'.\n");
             printf("Remember to press 'y' if you are absolutely sure that the amount can be paid.\n");
             printf("(vi) A notification will be sent to the owner of the product.\n");
             printf("\nPress any key to go to main menu........ ");
             getchar();
             fflush ( stdin );
            }
            else if(back==3)
            {
             system ( "cls" );
             printf("\n\t\tSelling a product\n\n");
             printf("(i) For selling a product you need to first enter your registered roll no. in the\n");
             printf("format of xxx(CH)xxx eg. 191CH036 or 191ME222\n");
             printf("(ii) Enter your registered password. Remember that password can be upto 10 characters\n");
             printf("(iii) Now, choose the type of product you want to sell.\n");
             printf("(iv) Enter the product name, select if it's used or new, and set the price.\n");
             printf("(v) Enter further details of the product, and you successfully put your product for sale.\n");
             printf("(vi) Remember that a maximum of 20 products can be sold." );
             printf("\nPress any key to go to main menu........ ");
             getchar();
             fflush ( stdin );
            }
            else if(back==4)
            {
             system ( "cls" );
             printf("\n\t\tPurchase requests\n\n");
             printf("After typing your roll no. and password, you will be able to see whether\n");
             printf("you got any request from another user for purchase of your product with the\n");
             printf("details of another user, for easy contact with the person.\n");
             printf ( "\nSelect the buyer of your choice and take actions as prompted" );
             printf("\nPress any key to go to main menu........ ");
             getchar();
             fflush ( stdin );
            }
            else if(back==5)
            {
             system ( "cls" );
             printf("\n\t\tHow to register\n\n");
             printf("(i) After going to register option. Enter your name.\n");
             printf("(ii)  Enter a password. Remember that password can be upto 10 characters.\n");
             printf("(iii) You are successfully registered now.\n");
             printf("\nPress any key to go to main menu........ ");
             getchar();
             fflush ( stdin );
            }
            else if ( back==6 )
             break;
            else
            {
             printf ( "\nINVALID CHOICE!!!!" );
             getchar();
             fflush ( stdin );
            }
           }
           break;
   case 6: system ( "cls" );
           exit(0);      //Exiting the application.
           break;
   default:printf ( "\nINVALID CHOICE!!!!" );
           fflush(stdin);
           getchar();
           fflush ( stdin );
           break;
  }
 }
}

/* The main program, which calls the menu() function to run the application */
int main()
{
 menu();
 return 0;
}
