$(document).ready(()=>{
    $('body').on('click','tr[data-href]', function (e){
        window.location = $(this).attr('data-href');
    });

    $('body').on('click','tr[part-href]', function (e){
        window.location = $(this).attr('part-href');
    });

    $('#partedit').on('click', function (e) {
        /*
        document.getElementsByClassName('edit1')[0].style.display = 'block';
        $('.edit1')[0].style('block');
        for(let i = 0; i<document.getElementsByClassName('edit').length;i++)
            document.getElementsByClassName('edit')[i].readOnly = false;
        document.getElementById('select').disabled = false;

         */
        $('.edit1').css('display', 'block');
        $('.edit').css('readonly', false);
        $("#select").css('disabled', false);
    });

    $('.parteditY').on('click', function (e) {
        //let x = document.getElementsByClassName('edit');
        let x = $('.edit');
        let tmp = {};
        tmp.name = x.eq(0).val();
        tmp.location = x.eq(1).val();
        tmp.inAuc = x.eq(2).val();
        tmp.x = x.eq(3).val();
        tmp.y = x.eq(4).val();
        ajax('post', document.location.href, tmp);
        $.ajax({
            type:'get',
            url: document.location.href,
            success: function (msg) {
                $('#map').html("");
                initMap(tmp.x, tmp.y)
            }
        });
        close();
    });

    $('.editP').on('click', function (e){
        /*
        document.getElementsByClassName('edit1')[0].style.display = 'block';
        for(let i = 0; i<document.getElementsByClassName('edit').length;i++)
            document.getElementsByClassName('edit')[i].readOnly = false;
        document.getElementById('select').disabled = false;
        document.getElementById('file1').style.display = 'block'
         */
        $('.edit1').css('display', 'block');
        $('.edit').attr('readonly', false);
        $("#select").attr('disabled', false);
        $('#file1').css('display', 'block');
    });

    $("#editset").on('click', function (e) {
        /*
        document.getElementsByClassName('edit1')[0].style.display = 'block';
        for(let i = 0; i<document.getElementsByClassName('edit').length;i++)
            document.getElementsByClassName('edit')[i].readOnly = false;
         */
        $('.edit1').css('display', 'block');
        $('.edit').css('readonly', false);
    });

    $('.seteditY').on('click', function (e){
        let tmp = {};
        let x = $('.edit');
        $('.edit').attr('readonly', true);
        $('.edit1').eq(0).css('display', 'none');
        tmp.date = x.eq(0).val();
        tmp.time = x.eq(1).val();
        tmp.out = x.eq(2).val();
        tmp.duration = x.eq(3).val();
        tmp.pause = x.eq(4).val();

        /*
        tmp.date = (document.getElementsByClassName('edit')[0].value);
        tmp.time = (document.getElementsByClassName('edit')[1].value);
        tmp.out = (document.getElementsByClassName('edit')[2].value);
        tmp.duration = (document.getElementsByClassName('edit')[3].value);
        tmp.pause = (document.getElementsByClassName('edit')[4].value);
        for(let i = 0; i<document.getElementsByClassName('edit').length;i++)
            document.getElementsByClassName('edit')[i].readOnly = true;
        document.getElementsByClassName('edit1')[0].style.display = 'none';
         */
        ajax('post', document.location.href, tmp);
    });

    $('.image').click(function(){
        $(".image").attr('src',"https://localhost:3000/1.jpg");
        return false;
    });

    $('.editY').click(function (el){
        let tmp = {};
        let x = $('.edit');
        /*
        tmp.name = (document.getElementsByClassName('edit')[0].value);
        tmp.author = (document.getElementsByClassName('edit')[1].value);
        tmp.date = (document.getElementsByClassName('edit')[2].value);
        tmp.description = (document.getElementsByClassName('edit')[3].value);
        tmp.inAuc = (document.getElementsByClassName('edit')[4].value);
         */
        tmp.name = x.eq(0).val();
        tmp.author = x.eq(1).val();
        tmp.date = x.eq(2).val();
        tmp.description = x.eq(3).val();
        tmp.inAuc = x.eq(4).val();
        close();
        $('#file1').css('display', 'none');
        ajax('post', document.location.href, tmp);
        var formData = new FormData();
        files = $("#file1")[0].files[0];
        formData.append('file' , files);
        let t = document.location.href.split('/');
        $.ajax({
            type:'put',
            url:'https://localhost:3000/paint/'+t[t.length-1],
            data: formData,
            processData:false,
            contentType:false,
            success:function (e) {
                console.log("https://localhost:3000/"+t[t.length-1]+'.jpg');
                d = new Date();
                $(".image").removeAttr("src").attr("src", "https://localhost:3000/"+t[t.length-1]+'.jpg?'+d.getTime());
            }
        });
        return false;
    });

    $('.editN').on('click', function (e) {
        close();
    });

    $('.addPic').on('click', function (e) {
        /*
        document.getElementById('addPic').style.display = 'block';
        document.getElementsByClassName('edit1')[0].style.display = 'block';

         */
        $('#addPic').css('display', 'block');
        $('.edit1').eq(0).css('display', 'block');
    });

    $('.addY').on('click', function (e) {
        let tmp = {};
        /*
        tmp.name = (document.getElementsByClassName('edit')[0].value);
        tmp.author = (document.getElementsByClassName('edit')[1].value);
        tmp.date = (document.getElementsByClassName('edit')[2].value);
        tmp.description = (document.getElementsByClassName('edit')[3].value);
        document.getElementById('addPic').style.display = 'none';

         */
        let x = $('.edit');
        tmp.name = x.eq(0).val();
        tmp.author = x.eq(1).val();
        tmp.date = x.eq(2).val();
        tmp.description = x.eq(3).val();
        ajax('post', document.location.href, tmp);

        var formData = new FormData();
        files = $("#file")[0
            ].files[0];
        formData.append('file' , files);
        $.ajax({
            type:'post',
            url:'/image',
            data: formData,
            processData:false,
            contentType:false,
            success:function (e) {
                console.log(e);
            }
        });
    });

    $('.addN').on('click', function (e) {
        //document.getElementById('addPic').style.display = 'none';
        $('#addPic').css('display', 'none');
    });
});

