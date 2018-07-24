/* Problem from: https://leetcode.com/problems/exchange-seats/description/

 * Description:
 * Mary is a teacher in a middle school and she has a table sear storing students' names and their corresponding sear ids.
 * The column id is continuous increment.
 * Mary wants to change seats for the adjacent students.
 * Can you write a SQL query to output the result for Mary?
 *
 * +---------+---------+
   |    id   | student |
   +---------+---------+
   |    1    | Abbot   |
   |    2    | Doris   |
   |    3    | Emerson |
   |    4    | Green   |
   |    5    | Jeames  |
   +---------+---------+
 *
 * For the same input, the output is:
 * +---------+---------+
   |    id   | student |
   +---------+---------+
   |    1    | Doris   |
   |    2    | Abbot   |
   |    3    | Green   |
   |    4    | Emerson |
   |    5    | Jeames  |
   +---------+---------+
 *
 * Note: If the number of students is odd, there is no need to change the last one's seat.
 */

SELECT 
    CASE
        WHEN seat.id % 2 = 0 THEN seat.id - 1
        WHEN seat.id % 2 <> 0 AND seat.id = (SELECT COUNT(*) FROM seat) THEN seat.id
        ELSE seat.id + 1
    END AS id,
    student
FROM seat
ORDER BY id ASC;