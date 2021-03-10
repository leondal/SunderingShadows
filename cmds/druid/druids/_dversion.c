// Pator@ShadowGate
// May 9 1996
// dver.c ==> Give the dversion of the Druidic Mistletoe

int cmd_dversion();

int cmd_dversion() {
	string vrs,tmp;
	if (!present("mistletoe",this_player()))
		{ notify_fail("You have No mistletoe !!\n");
		  return 0; }
	else {
	  vrs = present("mistletoe",this_player())->query_dversion();
	  tmp = "The dversion of your mistletoe is : \n";
	  tmp += vrs+"\n";
      tell_player(this_player(),tmp);
        return 1; } }
	  
