#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define left -10000
using namespace std;

struct POS{
	int x,y;
	POS *next;
};

int crossMul(POS* p1,POS* p2);
bool checkCross(POS* p1,POS* p2,POS* p3,POS* p4);
void makePos(POS *p,int x,int y);
bool onSegment(POS* p1,POS* p2,POS* p);

int crossMul(POS* p1,POS* p2){
    return (p1->x*p2->y)-(p1->y*p2->x);
}  

bool onSegment(POS* p1,POS* p2,POS* p){
    if((p->x-p1->x)*(p2->y-p1->y)==(p2->x-p1->x)*(p->y-p1->y) && min(p1->x,p2->x)<=p->x&&p->x<=max(p1->x,p2->x) && min(p1->y,p2->y)<=p->y && p->y<=max(p1->y,p2->y)){
    	return true;
	}
    else{
    	return false;
	}
}
 
bool checkCross(POS* p1,POS* p2,POS *p3,POS *p4)  
{  
	if(onSegment(p1,p2,p3)==true || onSegment(p1,p2,p4)==true){
		return true;
	}
    POS *v1,*v2,*v3;
    v1=(POS *)malloc(sizeof(POS));
    v2=(POS *)malloc(sizeof(POS));
    v3=(POS *)malloc(sizeof(POS));
    v1->x=p1->x-p3->x;
    v1->y=p1->y-p3->y;
    v2->x=p2->x-p3->x;
    v2->y=p2->y-p3->y;
    v3->x=p4->x-p3->x;
    v3->y=p4->y-p3->y;
    int n1=crossMul(v1,v3)*crossMul(v2,v3);
    v1->x=p3->x-p1->x;
    v1->y=p3->y-p1->y;
    v2->x=p4->x-p1->x;
    v2->y=p4->y-p1->y;
    v3->x=p2->x-p1->x;
    v3->y=p2->y-p1->y;
    int n2=crossMul(v1,v3)*crossMul(v2,v3);
    free(v1);
    free(v2);
    free(v3);
    return n1<0 && n2<0?true:false;
}  

void makePos(POS *p,int x,int y){
	p->x=x;
	p->y=y;
}

int main(){
	POS *p1,*p2,*p3,*p4;
	p1=(POS *)malloc(sizeof(POS));
	p2=(POS *)malloc(sizeof(POS));
	p3=(POS *)malloc(sizeof(POS));
	p4=(POS *)malloc(sizeof(POS));
	makePos(p1,2,2);
	makePos(p2,6,2);
	makePos(p3,4,-2);
	makePos(p4,4,4);
	cout<<checkCross(p1,p2,p3,p4)<<endl;
	return 0;
}
