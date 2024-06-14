//#################### all permuation1 of number  ####################

void permutations(vector<int>& boxes, int ci, int ti) {
    if (ci > ti) {
        for (int i = 0; i < boxes.size(); i++) {
            cout << boxes[i];
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < boxes.size(); i++) {
        if (boxes[i] == 0) {
            boxes[i] = ci;
            permutations(boxes, ci + 1, ti);
            boxes[i] = 0;
        }
    }
}

//#################### all permuation2 of number  ####################


void permutations(int cb, int tb, vector<int>& items, int ssf, int ts, string asf) {
    if (cb > tb) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    for (int i = 0; i < items.size(); i++) {
        if (items[i] == 0) {
            items[i] = cb;
            permutations(cb + 1, tb, items, ssf + 1, ts, asf + to_string(i + 1));
            items[i] = 0;
        }
    }
    permutations(cb + 1, tb, items, ssf, ts, asf + "0");
}
//#################### all combination1 of number  ####################



void combinations(int cb, int tb, int ssf, int ts, string asf) {
    if (cb > tb) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    combinations(cb + 1, tb, ssf + 1, ts, asf + "i");
    combinations(cb + 1, tb, ssf, ts, asf + "-");
}



//#################### all combination2 of number  ####################


void combinations(vector<int>& boxes, int ci, int ti, int lb) {
    if (ci > ti) {
        for (int i = 0; i < boxes.size(); i++) {
            cout << (boxes[i] == 0 ? "-" : "i");
        }
        cout << endl;
        return;
    }

    for (int i = lb + 1; i < boxes.size(); i++) {
        if (boxes[i] == 0) {
            boxes[i] = ci;
            combinations(boxes, ci + 1, ti, i);
            boxes[i] = 0;
        }
    }
}


//#################### all 1D queen place permuation  mtlb q1 q2 q3 q4 all different  ####################

void queensPermutations(int qpsf, int tq, vector<vector<int>>& chess) {
    if (qpsf == tq) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess[row].size(); col++) {
                cout << (chess[row][col] != 0 ? "q" + to_string(chess[row][col]) + "\t" : "\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < chess.size(); row++) {
        for (int col = 0; col < chess[row].size(); col++) {
            if (chess[row][col] == 0) {
                chess[row][col] = qpsf + 1;
                queensPermutations(qpsf + 1, tq, chess);
                chess[row][col] = 0;
            }
        }
    }
}


//#################### all 1D queen combination mtlb q q q q sab identical hai ####################


void queensCombinations(int qpsf, int tq, int row, int col, string asf) {
    if (row == tq) {
        if (qpsf == tq) {
            cout << asf << endl;
        }
        return;
    }

    queensCombinations(qpsf + 1, tq, (col == tq - 1) ? row + 1 : row, (col == tq - 1) ? 0 : col + 1, (col == tq - 1) ? asf + "q\n" : asf + "q");
    queensCombinations(qpsf, tq, (col == tq - 1) ? row + 1 : row, (col == tq - 1) ? 0 : col + 1, (col == tq - 1) ? asf + "\n" : asf + "-");
}
//#################### all 2D queen place permuation wala mtlb q1 q2 q3 q4 sab alag hai ####################


void queensPermutations(int qpsf, int tq, vector<vector<int>>& chess) {
    if (qpsf == tq) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess[row].size(); col++) {
                cout << (chess[row][col] != 0 ? "q" + to_string(chess[row][col]) + "\t" : "\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int row = 0; row < chess.size(); row++) {
        for (int col = 0; col < chess[row].size(); col++) {
            if (chess[row][col] == 0) {
                chess[row][col] = qpsf + 1;
                queensPermutations(qpsf + 1, tq, chess);
                chess[row][col] = 0;
            }
        }
    }
}


//#################### all 2D queen combination mtlb q q q q sab identical hai ####################


void queensCombinations(int qpsf, int tq, int row, int col, string asf) {
    if (row == tq) {
        if (qpsf == tq) {
            cout << asf << endl;
        }
        return;
    }

    queensCombinations(qpsf + 1, tq, (col == tq - 1) ? row + 1 : row, (col == tq - 1) ? 0 : col + 1, (col == tq - 1) ? asf + "q\n" : asf + "q");
    queensCombinations(qpsf, tq, (col == tq - 1) ? row + 1 : row, (col == tq - 1) ? 0 : col + 1, (col == tq - 1) ? asf + "\n" : asf + "-");
}
//#################### 1d or 2d all Queen choose kaisa kruunga combination sa ####################
// 1-2D permutations aur combination sa banega
// Q1 
// Q2
// Q3
// Q4
// Q5
// Q6
// Repeat hai

void queensCombinations(int qpsf, int tq, vector<vector<bool>>& chess, int lcno) {
    if (qpsf == tq) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess[row].size(); col++) {
                cout << (chess[row][col] ? "q\t" : "-\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = lcno + 1; i < chess.size() * chess[0].size(); i++) {
        int row = i / chess[0].size();
        int col = i % chess[0].size();
        if (chess[row][col] == false) {
            chess[row][col] = true;
            queensCombinations(qpsf + 1, tq, chess, row * chess[0].size() + col);
            chess[row][col] = false;
        }
    }
}
//####################  all N Queen branch and bound    ####################
void solution(vector<vector<bool>>& board, int row, vector<bool>& cols, vector<bool>& ndiag, vector<bool>& rdiag, string asf) {
    if (row == board.size()) {
        cout << asf << "." << endl;
        return;
    }

    for (int col = 0; col < board.size(); col++) {
        if (!cols[col] && !ndiag[row + col] && !rdiag[row - col + board.size() - 1]) {
            board[row][col] = true;
            cols[col] = true;
            ndiag[row + col] = true;
            rdiag[row - col + board.size() - 1] = true;
            solution(board, row + 1, cols, ndiag, rdiag, asf + to_string(row) + to_string(col) + ", ");
            board[row][col] = false;
            cols[col] = false;
            ndiag[row + col] = false;
            rdiag[row - col + board.size() - 1] = false;
        }
    }
}

 vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<bool> cols(n, false);
    vector<bool> ndiag(2 * n - 1, false);
    vector<bool> rdiag(2 * n - 1, false);

    solution(board, 0, cols, ndiag, rdiag, "");

//#################### 1d or 2d all knight choose   combination  ####################
// 1-2D permutations aur combination sa banega
// Q1 
// Q2
// Q3
// Q4
// Q5
// Q6
// Repeat hai

bool isKnightSafe(vector<vector<bool>>& chess, int i, int j) {
    if (i - 1 >= 0 && j - 2 >= 0 && chess[i - 1][j - 2]) {
        return false;
    }
    if (i - 1 >= 0 && j + 2 < chess.size() && chess[i - 1][j + 2]) {
        return false;
    }
    if (i - 2 >= 0 && j - 1 >= 0 && chess[i - 2][j - 1]) {
        return false;
    }
    if (i - 2 >= 0 && j + 1 < chess.size() && chess[i - 2][j + 1]) {
        return false;
    }
    return true;
}

void nknights(int kpsf, int tk, vector<vector<bool>>& chess, int lcno) {
    if (kpsf == tk) {
        for (int row = 0; row < chess.size(); row++) {
            for (int col = 0; col < chess.size(); col++) {
                cout << (chess[row][col] ? "k\t" : "-\t");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int i = lcno + 1; i < chess.size() * chess.size(); i++) {
        int row = i / chess.size();
        int col = i % chess.size();
        if (!chess[row][col] && isKnightSafe(chess, row, col)) {
            chess[row][col] = true;
            nknights(kpsf + 1, tk, chess, row * chess.size() + col);
            chess[row][col] = false;
        }
    }
}




//////////////////////////////////////Permutation of words///////////////////


//#################### Saare permuation of number ka repeated char bhi hai ####################

void generateWords(int cs, int ts, unordered_map<char, int>& fmap, string asf) {
    if (cs > ts) {
        cout << asf << endl;
        return;
    }
    for (auto& kv : fmap) {
        char ch = kv.first;
        if (fmap[ch] > 0) {
            fmap[ch]--;
            generateWords(cs + 1, ts, fmap, asf + ch);
            fmap[ch]++;
        }
    }
}

//#################### all permuation of number ka repeated char bhi hai ####################

void generateWords(int cc, string str, vector<char>& spots, unordered_map<char, int>& lastOccurrence) {
    if (cc == str.length()) {
        for (char ch : spots) {
            cout << ch;
        }
        cout << endl;
        return;
    }

    char ch = str[cc];
    int lo = lastOccurrence[ch];

    for (int i = lo + 1; i < spots.size(); i++) {
        spots[i] = ch;
        lastOccurrence[ch] = i;

        if (spots[i] == '\0') {
            generateWords(cc + 1, str, spots, lastOccurrence);
            lastOccurrence[ch] = lo;
            spots[i] = '\0';
        }
    }
}

//#################### all k length k distict string ####################

void generateSelection(string ustr, int cs, int ts, int lc, string asf) {
    if (cs == ts) {
        cout << asf << endl;
        return;
    }

    for (int i = lc + 1; i < ustr.length(); i++) {
        generateSelection(ustr, cs + 1, ts, i, asf + ustr[i]);
    }
}


//#################### all k length ka string   words  ####################
void generateSelection(int cc, string ustr, int ssf, int ts, unordered_map<char, int>& unique, string asf) {
    if (cc == ustr.length()) {
        if (ssf == ts) {
            cout << asf << endl;
        }
        return;
    }

    char ch = ustr[cc];
    char fasf[ssf];
    for (int i = 0; i < ssf; ++i) {
        fasf[i] = ch;
    }

    for (int i = unique[ch]; i > 0; --i) {
        generateSelection(cc + 1, ustr, ssf + i, ts, unique, asf + string(fasf, fasf + ssf));
        generateSelection(cc + 1, ustr, ssf, ts, unique, asf);
    }
}

//#################### all k length  string out of words ####################

void generateSelection(int cs, int ts, string ustr, unordered_map<char, int>& unique, int ls, string asf) {
    if (cs == ts) {
        cout << asf << endl;
        return;
    }

    for (int i = ls; i < ustr.length(); i++) {
        char ch = ustr[i];
        if (unique[ch] > 0) {
            unique[ch]--;
            generateSelection(cs + 1, ts, ustr, unique, i, asf + ch);
            unique[ch]++;
        }
    }
}



//#################### sudoku####################

void display(vector<vector<int>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<int>>& board, int row, int col, int val) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == val || board[row][i] == val || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) {
            return false;
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& board, int i, int j) {
    if (i == 9) {
        display(board);
        return;
    }

    int ni = 0, nj = 0;
    if (j == 8) {
        ni = i + 1;
        nj = 0;
    } else {
        ni = i;
        nj = j + 1;
    }

    if (board[i][j] != 0) {
        solveSudoku(board, ni, nj);
    } else {
        for (int val = 1; val <= 9; val++) {
            if (isValid(board, i, j, val)) {
                board[i][j] = val;
                solveSudoku(board, ni, nj);
                board[i][j] = 0;
            }
        }
    }
}
bool isValid(vector<vector<int>>& board, int x, int y, int val) {
    int n = board.size();

    // Check row for the same value
    for (int i = 0; i < n; i++) {
        if (board[x][i] == val) {
            return false;
        }
    }

    // Check column for the same value
    for (int i = 0; i < n; i++) {
        if (board[i][y] == val) {
            return false;
        }
    }

    // Determine the start of the subgrid
    int startX = x / 3 * 3;
    int startY = y / 3 * 3;

    // Check subgrid for the same value
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startX + i][startY + j] == val) {
                return false;
            }
        }
    }

    return true;
}


