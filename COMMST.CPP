#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<stdlib.h>
#include<alloc.h>

void graphics()
{

	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\turboc3\\bgi");

}

struct IMAG
{
      char Type[2];           //File type. Set to "BM".
      unsigned long Size;     //Size in BYTES of the file.
      unsigned long Reserved;      //Reserved. Set to zero.
      unsigned long OffSet;   //Offset to the data.
      unsigned long headsize; //Size of rest of header. Set to 40.
      unsigned long Width;     //Width of bitmap in pixels.
      unsigned long Height;     //  Height of bitmap in pixels.
      unsigned int  BitsPerPixel;       //Number of Bits per pixels.
      unsigned long Compression;   //Compression. Usually set to 0.
      unsigned long SizeImage;   //Size in bytes of the bitmap.
};

void IMAG(int x, int y, char* FileName)
{
	int b,a;
	struct  IMAG Obj;

	unsigned char* Datas;
	int in=0;
	unsigned char c=0;
	FILE * fp;

	fp = fopen(FileName,"r");

	fread(&Obj, sizeof(Obj), 1, fp);

	fseek(fp,Obj.OffSet,SEEK_SET);

	Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));

	for(b=Obj.Height;b>=0;b--)
	{
	 fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);
	 c=0;
	 in=0;

	 for(a=0;a<=Obj.Width;a+=2)
	 {
	     c = (Datas[in] | 0x00) >>4;
	     putpixel(a+x,b+y,c);
	     c = (Datas[in] | 0xF0) & 0x0F;
	     putpixel(a+1+x,b+y,c);
	     in++;
	 }
	}
	free(Datas);
	fclose(fp);
}

void loadD()
{
	int i;
	graphics();  //graphics initialization

		// For program loading
		setcolor(WHITE);

	    for(i=35;i<555;i++)
	    {
		line(25+i,170,25+i,200); //this is for the white bar
	    }

	   for(i=35;i<555;i++)
	    {
		setcolor(GREEN);
		line(25+i,170,25+i,200); //for Green bar which is incressing
		delay(1);               //incress the size

		setcolor(WHITE);
		settextstyle(SMALL_FONT,0,16);
		outtextxy(220,220,"Loading");
		delay(1);

		setcolor(rand()%16);
		settextstyle(SMALL_FONT,HORIZ_DIR,16);
		outtextxy(390,220,"....");
		delay(1);

	}
	cleardevice();
}

class msg
{
public:
	void intro()
	{
	cout<<"Hello, \n";
	cout<<"This game is for entertainment purpose.\n";
	cout<<"Give input as shown in this notes.\n";
	cout<<"Control pannel is for control the game, in Control pannel\n";
	cout<<"(->) this symbol show the input what is given\n";
	cout<<"there are four option's 's' is for start, 'r' is for restart,\n";
	cout<<"and h for help.";
	cout<<"After the start the game, if you want to return\n";
	cout<<"towards control pannel then press 0 and enter.";
	}

	void help()
	{
	cout<<"Hello,\n";
	cout<<"This game is devloped by the 'Pradyumna','Sandeep','Parimal.\n";
	cout<<"In this game,There are two pannel, first pannel is game pannel\n";
	cout<<"second pannel is control pannel, In game pannel the diagram is\n";
	cout<<"shown structure of game";
	}

};

class players
{
	char pl1[20];
	char pl2[20];

public: void player_name()
	{
		cout<<"\t\t<-----Name of player-1:"<<"----->";
		gets(pl1);
		cout<<"\t\t<-----Name of player-2:"<<"----->";
		gets(pl2);
		fflush(stdin);
	 }
	 void pl_name_show()
	 {
		cout<<"\t\t<-----Name of player-1:"<<"----->"<<pl1;
		cout<<"\n\t\t<-----Name of player-2:"<<"----->"<<pl2;
		cout<<"\n";
	 }

};

class structure
{
public:
	void basic_design()
	{
	//Basic structure of game
	 setcolor(BLUE);
	rectangle(15,50,625,450);     //large box 1
	rectangle(415,50,625,450);    //left side box

	//for making box
	line(415,140,625,140);
	line(415,340,625,340);

	//for horizontal lines
	line(165,90,165,390);
	line(265,90,265,390);

	//for vertical lines
	line(65,190,365,190);
	line(65,290,365,290);
	}

	void print_in()
	{
	   // for no
	setcolor(GREEN);
	settextstyle(0,0,0);
	outtextxy(110,340,"1");
	outtextxy(210,340,"2");
	outtextxy(310,340,"3");
	outtextxy(110,240,"4");
	outtextxy(210,240,"5");
	outtextxy(310,240,"6");
	outtextxy(110,140,"7");
	outtextxy(210,140,"8");
	outtextxy(310,140,"9");

	//for control panel's print
	setcolor(WHITE);
	settextstyle(0,0,2);
	outtextxy(430,160,"S-Start ");
	outtextxy(430,200,"R-Restart ");
	outtextxy(430,240,"E-Exit ");
	outtextxy(430,280,"H-Help ");

	}

