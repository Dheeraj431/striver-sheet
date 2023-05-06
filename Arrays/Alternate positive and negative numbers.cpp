class Solution{
public:

	void rearrange(int arr[], int n) {
    vector<int>pos,neg;
    for(int i=0; i<n; i++){
        if(arr[i]>=0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    int pos_cnt = pos.size(),neg_cnt = neg.size();
    int p=0,ne=0;
    int i = 0;
    while(p < pos_cnt && ne < neg_cnt){
        if(i%2==0){
            arr[i] = pos[p];
            p++;
        }
        else{
            arr[i] = neg[ne];
            ne++;
        }
        i++;
    }
    while(ne < neg_cnt){
        arr[i] = neg[ne];
        i++;
        ne++;
    }
    while(p < pos_cnt){
        arr[i] = pos[p];
        i++;
        p++;
    }
}

};