function close() {
    /*
    for(let i = 0; i<document.getElementsByClassName('edit').length;i++)
        document.getElementsByClassName('edit')[i].readOnly = true;
    document.getElementById('select').disabled = true;
    document.getElementsByClassName('edit1')[0].style.display = 'none';

     */
    let x = $('.edit');
    for (let i = 0; i < x.length; i++) {
        $('.edit').eq(i).attr('readonly', true);
    }
    $('#select').attr('disabled', true);
    $('.edit1').css('display', 'none');
}

function initMap(x, y) {
    ymaps.ready(init);
    function init(){
        var myMap = new ymaps.Map("map", {
            center: [x, y],
            zoom: 7
        }),
        myGeoObject = new ymaps.GeoObject({
            // Описание геометрии.
            geometry: {
            type: "Point",
            coordinates: [x, y]
            }
        });
        myMap.geoObjects.add(myGeoObject);
    }
}

$('.addPart').on('click', function (e) {
   //document.getElementById('addPartmod').style.display = 'block'
    $('#addPartmod').css('display', 'block');
});

$('#deleteP').on('click', function (e) {
   $.ajax({
       type:'delete',
       url:document.location.href,
       success: function (e){
           window.location.replace(e)
       }
   })
});

$('.partaddY').on('click', function (e) {
   //x = document.getElementsByClassName('edit');
   let x = $('.edit');
   tmp = {};
   tmp.name = x.eq(0).val();
   tmp.location = x.eq(1).val();
   tmp.x = x.eq(2).val();
   tmp.y = x.eq(3).val();
   url = document.location.href;
    $.ajax({
        type:'post',
        url:url,
        data: tmp,
        success: function (txt) {
            $.ajax({
                url:url,
                type:'get',
                success: function (msg) {
                    $('#addPartmod').parent().html(txt);
                }
            })
        }
    });
    document.getElementById('addPartmod').style.display = 'none'
});

function ajax(type, url, data){
    $.ajax({
        url:url,
        type:type,
        data:data,
        success: function (msg) {
            $.ajax({
                url:url,
                type:'get',
                success: function (msg) {
                    $("#tble").parent().html(msg) ;
                }
            })
        }

    });
}