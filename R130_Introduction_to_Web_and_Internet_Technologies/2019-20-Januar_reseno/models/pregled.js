const mongoose = require('mongoose');

const shema = mongoose.Schema({
    _id: mongoose.Schema.Types.ObjectId,
    lekar: {
        type: String,
        required: true
    },
    pacijent: {
        type: String,
        required: true
    },
    termin: {
        type: Date,
        required: true
    }
});

const Ordinacija = mongoose.model('Ordinacija', shema);
module.exports.Ordinacija = Ordinacija;

module.exports.dohvatiPreglede = async function() {
    let sviPregledi = await Ordinacija.find({}).sort({termin: 1}).exec();
    return sviPregledi;
};

module.exports.otkaziPregled = async function(id) {
    await Ordinacija.deleteOne({_id: id}).exec();
};

module.exports.zakaziPregled = async function(lekar, pacijent, termin) {
    let uTerminu = await Ordinacija.countDocuments({lekar: lekar, termin: termin});
    if(uTerminu > 0)
        return false;
    let noviPregled = new Ordinacija({
            _id: new mongoose.Types.ObjectId(),
            lekar: lekar,
            pacijent: pacijent,
            termin: termin
    });
    await noviPregled.save();
    return true;
};