WITH Sum_salary AS
	(SELECT Department_id, SUM(Salary) Salary
    FROM Employee
    GROUP BY Department_id)
SELECT Department_id, Salary
FROM Sum_salary first       
WHERE  first.Salary = (SELECT MAX(Salary) FROM Sum_salary ) 