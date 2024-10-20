INSERT INTO person_order
SELECT
    generate_series((SELECT MAX(id) FROM person_order) + 1, (SELECT MAX(id) FROM person_order) + (SELECT MAX(id) FROM person))
    , generate_series(1::bigint, (SELECT MAX(id) FROM person))
    , (SELECT id FROM menu WHERE pizza_name = 'greek pizza')
    , '2022-02-25';