inherit "/std/armour";

void create() {
    	::create();
    	set_name("leather");
    	set_id( ({ "leather","leather armor", "armor" }) );
    	set_short("a suit of leather armor");
    	set_long("This armor is made of leather, hardened in boiling oil and then "+
		"shaped into breastplate and shoulder protectors. The rest of the "+
		"suit is made of softer, more flexable materials."
    	);
    	set_weight(15);
    	set("value", 5);
    	set_type("leather");
    	set_limbs( ({ "torso" }) );
    	set_ac(2);
}
