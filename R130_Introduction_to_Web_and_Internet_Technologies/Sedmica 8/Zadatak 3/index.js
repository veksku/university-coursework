let dugme = document.getElementById('izracunaj')
dugme.addEventListener('click',function(){
    let polje1 = document.getElementById('a')
    let polje2 = document.getElementById('b')
    let polje3 = document.getElementById('c')

    let av = parseFloat(polje1.value)
    let bv = parseFloat(polje2.value)
    let cv = parseFloat(polje3.value)

    if(av <= 0 || av <= Math.abs(bv - cv) ||av >= bv + cv)
        window.alert('Pogresan unos za a')
    if(bv <= 0 || bv <= Math.abs(cv - av) || bv >= av + cv)
        window.alert('Pogresan unos za b')
    if(cv <= 0 || cv <= Math.abs(bv - av) || cv >= bv + av)
        window.alert('Pogresan unos za c')

    let povrsina = document.getElementById('P')
    let poluobim = (av + bv + cv)/2

    povrsina.value = Math.sqrt(poluobim * (poluobim - av) * (poluobim - bv) * (poluobim - cv))  
})