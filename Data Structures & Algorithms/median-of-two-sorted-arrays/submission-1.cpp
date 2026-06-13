class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (m==0 && n==0) return 0.0;
        if (m==0){
            if (n%2==0){
                return ((double)nums1[n/2]+(double)nums1[n/2-1])/2;
            }
            else return nums1[n/2];
        }
        else if (n==0){
            if (m%2==0){
                return ((double)nums2[m/2]+(double)nums2[m/2-1])/2;
            }
            else return nums2[m/2];
        }
        
        int l=0, r=n;
        double ans=0;
        while (l<=r){
            int mid = (l+r)/2;
            int l1 = -1e7,l2 = -1e7, r1 = 1e7, r2= 1e7;
            if (mid-1>=0){
                l1 =  nums1[mid-1];
            }
            if ((n+m)/2 - mid - 1 >=0){
                l2= nums2[(n+m)/2 - mid - 1];
            }
            if (n-mid>0){
                r1= nums1[mid];
            }
            if ((n+m)/2 - mid <m){
                r2= nums2[(m+n)/2 - mid];
            }
            if (l1<=r2 && l2<=r1){
                if ((m+n)%2==0){
                    ans = (max(l1,l2)+min(r1,r2))/(double)2;
                }
                else{
                    ans= min(r1,r2);
                }
                break;
            }
            // cout<<l1<<l2<<r1<<r2;
            if (l2 > r1) l=mid+1;
            else if (l1>r2) r = mid-1;
        }
        return ans;
    }
};
