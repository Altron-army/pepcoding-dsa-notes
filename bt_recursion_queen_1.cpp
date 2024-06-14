//#################### zig zak print  12344321 ####################
void pzz(int n) {
    if (n == 0) return;
    cout << n << " ";
    pzz(n - 1);
    cout << n << " ";
    pzz(n - 1);
    cout << n << " ";
}

//#################### tower of hanoi  ####################
void toh(int n, char t1, char t2, char t3) {
    if (n == 0) return;
    toh(n - 1, t1, t3, t2);
    cout << n << "[" << t1 << " -> " << t2 << "]" << endl;
    toh(n - 1, t3, t2, t1);
}





//#################### all subsequence  print #########################################


void printSS(string ques, string ans) {
    if (ques.length() == 0) {
        cout << ans << endl;
        return;
    }
    
    char ch = ques[0];
    string roq = ques.substr(1);
    
    printSS(roq, ans + ch); // Include current character
    printSS(roq, ans);      // Exclude current character
}

//#################### all possible keypad combination #########################################


string codes[] = {";", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printKPC(string ques, string ans) {
    if (ques.length() == 0) {
        cout << ans << endl;
        return;
    }

    char ch = ques[0];
    string roq = ques.substr(1);
    string codeforch = codes[ch - '0'];

    for (int i = 0; i < codeforch.length(); i++) {
        char cho = codeforch[i];
        printKPC(roq, ans + cho);
    }
}

//#################### all Possible stair paths are#########################################


void printStairPaths(int n, string psf) {
    if (n <= 0) {
        if (n == 0) {
            cout << psf << endl;
        }
        return;
    }

    printStairPaths(n - 1, psf + "1");
    printStairPaths(n - 2, psf + "2");
    printStairPaths(n - 3, psf + "3");
}


//#################### all Possible maze paths are#########################################

void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if (sr > dr || sc > dc) {
        return;
    }

    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }

    printMazePaths(sr, sc + 1, dr, dc, psf + "h");
    printMazePaths(sr + 1, sc, dr, dc, psf + "v");
}

//#################### all Possible jump maze paths are:#########################################


void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
    if (sr == dr && sc == dc) {
        cout << psf << endl;
        return;
    }

    for (int move = 1; move <= dc - sc; move++) {
        printMazePaths(sr, sc + move, dr, dc, psf + "h" + to_string(move));
    }

    for (int move = 1; move <= dr - sr; move++) {
        printMazePaths(sr + move, sc, dr, dc, psf + "v" + to_string(move));
    }

    for (int move = 1; move <= dc - sc && move <= dr - sr; move++) {
        printMazePaths(sr + move, sc + move, dr, dc, psf + "d" + to_string(move));
    }
}

//#################### all Permutations of the string are:#########################################
void printPermutations(string str, string asf) {
    if (str.length() == 0) {
        cout << asf << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        string leftPart = str.substr(0, i); // Substring from 0 to i-1 (left to ch)
        string rightPart = str.substr(i + 1); // Substring from i+1 till end of string (right to ch)
        string roq = leftPart + rightPart; // Remaining string after extracting ch
        printPermutations(roq, asf + ch);
    }
}
//#################### all Possible encoding 123 like 1 or 12 A hoga nhi to other:#########################################


void printEncodings(string ques, string ans) {
    if (ques.length() == 0) {
        cout << ans << endl;
        return;
    } else if (ques.length() == 1) {
        if (ques[0] == '0') {
            return;
        } else {
            string ch0 = ques.substr(0, 1);
            string roq0 = ques.substr(1);
            char code0 = 'a' + (stoi(ch0) - 1);
            printEncodings(roq0, ans + code0);
        }
    } else {
        if (ques[0] == '0') {
            return;
        } else {
            string ch0 = ques.substr(0, 1);
            string roq0 = ques.substr(1);
            char code0 = 'a' + (stoi(ch0) - 1);
            printEncodings(roq0, ans + code0);

            string ch01 = ques.substr(0, 2);
            string roq01 = ques.substr(2);
            char code01 = 'a' + (stoi(ch01) - 1);
            if (stoi(ch01) <= 26) {
                printEncodings(roq01, ans + code01);
            }
        }
    }
}
//#################### all possible paths are (flood fill ):#########################################

void floodfill(vector<vector<int>>& maze, int sr, int sc, string asf, vector<vector<bool>>& visited) {
    if (sr < 0 || sc < 0 || sr >= maze.size() || sc >= maze[0].size() || maze[sr][sc] == 1 || visited[sr][sc]) {
        return;
    }

    if (sr == maze.size() - 1 && sc == maze[0].size() - 1) {
        cout << asf << endl;
        return;
    }

    visited[sr][sc] = true;
    floodfill(maze, sr - 1, sc, asf + "t", visited);
    floodfill(maze, sr, sc - 1, asf + "l", visited);
    floodfill(maze, sr + 1, sc, asf + "d", visited);
    floodfill(maze, sr, sc + 1, asf + "r", visited);
    visited[sr][sc] = false;
}

//#################### all subset target sum:#########################################

