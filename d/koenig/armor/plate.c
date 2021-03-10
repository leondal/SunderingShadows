inherit "/std/armour";

void create() {
    	::create();
    	set_name("plate");
    	set_id( ({ "plate","armor", "plate mail","mail" }) );
    	set_short("a suit of plate mail armor");
    	set_long("This armor is a combination of chain or brigadine with metal "+
		"plates covering the vital areas. The weight is distributed over "+
		"the whole body and the whole thing is held together by buckles "+
		"and straps. This is the most common from of heavy armor."
       );
    	set_weight(50);
    	set("value", 600);
    	set_type("armour");
    	set_limbs( ({ "torso" }) );
    	set_ac(7);
}
