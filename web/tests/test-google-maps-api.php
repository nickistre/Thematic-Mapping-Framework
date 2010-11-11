<?php
require_once '../lib/class/HTML.inc';

$html = new HTML("Testing Google Map API");

$html->add_script_links("../lib/js/jquery.js");
$html->add_script_links("http://maps.google.com/maps/api/js?sensor=false", "js/google-maps.js");

$html->add_header('<style type="text/css">
  html { height: 100% }
  body { height: 100%; margin: 0px; padding: 0px }
  #map_canvas { height: 100% }
</style>
');

//$html->add("<h1>Header 1</h1>");
//$html->add("<p>Testing the HTML class.</p>");

$html->add('<div id="map_canvas" style="width: 100%; height: 100%"></div>');