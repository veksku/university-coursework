let f = document.querySelector('#formular')
f.addEventListener('submit',function(ev){
    let polje

    const greska = document.querySelector('#greska')

    let br = 0
    polje = document.getElementsByClassName('form-check-input')
    for(let i = 0; i < polje.length; i++)
        if(polje[i].checked)
            br++
    if(br < 2){
        greska.textContent = ('izaberite bar 2 opcije')
        polje[0].focus()
        ev.preventDefault()
    }        
})