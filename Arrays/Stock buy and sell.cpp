//PC -> 4
void stockBuySell(int price[], int n) {
    bool check = 0;
    int i=0;
    while(i<n-1){
            while(i<n-1 && price[i]>=price[i+1])
                    i++;
            if(i==n-1){
                break;
            }
                
            int buy = i++;
            while(i<n && price[i]>=price[i-1] )
                    i++;
            int sell = i-1;
            check = 1;
            cout<<"("<<buy<<" "<<sell<<") ";
    }
    if(!check)
        cout<<"No Profit";
    cout<<endl;
}
