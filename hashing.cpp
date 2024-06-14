class Solution {
public:
    int totalFruit(vector<int>& arr) {
       int n=arr.size(), ans=0,k=2;
       unordered_map<int, int> mp ; 
       for(int r=0,l=0;r<n;r++){
        mp[arr[r]]++;
            while(mp.size()>2)
            {
                mp[arr[l]]--;
                if(mp[arr[l]]==0) mp.erase(arr[l]);
                l++;
            }
           ans=max(ans,r-l+1);  
        }       
     return ans;
    }
};

// next smallest left
vector<int> ns1(vector<int> &height,int n)
{
stack<int> s;
vector<int> ans;
 for(int i=0;i<n;i++)
{
while(!s.empty() and height[s.top()]>=height[i]) s.pop(); 
 if(!s.size()) ans.push_back(-1); 
 else ans.push_back(s.top());
s.push(i);
}
return ans;
}

// next smallest right
vector<int> nsr(vector<int> &height, int n)
{
stack<int> s;
vector<int> ans;
for(int i=n-1;i>=0;i--)
{
if(!s.size()) ans.push_back(n);
while(!s.empty() and height[s.top()]>=height[i]) s.pop();
 s.push(i);
else ans.push_back(s.top());
}
reverse(ans.begin(),ans.end());
}
return ans;

//####################next greatest to right ####################

