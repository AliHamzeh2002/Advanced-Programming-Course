const params = new URLSearchParams(window.location.search)
if (params.has("msg")){
    document.getElementById("msg").innerHTML = params.get("msg"); 
    document.getElementById("alert").style.visibility = 'visible';
}
