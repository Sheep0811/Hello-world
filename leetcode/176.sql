
select ifNull(
(
select distinct Salary
from Employee
order by Salary desc
limit 1,1 --limit x,y(去掉前x个，取y个)
),null)as SecondHighestSalary;

