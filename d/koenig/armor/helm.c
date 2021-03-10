inherit "/std/armour";

void create() {
    	::create();
    	set_name("helm");
    	set_id( ({ "helm", "helmet", "great helm" }) );
    	set_short("great helm");
    	set_long("This is a great helm.");
    	set_weight(10);
    	set("value", 30);
    	set_type("clothing");
    	set_limbs( ({ "head" }) );
    	set_ac(1);
    	set_remove("The helm slips off your head, easily.");
}