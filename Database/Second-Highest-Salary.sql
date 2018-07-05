/* Problem from: https://leetcode.com/problems/second-highest-salary/description/ */

select MAX(salary) as SecondHighestSalary
from Employee
where salary not in (select MAX(salary) from Employee);

/*
 * Input: {"headers": {"Employee": ["ID", "Salary"]}, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}
 * Output: {"headers": ["SecondHighestSalary"], "values": [[200]]}
 */