//#################### k partition of n elements ####################
int counter = 1;

void solution(int i, int n, int k, int rssf, std::vector<std::vector<int>>& ans) {
    if (i == n + 1) {
        if (rssf == k) {
            std::cout << counter << ". ";
            counter++;
            for (std::vector<int> a : ans) {
                std::cout << "[";
                for (int val : a) {
                    std::cout << val << " ";
                }
                std::cout << "] ";
            }
            std::cout << std::endl;
        }
        return;
    }

    for (int j = 0; j < ans.size(); j++) {
        if (ans[j].size() == 0) {
            ans[j].push_back(i);
            solution(i + 1, n, k, rssf + 1, ans);
            ans[j].pop_back();
            break;
        } else {
            ans[j].push_back(i);
            solution(i + 1, n, k, rssf, ans);
            ans[j].pop_back();
        }
    }
}



//#################### k partition with equal sum elements ####################


void solution(int arr[], int vidx, int n, int k, int subsetSum[], int ssssf, std::vector<std::vector<int>>& ans) {
    if (vidx == n) {
        if (ssssf == k) {
            int isum = subsetSum[0];
            bool flag = true;
            for (int i = 1; i < k; i++) {
                if (subsetSum[i] == isum) {
                    continue;
                } else {
                    flag = false;
                    break;
                }
            }
            if (flag == true) {
                for (std::vector<int> a : ans) {
                    for (int val : a) {
                        std::cout << val << " ";
                    }
                    std::cout << "\n";
                }
            }
            return;
        }
    }

    for (int j = 0; j < ans.size(); j++) {
        if (ans[j].size() == 0) {
            ans[j].push_back(arr[vidx]);
            subsetSum[j] += arr[vidx];
            solution(arr, vidx + 1, n, k, subsetSum, ssssf + 1, ans);
            ans[j].pop_back();
            subsetSum[j] -= arr[vidx];
            break;
        } else {
            ans[j].push_back(arr[vidx]);
            subsetSum[j] += arr[vidx];
            solution(arr, vidx + 1, n, k, subsetSum, ssssf, ans);
            ans[j].pop_back();
            subsetSum[j] -= arr[vidx];
        }
    }
}

//#################### word break problem ####################
dict = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    std::string str = "ilikeicecreamandmango";

    wordBreak(str, "", dict);



void wordBreak(std::string str, std::string ans, std::unordered_set<std::string>& dict) {
    if (str.length() == 0) {
        std::cout << ans << std::endl;
        return;
    }

    for (int i = 0; i < str.length(); i++) {
        std::string left = str.substr(0, i + 1);
        if (dict.find(left) != dict.end()) {
            std::string right = str.substr(i + 1);
            wordBreak(right, ans + left + " ", dict);
        }
    }
}