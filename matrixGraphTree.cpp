// basic
int m=arr.size(),n=arr[0].size();

for (int row = 0; row < m; row++){
for (int col = 0; col < n; col++){
}
int nrow[]={-1,0,1,0};
 int ncol[]={0,-1,0,1};
for(int i=0;i<4; i++)
{
int nr=row+nrow[i];
int nc=col+ncol[i];
if(nr>=0 and nr<m and nc>=0 and nc<n and ans[nr][nc]>ans[r][c]+1)
}

// nearest zero 

int m=ans.size(),n=ans[0].size();
 queue<pair<int, int>> q;
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
if(!ans[i][j]) q.push({i,j}); 
else ans[i][j]=INT_MAX;
}
}
while(!q.empty())
{
int r=q.front().first;
int c=q.front().second;
q.pop();
int nrow[]={-1,0,1,0};
 int ncol[]={0,-1,0,1};
for(int i=0;i<4; i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i];
if(nr>=0 and nr<m and nc>=0 and nc<n and ans[nr][nc]>ans[r][c]+1)
{
ans[nr][nc]=ans[r][c]+1; 
q.push({nr,nc});
}
}
}
return ans;

// Min path
int help(vector<vector<int>>& arr, vector<vector<int>>& dp, int m, int n)
 { 
    if(m==0 and n==0) return arr[m][n]; 
    if(m<0 or n<0) return 1e9; 
    if(dp[m][n]!=-1) return dp[m][n];
     return dp[m][n]=arr[m][n]+min(help(arr,dp,m-1,n), help(arr,dp,m,n-1));
}

// unique path  start to end 
int help(vector<vector<int>> &dp, int i,int j)
if(i==0 and j==0) return 1;
{ if(i<e or j<0) return 0; return dp[i][j]=help(dp,i-1,j)+help(dp,i,j-1);
if(dp[i][j]!=-1) return dp[i][j];
}

// longestIncreasingPath

int fun(int row, int col, vector<vector<int>> & mat, vector<vector<int>>
&dp) {
int n = mat.size(),m = mat[0].size();
int delrow[] = {-1,0,1,0};
int delcol[] = {0,1,0,-1};
int maxim = 0;
if(dp[row][col] != -1) return dp[row][col];
for(int i = 0; i < 4;i++) {
int drow=delrow[i] + row; 
int dcol=delcol[i] + col;
if(drow >= 0 && dcol >= 0 && drow < n && dcol < m && mat[drow][dcol] > mat[row][col]) 
{
maxim = max(maxim,1 + fun (drow,dcol,mat,dp));
}
}
return dp[row][col] = maxim;
}
int longestIncreasingPath(vector<vector<int>>& matrix) 
{
     int n = matrix.size(), m = matrix[0].size();
vector<vector<int>> dp(n, vector<int> (m,-1));
int ans = 0;
for(int i = 0; i < n; i++) {
for(int j = 0; j < m; j++) {
ans=max(ans, fun(i,j,matrix,dp));
}
}
return ans+1;
}

// countPaths

11 m,n;
11 mod=1e9+7;
11 dp[1005][1005],a[1005] [1005], vis[1005][1005];
11 dx[4]={1,-1,0,0};
11 dy[4]={0,0,1,-1}; 
void dfs(11 x,11 y){
if(vis[x][y])return;
vis[x][y]=1;
dp[x][y]=1;
for(11 i=0;i<4; i++){
11 x1=x+dx[i],y1=y+dy[i];
if(x1>=0 && x1 <m && y1>=0 && y1<n && a[x] [y] < a[x1][y1]){ dfs(x1,y1);
if(dp[x1][y1]){
dp[x][y]=(dp[x] [y] +dp[x1] [y1])%mod;
}
}
}
}
int countPaths (vector<vector<int>>& matrix)
 { 
    m=matrix.size();
     n=matrix[0].size();
      for(11 i=0;i<m; i++){ for(11 j=0;j<n;j++)
      { 
        a[i][j]=matrix[i][j];
         vis[i][j]=0;
dp[i][j]=0;
}
}
11 ans=0;
for(11 i=0;i<m;i++){
for(11 j=0;j<n;j++)
{ 
    if(vis[i][j]==0)
    {
         dfs(i,j);
}
ans=(ans+dp[i][j])%mod;
}
}
return ans;
}

// minFallingPathSum

