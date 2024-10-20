SELECT
    tmp::date AS missing_date
FROM
    (
        SELECT
            *
        FROM
            person_visits
        WHERE
            person_id = 1
        OR  person_id = 2) AS p
RIGHT JOIN
    generate_series('2022-01-01','2022-01-10', interval '1 day') AS tmp
ON
    p.visit_date = tmp
WHERE
    p.id IS NULL
ORDER BY
    1