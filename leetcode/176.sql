
select ifNull(
(
select distinct Salary
from Employee
order by Salary desc
limit 1,1 --limit x,y(ȥ��ǰx����ȡy��)
),null)as SecondHighestSalary;

