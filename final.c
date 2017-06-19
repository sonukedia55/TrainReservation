#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>


void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

//...................................String to code......................................

int stoc(char a[4]){
	
	int i=0;
	
			int b,c=0,n=0,mi=1,j,k,h;
			
			b=0;c=0;n=0;mi=0;j=0;k=0;
			
			for(j=0;a[j]!='\0';j++) n++;
			
			for(j=0;j<n;j++)
			{
				b=a[j];
					b=b-65;
					mi=1;
					
					for(k=0;k<j;k++){
						mi=mi*26;
					}
					if(j==n)mi=1;
					
					c=c+b*mi;	
					
				}
	
	   
	return c;

	
}


//..................................string to code.......................................//

//..................................Code to String.......................................

void ctos(int b){
	
	int p=0;
	int i=0;int c=0;
	while(b>0){
		c=b%26;
		c=c+65;
		b=b/26;
		if(i==1)i=2;
		if(b==0){i=1;}
		//chg[p]=c;
		printf("%c",c);
		p++;
	}
	p=0;
	
	
}


//.......................................to get the no of seats available of particular train..........


int getseats(int train_no,int date){
	
	int l=0,search=0;
	
	FILE *qs;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int mn=tm.tm_mon + 1;int dy = tm.tm_mday;
	
	dy=date-dy-1;
	
   qs = fopen("train.txt", "r");
   
   
   int cont=1,train_id,seats[7],temp;
   
   
   
   while(qs!=NULL){
	   
	   
	   
	   fscanf(qs,"%d %d %d %d %d %d %d %d\n",&train_id,&seats[0],&seats[1],&seats[2],&seats[3],&seats[4],&seats[5],&seats[6]);
	   
	   if(train_id==temp)break;
	  
	   temp=train_id;
	   if(train_id==train_no)search=seats[dy];
	   
   }
	   
   fclose(qs);  
   return search;
	
}
//.......................................to get the no of seats available of particular train..........//

//.......................................to get the schedule of particular train..........

void getschedule(int train_no){
	
	int l=0,temp;
 int i,r=10;
 int b,h,m;
	FILE *qs;
  char a[4];
  temp=train_no;
  int temp2;
  char dd[4];
  
  for(i=0;i<4;i++){
	  
	  temp2=temp%10;
	  temp=temp/10;
	  a[3-i]=(char)(temp2+48);
	  
  }
	  a[4]='\0';
   
   strcat(a,".txt");
   qs = fopen(a, "r");
   
   temp=0;
   int cont=1,stations,hour,min;
   
   system("@cls||clear");
	
	printf("\n\n      ********************INDIAN RAIWAYS********************\n");
	printf("\n\n");
	printf("                           Train No : %d\n",train_no);
	printf("\n\n");
	printf("         ---------------------SCHEDULE---------------------\n");
  
   while(qs!=NULL){
	   
	   
	   
	   fscanf(qs,"%d %d %d\n",&stations,&hour,&min);
	   
	   if(stations==temp)break;
	   printf("\n        |");
	   printf("              ");
	   ctos(stations);
	   printf("          %02d:%02d",hour,min);
	   temp=stations;
	   
	   printf("                 |");
   }
	   printf("\n\n         ---------------------------------------------------\n");
   fclose(qs);  
	
	
	
}

//.......................................to get the schedule of particular train...........//

//....................................to get the Arival of train In hour..........................


int gethour(int train,int station){
	
	int l=0,temp,search;
 int i,r=10;
 int b,h,m;
	FILE *qs;
  char a[4];
  temp=train;
  int temp2;
  char dd[4];
  
  for(i=0;i<4;i++){
	  
	  temp2=temp%10;
	  temp=temp/10;
	  a[3-i]=(char)(temp2+48);
	  
  }
	  a[4]='\0';
   
   strcat(a,".txt");
   qs = fopen(a, "r");
   
   temp=0;
   int cont=1,station1,hour,min;
   
   
   
   while(qs!=NULL){
	   
	   
	   
	   fscanf(qs,"%d %d %d\n",&station1,&hour,&min);
	   
	   if(station1==temp)break;
	   
	   temp=station1;
	   if(station1==station)search=hour;
	   
   }
	   
   fclose(qs);  
   return search;
	
}

//....................................to get the Arival of train In hour..........................//

//....................................to get the Arival of train In min..........................


