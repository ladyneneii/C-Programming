#Exercise 3 Answers

1.

SELECT m.Title, m.Year, b.Domestic_Sales, b.International_Sales
FROM Movies m
WHERE m.ID IN (
    SELECT Movie_ID 
    FROM BoxOffice
);

2.

SELECT m.Title 
FROM Movies m, BoxOffice b 
WHERE m.ID IN (
    SELECT Movie_ID 
    FROM BoxOffice b
    WHERE b.Domestic_Sales < b.International_Sales;
);

3.

SELECT m.Title, b.Rating
FROM Movies m, BoxOffice b 
WHERE m.ID IN (
    SELECT Movie_ID 
    FROM BoxOffice b
    ORDER BY b.Rating DESC;
);

4.

SELECT m.Title, (b.Domestic_Sales + b.International_Sales) AS "Overall Sales"
FROM Movies m, BoxOffice b 
WHERE m.ID IN (
    SELECT Movie_ID 
    FROM BoxOffice b
    ORDER BY b.Domestic_Sales + b.International_Sales;
);

5.

SELECT m.Title, m.Year
FROM Movies m  
ORDER BY m.Length_Minutes DESC
LIMIT 1;




#Exercise 4 Answers

1.

SELECT e.first_name, e.last_name
FROM Employees e
WHERE e.salary > 100000;

2.

SELECT d.department_name, e.first_name, e.last_name
FROM Employees e
INNER JOIN Departments d
    ON d.manager_id = e.manager_id 
INNER JOIN Locations l 
    ON l.location_id = d.location_id
INNER JOIN Countries c
    ON c.country_id = l.country_id
    AND c.ountry_name = 'UK';

3.

SELECT e.first_name, e.last_name
FROM Employees e
INNER JOIN Departments d
    ON d.department_id = e.department_id
    AND d.department_name = 'Finance';


4.

SELECT j.job_title
FROM Jobs j
INNER JOIN Job_History h 
    ON j.job_id = h.job_id
INNER JOIN Employees e 
    ON e.employee_id = h.employee_id
WHERE e.first_name = 'Elon' AND e.last_name = 'Musk'

5.

SELECT  e.first_name, e.last_name
FROM Employees e 
INNER JOIN Departments d
    ON d.manager_id = e.manager_id 
INNER JOIN Locations l 
    ON l.location_id = d.location_id
INNER JOIN Countries c
    ON c.country_id = l.country_id
INNER JOIN Region r
    ON r.region_id = c.region_id
    AND region_name = "Europe";


6.

SELECT  e.first_name, e.last_name
FROM Employees e
INNER JOIN Jobs j
    ON j.job_id = e.job_id 
    AND j.max_salary = CEIL(e.salary);

7.

SELECT  e.first_name, e.last_name
FROM Employees e
INNER JOIN Jobs j
    ON j.job_id = e.job_id 
    AND j.min_salary = FLOOR(e.salary);

8.

SELECT e.first_name, e.last_name, d.department_name, e.manager_id
FROM Employees e
INNER JOIN Departments d 
    ON d.department_id = e.department_id
ORDER BY e.salary DESC
LIMIT 1;


9.

SELECT d.department_name, c.country_name, r.region_name
FROM Employees e
INNER JOIN Departments d
    ON d.manager_id = e.manager_id 
INNER JOIN Locations l 
    ON l.location_id = d.location_id
INNER JOIN Countries c
    ON c.country_id = l.country_id
INNER JOIN Region r
    ON r.region_id = c.region_id
ORDER BY e.salary DESC
LIMIT 1;

10.

SELECT c.country_name, r.region_name
FROM Employees e
INNER JOIN Departments d
    ON d.manager_id = e.manager_id 
INNER JOIN Locations l 
    ON l.location_id = d.location_id
INNER JOIN Countries c
    ON c.country_id = l.country_id
INNER JOIN Region r
    ON r.region_id = c.region_id
ORDER BY count(e.department_id) DESC
LIMIT 1;