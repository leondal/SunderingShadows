inherit "/d/common/obj/weapon/whip.c";

create() {
    	::create();
   	set_id(({ "drow whip","whip"}));
   	set_name("drow whip");
   	set_short("%^BOLD%^%^BLUE%^drow whip%^RESET%^");
   	set_long(
   		"%^BOLD%^%^BLUE%^"+
   		"This whip it made from strips of braided black leather.  Pieces of "+
   		"razor sharp obsidian and metal have been woven into the strips of "+
   		"leather near the end.  Against an armored opponent this whip would "+
   		"be laughable, but in skilled hands the exposed flesh could be stripped "+
   		"away with each crack of the whip.\n"+
		"%^RESET%^"
   	);
   	//set_weight(2);
   	//set_size(2);
   	set("value", 10);
   	set_cointype("gold");
   	//set_wc(1,4);
   	//set_large_wc(1,3);
   	//set_type("slashing");
   	//set_prof_type("whip");
   	//set_weapon_speed(8);
}
