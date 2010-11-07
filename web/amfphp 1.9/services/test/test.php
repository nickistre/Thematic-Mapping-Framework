<?php
class Test {
	
	public function return_test_data() {
		$test_data = array (
			array (
				"region" => "US-CA",
				"val" => "10",
			),
			array (
				"region" => "US-OR",
				"val" => "15",
			),
			array(
				"region" => "US-WA",
				"val" => "20"
			),
		);
		
		return $test_data;
	}
}