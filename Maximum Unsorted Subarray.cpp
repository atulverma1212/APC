vector<int> Solution::subUnsort(vector<int> &arr) {
    int a=0,b=arr.size()-1;
    int pos=0;
    int i=0;
    vector <int> ptr;
    while(i<arr.size()-1 && arr[i]<=arr[i+1]){ a++; i++; }
    if(i==arr.size()-1){
        ptr.push_back(-1);
        return ptr;
    }
    i = arr.size()-1;
    while(i>0   &&   arr[i]>=arr[i-1]) {b--; i--; }
    int max=0,min=INT_MAX;
    for(int i=a;i<=b;i++)
    {
        if(arr[i]>max) max=arr[i];
        if(arr[i]<min) min=arr[i];
    }
    if(min<arr[a])
    {
        while(a>=0 && min<arr[a]) a--;
        a++;
    }
    if(max>arr[b])
    {
        while(b<arr.size() && max>arr[b]) b++;
        b--;
    }
    ptr.push_back(a);
    ptr.push_back(b);
    return ptr;
}
