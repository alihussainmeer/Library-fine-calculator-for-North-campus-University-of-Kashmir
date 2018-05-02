#include<stdio.h>

void days(int,int,int,int,int,int);
int month(int, int);
int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
void fine(int);

int main(){
    int d1,d2,m1,m2,y1,y2;  //n1 for withrawl date and n2 for submission date
    char con;
    do{
        printf("Enter the date of issuance of book(dd mm yyyy) :- ");
        scanf("%d%d%d",&d1,&m1,&y1);
        printf("Enter the date of Submission of book(dd mm yyyy) :- ");
        scanf("%d%d%d",&d2,&m2,&y2);

        if(y2>=y1){
            days(y1,y2,m1,m2,d1,d2);
        }else{
            days(y2,y1,m2,m1,d2,d1);
        }

        printf("\nPress y to continue :- ");
        scanf("%s",&con);
    }while(con == 'y');

return 0;
}


void days(int y1,int y2,int m1,int m2,int d1,int d2){
    int i, count = 0;

    for(i = y1; i < y2 ; i++){
        if(i%4 == 0){
            count += 366;
        }else{
            count += 365;
        }
    }

    count -= month(m1,y1);
    count -= d1;
    count += month(m2,y2);
    count += d2;

    if(count < 0)
        printf("Incorrent details\n");
    else{
        printf("Number of days is %d\n",count);
        fine(count);
    }

}

int month(int a, int y){
    int x = 0, c;

    for(c = 0; c < a-1 ; c++){
        if(c==1){
            if(y%4 == 0)
                x += 29;
            else
                x += 28;
        }
    else{
        x += mon[c];
    }

    }
    return x;
}


void fine(int d){
    int i,fine = 0,c;
    c = d-40; //the number of days we can take book without fine

    for(i=0; i<c ; i++){
        if(i<10){
            fine += 1;
        }
        if(i>=10 && i<30){
            fine +=2;
        }
        if(i>=30){
            fine += 4;
        }
    }
    printf("Fine = %d\n\n",fine);
}