std::vector<int> solve(std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> nge(n);
    std::stack<int> st;

    nge[n - 1] = -1;
    st.push(arr[n - 1]);

    for (int i = n - 2; i >= 0; i--) {
        while (!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }
        if (st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    return nge;
}


//#################### pair divible k ####################

void solution(vector<int>& arr, int k) {
    unordered_map<int, int> rfmap;

    for (int val : arr) {
        int rem = val % k;
        int of = rfmap[rem];
        rfmap[rem] = of + 1;
    }

    int count = 0;

    for (int val : arr) {
        int rem = val % k;

        if (rem == 0) {
            count += rfmap[rem] / 2;
        } else if (2 * rem == k) {
            count += rfmap[rem] / 2;
        } else {
            int of = rfmap[k - rem];
            count += min(of, rfmap[rem]);
        }
    }

    cout << count << endl;
}
//#################### distinct element count   k windows ####################


vector<int> solution(vector<int>& arr, int k) {
    vector<int> list;
    unordered_map<int, int> map;

    int i = 0;
    int j = -1;

    while (i <= k - 2) {
        map[arr[i]]++;
        i++;
    }

    while (i < arr.size() - 1) {
        i++;
        map[arr[i]]++;  // acquire
        list.push_back(map.size());  // work

        // release
        j++;
        int freq = map[arr[j]];

        if (freq == 1) {
            map.erase(arr[j]);
        } else {
            map[arr[j]] = freq - 1;
        }
    }

    return list;
}


//#################### largest subarray  sum 0 ####################


int maxLengthSubarrayWithEqual0and1(vector<int>& arr) {
    unordered_map<int, int> map;
    int mlen = 0;
    int i = -1;
    int sum = 0;
    map[sum] = i;

    while (i < arr.size() - 1) {
        i++;
        sum += arr[i];
        
        if (map.find(sum) == map.end()) {
            map[sum] = i;
        } else {
            int len = i - map[sum];
            if (len > mlen) {
                mlen = len;
            }
        }
    }
    
    return mlen;
}

//#################### count all subarray  sum 0 ####################


int countSubarraysWithEqual0sAnd1s(vector<int>& arr) {
    unordered_map<int, int> map;
    int count = 0;
    int i = -1;
    int sum = 0;
    map[0] = 1;

    while (i < static_cast<int>(arr.size()) - 1) {
        i++;
        sum += arr[i];

        if (map.find(sum) != map.end()) {
            count += map[sum];
            map[sum]++;
        } else {
            map[sum] = 1;
        }
    }

    return count;
}

//#################### largest continous subarray    like 2 3 4 5####################


 int minVal = arr[0];
    int maxVal = arr[0];
    unordered_set<int> cd;
    cd.insert(arr[0]);

    for (size_t i = 1; i < arr.size(); ++i) {
        if (cd.find(arr[i]) != cd.end()) {
            break;
        }
        cd.insert(arr[i]);
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);

        if (maxVal - minVal == i) {
            // Your logic when condition is met
        }
    }

//#################### s1 and s2 string  minimum window substring  all s1 ka s2 ma mil jaye####################
string minwindow(string s, string t) { 
    int head=0,tail=0,minlen=INT_MAX,start_pos=0,sz=0;
     int map[128]={};
for(auto it:t){
}
map[it]++;
for(head=0; head<s.size(); head++){ map[s[head]]--;
// operation
if(map[s[head]]>=0) sz++;
while(sz==t.size()){
if(minlen > (head-tail+1)){ minlen= head-tail+1;
start_pos= tail;
}
map[s[tail]]++;
if(map[s[tail]]>0) sz--;
tail++;
}
}
return minlen==INT_MAX?"": s.substr(start_pos,minlen);
}
//#################### min substring jisma itself ka saare char mil jaye####################
 string str = "your_string_here"; // Replace 'your_string_here' with the actual string

    unordered_map<char, int> map;
    unordered_set<char> set;

    int i = -1, j = 0;
    int len = str.length(); // Initialize 'len' with the maximum possible value

    while (true) {
        bool f1 = false;
        bool f2 = false;
        i++;

        // Acquire till it is invalid (map.size() < set.size())
        while (i < str.length() - 1 && map.size() < set.size()) {
            f1 = true;
            char ch = str[i];
            map[ch] = map[ch] + 1;
            set.insert(ch);
            i++;
        }

        // Collect and release
        while (j < i && map.size() == set.size()) {
            int plen = i - j;
            if (plen < len) {
                len = plen;
            }
            j++;
            char ch = str[j];
            if (map[ch] == 1) {
                map.erase(ch);
            } else {
                map[ch] = map[ch] - 1;
            }
            f2 = true;
        }

        if (f1 == false && f2 == false) {
            break;
        }
    }

//longest substring without repeat
    int ans = 0, start = -1;
        vector<int> m(128, -1);
        for (int i = 0; i < s.size(); ++i) {
            start = max(start, m[s[i]]);
            m[s[i]] = i;
            ans = max(ans, i - start);
        }
        //longest substring without repeat  (k replacement allow)
        int i = 0, j = 0, cnt[26] = {}, ans = 0, N = s.size();
        while (j < N) {
            cnt[s[j++] - 'A']++;
            while (j - i - *max_element(cnt, cnt + 26) > k) cnt[s[i++] - 'A']--;
            ans = max(ans, j - i);
        }
//#################### count sustring all unique char####################

  int i = 0, j = 0;
    bool f1 = false, f2 = false;
    string str = "your_string_here"; // Replace "your_string_here" with your actual string
    unordered_map<char, int> map;
    int ans = 0;
    
    while (i < str.length() - 1) {
        f1 = true;
        i++;
        char ch = str[i];
        map[ch]++;
        if (map[ch] == 2) {
            break;
        } else {
            ans += i * j;
        }
    }
    
    while (j < i) {
        f2 = true;
        j++;
        char ch = str[j];
        map[ch]--;
        if (map[ch] == 1) {
            ans += 11;
            break;
        }
    }
    


//#################### longest substring exactly k char####################


int i = -1, j = -1;
    bool f1 = false, f2 = false;
    int k = 3; // Replace 'k' with the desired value
    string str = "your_string_here"; // Replace "your_string_here" with your actual string
    unordered_map<char, int> map;
    int ans = 0;

    while (i < str.length() - 1) {
        f1 = true;
        i++;
        char ch = str[i];
        map[ch]++;
        
        if (map.size() < k) {
            continue;
        } else if (map.size() == k) {
            int len = i - j;
            if (len > ans) {
                ans = len;
            }
        } else {
            break;
        }

        while (j < i) {
            f2 = true;
            j++;
            char ch = str[j];
            
            if (map[ch] == 1) {
                map.erase(ch);
            } else {
                map[ch]--;
            }

            if (map.size() > k) {
                continue;
            } else if (map.size() == k) {
                int len = i - j;
                if (len > ans) {
                    ans = len;
                }
                break;
            }
        }
    }

//#################### count longest substring exactly k char####################
  string str = "your_string_here"; // Replace "your_string_here" with your actual string
    unordered_map<char, int> map;
    int ans = 0;
    int i = -1;
    int j = -1;

    while (true) {
        while (i < str.length() - 1) {
            i++;
            char ch = str[i];
            map[ch]++;

            if (map.size() == 2) {
                removeInMap(map, ch);
                i--;
                break;
            }
        }

        while (j < i) {
            if (map.size() == 1) {
                ans += (i - j);
            }
            j++;
            char ch = str[j];
            removeInMap(map, ch);

            if (map.size() == 0) {
                break;
            }
        }

        if (i == str.length() - 1) {
            break;
        }
    }


void removeInMap(unordered_map<char, int>& map, char ch) {
    if (map.find(ch) != map.end()) {
        map[ch]--;
        if (map[ch] == 0) {
            map.erase(ch);
        }
    }
}
//####################equivlaent subarray mtlb count unique subarray =actual unique subarry####################

  int k = 3; // Replace with your k value
    unordered_map<int, int> map;
    int ans = 0;
    int i = -1;
    int j = -1;
    int n = arr.size();

    while (j < n) {
        bool f2 = true;
        j++;

        while (i < n - 1) {
            bool f1 = true;
            i++;
            map[arr[i]]++;

            if (map.size() == k) {
                ans += (n - 1);
                break;
            }

            if (map[arr[j]] == 1) {
                map.erase(arr[j]);
            } else {
                map[arr[j]]--;
            }

            if (map.size() == k) {
                ans = (n - 1);
            } else {
                break;
            }
        }

        if (i == n - 1) {
            break;
        }
    }
//#################### max consecutive one k flip ####################
int longestones(vector<int>& A, int k) 
{ int head=0,tail=0,ans=0;
 if(A[head]==0) k--;
for (head=0; head<A.size(); head++){
while(k<0){
     if(A[tail]==0) k++; tail++;
}
 ans=max(ans, head-tail+1);
}
return max(ans, head-tail);
}
//####################get equal substring within budget####################
int equalSubstring(string s, string t, int maxCost) 
{ 
    int head=0,tail=0,ans=0,cost=0;
     for (head=0; head<s.size(); head++){
         cost+=abs(s[head]-t[head]); 
         while(cost>maxCost){
             cost-=abs(s[tail]-t [tail]); 
             tail++;
}
ans=max(ans, head-tail+1);
}
return ans;
}
//####################atmost 1 zero flip krke max consecutive one####################

int longestSubarray(vector<int>& nums) { 
    int head=0,tail=0,len=0,cnt=0;
for (head=0; head<nums.size();head++){
     if(nums [head]==0) cnt++;
while(cnt>1){
if(nums[tail]==0)cnt--;
 tail++;
} 
len=max(len, head-tail);
}
return len;
}
//#################### longest substring atmost k unique####################
    string str = "your_string_here"; // Replace "your_string_here" with your string
    unordered_map<char, int> map;
    int i = -1;
    int j = -1;
    bool f1 = false;
    bool f2 = false;
    int ans = 0;

    while (true) {
        while (i < str.length() - 1) {
            f1 = true;
            i++;
            char ch = str[i];
            map[ch] = map[ch] + 1;
            int len = 1;

            if (map.size()) {
                ans = len;
                if (len > ans) {
                    // Logic unclear
                } else {
                    break;
                }
            }
        }

        while (j < i) {
            f2 = true;
            j++;
            char ch = str[j];
            if (map[ch] == 1) {
                map.erase(ch);
            } else {
                map[ch] = map[ch] - 1;
            }

            if (map.size() != 0) {
                continue;
            } else {
                int len = i - j;
                if (len > ans) {
                    ans = len;
                }
                break;
            }
        }

        // Additional logic required here

        if (!(f1 && f2)) {
            break;
        }
    }

//#################### count substring atmost k unique####################


  string str = "your_string_here"; // Replace "your_string_here" with your string
    unordered_map<char, int> map;
    int i = -1;
    int j = -1;
    int k = 3; // Replace 'k' with your desired value
    int ans = 0;

    while (true) {
        i++;
        while (i < str.length() - 1) {
            char ch = str[i];
            map[ch] = map[ch] + 1;

            if (map.size() <= k) {
                ans += i - j;
            } else {
                break;
            }
            i++;
        }

        if (i == str.length() - 1 && map.size() <= k) {
            break;
        }

        while (j < i) {
            j++;
            char ch = str[j];
            if (map[ch] == 1) {
                map.erase(ch);
            } else {
                map[ch] = map[ch] - 1;
            }

            if (map.size() > k) {
                continue;
            } else {
                ans += i - j;
                break;
            }
        }
    }

//#################### find all anagram (start index de arr {0,2} )####################

  vector<int> findAnagrams(string s, string p) {
vector<int>ans; vector<int>hash(26);
vector<int>temp(26);
for(int i=0;i<p.size();i++){ hash[p[i]-'a']++;
}
int sz=p.size();
int head=0,tail=0;
for (head=0; head<s.size(); head++){
if(temp==hash) ans.push_back(tail); while(head-tail+1>sz){
temp[s[tail]-'a']--;
tail++;
} temp[s[head]-'a']++;
} if(temp==hash) ans.push_back(tail);
return ans;
//#################### two string k anagram or not ####################


bool arekAnagrams(std::string str1, std::string str2, int k) {
    if (str1.length() != str2.length()) {
        return false;
    }

    std::unordered_map<char, int> map;
    for (char ch : str1) {
        map[ch]++;
    }

    for (char ch : str2) {
        if (map[ch] > 0) {
            map[ch]--;
        }
    }

    int count = 0;
    for (auto &pair : map) {
        count += pair.second;
    }

    return count <= k;
}
//####################groups anagrams ####################


std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::map<char, int>, std::vector<std::string>> bmap;

    for (const std::string& str : strs) {
        std::map<char, int> fmap;
        for (char ch : str) {
            fmap[ch]++;
        }

        if (bmap.find(fmap) == bmap.end()) {
            std::vector<std::string> list = {str};
            bmap[fmap] = list;
        } else {
            bmap[fmap].push_back(str);
        }
    }

    std::vector<std::vector<std::string>> res;
    for (auto& val : bmap) {
        res.push_back(val.second);
    }
    return res;
}

//#################### group shift string ####################


std::string getKey(const std::string& str) {
    std::string key = str;
    std::sort(key.begin(), key.end());
    return key;
}

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (const std::string& str : strs) {
        std::string key = getKey(str);

        if (map.find(key) == map.end()) {
            std::vector<std::string> list = {str};
            map[key] = list;
        } else {
            map[key].push_back(str);
        }
    }

    std::vector<std::vector<std::string>> res;
    for (auto& list : map) {
        res.push_back(list.second);
    }
    return res;
}
//#################### no. subarray sum =k ####################


