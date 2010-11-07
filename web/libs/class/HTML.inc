<?php
class HTML {
	
	
	/**
	 * Title of the page
	 * @var string
	 */
	public $page_title;
	
	/**
	 * Array of strings of the current buffer.
	 * @var array
	 */
	private $buffer;
	
	/**
	 * Current position of the buffer pointer; which array will output next.
	 * @var int
	 */
	private $buffer_pos = 0;
	
	/**
	 * Array of strings for the header.
	 * @var array
	 */
	private $buffer_header;
	
	/**
	 * Flag for whenever the header is shown
	 * @var boolean
	 */
	protected $header_shown = false;
	
	/**
	 * Returns header_shown flag
	 * @return boolean
	 */
	public function is_header_shown() {
		return $this->header_shown;
	}
	
	/**
	 * Flag to mark whenever the footer was shown.
	 * @var boolean
	 */
	protected $footer_shown = false;
	
	/**
	 * Returns footer_shown flag
	 * @return boolean
	 */
	public function is_footer_shown() {
		return $this->footer_shown;
	}
	
	/**
	 * Sets the onload event for the body.  Keep null for no event handler.
	 * @var string
	 */
	private $onload = null;
	
	/**
	 * Constructor for class. 
	 * @param string $page_title
	 */
	function __construct($page_title = "") {
		$this->page_title = $page_title;
		$this->buffer = array();
		$this->buffer_pos = 0;
		$this->buffer_header = array();
		$this->header_shown = false;
		$this->footer_shown = false;
		$this->onload = null;
		
	}
	
	function __destruct() {
		if (!$this->is_footer_shown()) {
			$this->output_all();
		}
	}
	
	/**
	 * Sets the onload event for the document body.  Nothing will happen if this is
	 * called after the header is generated.
	 * @param unknown_type $script
	 */
	public function set_onload($script) {
		$this->onload = $script;
	}
	
	protected function gen_header($title = null) {
		if (is_null($title)) {
			$title = $this->page_title;
		}
		if (!$this->is_header_shown()) {
			
			if (!is_null($this->onload)) {
				$set_onload = " onload='{$this->onload}'";
			}
			else {
				$set_onload = "";
			}
		
			print "
<!DOCTYPE html>
<html>
<head>
<title>{$title}</title>
";
			
			print implode("\n", $this->buffer_header);
			
			print "
</head>
<body{$set_onload}>
";
			$this->header_shown = true;
		}
	}
	
	protected function gen_footer() {
		if (!$this->is_footer_shown()) {		
			print "
</body>
</html>
";
			$this->footer_shown = true;
		}
	}
	
	/**
	 * Addes one or more lines to the buffer.
	 * @param string $value1
	 * @param string $values...
	 */
	public function add( $value1 ) {
		$args_list = func_get_args();
		
		$this->buffer = array_merge($this->buffer, $args_list);
	}
	
	public function add_header( $value1 ) {
		if ($this->is_header_shown()) {
			// header already outputted, can't add any more data into it.
		}
		$args_list = func_get_args();
		
		$this->buffer_header = array_merge($this->buffer_header, $args_list);
		
	}
	
	/**
	 * Outputs some number of lines from the buffer.
	 * @param int $num_buffer_lines Number of lines to output.  If set to null, outputs all lines in the buffer.
	 */
	public function output($num_buffer_lines = null) {
		$buffer_count = count($this->buffer);
		if (is_null($num_buffer_lines)) {
			$num_buffer_lines = $buffer_count - $this->buffer_pos;
		}
		
		$number_shown = 0;
		
		while ($this->buffer_pos <= $buffer_count && $number_shown < $num_buffer_lines) {
			if ($this->buffer_pos == 0) {
				// First line, need to output header info first.
				$this->gen_header();
			}
			
			print $this->buffer[$this->buffer_pos] . "\n";
			$this->buffer_pos++;
			$number_shown++;
		}
	}
	
	/**
	 * Outputs all lines fromt he buffer with the footer.
	 */
	public function output_all() {
		$this->output();
		
		$this->gen_footer();
	}
	
	public function add_script_links($script1_url) {
		$args_list = func_get_args();
		
		// Combine everything into one large array.
		$script_list = array();
		foreach ($args_list as $arg) {
			if (!is_array($arg)) {
				$arg = array($arg);
			}
			$script_list = array_merge($script_list, $arg);
		}

		
		if ($this->is_header_shown()) {
			$func_callback = array($this, 'add');
		}
		else {
			$func_callback = array($this, 'add_header');
		}
		
		foreach ($script_list as $script_url) {
			$script_line = "<script type=\"text/javascript\" src=\"" . $script_url . "\"></script>";
			call_user_func($func_callback, $script_line);
		}
		
	}
}