int getmin(int train,int station){
	
	
	int l=0,temp,search;
 int i,r=10;
 int b,h,m;
	FILE *qs;
  char a[4];
  temp=train;
  int temp2;
  char dd[4];
  
  for(i=0;i<4;i++){
	  
	  temp2=temp%10;
	  temp=temp/10;
	  a[3-i]=(char)(temp2+48);
	  
  }
	  a[4]='\0';
   
   strcat(a,".txt");
   qs = fopen(a, "r");
   temp=0;
   int cont=1,station1,hour,min;
   
   
   
   while(qs!=NULL){
	   
	   
	   
	   fscanf(qs,"%d %d %d\n",&station1,&hour,&min);
	   
	   if(station1==temp)break;
	   
	   temp=station1;
	   if(station1==station)search=min;
	   
   }
	   
   fclose(qs);  
   return search;
	
}

//....................................to get the Arival of train In min..........................//


//.......................................Finding particular train from ini to fin route..........

int findtrain(int ini,int fin,int date){
	
	int l=0,chk=0;
	
	FILE *qs;
  
   qs = fopen("train_station.txt", "r");
   
   
   int cont=1,train_id,seats,temp,tmp2,inti=ini,flg=0,tt;
   
   system("@cls||clear");
	
	printf("\n   ___________________________________________________________________\n");
	printf("   |                                                                   |\n");
	printf("   |                 *****INDIAN RAILWAYS*****                         |\n");
	printf("   |                                                                   |\n");
	printf("   |                      Date : %02d-04-17                              |\n",date);
	printf("   |                                                                   |\n");
	printf("   |               Train No - Schedule - Availability                  |\n");
	
	char noo[20]="No Result Found!";

   while(qs!=NULL){
	   
	   fscanf(qs,"%d %d",&train_id,&seats);
	   flg=0;
	   
	   for(l=0;l<seats;l++){
		   fscanf(qs," %d",&tmp2); if(tmp2==inti) flg++;if(tmp2==fin){ if(flg==1)flg++;}
	   }
	   
	   if(flg==2){
		   
		   chk=1;
		   printf("\n                       %d   - %02d:%02d -     %d",train_id,gethour(train_id,ini),getmin(train_id,ini),getseats(train_id,date));
		   
		   
		   }
	   
	   if(train_id==temp)break;
	   
	   temp=train_id;
	   
	   
   }
	 if(chk==1){
	printf("\n   ____________________________________________________________________\n");
	
	printf("\n                 Enter the Train No. :");
	
	 scanf("%d",&tt);}
	 else{
		 printf("\n                    **    No Result Found!    **                         \n");
		 printf("\n   ____________________________________________________________________\n");
		 tt=0;
		 
	 }
	fclose(qs);	 
	return tt;
	
	
}

//.......................................Finding particular train from ini to fin route..........//

//.......................................To insert in booked.txt of the booked ticket..........


void entry(char name[20],int seat,int p_train){
	
	int l=0,no;
	
	FILE *qs,*qr,*qp;
  
   qs = fopen("booked.txt", "a");
   qr = fopen("no_booked.txt", "r");
   fscanf(qr,"%d",&no);
   qp = fopen("no_booked.txt", "w");
   no=no+1;
   fprintf(qp,"%d",no);
	   
	fprintf(qs,"%d %d %s\n",p_train,seat,name);
   
   
  fclose(qr);  
   fclose(qs);  
	fclose(qp);  
	
}
//.......................................To insert in booked.txt of the booked ticket..........//

//.......................................To Update seats of a particular train after booking..........


void update_seats(int train,int seat,int date){
	
	FILE *stream=fopen("train.txt","r");
	FILE *stream1=fopen("copy.txt","w");
	int a,b,temp=0,seats[7];
	
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int mn=tm.tm_mon + 1;int dy = tm.tm_mday;
	dy=date-dy-1;
	
	for(;;)
	{
    	
	fscanf(stream,"%d %d %d %d %d %d %d %d\n",&a,&seats[0],&seats[1],&seats[2],&seats[3],&seats[4],&seats[5],&seats[6]);
	
	if(a==train)
		seats[dy]=seat;
	if(temp!=a)
	fprintf(stream1,"%d %d %d %d %d %d %d %d\n",a,seats[0],seats[1],seats[2],seats[3],seats[4],seats[5],seats[6]);
	if(temp==a)
    	{
         goto ab; 		
	    }
    else
		temp=a;
			
	}
	ab:
	
	fclose(stream1);
	fclose(stream);
	FILE *stream2=fopen("copy.txt","r");
	FILE *stream3=fopen("train.txt","w");
	int c;
	while((c=getc(stream2))!=EOF)
		putc(c,stream3);
	
	fclose(stream1);
	fclose(stream);
	
	
}
//.......................................To Update seats of a particular train after booking..........//


