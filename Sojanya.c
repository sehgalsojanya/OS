#include<stdio.h>
struct system				
{
    int pno;
    int process_arrival;			
    int process_burst;
    int priority;

};
struct user
{
    int pno;
    int process_arrival;
    int process_burst;
    int priority;


};
struct result
{
    int final_pno;
};
int main()
{
	struct system objs[30];
	struct user obju[30];
    struct system temp;
    struct user temp1;
	struct result res[30];
	int i,n,j,min,times,timeu,end,k,ideal_time,syscnt,uscnt,call,flag;
	printf("Enter the no. of processes-");
	scanf("%d",&n);					//enter process
	i=1;
	j=1;
	for(k=1;k<=n;k++)
	{
	    printf("\n\nPROCESS P%d\n",k);
	    printf("press>> System Process{1} / User Process{any no.} -");
		scanf("%d",&call);
		if(call==1)
        {
            objs[i].pno=k;
            printf("Arrival Time-");
            scanf("%d",&objs[i].process_arrival);
            printf("Burst Time-");
            scanf("%d",&objs[i].process_burst);
            printf("Priority-");
            scanf("%d",&objs[i].priority);
            i++;
        }
        else
        {
            obju[j].pno=k;
            printf("Arrival Time-");
            scanf("%d",&obju[j].process_arrival);
            printf("Burst Time-");
            scanf("%d",&obju[j].process_burst);
            printf("Priority-");
            scanf("%d",&obju[j].priority);
            j++;
        }
	}
	i--;
	j--;
	syscnt=i;
	uscnt=j;
	times=objs[1].process_arrival;
    for(i=1;i<=syscnt;i++)
	{
        if(objs[i].process_arrival<times )
        {
            times=objs[i].process_arrival;
        }
	}
	timeu=obju[1].process_arrival;
    for(i=1;i<=uscnt;i++)
	{
        if(obju[i].process_arrival<timeu )
        {
            timeu=obju[i].process_arrival;
        }
	}
	for(k=1;k<syscnt;k++)
    {
        for(j=1;j<=syscnt-k;j++)
		{
            if(objs[j].priority<objs[j+1].priority)
            {
                temp = objs[j];
                objs[j]=objs[j+1];
                objs[j+1]=temp;
            }
		}
    }
    for(k=1;k<uscnt;k++)
    {
        for(j=1;j<=uscnt-k;j++)
		{
            if(obju[j].priority<obju[j+1].priority)
            {
                temp1 = obju[j];
                obju[j]=obju[j+1];
                obju[j+1]=temp1;
            }
		}
    }

    k=1;
    n=syscnt;
	while(k<=syscnt)
    {
     ideal_time=times+1;
     flag=0;
      for(j=1;j<=n;j++)
      {
          if(objs[j].process_arrival<=times)
          {
              res[k].final_pno=objs[j].pno;
              times=times+objs[j].process_burst;
                for(i=j;i<n;i++)
                {
                   objs[i]=objs[i+1];
                }
                n--;
                k++;
                flag=1;
            break;
          }

      }
        if(flag==0)
        {
                for(i=1;i<=n;i++)
                {
                    if(objs[i].process_arrival<ideal_time && ideal_time>times )
                    {
                        ideal_time=objs[i].process_arrival;
                    }
                }
                times=ideal_time;
          }

    }
    //USER
    n=uscnt;
	while(k<=syscnt+uscnt)
    {
     ideal_time=timeu+1;
     flag=0;
      for(j=1;j<=n;j++)
      {
          if(obju[j].process_arrival<=timeu)
          {
              res[k].final_pno=obju[j].pno;
              timeu=timeu+obju[j].process_burst;
                for(i=j;i<n;i++)
                {
                   obju[i]=obju[i+1];
                }
                n--;
                k++;
                flag=1;
            break;
          }

      }
        if(flag==0)
        {
                for(i=1;i<=n;i++)
                {
                    if(obju[i].process_arrival<ideal_time && ideal_time>timeu )
                    {
                        ideal_time=obju[i].process_arrival;
                    }
                }
                times=ideal_time;
          }

    }
            printf("\n\n\nPROCESS\n");
        for(i=1;i<=syscnt+uscnt;i++)
        {
            printf("\nP%d",res[i].final_pno);

        }

    return 0;
}