int solution(std::vector<int>& arr, int target) {
    int ans = 0;
    std::unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        if (map.find(sum - target) != map.end()) {
            ans += map[sum - target];
        }
        map[sum]++;
    }
    return ans;
}
//#################### min subarray sum >=tar ####################
int minSubArrayLen(int target, vector<int>& nums) { 
    int head=0,tail=0,min_len=INT_MAX,sum=0;
for (head=0; head<A.size(); head++){ 
    sum+=nums[head];
while(sum>-target){ 
tail++;
}
}
return min_len==INT_MAX?0:min_len; // return ans;
}

//#################### min oprtn to arr to zero (x ko - kro left or right sa) ####################
int minOperations(vector<int>& nums, int x) {
int sum accumulate(nums.begin(),nums.end(),0); 
int reqsum=sum-x; 
if(reqsum<0) return -1;
if(reqsum==0) return nums.size();
int head=0,tail=0,mxlen=0,mysum=0;
for(head=0; head<nums.size(); head++){
mysum+=nums[head];
// perform operation
while(mysum>reqsum){ mysum-nums[tail]; tail++;
// go inside while loop to make it valid
}
if(mysum==reqsum){
     mxlen=max(mxlen, head-tail+1);
// update length
}
}
return mxlen==0?-1:nums.size()-mxlen;
}
//#################### number subarray product <k ####################
int numSubarray Product LessThank(vector<int>& nums, int k) {
if(k<=1) return 0;
int head=0,tail=0,ans=0, prod=1;
 for(head=0; head<size(nums); head++){
     prod=prod*nums [head];
      while(prod>=k){ 
        prod=prod/nums[tail]; tail++;
}
ans=ans+(head-tail+1);
}
return ans;
}
//#################### max erase value####################
int maximumUniqueSubarray(vector<int>& nums) {
int head=0,tail=0,ans=0,sum=0; unordered_map<int,int>mp; // to store frequency
for(head=0; head<nums.size(); head++){
mp[nums[head]]++;
while(mp[nums[head]]>1){ ans=max(ans, sum); sum-=nums[tail]; mp[nums[tail]]--; tail++;
}
if(mp[nums[head]]==1) sum+=nums[head];
}
return max(ans,sum);
}
//#################### longest subarray sum divisible by k ####################


