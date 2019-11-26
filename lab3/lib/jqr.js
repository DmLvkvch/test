$(document).ready(()=>{

    $('#mainchat').draggable();
    $('#mainchat').resizable({alsoResize:"#chat, #m"});
    $('body').on('click','tr[data-href]', function (e){
        window.location = $(this).attr('data-href');
    });

    $('body').on('click','tr[part-href]', function (e){
        window.location = $(this).attr('part-href');
    });

    $('#partedit').on('click', function (e) {
        $('.edit1').css('display', 'block');
        let x = $('.edit');
        for (let i = 0; i < x.length; i++) {
            $('.edit').eq(i).attr('readonly', false);
        }
        $("#select").attr('disabled', false);
    });

    $('.parteditY').on('click', function (e) {
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
        $('.edit1').css('display', 'block');
        let x = $('.edit');
        for (let i = 0; i < x.length; i++) {
            $('.edit').eq(i).attr('readonly', false);
        }
        $("#select").attr('disabled', false);
        $('#file1').css('display', 'block');
    });

    $("#editset").on('click', function (e) {
        $('.edit1').css('display', 'block');
        let x = $('.edit');
        for (let i = 0; i < x.length; i++) {
            $('.edit').eq(i).attr('readonly', false);
        }
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
        ajax('post', document.location.href, tmp);
        close()
    });

    $('.editY').click(function (el){
        let tmp = {};
        let x = $('.edit');
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
            url:'http://localhost:3000/paint/'+t[t.length-1],
            data: formData,
            processData:false,
            contentType:false,
            success:function (e) {
                e = JSON.parse(e);
                d = new Date();
                $(".image").removeAttr("src").attr("src", "http://localhost:3000/"+e.img+'?'+d.getTime());
            }
        });
        return false;
    });

    $('.editN').on('click', function (e) {
        close();
    });

    $('#partdel').on('click', function () {
        $.ajax({
            type:'delete',
            url:document.location.href,
            success: function (e){
                window.location.replace(e)
            }
        });
    });

    $('.addPic').on('click', function (e) {
        $('#addPic').css('display', 'block');
        $('.edit1').eq(0).css('display', 'block');
    });

    $('.addY').on('click', function (e) {
        let tmp = {};
        let x = $('.edit');
        tmp.name = x.eq(0).val();
        tmp.author = x.eq(1).val();
        tmp.date = x.eq(2).val();
        tmp.description = x.eq(3).val();
        ajax('post', document.location.href, tmp);

        var formData = new FormData();
        files = $("#file")[0].files[0];
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
        $('#addPic').css('display', 'none');
    });
});

function close() {
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
            zoom: 17
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
    $('#addPartmod').css('display', 'block');
});

$('#deleteP').on('click', function (e) {
   $.ajax({
       type:'delete',
       url:document.location.href,
       success: function (e){
           window.location.replace(e)
       }
   });
});

$('.partaddY').on('click', function (e) {
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