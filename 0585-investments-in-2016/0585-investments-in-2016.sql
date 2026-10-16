# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance i
WHERE (SELECT COUNT(*)
       FROM Insurance x
       WHERE x.tiv_2015 = i.tiv_2015) > 1
  AND (SELECT COUNT(*)
       FROM Insurance y
       WHERE y.lat = i.lat AND y.lon = i.lon) = 1;