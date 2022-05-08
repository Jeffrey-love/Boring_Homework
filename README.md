# Boring_Homework
  
  就当是个笔记叭~~~    
  
## python的一些小语法  
输入一串用空格隔开的数字，最后以int型存放到列表li中：:smiley:  
`st = input()`   
`li = [int(x) for x in st.split()]`    
  输入两个用空格隔开的数字，以字符型赋值给r和c:  
`str1 = input()`   
`r, c = str1.split()`  
  
输出结束后不换行：:satisfied:    
`print(pp[i][j], end="")`
  
文件操作：  
```python
    with open('article_de.txt', 'a') as f:
        f.write(plain_message)    # 文件写入
    with open('article_en.txt', 'r') as f:
        message = f.read()    # 文件读取
```

将字典转换成列表
```python
    dict_de = count_each_char(message)
    dict_de = dict(dict_de)
```
      
同时遍历字典的key和value
```python
for item, fre in dict_text.items():
    if item in ZIMUBIAO:
        minus = abs(frequency-fre)
        if minus < min1:
            min1 = minus
            lett = item
```
  
    
### 一些运算符~  
`//` 如a//b是a/b向下取整



  
## Java语法学习
输入一行字符串：  
```java
import java.util.*;
Scanner in = new Scanner(System.in);
String s1 = in.nextLine();
```
