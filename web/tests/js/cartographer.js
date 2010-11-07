$(document).ready(function() {
	initialize();
});

function initialize() {
	  if( GBrowserIsCompatible() ) {
		    var map = new GMap2(document.getElementById("map"));
		    map.enableScrollWheelZoom();
		    map.setCenter(new GLatLng(18, 0), 2);
		    map.addControl(new GLargeMapControl());
		    map.addControl(new GHierarchicalMapTypeControl());
		    map.setMapType(G_PHYSICAL_MAP)
		 
		    var countyNames = (new String("AITKIN,ANOKA,BECKER,BELTRAMI,BENTON,BIG-STONE,BLUE-EARTH,BROWN,CARLTON,CARVER,CASS,CHIPPEWA,CHISAGO,CLAY,CLEARWATER,COOK,COTTONWOOD,CROW-WING,DAKOTA,DODGE,DOUGLAS,FARIBAULT,FILLMORE,FREEBORN,GOODHUE,GRANT,HENNEPIN,HOUSTON,HUBBARD,ISANTI,ITASCA,JACKSON,KANABEC,KANDIYOHI,KITTSON,KOOCHICHING,LAC-QUI-PARLE,LAKE,LAKE-OF-THE-WOODS,LE-SUEUR,LINCOLN,LYON,MAHNOMEN,MARSHALL,MARTIN,MCLEOD,MEEKER,MILLE-LACS,MORRISON,MOWER,MURRAY,NICOLLET,NOBLES,NORMAN,OLMSTED,OTTER-TAIL,PENNINGTON,PINE,PIPESTONE,POLK,POPE,RAMSEY,RED-LAKE,REDWOOD,RENVILLE,RICE,ROCK,ROSEAU,SCOTT,SHERBURNE,SIBLEY,ST.-LOUIS,STEARNS,STEELE,STEVENS,SWIFT,TODD,TRAVERSE,WABASHA,WADENA,WASECA,WASHINGTON,WATONWAN,WILKIN,WINONA,WRIGHT,YELLOW-MEDICINE")).split(",");
		    var countyData = [];
		    for( var i=0, ii=countyNames.length; i<ii; i++ ) { 
		      var name = countyNames[i];
			 var code = "MN-" + name;
		      countyData.push( { region:code, val:name.charCodeAt(0), label: Cartographer.regions[code].name + " County, " + "MN" } ); 	
		    }
		 
		    var cartographer = Cartographer( map, { colorize:"#000", colorizeAlpha:.3 } );
		    cartographer.choropleth(countyData, { colorScheme:"YlOrRd"});
		  }
  }