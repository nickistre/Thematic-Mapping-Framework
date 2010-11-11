$(document).ready(function() {
	initialize();
});

var map;
var cartographer;

function initialize() {
	  if( GBrowserIsCompatible() ) {
		    map = new GMap2(document.getElementById("map"));
		    map.enableScrollWheelZoom();
		    map.setCenter(new GLatLng(18, 0), 2);
		    map.addControl(new GLargeMapControl());
		    map.addControl(new GHierarchicalMapTypeControl());
		    map.setMapType(G_PHYSICAL_MAP);
		    
		    var options = { };
		    cartographer = new Cartographer( map, options );
		    
		    getTestData("Test 1", "TEst 2", "blah");
	  }
}
		    
		    
		    
function getTestData(arg1, arg2, arg3) {
	$.ajax({
		url: '../amfphp/json.php/test.Test.return_test_data/' + arg1 + '/' + arg2 + '/' + arg3,
		dataType: 'json',
		//data: ,
		success: getTestDataHandler
	});
}

function getTestDataHandler(data) {
 
	// here we specify a custom color scheme
	var options = { colorScheme:"Spectral" };
	 
	cartographer.choropleth( data, options );
}