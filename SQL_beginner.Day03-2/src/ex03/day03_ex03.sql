SELECT
    pz.name AS pizzeria_name
FROM
    pizzeria AS pz
JOIN
    (
        SELECT
            pv.pizzeria_id,
            SUM(CASE WHEN p.gender = 'male' THEN 1 ELSE 0 END) AS male_visits,
            SUM(CASE WHEN p.gender = 'female' THEN 1 ELSE 0 END) AS female_visits
        FROM
            person_visits AS pv
        JOIN
            person AS p
        ON
            pv.person_id = p.id
        GROUP BY
            pv.pizzeria_id ) AS gender_visits
ON
    pz.id = gender_visits.pizzeria_id
WHERE
    gender_visits.male_visits <> gender_visits.female_visits
AND (
        gender_visits.male_visits      > gender_visits.female_visits
        OR gender_visits.female_visits > gender_visits.male_visits)
ORDER BY
    pz.name ASC;