int solution(std::vector<int>& arr, int k) {
    int ans = 0;
    std::unordered_map<int, int> map;
    int sum = 0;
    int rem = 0;
    map[0] = -1;

    for (int i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        rem = sum % k;
        if (rem < 0) {
            rem += k;
        }
        if (map.find(rem) != map.end()) {
            int idx = map[rem];
            int len = i - idx;
            if (len > ans) {
                ans = len;
            }
        } else {
            map[rem] = i;
        }
    }
    return ans;
}

  // number of subarrays with a sum 
         int N = A.size(), i = 0, j = 0, cnt = 0, ans = 0;
        while (j < N) {
            cnt += A[j++];
            while (i < j && cnt > goal) cnt -= A[i++];
            ans += j - i;
        }
//#################### subarray sum divisible by k####################


int solution(std::vector<int>& arr, int k) {
    int ans = 0;
    std::unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;
    int rem = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];
        rem = sum % k;
        if (rem < 0) {
            rem += k;
        }
        if (map.find(rem) != map.end()) {
            ans += map[rem];
            map[rem]++;
        } else {
            map[rem] = 1;
        }
    }

    return ans;
}
//#################### longest contiguous equal 0 and 1####################


int solution(std::vector<int>& arr) {
    int ans = 0;
    std::unordered_map<int, int> map;
    map[0] = -1;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            sum -= 1;
        } else if (arr[i] == 1) {
            sum += 1;
        }

        if (map.find(sum) != map.end()) {
            int idx = map[sum];
            int len = i - idx;
            ans = std::max(ans, len);
        } else {
            map[sum] = i;
        }
    }

    return ans;
}


