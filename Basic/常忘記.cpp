round(double f); // 四捨五入
ceil(double f);  // 無條件捨去
floor(double f); //無條件進入
__builtin_popcount(int n) // 32bit有多少 1
to_string(int s) // int to string
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