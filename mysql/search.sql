SELECT Sname--1.查询平均成绩大于80的学生姓名。
FROM student
WHERE Sno IN 
  (
    select Sno
    FROM sc
    GROUP BY Sno
    HAVING AVG(Grade) > 80
  );
select--2.查询课程成绩大于课程平均成绩的选课信息，显示学生姓名、课程名称和成绩。查询课程成绩大于课程平均成绩的选课信息，显示学生姓名、课程名称和成绩。
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

SELECT COUNT(*)--5.统计每门课程成绩大于80分的学生数。
FROM course left JOIN sc ON course.Cno=sc.Cno
where Grade>80 GROUP BY course.Cno;

SELECT AVG(Grade)--6. 统计计算机系“CS”学生的平均分
FROM sc
WHERE sno IN
(
  SELECT sno
  FROM student
  WHERE Sdept="CS"
);

SELECT COUNT(DISTINCT a.Sno)--7. 统计至少选修了两门课程的学生数
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
FROM 
(
  SELECT COUNT(sc.Cno) as nums
  FROM sc
  GROUP BY Sno
)as a;

select student.Sdept,avg(nums)--16. 统计各院系学生平均选课数。
FROM student,
(
  SELECT sc.Sno,COUNT(sc.Cno) nums
  FROM sc
  GROUP BY Sno
) as a
where student.Sno=a.Sno
GROUP BY student.Sdept;

SELECT COUNT(sno),MAX(Grade),MIN(Grade),AVG(Grade)--17. 统计每门课程的选课人数，最高分，平均分和最低分。
FROM sc
GROUP BY Cno;

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
where Grade<81;

--UPDATE sc
--set grade=80
--where Sno="201215122"and Cno=3;

DELETE--20. 删除“IS”系学生的成绩记录
FROM sc
where Sno IN
(
  SELECT Sno
  FROM student
  WHERE Sdept="CS"
); 

CREATE View CS_student
as
select student.Sno,student.Sname,student.Sage,a.avgscore
from student,
(
  SELECT Sno,AVG(Grade) avgscore
  from sc
  GROUP BY Sno
) as a
where student.Sno=a.Sno and student.Sdept="CS"
with check option;