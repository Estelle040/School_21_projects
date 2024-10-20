SELECT
    dates AS missing_date
FROM
    v_generated_dates

except

SELECT
    visit_date
FROM
    person_visits
ORDER BY
    missing_date;

select dates as missing_date from v_generated_dates except select visit_date from person_visits order by 1