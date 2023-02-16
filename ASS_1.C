#include<stdio.h>
#include<graphics.h>


void dda(int x1,int y1,int x2,int y2){
// int gd,gm;
float xnew,ynew,m,dx,dy;

// gd=DETECT;
// initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
dx=x2-x1;
dy=y2-y1;
m=dy/dx;
if(m<0){
 m=m*(-1);
}
// printf("%f",m);
//line(150,300,50,100);
if(dx>=dy){
     xnew=x1;
     ynew=y1;
    if(x1>x2 && y1>y2){
	 do{
	    xnew=xnew-1;
	    ynew=ynew-m;
	    // printf("\n x : %d  y : %d\n",(int)(xnew),(int)(ynew+0.5));
	     putpixel((int)(xnew),(int)(ynew+0.5),WHITE);
	    }while((int)(ynew+0.5)!=y2);
	}
    else if(x1>x2){
      do{
	    xnew=xnew-(1/m);
	    ynew=ynew+1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);
    }
    else if(y1>y2){
       do{
	    xnew=xnew+(1/m);
	    ynew=ynew-1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);

    }
    else{
	    do{
	    xnew=xnew+1;
	    ynew=ynew+m;
	    // printf("\n x : %d  y : %d\n",(int)(xnew),(int)(ynew+0.5));
	     putpixel((int)(xnew),(int)(ynew+0.5),WHITE);
	    }while((int)(ynew+0.5)!=y2);
	}
}
else{
    xnew=x1;
    ynew=y1;
    if(x1>x2 && y1>y2){
       do{
	    xnew=xnew-(1/m);
	    ynew=ynew-1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);
    }
    else if(x1>x2){
      do{
	    xnew=xnew-(1/m);
	    ynew=ynew+1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);
    }
    else if(y1>y2){
      do{
	    xnew=xnew+(1/m);
	    ynew=ynew-1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);

    }
    else{
	    do{
	    xnew=xnew+(1/m);
	    ynew=ynew+1;
	    // printf("\n x : %d  y : %d\n",(int)(xnew+0.5),(int)(ynew));
	     putpixel((int)(xnew+0.5),(int)(ynew),WHITE);
	    }while((int)(xnew+0.5)!=x2);

    }
}
// getch();
// closegraph();
}



void bresenham(int x1,int y1,int x2,int y2){
int p,xnew,ynew,dx,dy,temp;

// gd=DETECT;
// initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

if(x1>x2 && y1>y2){
temp=x1;
x1=x2;
x2=temp;

temp=y1;
y1=y2;
y2=temp;
}
dx=x2-x1;
dy=y2-y1;
if(dx<0){
dx=dx*(-1);

}
if(dy<0){
dy=dy*(-1);
}


// printf("%d\n",dx);
// printf("%d\n",dy);

p = (2)*dy-dx;
if(dx==0){
   p=-p;
}
if(dx>=dy){
xnew=x1;
ynew=y1;

do{
if(x1>x2){
    if(p<0){
		putpixel(xnew,ynew,WHITE);
	xnew=xnew-1;
	ynew=ynew;
	p=p+(2)*dy;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
	xnew=xnew-1;
	ynew=ynew+1;
	p=p+(2)*dy-(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));
    }

}
else if(y1>y2){
    if(p<0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew;
		p=p+(2)*dy;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew-1;
		p=p+(2)*dy-(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));
    }
}
else{
    if(p<0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew;
		p=p+(2)*dy;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew+1;
		p=p+(2)*dy-(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));
    }

}
}while(xnew!=x2);

}

else{
xnew=x1;
ynew=y1;
do{
if(x1>x2){
    if(p<0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew;
		ynew=ynew+1;
		p=p+(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew-1;
		ynew=ynew+1;
		p=p+(2)*dx-(2)*dy;
		// printf("\n x : %d  y : %d\n",(xnew),(ynew));
    }

}
else if(y1>y2){
    if(p<0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew;
		ynew=ynew-1;
		p=p+(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew-1;
		p=p+(2)*dx-(2)*dy;
		// printf("\n x : %d  y : %d\n",(xnew),(ynew));
    }

}
else{
    if(p<0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew;
		ynew=ynew+1;
		p=p+(2)*dx;
	// printf("\n x : %d  y : %d\n",(xnew),(ynew));

    }
    else if(p>=0){
		putpixel(xnew,ynew,WHITE);
		xnew=xnew+1;
		ynew=ynew+1;
		p=p+(2)*dx-(2)*dy;
		// printf("\n x : %d  y : %d\n",(xnew),(ynew));
}

}

}while(ynew!=y2);


}
//line(123,345,234,123);
// getch();
// closegraph();
}

void house(){
	dda(170,210,340,105);
	dda(170,210,510,210);
	dda(340,105,510,210);
	bresenham(170,210,170,370);
	bresenham(510,210,510,370);
	bresenham(170,370,510,370);
	bresenham(300,270,380,270);
	bresenham(300,270,300,370);
	bresenham(380,270,380,370);
	bresenham(170,210,510,210);
}
int main(){

    int gm,gd,ch,x1,y1,x2,y2,x=0;
    // gd=DETECT;
    // initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	while(x==0){
          printf("\nChoose algorithm to draw line\n");
          printf("\n1.DDA algorihtm \n");
          printf("\n2.Bresenham algorithm \n");
          printf("\n3.Object \n");
          printf("\n4.Exit \n");
          
          printf("Enter your choice : ");
          scanf("%d",&ch);
			if(ch==1){
				printf("\nEnter coordinates : ");
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				dda(x1,y1,x2,y2);
				getch();
                closegraph();
				// break;
			}
			else if(ch==2){
				printf("\nEnter coordinates : ");
				scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				bresenham(x1,y1,x2,y2);
				getch();
                closegraph();
				
			}
			else if(ch==3){
				gd=DETECT;
				initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
				printf("\nHouse ");
				house();
				getch();
                closegraph();
			
			}
			else{
                x=1;
			}
			   
				

    }

    // dda(123,345,234,123);
    // bresenham(90,100,150,120);
    // bresenham(100,200,100,300);

    // getch();
    // closegraph();
    return 0;

}