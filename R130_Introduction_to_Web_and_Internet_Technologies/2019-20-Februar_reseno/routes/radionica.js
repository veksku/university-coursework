const express = require('express');

const kontroler = require('../controllers/radionica');
const router = express.Router();

router.get('/', kontroler.prikazRadionica);
router.post('/organizuj', kontroler.organizuj, kontroler.prikazRadionica);
router.post('/rezervisi', kontroler.rezervisi, kontroler.prikazRadionica);

module.exports = router;