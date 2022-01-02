CREATE database HuKo;
--新建户籍管理系统数据库

CREATE Table accout
--新建户籍信息表
(
    Hno VARCHAR(20) PRIMARY KEY,
    Hname VARCHAR(20) NOT NULL,
    Adr VARCHAR(50) NOT NULL,
    regdata DATETIME NOT NULL
);
CREATE TABLE person 
--新建个人信息表
(
  IDcard varchar(20) NOT NULL,
  Hno char(20),
  name varchar(20) NOT NULL,
  Sex char(2) NOT NULL check(sex in('男','女')),
  relation varchar(20),
  nation VARCHAR(10) NOT NULL,
  province varchar(10) NOT NULL,
  birthdata datetime NOT NULL,
  birthplace varchar(50) NOT NULL,
  liveplace VARCHAR(50) NOT NULL,
  Education varchar(10) NOT NULL,
  indata DATETIME NOT NULL,
  PRIMARY KEY(IDcard),
  FOREIGN KEY (Hno) REFERENCES accout(Hno)
);

CREATE Table Hout
--户口迁出信息表
(
    Hno char(20) NOT NULL,
    Hname varchar(10) NOT NULL,
    outdata datetime NOT NULL,
    originadr VARCHAR(50) NOT NULL,
    outadress varchar(50) NOT NULL,
    PRIMARY KEY(Hno,originadr,outadress)
);

CREATE Table perout
--人口迁出信息表
(    
    IDcard varchar(20),
    name varchar(20) NOT NULL,
    outHno varchar(20),
    inHno VARCHAR(20),
    outdata datetime NOT NULL,
    PRIMARY KEY(IDcard,outHno,inHno)
);

CREATE Table Hdis
--户口注销表
(
    Hno varchar(20) PRIMARY KEY,
    name varchar(10) NOT NULL,
    disdata datetime NOT NULL,
    reason varchar(50),
    prove varchar(50)
);

CREATE Table operator
--管理员表
(
    Name VARCHAR(20) PRIMARY KEY,
    password VARCHAR(20) NOT NULL,
    phone VARCHAR(20)
);

CREATE Trigger hukouout --添加户口迁出触发器
after update
on accout
for each row
insert into Hout(Hno,Hname,outdata,originadr,outadress)
values 
(old.Hno,old.Hname,Now(),OLD.Adr,NEW.Adr);

UPDATE accout
SET Adr='上海市普陀区',regdata=NOW()
WHERE Hno=123456;


CREATE View harbinper
as 
select IDcard,Hno,name,sex,liveplace
from person
where liveplace='哈尔滨';

CREATE Trigger deletehukouper --添加户口注销关联人口触发器
before delete
on accout
for each row
update person
set Hno=null,relation=null
where old.Hno=person.Hno;

DELETE from accout
WHERE Hno='123456';

CREATE Trigger deletehukou --添加户口注销触发器
after delete
on accout
for each row
insert into hdis
values(old.Hno,old.Hname,now(),null,null);

ALTER TABLE person ADD INDEX (Hno)--为person表中Hno添加索引