INSERT INTO menu
SELECT
    MAX(id) + 1 ,
    (
        SELECT
            id
        FROM
            pizzeria
        WHERE
            name = 'Dominos') ,
    'sicilian pizza'          ,
    900
FROM
    menu;