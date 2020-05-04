# Windows下基于Git的首次Github项目推送

==[Date]20200504tue==
==[Author]DaSinging==
==[Start]==

@[TOC](目录)

## 1.准备

 - github账号
 - windwos下git工具
 - ssh密钥
 - 一个想要推送的小项目

## 2.创建github账号
自己注册，此处不再详细讲述。
 ![github账号登陆](https://img-blog.csdnimg.cn/20200504205739835.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)
然后登陆你的github账号。
## 3.安装windows本地git工具
### 3.1.下载安装程序
官方下载地址（不知何年何月才下得）：[https://git-scm.com/downloads](https://git-scm.com/downloads)

镜像文件地址（喝口水的功夫就下好了）：[https://npm.taobao.org/mirrors/git-for-windows/](https://npm.taobao.org/mirrors/git-for-windows/)

### 3.2.点击安装程序
点开安装程序，开始安装git。
 ![git安装程序](https://img-blog.csdnimg.cn/20200504210030460.png#pic_center)

此处不再叙述安装过程，参见参考资料：
 - Git下载安装及设置详细教程：[https://blog.csdn.net/sanxd/article/details/82624127](https://blog.csdn.net/sanxd/article/details/82624127)


### 3.3.cmd下检查git是否安装成功
命令： ```git```
结果：出现下面那一大溜东西，说明git安装成功。
 ![cmd下检查git安装成功](https://img-blog.csdnimg.cn/20200504210803441.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)
## 4.配置git
windows桌面上，右击菜单选择“Git Bash Here”。 
![使用Git Bash](https://img-blog.csdnimg.cn/20200504210925969.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

进行环境变量配置，输入你的github账号的邮箱，和随便一个名字：
命令：```git config --global user.name "你的名字"```
命令：```git config --global user.email "你的邮箱"```
检查一下是否配置成功：
命令：```git config --global --list```
结果：出现你的名字和邮箱，说明配置成功。
 ![结果出现你的名字](https://img-blog.csdnimg.cn/20200504211005679.png#pic_center)
## 5.生成SSH
### 5.1.开始生成SSH
命令：```ssh-keygen -t rsa –C "你的邮箱"```
接着一路按回车键。
 ![生成SSH](https://img-blog.csdnimg.cn/20200504211051406.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)
去C盘检查一下是否成功生成。
 ![C盘有个.ssh隐藏文件夹](https://img-blog.csdnimg.cn/20200504211125250.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)
有两个文件，带“.pub”的那个是公钥。
 ![两个文件](https://img-blog.csdnimg.cn/20200504211151987.png#pic_center)
用记事本打开“id_rsa.pub”文件并复制其中的所有内容，登陆github账号，进入设置界面。
 ![进入github设置](https://img-blog.csdnimg.cn/2020050421122191.png#pic_center)

选择“SSH and GPG Keys”并创建新的SSH密钥。
 ![SSH设置](https://img-blog.csdnimg.cn/20200504211236143.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

标题随便写一个，粘贴刚才复制的文件内容。
 ![SSH标题和内容填写](https://img-blog.csdnimg.cn/2020050421130912.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

5.2.检查一下SSH是否配置成功
命令：```ssh -T git@github.com```
 ![检查SSH填写成功](https://img-blog.csdnimg.cn/20200504211343741.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

然后去C盘看看，多了一个文件，说明SSH配置成功。
 ![多了一个文件](https://img-blog.csdnimg.cn/20200504211425402.png#pic_center)

## 6.创建本地仓库
找一个磁盘，磁盘里找一个地方，建一个文件夹：
命令：```cd d:```
命令：```mkdir mygit```
命令：```cd mygit```
 ![建个文件夹](https://img-blog.csdnimg.cn/20200504211500188.png#pic_center)

初始化这个文件夹，把它变成仓库：
命令：```git init```
结果：出现一个隐藏文件夹。
 ![初始化文件夹使它成为仓库](https://img-blog.csdnimg.cn/20200504211539735.png#pic_center)
![发现多了一个隐藏文件夹.git](https://img-blog.csdnimg.cn/20200504211603407.png#pic_center)

 
时刻检查一下仓库的状态：
命令：```git status```
 ![检查仓库状态](https://img-blog.csdnimg.cn/20200504211924477.png#pic_center)

把你的项目从其他地方复制粘贴进去，必须有一个readme.md文件：
 
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200504211711965.png#pic_center)
![](https://img-blog.csdnimg.cn/20200504211642593.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

将所有文件添加到缓冲区：
命令：```git add .```
 ![将文件放到缓冲区](https://img-blog.csdnimg.cn/20200504212026805.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

将文件添加到仓库：
命令：```git commit –m "Add all files."```
 ![将文件添加到仓库](https://img-blog.csdnimg.cn/20200504212109451.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

本地仓库准备完毕。
## 7.创建远程仓库
回到github账号，单击头像选择“你的仓库”：
 ![选择“你的github仓库”](https://img-blog.csdnimg.cn/20200504212139677.png#pic_center)

新建一个仓库：
 ![新建仓库的按钮](https://img-blog.csdnimg.cn/20200504212210951.png#pic_center)

写下你的仓库的名字和仓库的描述，最后按下那个绿色的按钮：
 ![创建仓库需要填写的内容](https://img-blog.csdnimg.cn/2020050421222836.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

把那个ssh记一下，需要后面推送本地仓库的时候会用到。
 ![得到一个SSH需要记一下](https://img-blog.csdnimg.cn/20200504212252555.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

## 8.将本地仓库推送到远程仓库
首先，去Setings的Email设置下，确保一个关于你邮箱的设置没有勾上：
 ![你的github邮箱私有化选项去掉](https://img-blog.csdnimg.cn/20200504212327376.png#pic_center)

接着回到git Bash上，推送你的本地仓库里的项目：
命令：```git remote add origin git@github.com:你的名字/远程仓库的名字.git```
命令：```git push –u origin master```
 ![将本地仓库推送到github的远程仓库](https://img-blog.csdnimg.cn/20200504212415483.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

噔噔噔~
 ![欣慰地在github上看到你本地仓库里的项目](https://img-blog.csdnimg.cn/20200504212451851.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

## 9.参考资料

 - git push时提示The authenticity of host 'github.com (52.74.223.119)' can't be established. [https://www.cnblogs.com/illusion1010/p/11667069.html
](https://www.cnblogs.com/illusion1010/p/11667069.html)
- Git的使用--如何将本地项目上传到Github. [https://zhuanlan.zhihu.com/p/28377120](https://zhuanlan.zhihu.com/p/28377120)
- windows下如何使用Git将本地项目上传到GitHub. [https://zhuanlan.zhihu.com/p/122562060](https://zhuanlan.zhihu.com/p/122562060)
- Git下载、安装与环境配置 [https://blog.csdn.net/huangqqdy/article/details/83032408](https://blog.csdn.net/huangqqdy/article/details/83032408)
- 第一次使用Git上传本地项目到github上 [https://www.cnblogs.com/sdcs/p/8270029.html](https://www.cnblogs.com/sdcs/p/8270029.html)
- GIT使用笔记 [https://www.freesion.com/article/796681245/](https://www.freesion.com/article/796681245/)

## 10.附录
### 10.1.git命令
查看ssh是否已经存在：
命令：```cd ~/.ssh```
结果：
 ![查看ssh是否存在结果1](https://img-blog.csdnimg.cn/20200504212756595.png#pic_center)

或者
 ![查看ssh是否存在结果2](https://img-blog.csdnimg.cn/20200504212813842.png#pic_center)

删除origin
命令：```git remote rm origin```
### 10.2.git卸载的一部分操作
 ![git卸载的一部分操作](https://img-blog.csdnimg.cn/20200504212914956.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

### 10.3.删除远程仓库
点进仓库，接着找仓库的设置：
 ![仓库内部的设置](https://img-blog.csdnimg.cn/20200504212954328.png#pic_center)

滚动鼠标滑轮，将页面拉到最底下，点击那个“删除仓库”的红色按钮：
 ![页面拉到底](https://img-blog.csdnimg.cn/20200504213009203.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

github怕你是手抽才删库的，要求你照着上面键盘输入一串字符。
 ![输入一部分内容](https://img-blog.csdnimg.cn/20200504213022941.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NPSWFqNA==,size_16,color_FFFFFF,t_70#pic_center)

红色的按钮亮起来了，点一下。
 ![红色按钮可以点击了](https://img-blog.csdnimg.cn/20200504213038333.png#pic_center)

你的仓库没了，回不去了。
## ==[End]==

