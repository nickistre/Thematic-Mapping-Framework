<?php
class HTML {
	
	
	/**
	 * Title of the page
	 * @var string
	 */
	public $page_title;
	
	function __construct() {
		
	}
	
	
	
	protected function gen_header($title = null) {
		if (is_null($title)) {
			$title = $this->page_title;
		}
		
		return "
<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">
<html>
<head>
<meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">
<title>{$title}</title>
</head>
<body>";
	}
	
	protected function gen_footer() {
		return "
</body>
</html>
";
	}
}



