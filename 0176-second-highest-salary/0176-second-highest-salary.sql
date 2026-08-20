# Write your MySQL query statement below

SELECT max(salary) AS SecondHighestSalary from Employee where salary<(SELECT max(salary) from Employee)
