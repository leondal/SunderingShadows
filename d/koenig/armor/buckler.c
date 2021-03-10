inherit "/std/armour";

void create() {
    	::create();
    	set_name("buckler");
    	set_id(({ "shield","buckler shield", "buckler" }));
    	set_short("a buckler shield");
    	set_long("This shield is made of leather, hardened in boiling oil and then "+
		"shaped into an oval shield."
    	);
    	set_weight(3);
    	set("value", 1);
    	set_type("shield");
    	set_limbs( ({ "right hand","left hand" }) );
    	set_ac(1);
}
