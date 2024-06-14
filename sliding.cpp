
     
      
         //max freq kisse element ka bna sakte hai k operation krke [1,2,4], k = 5  1+3,2+2 [4,4,4] max-3
         sort(begin(A), end(A));
        long i = 0, N = A.size(), ans = 1, sum = 0;
        for (int j = 0; j < N; ++j) {
            sum += A[j];
            while ((j - i + 1) * A[j] - sum > k) sum -= A[i++];
            ans = max(ans, j - i + 1);
        }
        //maximum length substring of s = substring of t with change. cost<= maxCost(cost=ascii value diff abs(s[i] - t[i]))
         int i = 0, j = 0, N = s.size(), cost = 0, ans = 0;
        for (; j < N; ++j) {
            cost += abs(s[j] - t[j]);
            for (; cost > maxCost; ++i) cost -= abs(s[i] - t[i]);
            ans = max(ans, j - i + 1);
        }
        //max subarray
        int runningSum = 0, maxi = 0;
    for (int i = 0; i < arr.size(); i++) {
        runningSum +=arr[i];
        if (runningSum < 0)
            runningSum = 0;
        maxi = max(maxi, runningSum);
    }
    
        //longest substring of 1's delete one zero allow
        int N = A.size(), prev2 = -1, prev = -1, ans = 0;
        for (int i = 0; i <= N; ++i) {
            if (i < N && A[i] == 1) continue;
            if (i == N && prev == -1) return N - 1;
            if (prev != -1) ans = max(ans, i - prev2 - 2);
            prev2 = prev;
            prev = i;
        }
        
//maximum score you can get by erasing exactly one subarray show that sab unique ho [4,2,4,5,6]->[2,4,5,6]
         int ans = 0, N = A.size(), sum = 0;
        unordered_set<int> s;
        for (int i = 0, j = 0; j < N; ++j) {
            while (s.count(A[j])) {
                s.erase(A[i]);
                sum -= A[i++];
            }
            s.insert(A[j]);
            sum += A[j];
            ans = max(ans, sum);
        }
//min number of operations to make nums continuous (array (max-min)=n-1)
    int N = A.size(), ans = N, j = 0;
        sort(begin(A), end(A));
        A.erase(unique(begin(A), end(A)), end(A)); // only keep unique elements
        int M = A.size();
        for (int i = 0; i < M; ++i) {
            while (j < M && A[j] < A[i] + N) ++j; // let `j` point to the first element that is out of range -- `>= A[i] + N`.
            ans = min(ans, N - j + i); // The length of this subarray is `j - i`. We need to replace `N - j + i` elements to make it continuous.
        } 
 //number of subarray prod less than k
 if (k == 0) return 0;
        long i = 0, j = 0, N = A.size(), prod = 1, ans = 0;
        for (; j < N; ++j) {
            prod *= A[j];
            while (i <= j && prod >= k) prod /= A[i++];
            ans += j - i + 1;
        } 
//number of Subarrays exactly 2 different integers (total-(k-1) kr dunga)
 int distinct = 0, i = 0, j = 0, N = A.size(), ans = 0;
        unordered_map<int, int> cnt;
        for (; j < N; ++j) {
            distinct += ++cnt[A[j]] == 1;
            while (distinct > k) distinct -= --cnt[A[i++]] == 0;
            ans += j - i;
        }  
//#######################################string waale aaya  gya


   //s1 and s2, return true if s2 contains a permutation of s1 (s1 = "ab", s2 = "eidbaooo"->true)
        unordered_map<char, int> table;
        for(char c : s1) table[c]++;
        int begin = 0, end = 0, counter = table.size();
        while(end < s2.length()){
            char endchar = s2[end];
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            end++;
            while(counter == 0){
                if(end - begin == s1.length()) return true;
                char startchar = s2[begin];
                if(table.count(startchar) == 1){
                    table[startchar]++;
                    if(table[startchar] > 0) counter++;
                }
                begin++;
            }
        }
        return false;
    
