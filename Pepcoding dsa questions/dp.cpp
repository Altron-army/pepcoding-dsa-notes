// basic
vector<vector<int>> dp(m, vector<int> (n,-1)); 
int res=help(arr,m-1, amt,dp);
vector<int> dp(n,-1);


// one dimension

int help(int n, vector<int>& dp) {
if(n<=2) return n;
if(dp[n]!=-1) return dp[n];
return dp[n]=help(n-1,dp)+help(n-2,dp);
}
// fib
int fib(int n) {
if(n==0 || n==1)
return n;
int prev = 1;
int prev2 = 0;
for(int i=2;i<=n;i++)
{int curr= prev + prev2;
prev2= prev;
prev =curr; 
}
return prev

// climbStairs

int climbStairs (int n) {
SC = 0 (1)
int next2=0;
int next1=1;
for(int CurrInd = n-1; CurrInd>=0; CurrInd--)
{ int steps= next1 + next2;
next2 =next1;
next1 = steps;
}
return next1
}

// frogJump

int frogJump(int n, vector<int> &heights)
{
int next2 = 100000;
int next = 0;
for(int CurrInd =n-2; CurrInd>=0; CurrInd--)
{ int stepone = abs (heights [CurrInd+1]-heights [CurrInd]) + next;
int steptwo= abs(heights [CurrInd+2]-heights [CurrInd]) + next2;
next2 =next;
next = min(stepone, steptwo);
}
return next
}

// frogJump variation

int frogJump(int k,int n, vector<int>& heights)
{
vector<int> dp(n+1,0);
dp[n] = 100000;
dp[n-1] = 0;
for(int CurrInd =n-2; CurrInd>=0; CurrInd--)
{ int mincost = INT_MAX;
for(int i=1;i<=k && i<n; i++)
{ 
    int stepk = abs(heights [CurrInd+i]-heights [CurrInd]) + dp[CurrInd+i];
     mincost= min(stepk,mincost);
}
dp[CurrInd] = mincost;
}
return dp[0]
}

// house rob

int rob(vector<int>& nums) {
int n=nums.size();
int next2 =0;
int next = nums [n-1];
for(int currentindex =n-2; currentindex>=0; currentindex--){
int rob = nums [currentindex] + next2;
int dontrob = next;
int curramount= max(rob, dontrob);
next2 = next;
next = curramount;
}
return next:
}

// findMaxSum
int findMaxSum(int *arr, int n) {
int incl=0;
int excl=0;
for(int i=0;i<n;i++)
{ int ni = arr[i] + excl;
int ne = max(incl,excl);
incl = ni;
excl = ne;
}
return max(incl,excl)
}
// houserobber2

int houserobberl(int currindex, int target, vector<int>& nums) {
int next2 =0;
int next = nums [currindex];
for(int currentindex = currindex-1; currentindex>=target; currentindex--){
int rob nums [currentindex] + next2;
int dontrob = next;
int curramount= max(rob, dontrob);
next2 = next;
next = curramount;
}
return next;
}
// ninjaTraining

int ninjaTraining(int n, vector<vector<int>> &points)
{ vector<int> prev(4,0);
prev [0] = max(points[n-1][1], points [n-1][2]);
prev [1] =max(points[n-1][0], points [n-1][2]);
prev [2] =max(points[n-1][0], points [n-1][1]);
prev [3] =max(prev [2], prev[0]);
for(int currday = n-2; currday>=0; currday--)
{ vector<int> temp(4,0);
for(int lasttask = 3; lasttask>=0; lasttask--)
{ for(int i=0;i<=2;i++){
if(i!=lasttask){
int reward = points [currday] [i] + prev[i];
temp[lasttask] = max(temp[lasttask], reward);
}
}
}
prev=temp;
}
return prev[3]
}

// uniquePaths

int uniquePaths(int m, int n) {
vector<int> next(n,1);
for(int CurrRow=m-2; CurrRow>=0; CurrRow--)
{ 
 vector<int> curr(n,0);
curr[n-1] = 1;
for(int CurrCol=n-2;CurrCol>=0; CurrCol--)
{
 int movedown=0,moveright=0;
movedown = next [CurrCol];
moveright = curr [CurrCol+1];
curr [CurrCol] = movedown + moveright;
}
next= curr;
}
return next[0].
}

// or uniquePaths

int uniquePaths(int m, int n) {
//it will done using combinatorics
// ncr, where n is the number of steps require, r is the arrangement of these steps.
// TCO(m-1) or (n-1)
int Number_of_steps = n+m-2; // (m-1) + (n-1)
int rm-1; // ог п-1;
double totalpaths = 1;
for(int i = 1; i<=r;i++)
{
totalpaths= totalpaths*(Number_of_steps-r+i)/i;
}
return (int)totalpaths
}

// uniquePathsWithObstacles

int uniquePathsWithObstacles (vector<vector<int>>& obstacleGrid) {
int m obstacleGrid.size();
int n obstacleGrid[0].size();
vector<double> next(n,0);
for(int CurrRow=m-1; CurrRow>=0; CurrRow--)
{ vector<double> curr(n,®);
for(int CurrCol=n-1; CurrCol>=0; CurrCol--)
{f(CurrRow ==m-1 && CurrCol=n-1 && obstacleGrid [CurrRow]
[CurrCol]==0)
curr[CurrCol]=1;
else if(obstacleGrid [CurrRow] [CurrCol]==1)
curr [CurrCol]=0;
else { double movedown=0;
double moveright =0;
Lf(CurrRow<m-1)
movedown = next [CurrCol];
if(CurrCol<n-1)
moveright = curr [CurrCol+1];
curr [CurrCol] = movedown+moveright;
}
}
next = curг;
}
return next[0]
}

// minPathSum

int minPathSum(vector<vector<int>>& grid) {
int rowsize = grid.size();
int colsize = grid[0].size();
vector<int> next(colsize, INT_MAX);
for(int CurrRow=rowsize-1; CurrRow>=0; CurrRow--)
{ vector<int> curr(colsize, INT_MAX);
for(int CurrCol = colsize-1; CurrCol>=0;CurrCol--)
{
if(CurrRow==rowsize-1 && CurrCol==colsize-1)
curr[CurrCol]=grid [CurrRow] [CurrCol];
else{
int movedown=INT_MAX; int moveright=INT_MAX;
if(CurrRow<rowsize-1)
movedown = next [CurrCol];
if (CurrCol<colsize-1)
moveright = curr [CurrCol+1];
curr [CurrCol] = grid [CurrRow] [CurrCol] + min(movedown, moveright);
}
}
next = curr;
}
return next[0];
}



// minimumTotal

int minimumTotal(vector<vector<int>>& triangle) {
int rowsize = triangle.size();
int colsize = triangle [rowsize-1].size();
vector<int> next(rowsize,0);
vector<vector<int>> dp(rowsize, vector<int> (colsize,®));
for(int i=0;i<colsize; i++)
next[i] = triangle [rowsize-1][i];
for(int CurrRow = rowsize-2; CurrRow>=; CurrRow--)
{ vector<int> curr(rowsize,);
for(int CurrCol = CurrRow; CurrCol>=@; CurrCol--)
{
int onestep next [CurrCol];
int twostep = next [CurrCol+1];
curr[CurrCol] = triangle [CurrRow] [CurrCol] + min(onestep, twostep);
}
next = curr;
}
return next[0]
}

// minFallingPathSum

int minFallingPathSum(vector<vector<int>>& matrix) {
int n matrix.size();
vector<int> next(n,0);
for(int i=0;i<n; i++)
{ next[i]= matrix[n-1][i];
}
for(int CurrRow =n-2; CurrRow>=0; CurrRow--)
{ vector<int> curr(n,0);
for(int CurrCol=n-1; CurrCol>=@;CurrCol--)
{ int down INT_MAX; int downleft = INT_MAX; int downright INT_MAX;
down = next [CurrCol];
(CurrCol>)
downleft = next [CurrCol-1];
LT(CurrCol<n-1) downright = next [CurrCol+1];
curr[CurrCol] = matrix [CurrRow] [CurrCol] + min (down, min (downleft, downright));
}
next = curr;
}
int mini = INT_MAX;
for(int i=0; i<n; i++)
{ 
    mini = min(mini, next[i]);
}
return mini
}

// cherryPickup

int cherryPickup(vector<vector<int>>& grid) {
int dp[50][50][50];
memset(dp,-1,sizeof(dp));
return max(8, maxcherry(, 8, 8, grid, dp));
}
int maxcherry(int ri, int c1, int r2, vector<vector<int>>& grid, int dp[58][50][50]) {
int cherries = 0;
int c2=r1+c1-r2;
int n grid.size();
if(r1>=n || r2>n || c1 >=n || c2 >=n || grid[rl] [c1]=-1 || grid[r2] [c2] == -1)
return -100000;
if(dp[rl][cl][r2]!=-1){
return dp[r1][cl][r2];
}
if((r1==n-1) && (c1==grid[8].size()-1))
return grid[r1][cl];
if(r1 r2 || c1==c2) cherries+=grid[r1][cl];
elsecherries+= grid[r1][cl]+grid[r2][c2];
int rr=maxcherry(r1,c1+1, r2,grid,dp);
int rd=maxcherry (r1,c1+1, r2+1,grid, dp);
int dd=maxcherry (r1+1,c1,r2+1,grid,dp);
int dr=maxcherry (r1+1,c1, r2,grid,dp);
cherries+= max({rr,rd,dd,dr});
dp[r1][c1][r2]=cherries.
return cherries
}

// subsetSumTok

bool subsetSumTok(int n, int k, vector<int> &nums) {
vector<bool> next(k+1,0);
next[0]=1;
if(nums[n-1]<=k)
next[nums[n-1]] = true;
for(int currind=n-2;currind>=0;currind--)
{ vector<bool> curr(k+1,0);
curr[0]=1;
for(int target=k; target>=1;target--)
{ bool consider = false;
if(target>=nums[currind])
consider next [target-nums[currind]];
bool notconsider = next[target];
curr[target] = consider + notconsider;
}
next = curr;
return next[k];
}

// canPartition

bool canPartition(vector<int>& nums) {
int n = nums.size();
int sum=0;
for(int i=0; i<n; i++)
sum+=nums[i];
Lf(sum%2!=0)
return false;
vector<bool> next(sum/2+1,0);
next[0]=1;
T(nums [n-1]<=sum/2)
next[nums [n-1]] = true;
for(int currind=n-2;currind>=0;currind--)
{ vector<bool> curr(sum/2+1,0);
for(int target=sum/2;target>=@; target--)
{ bool consider = false;
if(target>=nums[currind])
consider = next [target-nums [currind]];
bool notconsider = next[target];
}
curr[target] = consider + notconsider;
next = curr;
}
return next[sum/2];
}

// minSubsetSumDifference

int minSubsetSumDifference(vector<int>& nums, int n)
{
int k=0;
for(int i=0; i<n; i++)
{
    k+=nums[i];
}
vector<bool> next(k+1,0);
next[0]=1;
if(nums[n-1]<=k)
next[nums[n-1]] = true;
for(int currind=n-2;currind>=; currind--)
{ vector<bool> curr(k+1,0);
for(int target=k; target>=0; target--)
{ bool consider = false;
if(target>=nums[currind])
consider =next [target-nums[currind]];
bool notconsider=next[target];

curr[target] = consider+ notconsider;
}
next = curr;
}
int mini = le9;
for(int sl=0;sl<=k/2;s1++)
{
if(next [sl]==true)
{ 
    int s2=k-s1;
mini = min(mini,abs(s2-s1));
}
return mini
}

// findWays

int findWays (vector<int> &nums, int tar)
{ int n= nums.size();
vector<int> next(tar+1,0);
(nums[n-1]==)
next[0]=2;
else next[@]=1;
f(nums[n-1]!= && nums[n-1]<=tar)
next[nums[n-1]]=1;
for(int currind=n-2;currind>=0;currind--)
{ for(int target=tar; target>=; target--)
{ int pick = 0;
f(nums[currind]<=target)
pick = next[target-nums[currind]];
int notpick = next [target];
}
next[target] = pick+notpick;
}
}
return next[tar]
}

// countways

int mod =(int)(1e9 + 7);
int countways(int tar, vector<int>& nums)
int n= nums.size();
vector<int> next(tar+1,0);
if(nums[n-1]==0)
next[0]=2;
else next[0]=1;
if(nums[n-1]!= && nums[n-1]<=tar)
next[nums[n-1]]=1;
for(int currind=n-2; currind>=6;currind--)
{
     vector<int> curr(tar+1,0);
for (int target=tar; target>=;target--)
{ 
int pick = 0;
if(nums[currind]<=target)
pick next[target-nums[currind]];
 int notpick= next[target];
curr[target] = (pick+notpick)%mod;
}
next = curr;
}
return next[tar];
}
int countPartitions(int n, int d, vector<int> &arr)
int totalsum = 0;
for(int i=0;i<n; i++)
totalsum+=arr[i];
((totalsum-d)< || (totalsum-d)%2!=)
return 0;

}

