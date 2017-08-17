#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
union REGS in, out; //  int check[25]={0};
void menu(int *button, int *xpos, int *ypos);
void g1(int *button, int *xpos, int *ypos);
int inputx(int *xpos);
void input(int *button, int *xpos, int *ypos);
int ans[][25]={{1,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1},
				{1,1,1,1,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,1,1},
				{0,0,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1,0,0,0,0,0,1,1,1},
				{1,1,1,1,0,0,0,1,1,1,0,1,1,1,0,0,0,1,1,1,1,1,1,1,0},
				{0,0,0,1,0,1,1,1,0,0,0,0,1,1,0,1,1,1,1,1,0,0,0,1,0}};
int gameNo;
int check[25];



//Detects coordinates of click
void detect(int *button,int *xpos,int *ypos)
{	in.x.ax=3;
	int86(51,&in,&out);
	*button=out.x.bx;
	*xpos=out.x.cx;
	*ypos=out.x.dx;
}





void check0()
{	int i=0;
	for(i=0; i<25; i++)
	   check[i]=0;
}



//Places game data
void gamedata(int a, int b, int c, int d, int e, int f, int g,int h,int i,int j,int k,int l,
int m,int n,int o,int p,int q,int r,int s,int t, int *button, int *xpos, int *ypos )
{	gotoxy(33,7); printf("%d",a);
	gotoxy(38,7); printf("%d", b);
	gotoxy(43,7);  printf("%d", c);
	gotoxy(48,7);  printf("%d", d);
	gotoxy(53,7);  printf("%d", e);
	gotoxy(33,9); printf("%d",f);
	gotoxy(38,9);   printf("%d",g);
	gotoxy(43, 9);  printf("%d",h);
	gotoxy(48, 9);  printf("%d", i);
	gotoxy(53, 9); printf("%d", j);
	gotoxy(33,12);  printf("%d", k);
	gotoxy(38, 12); printf("%d", l);
	gotoxy(43, 12); printf("%d", m);
	gotoxy(48, 12); printf("%d", n);
	gotoxy(53,12);  printf("%d", o);
	gotoxy(28,15 ); printf("%d", p);
	gotoxy(28, 17); printf("%d", q);
	gotoxy(28, 20); printf("%d", r);
	gotoxy(28, 22); printf("%d", s);
	gotoxy(28, 24); printf("%d",t);
    input(button, xpos, ypos);
}


void g1(int *button, int *xpos, int *ypos)
{  check0();
	gameNo=0;
     gamedata(0,1,1,1,0,3,1,1,1,1,1,1,1,1,3,5,1,5,1,5, button, xpos, ypos);
}
 
void g2(int *button, int *xpos, int *ypos)
{   check0(); 
	gameNo=1; gamedata(0,0,1,0,0,1,1,1,2,1,1,2,1,1,1,5,1,1,1,5, button,xpos, ypos);
}

void g3(int *button, int *xpos, int *ypos)
{  check0();
	gameNo=2;
	 gamedata(0,0,1,1,1,0,0,1,1,1,1,3,1,1,1,3,1,5,1,3,button,xpos,ypos);
}

void g4( int *button, int *xpos, int *ypos)
{  check0();  gameNo=3; gamedata(0,1,0,0,0,1,1,0,0,1,1,1,5,5,1,4,3,3,3,4, button, xpos, ypos);
}

void g5(int *button, int *xpos, int *ypos)
{
	    check0(); 
		 gameNo=4;
		 gamedata(0,0,0,0,0,1,1,0,1,0,1,1,3,3,1,1,3,2,5,1, button, xpos , ypos);
}
 
 
 
 
 //Game layout
void drawbasic(int *button , int *xpos, int *ypos)
{	cleardevice();       setcolor(3); setlinestyle(0,1,2);
	rectangle(200,80,440,400);
	line(200,80,200,400);  line(440,80,440,400);
	line(200,80,440,80);   line(200,400,440,400);setlinestyle(0,1,1);
	setcolor(3);
	line(200,120,440,120);   line(200,160,440,160);
	line(200,200,440,200);    line(200,240,440,240);
	line(200,280,440,280);    line(200, 320,440 ,320);
	line(200,360,440,360);
	line(240,80,240,400);    line(280,80,280, 400);
	line(320,80,320,400);     line(360,80,360,400);
	line(400,80,400,400);
	rectangle(60, 420,180,460); outtextxy(70,430,"MAIN MENU");
	rectangle(240, 420, 360, 460); outtextxy(270, 430, "DONE");
	
	switch(gameNo)
	{
		case 0: g1(button, xpos, ypos);		break;
		case 1: g2(button, xpos, ypos);		break;
		case 2: g3(button, xpos, ypos);		break;
		case 3: g4(button, xpos, ypos);		break;
		case 4: g5(button, xpos, ypos);		
	}
	
	//places game data ; need to change this
}
 
 
void game(int *button , int *xpos, int *ypos)
{	
	drawbasic(button , xpos, ypos);
}



//colors the clicked box
void color(int n)
{       
	check[n-1]=1;
	switch(n)
	{	case 1: bar(240,200,280,240);  break;
		case 2:  bar(280,200, 320, 240); break;
		case 3:  bar(320,200,360,240);  break;
		case 4:  bar(360, 200,400, 240);  break;
		case 5:  bar(400,200,440,240);   break;
		case 6:   bar(240,240,280,280); break;
		case 7:  bar(280,240,320,280);  break;
		case 8: bar(320, 240,360, 280); break;
		case 9:  bar(360, 240, 400, 280);  break;
		case 10:   bar(400,240,440, 280);   break;
		case 11:    bar(240,280,280,320);  break;
		case 12:  bar(280,280,320,320); break;
		case 13: bar(320,280,360,320); break;
		case 14: bar(360,280,400,320);  break;
		case 15: bar(400, 280, 440, 320); break;
		case 16: bar(240,320,280,360); break;
		case 17: bar(280,320,320,360); break;
		case 18: bar(320,320,360,360); break;
		case 19: bar(360,320,400,360); break;
		case 20: bar(400,320,440, 360); break;
		case 21:  bar(240,360,280,400); break;
		case 22: bar(280,360,320,400); break;
		case 23: bar(320,360,360,400); break;
		case 24:  bar(360,360,400,400); break;
		case 25:  bar(400,360,440,400);
	}
}





