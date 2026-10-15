const models = require('../models/pregled');

module.exports.prikaziPreglede = async function(req, res, next) {
    try {
        let sviPregledi = await models.dohvatiPreglede();
        res.render('prikaziPreglede.ejs', {
            pregledi: sviPregledi
        });
    }
    catch(err) {
        next(err);
    }
};

module.exports.otkaziPregled = async function(req, res, next) {
    try {
        await models.otkaziPregled(req.body.id);
        next();
    }
    catch(err) {
        next(err);
    }
};

module.exports.zakaziPregled = async function(req, res, next) {
    try {
        let termin = new Date(req.body.datum);
        termin.setHours(req.body.vreme);
        let status = await models.zakaziPregled(req.body.lekar, req.body.pacijent, termin);
        res.render('zakaziPregled.ejs', {
            status: status
        });
    }
    catch(err) {
        next(err);
    }
}