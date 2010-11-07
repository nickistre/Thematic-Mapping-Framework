<?php
class Test {
	
	public function return_test_data($val1, $val2 = null, $val3 = null) {
		$test_data = array (
			array (
				"region" => "US-CA",
				"val" => "10",
				"label" => $val1,
			),
			array (
				"region" => "US-OR",
				"val" => "15",
				"label" => $val2,
			),
			array(
				"region" => "US-WA",
				"val" => "20",
				"label" => $val3,
			),
		);
		
		return $test_data;
	}
}