const char Rejected[] =
R"=====(
<!DOCTYPE html>
<html>
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
            h1{color: red; text-align:center; font-size: 50px;}
            h2{color: red; text-align:center; font-size: 50px;}
    </style>
 
</head>
<!----------------------------H T M L--------------------------------->
<body>
    <h1>
        <br> Rejected <br><br>
        
        <a href="/#1" id="btn" ONCLICK='JS1()'>Home</a> <br><br>
        
        
    </h1>

    
<!---------------------------JavaScript------------------------------->
<script>
    //function displays text message
    
    
   function JS1()
    {
      alert('RFID Rejected !!');
      
    }
</script>
</body>
</html>
)=====";
