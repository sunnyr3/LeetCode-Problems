/* Problem from: https://leetcode.com/problems/department-top-three-salaries/description/ 

 * Description
 * The Employee table holds all employees. Every employees has an Id, and there is also a column for the department Id.
 * +----+-------+--------+--------------+
   | Id | Name  | Salary | DepartmentId |
   +----+-------+--------+--------------+
   | 1  | Joe   | 70000  | 1            |
   | 2  | Henry | 80000  | 2            |
   | 3  | Sam   | 60000  | 2            |
   | 4  | Max   | 90000  | 1            |
   | 5  | Janet | 69000  | 1            |
   | 6  | Randy | 85000  | 1            |
   +----+-------+--------+--------------+

 * The Department table holds all departments of the company.
 * +----+----------+
   | Id | Name     |
   +----+----------+
   | 1  | IT       |
   | 2  | Sales    |
   +----+----------+
 
 * Write a SQL query to find employees who earn the top three salaries in each of the department. For the above tables, your SQL query should 
   return the following rows:
   +------------+----------+--------+
   | Department | Employee | Salary |
   +------------+----------+--------+
   | IT         | Max      | 90000  |
   | IT         | Randy    | 85000  |
   | IT         | Joe      | 70000  |
   | Sales      | Henry    | 80000  |
   | Sales      | Sam      | 60000  |
   +------------+----------+--------+
 */

SELECT d.Name AS 'Department', e1.Name AS 'Employee', e1.Salary
FROM 
    Employee e1
        INNER JOIN 
    Employee e2 ON e1.DepartmentId = e2.DepartmentId AND e1.Salary <= e2.Salary
        INNER JOIN
    Department d ON e1.DepartmentId = d.Id
GROUP BY e1.Id
HAVING COUNT(distinct e2.Salary) < 4;