// knapsack

int knapsack(vector<int>& wt, vector<int>& profit, int n, int W)
(
     vector<int> next(W+1,0);
for(int i=wt[n-1]; i<=W;i++) next[i]= profit[n-1];

for(int currind-n-2;currind>=0;currind--)
{
vector<int> curr(W+1,0);
for(int capacity-W;capacity>=0;capacity--)
int notconsider next[capacity];
int consider = INT_MIN;
(wt[currind]<=capacity)
consider profit= [currind] + next[capacity-wt[currind]];
}
curr[capacity] = max(consider, notconsider);
next = curr;
}
return next[W];
}

// minimumElements

int minimumElements(vector<int> &coins, int x)
{
int n = coins.size();
vector<int> next(x+1,0);
for(int i=0; i<=x; i++)
{
if(i%coins [n-1]=)
next[i] = (i/coins [n-1]==0);
else
next[i] =le9;
for (int currind=n-2;currind>=;currind--)
for(int price=0;price<=x; price++)
{int notconsider =next [price];
int consider = le9;
(coins[currind]<=price)
consider = 1 + next [price-coins [currind]];
next[price] = min(consider, notconsider);
}
}
int ans=next[x];
(ans>=189) return -1
else ans
}

// countWaysToffakeChange

Lang countWaysToffakeChange(int denominations, int n, int value)
{ 
    vector<long> next(value+1,0);
for (int i=0; i<value; i++) next[i]=(idenominations[n-1]);

for (long currind-n-2;currind;currind--)
t
for(long price; price value;price++)
{ long notpick
Long pick
next[price];
(denominat Lons[currind]<=price)
pick = next [price-denominations[currind]];
next[price]= pick notpick;
// two dimension 

int help(vector<int> &arr, int m, int n, vector<vector<int>> & dp)
{
if(m==-1 or n<=0)
{
if(n==0) return 0; else return INT_MAX-1;
}
if(dp[m][n]!=-1) return dp[m][n];
if(arr[m]>n) return dp[m][n]=help(arr,m-1,n,dp);
return dp[m][n]=min(1+help(arr,m,n-arr[m], dp), help(arr,m-1,n,dp));
}

// numberOfArithmeticSlices

int numberOfArithmeticSlices (vector<int>& arr)
 {
     int ans=0,n=arr.size(); 
     if(arr.size()<3) return 0; 
     vector<int> dp(n,0); 
     for(int i=2;i<arr.size(); i++)
{
if((arr[i]-arr[i-1]) == (arr[i-1]-arr[i-2]))
{
dp[i]=dp[i-1]+1; ans+=dp[i];
}
}
return ans;

// buy  and sell

{
int help(vector<int> &arr, int index, int buy, vector<vector<int>> &dp)
if(index>=arr.size()) return 0;
if(dp[index] [buy]!=-1) return dp[index] [buy];
int buykaro=0, sellkaro=0;
if(buy)
{
return dp[index] [buy]=max(-arr[index]+help(arr, index+1,0,dp), 1p(arr, index+1,1,dp));
}
else return dp[index] [buy]=max(arr[index]+help(arr, index+2,1,dp), help r, index+1,0,dp));
//return dp[index] [buy]=max(buykaro, sellkaro);
}
int maxProfit(vector<int>& arr) { vector<vector<int>> dp(n, vector<int> (2,-1));
int n=arr.size();
return help(arr,0,1,dp);
}


// buy sell and limit

int help(vector<int> &arr, int i, int buy, int n, vector<vector<vector<int>>> &dp, int limit)
{
if(i==n) return 0; if(limit==0) return 0;
if(dp[i][buy] [limit]!=-1) return dp[i][buy] [limit]; int profit=0;
if(buy)
{
int buykaro=-arr[i]+help(arr, i+1,0,n,dp,limit); int skipkaro=0+help(arr,i+1, 1, n, dp, limit); profit=max(buykaro, skipkaro);
}
else
{
int buykaro=arr[i]+help(arr, i+1,1,n,dp,limit-1); int skipkaro=0+help(arr,i+1,0,n, dp, limit); profit=max(buykaro, skipkaro);
}
return dp[i] [buy] [limit]=profit;
}

int maxProfit(vector<int>& arr) {
int n=arr.size(); vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>
(3, -1)));
return help(arr,0,1,n,dp, 2);
}

