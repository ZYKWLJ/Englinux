### 一款支持前中后全匹配的内置4、6级单词、音标、释义查询软件
![image](https://github.com/user-attachments/assets/c3271884-3762-42f0-899d-7b6f40c256a7)

#### 1.使用说明——1个核心命令，4个其他命令
##### 核心find命令
命令形式：find|f [%]word[%] [-lib] [-1234]
![image](https://github.com/user-attachments/assets/ef25e702-dd86-4660-89ad-2e9bf20edb1a)
例如：

##### 二级指令——全匹配：
```shell
find and
```
将显示4、6级搜索到的全部精确匹配的单词。
![image](https://github.com/user-attachments/assets/7a01e4b8-1a14-410b-b5f9-b907a602e146)

##### 二级指令——前缀匹配：
如下命令，将显示4、6级搜索到的全部以au为前缀的单词。
```shell
find au%
```
![image](https://github.com/user-attachments/assets/0d3a158b-7315-4daf-9be3-419af5a270d1)

##### 二级指令——后缀匹配：
如下命令，将显示4、6级搜索到的全部以lish为后缀的单词。
```shell
find %lish
```
![image](https://github.com/user-attachments/assets/32f1b88b-9389-40e2-89ce-f65048710bc3)

##### 二级指令——包含匹配：
如下命令，将显示4、6级搜索到的全部包含ab的单词。
```shell
find %ab%
```
![image](https://github.com/user-attachments/assets/26677c39-e778-418d-9653-e7324c0d0a1e)


##### 三级指令——指定查找库
**注意，目前只内置了4、6级库，且参数必须包含前缀-**
如下命令，将会从4级库里面查找以ac为前缀的单词
```shell
find ac% -4
```
![image](https://github.com/user-attachments/assets/9234183a-0489-4909-91e8-7233e3cdba23)

如下命令，将会从6级库里面查找以end为后缀的单词
```shell
find %end -6
```
![image](https://github.com/user-attachments/assets/8f1d7ca5-5e64-457e-9ae5-98a8bc9b7860)


##### 四级指令——指定显示列数
**注意，0代表不显示，1代表显示单词在词库中的下标，2代表单词，3代表音标，4代表释义**，参数不能多余4个，必须包含前缀-
如下命令，将会从4级库里面查找以ac为前缀的单词,并按照**单词-下标-音标-释义**显示
```shell
find ac% -4 -2143
```
![image](https://github.com/user-attachments/assets/d81cf713-9f22-438c-b041-e379c60fac2e)

如下命令，将会从4级库里面查找以ac为前缀的单词,并按照**单词-单词-释义**显示
```shell
find ac% -4 -224
```
![image](https://github.com/user-attachments/assets/e6c2ce45-cd35-4c2d-9855-bb4458bcd50e)
