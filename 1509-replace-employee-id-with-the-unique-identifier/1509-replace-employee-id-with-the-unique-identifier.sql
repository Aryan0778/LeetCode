# Write your MySQL query statement below
SELECT e.name,p.unique_id FROM Employees as e LEFT JOIN EmployeeUNI as p
ON e.id= p.id;