$(document).ready(function() {
	getTestData('Test 1', 'abc', '123');
});

var aoColumns

function getTestData(arg1, arg2, arg3) {
	$.ajax({
		url: '../amfphp 1.9/json.php/test.Test.return_test_datatable_info/' + arg1 + '/' + arg2 + '/' + arg3,
		dataType: 'json',
		//data: ,
		success: getTestDataHandler
	});
}

function getTestDataHandler(data) {
	//alert("Data Loaded: " + data);
	
	$('#table_div').html('<table cellpadding="0" cellspacing="0" border="0" class="display" id="table_data"></table>' );
	$('#table_data').dataTable( data )
}