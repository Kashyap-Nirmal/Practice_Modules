/*
	https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
	Submitted
	05-01-21
*/

//{}Driver Code Ends

void sort012(int a[],int n)
{
    int iter,count_0=0,count_2=n-1,flag=0;
    int sorted_array_[n];
    for(iter=0;iter<n;iter++)
    {
        if(flag==0 & iter<=count_2)
            sorted_array_[iter]=1;
        else if(iter>count_2)
            flag=1;
        /*
            Dont use else if. Because then these conditions wont be executed.
        */
        if(a[iter]==0)
        {
            sorted_array_[count_0]=0;
            count_0++;
        }
        else if(a[iter]==2)
        {
            sorted_array_[count_2]=2;
            count_2--;
        }
    }
    for(iter=0;iter<n;iter++)
    {
        a[iter]=sorted_array_[iter];
    }
}