//#################### count longest contiguous equal 0 and 1####################


int solution(std::vector<int>& arr) {
    int ans = 0;
    std::unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0;

    for (int val : arr) {
        if (val == 0) {
            sum -= 1;
        } else {
            sum += 1;
        }

        if (map.find(sum) != map.end()) {
            ans += map[sum];
            map[sum]++;
        } else {
            map[sum] = 1;
        }
    }

    return ans;
}

//#################### longest subarray = 0 1 2####################


int solution(std::vector<int>& arr) {
    int ans = 0;
    std::unordered_map<std::string, int> map;
    int countz = 0, counto = 0, countt = 0;
    int delta10 = counto - countz;
    int delta21 = countt - counto;
    std::string key = std::to_string(delta21) + "#" + std::to_string(delta10);
    map[key] = -1;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            countz++;
        } else if (arr[i] == 1) {
            counto++;
        } else {
            countt++;
        }

        delta10 = counto - countz;
        delta21 = countt - counto;
        key = std::to_string(delta21) + "#" + std::to_string(delta10);

        if (map.find(key) != map.end()) {
            int idx = map[key];
            int len = i - idx;
            if (len > ans) {
                ans = len;
            }
        } else {
            map[key] = i;
        }
    }

    return ans;
}

//####################count longest subarray = 0 1 2####################

int solution(std::vector<int>& arr) {
    int ans = 0, c0 = 0, c1 = 0, c2 = 0;
    std::unordered_map<std::string, int> map;

    std::string key = std::to_string(c1 - c0) + "#" + std::to_string(c2 - c1);
    map[key] = 1;

    for (int val : arr) {
        if (val == 0) {
            c0++;
        } else if (val == 1) {
            c1++;
        } else {
            c2++;
        }

        key = std::to_string(c1 - c0) + "#" + std::to_string(c2 - c1);
        if (map.find(key) != map.end()) {
            ans += map[key];
            map[key]++;
        } else {
            map[key] = 1;
        }
    }
    return ans;
}


//####################pair with equal sum ####################


bool solution(std::vector<int>& arr) {
    std::unordered_set<int> set;

    for (size_t i = 0; i < arr.size(); ++i) {
        for (size_t j = i + 1; j < arr.size(); ++j) {
            int sum = arr[i] + arr[j];

            if (set.find(sum) != set.end()) {
                return true;
            } else {
                set.insert(sum);
            }
        }
    }

    return false;
}
//####################smallest subarray with highest number of freq####################



