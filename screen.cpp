#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
#include<Windows.h>
#define cls setbkcolor(WHITE),cleardevice()
#define BLUE RGB(200,120,0)
#define ORANGE RGB(0,150,200)
#define RED RGB(0,0,200)
#define GREY RGB(150,150,150)
using namespace std;
int screen_x,screen_y;
bool _getch=0,esc=1;
int sound=8;
void mainpage(),ch1(int p),setting();
int main();
void read_setting()
{
	freopen("SFile\\config.ini","r",stdin);
	cin>>sound>>esc;
	freopen("CON","r",stdin);
}
void SetValume(int Valume)
{
	char tmp[100];
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio chuang_wen volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio next_zh volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio next_yue volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio next_en volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio arrive_zh volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio arrive_yue volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio arrive_en volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio sta_zh volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio sta_yue volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio sta_en volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio jdtx volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
	memset(tmp,0,sizeof(tmp));
	sprintf(tmp,"setaudio dcgz volume to %d",Valume);
	mciSendString(tmp,NULL,0,0);
}
void right_up_box(int x)
{
	line(screen_x-x*50,50,screen_x,50);
	for(int i=0;i<x;i++)	line(screen_x-(x-i)*50,0,screen_x-(x-i)*50,50);
}
int Rand(int l,int r)
{
	srand(time(NULL));
	return abs(rand()/rand()-rand()*rand())%(r-l)+l;
}
bool click(int x,int y,int a1,int b1,int a2,int b2)
{
	if(a1<=x&&x<=a2&&b1<=y&&y<=b2)	return 1;
	return 0;
}
string www(char *s)
{
	string ans="";
	for(int i=0;i<strlen(s);i++)	ans+=s[i];
	return ans;
}
int www1(char *c)
{
	int ans=0;
	for(int i=0;i<strlen(c);i++)	ans=ans*10+c[i]-48;
	return ans;
}
void loading(int a,int b)
{
	setcolor(BLUE);
	setfontbkcolor(WHITE);
	setfont(60,24,"微软雅黑");
	int x1=(screen_x-a)/2,x2=(screen_x+a)/2,y1=screen_y/3*2,y2=y1+b;
	outtextxy(x1,y1-60,"请稍等……");
	line(x1,y1,x2,y1);
	line(x1,y2,x2,y2);
	line(x2,y1,x2,y2);
	for(int i=x1;i<=x2;i++)
	{
		line(i,y1,i,y2);
		Sleep(1);
	}
}
void start()
{
	PIMAGE img=newimage();
	getimage(img,"SFile\\writer.png");
	putimage(screen_x/2-100,150,img);
	Sleep(2000);
	cleardevice();
}
struct gzbus{
	int tot[10],d[100],sec[10],cnt=0;
	char stop[10][100][50],name[50],all_name[100],fenzhi[10][50];
	void read(char *path)
	{
		cls;
		setcolor(BLUE);
		setfontbkcolor(WHITE);
		setfont(50,20,"微软雅黑");
		char file_name[100];
		memset(file_name,0,sizeof(file_name));
		sprintf(file_name,"Line\\%s\\main.line",path);
		freopen(file_name,"r",stdin);
		memset(tot,0,sizeof(tot));
		memset(stop,0,sizeof(stop));
		scanf("%s",all_name);
		scanf("%s",name);
		scanf("%d",&cnt);
		for(int i=1;i<=cnt;i++)	scanf("%s",fenzhi[i]);
		for(int i=1;i<=cnt;i++)
		{
			scanf("%d",&tot[i]);
			for(int j=1;j<=tot[i];j++)	scanf("%s",stop[i][j]);
		}
		freopen("CON","r",stdin);
	}
	void szd(int i,int now,int m,int y,int l,int r)
	{
		int t=y;
		setfontbkcolor(WHITE);
		if(i>now)	setcolor(BLUE);
		else if(i<now)	setcolor(GREY);
		else
		{
			setcolor(BLUE);
			setfillcolor(BLUE);
			bar(d[now]-21,75,d[now]+23,screen_y-90);
			setcolor(WHITE);
			setfontbkcolor(BLUE);
		}
		for(int j=0;j<strlen(stop[m][i]);j++)
		{
			char tmp[3];
			memset(tmp,0,sizeof(tmp));
			tmp[0]=stop[m][i][j];
			tmp[1]=stop[m][i][++j];
			if(stop[m][i][j-1]>0)
			{
				j--;
				if(stop[m][i][j]=='(')	outtextxy(d[i]-20,t,"︵");
				else if(stop[m][i][j]==')')	outtextxy(d[i]-20,t,"︶");
				else	outtextxy(d[i]-10,t,stop[m][i][j]);
			}
			else
			{
				if(strcmp(tmp,"（")==0)	outtextxy(d[i]-20,t,"︵");
				else if(strcmp(tmp,"）")==0)	outtextxy(d[i]-20,t,"︶");
				else outtextxy(d[i]-20,t,tmp);
			}
			t+=50;
		}
		setcolor(GREY); 
		setfontbkcolor(WHITE);
		setfillcolor(BLUE);
		bar(0,screen_y-70,screen_x,screen_y);
		setcolor(ORANGE);
		setfontbkcolor(BLUE);
		outtextxy(50,screen_y-60,name);
		setcolor(WHITE);
		outtextxy(50+(strlen(name)+2)*20,screen_y-60,"本车从");
		setcolor(ORANGE);
		outtextxy(50+(strlen(name)+9)*20,screen_y-60,stop[m][l]);
		setcolor(WHITE);
		outtextxy(50+(strlen(name)+10+strlen(stop[m][l]))*20,screen_y-60,"开往");
		setcolor(ORANGE);
		outtextxy(50+(strlen(name)+15+strlen(stop[m][l]))*20,screen_y-60,stop[m][r]);
	}
	void lz(int now,int l,int r,int m)
	{
		cls;
		setfont(50,20,"微软雅黑");
		setfillcolor(GREY);
		bar(75,40,screen_x-75,60);
		for(int i=l;i<=r;i++)
		{
			double kk=(screen_x-150)*1.0/(r-l);
			d[i]=60+(i-l)*kk;
			szd(i,now,m,75,l,r);
			if(now<=i)	setfillcolor(BLUE),setcolor(BLUE);
			else	setfillcolor(GREY),setcolor(GREY);
			fillellipse(d[i],50,20,20);
		}
		if(now==0)	return;
		char length[100];
		mciSendString("play chuang_wen",NULL,0,NULL);
		char tmp[200];
		int w=Rand(1,3);
		for(int k=1;;k++)
		{
			if(k%100==1)
			{
				setcolor(RED);
				setfillcolor(RED);
				fillellipse(d[now],50,20,20);
			}
			if(k%50==1&&k%100!=1)
			{
				setcolor(GREY);
				setfillcolor(GREY);
				fillellipse(d[now],50,20,20);
			}
			if(k==sec[1])
			{
				mciSendString("close chuang_wen",NULL,0,NULL);
				mciSendString("play next_zh",NULL,0,NULL);
			}
			if(k==sec[2])
			{
				mciSendString("close next_zh",NULL,0,NULL);
				mciSendString("play sta_zh",NULL,0,NULL);
			}
			if(k==sec[3])
			{
				mciSendString("close sta_zh",NULL,0,NULL);
				mciSendString("play next_yue",NULL,0,NULL);
			}
			if(k==sec[4])
			{
				mciSendString("close next_yue",NULL,0,NULL);
				mciSendString("play sta_yue",NULL,0,NULL);
			}
			if(k==sec[5])
			{
				mciSendString("close sta_yue",NULL,0,NULL);
				mciSendString("play next_en",NULL,0,NULL);
			}
			if(k==sec[6])
			{
				mciSendString("close next_en",NULL,0,NULL);
				mciSendString("play sta_en",NULL,0,NULL);
			}
			if(k==sec[7])
			{
				mciSendString("close sta_en",NULL,0,NULL);
				if(w!=1)	break;
				mciSendString("play jdtx",NULL,0,NULL);
			}
			if(k==sec[8])
			{
				mciSendString("close jdtx",NULL,0,NULL);
				break;
			}		
			Sleep(10);
		}
	}
	void dz(int x,int l,int r,int m)
	{
		cls;
		mciSendString("play sta_zh",NULL,0,NULL);
		int x1=50,x2=screen_x-50-(strlen(stop[m][x+1])+6)*55,x3=x1,x4=x2,x5=screen_x-50-(strlen(stop[m][x])+4)*55,x6=50;
		int w=Rand(1,3);
		setfillcolor(BLUE);
		bar(0,screen_y-70,screen_x,screen_y);
		for(int k=1;;k++)
		{
			cls;
			int yy=screen_y-70;
			setfontbkcolor(BLUE);
			setfillcolor(BLUE);
			bar(0,yy,screen_x,screen_y);
			setfont(50,20,"微软雅黑");
			setcolor(ORANGE);
			outtextxy(50,yy+10,name);
			setcolor(WHITE);
			outtextxy(50+(strlen(name)+2)*20,screen_y-60,"本车从");
			setcolor(ORANGE);
			outtextxy(50+(strlen(name)+9)*20,screen_y-60,stop[m][l]);
			setcolor(WHITE);
			outtextxy(50+(strlen(name)+10+strlen(stop[m][l]))*20,screen_y-60,"开往");
			setcolor(ORANGE);
			outtextxy(50+(strlen(name)+15+strlen(stop[m][l]))*20,screen_y-60,stop[m][r]);
			setfontbkcolor(WHITE);
			setcolor(BLUE);
			setfont(120,48,"微软雅黑");
			outtextxy(x3,yy/6,stop[m][x]);
			setcolor(ORANGE);
			outtextxy(x3+(strlen(stop[m][x]))*55,yy/6,"到了");
			if(x<r)
			{
				outtextxy(x4,yy/6*5-120,"下一站");
				setcolor(BLUE);
				outtextxy(x4+6*55,yy/6*5-120,stop[m][x+1]);
			}
			if(k==sec[1])
			{
				mciSendString("close sta_zh",NULL,0,NULL);
				mciSendString("play arrive_zh",NULL,0,NULL);
			}
			if(k==sec[2])
			{
				mciSendString("close arrive_zh",NULL,0,NULL);
				mciSendString("play sta_yue",NULL,0,NULL);
			}
			if(k==sec[3])
			{
				mciSendString("close sta_yue",NULL,0,NULL);
				mciSendString("play arrive_yue",NULL,0,NULL);
			}
			if(k==sec[4])
			{
				mciSendString("close arrive_yue",NULL,0,NULL);
				mciSendString("play arrive_en",NULL,0,NULL);
			}
			if(k==sec[5])
			{
				mciSendString("close arrive_en",NULL,0,NULL);
				mciSendString("play sta_en",NULL,0,NULL);
			}
			if(k==sec[6])
			{
				mciSendString("close sta_en",NULL,0,NULL);
				if(w!=1)	break;
				mciSendString("play dcgz",NULL,0,NULL);
			}
			if(k>=sec[7])
			{
				mciSendString("close dcgz",NULL,0,NULL);
				break;
			}
			Sleep(10);
			if(k<500)	continue;
			if(k%1000>=500)
			{
				if(x4<x6)	x4+=10;
				if(x3>x5)	x3-=10;
			}
			else
			{
				if(x3<x1)	x3+=10;
				if(x4>x2)	x4-=10;
			}
		}
	}
	void sx(int l,int r,int m)
	{
		cls;
		setcolor(GREY);
		int x1=Rand(0,screen_x),y1=Rand(0,screen_y),x2=Rand(0,screen_x),y2=Rand(0,screen_y);
		outtextxy(x1,y1,"催逝员2.0");
		outtextxy(x2,y2,"cuishiyuan2.0");
		read_setting();
		outtextxy((screen_x-400)/2,screen_y/3*2-50,"加载中...");
		loading(400,30);
		lz(0,l,r,m);
		Sleep(3000);
		for(int i=l+1;i<=r;i++)
		{
			memset(sec,0,sizeof(sec));
			mciSendString("open Patterns\\gzbus\\sounds\\chuang_wen.mp3 alias chuang_wen",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\next_zh.mp3 alias next_zh",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\next_yue.mp3 alias next_yue",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\next_en.mp3 alias next_en",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\dcgz.mp3 alias dcgz",NULL,0,NULL);
			char tmp[105];
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_zh.mp3 alias sta_zh",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_en.mp3 alias sta_en",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_yue.mp3 alias sta_yue",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\arrive_zh.mp3 alias arrive_zh",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\arrive_yue.mp3 alias arrive_yue",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\arrive_en.mp3 alias arrive_en",NULL,0,NULL);
			mciSendString("open Patterns\\gzbus\\sounds\\jdtx.mp3 alias jdtx",NULL,0,NULL);
			mciSendString("status chuang_wen length",tmp,100,NULL);
			sec[1]=www1(tmp)/18;
			mciSendString("status next_zh length",tmp,100,NULL);
			sec[2]=sec[1]+www1(tmp)/18;
			mciSendString("status sta_zh length",tmp,100,NULL);
			sec[3]=sec[2]+www1(tmp)/15;
			mciSendString("status next_yue length",tmp,100,NULL);
			sec[4]=sec[3]+www1(tmp)/18;
			mciSendString("status sta_yue length",tmp,100,NULL);
			sec[5]=sec[4]+www1(tmp)/15;
			mciSendString("status next_en length",tmp,100,NULL);
			sec[6]=sec[5]+www1(tmp)/18;
			mciSendString("status sta_en length",tmp,100,NULL);
			sec[7]=sec[6]+www1(tmp)/15;
			mciSendString("status jdtx length",tmp,100,NULL);
			sec[8]=sec[7]+www1(tmp)/20;
			SetValume(sound*100);
			lz(i,l,r,m);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_zh.mp3 alias sta_zh",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_en.mp3 alias sta_en",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_yue.mp3 alias sta_yue",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			mciSendString("status sta_zh length",tmp,100,NULL);
			sec[1]=www1(tmp)/15;
			mciSendString("status arrive_zh length",tmp,100,NULL);
			sec[2]=sec[1]+www1(tmp)/18;
			mciSendString("status sta_yue length",tmp,100,NULL);
			sec[3]=sec[2]+www1(tmp)/15;
			mciSendString("status arrive_yue length",tmp,100,NULL);
			sec[4]=sec[3]+www1(tmp)/18;
			mciSendString("status arrive_en length",tmp,100,NULL);
			sec[5]=sec[4]+www1(tmp)/18;
			mciSendString("status sta_en length",tmp,100,NULL);
			sec[6]=sec[5]+www1(tmp)/15;
			mciSendString("status dcgz length",tmp,100,NULL);
			sec[7]=sec[6]+www1(tmp)/20;
			SetValume(sound*100);
			dz(i,l,r,m);
		}
	}
	void motify(int m,int p)
	{
		cls;
		setcolor(BLUE);
		setfont(60,24,"微软雅黑");
		setfontbkcolor(WHITE);
		outtextxy(20,20,"全称：");
		outtextxy(440+strlen(all_name)*20,20,"简称：");
		int ln=(screen_y-180)/50,xx=screen_x/3*2;
		setfont(50,20,"微软雅黑");
		outtextxy(160,25,all_name);
		outtextxy(580+strlen(all_name)*20,25,name);
		for(int i=(p-1)*ln+1;i<=min(tot[m],p*ln);i++)
		{
			setcolor(BLACK);
			setfontbkcolor(WHITE);
			int j=i%ln;
			if(j==0)	j=ln;
			outtextxy(50,100+(j-1)*50,stop[m][i]);
			setcolor(WHITE);
			char tmp[110];
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_zh.mp3 alias sta_zh",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			mciSendString("status sta_zh length",tmp,105,NULL);
			if(www1(tmp)<=0)	setfontbkcolor(RED);
			else	setfontbkcolor(GREEN);
			outtextxy(70+strlen(stop[m][i])*20,100+(j-1)*50,"zh");
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_yue.mp3 alias sta_yue",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			mciSendString("status sta_yue length",tmp,105,NULL);
			if(www1(tmp)<=0)	setfontbkcolor(RED);
			else	setfontbkcolor(GREEN);
			outtextxy(125+strlen(stop[m][i])*20,100+(j-1)*50,"yue");
			memset(tmp,0,sizeof(tmp));
			sprintf(tmp,"open Line\\%s\\%s_en.mp3 alias sta_en",all_name,stop[m][i]);
			mciSendString(tmp,NULL,0,NULL);
			mciSendString("status sta_en length",tmp,105,NULL);
			if(www1(tmp)<=0)	setfontbkcolor(RED);
			else	setfontbkcolor(GREEN);
			outtextxy(205+strlen(stop[m][i])*20,100+(j-1)*50,"en");
		}
		PIMAGE img=newimage();
		if(p>1)
		{
			getimage(img,"SFile\\back.jpg");
			putimage(20,screen_y-65,img);
		}
		if(p<ceil(tot[m]*1.0/ln))
		{
			getimage(img,"SFile\\next.jpg");
			putimage(xx-70,screen_y-65,img);
		}
		setfont(40,16,"微软雅黑");
		setcolor(GREY);
		setfontbkcolor(WHITE);
		char wz[105];
		sprintf(wz,"第%2d页，共%2d页",p,ceil(tot[m]*1.0/ln));
		outtextxy(screen_x/3-112,screen_y-60,wz);
		setfillcolor(GREY);
		bar(xx,90,screen_x,screen_y);
		setfont(50,20,"微软雅黑");
		setcolor(BLACK);
		setfontbkcolor(WHITE);
		outtextxy(xx+20,100,"切换分支");
		outtextxy(xx+20,160,"新建分支");
		outtextxy(xx+20,220,"删除分支");
		outtextxy(xx+20,280,"增加站点");
		outtextxy(xx+20,340,"重命名站点");
		outtextxy(xx+20,400,"移动站点");
		outtextxy(xx+20,460,"对调站点");
		outtextxy(xx+20,520,"删除站点");
		getimage(img,"SFile\\save.jpg");
		putimage(screen_x-50*2,0,img);
		getimage(img,"SFile\\exit.jpg");
		putimage(screen_x-50,0,img);
		right_up_box(2);
		int x,y;
		while(1)
		{
			mouse_msg msg=getmouse();
			if(msg.is_left())
			{
				if(msg.is_down())	x=msg.x,y=msg.y;
				else
				{
					if(click(x,y,screen_x-2*50,0,screen_x-51,50))
					{
//						save();
						motify(m,p);
						return;
					}
					if(click(x,y,screen_x-50,0,screen_x-1,50))
					{
						return;
					}
					if(click(x,y,20,screen_y-65,70,screen_y-15)&&p>1)
					{
						motify(m,p-1);
						return;
					}
					if(click(x,y,xx-70,screen_y-65,xx-20,screen_y-15)&&p<ceil(tot[m]*1.0/ln))
					{
						motify(m,p+1);
						return;
					}
				}
			}
		}
	} 
};
void main1()
{
	cls;
	setfont(150,60,"微软雅黑");
	setcolor(BLUE);
	setfontbkcolor(WHITE); 
	outtextxy((screen_x-strlen("cbz报站系统")*70)/2,100,"cbz报站系统");
	setfont(60,24,"微软雅黑");
	PIMAGE img=newimage();
	getimage(img,"SFile\\start.png");
	putimage(screen_x-630,screen_y-380,img);
	getimage(img,"SFile\\setting.jpg");
	putimage(screen_x-100,0,img); 
	getimage(img,"SFile\\exit.jpg");
	putimage(screen_x-50,0,img); 
	right_up_box(2);
	int x,y;
	while(1)
	{
		mouse_msg msg=getmouse();
		if(msg.is_left())
		{
			if(msg.is_down())	x=msg.x,y=msg.y;
			else
			{
				if(click(x,y,screen_x-630,screen_y-420,screen_x,screen_y))
				{
					ch1(1);
					return;
				}
				if(click(x,y,screen_x-2*50,0,screen_x-51,50))
				{
					setting();
					main1();
					return;
				}
				if(click(x,y,screen_x-50,0,screen_x-1,50))
				{
					exit(0);
				}
			}
		}
	}
}
void ch1(int p)
{
	cls;
	int x,y,cnt=0;
	gzbus a;
	PIMAGE img=newimage();
	getimage(img,"SFile\\search.png");
	putimage(screen_x-200,0,img);
	getimage(img,"SFile\\setting.jpg");
	putimage(screen_x-150,0,img);
	getimage(img,"SFile\\back.jpg");
	putimage(screen_x-100,0,img); 
	getimage(img,"SFile\\home.jpg");
	putimage(screen_x-50,0,img);
	setfont(60,24,"微软雅黑");
	setcolor(BLUE);
	right_up_box(4);
	outtextxy(50,50,"请选择路线：");
	line(50,120,screen_x-50,120);
	freopen("SFile\\lines.txt","r",stdin);
	char name[15][50];
	while(1)
	{
		scanf("%s",name[++cnt]);
		if(strcmp(name[cnt],"AKIOI")==0)
		{
			cnt--;
			break;
		}
	}
	freopen("CON","r",stdin); 
	setfont(40,16,"微软雅黑");
	for(int i=1;i<=cnt;i++)
	{
		setcolor(BLUE);
		line(50,120+i*50,screen_x-50,120+i*50);
		line(50,120+(i-1)*50,50,120+i*50);
		line(screen_x-50,120+(i-1)*50,screen_x-50,120+i*50);
		setcolor(BLACK);
		setfontbkcolor(WHITE);
		outtextxy(60,120+(i-1)*50+5,name[i]);
	}
	bool b=0;
	while(1)
	{
		mouse_msg msg=getmouse();
		if(msg.is_left())
		{
			if(msg.is_down())	x=msg.x,y=msg.y;
			else
			{
				if(click(x,y,screen_x-4*50,0,screen_x-50*3-1,50))
				{
					char tmp[105],tmp2[205];
					inputbox_getline("cbz报站系统","请输入你想找的线路全称，注意是全称！\n如停止搜索请输入End",tmp,sizeof(tmp));
					while(1)
					{
						if(strcmp(tmp,"End")==0)
						{
							ch1(1);
							return;
						}
						int i;
						for(i=1;i<=cnt;i++)	if(strcmp(tmp,name[i])==0)	break;
						sprintf(tmp2,"未找到“%s”！\n请重新输入！\n如停止搜索请输入End",tmp);
						if(i<=cnt)	break;
						else	inputbox_getline("cbz报站系统",tmp2,tmp,sizeof(tmp));
					}
					a.read(tmp); 
					b=1;
					break;
				}
				if(click(x,y,screen_x-3*50,0,screen_x-50*2-1,50))
				{
					setting();
					ch1(1);
					return;
				}
				if(click(x,y,screen_x-2*50,0,screen_x-51,50))
				{
					main1();
					return;
				}
				if(click(x,y,screen_x-50,0,screen_x,50))
				{
					main1();
					return;
				}
				for(int i=1;i<=cnt;i++) 
					if(click(x,y,50,120+(i-1)*50,screen_x-50,120+i*50))
					{
						a.read(name[i]);
						b=1;
						break;
					}
				if(b==1)	break;
			}
		}
	}
	ch1_1:
	cls;
	getimage(img,"SFile\\setting.jpg");
	putimage(screen_x-150,0,img);
	getimage(img,"SFile\\back.jpg");
	putimage(screen_x-100,0,img); 
	getimage(img,"SFile\\home.jpg");
	putimage(screen_x-50,0,img);
	setcolor(BLUE);
	setfont(60,24,"微软雅黑");
	outtextxy(50,50,"请选择分支：");
	right_up_box(3);
	setfont(40,16,"微软雅黑");
	line(50,120,screen_x-50,120);
	for(int i=1;i<=a.cnt;i++)
	{
		setcolor(BLUE);
		line(50,120+i*50,screen_x-50,120+i*50);
		line(50,120+(i-1)*50,50,120+i*50);
		line(screen_x-50,120+(i-1)*50,screen_x-50,120+i*50);
		setcolor(BLACK);
		setfontbkcolor(WHITE);
		outtextxy(60,120+(i-1)*50+5,a.fenzhi[i]);
	}
	int m;
	while(1)
	{
		mouse_msg msg=getmouse();
		if(msg.is_left())
		{
			if(msg.is_down())	x=msg.x,y=msg.y;
			else
			{
				if(click(x,y,screen_x-3*50,0,screen_x-50*2-1,50))
				{
					setting();
					goto ch1_1;
				}
				if(click(x,y,screen_x-2*50,0,screen_x-51,50))
				{
					ch1(1);
					return;
				}
				if(click(x,y,screen_x-50,0,screen_x,50))
				{
					main1();
					return;
				}
				for(int i=1;i<=a.cnt;i++) 
					if(click(x,y,50,120+(i-1)*50,screen_x-50,120+i*50))
					{
						m=i;
						b=0;
						break;
					}
			}
			if(b==0)	break;
		}
	}
	cls;
	
	a.sx(1,a.tot[m],m);
	main1(); 
}
void out_setting()
{
	freopen("SFile\\config.ini","w",stdout);
	cout<<sound<<" "<<esc<<endl;
	freopen("CON","w",stdout);
} 
void setting()
{
	cls;
	setcolor(BLUE);
	setfont(60,24,"微软雅黑");
	outtextxy(50,50,"设置");
	PIMAGE img=newimage();
	getimage(img,"SFile\\back.jpg");
	putimage(screen_x-100,0,img);
	getimage(img,"SFile\\home.jpg");
	putimage(screen_x-50,0,img);  
	right_up_box(2);
	freopen("SFile\\config.ini","r",stdin);
	cin>>sound>>esc;
	freopen("CON","r",stdin);
	setfont(50,20,"微软雅黑");
	for(int i=1;i<=10;i++)
	{
		if(i<=sound)	setfillcolor(BLUE);
		else setfillcolor(GREY);
		bar(150+(i-1)*80,130,150+i*80,165);
	}
	outtextxy(970,120,"+ -");
	line(400,185,400,225); 
	line(450,185,450,225); 
	line(400,185,450,185); 
	line(400,225,450,225);
	if(esc)	setfillcolor(BLUE),bar(405,190,445,220); 
	setcolor(BLACK);
	outtextxy(50,120,"音量");
	outtextxy(50,180,"是否开启全屏模式");
	bool b=0;
	int x,y;
	while(1)
	{
		mouse_msg msg=getmouse();
		if(msg.is_left())
		{
			if(msg.is_down())	x=msg.x,y=msg.y;
			else
			{
				if(click(x,y,961,120,1000,170)&&sound<10)	
				{
					sound++;
					out_setting();
					setting();
					return;
				}
				if(click(x,y,1001,120,1040,170)&&sound>0)
				{
					sound--;
					out_setting();
					setting();
					return;
				}
				if(click(x,y,screen_x-2*50,0,screen_x-51,50))
				{
					out_setting();
					return;
				} 
				if(click(x,y,screen_x-50,0,screen_x,50))
				{
					out_setting();
					main1();
					return;
				}
				if(click(x,y,405,190,445,220))
				{
					esc=1-esc;
					out_setting();
					closegraph(); 
					if(esc)	screen_y=GetSystemMetrics(SM_CYSCREEN),screen_x=GetSystemMetrics(SM_CXSCREEN),initgraph(screen_x,screen_y,1);
					else	screen_x=1120,screen_y=640,initgraph(screen_x,screen_y,0);
					setting();
					return;
				}
			}
			if(b==1)	break;
		}
	}
}
void debug()
{
	gzbus a;
	a.read("广州公交B17路");
	a.motify(2,1);
}
int main()
{
	cout<<"此黑框请勿关闭";
	read_setting();
	if(esc)	screen_y=GetSystemMetrics(SM_CYSCREEN),screen_x=GetSystemMetrics(SM_CXSCREEN),initgraph(screen_x,screen_y,1);
	else	screen_x=1120,screen_y=640,initgraph(screen_x,screen_y,0);
	start();
//	debug();
	main1();
	closegraph();
}
