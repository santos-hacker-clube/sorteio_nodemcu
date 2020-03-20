const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>

<div id="demo">
<h1>SANTOS HACKER CLUBE <h1>
<h1>SORTEIO ARDUINO DAY 2020 <h1>
<h3>Pressione e segure o FLASH da placa <h3>


</div>

<div>
 <h1> Num. Sorteado  = <span id="sorteioValue">0</span><br> <h1>
   
</div>
<script>
function sendData(led) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("LEDState").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "setLED?LEDstate="+led, true);
  xhttp.send();
}

setInterval(function() {
  // chama
  getData();
}, 500); //2000
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("sorteioValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readADC", true);
  xhttp.send();
}
</script>


<h3>Santos Hacker Clube<h3>
</body>
</html>
)=====";