//.......................................To Show passengers of particular train..........


void showPassengers(int train_no){
	
	
	int l=0,search=0,no;
	
	FILE *qs,*qr;
	
   qs = fopen("booked.txt", "r");
   qr = fopen("no_booked.txt", "r");
   fscanf(qr,"%d",&no);
   
   int cont=1,train,seats,temp,temp2;
   char name[20];
   
   
   while(no>0){
	   
	   
	   no=no-1;
	   fscanf(qs,"%d %d %s\n",&train,&seats,name);
	   
	   
	   temp=train;temp2=seats;
	   
	   if(train==train_no)
		    printf("\n     %d - %s",seats,name);
	   
   }
	   
   fclose(qs);  
  
	
	
}

//.......................................To Add a particular train./...................//

void addTrain(int train_id){
	
	system("@cls||clear");
	
	int l=0;
	
	FILE *qs;
  
   qs = fopen("train.txt", "a");
   
   int seats;
   
	   printf("\n            No. of Seats?");
	   scanf("%d",&seats);
	   
	   fprintf(qs,"%d %d %d %d %d %d %d %d\n",train_id,seats,seats,seats,seats,seats,seats,seats);
   
	   
   
   fclose(qs);  
	
}

//.......................................To Add a of particular train..........

//.......................................To Add Stopping Stations of particular train..........

void addStations(int train_id,int stations){
	
	int l=0;
	int i=0;
	FILE *qs;
  char a[4];
   printf("\n\n         ---------------------------------------------------\n");
   qs = fopen("train_station.txt", "a");
  
	   fprintf(qs,"%d %d",train_id,stations);
	   for(i=0;i<stations;i++){
		   printf("\n            Stations %d? ",i+1);
			scanf("%s",a);
			
			
			int b,c=0,n=0,mi=1,j,k,h;
			
			b=0;c=0;n=0;mi=0;j=0;k=0;
			
			for(j=0;a[j]!='\0';j++) n++;
			for(j=0;j<n;j++)
			{
				b=a[j];
					b=b-65;
					mi=1;
					
					for(k=0;k<j;k++){
						mi=mi*26;
					}
					if(j==n)mi=1;
					
					c=c+b*mi;	
					
				}
	
		   fprintf(qs," %d",c);
		   
	   
	   
	   
   
	   }
   fprintf(qs,"\n");
   fclose(qs);  
	
	
}

//.......................................To Add Stopping Stations of particular train..........//

//.......................................To Add Schedule of particular train..........

void addschedule(int train_id,int stations){
	
	 printf("\n\n         ---------------------------------------------------\n");
	
 int l=0,temp;
 int i,r=10;
 int b,h,m;
	FILE *qs;
  char a[4];
  temp=train_id;
  int temp2;
  char dd[4];
  
  for(i=0;i<4;i++){
	  
	  temp2=temp%10;
	  temp=temp/10;
	  a[3-i]=(char)(temp2+48);
	  
  }
	  a[4]='\0';
   
   strcat(a,".txt");
   qs = fopen(a, "w");
	   
	   for(i=0;i<stations;i++){
		   printf("\n            HH MM station_Name %d :? ",i+1);
			scanf("%d %d %s",&h,&m,dd);
			l=stoc(dd);
		   fprintf(qs,"%d %d %d\n",l,h,m);
		   
		   
	   }
	   
   fclose(qs);
	
	
}

//.......................................To Add Schedule of particular train..........//

//.......................................To Cancel Ticket............................//