void findFrequent(std::vector<int>& arr) {
    int hfreq = 0;
    int si = 0;
    int ei = 0;
    int len = ei - si + 1;

    std::unordered_map<int, int> fmap;
    std::unordered_map<int, int> smap;

    for (size_t i = 0; i < arr.size(); ++i) {
        if (fmap.find(arr[i]) != fmap.end()) {
            fmap[arr[i]]++;
        } else {
            fmap[arr[i]] = 1;
            smap[arr[i]] = i;
        }

        if (fmap[arr[i]] > hfreq) {
            hfreq = fmap[arr[i]];
            si = smap[arr[i]];
            ei = i;
            len = ei - si + 1;
        } else if (fmap[arr[i]] == hfreq) {
            int clen = i - smap[arr[i]] + 1;
            if (clen < len) {
                hfreq = fmap[arr[i]];
                si = smap[arr[i]];
                ei = i;
                len = ei - si + 1;
            }
        }
    }

    std::cout << hfreq << std::endl;
}
//####################longest substring atmost two distinct char####################


int lengthOfLongestSubstringTwoDistinct(std::string s) {
    std::unordered_map<char, int> count;
    int dis = 0;
    int start = 0;
    int ans = 0;

    for (int i = 0; i < s.length(); i++) {
        int fre = count[s[i]];
        if (fre == 0) {
            dis++;
        }
        count[s[i]] = fre + 1;

        while (dis > 2) {
            fre = count[s[start]];
            count[s[start]] = fre - 1;
            if (fre - 1 == 0) {
                dis--;
            }
            start++;
        }
        ans = std::max(ans, i - start + 1);
    }
    return ans;
}

//#################### max freq every i incrs by 1####################
int maxFrequency(vector<int>& A, int k) {
     sort(begin(A), end(A)); 
long head = 0, tail=0, N = A.size(), ans = 0, sum=0;
for (head = 0; head < N; ++head) { 
    sum += A[head];
if ((head - tail+ 1) * A[head] sum-=A[tail]; tail++; sum > k){
}
ans=max(ans,head-tail+1);
}
return ans;
}
//#################### number of zero fill subarray####################
long long zerofilledSubarray(vector<int>& nums) {
     long long head=0,tail=0,ans=0;
for(head=0; head<nums.size();head++){
tail-head;
while(head<nums.size() and nums [head]==0){
     ans+=(head-tail+1);
      head++;
}
}
return ans;
}
//####################number of pair in subarray >=k####################
long long countGood(vector<int>& nums, int k) {
int head = 0, tail = 0, n = nums.size();
 unordered_map<int,int> mp; long long int cnt = 0 ans = 0;
for(head=0; head<nums.size():head++){
cnt += mp[nums[head]] mp[nums[head]]++;

while(tail < head and cnt >= k){ ans += n - head; mp[nums[tail]]--; 
cnt = mp[nums[tail]];
 tail++;
}
}
return ans;
}

//#################### longest nice subarray mtlb pair bit and kro to zero ho####################
int longestNiceSubarray(vector<int>& nums) {
     int head=0,tail=0,ans=0,result=0; 
     for(head=0; head<nums.size(); head++){
while((ans&nums[head])>0){ 
    ans^=nums[tail];
tail++;
}
 ans|=nums[head];
result=max(result, head-tail+1); cout<<head-tail+1<<" "<<head<<endl;
}
return result;
}
//####################number of binary subarray sum==k ####################
int atmost(vector<int>&nums, int g){
long long head=0,tail=0,sum=0,ans=0; 
for(head=0; head<nums.size();head++){
     sum+=nums[head];
while(tail<=head and sum>g){
sum-=nums[tail];
tail++;
} ans+=head-tail+1;
}
return ans;
}
int numSubarrayswithSum(vector<int>& nums, int goal) {
cout<< atmost(nums,goal)<<" "<<atmost(nums,goal-1); 
return atmost(nums, goal)-atmost(nums,goal-1);
}

  //number of  subarrays k odd numbers
        int N = A.size(), i = 0, j = 0, prev = -1, ans = 0, ci = 0, cj = 0;
        while (j < N) {
            cj += A[j++] % 2;
            if (ci <= cj - k) {
                prev = i;
                while (ci <= cj - k) ci += A[i++] % 2;
            }
            if (cj >= k) ans += i - prev;
        }
//#################### min swap to group all one together####################
int minSwaps (vector<int>& nums) {
int cnt1=0,cnte,sz=nums.size();
 cnt1=count(nums.begin(),nums.end(),1);
int windowsize=cnt1;
for(int i=0;i<windowsize;i++){ if(nums[i]==0) cnt++;
}
int mn=cnte;
for(int i=windowsize;i<windowsize+sz;i++){
if(nums[i%sz]==0) cnt++; if(nums[i-windowsize]==0) cnt--;
mn=min(mn,cnte);
}
return mn;
}
