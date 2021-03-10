inherit "/std/armour";

void create() {
    	::create();
    	set_name("ring");
    	set_id( ({ "ring","armor", "protection","ring of protection", "prot ring" }) );
    	set_short("a small gold ring");
    	set_long("This is a tiny nondescript gold ring.  For some reason "+
    		"you feel more protected while wearing it."
    	);
    	set_weight(3);
    	set("value", 500);
    	set_type("clothing");
    	set_limbs( ({ "left hand", "right hand" }) );
//    	set_ac(1);
}
