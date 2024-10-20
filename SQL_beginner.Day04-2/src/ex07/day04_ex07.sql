INSERT INTO person_visits
    (
        id         ,
        person_id  ,
        pizzeria_id,
        visit_date
    )
VALUES
    (
    (
        SELECT
            max(id)+1
        FROM
            person_visits),
    (
        SELECT
            id
        FROM
            person
        WHERE
            name = 'Dmitriy'),
    (
        SELECT
            pizzeria_id
        FROM
            menu
        JOIN
            pizzeria
        ON
            menu.pizzeria_id = pizzeria.id
        WHERE
            price         < 800
        AND pizzeria.name != 'Papa Johns'
        LIMIT 1),
    '2022-01-08'
    )
;
SELECT
    pizzeria.name
FROM
    pizzeria
JOIN
    menu
ON
    pizzeria.id = menu.pizzeria_id
JOIN
    person_visits
ON
    pizzeria.id = person_visits.pizzeria_id
JOIN
    person
ON
    person_visits.person_id = person.id
WHERE
    person.name='Dmitriy'
AND visit_date ='2022-01-08'
AND price      <800;
REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;

select * from mv_dmitriy_visits_and_eats