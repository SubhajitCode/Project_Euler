class combine
{
    static int l=0;
    static int i=0;
    static void print_array(char result[])
    {
        for(int j=0;j<result.length;j++)
        {
            System.out.print(result[j]+" ");
        }
        System.out.println();
    }
    static void combineUtil(char result[],int size,int level)
    {
        if(level == size)
        {

            print_array(result);
            l++;
            return;

        }
        for(int k = 0; k <6; k++)
        {
            if(level>=1)
            {
                if(result[level-1]==get(k))
                {
                    continue;
                }
            }
            result[level]=get(k);
            combineUtil(result,size,level+1);
        }


    }
    static char get(int i)
    {
    
        return array[i];
    }
    
    static char[] array = {'A','B','C','D','E','F'};
    static char[] result = new char[4];
    public static  void main(String args[])
    {
        int size =4;
        combineUtil(result,size,0);
        System.out.println(l);
        
    }
}