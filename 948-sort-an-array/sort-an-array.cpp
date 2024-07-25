class Solution {
public:
    void merge(vector<int>&v, int s, int e){
        int mid = s+ (e-s)/2;
        int n1 = mid-s+1;
        int n2 = e-mid;
        vector<int>v1;
        vector<int>v2;
        int k = s;
        for(int i = 0; i<n1; i++){
            v1.push_back(v[k]);
            k++;
        }
        k = mid+1;
        for(int i = 0; i<n2; i++){
            v2.push_back(v[k]);
            k++;
        }

        //merge 2 sorted arrays
        int i1 = 0;
        int i2 = 0;
        k = s;
        while(i1<n1 && i2<n2){
            if(v1[i1] < v2[i2]){
                v[k] = v1[i1];
                i1++;
            }
            else{
                v[k] = v2[i2];
                i2++;
            }
            k++;
        }
        while(i1<n1){
            v[k] = v1[i1];
            i1++;
            k++;
        }
        while(i2<n2){
            v[k] = v2[i2];
            i2++;
            k++;
        }
    }
    void mergeSort(vector<int>&v, int s, int e){
        if(s>=e){
            return ;
        }
        int m = s + (e-s)/2;
        
        //sort the left part
        mergeSort(v, s, m);

        //sort right part
        mergeSort(v, m+1, e);

        //merge the two arraays
        merge(v, s, e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;   
    }
};