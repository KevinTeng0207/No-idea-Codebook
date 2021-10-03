import sys
line = sys.stdin.readline() // 讀一行
D, R, N = map(int, line[:-1].split()) // 分三個 int 變數

print(*objects, sep=' ', end='\n', file=sys.stdout, flush=False)
objects -- /*表示可以一次輸出多個對象。輸出多個對象時，需要使用、複數請求。*/
sep -- /*分開多個對象，默認值是一個整體。*/
end -- /*默認值是換行符 '\n'，我們可以使用其他字符串。*/
file -- /*要寫入的文件對象。*/
flush -- /*輸出是否被刷新通常決定於文件，但如果flush關鍵字參數為True，流會被強制刷新。*/