inherit "/d/common/obj/weapon/dagger.c";

create() {
   	::create();
   	set_id(({ "dagger","obsidian dagger" }));
   	set_name("dagger");
        set_short("%^BOLD%^%^BLUE%^obsidian dagger%^RESET%^");
   	set_long(
   		"%^BOLD%^%^BLUE%^"+
   		"The dagger is made from volcanic glass and looks razor sharp.  The "+
   		"blade was painstakingly chiseled to a sharp point with an edge you "+
   		"could shave with.  The handle is wrapped with leather strips so that "+
   		"it fits very comfortably in your hand.  Its small size and good point "+
   		"make it a perfect weapon for people who don't want to have to worry "+
   		"about space for carrying a larger weapon.\n"+
   		"%^RESET%^"
   );
   	set_weight(2);
   	set_size(1);
   	set("value", 10);
   	//set_wc(2,2);
   	//set_large_wc(1,4);
   	//set_type("piercing");
   	//set_weapon_speed(2);
}
