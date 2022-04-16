# 1. git的三种状态说一下，分别什么时候对应什么状态？

3个工作区的概念：**Git 仓库、工作目录以及暂存区域**。其中工作目录比较好理解，就是我们开发时修改文件的那些目录，Git 仓库就是我们项目目录下面的 .git目录中的内容，而暂存区域是保存已经被Git标记过，将要提交保存到Git数据库中的文件的地方

文件从我们创建到编辑完提交Git帮我们记录，一共要经历3种状态：

**已修改（modified）、 已暂存（staged）和已提交（committed）**

1. 刚刚开始时编辑文件，这个时候文件是处于 已修改（modified） 状态，文件是在工作目录

2. 修改完文件，我们执行git add，这个时候文件就变为 已暂存（staged）状态，文件信息进入暂存区域，内容被保存到Git数据库中

3. 然后我们执行git commit，文件就变为已提交（committed）状态，创建了一个提交记录保存到了Git 仓库

`git status`命令用于显示工作目录和暂存区的状态。

# 2. git分支，我们一般怎么用

创建分支命令：

```
git branch (branchname)
```

删除分支命令：

```
git branch -d (branchname)
```

切换分支命令:

```
git checkout (branchname)
```

当你切换分支的时候，Git 会用该分支的最后提交的快照替换你的工作目录的内容， 所以多个分支不需要多个目录。

合并分支命令:

```
git merge 
```

# 冲突解决方法

**第一种情况：**

线上为master主分支以及自己的分支 my_branch

本地有master主分支以及自己的分支 my_branch

本地自己分支开发完之后

1. 先提交本地自己分支开发代码

   ```shell
   git add xxx
   git commit -m “xxx”
   ```

2. 本地切换到master分支

   ```shell
   git checkout master
   ```

3. 更新master分支代码

   ```shell
   git pull
   ```

4. 切换到自己的分支

   ```shell
   git checkout my_branch
   ```

5. 合入master最新代码
   ``` shell
   git merge master
   ```

   建议使用：git rebase master

6. 解决冲突
   如果第5步使用的是 git merge master
   使用`git status` 查看冲突文件，
   解决冲突文件后重新add以及commit再push到线上自己的分支
   如果第5步使用的是 git rebase master
   使用git status 查看冲突文件，
   解决冲突文件后，把冲突文件add，
   所有冲突文件add完毕后，使用 git rebase --continue 继续合并
   再使用git status 查看状态，没问题后 push到线上自己的分支

**第一种情况：**

线上为master主分支以及自己的分支 my_branch

本地为master主分支，也就是说本地在master分支上开发，开发完成后提交到线上自己的分支，这样开发会减少一些步骤，方便，本人喜欢这种方式开发

本地master分支开发完之后
**方式一：**

1. 先提交本地自己分支开发代码

   ```shell
   git add xxx
   git commit -m “xxx”
   ```

2. 更新master分支代码

   ```shell
   git pull
   ```

   建议使用: git pull --rebase`

3. 解决冲突
   如果第2步使用的是 git pull
   使用git status 查看冲突文件，
   解决冲突文件后重新add以及commit再push到线上自己的分支 git push origin master:my_branch
   如果第2步使用的是 git pull --rebase
   使用git status 查看冲突文件，
   解决冲突文件后，把冲突文件add，
   所有冲突文件add完毕后，使用 git rebase --continue 继续合并
   再使用git status 查看状态，没问题后 push到线上自己的分支 git push origin master:my_branch

**方式二：**

1. 把自己开发的代码储藏起来，这样代码就是没有变动的情况，下面更新代码就不会有冲突

   ```
   git stash
   ```

2. 更新代码

   ```
   git pull
   ```

3. 还原刚才储藏的代码

   ```
   git stash apply
   ```

4. 查看冲突，解决冲突

   ```
   git status -s
   ```

5. 解决完冲突后就可以像正常提交代码一样操作了，

   ```
   git add xxx
   git commit -m “xxx”
   git push origin master:my_branch
   ```

   