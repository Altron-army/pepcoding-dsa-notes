
 //////////////////basic  

class Solution {
public:
    bool ispossible(int mid,vector<int>& arr, int k)
    {
        int n=arr.size(),c=0;
        for(int i=0;i<n;i++){ 
            if(arr[i]<=mid) 
            {
                c++;
                i++;
            }
        }
       return (c>=k);

    }
     int minCapability(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElement = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>maxElement)
                maxElement=nums[i];
        }
        int ans=maxElement;
        int low=0;
        int high=maxElement; 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(mid,nums,k)){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
///////// median two sorted array ////////

double findMedianSortedArrays (vector<int> & nums1, vector<int>& nums2)
 { // Create a single sorted by merging two sorted arrays
int n1=nums1.size();
int n2=nums2.size();
int i=0;
int j=0;
int lastindex=-1;
// Initialize a new array vector<int>v(n1+n2,0);
while(i<n1&&j<n2)
{
if(nums1[i]<=nums2[j])
v[++lastindex]=nums1[i++];
else
v[++lastindex]=nums2[j++];
}
while(i<n1)
v[++lastindex]=nums1[i++];
while(j<n2)
v[++lastindex]=nums2[j++];
// Return the result return n%2?v[n/2]: (v[n/2]+[n/2-1])/2.0;
int n=n1+n2;
}


///////// search  rotated array  ////////
int search(Vector<int>& arr, int tar) 
{
int 1=0, h=arr.size()-1;
while(1<=h)
{
int mid=(1+h)/2;
if(arr[mid]==tar) return mid;
else if(arr[1]<=arr[mid])
{
if(arr[1]<=tar and tar<arr[mid]) h=mid-1;
else 1=mid+1;
}
else
{
if(arr[mid]<tar and tar<=arr[h]) 1=mid+1; else h=mid-1;
}
}
return -1;
}

///////// first and last occurences ////////
{
int help1(vector<int> & arr, int x)
int 1=0,h=arr.size()-1; while(1<=h)
{
int mid=(1+h)/2;
if(arr[mid]==x)
{
if(mid==0 or arr[mid-1]!=arr[mid]) return mid;
else h=mid-1;
}
else if(arr[mid]<x) 1=mid+1;
}
else h=mid-1;
return -1;
}
int help2(vector<int>& arr, int x)
{
int 1=0, h=arr.size()-1,n=arr.size();
while(1<=h)
{
int mid=(1+h)/2;
if(arr[mid]==x)
{
if(mid==n-1 or arr[mid+1]!= arr[mid]) return mid; else 1=mid+1;
}
else if(arr[mid]<x) 1=mid+1;
}
else h=mid-1;
return -1;
}



///////// good subarray split ////////
class Solution {
bool good(int x, vector<int> &nums, int k) 
{ 
    int cnt = 1, s = 0, n = nums.size();
for(int i=0; i<n; i++) {
if(nums[i] > x) return false;
 s += nums[i];
if(s > x) {
cnt++;
s = nums[i];
if(cnt > k) return false;
}
}
return true;
}
public:
int splitArray(vector<int>& nums, int k) 
{
     int s = 0, e = 1e9, ans = INT_MAX; // for(int i nums) e += 1;
while(s <= e) {
int m = (s + e) / 2;
if(good(m, nums, k)) e = m - 1, ans = min(ans, m);
else s = m + 1;
}
return ans;
}
};




