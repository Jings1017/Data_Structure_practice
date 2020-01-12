先用gets輸入max heap
之後分割並存到整數陣列中 (從1存起)

輸入欲刪除的元素
利用for找到其位置並記錄下來
將最後一個元素放到該位置
然後把最後一個元素設為空

while迴圈做比大小
與hw5_1相比 不用考慮上層元素
只需考慮下層元素

如果 該元素小於left-child 且 left-child > right-child 
將該元素與left-child交換

如果 該元素小於right-child 且 left-child < right-child 
將該元素與right-child交換

輸出結果  程式結束



 
