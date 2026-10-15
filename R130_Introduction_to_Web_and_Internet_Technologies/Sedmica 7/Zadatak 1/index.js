const studenti = [
    {indeks:'20140021',ime:'Milos',prezime:'Peric',datum_rodjenja:'20.01.1995.',mesto_rodjenja:'Beograd',datum_upisa:'06.07.2014.'}, 
    {indeks:'20140022',ime:'Marijana',prezime:'Savkovic',datum_rodjenja:'11.03.1995.',mesto_rodjenja:'Kraljevo',datum_upisa:'05.07.2014.'}, 
    {indeks:'20130023',ime:'Sanja',prezime:'Terzic',datum_rodjenja:'09.11.1994.',mesto_rodjenja:'Beograd',datum_upisa:'04.07.2013.'}, 
    {indeks:'20130024',ime:'Nikola',prezime:'Vukovic',datum_rodjenja:'17.09.1994.',mesto_rodjenja:' ',datum_upisa:'04.07.2013.'}, 
    {indeks:'20140025',ime:'Marijana',prezime:'Savkovic',datum_rodjenja:'04.02.1995.',mesto_rodjenja:'Kraljevo',datum_upisa:'06.07.2014.'}, 
    {indeks:'20140026',ime:'Zorica',prezime:'Miladinovic',datum_rodjenja:'08.10.1995.',mesto_rodjenja:'Vranje',datum_upisa:'06.07.2014.'}, 
    {indeks:'20130027',ime:'Milena',prezime:'Stankovic',datum_rodjenja:' ',mesto_rodjenja:' ',datum_upisa:' '}
];

const wrapper = document.getElementById('podaci');
const tabela = document.createElement('table');
wrapper.appendChild(tabela);
const thead = document.createElement('thead');
tabela.appendChild(thead);
const tbody = document.createElement('tbody');
tabela.appendChild(tbody);

function kreiraj_zaglavlje_tabele(studenti) {
    const tr = document.createElement('tr');
    thead.appendChild(tr);
    for(const k in studenti[0]) {
        const th = document.createElement('th');
        tr.appendChild(th);
        const tx = document.createTextNode(k);
        th.appendChild(tx);
    }
}

function kreiraj_red_tabele(student) {
    const tr = document.createElement('tr');
    tbody.appendChild(tr);
    for(const k in student) {
        const td = document.createElement('td');
        tr.appendChild(td);
        const tx = document.createTextNode(student[k]);
        td.appendChild(tx);
    }
}

function postavi_hover_stil() {
    this.style.backgroundColor = 'gray';
}

function ukloni_hover_stil() {
    this.style.backgroundColor = 'white';
}

function odaberi_studenta() {
    const os = document.getElementById('odabran_student');
    while(os.children.length>0) {
        os.removeChild(os.children[0]);
    }
    const h1 = document.createElement('h1');
    os.appendChild(h1);
    const h1t = document.createTextNode('Odabran student');
    h1.appendChild(h1t);
    const studentId = this.textContent.slice(0,8);
    for(const s of studenti) {
        if (s['indeks'] === studentId) {
            for(const k in s) {
                if(s[k] !== ' ') {
                    const p = document.createElement('p');
                    os.appendChild(p);
                    const pt = document.createTextNode(k + ': ' + s[k]);
                    p.appendChild(pt);
                }
            }
        }
    }
}

function postavi_osluskivace_nad_prvom_kolonom() {
    trs = document.querySelectorAll('tbody tr');
    for(const tr of trs) {
        tr.addEventListener('mouseenter',postavi_hover_stil);
        tr.addEventListener('mouseleave',ukloni_hover_stil);
        tr.addEventListener('click',odaberi_studenta);
    }
}

const dugme = document.getElementById('prikazi_podatke');

function prikazi_podatke() {
    kreiraj_zaglavlje_tabele(studenti);
    for(const s of studenti) {
        kreiraj_red_tabele(s);
    }
    postavi_osluskivace_nad_prvom_kolonom();
    dugme.disabled = true;
}

dugme.onclick = prikazi_podatke;