// all the start indices of p's anagrams in s.s = "cbaebabacd", p = "abc" [0,6]
        unordered_map<char, int> table;
        vector<int> ans;
        for(char c : p)table[c]++;
        if(s.length() < p.length() || s.length() == 0) return ans;
        int begin = 0, end = 0, word_size = p.length();
        int counter = table.size();
        while(end  < s.length()){
            char endchar = s[end];
            if(table.count(endchar) == 1){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            end++;
            while(counter == 0){
                if(end - begin == word_size) {
                    ans.push_back(begin);
                }
                char beginchar = s[begin];
                if(table.count(beginchar) == 1){
                    table[beginchar]++;
                    if(table[beginchar] > 0) counter++;
                }
                begin++;
            }
        }
        return ans;
//longest substr with 2dist        
if(s.length() == 0) return 0;
        unordered_map<char, int> table;
        int begin = 0, end = 0, len = 0, counter = 0;
        while(end < s.length()){
            char current = s[end];
            table[current]++;
            if(table[current] == 1) counter++;
            end++;
            while(counter > 2){
                char startchar = s[begin];
                if(table.count(startchar) == 1){
                    table[startchar]--;
                    if(table[startchar] == 0) counter--;
                }
                begin++;
            }
            len = max(len, end - begin);
        }
         return len;  
// max possible k consecutive
         int max_sum = 0, window_sum = 0; 
for (int i = 0; i < k; i++)  window_sum += arr[i]; 
for (int i = k; i < n; i++){ 
    window_sum += arr[i] - arr[i-k];   
    max_sum = max(max_sum, window_sum);
} 
//min window substring of s such that every character in t (s="ADOBECODEBANC", t = "ABC")=> "BANC"
  unordered_map<char, int> table;
        for(char c : t){
            table[c]++;
        }
        int begin = 0, end = 0;
        int counter = table.size();
        int len = INT_MAX;
        string ans = "";
        // start sliding window
        while(end < s.length()){
            char endchar = s[end];
            // if current char found in table, decrement count
            if(table.find(endchar) != table.end()){
                table[endchar]--;
                if(table[endchar] == 0) counter--;
            }
            end++;
             // if counter == 0, means we found an answer, now try to trim that window by sliding begin to right.
            while(counter == 0){
                // store new answer if smaller than previously best
                if(end-begin < len){
                    len = end - begin;
                    ans = s.substr(begin, end - begin); 
                }
                
                // begin char could be in table or not, 
                // if not then good for us, it was a wasteful char and we shortened the previously found substring.
                
                // if found in table increment count in table, as we are leaving it out of window and moving ahead, 
                // so it would no longer be a part of the substring marked by begin-end window
                // table only has count of chars required to make the present substring a valid candidate
                // if the count goes above zero means that the current window is missing one char to be an answer candidate
                int startchar = s[begin];
                
                if(table.count(startchar) == 1){
                   table[startchar]++;
                   if(table[startchar] > 0) counter++; 
                }
                
                begin++;
            }
        }
//A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.
 "barfoothefoobarman", words = ["foo","bar"]
// Output: [0,9]

 vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> table;
        vector<int> ans;
        
        if(words.size() == 0) return ans;
        
        int window_size = 0;
        int word_size = words[0].length();
        
        // building frequency table
        for(string word : words){
            window_size += word.length();
            table[word]++;
        }
        
        unordered_map<string, int> reference(table);
        
        int begin = 0, end = 0, counter = table.size();
        vector<string> tokens;
        
        if(s.length() < window_size) return ans;
        
        // we increment begin and end only in word_size 
        // there are only word_size possible start points for our window. 
        // end is actually the start of the last word in window or put in other words
        // the real end of window is actually at end + word_size
        for(int i = 0; i < word_size; i++){
            begin = i; end = i;
            table = reference; // reset to original frequency table after every iteration
            counter = table.size();
            while(end + word_size -1 < s.length()){
                string lastword = s.substr(end, word_size);
                
                if(table.count(lastword) == 1){
                    table[lastword]--;
                    if(table[lastword] == 0) counter--;
                }

                if(end + word_size - begin == window_size){
                    // counter == 0, valid answer !
                    if(counter == 0){
                        ans.push_back(begin);
                    } 

                    string firstword = s.substr(begin, word_size);
                    
                    if(table.count(firstword) == 1){
                        table[firstword]++;
                        if(table[firstword] > 0) counter++;
                    }

                    begin += word_size;
                }

                end += word_size;
            }
        }
        
        return ans;
    }        
        


