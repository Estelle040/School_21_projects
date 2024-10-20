SELECT
    menu.pizza_name          AS pizza_name   ,
    menu.price               AS price        ,
    pizzeria.name            AS pizzeria_name,
    person_visits.visit_date AS visit_date
FROM
    person_visits
JOIN
    person
ON
    person_visits.person_id = person.id
JOIN
    menu
ON
    person_visits.pizzeria_id = menu.pizzeria_id
JOIN
    pizzeria
ON
    pizzeria.id = menu.pizzeria_id
WHERE
    person.id = 3 AND menu.price BETWEEN 800 AND 1000
ORDER BY
    pizza_name,
    price     ,
    pizzeria_name;