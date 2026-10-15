$("#dugme").click(function() {
    $("#zakazi").slideDown();
});

$("#zakazi").submit(function() {
    let lekar = $("#lekar").val();
    if(lekar === "")
    {
        window.alert("Ime lekara je obavezno!");
        $("#lekar").focus();
        return false;
    }
    let pacijent = $("#pacijent").val();
    if(pacijent === "")
    {
        window.alert("Ime pacijenta je obavezno!");
        $("#pacijent").focus();
        return false;
    }
    let datum = $("#datum").val();
    if(datum === "")
    {
        window.alert("Datum je obavezan!");
        $("#datum").focus();
        return false;
    }
    let vreme = $("#vreme").val();
    if(vreme === "")
    {
        window.alert("Vreme je obavezno!");
        $("#vreme").focus();
        return false;
    }
    if(parseInt(vreme) < 7 || parseInt(vreme) > 19)
    {
        window.alert("Vreme mora biti izmedju 7 i 19!");
        $("#vreme").focus();
        return false;
    }
});