inherit "/std/armour";

void create() {
    	::create();
    	set_name("kobold's clothes");
    	set_id( ({ "clothes","clothing", "kobold clothes", "kobold's clothes" }) );
    	set_short("A Kobold's tattered clothes");
    	set_long(
@KAYLA
This is a set of tattered clothes once worn by a disgusting Kobold.
KAYLA
	);
    	set_weight(5);
    	set("value", 8);
    	set_cointype("silver");
    	set_type("body");
    	set_limbs( ({ "torso" }) );
    	set_ac(0);
}
