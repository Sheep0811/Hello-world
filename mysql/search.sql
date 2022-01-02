SELECT Sname--1.查询平均成绩大于80的学生姓名。
FROM student
WHERE Sno IN 
  (
    select Sno
    FROM sc
    GROUP BY Sno
    HAVING AVG(Grade) > 80
  );
select--2.查询课程成绩大于课程平均成绩的选课信息，显示学生姓名、课程名称和成绩。
(
    select Sname
    from student
    where student.sno = sc.sno
) as Sname,
(
    select cname
    from course
    where cno = sc.cno
) as Cname,sc.Grade
from
  sc,(
    select cno as cno, AVG(Grade) as grade
    from sc
    group by cno
  ) as c
Where
  sc.cno = c.cno
  and sc.grade > c.grade;

SELECT *--3.查询至少选修了C1和C2课程的学生名单。
FROM student
WHERE Sno IN
(
  SELECT a.Sno
  FROM sc as a,sc as b
  WHERE a.Sno=b.Sno AND a.cno=1 and b.cno=2
);

SELECT *--4.查询选修了C1课程而没有选修C2课程的学生名单。
FROM student
where Sno IN
(
  SELECT Sno
  FROM  sc 
  WHERE sc.Cno=1 and sc.Sno NOT IN
  (
    SELECT Sno
    FROM sc
    WHERE sc.Cno=2
  )
);

SELECT course.Cno,ifnull(nums,0)--5.统计每门课程成绩大于80分的学生数。
FROM course left JOIN 
(select Cno,COUNT(Sno) as nums from sc where Grade>80 GROUP BY Cno) as a
ON course.Cno=a.Cno
ORDER BY course.Cno;


SELECT AVG(Grade)--6. 统计计算机系“CS”学生的平均分
FROM sc
WHERE sno IN
(
  SELECT sno
  FROM student
  WHERE Sdept="CS"
);

SELECT COUNT(a.Sno)--7. 统计至少选修了两门课程的学生数
FROM 
(
 SELECT Sno
 From sc GROUP BY sc.Sno
 HAVING COUNT(Cno)>=2
) a;

SELECT student.*--8. 查询至少选修了两门课程的学生名单
FROM student, 
(
 SELECT Sno
 From sc GROUP BY Sno
 HAVING COUNT(Cno)>=2
) a
WHERE student.Sno=a.Sno;

SELECT Course.*--9. 查询没有被选修的课程信息
FROM course
WHERE Cno NOT IN
(
  SELECT distinct Cno
  FROM sc
);

SELECT student.*--10.查询没有选修C1课程的学生信息
FROM student
WHERE Sno NOT IN
(
  SELECT Sno
  FROM sc
  WHERE Cno=1
);

SELECT count(student.sno)--11.查询没有选修C1课程的学生人数
FROM student
WHERE Sno NOT IN
(
  SELECT Sno
  FROM sc
  WHERE Cno=1
);

SELECT course.* --12.查询平均分最高的课程信息
FROM course,
(
  SELECT Cno
  FROM sc GROUP BY Cno 
  ORDER BY AVG(Grade) DESC
  LIMIT 0,1
) as a
WHERE course.Cno=a.Cno;

SELECT student.Sno,student.Sname,course.Cname,sc.Grade--13.查询平均分最高的课程的选课信息（学号，姓名，课程名程，成绩）
FROM course,student,sc,
(
  SELECT Cno
  FROM sc GROUP BY Cno 
  ORDER BY AVG(Grade) DESC
  LIMIT 0,1
) as a
WHERE course.Cno=a.Cno AND sc.Cno=a.Cno AND sc.Sno=student.Sno;

SELECT student.Sdept--14.查询平均分最高的学生所在院系。
FROM student,
(
  SELECT Sno
  FROM sc GROUP BY Sno
  ORDER BY AVG(Grade) DESC
  LIMIT 0,1
) as a 
WHERE student.Sno=a.Sno;

SELECT avg(nums)--15. 统计学生平均选修课程数。
--选课了的学生
FROM
(
  SELECT COUNT(sc.Cno) as nums
  FROM sc
  GROUP BY Sno
)as a;
SELECT count(student.Sno),COUNT(sc.sno)
FROM student,sc;
SELECT avg(IFNULL(nums,0))--15. 统计学生平均选修课程数。
--全部学生
FROM student left JOIN
(
  SELECT Sno,COUNT(Cno)as nums
  FROM sc
  GROUP BY Sno
)as a on student.Sno=a.Sno;

select student.Sdept,avg(nums)--16. 统计各院系学生平均选课数。
FROM student,
(
  SELECT sc.Sno,COUNT(sc.Cno) nums
  FROM sc
  GROUP BY Sno
) as a 
WHERE a.Sno=student.Sno
GROUP BY student.Sdept;
select student.Sdept,ifnull(avg(nums),0)--16. 统计各院系学生平均选课数。
--所有院系
FROM student left JOIN
(
  SELECT sc.Sno,COUNT(sc.Cno) nums
  FROM sc
  GROUP BY Sno
) as a ON student.Sno=a.Sno 
GROUP BY student.Sdept;

