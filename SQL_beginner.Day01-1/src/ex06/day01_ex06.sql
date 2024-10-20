SELECT
    action_date,
    p.name AS person_name
FROM
    (
        SELECT
            order_date AS action_date,
            person_id
        FROM
            person_order
        
        INTERSECT
        
        SELECT
            visit_date AS action_date,
            person_id
        FROM
            person_visits ) AS common_data
JOIN
    person p
ON
    common_data.person_id = p.id
ORDER BY
    action_date ASC,
    person_name DESC;