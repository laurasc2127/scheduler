scheduler.c

int main()
{
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    //declaracion de las variables
    printf("Enter Total Number of Task:"); //numero total de procesos
    scanf("%d",&n);

    printf("\nEnter Burst Time and Priority\n"); //presionar el tiempo de prioridad
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1); //interrupcion del reloj
        scanf("%d",&bt[i]);
        printf("Priority:"); //prioridad
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contiene numero de procesos
    }


    //ordenando el tiempo de rafaga,la prioridad y el numero de proceso en orden ascendiente usando el orden de sellecion
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }

        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    wt[0]=0; //tiempo de espera del primer proceso es cero




    //calacular tiempo de espera
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];

        total+=wt[i];
    }

    avg_wt=total/n;  //tiempo de espera promedio
    total=0;

    printf("\nIdñ{-  \t Writing    \t Read     \t Listen"); //proceso,tiempo de espera,tiempo de respuesta
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calcular tiempo de respuesta
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }

    avg_tat=total/n;     //tiempo de respuesta promedio
    printf("\n\nAverage Waiting Time=%d",avg_wt); //tiempo de espera promedio
    printf("\nAverage Turnaround Time=%d\n",avg_tat); //tiempo de respuesta

	return 0;
}
