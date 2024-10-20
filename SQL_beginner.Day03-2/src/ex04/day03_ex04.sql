WITH name_place
    (
        gender,
        pizzeria_name) AS
    (
        SELECT
            sel_p.gender ,
            piz.name AS pizzeria_name
        FROM
            (
                SELECT
                    gender,
                    id
                FROM
                    person) AS sel_p
        RIGHT JOIN
            person_order po
        ON
            po.person_id = sel_p.id
        LEFT JOIN
            menu m
        ON
            m.id = po.menu_id
        LEFT JOIN
            pizzeria piz
        ON
            piz.id = m.pizzeria_id )
SELECT
    pizzeria_name
FROM
    name_place
WHERE
    gender = 'female'
EXCEPT
SELECT
    pizzeria_name
FROM
    name_place
WHERE
    gender = 'male'
ORDER BY
    pizzeria_name;