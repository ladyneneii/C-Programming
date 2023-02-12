1.

SELECT Fname, Lname
FROM EMPLOYEE e
LEFT JOIN DEPARTMENT d ON e.DNo = d.DNo;


2.

SELECT e.Fname, e.Lname, w.SSN
FROM EMPLOYEE e
LEFT JOIN WORKS_ON w ON e.SSN = w.SSN
WHERE w.SSN IS NULL;


3.

SELECT p.PName, SUM(Hours) AS "Accumulated Hours"
FROM PROJECT p 
WHERE p.PNo IN (
    SELECT w.Hours 
    FROM WORKS_ON
    GROUP BY w.Hours
    ORDER BY SUM(Hours) LIMIT 1);


4. 

SELECT e.Fname, e.Lname, e.DNo
FROM EMPLOYEE e 
LEFT JOIN DEPARTMENT d ON e.DNo = d.DNo
WHERE d.DNo IS NULL;