void printTargetSumSubsets(vector<int>& arr, int idx, string set, int sos, int tar) {
    if (idx == arr.size()) {
        if (sos == tar) {
            cout << set << "." << endl;
        }
        return;
    }

    printTargetSumSubsets(arr, idx + 1, set + to_string(arr[idx]) + ", ", sos + arr[idx], tar);
    printTargetSumSubsets(arr, idx + 1, set, sos, tar);
}

printTargetSumSubsets(arr, 0, "", 0, tar);



//#################### all N queen Place :#########################################


bool isQueenSafe(vector<vector<int>>& chess, int row, int col, int n) {
    // Checking in the same column
    for (int i = row - 1; i >= 0; i--) {
        if (chess[i][col] == 1) {
            return false;
        }
    }

    // Checking upper left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    // Checking upper right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printNQueens(vector<vector<int>>& chess, string qsf, int row, int n) {
    if (row == n) {
        cout << qsf << "." << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (chess[row][col] == 0 && isQueenSafe(chess, row, col, n)) {
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1, n);
            chess[row][col] = 0;
        }
    }
}

//#################### all  knight tour :#########################################


bool isQueenSafe(vector<vector<int>>& chess, int row, int col) {
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col; i >= 0; i--) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++) {
        if (chess[i][j] == 1) {
            return false;
        }
    }

    return true;
}

void printNQueens(vector<vector<int>>& chess, string qsf, int row) {
    if (row == chess.size()) {
        cout << qsf << "." << endl;
        return;
    }

    for (int col = 0; col < chess.size(); col++) {
        if (chess[row][col] == 0 && isQueenSafe(chess, row, col)) {
            chess[row][col] = 1;
            printNQueens(chess, qsf + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0;
        }
    }
}




//#################### all subsequence ABC  ####################

vector<string> gss(string str) {
    vector<string> base;
    if (str.length() == 0) {
        base.push_back("");
        return base;
    }

    char ch = str[0];
    string ros = str.substr(1);
    
    vector<string> rres = gss(ros);
    vector<string> mres;

    for (string val : rres) {
        mres.push_back(val);
    }

    for (string val : rres) {
        mres.push_back(ch + val);
    }

    return mres;
}

//#################### keypad  #########################################

vector<string> getKPC(string str);

string codes[] = {";", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

vector<string> getKPCUtil(char ch) {
    int index = ch - '0';
    return getKPC(codes[index]);
}

vector<string> getKPC(string str) {
    vector<string> base;
    if (str.length() == 0) {
        base.push_back("");
        return base;
    }

    char ch = str[0];
    string ros = str.substr(1);

    vector<string> rres = getKPC(ros);
    vector<string> mres;

    vector<string> codeForCh = getKPCUtil(ch);

    for (int i = 0; i < codeForCh.size(); i++) {
        char chCode = codeForCh[i][0];
        for (string val : rres) {
            mres.push_back(chCode + val);
        }
    }
    return mres;
}


//#################### all path stair    #########################################


vector<string> getStairPaths(int n) {
    if (n == 0) {
        vector<string> bres;
        bres.push_back("");
        return bres;
    } else if (n < 0) {
        vector<string> bres;
        return bres;
    }

    vector<string> path1 = getStairPaths(n - 1);
    vector<string> path2 = getStairPaths(n - 2);
    vector<string> path3 = getStairPaths(n - 3);
    vector<string> paths;

    for (string path : path1) {
        paths.push_back("1" + path);
    }

    for (string path : path2) {
        paths.push_back("2" + path);
    }

    for (string path : path3) {
        paths.push_back("3" + path);
    }

    return paths;
}



//#################### all path matrix  start to end    #########################################


vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        vector<string> bres;
        bres.push_back("");
        return bres;
    }

    vector<string> hpaths, vpaths;

    if (sc < dc) {
        hpaths = getMazePaths(sr, sc + 1, dr, dc);
    }

    if (sr < dr) {
        vpaths = getMazePaths(sr + 1, sc, dr, dc);
    }

    vector<string> paths;

    for (string hpath : hpaths) {
        paths.push_back("h" + hpath);
    }

    for (string vpath : vpaths) {
        paths.push_back("v" + vpath);
    }

    return paths;
}



//#################### all jump  path matrix   start to end    #########################################


vector<string> getMazePaths(int sr, int sc, int dr, int dc) {
    if (sr == dr && sc == dc) {
        vector<string> bres;
        bres.push_back("");
        return bres;
    } else if (sr > dr || sc > dc) {
        vector<string> bres;
        return bres;
    }

    vector<string> paths;

    for (int hms = 1; hms <= dc - sc; hms++) {
        vector<string> hpaths = getMazePaths(sr, sc + hms, dr, dc);
        for (string hpath : hpaths) {
            paths.push_back("h" + to_string(hms) + hpath);
        }
    }

    for (int vms = 1; vms <= dr - sr; vms++) {
        vector<string> vpaths = getMazePaths(sr + vms, sc, dr, dc);
        for (string vpath : vpaths) {
            paths.push_back("v" + to_string(vms) + vpath);
        }
    }

    for (int dms = 1; dms <= dr - sr && dms <= dc - sc; dms++) {
        vector<string> dpaths = getMazePaths(sr + dms, sc + dms, dr, dc);
        for (string dpath : dpaths) {
            paths.push_back("d" + to_string(dms) + dpath);
        }
    }

    return paths;
}

