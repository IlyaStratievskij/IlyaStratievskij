SELECT first.Department_id, first.Name, first.Salary
FROM   Employee first
WHERE  first.Salary = ( 
		SELECT MAX(Salary) 
		FROM Employee second
		WHERE  second.Department_id = first.Department_id )
ORDER BY Department_id