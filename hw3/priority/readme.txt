eval.cpp

先輸入prefix
進入到for-loop裡面
用if-else判斷string中每一格存取的資料
如果是空格 則continue
如果是數字 將數字push到stack中
其中 因輸入二位數時會有問題 故再用if-else進行判斷處理
如果是+-*/ 則將stack中最上面兩個數pop出來進行運算  
算完之後再push進stack裡
for-loop run完之後 將stack中的值輸出即所求

*********************************************************
prefix.cpp

主程式:
宣告infix，scan infix，
執行function in2pre ，結束程式

副程式priority:
參考課本，定義各個運算子的權重，方便主程式使用

副程式in2pre:
主要是將infix轉成prefix
利用strlen計算字串大小
進到while(1)迴圈
先用switch case 分類成左右括號、其他運算子、運算元

其他運算子:
這裡只處理十種不同的運算子，
依權重(副程式)比較大小，
權重較大者可壓過權重較小者，故push進stack
反之，權重較小者無法壓過權重較大者，
需先將stack裡權重較大者pop出來

左右括號:
當遇到右括號時，將之後的運算子push進stack，
直到遇到左括號，則將這一段的運算子pop出來

運算元:
這裡歸類在default裡，
遇到運算元則直接放入prefix裡

當做完infix內所有元素的運算，
最後將prefix逆置即為所求。

