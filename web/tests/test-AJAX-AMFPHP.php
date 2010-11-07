<?php
require_once '../libs/class/HTML.inc';

$html = new HTML("Testing AJAX AMFPHP");

$html->add_script_links("../js/jquery.js", "js/ajax-amfphp.js");

$html->add("<h1>Header 1</h1>");
$html->add("<p>Testing the HTML class.</p>");