void cancelTicket(int train_id,int seats,char name[20],int date){
	
	int l=0,no;
	
	FILE *qs,*qr,*ql,*q2;
  
   qs = fopen("booked.txt", "r");
   qr = fopen("no_booked.txt", "r");
   fscanf(qr,"%d",&no);
   q2 = fopen("copy2.txt", "w");
	
	
	int q=no;char nm[20];
	int a,b,temp=0;
	
	while(q>0)
	{
    	q--;
	fscanf(qs,"%d %d %s\n",&a,&b,nm);
	
	if(a==train_id&&b==seats&&strcmp(name,nm)==0)
	{b=seats;l=1;}
	else{
		
		fprintf(q2,"%d %d %s\n",a,b,nm);
		
	}
	
			
	}
	fclose(q2);fclose(qs);
	
	FILE *stream2=fopen("copy2.txt","r");
	FILE *stream3=fopen("booked.txt","w");
	q=no-1;
	while(q>0)
	{
    	q--;
	fscanf(stream2,"%d %d %s\n",&a,&b,nm);
	
	fprintf(stream3,"%d %d %s\n",a,b,nm);
				
	}
	no=no-1;
	fclose(qr);
	
	if(l==1){
	FILE *qp = fopen("no_booked.txt", "w");
    fprintf(qp,"%d",no);
	b=getseats(train_id,date);
	update_seats(train_id,b+1,date);
	fclose(qp);
	printf("\n         !!.........Your Ticket has been Cancelled...............!!");

	}
	if(l==0) printf("\n             !!.........No Ticket Found...............!!");
 
  fclose(stream2);
  fclose(stream3);
	
	
}
//.......................................To Cancel Ticket............................//

//.........../....../............/..........Displays............/......../........../........../....../


//.......................................To Show ticket of passengers after booking..........

void show_ticket(char name[20],int age,int no_ticket,char sin[4],char sfi[4],int p_train,int tick){
	
	
    int seat=tick-no_ticket+1;
	
	system("@cls||clear");
	printf("Your Generated Ticket: \n");
	printf("\n   ____________________________________________________________________\n");
	printf("   |                                                                   |\n");
	printf("   |                                                                   |\n");
	printf("   |                 *****INDIAN RAILWAYS*****                         |\n");
	printf("   |                                                                   |\n");

	printf("   | Traveller's Name:%s              Age: %d           \n",name,age);
	printf("   | Status: CONFIRMED                                                 |\n");
	if(seat!=tick)
	printf("   | Train no.: %d         Seats:%d-%d                       \n",p_train,seat,tick);
	else
	printf("   | Train no.: %d         Seat:%d                       \n",p_train,seat,tick);
	printf("   | From : %s               To :%s                                |\n",sin,sfi);
	printf("   |                                                                   |\n");
    printf("   |                ***''Wish You A Happy Journey''                    |\n");
	printf("   |___________________________________________________________________|");
	
	
	
}

//.......................................To Show ticket of passengers after booking..........//

//....................................welcome screen..................................

void welcome1(){
	
	system("@cls||clear");
	
	printf("\n\n      ********************INDIAN RAIWAYS********************\n");
	printf("\n\n");
	printf("                           WELCOME GUEST\n");
	printf("\n\n");
	printf("         ---------------------------------------------------\n");
	printf("         |      CHOOSE YOUR OPERATION                       |\n");
	printf("         |                                                  |\n");
	printf("         |      1.View Information                          |\n");
	printf("         |      2.Book ticket                               |\n");
	printf("         |      3.Admin                                     |\n");
	printf("         |      4.Cancel Ticket                             |\n");
	printf("         |      0.Exit                                      |\n");
	printf("         ---------------------------------------------------\n\n");
	printf("       ******************************************************\n");
	
}

//.......................................Admin screen........................

void admin(){
		
			system("@cls||clear");
	printf("\n\n     ********************INDIAN RAIWAYS********************\n");
	printf("\n\n");
	printf("                        WELCOME ADMIN\n");
	printf("\n\n");
	printf("              ----------------------------------\n");
	printf("              |      CHOOSE YOUR OPERATION     |\n");
	printf("              |                                |\n");
	printf("              |      1.View Passengers         |\n");
	printf("              |      2.Add Train               |\n");
	printf("              |                                |\n");
	printf("              ----------------------------------\n\n");
	printf("     ******************************************************\n");

}

//.......................................Admin screen........................

