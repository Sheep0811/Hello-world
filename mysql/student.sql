CREATE Table Student
--新建学生表
(
    Sno CHAR(9) PRIMARY KEY,
    Sname CHAR(20) UNIQUE,
    Ssex CHAR(2),
    Sage SMALLINT,
    Sdept CHAR(20)
);

CREATE Table Course
--新建课程表 
(
  Cno CHAR(4) PRIMARY KEY,
  Cname CHAR(40) NOT NULL,
  Cpno CHAR(4),
  Ccredit SMALLINT,
  FOREIGN KEY(Cpno) REFERENCES Course(Cno)
);
CREATE Table SC 
--新建选课表
(
  Sno CHAR(9),
  Cno CHAR(4),
  Grade SMALLINT,
  PRIMARY KEY (Sno, Cno),
  FOREIGN KEY(Sno) REFERENCES Student(Sno),
  FOREIGN KEY(Cno) REFERENCES Course(Cno)
);
--在学生表中添加数据
INSERT INTO student
VALUES
("201215121","李勇","男",20,"CS"),
("201215122","刘晨","女",19,"CS"),
("201215123","王敏","女",18,"MA"),
("201215125","张立","男",19,"IS");
--在课程表中添加数据
INSERT INTO course
VALUES
('6',"数据处理",NULL,'2'),
('2',"数学",NULL,'2'),
('7',"PASCAL语言",'6','4'),
('5',"数据结构",'7','4'),
('4',"操作系统",'6','3'),
('1',"数据库",'5','4'),
('3',"信息系统",'1','4');
--在选课表中添加数据
INSERT INTO sc VALUES 
("201215121",1,92),
("201215121",2,85),
("201215121",3,88),
("201215122",2,90),
("201215122",3,80);

SELECT Sno,Sname
FROM student;
--从学生表中查询学号与姓名
SELECT student.Sno,Sname
FROM student,sc
WHERE student.Sno=sc.Sno AND
sc.Cno='1'AND sc.Grade>=90;
--查询选修了课程编号为1，且成绩大于等于90的学生