// buy sell and size

int solve(int i, int buy, int sz, vector<int>& p, vector<vector<vector<int>>>&dp)
{
if(sz==0)return 0;
if(i>=p.size ()) return 0;
if(dp[i][buy] [sz]!=-1) return dp[i] [buy][sz];
if(buy) {
dp[i][buy] [sz]=max(-p[i]+solve(i+1,0,sz,p,dp), solve(i+1,1,sz,p,dp));
}
else{
dp[i][buy][sz]=max(p[i]+solve(i+1,1, sz-1,p,dp), solve(i+1,0,sz,p,dp));
}
return dp[i][buy][sz];
}
int maxProfit(vector<int>& prices) {
vector<vector<vector<int>>>dp(prices.size(), vector<vector<int>>(2,
vector<int>(3,-1)));
return solve(0,1,2, prices,dp);
}
};

// longestNonDecreasingSubsequence

    int longestNonDecreasingSubsequence(const vector<int>& arr) {
        vector<int> sub;
        for (int i = 0; i < arr.size(); ++i) {
            int x = arr[i];
            if (sub.empty() || sub[sub.size() - 1] <= x) { // Append to LIS if new element is >= last element in LIS
                sub.push_back(x);
            } else {
                int idx = upper_bound(sub.begin(), sub.end(), x) - sub.begin(); // Find the index of the smallest number > x
                sub[idx] = x; // Replace that number with x
            }
        }
        return sub.size();
    }

