SELECT 
    p.name AS имя,
    COALESCE(visit_count, 0) + COALESCE(order_count, 0) AS общее_количество
FROM 
    pizzeria p
LEFT JOIN (
    SELECT 
        pv.pizzeria_id,
        COUNT(pv.id) AS visit_count
    FROM 
        person_visits pv
    GROUP BY 
        pv.pizzeria_id
) AS visits ON p.id = visits.pizzeria_id
LEFT JOIN (
    SELECT 
        m.pizzeria_id,
        COUNT(po.id) AS order_count
    FROM 
        menu m
    LEFT JOIN 
        person_order po ON m.id = po.menu_id
    GROUP BY 
        m.pizzeria_id
) AS orders ON p.id = orders.pizzeria_id
ORDER BY 
    общее_количество DESC, 
    p.name ASC;
