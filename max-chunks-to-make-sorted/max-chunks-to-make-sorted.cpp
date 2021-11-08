class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int chunks=0;
        int p[n];
        p[0]=arr[0];
        for(int i=1;i<n;i++){
            p[i]=max(p[i-1],arr[i]);
        }
        for(int i=0;i<n;i++){
            if(p[i]==i) chunks++;
        }
        return chunks;
    }
};