	void print_in1()
	{
	setcolor(RED);
	settextstyle(0,0,0);

	outtextxy(325,440,"Game pannel");
	outtextxy(512,330,"Control pannel");
	outtextxy(582,130,"Score");
	outtextxy(527,440,"Announcement");
	}

	void print_sc()
	{
	settextstyle(0,0,0);
	setcolor(13);

	outtextxy(430,70, "Score of player-1: ");
	outtextxy(430,100, "Score of Player-2: ");
       }
};

class GAME
{
public:
	static int n1,n2;

	void score_play()
	{
	char str2[10],str3[10];

	settextstyle(0,0,0);
	setcolor(13);

	outtextxy(430,70, "Score of player-1: ");
	outtextxy(430,100, "Score of Player-2: ");

	itoa(n1, str2, 10);
	outtextxy(580,70,str2);
	itoa(n2, str3, 10);
	outtextxy(580,100,str3);

	}


void game_ctr()
{
re:
	char a='0',b='0',c='0',d='0',e='0',f='0',g='0',h='0',i='0',x;
	int y=1,flag=0,ind=0,flag2=0,flag1=0,flagex=0,flag3=0;
	char ch,ch1,i1;

	structure m;
	msg n;

	sre:
	settextstyle(0,0,0);

	 if(ind==0)
	 {
		 setcolor(BLACK);
		 outtextxy(495,330,"->");
		 outtextxy(307,440,"->");
	 }
	 ind=2;

	 if(ind==2)
	 {
		setcolor(RED);
		outtextxy(495,330,"->");
		setcolor(BLACK);
		outtextxy(307,440,"->");
	 }

	fflush(stdin);
	ch1=getch();
	flagex++;

	if(ch1>=97 && ch1<=122)
	{
	ch1=ch1-32;
	}

	switch(ch1)
	{
	case 'S':
	ind=1;

	if(ind==1)
	{
	  setcolor(BLACK);
	  outtextxy(495,330,"->");
	  setcolor(RED);
	  outtextxy(307,440,"->");
	}

	m.basic_design(); //-> //for basic game box function call

	while(y<10)
	{
	setbkcolor(0);
	if(flag2==0 && flag1==0 && flag3==0)
	{
		settextstyle(0,0,2);
		setcolor(BLACK);
		outtextxy(430,390,"Player-2 (!)");
		setcolor(WHITE);
		outtextxy(430,360,"Player-1 (#)");
	}

	if(flag2==1 && flag1==0 && flag3==0)
	{
		settextstyle(0,0,2);
		setcolor(BLACK);
		outtextxy(430,360,"Player-1 (#)");
		setcolor(WHITE);
		outtextxy(430,390,"Player-2 (!)");
	}
	flag1=0;
	flag3=0;

	fflush(stdin);
	ch=getch();
	flagex++;

	if(flagex>(3000*10))
	{
		fflush(stdin);
		exit(0);
	}

if(y%2==0)
{
	flag2=0;
	setcolor(7);
	settextstyle(0,0,7);

	x='!';

	switch(ch)
	{
		case '1' :if(g=='0')
			{
				outtextxy(95,315,"!");
				g=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '2' :if(h=='0')
			{
				outtextxy(195,315,"!");
				h=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '3' :if(i=='0')
			{
				outtextxy(295,315,"!");
				i=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '4' :if(d=='0')
			{
				outtextxy(95,215,"!");
				d=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '5' :if(e=='0')
			{
				outtextxy(195,215,"!");
				e=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '6' :if(f=='0')
			{
				outtextxy(295,215,"!");
				f=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '7' :if(a=='0')
			{
				outtextxy(95,115,"!");
				a=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '8' :if(b=='0')
			{
				outtextxy(195,115,"!");
				b=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '9' :if(c=='0')
			{
				outtextxy(295,115,"!");
				c=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}
	       case '0' :goto sre;

	       default: y--;
			fflush(stdin);
			flag3++;
			break;
	}
}

else

{
	flag2=1;
	settextstyle(0,0,7);
	setcolor(WHITE);
	x='#';

	switch(ch)
	{
		case '1' :if(g=='0')
			{
				outtextxy(95,315,"#");
				g=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '2' :if(h=='0')
			{
				outtextxy(195,315,"#");
				h=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '3' :if(i=='0')
			{
				outtextxy(295,315,"#");
				i=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '4' :if(d=='0')
			{
				outtextxy(95,215,"#");
				d=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '5' :if(e=='0')
			{
				outtextxy(195,215,"#");
				e=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '6' :if(f=='0')
			{
				outtextxy(295,215,"#");
				f=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '7' :if(a=='0')
			{
				outtextxy(95,115,"#");
				a=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '8' :if(b=='0')
			{
				outtextxy(195,115,"#");
				b=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

		case '9' :if(c=='0')
			{
				outtextxy(295,115,"#");
				c=x;
				break;
			}
			else
			{
				y--;
				flag1=1;
				break;
			}

	case '0' :goto sre;

	default: y--;
		fflush(stdin);
		flag3++;
		break;
	}


}

if(flag1==1 || flag3==1)
{
	if(flag2==0)
	{
		settextstyle(0,0,2);
		setcolor(RED);
		outtextxy(418,360,"INVALID INPUT");
		delay(1000);
		setcolor(BLACK);
		outtextxy(418,360,"INVALID INPUT");
	}
	else
	{
		settextstyle(0,0,2);
		setcolor(RED);
		outtextxy(418,390,"INVALID INPUT");
		delay(1000);
		setcolor(BLACK);
		outtextxy(418,390,"INVALID INPUT");
	}
}


if(y>4 && y<10)
{
	 if(a==b && b==c && c=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(a==d && d==g && g=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(a==e && e==i && i=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(d==e && e==f && f=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(g==h && h==i && i=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(b==e && e==h && h=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(c==f && f==i && i=='!')
	  {
		  flag=1;
		  break;
	  }

	  if(g==e && e==c && c=='!')
	  {
		  flag=1;
		  break;
	 }
}

if(y>4 && y<10)
{
	 if(a==b && b==c && c=='#')
	  {
		 flag=2;
		  break;
	  }

	if(a==d && d==g && g=='#')
	  {
		  flag=2;
		  break;
	  }

	if(a==e && e==i && i=='#')
	  {
		  flag=2;
		  break;
	  }

	if(d==e && e==f && f=='#')
	  {
		  flag=2;
		  break;
	  }

	if(g==h && h==i && i=='#')
	  {
		  flag=2;
		  break;
	  }

	if(b==e && e==h && h=='#')
	  {
		  flag=2;
		  break;
	  }

	if(c==f && f==i && i=='#')
	  {
		  flag=2;
		  break;
	  }

	if(g==e && e==c && c=='#')
	  {
		  flag=2;
		  break;
	  }
}

	if(flag==1)
	{
		break;
	}
	if(flag==2)
	{
		break;
	}
		y++;
	}


	if(flag==1)
	{
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(430,390,"Player-2 (!)");

		while(!kbhit())
		{
			setcolor(rand()%16);
			outtextxy(425,360,"Player-2 Win");
			delay(1);
		}
	n2=n2+10;
	setcolor(WHITE);
	}

	if(flag==2)
	{
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(430,360,"Player-1 (#)");

		while(!kbhit())
		{
			setcolor(rand()%16);
			outtextxy(425,390,"Player-1 Win");
			delay(1);
		}
	n1=n1+10;
	setcolor(WHITE);
	}

	if(flag==0)
	{
	settextstyle(0,0,2);
	setcolor(BLACK);
	outtextxy(430,360,"Player-1 (#)");

		while(!kbhit())
		{
		setcolor(rand()%16);
		outtextxy(430,390,"Match Tie");
		delay(1);
		}
	}

	fflush(stdin);
	break;

		case 'R':
			fflush(stdin);
			clrscr();
			cleardevice();

			players p;
			p.player_name();
			clrscr();
			cleardevice();

			m.basic_design();
			m.print_in();
			m.print_in1();
			m.print_sc();
			p.pl_name_show();
			n1=0;n2=0;
			score_play();
			goto re;

		case 'E':exit(0);

		case 'H':clrscr();
			 cleardevice();
			 n.help();
			 getch();
			 break;

		default:fflush(stdin);
			break;
	    }

	}
};

int GAME :: n1=0;
int GAME :: n2=0;

void main()
{
char ch3;
clrscr();
       graphics();

	IMAG(0,0,"IC5.BMP");
	delay(1000);

	loadD();

	players p;
	p.player_name();
	clrscr();
	cleardevice();

	msg n;
	n.intro();
	getch();
	clrscr();
	cleardevice();

	do
	{
	p.pl_name_show();

	structure m;
	m.basic_design(); //-> for basic game box function call
	m.print_in();
	m.print_in1();
	m.print_sc();
	GAME g1;
	g1.score_play();
	g1.game_ctr();

	fflush(stdin);

	cout<<"\n\nDo you want continue press '(y/Y)': ";
	ch3=getche();
	clrscr();
	cleardevice();
	}
	while(ch3=='y' || ch3=='Y');

getch();
closegraph();
}
