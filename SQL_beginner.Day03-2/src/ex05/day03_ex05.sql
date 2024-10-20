SELECT name FROM pizzeria
WHERE pizzeria.id IN (
    SELECT person_visits.pizzeria_id 
    FROM person_visits
    WHERE person_visits.person_id = 2
)
AND pizzeria.id NOT IN (
    SELECT pizzeria.id
    FROM person_order
    JOIN menu ON menu.id = person_order.menu_id
    JOIN pizzeria ON pizzeria.id = menu.pizzeria_id
    WHERE person_order.person_id = 2
);