SELECT COUNT(sno),MAX(Grade),MIN(Grade),AVG(Grade)--17. 统计每门课程的选课人数，最高分，平均分和最低分。
FROM sc
GROUP BY Cno;
SELECT course.Cno,COUNT(sno),MAX(Grade),MIN(Grade),AVG(Grade)--17. 统计每门课程的选课人数，最高分，平均分和最低分。
FROM course LEFT JOIN sc as a ON course.Cno=a.Cno
GROUP BY course.Cno
ORDER BY Cno;

SELECT student.*--18. 查询平均分75以上，并且没有不及格成绩的学生信息。
FROM student,
(
  SELECT sno
  FROM sc GROUP BY Sno
  having AVG(Grade)>75 AND MIN(Grade)>=60
) as a
WHERE student.Sno=a.Sno;

UPDATE sc--19. 修改“CS”的学生成绩，不及格学生的成绩增加5分。
SET Grade=Grade+5
where Grade<60 and Sno IN
( SELECT Sno
  FROM student
  WHERE Sdept='CS');

UPDATE sc--test
DELETE--20. 删除“IS”系学生的成绩记录
FROM sc
where Sno IN
(
  SELECT Sno
  FROM student
  WHERE Sdept="IS"
); 


UPDATE course--21.修改“数据库”课程的学分为3
SET Ccredit=3
where Cname='数据库';

UPDATE student--22. 修改学生的年龄加1岁
SET Sage=Sage+1;

CREATE View student_credit--23. 定义视图反映学生学号、姓名以及选修的总学分。
as
select student.Sno,student.Sname,ifnull(Scredit,0) as Scredit
from student left join
(
  select sc.Sno,sum(course.Ccredit)as Scredit
  from sc,course
  WHERE sc.Cno=course.Cno
  group by sc.Sno
) a on student.Sno=a.Sno;

CREATE View CS_student
--24. 定义“CS”系学生视图，并要求进行修改和插入操作时仍需保证视图只有“CS”系的学生。
as
select student.*
from student
where student.Sdept="CS"
with check option;

SELECT Sname,Scredit--25. 在视图上查询“李勇”已选修的学分数。
from student_credit
WHERE Sname='李勇';

ALTER Table student ADD S_entrance DATE;
--向student表中增加“入学时间”列，其数据类型为日期型。
ALTER table student modify column sage INT;
--将年龄的数据类型由字符型改为整数。
ALTER table course add UNIQUE(Cname);
--增加课程名必须取唯一值的约束条件。
ALTER Table student drop column S_entrance;
--删除student表中“入学时间”属性。


SET foreign_key_checks = 0;  
--先设置外键约束检查关闭
DROP table student;
--删除student表。
SET foreign_key_checks = 1; 
--开启外键约束检查，以保持表结构完整性

--新建“学生课程数据库”
Create database 学生课程数据库;
--新建数据库命令
show database;
--查看所有数据库
Use 学生课程数据库;
--使用数据库

CREATE View CS_student_avgGrade
--26. 建立视图保存cs系学生的基本信息与平均成绩
as
select student.sdept,student.Sno,student.Sname,student.Sage,a.avgscore
from student,
(
  SELECT Sno,AVG(Grade) avgscore
  from sc
  GROUP BY Sno
) as a
where student.Sno=a.Sno and student.Sdept="CS";


SELECT *--26.查询选修了C2课程且平均分大于85分的学生信息
FROM cs_student_avggrade
WHERE avgscore>85 and Sno IN
(
  SELECT Sno
  FROM sc
  WHERE Cno="2"
);
UPDATE cs_student_avggrade--26.将视图中所有学生年龄增加一岁
SET sage=sage+1;

INSERT--将视图中插入一个新的学生记录
INTO student(Sdept,Sno,Sname,Sage,Ssex)
VALUES('CS','201965725','杨洋',20,'男');
INSERT INTO cs_student
VALUES('201965725','杨洋','男',20,'CS');
DELETE 
FROM cs_student
WHERE Sname='杨洋';

INSERT--将视图中插入一个新的学生记录
INTO cs_student_avggrade
VALUES('CS','201965725','杨洋',20,'男');
INSERT--将视图中插入一个新的学生记录
INTO sc
VALUES('201965725',1,100);



INSERT INTO accout
VALUES
('123456','杨洋','上海市普陀区志丹路155弄','2001-08-11');

INSERT INTO operator
VALUES
('admin','admin','18616512114');

INSERT INTO person
VALUES
('310107','123456','杨洋','男','户主','汉族','上海','2001-8-11','上海','哈尔滨','本科','2001-8-11');