class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i =0,j=0,m=nums1.size(),n= nums2.size(),count=-1,median=0,ans,cur=0,prev=0;
        bool isEven=false;
        if((m+n)%2==0) isEven = true;
        median = (m+n)/2;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                cur = nums1[i];
                    i++;
            }else{
                cur = nums2[j];
                j++;
            }
            count++;
            if(count == median){
               if(isEven){
                    return double(cur+prev)/2;
               } else{
                   return cur;
               }
             }
            prev= cur;
        }
        while(i<m){
            cur = nums1[i];
            count++; 
            i++;
            if(count == median){
               if(isEven){
                    return double(cur+prev)/2;
               } else{
                   return cur;
               }
             }
            prev = cur;
            
        }
        while(j<n){
            cur = nums2[j];
            j++;
            count++; 
            if(count == median){
               if(isEven){
                    return double(cur+prev)/2;
               } else{
                   return cur;
               }
             }
            prev = cur;
        }
      return median;  
    }
};