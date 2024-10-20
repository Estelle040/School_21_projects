SELECT
    pizza_name           ,
    name AS pizzeria_name,
    price
FROM
    menu
JOIN
    pizzeria
ON
    menu.pizzeria_id = pizzeria.id
WHERE
    pizza_name IN ('mushroom pizza',
                   'pepperoni pizza')
ORDER BY
    pizza_name,
    pizzeria_name;