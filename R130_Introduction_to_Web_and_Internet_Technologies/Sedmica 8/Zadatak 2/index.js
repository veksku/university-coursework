let polje = document.getElementById('username')

let duzina
polje.addEventListener('blur',
    function(){
    duzina = polje.value.trim().length
    console.log(duzina)
    if(duzina < 5){
        window.alert('Korisničko ime mora biti duže od 5 karaktera!')   
    }        
})
