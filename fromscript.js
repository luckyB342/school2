function formconfirm() {
    alert("Please confirm that you want to submit form!");
}

function messageValidation() {
    var inpObj = document.querySelector("#contact-subject");
    if (!inpObj.checkValidity()) {
      document.querySelector("#validationStatus").innerHTML = inpObj.validationMessage;
    }
    else {
      document.querySelector("#validationStatus").innerHTML = "Met Validaion specification";
    }
  }

function validateForm() {
    var x = document.forms["myForm"]["lastname"].value;
    if (x == "") {
      window.alert("Name must be filled out");
      return false;
    }

}
function formWriteupHeading() {
    var heading = document.getElementById('formH').innerHTML;
    heading = "<h1>FORM SUCCESSFULLY SUBMITED </h1>";
}

// function formWriteupSubheading() {
//     var subheading = document.getElementById('formSh').innerHTML;
//     subheading = "The following data is what we recieved from you; </br>";
// }

function firstNameData() {
    let ftname = document.querySelector('#contact-firstname', '#formSh').value;

      document.querySelector("#fstname").innerHTML = "<h1> First Name:  </h1>" + ftname;
}

function lastNameData() {
    let ltname = document.querySelector('#contact-lastname').value;
      document.querySelector("#lstname").innerHTML = "<h1> Last Name:  </h1>" + ltname;
}

function countryData() {
    let cuntry = document.querySelector('#contact-country').value;
      document.querySelector("#input-country").innerHTML = "<h1> Country:  </h1>" + cuntry;
}

function messageData() {
    let message = document.querySelector('#contact-subject').value;
      document.querySelector("#input-subject").innerHTML = "<h1> Message:  </h1>" + message;
}

function formData() {
    let userInput = formWriteupHeading() + firstNameData() + lastNameData() + countryData() + messageData();
}