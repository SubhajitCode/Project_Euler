for(i=0;i<h;i++)
        {
        
            for(j=0;j<w;j++)
            {
                clayer[i][j]= *(layer+(0*w)+j);
            }

        }
        printf("\n \n printing combination \n \n");
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
            printf("%d ", clayer[i][j]);
            }
            printf("\n");

        }
        c = checkcrack(&clayer,w,h);
        if(c==1)
        {
            printf("\n--------------------cracked wall found --------------- \n");
        }
        else
        {
            printf("\n------no crackk------ \n");
        }