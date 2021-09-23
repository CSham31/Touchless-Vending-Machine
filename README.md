# Touchless-Vending-Machine
Smart IoT System for Vending Machine Monitoring


##System Overview and Operations
Regular use of vending machines has two features that require physical contact with the machine.
*Selecting the required food or beverage item.
*The payment process involving conventional notes and coins
We insert a QR code on the vending machine surface. Once the QR is scanned by a user, he/she will be directed
to a webpage that allows him/her to select the food or beverage item. After the selecting required item user will
redirect to the payment process. We have selected to RFID which is the most used and easiest payment method
available nowadays to make payment process touchless. So, the user can make the payment using their bank
credit/debit card or specific RFID card issued by vending company. Through that we provide users a contactless
way to carry out their purchases in the times of a pandemic.
For the Vendor’s side, we enable the power of IoT by,
*Providing a Dashboard which shows the current sales amount, availability of stocks for each product in
the machine etc.
*Email alerts when a stock drops below a certain threshold defined by the vendor
*Daily sales data logs for further business analysis
The dashboard will show the current number of stocks available in the machine and how the daily sales have
carried out for each machine. The data about availability of stocks will help the manager to plan the logistics and
to minimize the costs. Also, our system will provide on dashboard alerts as well as Email alerts to the vendors
once the stocks drop below a vendor defined threshold. This will help the vendor to utilize their ground staffs for
immediate refills and to have a continuous supply to the user with out machine running out of stocks. This
continuous supply of service will maximize the vendor’s revenue while keeping the user satisfaction at highest.
Furthermore, our system will provide logs of daily sales in the sense of each product as a daily email at the end
of the day and as a log file. Once enough data has been collected, this data can be used to data analysis to maximize
sales and revenue while minimizing the logistic costs. As a starting step we provide the vendor with the weather
update at the machine location since weather at the location heavily affect the sales of beverages and soft drinks.
As we progress and once enough data is collected, we can deploy a machine learning model on node red using
Tensorflow.js. These predictions can be used to plan the refill routines and minimize the logistic costs.Our system can be easily integrated even with an existing vending machine with less effort and at a very low cost
to give the comfort of using both conventional money and card payments to the customer. Or else vendor can
completely replace the payment procedure to touchless.
Our system replaces the complex mechanism used in vending machine to identify and count the money notes and
coins. This will heavily reduce the manufacturing cost of the vending machines.
Our system eliminates the risks and inconvenient vendor faces when using the conventional money such as
robbing attacks on machines, attacks while emptying the money and collecting the money deposited in machines
in a periodical routine.
Furthermore, our system is scalable to any number of machines, and we can extend the system to different kinds
of vending machines with very little modifications.
