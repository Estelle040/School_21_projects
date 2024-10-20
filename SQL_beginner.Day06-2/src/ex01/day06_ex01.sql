INSERT INTO person_discounts (id, person_id, pizzeria_id, discount)
SELECT 
    ROW_NUMBER() OVER () AS id,  
    po.person_id, 
    pv.pizzeria_id,
    CASE
        WHEN COUNT(*) = 1 THEN 0.105 
        WHEN COUNT(*) = 2 THEN 0.22  
        ELSE 30.0                
    END AS discount
FROM 
    person_order po
JOIN 
    person_visits pv ON po.person_id = pv.person_id 
GROUP BY 
    po.person_id, 
    pv.pizzeria_id;
