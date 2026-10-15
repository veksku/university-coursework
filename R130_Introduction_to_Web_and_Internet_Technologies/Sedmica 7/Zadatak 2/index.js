/*const toDoLista = document.getElementById('lista');

function prikaziListu(){

}



function dodajStavkuListe(){
    const datum = document.getElementById('datum');
    const tekst = document.getElementById('tekst');

    if(datum.value != ''  && tekst.value != ''){
        const ul = document.createElement('ul');
        ul.className = "stavka";
        toDoLista.appendChild(ul);

        var k = tekst.value;
        const tx = document.createTextNode(k);
        ul.appendChild(tx);
    }
    else{
        if(datum.value === ''){
            console.log('Niste lepo popunili polje za datum');
        }
        if(tekst.value === ''){
            console.log('Niste popunili polje za tekst');
        }
    }
}
const dugme = document.getElementById('napravi-todo');

dugme.onclick = dodajStavkuListe;*/

let toDoLista = [];

function prikaziListu(){
    let lista = document.getElementById('lista')
    for(let i = lista.childNodes.length - 1; i >= 0; i--)
        lista.removeChild(lista.childNodes[i])
    for(let i = 0; i < toDoLista.length; i++){
        let div = document.createElement('div')
        div.className = 'stavka'
        let para1 = document.createElement('p')
        para1.style.fontStyle = 'italic'
        para1.style.marginLeft = '10px'
        let para2 = document.createElement('p')
        para2.style.width = '80%'
        para2.style.margin = 'auto'
        para2.style.wordWrap = 'break-word'
        
        tekst1 = document.createTextNode('Podsetnik za datum ' + toDoLista[i]['datum'] + ':')
        tekst2 = document.createTextNode(toDoLista[i]['tekst'])

        para1.appendChild(tekst1)
        para2.appendChild(tekst2)
        div.appendChild(para1)
        div.appendChild(para2)
        lista.appendChild(div)
    }    
    
}

function dodajStavkuListe(){
    let datum = document.getElementById('datum')
    let tekst = document.getElementById('tekst')
    if(tekst.value.trim() !== '' && datum.value.trim() !== ''){
        let stavka = {
            datum: datum.value.trim(),
            tekst: tekst.value.trim()
        }
        toDoLista.push(stavka)
    }
    prikaziListu()
}

let dugme = document.getElementById('napravi-todo')
//dugme.addEventListener('click',dodajStavkuListe)
dugme.onclick = dodajStavkuListe