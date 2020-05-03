#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
int chk(char sq[]);
void game();
void intro();
void frame();
void pattern(char sq[]);




//defining pattern() function
void pattern(char sq[])
{
  frame();
  gotoxy(28,5);
  cprintf("WELCOME TO TIC TOE GAME");
  gotoxy(15,8);
  cprintf("PLAYER-1 [X]");
  gotoxy(54,8);
  cprintf("PLAYER-2 [0]");
  gotoxy(31,10);
  cprintf("     |     |     ");
  gotoxy(31,11);
  cprintf("  %c  |  %c  |  %c  ",sq[0],sq[1],sq[2]);
  gotoxy(31,12);
  cprintf("_____|_____|_____");
  gotoxy(31,13);
  cprintf("     |     |     ");
  gotoxy(31,14);
  cprintf("  %c  |  %c  |  %c  ",sq[3],sq[4],sq[5]);
  gotoxy(31,15);
  cprintf("_____|_____|_____");
  gotoxy(31,16);
  cprintf("     |     |     ");
  gotoxy(31,17);
  cprintf("  %c  |  %c  |  %c  ",sq[6],sq[7],sq[8]);
  gotoxy(31,18);
  cprintf("     |     |     ");
}








//Defining intro(); function
void intro()
{
 char s[100]="Hi! There Welcome to Gorilla Programming";
 char s1[100]="This Program is about TIC TOE GAME";
 char s2[100]="Enjoy the game !! CLick to continue";
 int i=0;
 frame();
 gotoxy(22,12);
 while(s[i]!='\0')
 {
  sound(200);
  cprintf("%c",s[i]);
  delay(5);
  nosound();
  delay(45);
  i++;
 }
 delay(50);
 i=0;
 frame();
 gotoxy(23,12);
 while(s1[i]!='\0')
 {
  sound(200);
  cprintf("%c",s1[i]);
  delay(5);
  nosound();
  delay(45);
  i++;
 }
 delay(50);
 i=0;
 frame();
 gotoxy(23,12);
 while(s2[i]!='\0')
 {
  sound(200);
  cprintf("%c",s2[i]);
  delay(5);
  nosound();
  delay(45);
  i++;
 }
 getch();
}


//Defining frame(); function
void frame()
{
 int i;
 clrscr();
 textcolor(GREEN);
 textbackground(BLACK);
 for(i=3;i<=24;i++)
 {
  gotoxy(77,i);
  cprintf("*");
  gotoxy(2,i);
  cprintf("*");
 }
 for(i=4;i<=76;i++)
 {
  gotoxy(i,24);
  cprintf("_");
  gotoxy(i,2);
  cprintf("_");
 }
}



//Start of main(); function
void main()
{
  int opt;
  int i;
  clrscr();
  frame();
  intro();
  A:
  while(1)
  {
   frame();
   gotoxy(24,10);
   cprintf("WELCOME TO TIC TOE GAME");
   gotoxy(24,12);
   cprintf("Do You Want to Play ::");
   gotoxy(45,13);
   cprintf("1 . YES");
   gotoxy(45,14);
   cprintf("2 . EXIT    ______");
   gotoxy(60,14);
   scanf("%d",&opt);
   switch(opt)
   {
   case 1 :

	 game();
	 goto A;

   case 2 :
	 exit(0);

   default :

     for(i=5;i>0;i--)
     {
      frame();
      gotoxy(34,12);
      cprintf("Please wait.");
      delay(500);
      gotoxy(34,12);
      cprintf("Please wait..");
      delay(500);
      gotoxy(34,12);
      cprintf("Please wait...");
      delay(500);
     }
     break;

   }
  }
}


//defining game();
void game()
{
  char sq[9]={'1','2','3','4','5','6','7','8','9'};
  int i,choice,win;
  pattern(sq);
  for(i=0;i<=9;i++)
  {
   if(i%2==0&&i<9)
   {
    gotoxy(6,22);
    cprintf("PLAYER - 1 [X] Chance :: ");
    scanf("%d",&choice);
    sq[choice-1]='X';
    pattern(sq);
    win= chk(sq);
    if(win==1)
    {
      gotoxy(6,22);
      cprintf("HURRAY !! PLAYER-1 [X] WON ");
      break;
    }
   }
   else if(i%2==1&&i<9)
   {
    gotoxy(50,22);
    cprintf("PLAYER - 2 [X] Chance :: ");
    scanf("%d",&choice);
    sq[choice-1]='0';
    pattern(sq);
    win=chk(sq);
    if(win==1)
    {
      gotoxy(50,22);
      cprintf("HURRAY !! PLAYER-2 [0] WON ");
      break;
    }
   }
   else
   {
    if(i==9)
    {
     win=chk(sq);
     if(win==0)
     {
      gotoxy(6,22);
      cprintf("OOPS MATCH DRAW ");
      break;
     }
    }
   }
  }
getch();
}
int chk(char sq[])
{
 int win=0;
 if(sq[0]==sq[1]&&sq[1]==sq[2])
 {
  win=1;
 }
 else if(sq[0]==sq[3]&&sq[3]==sq[6])
 {
  win=1;
 }
 else if(sq[0]==sq[4]&&sq[4]==sq[8])
 {
  win=1;
 }
 else if(sq[1]==sq[4]&&sq[4]==sq[7])
 {
  win=1;
 }
 else if(sq[2]==sq[5]&&sq[5]==sq[8])
 {
  win=1;
 }
 else if(sq[3]==sq[4]&&sq[4]==sq[5])
 {
  win=1;
 }
 else if(sq[2]==sq[4]&&sq[4]==sq[6])
 {
  win=1;
 }
 else if(sq[6]==sq[7]&&sq[7]==sq[8])
 {
  win=1;
 }
 else
 {
  win=0;
 }
 return(win);
}



