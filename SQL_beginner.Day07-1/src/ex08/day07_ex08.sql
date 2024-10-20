WITH orders AS
    (
        SELECT
            p.address,
            pz.name  ,
            COUNT(1) AS count_orders
        FROM
            person_order po
        JOIN
            menu m
        ON
            po.menu_id=m.id
        JOIN
            pizzeria pz
        ON
            m.pizzeria_id=pz.id
        JOIN
            person p
        ON
            p.id=po.person_id
        GROUP BY
            p.address,
            pz.name
        ORDER BY
            count_orders DESC )
SELECT
    address,
    name   ,
    count_orders AS count_of_orders
FROM
    orders o
ORDER BY
    1,
    2;