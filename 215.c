//project euler 215

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
unsigned long g=0;
int p=0;

void combine(int *clayer,int *layer,int w,int h,int level)
{
    
    int i,j,k;
    int c=0;
    if(level==h)
    {
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
          // printf("%d ", *(clayer+(i*w)+j));
            }
           //printf("\n");

        }
        // p++;
        //printf("%d \n",p);
        c = checkcrack(clayer,w,h);
        if(c==1)
        {
           // printf("\n--------------------cracked wall found --------------- \n");
        }
        else
        {
           // printf("\n------no crackk------ \n");
            p++;
        }
        return;
    }
    for(i=0;i<g;i++)
    {
        for(j=0;j<w;j++)
        {
           *(clayer+(level*w)+j)= *(layer+(i*w)+j);
        }
        combine(clayer,layer,w,h,level+1);      
    }
    
}


int checkcrack(int *clayer,int w,int h)
{
    int i,j;
    
    for(i=1;i<(w-1);i++)
    {
        int wall =0;
        for(j=0;j<(h-1);j++)
        {
            wall = (*(clayer+(j*w)+i))+(*(clayer+((j+1)*w)+i));
            if(wall > 1)
            {
                return 1;
            }
        }
        // printf("wall = %d \n",wall);

        
            
    }
    return 0;


}

void permute(int *blocks,int *count,int size,int *array,int level,int *layer,int w)
{
    if (level == size) 
        {
            print_array(array,size);
            create_layer_from_array(array,size,layer,g,w);
            g++;
            return;
        }
    int i;
    for(int i = 0; i <2 ; i++) {
            if(*(count+i) == 0) 
            {
                continue;
            }
            *(array+level) = *(blocks+i);
            (*(count+i))--;
            permute(blocks, count, size,array, level + 1,layer,w);
            (*(count+i))++;
        }

}
void create_layer_from_array(int *array,int size,int *layer,int pos,int w)
{
    int i;
    int k=0;
    int j;
    for(j=0;j<w;j++)
        {
            *(layer+(pos*w)+j)=0;
        }
    *(layer+(pos*w))=1;
    for(i=0;i<size;i++)
    {
        

        k=k+*(array+i) ;
        // *(array+i)
        
        *(layer+k+(pos*w))=1;
    }

}

unsigned long fact(int n)
{
    int i;
    unsigned long m=1;
    for(i=1;i<=n;i++)
    {
      m=m*i;
    }
    return m;
}

void print_layer(int *layer,int w,int k)
{
    int i;
      for(i=0;i<(w);i++)
        {
           // printf("%d " ,*(layer+k*(w)+i));
        }
        
       // printf("\n");
}

void print_array(int *array,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
       // printf("%d ",*(array+i));
    }
   // printf("---- %d",g);
  //  printf("\n");
}

void create_array(int *a,int *b,int *layer,int j,int w)
{
    int i;
    for(i=0;i<j;i++)
    {
        int blocks[2]={3,2};
        int count[2]={*(a+i),*(b+i)};
        int size=0;
        size = *(a+i)+*(b+i);
        int array[size];
        permute(&blocks,&count,size,&array,0,layer,w);
     }

}

void constuct_layers(int *a,int *b,int *layer,int j,int w)
{
    create_array(a,b,layer,j,w+1);
}
 int findabarry(int *a,int *b,int w)
{
    int i;
    int rem,mod;
    int j =0;
    for (i= 0; i<=(w/3) ;i++)
    {
        rem=(w-(i*3));
        mod = rem %2;
        if (mod==0)
        {
            *(a+j)= i;
            *(b+j) = (rem/2);

            //printf("%d  %d \n",a[j],b[j]);
            j++;
        }
    }
    return j;


}
int main()
{
    int w,h, m;
    scanf("%d %d %d",&w,&h,&m);
    int a[50],b[50],j;
    j=findabarry(&a,&b,w);
    int i;
    for (i=0;i<j; i++)

    {
      // printf("%d  %d  \n",a[i],b[i]);
    }
    unsigned long layer_size=0;
    for (i=0;i<j; i++)

    {
       layer_size = layer_size + (fact(a[i]+b[i])/(fact(a[i])*fact(b[i])));
    }
   // printf("%d    \n",layer_size);
    int layer[layer_size][(w+1)];
     memset( layer, sizeof( layer ), 0 );
    constuct_layers(&a,&b,&layer,j,w);
    int k;


   for(k=0;k<layer_size;k++)
   {
       print_layer(&layer,(w+1),k);
     }
  // print_layer(&layer,(w+1),2);
  int clayer[h][w+1];
  combine(&clayer,&layer,(w+1),h,0);
  printf("%d \n",p);


    return 0;

}
