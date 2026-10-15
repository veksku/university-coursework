const mongoose = require('mongoose');

const shema = mongoose.Schema({
    _id: mongoose.Schema.Types.ObjectId,
    naziv: {
        type: String,
        required: true
    },
    brojUlaznica: {
        type: Number,
        required: true
    },
    datum: {
        type: Date,
        required: true
    },
    vremeTrajanja: {
        type: Number,
        default: 2
    }
});

const Radionica = mongoose.model('Radionica', shema);
module.exports.Radionica = Radionica;

module.exports.dohvatiRadionice = async function() {
    let dostupneRadionice = await Radionica.find({brojUlaznica: {$gt: 0}}).sort({datum: 1, naziv: 1}).exec();
    return dostupneRadionice;
};

module.exports.organizujRadionicu = async function(naziv, broj, datum, vreme) {
    let radionica = new Radionica({
        _id: new mongoose.Types.ObjectId,
        naziv: naziv,
        brojUlaznica: broj,
        datum: datum,
    });
    if(vreme !== "")
        radionica.vremeTrajanja = vreme;
    await radionica.save();
};

module.exports.rezervisiKarte = async function(naziv, broj) {
    await Radionica.updateOne({naziv: naziv}, {$inc: {brojUlaznica: -broj}}).exec();
}