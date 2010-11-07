<?php
require_once '../libs/class/HTML.inc';

$html = new HTML("Testing AJAX AMFPHP");

$html->add_script_links("../js/jquery.js", "../js/jquery.dataTables.min.js", "js/amfphp-datatables.js");

$html->add("<h1>Header 1</h1>");
$html->add("<p>Testing testing creating a table from data.</p>");
$html->add("<div id='table_div'/>");
