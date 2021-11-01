CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
declare m INT;
set m=N-1; 
  RETURN (
      # Write your MySQL query statement below.
select ifNull((select distinct Salaryfrom Employee order by Salary desc limit m,1),null)
  );
END