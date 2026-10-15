const models = require('../models/radionica');

module.exports.prikazRadionica = async function(req, res, next) {
    try {
        let dostupneRadionice = await models.dohvatiRadionice();
        res.render('prikaziRadionice.ejs', {
            radionice: dostupneRadionice
        });
    }
    catch(err) {
        next(err);
    }
};

module.exports.organizuj = async function(req, res, next) {
    try {
        let danas = new Date();
        if(Date.parse(req.body.datum) < danas)
            throw new Error('Datum radionice ne moze biti u proslosti');
        else
        {
            await models.organizujRadionicu(req.body.naziv, req.body.broj, req.body.datum, req.body.vreme);
            next();
        }
    }
    catch(err) {
        next(err);
    }
}

module.exports.rezervisi = async function(req, res, next) {
    try {
        await models.rezervisiKarte(req.body.naziv, req.body.broj);
        next();
    }
    catch(err) {
        next(err);
    }
}