int solve(int row, int col, vector<vector<int>> &matrix,
vector<vector<int>> &dp)
{
if(col<e || col>matrix[0].size()-1) return 1E9;
if(row==0) return matrix[row][col]; 
if(dp[row][col] != -1) return dp[row][col];
int up = matrix[row][col] + solve(row-1, col, matrix,dp);
int leftDiagonal = matrix[row][col] + solve(row-1,col-1, matrix,dp);
int rightDiagonal = matrix[row][col] + solve(row-1, col+1, matrix,dp);
 return dp[row][col] = min(up, min(leftDiagonal, rightDiagonal));
}
int minFallingPathSum(vector<vector<int>>& matrix) {
int ans = INT_MAX;
int n = matrix.size();
int m = matrix[0].size();
vector<vector<int>> dp(n, vector<int>(m,-1));
for(int i=0;i<m;i++)
{
ans = min(ans, solve(n-1, i, matrix,dp));
}
return ans;
}

// countSubIslands

int vis[500][500];
void DFS(int i, int j, vector<vector<int>>&grid1, vector<vector<int>>&grid2, bool &f)
{
if(i>=grid2.size()||j>=grid2[0].size()||ie||j<@||grid2[i][j]==0||vis[i][j]==1) return;
if(grid1[i][j]==0)
{
f = true;
return;
}
vis[i][j] = 1;
DFS(i+1,j,grid1, grid2,f);
DFS(i-1,j,grid1, grid2, f);
DFS(i,j+1,grid1, grid2,f);
DFS(i,j-1, grid1, grid2, f);
}
int countSubIslands (vector<vector<int>>& grid1, vector<vector<int>>&grid2) {
int n = grid1.size();
int m = grid1[0].size();
int ans = 0;
for(int i = 0; i<n; ++i)
{
for(int j = 0; j<m; ++j)
{
if(grid2[i][j]==1&&vis[i][j]==0)
{
bool f = 0;
DFS(i,j,grid1, grid2,f);
if(!f) ans++;
}
}
}
return ans;
}


// check containsCycle

vector<int> dir = { 0, 1, 0, -1, 0 };
bool isCyclic(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int x, int y)
{
visited[i][j] = true; for(int d = 0; d < 4; ++d)
{
int a = i+dir[d];
int b = j+dir[d+1];
if(a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() &&
grid[a][b] == grid[i][j] && !(x == a && y == b)) if(visited[a] [b] || isCyclic (grid, visited, a,b,i,j))
return true;
}
return false;
}
bool containsCycle(vector<vector<char>>& grid) {
int n = grid.size(), m = grid[0].size();
for(int i = 0; i < n; ++i)
vector<vector<bool>> visited(n, vector<bool>(m, false)); if(!visited[i][j] && isCyclic (grid, visited, i, j, -1, -1))
for(int j = 0; j < m; ++j)
return true;
}
return false;

// floodFill

bool isvalid(int x, int y, int m, int n)
{
if(x<0 or x>=m or y<e or y>=n) return false; return true;
}
void dfs(int sr, int sc, int color, vector<vector<int>>& grid, int gridCol)
{
if(isvalid(sr,sc,grid.size(),grid[0].size()) || grid[sr] [sc]!=gridCol|| grid[sr] [sc] ==color)return;
grid[sr][sc]=color;
int nrow[]={-1,0,1,0};
int ncol[]={0,-1,0,1};
for(int i=0;i<4;i++)
{
int nr=sr+nrow[i];
int nc=sc+ncol[i];
dfs(nr, nc, color, grid, gridCol);
}
vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,int color) {
dfs(sr,sc,color, grid, grid [sr][sc]);
return grid;
}


// numIslands

Void dfs(vector<vector<char>>& arr, int r, int c)
{
arr[r] [c]='0';
int m=arr.size(),n=arr[0].size();
int nrow[]={-1,0,1,0};
int ncol[]={0,-1,0,1};
for(int i=0;i<4;i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i];
if(nr>=0 and nr<m and nc>= and nc<n and arr[nr] [nc] == '1') dfs
,nr,nc);
}
}
int numIslands (vector<vector<char>>& grid) {
int count = 0;
for(int i = 0; i<grid.size(); i++){
for(int j = 0; j<grid[0].size();j++){
if(grid[i][j] == '1'){
dfs(grid,i,j);
count++;
}
}
}
return count;
}

// findMaxFish

int void dfs(vector<vector<int>>& arr, vector<vector<int>>& vis, int r, int c, &count )
{
count++;
vis[r][c]=1;
int m=arr.size(),n=arr[0].size();
int nrow[]={-1,0,1,0};
int ncol[]={0,-1,0,1};
for(int i=0;i<4;i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i];
if(nr>=0 and nr<m and nc>= and nc<n and arr[nr] [nc] and !vis
[nr][nc])
dfs(arr, vis,nr,nc,count);
}
}
int findMaxFish(vector<vector<int>>& arr) {
int res=0,m=arr.size(),n=arr[0].size(); vector<vector<int>> vis(m, vector<int> (n,0));
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
if(arr[i][j])
{
int temp=arr[i][j]; help(arr,i,j,temp,vis);
res=max(temp, res);
}
}
}
return res;
}


