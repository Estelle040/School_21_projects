SELECT 
	COALESCE(u.name, 'not defined') as name,
    COALESCE(u.lastname, 'not defined') as lastname,
    b.type,
    sum(b.money) AS volume,
    COALESCE(c.name, 'not defined') as currency_name,
    COALESCE(cu.rate_to_usd, 1) AS last_rate_to_usd,
    CAST(sum(b.money) * COALESCE(cu.rate_to_usd, 1) AS float) AS total_volume_in_usd
FROM "user" u
FULL JOIN balance b on b.user_id = u.id
FULL JOIN (SELECT id, name, MAX(updated) AS last_updated FROM currency GROUP BY id, name) as  c on c.id = b.currency_id
LEFT JOIN currency  cu ON c.last_updated = cu.updated AND c.name = cu.name
GROUP BY u.name, u.lastname, b.type, c.name, cu.rate_to_usd
ORDER BY name DESC, lastname, b.type
