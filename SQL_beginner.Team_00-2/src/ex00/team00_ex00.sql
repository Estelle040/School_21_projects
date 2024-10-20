CREATE TABLE if not EXISTS nodes
(
  point1 varchar,
  point2 varchar,
  cost INTEGER
);

INSERT into nodes
VALUES 
  ('a', 'b', 10),
  ('b', 'a', 10),
  ('a', 'c', 15),
  ('c', 'a', 15),
  ('a', 'd', 20),
  ('d', 'a', 20),
  ('b', 'd', 25),
  ('d', 'b', 25),
  ('d', 'c', 30),
  ('c', 'd', 30),
  ('b', 'c', 35),
  ('c', 'b', 35);

WITH RECURSIVE Paths AS (
    SELECT 
        point1 AS start_point, 
        point2, 
        cost, 
        CONCAT('{', point1, ',', point2) AS tour, 
        ARRAY[point1, point2] AS visited_points,
        cost AS total_cost
    FROM 
        nodes
    WHERE 
        point1 = 'a'
    
    UNION ALL
    
    SELECT 
        p.start_point, 
        n.point2, 
        n.cost, 
        CONCAT(p.tour, ',', n.point2), 
        ARRAY_APPEND(p.visited_points, n.point2), 
        p.total_cost + n.cost AS total_cost
    FROM 
        Paths p
        INNER JOIN nodes n ON p.point2 = n.point1
    WHERE 
        n.point2 <> ALL(p.visited_points)
),
all_path_cte AS (
    SELECT 
        (p.total_cost + n.cost) AS total_cost,
        CONCAT(p.tour, ',', p.start_point, '}') AS tour
    FROM 
        Paths p
        INNER JOIN nodes n ON p.point2 = n.point1
    WHERE 
        n.point2 = 'a' AND
        array_length(visited_points, 1) = (SELECT COUNT(DISTINCT point1) FROM nodes)
    ORDER BY 
        total_cost, 
        tour
)
SELECT DISTINCT total_cost, tour FROM all_path_cte
where total_cost = (SELECT MIN(total_cost) from all_path_cte)
order by 1, 2; 