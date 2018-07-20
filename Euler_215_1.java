import java.util.Scanner;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;

class Euler_215
{
    static int g=0,p=0;
   
static void combine(int clayer[][],List<int[]> layer,int w,int h,int level)
{
    
    int i,j;
    int c=0;
    if(level==h)
    {
        /*
        for(i=0;i<h;i++)
        {
            print_array(clayer[i]);

        }
        */

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
    for(j=0;j<g;j++)
    {
        if(level>=1)
        {
            if(clayer[level-1]==layer.get(j))
            {
                continue;
            }
        }

        clayer[level]=layer.get(j);
        combine(clayer,layer,w,h,level+1);      
    }
    
}


static int checkcrack(int clayer[][],int w,int h)
{
    int i,j;
    
    for(i=1;i<(w-1);i++)
    {
        int wall =0;
        for(j=0;j<(h-1);j++)
        {
            wall = clayer[j][i] + clayer[j+1][i];
            if(wall > 1)
            {
                return 1;
            }
        }
        // printf("wall = %d \n",wall);

        
            
    }
    return 0;


}

    static int findabarry(int a[],int b[],int w)
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
                a[j]= i;
                b[j] = (rem/2);
                j++;
            }
        }
        return j;
    
    
    }
   static  void create_layer_from_array(List<int[]> layer,int array[],int w,int size)
{
    int i;
    int k=0;
    int j;
    int  [] array2= new int [w];
    for(j=0;j<w;j++)
        {
            array2[j]=0;
        }
    array2[0]=1;
    for(i=0;i<size;i++)
    {
        

        k=k+array[i] ;
        // *(array+i)
        array2[k]=1;
    }
    layer.add(array2);

}
    static void print_array(int array[])
    {
        for(int k=0;k<array.length;k++)
        {
            System.out.print(array[k]+" ");
        }
        System.out.println();
    }

    static void print_layer(List<int[]> layer)
    {
        for(int i=0;i<layer.size();i++)
        {
            print_array(layer.get(i));
        }
    }
    static void create_array(int a[],int b[],List<int[]> layer,int j,int w)
    {
        int i;
        for(i=0;i<j;i++)
        {
            int[] blocks={3,2};
            int[] count={a[i],b[i]};
            int size=0;
            size = a[i]+b[i];
            int array[]=new int[size];
            permute(blocks,count,size,array,0,layer,w+1);
        }

    }
    static void permute(int blocks[],int count[],int size,int array[],int level,List<int[]> layer,int w)
    {
        if (level == size) 
            {
                          
                create_layer_from_array(layer,array,w,size);
                // int  [] array2= new int [size];
                //array2 = Arrays.copyOf(array, size);
                //layer.add(array2);
                g++;
                return;
            }
        for(int i = 0; i <2 ; i++) {
                if(count[i] == 0) 
                {
                    continue;
                }
                array[level] = blocks[i];
                count[i]--;
                permute(blocks, count, size,array, level + 1,layer,w);
                count[i]++;
            }

    }


    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int w = sc.nextInt();
        int h = sc.nextInt();
        int m = sc.nextInt();
        List<int []> layer = new ArrayList<>();
        int a[],b[],j;
        a = new int[50];
        b = new int[50];

        j= findabarry(a,b,w);
        int i;
        /*
        for (i=0;i<j; i++)

        {
            System.out.println(a[i]+" "+b[i]);
        }
        */
        create_array(a,b,layer,j,w);
        //print_layer(layer);
        int clayer[][] = new int[h][w+1];
        combine(clayer,layer,(w+1),h,0);
        System.out.println(p%m);


        
    }
}