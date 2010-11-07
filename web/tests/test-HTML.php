<?php
require_once '../libs/class/HTML.inc';

$html = new HTML("Testing Page");

$html->add_script_links("../js/jquery.js");
//$html->add_script_links("../js/raphael-min.js", "../js/cartographer.min.0.4.js");

$html->add("<h1>Header 1</h1>");
$html->add("<p>Testing the HTML class.</p>");