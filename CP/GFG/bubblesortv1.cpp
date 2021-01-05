/*
    https://practice.geeksforgeeks.org/problems/bubble-sort/1
    Submitted
    05-01-21
*/

//{} Driver Code Ends

void bubble(int arr[], int i, int n)
{
    int iter=0,iter1=0,temp,flag=0;
    int count_=0,swap_count_=0;
    for(iter=0;iter<n;iter++)
    {
        if(flag==0 & iter >0)
            break;
        for(iter1=0;iter1<n-iter-1;iter1++)
        {
            if(arr[iter1]>arr[iter1+1])
            {
                temp=arr[iter1+1];
                arr[iter1+1]=arr[iter1];
                arr[iter1]=temp;
                flag=1;
            }
        }
    }
}
