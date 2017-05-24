/*
VTU MINI PROJECT - "SIMULATION OF ACTIVE MACHINE LEARNING ALGORITHM & ITS GRAPHICAL REPRESENTATION USING OPEN GL" 
AUTHOR: GANESH PRASAD K G, VI-A, CSE, DBIT
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<signal.h>
#include<math.h>
#include<GL/glut.h>
#include<string.h>
#include<time.h>

static volatile int keepRunning = 1;

int sub_menu1;
int sub_menu2;
int sub_menu3;
int sub_menu4;

float theta1=1;
int flag=-1;
char record[35];

struct logger
{
	const char *emotion;
	int count;
	char *time[4480];
    int index;
};

struct logger h = {"Happy",0,""};
struct logger e = {"Excited",0,""};
struct logger t = {"Tender",0,""};
struct logger s = {"Scared",0,""};
struct logger a = {"Angry",0,""};
struct logger d = {"Sad",0,""};

void intHandler(int dummy) {
	system("clear");
	logger_display(h);
	logger_display(e);
	logger_display(t);
	logger_display(s);
	logger_display(a);
	logger_display(d);
    keepRunning = 0;
}

void logger_display(struct logger e)
{
    int i;
    
    printf("\n\n::LOGGER REPORT::");
    printf("\nEmotion type  : ");
    
    puts(e.emotion);
    
    printf("Emotion count : %d\n",e.count);
}

struct logger logr(struct logger a)
{
    int i;
    char s[25];
    a.count++;
    
    const time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(s, sizeof(s), "%c", tm);
    a.time[a.index++]=s; 
    
    printf("\n::LOGGER::\n");
    printf("\n\"%s\" recorded: ",a.emotion);
    
    for(i=0;i<a.index;i++)
    {
        if(i==a.index-1)
            printf("%s\n",a.time[i]);
    }
    
    return a;
}

void idlefunc()
{	
	printf("\nRECORDER:> ");
	gets(record);
	printf("\nYou said: ");
	puts(record);
	pre_process(record);
	emotions(record);		
	glFlush();
	glutPostRedisplay();
}

void mytimer(int v)
{
	idlefunc();
	glutTimerFunc(100,mytimer,60);
	glutPostRedisplay();
}

void circle(int x,int y,int a,int b,int c)
{
	float rtheta,theta,r=150;
    glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(a,b,c);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
	}
	glEnd();
}

void rightoletter(int x,int y)
{
	GLfloat thr,x1,x2,y1,y2;
	int i;
	glColor3f(1,0,0);
	glBegin(GL_QUAD_STRIP);
	for(i=0;i<=196;i++)
	{
		thr=3.142*i/6.0;
		x1=5*cos(thr);
		y1=5*sin(thr);
		x2=10*cos(thr);
		y2=10*sin(thr);
		glVertex3f(x1+x+45,y1+y+45,0);
		glVertex3f(x2+x+45,y2+y+45,0);
	}
	glEnd();
}

void leftoletter(int x,int y)
{
	GLfloat thr,x1,x2,y1,y2;
	int i;
	glColor3f(1,0,0);
	glBegin(GL_QUAD_STRIP);
	for(i=0;i<=196;i++)
	{
		thr=3.142*i/6;
		x1=5*cos(thr);
		y1=5*sin(thr);
		x2=10*cos(thr);
		y2=10*sin(thr);
		glVertex3f(x1+x-45,y1+y+45,0);
		glVertex3f(x2+x-45,y2+y+45,0);
	}
	glEnd();
}

void smile(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
	glBegin(GL_POINTS);
    for(theta=225;theta<315;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	}while(r<92);
}

void sad(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
	glBegin(GL_POINTS);
    for(theta=45;theta<135;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y-150+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	}while(r<92);
}

void scary(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
    for(theta=45;theta<135;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		glVertex3f(x+r*cos(135*3.142/180),y-150+r*sin(135*3.142/180),0);
		glVertex3f(x+r*cos(45*3.142/180),y-150+r*sin(45*3.142/180),0);
		glVertex3f(x+r*cos(rtheta),y-150+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	y--;
	}while(y>-15);
}

void angry(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
    for(theta=45;theta<135;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		glVertex3f(x+r*cos(45*3.142/180),y-30+r*-sin(45*3.142/180),0);
		glVertex3f(x+r*cos(135*3.142/180),y-30+r*-sin(135*3.142/180),0);
		glVertex3f(x+r*cos(rtheta),y-100+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.5;
	y--;
	}while(y>-15);
}

void surprise(int x,int y)
{
	float rtheta,theta,r=1;
	do
	{
    glBegin(GL_POLYGON);
	for(theta=0;theta<360;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glVertex3f(x+r*cos(rtheta),y-84+r*sin(rtheta),0);
	}
	glEnd();
	r=r+0.05;
	}while(r<24);
}

void laugh(int x,int y)
{
	float rtheta,theta,r=90;
	do
	{
    for(theta=225;theta<315;theta++)
	{
		rtheta=theta*3.142/180;
		glColor3f(0,0,0);
		glBegin(GL_POLYGON);
		glVertex3f(x+r*cos(rtheta),y+r*sin(rtheta),0);
		glVertex3f(x+r*cos(225*3.142/180),y+r*sin(225*3.142/180),0);
		glVertex3f(x+r*cos(315*3.142/180),y+r*sin(315*3.142/180),0);
		glEnd();
	}
	y--;
	}while(y>-15);
}

void sample(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		smile(0,0);
		glFlush();
}

void sample1(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		sad(0,0);
		glFlush();
}

void sample2(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		surprise(0,0);
		glFlush();
}

void sample3(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		laugh(0,0);
		glFlush();
}

void sample4(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		scary(0,0);
		glFlush();
}

void sample5(int a,int b,int c)
{
		circle(0,0,a,b,c);
		rightoletter(0,0);
        leftoletter(0,0);
		angry(0,0);
		glFlush();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-250,250,-250,250,-250,250);
    glMatrixMode(GL_MODELVIEW);
	glClearColor(0,0,0,0);
}

void pre_process(char *record)
{
	int i;
	for(i = 0;i<strlen(record); i++)
	{
		record[i] = tolower(record[i]);
	}
}

void reaction(char status)
{
	switch(status)
	{
		case 'h' : printf("\nREACTOR:> I KNOW YOU ARE FEELING HAPPY!\n");h = logr(h);flag=0;break;
		case 'e' : printf("\nREACTOR:> I KNOW YOU ARE FEELING EXCITED!\n");e = logr(e);flag=1;break;
		case 't' : printf("\nREACTOR:> I KNOW YOU ARE FEELING TENDER!\n");t = logr(t);flag=2;break;
		case 's' : printf("\nREACTOR:> I KNOW YOU ARE FEELING SCARED!\n");s = logr(s);flag=3;break;
		case 'a' : printf("\nREACTOR:> I KNOW YOU ARE FEELING ANGRY!\n");a = logr(a);flag=4;break;
		case 'd' : printf("\nREACTOR:> I KNOW YOU ARE FEELING SAD!\n");d = logr(d);flag=5;break;
		default  : printf("\nREACTOR:> I DUNNO!!!");
	}
	glutPostRedisplay();
}

void emotions(char* record)
{
	int i,j,k;
	char status;
	
	//DICTIONARY
	if((strstr(record,"happy")!=NULL)||(strstr(record,"good")!=NULL)||(strstr(record,"satisfied")!=NULL))
	{
		status='h';
		reaction(status);
	}
	
	if((strstr(record,"excited")!=NULL)||(strstr(record,"persky")!=NULL)||(strstr(record,"aroused")!=NULL))
	{
			status='e';
			reaction(status);
	}
	
	if((strstr(record,"ok")!=NULL)||(strstr(record,"fine")!=NULL)||(strstr(record,"kind")!=NULL))
	{
		status='t';
		reaction(status);
	}
	
	if((strstr(record,"scare")!=NULL)||(strstr(record,"terrified")!=NULL)||(strstr(record,"fright")!=NULL))
	{
		status='s';
		reaction(status);
	}
	
	if((strstr(record,"irritate")!=NULL)||(strstr(record,"upset")!=NULL)||(strstr(record,"angry")!=NULL))
	{
		status='a';
		reaction(status);
	}
	
	if((strstr(record,"hate")!=NULL)||(strstr(record,"sad")!=NULL)||(strstr(record,"depressed")!=NULL))
	{
			status='d';
			reaction(status);
	}

}

void display()
{
	int i;
	
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glRotatef(0,0,0,0);
	char s1[]="EMOTION RECORDER";
	char s2[]=" REACTOR WINDOW ";
	glColor3f(1,1,1);
	glRasterPos2i(-50,200);
	for(i=0;i<strlen(s1);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s1[i]);
	glRasterPos2i(-50,180);
	for(i=0;i<strlen(s2);i++)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13,s2[i]);
	glLoadIdentity();
	
	glRotatef(theta1,0,1,0);
	if(flag==0)
	{
		sample3(1,1,1);
	}
	if(flag==1)
	{
		sample2(1,1,1);
	}
	if(flag==2)
	{
		sample(1,1,1);
	}
	if(flag==3)
	{
		sample4(1,1,1);
	}
	if(flag==4)
	{
		sample5(1,1,1);
	}
	if(flag==5)
	{
		sample1(1,1,1);
	}
	
	glFlush();
	glutSwapBuffers();
}

int main(int argc,char**argv)
{
	signal(SIGINT, intHandler);
	
	while(keepRunning)
	{
		printf("~~~ACTIVE DIALOG~~~");
		printf("\nPRESS CTRL+Z TO EXIT");
		printf("\nPRESS CTRL+C TO OBTIAN LOG REPORT");
		
		glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
		glutInitWindowPosition(100,100);
		glutInitWindowSize(500,500);
		glutInit(&argc,argv);
		glutCreateWindow("EVENT RECORDER FOR ACTIVE MACHINE LEARNING ALGORITHM");
		myinit();
		glutDisplayFunc(display);
		glutIdleFunc(idlefunc);
		glEnable(GL_DEPTH_TEST);
		glutMainLoop();
		
		logger_display(h);
		logger_display(e);
		logger_display(t);
		logger_display(s);
		logger_display(a);
		logger_display(d);
		
		return 0;
	}
}