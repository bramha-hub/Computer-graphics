#include<stdio.h>
#include<graphics.h>

void bresenham(int xc,int yc,int r){
int gm,gd,p,x,y;
//gd=DETECT;
//initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=0;
y=r;
p=3-2*r;
do{
   if(p<=0){
       x=x+1;
       display(xc,yc,x,y);
     // putpixel(x0+x,y0+r,WHITE);
       p=p+(4*x)+6;
       }
   else {
	x=x+1;
	y=y-1;
	display(xc,yc,x,y);
       //putpixel(x0+x,y0+r,WHITE);
	p=p+4*(x-y)+10;
	}
  }while(x<=y);
//getch();
//closegraph();
}

void midpoint(int xc,int yc,int r){
int gm,gd,p,x,y;
//gd=DETECT;
//initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=0;
y=r;
p=1-r;
do{
   if(p<=0){
       x=x+1;
       display(xc,yc,x,y);
       p=p+(2*x)+3;
       }
   else {
	x=x+1;
	y=y-1;
	display(xc,yc,x,y);
	p=p+2*(x-y)+5;
	}
  }while(x<=y);
//getch();
//closegraph();
}


int display(int xc,int yc ,int x,int y){
putpixel(xc+x,yc+y,WHITE);
putpixel(xc-x,yc-y,WHITE);
putpixel(xc-x,yc+y,WHITE);
putpixel(xc+x,yc-y,WHITE);
putpixel(xc+y,yc+x,WHITE);
putpixel(xc-y,yc-x,WHITE);
putpixel(xc-y,yc+x,WHITE);
putpixel(xc+y,yc-x,WHITE);
//putpixel(xc+x,yc-y,WHITE);
//putpixel(xc+x,yc-y,WHITE);
//putpixel(xc+x,yc-y,WHITE);
}

void object(){
  bresenham(200,200,70);
  midpoint(270,200,70);
  bresenham(235,270,70);
}


int main(){
   int gm,gd,ch,x,y,r,wx=0;

  while(wx==0){
	  printf("\nChoose algorithm to draw circle\n");
	  printf("\n1.Midpoint algorihtm \n");
	  printf("\n2.Bresenham algorithm \n");
	  printf("\n3.Object \n");
	  printf("\n4.Exit \n");

	  printf("Enter your choice : ");
	  scanf("%d",&ch);
			if(ch==1){
				printf("\nEnter coordinates : ");
				scanf("%d %d %d",&x,&y,&r);
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				midpoint(x,y,r);
				getch();
				closegraph();
			       // break;
			}
			else if(ch==2){
				printf("\nEnter coordinates : ");
				scanf("%d %d %d",&x,&y,&r);
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				bresenham(x,y,r);
				getch();
				closegraph();

			}
			else if(ch==3){
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				printf("\nCircle object ");
				object();
				getch();
				closegraph();

			}
			else{
				wx=1;
			}



    }

// bresenham(300,200,50);
// midpoint(100,300,100);
}
