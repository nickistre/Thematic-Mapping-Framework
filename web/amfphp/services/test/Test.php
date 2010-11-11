<?php
class Test {
	
	private $state_list = "AL,AK,AS,AZ,AR,CA,CO,CT,DE,DC,FM,FL,GA,GU,HI,ID,IL,IN,IA,KS,KY,LA,ME,MH,MD,MA,MI,MN,MS,MO,MT,NE,NV,NH,NJ,NM,NY,NC,ND,MP,OH,OK,OR,PW,PA,PR,RI,SC,SD,TN,TX,UT,VT,VI,VA,WA,WV,WI,WY";
	
	private function generate_test_data() {
		$state_array = explode(",", $this->state_list);
		
		$test_data_array = array();
		
		foreach ($state_array as $state_code) {
			$state_data[] = array(
				"region" => "US-{$state_code}",
				"val" => rand(0, 100),
				"label" => $state_code,
			);
		}
		
		return $state_data;
	}
	
	public function return_test_data($val1, $val2 = null, $val3 = null) {
		$test_data = $this->generate_test_data();
		
		return $test_data;
	}
	
	public function return_test_datatable_info($val1, $val2 = null, $val3 = null) {
		$test_data = $this->return_test_data($val1, $val2, $val3);
		
		$aaData = array();
		
		foreach ($test_data as $row) {
			$aaData[] = array($row["region"], $row["val"], $row["label"]);
		}
		
		$aoColumns = array(
			array( "sTitle" => "Region"),
			array( "sTitle" => "Value"),
			array( "sTitle" => "Label")
		);
		
		return array("aaData" => $aaData, "aoColumns" => $aoColumns);
	}
}