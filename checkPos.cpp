#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define left -1000
using namespace std;

struct POS{
	int x,y;
	POS *next;
};

int crossMul(POS* p1,POS* p2);
bool checkCross(POS* p1,POS* p2,POS* p3,POS* p4);
bool checkPos(int tx,int ty,POS* head);
bool onSegment(POS* p1,POS* p2,POS* p);

int main(){
	freopen("number.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int x,y,num,tx,ty;
	scanf("%d",&num);
	fclose(stdin);
	freopen("tp.txt","r",stdin);
	POS *q,*first,*last;
	first=last=NULL;
	while(scanf("%d %d",&tx,&ty)!=EOF){
		q=(POS *)malloc(sizeof(POS));
		q->x=tx;
		q->y=ty;
		if(first==NULL){
			first=last=q;
		}
		else{
			last=last->next=q;
		}
	} 
	last->next=NULL;
	fclose(stdin);
	POS *head,*tail,*p;
	char s1[10],s2[10],ns[10],end;
	bool test=false;
	for(q=first;q->next!=NULL;q=q->next){
		test=false;
		strcpy(s1,"in");
		strcpy(s2,".txt");
		for(int i=1;i<=num;i++){
			itoa(i,ns,10);
			freopen(strcat(strcat(s1,ns),s2),"r",stdin);
			strcpy(s1,"in");
			strcpy(s2,".txt");
			head=tail=NULL;
			while(scanf("%d %d",&x,&y)!=EOF){
				p=(POS *)malloc(sizeof(POS));
				p->x=x;
				p->y=y;
				if(head==NULL){
					head=tail=p;
				}
				else{
					tail=tail->next=p;
				}
			}
			tail->next=NULL;
			test=checkPos(q->x,q->y,head);
			if(test==true){
				break;
			}
		}
		if(test==false){
			printf("0\n");
		}
		else{
			printf("1\n");
		}
	}
	test=false;
	strcpy(s1,"in");
	strcpy(s2,".txt");
	for(int i=1;i<=num;i++){
		itoa(i,ns,10);
		freopen(strcat(strcat(s1,ns),s2),"r",stdin);
		strcpy(s1,"in");
		strcpy(s2,".txt");
		head=tail=NULL;
		while(scanf("%d %d",&x,&y)!=EOF){
			p=(POS *)malloc(sizeof(POS));
			p->x=x;
			p->y=y;
			if(head==NULL){
				head=tail=p;
			}
			else{
				tail=tail->next=p;
			}
		}
		tail->next=NULL;
		test=checkPos(last->x,last->y,head);
		if(test==true){ 
			break;
		}
	}
	if(test==false){
		printf("0");
	}
	else{
		printf("1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


bool onSegment(POS* p1,POS* p2,POS* p){
    if((p->x-p1->x)*(p2->y-p1->y)==(p2->x-p1->x)*(p->y-p1->y) && min(p1->x,p2->x)<=p->x&&p->x<=max(p1->x,p2->x) && min(p1->y,p2->y)<=p->y && p->y<=max(p1->y,p2->y)){
    	return true;
	}
    else{
    	return false;
	}
}


int crossMul(POS* p1,POS* p2){
    return (p1->x*p2->y)-(p1->y*p2->x);
}


bool checkCross(POS* p1,POS* p2,POS* p3,POS* p4){
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


bool checkPos(int tx,int ty,POS* head){
	POS *p,*p1,*p2,*p3,*p4;
    int count=0;
    p1=(POS *)malloc(sizeof(POS));
    p2=(POS *)malloc(sizeof(POS));
    p1->x=tx;
    p1->y=ty;
    p2->x=left;
    p2->y=ty;
    for(p=head;p->next!=NULL;p=p->next){
        p3=p;
        p4=p->next;
        if(onSegment(p3,p4,p1)==true){
        	return true;
		}
		else{
			if(onSegment(p1,p2,p3)==true){
				if(p4->y>ty){
					count++;
				}
				continue;
			}
			if(onSegment(p1,p2,p4)==true){
				if(p3->y>ty){
					count++;
				}
				continue;
			}
			if(p3->y==ty&&p4->y==ty&&tx>=p3->x&&tx>=p4->x){
        		continue;
			}
			else{
				if(checkCross(p1,p2,p3,p4)==true){
		            count++;
		        }
			}
		}
    }
    p3=p;
    p4=head;
    if(onSegment(p3,p4,p1)==true){
        	return true;
	}
	else{
		if(p3->y==ty&&p4->y==ty&&tx>=p3->x&&tx>=p4->x){
    		count+=2;
		}
		else{
			if(checkCross(p1,p2,p3,p4)==true){
	            count++;
	        }
		}
	}
    return count%2==0?false:true;
}
