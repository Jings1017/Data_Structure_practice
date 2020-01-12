先做兩個副程式
分別為pushf,popf
pushf:
將新元素從陣列前方加入
若陣列本來為空，則存進a[0]
否則將原陣列的元素往後移一格，再將新元素放至a[0]
popf:
將陣列最前方的元素移出

主程式
先scan指令為push_front,push_back,pop_front,pop_back,show哪一種
再利用if-else迴圈及strcmp進行判斷

push_front 
scan 欲放進的元素，呼叫pushf，再將n+1，回到begin進行下一個指令

push_back
直接將新元素放到陣列最後，n+1，回到begin

pop_front
呼叫popf，再將n-1，回到begin

pop_back
直接將陣列最後一個元素移除，n-1，回到begin

show
印出陣列deque，程式結束