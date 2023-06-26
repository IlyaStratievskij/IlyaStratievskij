SELECT ID, Name
FROM Employee 
WHERE Chief_id IS NULL AND ID NOT IN(
		SELECT Chief_id 
		FROM Employee 
		Where Chief_id IS NOT NULL);