SELECT
    name
FROM
    v_persons_male

UNION

SELECT
    name
FROM
    v_persons_female
ORDER BY
    name;

select name from v_persons_female union select name from v_persons_male order by 1