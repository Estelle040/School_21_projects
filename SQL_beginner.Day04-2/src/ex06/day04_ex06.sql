CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT
    pizzeria.name
FROM
    pizzeria
JOIN
    person_visits
ON
    person_visits.pizzeria_id = pizzeria.id
JOIN
    menu
ON
    menu.pizzeria_id=pizzeria.id
WHERE
    person_visits.person_id  = 9
AND person_visits.visit_date = '2022-01-08'
AND menu.price               < 800;

select * from mv_dmitriy_visits_and_eats;
