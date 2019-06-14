# Chinese Postman Problem Report
姓名：陳錫峰 

學號：N26074922

## 如何編譯
  在根目錄下執行下列流程
  ```
  # clone project
  $ git clone --recursive https://github.com/Chen-Hsi-Feng/2019-spring-gt
  # build and run
  $ make && ./main.out
  ```
  即可在終端機中看到執行結果
  並在產生出的RESULT.txt中看到路徑答案


## 程式設定

```

　我這次實作的中國郵差問題是使用"無向圖"且"無權重"的版本
  且由於題目沒有設定輸入點的個數
  因此我的程式設定為僅能最多接受"10"個點
  並且只需在topo.txt中設定一條邊
  我即會在程式中將另一條邊補上定義為無向圖
  
  ex. a b 1 1
      b c 1 1
      c d 1 1
       
  至於capacity以及flow在此程式中沒有使用到，因此可以隨意給值

```

## 解題思路：

```

  1. 利用助教的interpret API將圖用txt檔描述好並輸入
  2. 再使用connected API判斷兩點之間是否連線來建立adjacency matrix
  3. 利用建立好的adjacency matrix來判斷哪些點的order為奇數
  4. 利用"Dijkstra演算法將距離總和最短的配對組合求出來
  5. 將配對的奇數點補邊並更新adjacency matrix完成尤拉圖
  6. 利用DFS演算法將已經更新的adjacency matrix路徑走完

  上述6點為我的主要解題思路，下面會對於上述六點做更細節的解釋

```

## 程式實作

```

  此次的中國郵差問題要求為需要走過圖中所有的邊至少一次且要求路徑為最短
  因此在程式一開始將圖藉由API輸入至程式之後，我會將奇數order的點找出來
  之所以要找奇數order點的原因是，如果一張圖中所有點的order皆為偶數
  此圖稱為尤拉圖，在尤拉圖中一定可以找到一個迴路將所有點都經過一次並且回到原點
  因此若輸入圖本身不是尤拉圖，首先我會先將她補成尤拉圖
  因為奇數order的邊基於degree-sum formula會成對出現
  因此找尋奇數點之間的最短路徑以及長度是補圖的必要工作
  我找尋最短路徑的方法是使用"Dijkstra's algorithm"
  此演算法可以用來找尋兩點之間的最短路徑
  我從網路上參考了此演算法並做了一些修改
  因為原先我參考的Dijkstra's algorithm程式僅有最短長度
  我加上了最短的路徑的trace，因此我可以找到最短的路徑並存進陣列中
  藉由此演算法最短路徑的找尋，我就可以將最短的奇數點配對並對其進行補邊
  如此一來就能得到補完邊後整體長度最短的尤拉圖
  在得到尤拉圖之後，我會進行尤拉回路的尋找
  尤拉回路的尋找我是利用DFS，"深度優先搜尋演算法"
  並且將路徑print出來且寫至檔案中完成流程。

```       
                                                  
## 執行結果

```                                                 
                                                   -----
                                                  /     \
  以我在github上的例子舉例，輸入一個總數6個點        a------f-----c
  奇數order點為4個點的圖(如右圖)，完成DFS之後        |   // |\\
  會由起點"a"開始走並走完所有邊將結果輸出如下         |  //  | \\
  a b d f b f c f e f a                           | //   |  \\
  並最後把adjacency matrix輸出檢查是否皆為0         |//    |   \\
  皆為0代表已將所有路徑走完。                       |//    |    \\
                                                  b------d     e

```

## BONUS

```

  在我實作此project時，在做關於interpret的雙向連接時發現了bug
  經過與助教討論，確實是程式的bug

```



## 參考連結

```

  [1]https://www.geeksforgeeks.org/dijkstras-shortest-path-with-minimum-edges/fbclid=IwAR2XtFJXYBbffodIMhqsxKuCJpPDiyf-8oOkY6aUtwtchnkAC_-10OevxNs
  
  [2]https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/

```