void menu2(){
		
			system("@cls||clear");
	printf("\n\n        ********************INDIAN RAIWAYS********************\n");
	printf("\n\n");
	printf("                        WELCOME Users\n");
	printf("\n\n");
	printf("              ----------------------------------\n");
	printf("              |      CHOOSE YOUR OPERATION     |\n");
	printf("              |                                |\n");
	printf("              |      1. View Schedule          |\n");
	printf("              |      2. View Availability      |\n");
	printf("              |                                |\n");
	printf("              ----------------------------------\n\n");
	printf("        ******************************************************\n");
	

}
void todayseats(){
	
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int mn=tm.tm_mon + 1;int dy = tm.tm_mday;
	
	
	FILE *stoday=fopen("today.txt","r");
	int chp;
	fscanf(stoday,"%d",&chp);
	chp=tm.tm_mday-chp;
	
	fclose(stoday);
	
	FILE *stodayt=fopen("today.txt","w");
	fprintf(stodayt,"%d",tm.tm_mday);
	fclose(stodayt);
	
	if(chp>0){
	
	FILE *stream=fopen("train.txt","r");
	FILE *stream1=fopen("copy.txt","w");
	int a,b,temp=0,seats[7],i;

	for(;;)
	{
    	
	fscanf(stream,"%d %d %d %d %d %d %d %d\n",&a,&seats[0],&seats[1],&seats[2],&seats[3],&seats[4],&seats[5],&seats[6]);
	
	if(temp!=a)
	{
		fprintf(stream1,"%d ",a);
		for(i=0;i<6;i++)
			if((chp+i)>=6)
				fprintf(stream1,"%d ",seats[6]);
			else
				fprintf(stream1,"%d ",seats[chp+i]);
			
			fprintf(stream1,"%d\n",seats[6]);
	}
	if(temp==a)
    	{
         goto ab; 		
	    }
    else
		temp=a;
			
	}
	ab:
	
	fclose(stream1);
	fclose(stream);
	FILE *stream2=fopen("copy.txt","r");
	FILE *stream3=fopen("train.txt","w");
	int c;
	while((c=getc(stream2))!=EOF)
		putc(c,stream3);
	
	fclose(stream1);
	fclose(stream);
	}
}

