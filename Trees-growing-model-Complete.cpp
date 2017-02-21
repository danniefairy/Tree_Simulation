#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main()
{
	int i;
	double date;
	int timelong=0;
	int timetotal=0;
    int nutrient=0;
    int water=0;
    double sunshine=50;
    double stormdamage=0;
    double humidity=50;
    
    double height=1;
    double deltaheight=0;
    double health=100;
    double deltahealth=0;
    
    double tree[1000][10];
    tree[0][0]=1;
    tree[0][1]=height;
    tree[0][2]=health;
    tree[0][3]=nutrient;
    tree[0][4]=water;
    tree[0][5]=sunshine;
    tree[0][6]=stormdamage;
    tree[0][7]=humidity;
    tree[0][8]=deltaheight;
    tree[0][9]=deltahealth;
    for(i=1;;i++)
    {

    	if(timelong!=0)
        	timelong=timelong-1;
        	
    	if(timelong==0)
    	{
    		printf("%d month(s)\n",i);
    		printf("Whether planting automatically?(Y/N)\n");
    		nutrient=0;
        	water=0;
		}
    		
    	else
    		printf("%d month(s) <No. %d month(s) auto with (%dKG & %dL)>\n",i,timetotal-timelong+1,nutrient,water);
    	
		
    	tree[i][0]=i;
		printf("Height:%f\n",tree[i-1][1]);
        printf("Health:%f\n",tree[i-1][2]);    
		
        for(int j=1;j<=3;j++)
        {

            if(i==1||timelong==0)
			_sleep(1000);
            
       
            if(kbhit())
            {           

				if(timelong==0)
				{
					
					
				char ch;
				scanf("%c",&ch);
				ch=toupper(ch);
				if(ch=='Y')
				{
					printf("Enter how lone will you want to plant it automatically?\n");

					scanf("%d",&timelong);
					timetotal=timelong;
					printf("Enter how many Kg will you fertilize per month?\n");
					scanf("%d",&nutrient);
					printf("Enter how many L will you water per month?\n");
					scanf("%d",&water);					
					 }
				else if(ch=='N')
				{
					printf("Nurtient(0~20(kg)):");
                	scanf("%d",&nutrient);
                	printf("Water(0~20(L)):");
                	scanf("%d",&water);
				}
                
                if(nutrient>20)
                {
                    printf("Too much nutrient!\n The tree is dead!\n");
                    system("pause");
                    return 0;
                    }
                
                
                if(water>20)
                {
                    printf("Too much water!\n The tree is dead!\n");
                    system("pause");
                    return 0;
                    }
                	
				}
				else
				{
					break;
					
				}
				
				
            }
            
        }
        
        if(i==1&&nutrient==0)
            {
                printf("No nutrient!\nThe tree is dead!\n");
                system("pause");
                return 0;
            }
        if(i==1&&water==0)
            {
                printf("No water!\nThe tree is dead!\n");
                system("pause");
                return 0;
            }
                    
		tree[i][3]=nutrient;
    	tree[i][4]=water;
    
        srand(time(NULL));
		sunshine=(rand()%100+1);
		tree[i][5]=sunshine;
		
        _sleep(10);
        srand(time(NULL));
        double p=(-1)*(rand()%20+1)+10;
        double k=i;       
        if(p>(10*sin(k/3)))
		    stormdamage=(rand()%10+1)/10*tree[i-1][1];
		else
		    stormdamage=0;
		tree[i][6]=stormdamage;
                        
        if(i==1)
        	humidity=(100-tree[i][5])*(water+1)/(rand()%3+1)/10+stormdamage*2*tree[i-1][1];
        else
        	humidity=(100-tree[i-1][5])*(water+1)/(rand()%3+1)/10+stormdamage*2*tree[i-1][1];
        tree[i][7]=humidity;
        if(i==1)
        	humidity=humidity/6;
		

		deltaheight=((sqrt((20*water-water*water+1)*(nutrient+1)*(tree[i-1][2]))*i-i*i)*(1+sqrt(sunshine)*(tree[i-1][1])))*sqrt(humidity+1)/(tree[i-1][1])/15000;
        if(deltaheight<0)
            deltaheight=0;
        tree[i][8]=deltaheight;
         
        if(i==1)
        {
            deltahealth=((tree[1][5])*(tree[1][7])+(tree[0][5])*(tree[0][7]))/2000;
        }
        else if(i==2)
        {
             deltahealth=((tree[2][5])*(tree[2][7])+(tree[1][5])*(tree[1][7])+(tree[0][5])*(tree[0][7]))/3000;
        }
        else if(i>=3)
        {
             deltahealth=((tree[i][5])*(tree[i][7])+(tree[i-1][5])*(tree[i-1][7])+(tree[i-2][5])*(tree[i-2][7])+(tree[i-3][5])*(tree[i-3][7]))/4000;
        }
        tree[i][9]=deltahealth;
        height=tree[i-1][1]+deltaheight-tree[i][6];
        tree[i][1]=height;
        
        health=(tree[i-1][2]+deltahealth-tree[i][6]/2)*(tree[i-1][1]-tree[i][8])/tree[i-1][1];
        if(health==0)
        	health=0;
        tree[i][2]=health;
        
        if(tree[i][2]<0)
        {
            printf("The tree is dead!\n");
            printf("The height of the tree is :%f(%dmonths)\n\n",tree[i][1],i);
            goto Manu;
        }
		if(i>10)
			if(tree[i][1]==tree[i-1][1]&&tree[i][1]==tree[i-2][1]&&tree[i][1]==tree[i-3][1])
			{
				printf("The tree is healthy and stable!\n");
				printf("The height of the tree is :%f\n\n",tree[i][1]);
            	goto Manu;
			}
        
        system("cls");
    }
    
    Manu:
    	{
    		printf("Choose what data do you need:\n");
    		printf("1 for Height\n");
    		printf("2 for Health\n");
    		printf("3 for Nutrient\n");
    		printf("4 for Water\n");
    		printf("5 for Sunshine\n");
    		printf("6 for Stormdamage\n");
    		printf("7 for Hunidity\n");
    		printf("8 for Deltaheight\n");
    		printf("9 for Deltahealth\n");
    		printf("10 for Plot\n");
    		printf("11 for Exit\n");
    		printf("-> ");
    		int choose;
    		scanf("%d",&choose);
 			switch(choose)
 			{
 				case 1:
 					goto Height;break;
 				case 2:
 					goto Health;break;
 				case 3:
 					goto Nutrient;break;
 				case 4:
 					goto Water;break;
 				case 5:
 					goto Sunshine;break;
 				case 6:
 					goto Stormdamage;break;
 				case 7:
 					goto Humidity;break;
 				case 8:
 					goto Deltaheight;break;
 				case 9:
 					goto Deltahealth;break;
 				case 10:
 					goto Plot;break;
 				case 11:
 					system("pause");return 0;
 					
			 }
		}
    
    Height:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The height of the tree = %f(%dmonths)\n",tree[m][1],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Health:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The health of the tree = %f(%dmonths)\n",tree[m][2],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Nutrient:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The nutrient of the tree = %f(%dmonths)\n",tree[m][3],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Water:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The water of the tree = %f(%dmonths)\n",tree[m][4],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Sunshine:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The sunshine of the tree = %f(%dmonths)\n",tree[m][5],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Stormdamage:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The stormdamage of the tree = %f(%dmonths)\n",tree[m][6],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Humidity:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The humidity of the tree = %f(%dmonths)\n",tree[m][7],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Deltaheight:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The deltaheight of the tree = %f(%dmonths)\n",tree[m][8],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Deltahealth:
    	{
    		for(int m=1;m<=i;m++)
            	printf("The deltahealth of the tree = %f(%dmonths)\n",tree[m][9],m);
            system("pause");
            system("cls");
            	goto Manu;
		}
	Plot:
    	{
            system("cls");
            printf("Please enter which data do you want to plot?\n");
    	    printf("1 for Height\n");
    		printf("2 for Health\n");
    		printf("3 for Nutrient\n");
    		printf("4 for Water\n");
    		printf("5 for Sunshine\n");
    		printf("6 for Stormdamage\n");
    		printf("7 for Hunidity\n");
    		printf("8 for Deltaheight\n");
    		printf("9 for Deltahealth\n");
            int w;
            scanf("%d",&w);
    		int ratio=1;
    		int zone=100;
    		double large=tree[1][w];
    		for(int g=0;g<=i;g++)
   			 {
    			if(tree[g][w]>=large)
    			large=tree[g][w];
			}
			
			for(double q=1;q<=20;q++)
			{
                    if(large>pow(2,q-1)*zone&&large<=pow(2,q)*zone)
                    {
                        ratio=ratio*pow(2,q);
                        break;
                    }
             }
			//printf("%f\n",large);
 			printf("M\\H ");
 			if(large>10000)
 			{
   	            for(int k=0;k<=large/10/ratio;k++)
				    printf("%-10d",10*ratio*k);        
            }
            else
                for(int k=0;k<=large/10/ratio;k++)
				    printf("%-10d",10*ratio*k);   
		
			printf("\n    ");
			for(int k=0;k<=large/10/ratio;k++)
			{
				printf("----------");	
			}
			printf("\n");
			for(int k=0;k<=i;k++)
			{
				printf("%3d|",k);
				for(int u=1;u<=(tree[k][w]-1)/ratio;u++)
				printf(" ");
				printf("o\n");
			}
	        int YORN;
	        printf("Want to looking for each month's data?(1/0)\n");
	        scanf("%d",&YORN);
	        //YORN=toupper(YORN);
	        if(YORN==0)
	        {
                       system("cls");
                       goto Manu;
            }
                
			int check=1;
			while(check)
			{
				printf("Looking data for which months?");
				int month;
				scanf("%d",&month);
				printf("Month:%f\n",tree[month][0]);
				printf("Height:%f\n",tree[month][1]);
				printf("Health:%f\n",tree[month][2]);
				printf("Nutrient:%f\n",tree[month][3]);
				printf("Water:%f\n",tree[month][4]);
				printf("Sunshine:%f\n",tree[month][5]);
				printf("Stormdamage:%f\n",tree[month][6]);
				printf("Humidity:%f\n",tree[month][7]);
				printf("Deltaheight:%f\n",tree[month][8]);
				printf("Deltahealth:%f\n",tree[month][9]);
				printf("Whether want to looking data again?(1/0)");
				scanf("%d",&check);
				system("cls");
				printf("\n");
			}
			system("cls");
			goto Manu;
		}
}
//printf("nutrient=%d\nsunshine=%f\nhumidity=%f\n\deltaheight=%f\nstormdamage=%f\n",nutrient,sunshine,humidity,deltaheight,stormdamage);system("pause");
