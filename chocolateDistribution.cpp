class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
     sort(a.begin(), a.end());
     int min =  INT_MAX;
     int d;
     
     for(int i = 0; i+m-1 < n; i++)
     {
         d = a[i + m - 1] - a[i];
         
         if(d < min)
         {
            min = d;
         }
     }
     return min;
    
    }   
};

