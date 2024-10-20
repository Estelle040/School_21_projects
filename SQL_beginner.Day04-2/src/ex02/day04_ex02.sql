-- DROP VIEW v_generated_dates;
CREATE VIEW v_generated_dates
AS
SELECT
    generate_series::date AS dates
FROM
    generate_series('2022-01-01', '2022-01-31', interval '1 day');

select count(*) =31 as check, min(dates) as check1, max(dates) as check2 from v_generated_dates;