# Write your MySQL query statement below
SELECT name, IFNULL(SUM(distance), 0) AS travelled_distance
FROM Users AS A LEFT JOIN Rides AS B
ON A.id = B.user_id 
GROUP BY A.id
ORDER BY travelled_distance DESC, name;