$(document).ready(function() {
	getTestData('Test 1', 'abc', '123');
});

function getTestData(arg1, arg2, arg3) {
	$.ajax({
		url: '../amfphp 1.9/json.php/test.Test.return_test_data/' + arg1 + '/' + arg2 + '/' + arg3,
		dataType: 'json',
		//data: ,
		success: getTestDataHandler
	});
}

function getTestDataHandler(data) {
	alert("Data Loaded: " + data);
}