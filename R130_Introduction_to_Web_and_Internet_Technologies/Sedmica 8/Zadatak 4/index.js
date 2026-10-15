let xhr = new XMLHttpRequest()
xhr.open('GET','https://codepen.io/chriscoyier/pen/EAIJj.js')



xhr.addEventListener('load',function(){

    let odg = xhr.response
    let odgovor = JSON.parse(odg)

    let tabela = document.getElementById('tabela')


    let red = document.createElement('tr')
        let celija1 = document.createElement('td')
        let text1 = document.createTextNode('ID')
        let celija2 = document.createElement('td')
        let text2 = document.createTextNode('Type')
        celija1.appendChild(text1)
        celija2.appendChild(text2)
        red.appendChild(celija1)
        red.appendChild(celija2)
        tabela.appendChild(red)

    for(let i = 0; i < odgovor.batters.batter.length; i++){
        let red = document.createElement('tr')
        let celija1 = document.createElement('td')
        let text1 = document.createTextNode(odgovor.batters.batter[i].id)
        let celija2 = document.createElement('td')
        let text2 = document.createTextNode(odgovor.batters.batter[i].type)
        celija1.appendChild(text1)
        celija2.appendChild(text2)
        red.appendChild(celija1)
        red.appendChild(celija2)
        tabela.appendChild(red)
    }

    let lista = document.getElementById('lista')

    for(let i = 0; i < odgovor.topping.length; i++){
        let stavka = document.createElement('li')
        let text1 = document.createTextNode(odgovor.topping[i].type)
        stavka.appendChild(text1)
        lista.appendChild(stavka)
    }
})

xhr.addEventListener('error', function() {
	console.error('Problem prilikom slanja zahteva');
});

xhr.send()