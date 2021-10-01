round(double f); // 四捨五入
ceil(double f);  // 無條件捨去
floor(double f); //無條件進入
vector<int>::iterator it = lower_bound(v.begin(), v.end(), val); //用binary search找大於或等於val的最小值的位置
vector<int>::iterator it = upper_bound(v.begin(), v.end(), val); //用binary search找大於val的最小值的位置

/*queue*/
queue<datatype> q;
front(); /*取出最前面的值(沒有移除掉喔!!)*/
back();  /*取出最後面的值(沒有移除掉!!)*/
pop();   /*移掉最前面的值*/
push();  /*新增值到最後面*/
empty(); /*回傳bool,檢查是不是空的queue*/
size();  /*queue 的大小*/

/*stack*/
stack<datatype> s;
top();   /*取出最上面的值(沒有移除掉喔!!)*/
pop();   /*移掉最上面的值*/
push();  /*新增值到最上面*/
empty(); /*回傳bool,檢查是不是空的stack*/
size();  /*stack 的大小*/

/*unordered_set*/
unordered_set<datatype> s; 
unordered_set<datatype> s(arr,arr+n); /*initial with array*/
insert(); /*插入值*/
erase(); /*刪除值*/
empty(); /*回傳bool,檢查是不是空的unordered_set*/
count(); /*判斷元素是否存在 存在回傳1 反之則回傳0*/
