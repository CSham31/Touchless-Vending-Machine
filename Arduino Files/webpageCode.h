const char webpageCode[] =
R"=====(
<!DOCTYPE html>
<html>
<!------------------------------C S S--------------------------------->
<head>
    <style>
         #btn 
         { background-color: #000000; 
            border: none; 
            border-radius: 120px;
            color: #ffffff; 
            padding: 16px 40px; 
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;}
            body {font-family: "Calibri"; background-color: grey}
            h1{color: whitesmoke; text-align:center; font-size: 50px;}
            h2{color: whitesmoke; text-align:center; font-size: 50px;}
    </style>
    <style>
        #btn1
        {
            background-color: #af0c0c; 
            border: none; 
            border-radius: 120px;
            color: #ffffff; 
            padding: 16px 40px; 
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;}
    </style>

    <style>
        #btn2
        {
            background-color: #2306c7; 
            border: none; 
            border-radius: 120px;
            color: #c50e0e; 
            padding: 16px 40px; 
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;}
    </style>
    <style>
        #btn3
        {
            background-color: #098119; 
            border: none; 
            border-radius: 120px;
            color: #ffffff; 
            padding: 16px 40px; 
            text-decoration: none;
            font-size: 30px;
            margin: 2px;
            cursor: pointer;}
    </style>
</head>
<!----------------------------H T M L--------------------------------->
<body>
    <h1>
        <br> Touchless Vending Machine <br><br>
        
        <a href="1" id="btn1" ONCLICK='JS1()'>Coke</a> <br><br>
        <a href="2" id="btn2" ONCLICK='JS2()'>Pepsi</a> <br><br>
        <a href="3" id="btn3" ONCLICK='JS3()'>Sprite</a>
    </h1>
    <hr size="6" width="60%" color=#098119;>
    <h2>
         Vendor <br><br>
        <a href="0" id="btn" ONCLICK='JS0()'>Refill</a> <br><br>
    </h2>
<!---------------------------JavaScript------------------------------->
<script>
    //function displays text message
    let m0 = 'Place your ID'
    let m1 = 'You Selected Coke, Pay Here'
    let m2 = 'You Selected Pepsi, Pay Here'
    let m3 = 'You Selected Sprite, Pay Here'
    
    function JS0()
    {
      alert(m0);
      
    }
    function JS1()
    {
      alert(m1);
      
    }
    //function prompts for name, then displays message
    function JS2()
    {
        alert(m2);
        
    }
    //function computes factorial of integer number
    function JS3()
    {   alert(m3);
        
    }   
</script>
</body>
</html>
)=====";
