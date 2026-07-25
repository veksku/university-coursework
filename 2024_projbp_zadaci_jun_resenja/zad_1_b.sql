DROP SCHEMA IF EXISTS kupoprodajni_ugovori CASCADE;
CREATE SCHEMA kupoprodajni_ugovori;

SET search_path TO kupoprodajni_ugovori;

CREATE TABLE ucesnici (
    jmbg CHAR(13) NOT NULL,
    ime VARCHAR(50) NOT NULL,
    prezime VARCHAR(50) NOT NULL,

    PRIMARY KEY (jmbg)
);

CREATE TABLE ugovori (
    sifra CHAR(10) NOT NULL,
    jmbg_kupca CHAR(13) NOT NULL,
    jmbg_prodavca CHAR(13) NOT NULL,
    ukupna_vrednost INT NOT NULL CHECK (ukupna_vrednost > 0),
    datum_zakljucenja DATE,

    PRIMARY KEY (sifra),
    FOREIGN KEY (jmbg_kupca) REFERENCES ucesnici(jmbg) ON DELETE CASCADE ON UPDATE RESTRICT,
    FOREIGN KEY (jmbg_prodavca) REFERENCES ucesnici(jmbg) ON DELETE CASCADE ON UPDATE RESTRICT,

    CHECK (jmbg_kupca <> ugovori.jmbg_prodavca)
);

CREATE TABLE uplate (
    sifra_ugovora CHAR(10) NOT NULL,
    redni_broj INT NOT NULL,
    iznos INT NOT NULL CHECK (iznos > 0),

    PRIMARY KEY (sifra_ugovora, redni_broj),
    FOREIGN KEY (sifra_ugovora) REFERENCES ugovori(sifra)
);
