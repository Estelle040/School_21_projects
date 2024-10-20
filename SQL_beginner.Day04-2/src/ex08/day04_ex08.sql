DROP VIEW IF EXISTS v_persons_female;
DROP VIEW IF EXISTS v_persons_male;
DROP VIEW IF EXISTS v_generated_dates;
DROP VIEW IF EXISTS v_symmetric_union;
DROP VIEW IF EXISTS v_price_with_discount;

DROP MATERIALIZED VIEW IF EXISTS mv_dmitriy_visits_and_eats;

select count(*) =0 as check from pg_class where relname in ('v_generated_dates','v_persons_female','v_persons_male', 'v_price_with_discount','v_symmetric_union', 'mv_dmitriy_visits_and_eats');