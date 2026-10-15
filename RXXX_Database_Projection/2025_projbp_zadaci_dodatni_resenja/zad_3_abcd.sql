DROP SCHEMA IF EXISTS Prodavnica CASCADE;
CREATE SCHEMA Prodavnica;

SET SEARCH_PATH TO Prodavnica;

CREATE TABLE Proizvodi (
    sifra INT PRIMARY KEY,
    naziv VARCHAR(50) NOT NULL,
    cena REAL NOT NULL,
    popust INT NOT NULL DEFAULT 0 CHECK ( popust BETWEEN 0 AND 100 )
);

CREATE TABLE Prodaja (
    sifra INT PRIMARY KEY,
    sifra_proizvoda INT NOT NULL,
    kolicina INT NOT NULL,
    datum DATE NOT NULL,

    FOREIGN KEY (sifra_proizvoda) REFERENCES Proizvodi(sifra) ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE FUNCTION unos_proizvoda() RETURNS TRIGGER AS
$$
    BEGIN
        IF new.cena < 0 THEN
            RAISE EXCEPTION 'Greska - cena proizvoda ne moze biti negativna!';
        END IF;
        RETURN new;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER unos_proizvoda
BEFORE INSERT ON Proizvodi
FOR EACH ROW EXECUTE FUNCTION unos_proizvoda();

CREATE VIEW ProizvodiSaPopustom AS
SELECT P.sifra, P.naziv, (100.0 - P.popust) / 100.0 * P.cena AS snizena_cena, P.popust
FROM Proizvodi AS P;

CREATE FUNCTION unos_proizvoda_sa_popustom() RETURNS TRIGGER AS
$$
    BEGIN
        INSERT INTO Proizvodi
        VALUES (new.sifra, new.naziv, new.snizena_cena * 100 / (100 - new.popust), new.popust);
        RETURN new;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER unos_proizvoda
INSTEAD OF INSERT ON ProizvodiSaPopustom
FOR EACH ROW EXECUTE FUNCTION unos_proizvoda_sa_popustom();

INSERT INTO Proizvodi
VALUES (1, 'Cokolada', 100.0, 5);

SELECT * FROM ProizvodiSaPopustom;

INSERT INTO ProizvodiSaPopustom
VALUES (2, 'Nova cokolada', 95.0, 5);

SELECT * FROM Proizvodi;
