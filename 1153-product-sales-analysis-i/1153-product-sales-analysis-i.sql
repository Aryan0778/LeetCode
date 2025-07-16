# Write your MySQL query statement below
SELECT e.product_name,p.year,p.price FROM Sales as p INNER JOIN Product as e ON e.product_id = p.product_id;