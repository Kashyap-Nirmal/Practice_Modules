/*
    https://practice.geeksforgeeks.org/problems/union-of-two-arrays3538/1
    20-01-21
    Submitted
*/
//Driver code
int doUnion(int a[], int n, int b[], int m)  {
    int iter;
    set<int> s;
    /*
        Logic:
            -I have used set to avoid checking of elements present or not.
            -Firstly the larger array needs to be inserted without checking.
            -Then secondly the smaller array is inserted into set after checking their availability.
            Using the find function
    */
    if(m>n)
    {
        for(iter=0;iter<m;iter++)
            s.insert(b[iter]);
        for(iter=0;iter<n;iter++)
            if(s.find(a[iter])==s.end())
                s.insert(a[iter]);
    }
    else
    {
        for(iter=0;iter<n;iter++)
            s.insert(a[iter]);
        for(iter=0;iter<m;iter++)
            if(s.find(b[iter])==s.end())
                s.insert(b[iter]);
    }
    return(s.size());
}