void checkAnswer(int *button,int *xpos ,int *ypos)
{
			int i=0;		
				for(i=0;i<25;i++){
					if(check[i]!=ans[gameNo][i]){
						break;
					}
				}	
			if(i==25)
			{
				cleardevice();
				outtextxy(300,150,"Completed successfully !!");
				settextstyle(1,0,1);
		
			}
			else
			{
				cleardevice();
				outtextxy(300,150,"Unsuccessful attempt !! ");
				settextstyle(1,0,1);
			}
	
	
	    do{
				detect(button, xpos, ypos);
       }while(*button!=1);
	   
	   
	    do{
				detect(button, xpos, ypos);
       }while(*button!=1);
	   
			
			delay(700);
			menu(button, xpos, ypos);  			
		 
}


//if user clicks in a box, color that box
void input(int *button,int *xpos ,int *ypos)
{      int x=0;
	while(1)
	{      do
		{	detect(button, xpos, ypos);
		}while(*button!=1);


		if((*ypos>200)&&(*ypos<240))
		{   x=inputx(xpos); color(x);  }
		else if((*ypos>240)&&(*ypos<280))
		{   x=5+inputx(xpos);   color(x);   }
		else if((*ypos>280)&&(*ypos<320))
		{   x=10+inputx(xpos);    color(x);  }
		else if((*ypos>320)&&(*ypos<360))
		{	x=15+inputx(xpos);  color(x);  }
		else if((*ypos>360)&&(*ypos<400))
		{    x=20+inputx(xpos);   color(x);   }
		else if((*xpos>60)&&(*xpos<180)&&(*ypos>420)&&(*ypos<460))
		{    menu(button, xpos, ypos);   }
		else if((*xpos>240)&&(*xpos<360)&&(*ypos>420)&&(*ypos<460))
		{    
			checkAnswer(button, xpos, ypos);
		}
	}
}



//used to find column to color
int inputx(int *xpos)
{
			if((*xpos>240)&&(*xpos<280))   return 1;
			else if((*xpos>280)&&(*xpos<320))   return 2;
			else if((*xpos>320)&&(*xpos<360))   return 3;
			else if((*xpos>360)&&(*xpos<400))  return 4;
			else if((*xpos>400)&&(*xpos<440))   return 5;
			
}


void main()
{
	 int *xpos, *ypos, *button=0;
	int gd=DETECT, gm;

	initgraph(&gd, &gm ,"C://TC//BGI");
	setbkcolor(6);
	in.x.ax=1;
	int86(51, &in, &out);
	menu(button,xpos,ypos);
	getch();
	cleardevice();
	closegraph();
}




void displayGameOptions(int *button,int *xpos, int *ypos)
{
	cleardevice();
	
	settextstyle(3,0,3);
	outtextxy(300,120,"Game 1");
	settextstyle(3,0,3);
	outtextxy(300,180,"Game 2");
	settextstyle(3,0,3);
	outtextxy(300,240,"Game 3");
	settextstyle(3,0,3);
	outtextxy(300,300,"Game 4");
	settextstyle(3,0,3);
	outtextxy(300,360,"Game 5");	
	
	rectangle(280, 120, 440, 160);
	rectangle(280, 180, 440, 220);
	rectangle(280, 240, 440, 280);
	rectangle(280, 300, 440, 340);
	rectangle(280, 360, 440, 400);
	
	delay(1000);	
	
	z1: do
      {
	detect(button, xpos, ypos);
       }while(*button!=1);

	if((*xpos>=300)&&(*xpos<440))
	{	if((*ypos>=120)&&(*ypos<=160)){
			gameNo=0;
			game(button, xpos, ypos);
		}
		else if((*ypos>=180)&&(*ypos<220)){
			gameNo=1;
			game(button, xpos, ypos);
		}
		else if((*ypos>=240)&&(*ypos<=280)){
			gameNo=2;
			game(button, xpos, ypos);
		}
		
		else if((*ypos>=300)&&(*ypos<=340)){
			gameNo=3;
			game(button, xpos, ypos);
		}
		
		else if((*ypos>=360)&&(*ypos<=400)){
			gameNo=4;
			game(button, xpos, ypos);
		}
		
		
		else goto z1;
	}

	
//	game(button, xpos, ypos);
	
}


//landing screen
void menu(int *button,int *xpos, int *ypos)
{
	cleardevice();
	settextstyle(4,1,6);
	outtextxy(70, 15, "NONOGRAMS");
	settextstyle(3,0,3);
	outtextxy(300,150,"WELCOME...");
	settextstyle(1,0,1);
	rectangle(300, 190, 450, 220); rectangle(300,230,450,260);
	outtextxy(310, 200,"1. New Game");

	outtextxy(300, 240,"2. Exit");
     z: do
      {
	detect(button, xpos, ypos);
       }while(*button!=1);

	if((*xpos>=300)&&(*xpos<450))
	{	if((*ypos>=230)&&(*ypos<=260))
		{      printf("exiting");  delay(300);  cleardevice();  exit(0);}
		else if((*ypos>=190)&&(*ypos<220))
		    displayGameOptions(button, xpos, ypos);

		else goto z;
	}
}
