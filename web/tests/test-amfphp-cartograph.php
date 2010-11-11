<?php
require_once '../libs/class/HTML.inc';
require_once '../config/config.inc';

$config = new Config();

$google_map_api_key = $config->get("google_map_V2_api_key");

$html = new HTML("Testing Google Map API");

$html->add_script_links("../js/jquery.js");
$html->add_script_links("http://maps.google.com/maps?file=api&v=2.x&key={$google_map_api_key}");
$html->add_script_links("../js/raphael-min.js", "../js/cartographer.min.0.4.js");

$html->add_script_links("js/amfphp-cartograph.js");


$html->add_header('<style type="text/css">
  html { height: 100% }
  body { height: 100%; margin: 0px; padding: 0px }
  #map_canvas { height: 100% }
</style>
');

//$html->add("<h1>Header 1</h1>");
//$html->add("<p>Testing the HTML class.</p>");

$html->add('<div id="map" style="width: 100%; height: 100%"></div>');