int main(){
	
	int ch1,chckr,start,seats,p_train,chh,tick,no_ticket,s1,s2,age[10],i,seats2,tr_no,l,ps2,dd,mm,nostations;
	char sin[5],sfi[5],condl1,name[10][20],pass[9],ps;
	todayseats();
	start=1;
	while(start==1){
	start=0;
	welcome1();
	printf("\n\n                    Enter your choice : ");
	scanf("%d",&ch1);
	switch(ch1)
	{
		
		case 1:{
			chckr=1;
			while(chckr==1){
			chckr=0;
			menu2();
			printf("\n\nEnter your choice:");
			scanf("%d",&chckr);
			
			if(chckr==1){
				chckr=0;				
				printf("\n");							//check schedule
				printf("Enter the train no:");
				scanf("%d",&tr_no);
				getschedule(tr_no);
				printf("\n\n                      Back (B) Main-Menu (M)? : ");
				
				scanf("%c",&condl1);
				if(condl1=='\n')scanf("%c",&condl1);
				if(condl1=='B'){start=1;chckr=1;}
				if(condl1=='M'){start=1;}
				
			}
			if(chckr==2){
												//check seats avail
				chckr=0;
				printf("\n                 Enter the train no:");
				scanf("%d",&tr_no);
				printf("\n                 Enter Date (dd mm):");
				scanf("%d %d",&dd,&mm);
				seats=0;
				seats=getseats(tr_no,dd);system("@cls||clear");
				printf("\n\n         ----------------------------------\n\n");
				printf("                Available Seats : %d\n\n",seats);
				printf("         ----------------------------------\n\n");
				
				printf("\n\n             Back (B) Main-Menu (M)? : ");
				scanf("%c",&condl1);
				if(condl1=='\n')scanf("%c",&condl1);
				if(condl1=='B'){chckr=1;}
				if(condl1=='M'){start=1;}
				

				
			}}
				
				if(start!=1){printf("\n\n                  Main-Menu (M)? : ");
				scanf("%c",&condl1);
				if(condl1=='\n')scanf("%c",&condl1);
				
				if(condl1=='M'){start=1;}
				}
			
			break;
		}
		
		case 2:{
			chckr=1;
		while(chckr==1){
			chckr=0;
			seats=0;
		system("@cls||clear");
		
		gotoxy(10, 2);
		printf("\n\n    ********************INDIAN RAIWAYS********************\n");
		printf("   |                                                     |\n");
		printf("   |                                                     |\n");
		printf("   |              ---------------------------            |");  
		gotoxy(10, 15);	
		printf("\n                 ---------------------------");
		gotoxy(10, 8);
		printf("\n\n                    Final station: ");
		scanf("%s",sfi);
		printf("\n                    Inital Station: ");
		scanf("%s",sin);
		printf("\n                    Date (dd mm) : ");
		scanf("%d %d",&dd,&mm);
		
			
			
			s2=stoc(sfi);
			s1=stoc(sin);
			
			p_train=findtrain(s1,s2,dd);
			seats=getseats(p_train,dd);
			if(seats>0){
				printf("\n            Enter 0 to go back: ");
				printf("\n\n            Enter no. of passengers :");
				scanf("%d",&no_ticket);
				if(no_ticket>0){
				
				if(seats-no_ticket>=0){
					tick=seats;
					for(i=0;i<no_ticket;i++){
						
						printf("\n\n            Enter name of passenger %d :",i+1);
						scanf("%s",name[i]);
						printf("            Enter age. of passenger :");
						scanf("%d",&age[i]);
						entry(name[i],tick-i,p_train);
						
					}
					
					seats2=seats-no_ticket;
					update_seats(p_train,seats2,dd);
			
					show_ticket(name[0],age[0],no_ticket,sin,sfi,p_train,tick);
			
					printf("\n\n                      Back (B) Main-Menu (M)? : ");
					scanf("%c",&condl1);
					if(condl1=='\n')scanf("%c",&condl1);
					if(condl1=='B'){chckr=1;}
					if(condl1=='M'){start=1;}
					
				}else{
					printf("\n\n                      Back (B) Main-Menu (M)? : ");
					scanf("%c",&condl1);
					if(condl1=='\n')scanf("%c",&condl1);
					if(condl1=='B'){chckr=1;}
					if(condl1=='M'){start=1;}
					
					
					
				}
				}
				
			}else{
			printf("\n\n                      Back (B) Main-Menu (M)? : ");
					scanf("%c",&condl1);
					if(condl1=='\n')scanf("%c",&condl1);
					if(condl1=='B'){chckr=1;}
					if(condl1=='M'){start=1;}
			
			}
			
		}break;
		}
		case 3:{
			
				printf("\nEnter the password : ");
				ps='a';l=0;ps2=0;
				while(ps2!=13)
					 {
					  ps = getch();
					  ps2=ps;
					 if(ps2==13){pass[l]='\0';l=13;}
					  if(l!=13){
						  pass[l] = ps;
						  printf("*");l++;}
					  
					 }
					 //printf("%s",pass);
				//scanf("%d",&l);
				chckr=1;
			
				if(strcmp(pass,"SONUKEDIA")==0){
				while(chckr==1){	
					chckr=0;
					admin();
					printf("\n\n             Enter your Choice: ");
					scanf("%d",&chh);
														///Show passenger
					if(chh==1){
						printf("\nEnter the Train no. :");
						scanf("%d",&p_train);
						showPassengers(p_train);
						
					}									//add Trains
					
					if(chh==2){
						p_train=0;
						printf("\n            Enter the Train no.: ");
						scanf("%d",&p_train);
	
						addTrain(p_train);
						 printf("\n            No. of Stations? ");
						scanf("%d",&nostations);
						addStations(p_train,nostations);
						addschedule(p_train,nostations);
					}
					printf("\n\n                      Back (B) Main-Menu (M)? : ");
					
					scanf("%c",&condl1);
					if(condl1=='\n')scanf("%c",&condl1);
					
					if(condl1=='B'){chckr=1;}
					if(condl1=='M'){start=1;}
					
					
					
				}
			
			}
				
				printf("\n\n                      Main-Menu (M)? : ");
				scanf("%c",&condl1);
				if(condl1=='\n')scanf("%c",&condl1);
				
				if(condl1=='M'){start=1;}
			break;
		}
		case 4:{
			chckr=1;
			while(chckr==1){
				chckr=0;
			system("@cls||clear");
		gotoxy(10, 2);
		printf("\n\n    ********************INDIAN RAIWAYS********************\n");
		printf("   |                                                     |\n");
		printf("   |                     CANCEL TICKET                   |\n");
		printf("   |                                                     |\n");
		printf("   |              ---------------------------            |");     
		gotoxy(10, 20);
		printf("\n                 ---------------------------            \n\n");   
		gotoxy(10, 8);
		printf("\n\n                    Train Number: ");
		scanf("%d",&p_train);
		printf("\n\n                    Seat Number: ");
		scanf("%d",&seats);
		printf("\n\n                    Date (dd mm) : ");
		scanf("%d %d",&dd,&mm);
		printf("\n\n                    Name: ");
		scanf("%s",name[0]);
		
		if(p_train!=0){
		cancelTicket(p_train,seats,name[0],dd);
		}
		
		
		printf("\n\n                   Back (B) Main-Menu (M)? : ");
					
					scanf("%c",&condl1);
					if(condl1=='\n')scanf("%c",&condl1);
					
					if(condl1=='B'){chckr=1;}
					if(condl1=='M'){start=1;}
					
		
		}}
	
}


}
}