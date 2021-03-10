inherit "/std/armour";

void create() {
    	::create();
    	set_name("mshield");
    	set_id( ({ "shield","medium shield","medium" }) );
    	set_short("a body shield.");
    	set_long("This shield is made of leather, hardened in boiling oil and then "+
		"shaped into an oval shield."
     	);
    	set_weight(10);
    	set("value", 7);
    	set_type("shield");
    	set_limbs( ({ "right hand","left hand" }) );
    	set_ac(1);
}
