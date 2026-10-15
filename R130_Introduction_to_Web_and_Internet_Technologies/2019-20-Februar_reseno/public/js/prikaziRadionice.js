$("#organizuj").submit(function() {
    let naziv = $("#naziv").val();
    if(naziv === "")
    {
        window.alert("Naziv je obavezan!");
        return false;
    }
    let broj = $("#broj").val();
    if(broj === "")
    {
        window.alert("Broja karata je obavezan!")
        return false;
    }
    if(parseInt(broj) <= 10)
    {
        window.alert("Broj karata mora biti veci od 10!");
        return false;
    }
    let datum = $("#datum").val();
    if(datum === "")
    {
        window.alert("Datum je obavezan!");
        return false;
    }
    let vreme = $("#vreme").val();
    if(vreme !== "" && parseInt(vreme) < 0)
    {
        window.alert("Vreme trajanja ne sme biti negativno!")
        return false;
    }
});