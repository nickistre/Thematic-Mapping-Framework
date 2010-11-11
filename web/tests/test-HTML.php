<?php
require_once '../lib/class/HTML.inc';

$html = new HTML("Testing Page");

$html->add_script_links("../lib/js/jquery.js");
//$html->add_script_links("../lib/js/raphael-min.js", "../lib/js/cartographer.min.0.4.js");

$html->add("<h1>Header 1</h1>");
$html->add("<p>Testing the HTML class.</p>");