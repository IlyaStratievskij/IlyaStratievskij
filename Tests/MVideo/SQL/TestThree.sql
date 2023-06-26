SELECT Department_id
FROM Employee 
GROUP BY Department_id
HAVING COUNT(*) <= 3