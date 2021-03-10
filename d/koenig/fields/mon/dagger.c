inherit "/std/weapon";

create() {
    	::create();
   	set_id( ({ "dagger", "rusty dagger" }) );
   	set_name("dagger");
   	set_short("A rusty dagger");
    	set_long("An old dagger someone just threw out.\n");
   	set_weight(172);
   	set("value", 25);
   	set_wc(7);
   	set_ac(1);
   	set_type("knife");
    	set_wield("It's yucky, but it wields.");
}
