inherit "/std/armour";

void create() {
    	::create();
    	set_name("helm");
    	set_id( ({ "helm", "chain", "coif", "helmet", "chain coif" }) );
    	set_short("a chain coif");
    	set_long("This is a decorative light chain coif worn to protect the "+
    		"head from slashing weapons.");
    	set_weight(10);
    	set("value", 30);
    	set_type("clothing");
    	set_limbs( ({ "head" }) );
    	set_ac(1);
}
