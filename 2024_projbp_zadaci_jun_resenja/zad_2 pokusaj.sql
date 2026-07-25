DROP SCHEMA IF EXISTS prodavnica CASCADE;
CREATE SCHEMA prodavnica;

SET search_path TO prodavnica;

CREATE TABLE artikal (
    id SERIAL NOT NULL,
    naziv VARCHAR(50) NOT NULL,
    cena_u_dinarima REAL NOT NULL,

    PRIMARY KEY (id)
);

CREATE TABLE sekcija (
    naziv_sekcije VARCHAR(50) NOT NULL,
    naziv_artikla VARCHAR(50) NOT NULL,

    PRIMARY KEY (naziv_sekcije, naziv_artikla)
);

--kod

--

INSERT INTO artikal
VALUES (0, 'Mleko', 99.99);

-- INSERT INTO artikal
-- VALUES (1, 'Kackavalj', -123.99);

-- UPDATE artikal
-- SET cena_u_dinarima = -cena_u_dinarima
-- WHERE naziv = 'Mleko';

--kod

--

SELECT * FROM artikli_u_evrima;

--kod

--

INSERT INTO artikli_u_evrima
VALUES (1, 'Cokolada', 2.2);

SELECT * FROM artikli_u_evrima;

INSERT INTO artikal
VALUES (2, 'Ogroman lilihip', 1999.99);

INSERT INTO sekcija
VALUES ('Slatkisi', 'Ogroman lilihip');

INSERT INTO sekcija
VALUES ('Slatkisi', 'Cokolada');

--kod

--

-- Bez INSTEAD OF okidaca brisanje nije moguce jer je pogled kreiran nad spojenim tabelama.

-- DELETE FROM izabrani_artikli
-- WHERE sekcija = 'Slatkisi';

--kod

--

SELECT * FROM izabrani_artikli;

DELETE FROM izabrani_artikli
WHERE sekcija = 'Slatkisi';

SELECT * FROM izabrani_artikli;
