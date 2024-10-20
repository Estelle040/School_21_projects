-- CREATE TABLE person_discounts
--     (
--         id SERIAL PRIMARY KEY             ,
--         person_id   INTEGER NOT NULL      ,
--         pizzeria_id INTEGER NOT NULL      ,
--         discount    NUMERIC(5, 2) NOT NULL,
--         CONSTRAINT fk_person_discounts_person_id FOREIGN KEY (person_id) REFERENCES person (id) ON
--         DELETE
--             CASCADE,
--             CONSTRAINT fk_person_discounts_pizzeria_id FOREIGN KEY (pizzeria_id) REFERENCES pizzeria (id) ON
--         DELETE
--             CASCADE );

SELECT * FROM person_discounts;