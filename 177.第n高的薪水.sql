--
-- @lc app=leetcode.cn id=177 lang=mysql
--
-- [177] 第N高的薪水
--
-- https://leetcode-cn.com/problems/nth-highest-salary/description/
--
-- database
-- Medium (43.46%)
-- Likes:    251
-- Dislikes: 0
-- Total Accepted:    36.2K
-- Total Submissions: 81.8K
-- Testcase Example:  '{"headers": {"Employee": ["Id", "Salary"]}, "argument": 2, "rows": {"Employee": [[1, 100], [2, 200], [3, 300]]}}'
--
-- 编写一个 SQL 查询，获取 Employee 表中第 n 高的薪水（Salary）。
-- 
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+
-- 
-- 
-- 例如上述 Employee 表，n = 2 时，应返回第二高的薪水 200。如果不存在第 n 高的薪水，那么查询应返回 null。
-- 
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+
-- 
-- 
--

-- @lc code=start
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  IF N < 0 THEN
  RETURN (SELECT MIN(Salary)
  FROM Employee);
  ELSE
  SET N = N - 1;
  RETURN (
      # Write your MySQL query statement below.
  SELECT IFNULL((SELECT DISTINCT Salary
  FROM Employee ORDER BY Salary DESC LIMIT N, 1), NULL) AS getNthHighestSalary
  );
  END IF;
END
-- @lc code=end

