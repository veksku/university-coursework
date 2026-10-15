const express = require('express');
const kontroler = require('../controllers/pregledi');
const router = express.Router();

router.get('/', kontroler.prikaziPreglede);
router.post('/otkazi', kontroler.otkaziPregled, kontroler.prikaziPreglede);
router.post('/zakazi', kontroler.zakaziPregled);

module.exports = router;