// min change disconnect the  island 

void dfs(vector<vector<int>> &arr, vector<vector<int>> &vis, int r,intc,int m,int n)
{
vis[r][c]=1;
int nrow[]={-1,0,1,0};
int ncol[]={0,-1,0,1}; for(int i=0;i<4;i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i];
if(nr>=0 and nr<m and nc>=0 and nc<n and !vis [nr] [nc] and arr[nr][nc])
{
dfs(arr,vis,nr,nc,m,n);
}
}
}
int cc(vector<vector<int>> &arr)
{
int m=arr.size(),n=arr[0].size(),c=0; 
vector<vector<int>> vis(m, vector<int> (n,0)); 
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
if(arr[i][j] and !vis[i][j])
{
c++;
dfs(arr, vis,i,j,m,n);
}
}
}
return c;
}
int minDays(vector<vector<int>>& arr) {
int m=arr.size(),n=arr[0].size(); int check=cc(arr);
if(check==0 or check>1) return 0; //cout>1///too kya kro
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
{
if(arr[i][j])
{
arr[i][j]=0;
int ans=cc(arr);
arr[i][j]=1;
if(ans>1 or ans==0) return 1;
}
}
}
return 2;
}

// nearestExit

int nearestExit(vector<vector<char>>& arr, vector<int>& tar) {
int m=arr.size(),n=arr[0].size(); vector<vector<int>> vis(m, vector<int> (n,0));
queue<pair<int, pair<int, int>>> q; q.push({0, {tar[0], tar[1]}});
vis[tar[0]][tar[1]]=1;
while(!q.empty())
{
int cost=q.front().first;
int r=q.front().second.first;
int c=q.front().second.second;
q.pop();
if(r==0 or r==m-1 or c==0 or c==n-1)
{
if(r!=tar[0] or c!=tar[1]) return cost;
}
int nrow[]={-1,0,1,0}; int ncol[]={0,-1,0,1};
for(int i=0;i<4;i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i];
if(nr>=0 and nr<m and nc>=0 and nc<n and arr[nr] [nc]=='.' and
!vis[nr][nc])
{
vis[nr][nc]=1;
q.push({1+cost, {nr,nc}});
}
}
}
return -1;
}

// nearestExit minimumEffortPath

int minimumEffortPath(vector<vector<int>>& arr) { int m=arr.size(),n=arr[0].size();
priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int,
int>>>, greater<pair<int, pair<int, int>>>> pq;
int nrow[]={-1,0,1,0};
int ncol[]={0,-1,0,1};
pq.push({0,0,0,}}); vector<vector<int>> dis(m, vector<int> (n, INT_MAX));
dis[0][0]=0;
while(!pq.empty())
{
int diff=pq.top().first;
int r=pq.top().second.first;
int c=pq.top().second.second;
pq.pop();
if(r==m-1 and c==n-1) return diff;
for(int i=0;i<4;i++)
{
int nr=r+nrow[i];
int nc=c+ncol[i]; if(nr>=0 and nr<m and nc>=0 and nc<n)
{
int newdiff=max(diff,abs(arr[nr][nc]-arr[r][c])); if(newdiff<dis[nr][nc])
{
dis[nr][nc]=newdiff; pq.push({newdiff, {nr,nc}});
} }
}
}
return 0;




// orangesRotting

int orangesRotting(vector<vector<int>>& grid) {
int n=grid.size(), m=grid[0].size();
queue<pair<pair<int, int>, int>>q;
vector<vector<int>>vis(n,vector<int>(m,0));
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if (grid[i][j] == 2)
{
q.push({{i, j}, }); vis[i][j] = 2;
}
else
}
vis[i][j] = 0;
}
vector<vector<int>>d={{1,0},{0,1},{1,0},{0,1}};
 int time=0;
while (!q.empty())
{
int r = q.front().first.first;
int c = q.front().first.second;
int t = q.front().second;
q.pop();
time=max(time,t);
for(int i=0;i<4;i++)
{
int nr=r+d[i][0];
int nc=c+d[i][1];
vis[nr][nc]!=2)
if(nr<n && nc<m && nr>=0 && nc>=0 && grid[nr] [nc]==1 && vis[nr][nc]!=2)
{
q.push({{nr,nc},t+1});
vis[nr][nc]=2;
}
}
}
for (int i = 0; i < n; i++)
{
for (int j = 0; j < m; j++)
{
if(vis[i][j]!=2 && grid[i][j]==1) return -1;
}
}
return time;
}



