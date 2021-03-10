inherit "/std/armour";

void create() {
    	::create();
    	set_name("sshield");
    	set_id( ({ "shield","small shield", "small" }) );
    	set_short("a small shield.");
    	set_long("This shield is made of leather, hardened in boiling oil and then "+
		"shaped into an oval shield."
    	);
    	set_weight(5);
    	set("value", 3);
    	set_type("shield");
    	set_limbs( ({ "right hand","left hand" }) );
    	set_ac(1);
}
