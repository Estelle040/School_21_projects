SELECT 
    person_id, 
    COUNT(*) AS visit_count
FROM 
    person_visits
GROUP BY 
    person_id
ORDER BY 
    visit_count DESC, 
    person_id ASC;
