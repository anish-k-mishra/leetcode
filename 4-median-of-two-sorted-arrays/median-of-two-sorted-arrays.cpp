class Solution {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        int m = num2.size();
        int s = m+n;
        float arr[s];
        int i=0,j=0,p=0;
        while(i<n && j<m){
            if(num1[i]<num2[j]){
                arr[p]=num1[i];
                
                i++;
            }
            else{
                arr[p]=num2[j];
                j++;
                
            }
            p++;

        }
        if(i == n){
            while(j<m){
                arr[p]=num2[j];
                j++;
                p++;
            }

        }
        else if(j ==m){
            while(i<n){
                arr[p]=num1[i];
                i++;
                p++;
            }
        }

        int b=s/2;
        //float arr[b-1];
        //float arr[b];
        //float h =(arr[b-1]+arr[b])/2;

        if(s%2==0){
            
            return (arr[b-1]+arr[b])/2;
        }
        else{
            return arr[b];
        }


    }
};