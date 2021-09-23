# Touchless-Vending-Machine
Smart IoT System for Vending Machine Monitoring


## System Overview and Operations
Regular use of vending machines has two features that require physical contact with the machine.
* Selecting the required food or beverage item.
* The payment process involving conventional notes and coins

We insert a QR code on the vending machine surface. Once the QR is scanned by a user, he/she will be directed to a webpage that allows him/her to select the food or beverage item. After the selecting required item user will redirect to the payment process. We have selected to RFID which is the most used and easiest payment method available nowadays to make payment process touchless. So, the user can make the payment using their bank credit/debit card or specific RFID card issued by vending company. Through that we provide users a contactless way to carry out their purchases in the times of a pandemic.

For the Vendor’s side, we enable the power of IoT by,
* Providing a Dashboard which shows the current sales amount, availability of stocks for each product in the machine etc.
* Email alerts when a stock drops below a certain threshold defined by the vendor
* Daily sales data logs for further business analysis

The dashboard will show the current number of stocks available in the machine and how the daily sales have carried out for each machine. The data about availability of stocks will help the manager to plan the logistics and to minimize the costs. Also, our system will provide on dashboard alerts as well as Email alerts to the vendors once the stocks drop below a vendor defined threshold. This will help the vendor to utilize their ground staffs for immediate refills and to have a continuous supply to the user with out machine running out of stocks. This continuous supply of service will maximize the vendor’s revenue while keeping the user satisfaction at highest.Furthermore, our system will provide logs of daily sales in the sense of each product as a daily email at the end of the day and as a log file. Once enough data has been collected, this data can be used to data analysis to maximize sales and revenue while minimizing the logistic costs. As a starting step we provide the vendor with the weather update at the machine location since weather at the location heavily affect the sales of beverages and soft drinks.
As we progress and once enough data is collected, we can deploy a machine learning model on node red using Tensorflow.js. These predictions can be used to plan the refill routines and minimize the logistic costs.Our system can be easily integrated even with an existing vending machine with less effort and at a very low cost to give the comfort of using both conventional money and card payments to the customer. Or else vendor can completely replace the payment procedure to touchless.
Our system replaces the complex mechanism used in vending machine to identify and count the money notes and coins. This will heavily reduce the manufacturing cost of the vending machines.
Our system eliminates the risks and inconvenient vendor faces when using the conventional money such as robbing attacks on machines, attacks while emptying the money and collecting the money deposited in machines in a periodical routine.Furthermore, our system is scalable to any number of machines, and we can extend the system to different kinds of vending machines with very little modifications.

## Implementation
We have implemented our system while constraining to the given framework as shown in the figure 1.

We have used Node-Red to handle our dashboard. In our dashboard under settings, the vendor can define the machine capacity, machine location and the threshold limit for the email alerts. This input data will be used in the flow. We retrieve data as a JSON through the mqtt node in node red by subscribing the relevant topic. Then this JSON is converted to a JavaScript object. This contains data about current stocks of each product and refilling.The retrieved data then used to show the stocks values on the dashboard and to update the sales. Also, last refilling time will be displayed on the dashboard. Sales stats for the past 24 hours for each product can be seen in the
dashboard as well. The stocks are then compared with vendor defined alert threshold, if stocks are below the threshold the system will send an email alert to the vendor while pushing an alert to the dashboard as well. We have deliberately limited alerts to one email per 6 hours to eliminate spamming the email, but this time gap is adjustable according to the preference of the vendor. We have used OpenWeather API to get weather updates at the machine’s location. At the end of the day, our system will update the sales log file and email the vendor with a summary of the daily sales at each machine. The figure 2 shows the node red flow for a machine. This node red flow can be hosted locally or using IBM cloud node red instances.
NodeMCU will connect to the Gateway/Router and stablish webserver on its IP address. Webserver is based on HTTP and created using CSS, JavaScript, and HTML. After connecting to the same LAN with NodeMCU, user can use his/her device as a client. The home page of the web server contains buttons for beverage/food/items anda button for ground staff of the vending company for service purposes such as refill. On click of every button specific JavaScript function will run and inform the user’s action. If user selected any beverage/food, it would run a specified Cpp function that initiate a scan for RFID, and then get details of card. Once the process is success,it will redirect for another page only demonstrate the transaction in our implementation. After Transaction is completed NodeMCU will publish the order details as a JSON to the MQTT broker. Afterward using GPIOs we can control actuators to complete the user’s order. On a click of the vendor’s button NodeMCU scans the RFID and check the ID with pre-defined set of ID(s). If it matches correctly then the user will redirect to Service Page, otherwise directed to rejected notice page. In service page ground staff can proceed to refill the machine. Then it will publish the refilled notice to the MQTT broker.

## System Functionality Achieved
For the user’s side we have achieved the contactless product selection and payment at the machine. Once the QR is scanned he/she can select the product at the web page. Then user can make the payment through the RFID enabled card (figure 4, 5, 6).

he ground staff can update the refill at the machine by logging to the web page as usual. This process will be authorized only by especially issued RFID token. If the token is not authorized, it will be rejected (figure 7, 8).

Our system dashboard displays current stocks for each product, sales stats for each product for past 24 hours, last refill time and the weather at the location and brief description as shown in figure 9.

Vendor can customize the location, capacity and alert threshold for each machine at the settings tab (figure 10).

Once a stock value drops below the vendor defined threshold, system will put an alert email to the vendor (figure 12) and push an alert to the dashboard as well (figure 11).

At the end of the day, we will log the current sales for the day for each product in each machine (figure 13) and send an email update to the vendor (figure 14).
