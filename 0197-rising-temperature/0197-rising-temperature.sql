# Write your MySQL query statement below
select a.id as Id
from weather a
join weather b
on DATEDIFF(a.recordDate, b.recordDate) = 1
where a.temperature > b.temperature;