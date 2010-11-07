$(document).ready(function() {
	getTestData();
})

function getTestData() {
	$.ajax({
		url: '../amfphp 1.9/json.php/test.test.return_test_data/',
		dataType: 'json',
		//data: null,
		success: getTestDataHandler
	})
}

function getTestDataHandler(data) {
	alert("Data Loaded: " + data);
}