// isBipartite

bool dfs(int i, int col, vector<int>&color, vector<vector<int>>&adj,int n)
{ 
    color[i]=col;
for(auto it:adj[i])
{ if(color[it]==-1)
{ 
    if(dfs(it,!col, color, adj,n)==false) return false;
}
else if(color[it]==col) return false;
}
return true;
}
bool isBipartite(vector<vector<int>>& adj)
 { 
    int n=adj.size(); 
    if(color[i]==-1){
vector<int> col(n+1,-1);
 vector<int>color(n,-1);
for(int i=0;i<n;i++){
if(dfs(i,0, color, adj,n)==false) return false;
}
}
return true;



// allPathsSourceTarget

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
{
int n = graph.size() - 1;
vector<vector<int>> ans;
queue<pair<int, vector<int>>> q;
vector<int> temp;
q.push({0, temp});
while (q.size()) {
pair<int, vector<int>> f = q.front();
q.pop();
int u = f.first;
vector<int> vec = f.second;
vec.push_back(u);
if (u == n) {
ans.push_back(vec);
}
for (int v: graph[u]) { q.push({v, vec});
}
}
return ans;
}



// minimumTime

int minimumTime(int n, vector<vector<int>>& relations, vector<int>&time)
 {
queue<int> q;
vector<vector<int>> adj (n+1);
vector<int> rest(n+1,0);
 vector<int> indeg(n+1);
for(int i = 0; i<relations.size();i++)
{
adj[relations[i][0]].push_back(relations[i][1]);
indeg[relations[i][1]]++;
}
for(int i=1;i<=n;i++)
{
if(indeg[i] == 0)
{
q.push(i); rest[i] = time[i-1];
}
}
int result = 0;
while(q.empty() == 0)
{
int size = q.size(); while(size--)
{
int u = q.front();
q.pop();
for(int v:adj[u])
{
indeg[v]--;
rest[v] = max(rest[v], rest[u]+time [v-1]);
 if(indeg[v] == 0)
{
q.push(v);
}
}
}
}
result = *max_element(rest.begin(), rest.end()); 
return result;
}


// countRestrictedPaths
typedef pair<int, int> PII;
public:
int countRestrictedPaths (int n, vector<vector<int>>& E) {
long mod = 1e9 + 7; vector<vector<pair<long, int>>> G(n);
for (auto &e: E) {
int u = e[0] - 1, V = e[1] - 1, w = e[2];
G[u].emplace_back(v, w);
G[v].emplace_back(u, w);
}
priority_queue<PII, vector<PII>, greater<PII>> pq;
 vector<long> dist(n, INT_MAX), cnt(n, 0);
dist[n-1] = 0; 
cnt[n-1] = 1; 
pq.emplace(0, n - 1);
while (pq.size())
 {
auto [w, u] = pq.top();
pq.pop();
if (w > dist[u]) continue; 
for (auto &[v, d]: G[u])
 {
if (dist[v] > w + d) {
dist[v] = w + d; 
pq.emplace(dist[v], v);
}
if (w > dist[v]) {
cnt[u] = (cnt[u] + cnt[v]) % mod;
}
}
}
return cnt[0];
}

// largestPathValue
int largestPathValue(string colors, vector<vector<int>>& edges)
 { 
    int n = colors.size(); 
    vector<int> indegrees (n, 0);
     vector<vector<int>> graph(n, vector<int>());
for (vector<int>& edge: edges)
 {
     graph[edge[0]).push_back(edge[1]); 
     indegrees [edge[1]]++;
}
queue<int> zero_indegree;
 for (int i = 0; i < n; i++) {
if (indegrees[i] == 0)
 { 
    zero_indegree.push(i);
}
}
vector<vector<int>> counts(n, vector<int>(26, 0)); 
for (int i = 0; i < n; i++) 
{ 
    counts[i][colors[i] - 'a']++;
}
int max_count = 0;
int visited = 0;
while (!zero_indegree.empty())
 { 
    int u = zero_indegree.front();
     zero_indegree.pop();
      visited++;
for (int v graph[u]) 
{
for (int i = 0; i < 26; i++)
 {
     counts [v][i] = max(counts [v] [i], counts [u] [i] + (colors[v]-'a' == i ? 1 : 0)); 
}
indegrees [v]--;
if (indegrees [v] == 0) {
zero_indegree.push(v);
}
}
max_count = max(max_count, *max_element(counts [u].begin(), counts[u].end()));
}
return visited == n ? max_count : -1;
}





