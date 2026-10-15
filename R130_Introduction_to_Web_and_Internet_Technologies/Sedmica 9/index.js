$('#username').ready(function(){
    $('#username').blur(function(){
        if(!($(this).val())){
            $('span:first').addClass('greska')
            $('span:first').html('polja obeležena sa <sup> * </sup> su obavezna')
        }
        else{
            $('span:first').removeClass('greska')
            $('span:first').html('')
        }
    })
})

$('#email').ready(function(){
    $('#email').blur(function(){
        if(!($(this).val())){
            if($(this).siblings('span.greska').length === 0)
                $(this).parent().append('<span class="greska">polja obeležena sa <sup> * </sup> su obavezna</span>')
        }
        else{
            $($(this).siblings()).remove('span')
        }
    })
})

$('#sifra1').ready(function(){
    $('#sifra1').keypress(function(){
        if($(this).val().length <= 5){
            if($(this).siblings('span.greska').length === 0)
            $(this).parent().append('<span class="greska">Nekorektna lozinka</span>')
        }
        else{
            $($(this).siblings()).remove('span')
        }
    })
})

$('#prijava').ready(function(){
    $('#prijava').prop('checked',false)

    $('#prijava').change(function(){
        if($(this).is(':checked')){
            $('#vesti').show(1000,function(){
                $(this).slideDown(1000)
            })
        }
        else{
            $('#vesti').hide(1000,function(){
                $(this).slideUp(1000)
            })
        }
    })
})

$('input[type="submit"]').ready(function(){
        $('input[type="submit"]').click(function(ev){
            $('p').empty()

            if($('#username').val().length == 0){
                $('#izvestaj').append('Nije uneto korisnicko ime <br>')
                $('#username').focus()
                ev.preventDefault()
            }
            if($('#email').val().length == 0 || $('#email').val().indexOf('.') == -1 || $('#email').val().indexOf('@') == -1 ||
                $('#email').val().lastIndexOf('.') < $('#email').val().indexOf('@')){
                    $('#izvestaj').append('Nije unet korektan email<br>')
                    $('#email').focus()
                    ev.preventDefault()
            }
            if($('#sifra1').val().length <= 5 || $('#sifra2').val().length <= 5 || $('#sifra1').val() != $('#sifra2').val()){
                $('#izvestaj').append('Nisu unete korektne sifre <br>')
                $('#sifra1').focus()
                ev.preventDefault()
            }
            if($('#prijava').is(':checked')){
                if($(':selected').val() == ''){
                    window.alert('Nije odabrana oblast')
                    ev.preventDefault()
                }
                else{
                    window.alert($(':selected').text() + $($('input[type="radio"]:checked').siblings()).text())
                }
            }
        })
})    