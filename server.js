/*
    Justin De Guzman
     Date created : 26 July 2019
    Date modified : 30 August 2019
               by : Justin De Guzman

    Description:
    This js file is the Node service for exercise 1.
    
    ssh -i "jdg-ins1.pem" ubuntu@ec2-34-238-115-130.compute-1.amazonaws.com
    cd to directory and run server.js
    go to http://ec2-54-175-207-138.compute-1.amazonaws.com:3000/ (or whatever IPv4)
*/

const firebase = require('firebase');
const express = require('express');
// const request = require('request');
const app = express();
var bodyParser = require('body-parser');
app.use(bodyParser.json());

// Your web app's Firebase configuration
var firebaseConfig = {
  apiKey: "AIzaSyB1MdwLm26GIRpI8QzcGx72CVaxs0BIuNw",
  authDomain: "jpmc-exercisedb.firebaseapp.com",
  databaseURL: "https://jpmc-exercisedb.firebaseio.com",
  projectId: "jpmc-exercisedb",
  storageBucket: "jpmc-exercisedb.appspot.com",
  messagingSenderId: "297160890842",
  appId: "1:297160890842:web:fb8c932b1d0edd6d"
};

// Initialize Firebase
firebase.initializeApp(firebaseConfig);

app.get('/', (req, res) => {
  res.send("hello there :)");
});

app.get('/Customers', (req, res) => {
  console.log("HTTP Get!");

  let uName = req.body.name;
  let uAddress = req.body.address;

  let uPhone = req.body.phoneNumber;

	let referencePath = '/Customers';
  let userReference = firebase.database().ref(referencePath);

  console.log("Reference: " + userReference);

  userReference.on("value", 
    function(snapshot) {
      // console.log(snapshot.val());
      res.json(snapshot.val());
      userReference.off("value");
      },
    function (errorObject) {
      console.log("The read failed: " + errorObject.code);
      res.send("The read failed: " + errorObject.code);
    }
  );
});

app.post('/Customers', (req, res) => { // post
  console.log("POST!!!");

  let uName = req.body.name;
  let uAddress = req.body.address;
  let uPhone = req.body.phoneNumber;

  // error check for existing "ID"
	// let referencePath = '/Customers/1929'; // add ID to path; this makes a new object (1929) under /Customers
	let referencePath = '/Customers/'; // add ID to path
  let userReference = firebase.database().ref(referencePath);

  console.log("UNAME: " + req.body.name);

  userReference.update ({"name": uName, "address": uAddress, "phoneNumber": uPhone}, 
    function (error) {
      if (error) {
        res.send("Data could not be updated." + error);
      }
      else {
        res.send("Data updated successfully.");
      }
    }
  );
});

app.listen(3000, () => console.log('Server running on port 3000'));