// longestPalindrome substring

string longestPalindrome (string s) { int n=s.length(), start=0, end=1,1,h;
for(int i=0;i<n;i++)
{
/////even
1=1-1;
h=i;
while(1>=0 and h<n and s[1]==s[h])
{
if(h-1+1>end)
{
start=1;
end=h-1+1;
}
1--;
h++;
}
//odd
1=1-1;
h=i+1;
while(1>=0 and h<n and s[1]==s[h])
{
if(h-1+1>end)
{
start=1;
end=h-1+1;
}
1--;
h++;
}

// palindrome partition

void help(string s, vector<string> temp,vector<vector<string>> &ans)
{
if(s.size()==0)
{
ans.push_back(temp); return;
}
for(int len=1;len<=s.size(); len++)
{
string 1=s.substr(0,len); if(ispalindrome (1))
{
temp.push_back(1);
s.substr(len,s.size()-len), temp, ans); temp.pop_back();
}
}
}

// numSquares

int dp[10001];
int help(int n)
{
if(n==0) return 0;
if(dp[n]!=-1) return dp[n];
 int ans=n; for(int i=1;i*i<=n;i++)
{
int temp=i*i; ans=min(ans, 1+help(n-temp));
}
dp[n]=ans; return dp[n];
}
int numSquares(int n) {
int res=help(n);
}


// maxJumps

int dfs(int i, int n, vector<int> &arr, int d, vector<int> &dp) {
if(dp[i] != -1) return dp[i];
int left = 0, right = 0;
for(int 1=i-1; 1>=0 && 1>=i-d; 1--) {
if(arr[i] <= arr[1]) break;
left = max(left, dfs(1, n, arr, d, dp));
}
for(int r=i+1; r<n && r<=i+d; r++) {
if(arr[i] <= arr[r]) break;
right = max(right, dfs(r, n, arr, d, dp));
}
return dp[i] = 1 + max(left, right);
}
public:
int maxJumps(vector<int> & arr, int d) {
int n = arr.size(), ans = 0;
vector<int> dp(n, -1);
for(int i=0; i<n; i++) {
ans = max(ans, dfs(i, n, arr, d, dp));
}
return ans;
}


// count binary string with no 0's consecutive

 int zeroes = 1;
    int ones = 1;

    for (int i = 2; i <= n; i++) {
        int nzeroes = ones;
        int nones = ones + zeroes;

        zeroes = nzeroes;
        ones = nones;
    }

    std::cout << zeroes + ones << std::endl;

//  Arrange buildings


     long long ob = 1;
    long long os = 1;

    for (long long i = 2; i <= n; i++) {
        long long nb = os;
        long long ns = os + ob;

        ob = nb;
        os = ns;
    }

    long long total = ob + os;
    std::cout << total * total << std::endl;

//  count encoding "12" a or 12 check value 

  int n = str.length();

    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++) {
        if (str[i - 1] == '0' && str[i] == '0') {
            dp[i] = 0;
        } else if (str[i - 1] == '0' && str[i] != '0') {
            dp[i] = dp[i - 1];
        } else if (str[i - 1] != '0' && str[i] == '0') {
            if (str[i - 1] == '1' || str[i - 1] == '2') {
                dp[i] = (i >= 2 ? dp[i - 2] : 1);
            }
        } else {
            dp[i] = dp[i - 1];
            if (stoi(str.substr(i - 1, 2)) <= 26) {
                dp[i] += (i >= 2 ? dp[i - 2] : 1);
            }
        }
    }

//count subsequence of _a_ +_b_ +_c_ 

 int a = 0, ab = 0, abc = 0;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == 'a') {
            a = 2 * a + 1;
        } else if (ch == 'b') {
            ab = 2 * ab + a;
        } else if (ch == 'c') {
            abc = 2 * abc + ab;
        }
    }

    cout << abc << endl;





