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

CREATE FUNCTION provera_cene() RETURNS TRIGGER AS
$$
    BEGIN
        IF new.cena_u_dinarima <= 0 THEN
            RAISE EXCEPTION 'Cena artikla mora biti pozitivna!';
        END IF;
        RETURN new;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER provera_cene
BEFORE INSERT OR UPDATE ON artikal
FOR EACH ROW
EXECUTE FUNCTION provera_cene();

INSERT INTO artikal
VALUES (0, 'Mleko', 99.99);

-- INSERT INTO artikal
-- VALUES (1, 'Kackavalj', -123.99);

-- UPDATE artikal
-- SET cena_u_dinarima = -cena_u_dinarima
-- WHERE naziv = 'Mleko';

CREATE VIEW artikli_u_evrima AS
SELECT id, naziv, cena_u_dinarima / 100 AS cena_u_evrima
FROM artikal;

SELECT * FROM artikli_u_evrima;

CREATE FUNCTION unos_artikala_u_evrima() RETURNS TRIGGER AS
$$
    BEGIN
        INSERT INTO artikal
        VALUES (new.id, new.naziv, new.cena_u_evrima * 100);
        RETURN new;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER unos_artikala_u_evrima
INSTEAD OF INSERT ON artikli_u_evrima
FOR EACH ROW
EXECUTE FUNCTION unos_artikala_u_evrima();

INSERT INTO artikli_u_evrima
VALUES (1, 'Cokolada', 2.2);

SELECT * FROM artikli_u_evrima;

INSERT INTO artikal
VALUES (2, 'Ogroman lilihip', 1999.99);

INSERT INTO sekcija
VALUES ('Slatkisi', 'Ogroman lilihip');

INSERT INTO sekcija
VALUES ('Slatkisi', 'Cokolada');

CREATE VIEW izabrani_artikli AS
SELECT a.id, a.naziv, a.cena_u_dinarima, s.naziv_sekcije AS sekcija
FROM artikal AS a JOIN sekcija AS s ON a.naziv = s.naziv_artikla
WHERE cena_u_dinarima > 1500;

-- Bez INSTEAD OF okidaca brisanje nije moguce jer je pogled kreiran nad spojenim tabelama.

-- DELETE FROM izabrani_artikli
-- WHERE sekcija = 'Slatkisi';

CREATE FUNCTION obrisi_artikle() RETURNS TRIGGER AS
$$
    BEGIN
        DELETE FROM artikal
        WHERE id = old.id;
        RETURN old;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER brisanje_izabranih_artikala
INSTEAD OF DELETE ON izabrani_artikli
FOR EACH ROW
EXECUTE FUNCTION obrisi_artikle();

SELECT * FROM izabrani_artikli;

DELETE FROM izabrani_artikli
WHERE sekcija = 'Slatkisi';

SELECT * FROM izabrani_artikli;
