SELECT first.name, first.salary
FROM   Employee first, Employee second
WHERE  second.id = first.chief_id AND first.salary > second.salary