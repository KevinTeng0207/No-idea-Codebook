round(double f);           // 四捨五入
ceil(double f);            // 無條件捨去
floor(double f);           //無條件進入
__builtin_popcount(int n); // 32bit有多少 1
to_string(int s);          // int to string

/** 全排列要先 sort !!! **/
next_permutation(num.begin(), num.end());
prev_permutation(num.begin(), num.end());
//用binary search找大於或等於val的最小值的位置
vector<int>::iterator it = lower_bound(v.begin(), v.end(), val);
//用binary search找大於val的最小值的位置
vector<int>::iterator it = upper_bound(v.begin(), v.end(), val);
/*queue*/

queue<datatype> q;
front(); /*取出最前面的值(沒有移除掉)*/
back();  /*取出最後面的值(沒有移除掉)*/
pop();   /*移掉最前面的值*/
push();  /*新增值到最後面*/
empty(); /*回傳bool,檢查是不是空的queue*/
size();  /*queue 的大小*/

/*stack*/
stack<datatype> s;
top();   /*取出最上面的值(沒有移除掉)*/
pop();   /*移掉最上面的值*/
push();  /*新增值到最上面*/
empty(); /*bool 檢查是不是空*/
size();  /*stack 的大小*/

/*unordered_set*/
unordered_set<datatype> s;
unordered_set<datatype> s(arr, arr + n);
/*initial with array*/
insert(); /*插入值*/
erase();  /*刪除值*/
empty();  /*bool 檢查是不是空*/
count();  /*判斷元素存在回傳1 無則回傳0*/
