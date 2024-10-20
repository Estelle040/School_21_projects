COMMENT ON TABLE person_discounts IS 'Table to store personal discounts for customers in relation to pizzerias.';
COMMENT ON COLUMN person_discounts.id IS 'Unique identifier for each discount record.';
COMMENT ON COLUMN person_discounts.person_id IS 'Identifier for the person to whom the discount applies.';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'Identifier for the pizzeria that offers the discount.';
COMMENT ON COLUMN person_discounts.discount IS 'Discount percentage applicable to the person for the specific pizzeria. Must be between 0 and 100.';
