const studenti = [
/*i=0*/    {indeks:'20140021',ime:'Milos',prezime:'Peric',datum_rodjenja:'20.01.1995.',mesto_rodjenja:'Beograd',datum_upisa:'06.07.2014.'}, 
/*i=1*/    {indeks:'20140022',ime:'Marijana',prezime:'Savkovic',datum_rodjenja:'11.03.1995.',mesto_rodjenja:'Kraljevo',datum_upisa:'05.07.2014.'}, 
/*i=2*/    {indeks:'20130023',ime:'Sanja',prezime:'Terzic',datum_rodjenja:'09.11.1994.',mesto_rodjenja:'Beograd',datum_upisa:'04.07.2013.'}, 
/*i=3*/    {indeks:'20130024',ime:'Nikola',prezime:'Vukovic',datum_rodjenja:'17.09.1994.',mesto_rodjenja:' ',datum_upisa:'04.07.2013.'}, 
/*i=4*/    {indeks:'20140025',ime:'Marijana',prezime:'Savkovic',datum_rodjenja:'04.02.1995.',mesto_rodjenja:'Kraljevo',datum_upisa:'06.07.2014.'}, 
/*i=5*/    {indeks:'20140026',ime:'Zorica',prezime:'Miladinovic',datum_rodjenja:'08.10.1995.',mesto_rodjenja:'Vranje',datum_upisa:'06.07.2014.'}, 
/*i=6*/    {indeks:'20130027',ime:'Milena',prezime:'Stankovic',datum_rodjenja:' ',mesto_rodjenja:' ',datum_upisa:' '}
]

function spoji_ime_i_prezime(studenti){
    for(let i = 0; i < studenti.length; i++){
        studenti[i].ime_prezime = studenti[i].ime + studenti[i].prezime
        delete studenti[i].ime
        delete studenti[i].prezime
    }
}

function filter_indeks(studenti, godina){
    let rezultat = []
    for(let i = 0; i < studenti.length; i++){
        let god_upisa = studenti[i].indeks.slice(0,4)
        if (god_upisa === godina)
            rezultat.push(studenti[i])
    }
    return rezultat
}

function filter_f(studenti, f){
    let rezultat = []
    for(let i = 0; i < studenti.length; i++){
        let vrednost = f(studenti[i])
        if(vrednost === true)
            rezultat.push(studenti[i])
    }
    return rezultat        
}    

function nema_nepoznate_vrednosti(student){
   
    if(student.indeks === '' || student.ime === '' || student.prezime === '' || student.prezime === '' || student.datum_rodjenja === ''
    || student.mesto_rodjenja === '' || student.datum_upisa === '')
        return false
    else
        return true
    
}

function pocisti_podatke(studenti){
    let rezultat = []
    rezultat = studenti.filter(x => (filter_f(studenti, nema_nepoznate_vrednosti)).includes(x))
    return rezultat
}
const button = document.getElementById('prikazi_podatke');

function generisi_html(studenti){
    let body = document.body
    let tbl = document.createElement('table')
    body.appendChild(tbl)
    
    let red0 = document.createElement('tr')
    for(let kljuc in studenti[0]){
        let celija = document.createElement('td')
        celija.innerHTML = kljuc 
        red0.appendChild(celija)
        celija.style.border = '1px solid black'
        celija.style.textAlign = 'center'
        celija.style.width = '90px'
        celija.style.height = '40px'
    }
    tbl.appendChild(red0)
    red0.style.backgroundColor = 'black'
    red0.style.color = 'white'

    for(let i = 0; i < studenti.length; i++){
        let red = document.createElement('tr')
        for(let kljuc in studenti[i]){
            let celija = document.createElement('td')
            celija.innerHTML = studenti[i][kljuc] 
            red.appendChild(celija)
            if(kljuc === 'indeks')
                celija.className = 'prva'
            celija.style.border = '1px solid black'
            celija.style.width = '90px'
            celija.style.height = '40px'
        }
        tbl.appendChild(red)
    }
    tbl.style.borderCollapse = 'collapse'
}

button.onclick = generisi_html;