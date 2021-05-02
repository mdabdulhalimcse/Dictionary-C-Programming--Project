#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>


COORD coord = {0, 0};
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



struct node
{
    char data [ 20 ] ;
    char m [ 5 ] [ 20 ] ;
    int mcount ;
    struct node * link ;
} ;

struct node * dic [ 26 ] ;

void add ( char * ) ;
int  search ( char * ) ;
void show( ) ;
void deldic( ) ;

void main( )
{
    system("cls");
   system("color 4e");
    char word [ 20 ] , ch ;
    int i ;



    while ( 1 )
    {
        system("cls");
       gotoxy(20,3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SMART DICTIONARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,5);
        printf("\xDB\xDB\xDB\xDB\xB2 1. Add Word   ");
        gotoxy(20,7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Search Word.");
	gotoxy(20,9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Show Dictionary.");
	gotoxy(20,11);
	printf("\xDB\xDB\xDB\xDB\xB2 0. Close Applications & helps");
	gotoxy(20,13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(20,15);
	t();
    gotoxy(20,16);
	printf("Enter your choice:");
	gotoxy(40,16);
        scanf ( "%d", &ch ) ;
        gotoxy(20,16);

        switch ( ch )
        {
            case 1 :
                system("cls");

                printf ( "\nEnter any word : " ) ;
                fflush ( stdin ) ;
                gets ( word ) ;
                add ( word ) ;

                break ;

            case 2 :

                printf ( "\nEnter the word to search : " ) ;
                fflush (stdin);
                gets ( word ) ;
                i = search ( word ) ;
                if ( ! i )
                    printf ( "Word does not exists." ) ;
                getch( ) ;

                break ;

            case 3 :

                show( ) ;
                getch( ) ;

                break ;

            case 0 :
        {
		system("cls");
		gotoxy(16,3);
		printf("The Programmers....");
		gotoxy(16,4);
		printf("1. Md. Abdul Halim       (ID: 171-15-1408 )");
		gotoxy(16,5);
		printf("   Mobile:+8801786571095  E-mail:mdabdulhalim.cse@gmail.com");
		gotoxy(16,7);
		printf("2. Sheikh Khadija Meem      (ID: 171-15-1151)");
		gotoxy(16,8);
		printf("   Mobile:01736355306  E-mail:15-1151@diu.edu.bd  ");
		gotoxy(16,10);
        gotoxy(16,13);
		printf("With  the Unexplainable Help of Md. Abdul Halim");
		gotoxy(10,17);
		printf("Exiting in 3 second...........->");


		exit(3);
	    }




            default :

               printf("\aWrong Entry!!Please re-entered correct option\n\n\n");
		if(getch())
		main ();

        }
    }
}

void add ( char * str )
{

    int i, j = toupper ( str [ 0 ] ) - 65 ;
    struct node* r, *temp = dic [ j ], *q ;
    char mean [ 5 ] [ 20 ], ch = 'y' ;

    i = search ( str ) ;
    if ( i )
    {
        printf ( "\nWord already exists." ) ;
        getch( ) ;
        return ;
    }
    q = (struct node*)malloc(sizeof(struct node)) ;
    strcpy ( q -> data, str ) ;
    q -> link = NULL ;

    for ( i =0 ; tolower( ch ) == 'y' && i < 5 ; i++ )
    {
        fflush(stdin);
        printf( "\n\nEnter the meaning(s) : ") ;
        gets ( mean [ i ] ) ;

        strcpy ( q -> m [ i ] , mean [ i ] ) ;
        if ( i != 4 )
            printf ( "\nAdd more meanings (y/n) " ) ;
        else
            printf ( "You cannot enter more than 5 meanings." ) ;
        fflush ( stdin ) ;
        ch = getche( );
    }

    q -> mcount = i ;
    if ( dic [ j ] == NULL || strcmp ( dic [ j ] -> data, str ) > 0 )
    {
        r = dic [ j ] ;
        dic [ j ] = q ;
        q -> link = r ;
        return ;
    }

    else
    {
        while ( temp != NULL )
        {
            if((strcmp( temp -> data,str ) < 0 ) && ((strcmp (temp -> link -> data, str) > 0 )||temp -> link == NULL ) )
            {
                q -> link = temp -> link ;
                temp -> link = q ;
                return ;
            }
            temp = temp -> link ;
        }
    }
}

int search (char *str)
{
    system("cls");
    struct node *n ;
    char temp1 [ 20 ] ;
    char temp2 [ 20 ] ;
    int i ;

    n = dic [ toupper ( str [ 0 ] ) - 65 ] ;
    strcpy ( temp2, str ) ;
    strupr ( temp2 ) ;

    while ( n != NULL )
    {
        strcpy ( temp1, n -> data ) ;

        if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
        {
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( i = 1 ; i < n -> mcount ; i++ )
                printf ( "\n\t\t%s", n -> m [ i ] ) ;
            return 1 ;
        }
        n = n -> link ;
    }
    return 0 ;
}

void show( )
{
system("cls");
    struct node *n ;
    int i, j ;

    printf ( "Word\t\tMeaning\n" ) ;
    for ( i = 0 ; i <= 30 ; i++ )
        printf ( "-" ) ;


    for (i=0;i<=25 ;i++)
    {
        n = dic[i] ;
        while ( n!=NULL )
        {
            printf ("\n%s\t\t%s", n->data, n-> m[0] ) ;
            for ( j = 1 ; j < n -> mcount ; j++ )
                printf ( "\n\t\t%s", n -> m [ j ] ) ;
            n = n -> link ;
        }
    }
}


int t(void)
{

time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}


