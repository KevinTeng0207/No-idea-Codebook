round(double f);           // 四捨五入
ceil(double f);            // 進入
floor(double f);           //捨去
__builtin_popcount(int n); // 32bit有多少 1
to_string(int s);          // int to string

cout << setprecision(位數) // cout 小數位設定
printf 型別
"%lf" // long double
"%lld" // long long int

set_union(all(a), all(b), back_inserter(d)); // 聯集 
set_intersection(all(a), all(b), back_inserter(c)); //交集

/** 全排列要先 sort !!! **/
next_permutation(num.begin(), num.end());
prev_permutation(num.begin(), num.end());
//用binary search找第一個大於或等於val的位置
vector<int>::iterator it = lower_bound(v.begin(), v.end(), val);
//用binary search找第一個大於val的位置
vector<int>::iterator it = upper_bound(v.begin(), v.end(), val);

/*找到範圍裏面的最大元素*/
max_element(n, n + len);         // n到n+len範圍內最大值
max_element(v.begin(), v.end()); // vector 中最大值
/*找到範圍裏面的最大元素*/
min_element(n, n + len);         // n到n+len範圍內最小值
min_element(v.begin(), v.end()); // vector 中最小值

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

/*tuple*/
tuple<datatype,datatype,datatype> t;
std::get<0>(t) /*Get first element of tuple*/
std::get<1>(t) /*Get second element of tuple*/
std::get<2>(t) /*Get third element of tuple*/
