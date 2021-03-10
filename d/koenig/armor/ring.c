inherit "/std/armour";

void create() {
    	::create();
    	set_name("ringmail");
    	set_id( ({ "ring","armor", "ring mail","mail" }) );
    	set_short("a suit of ring mail armor");
    	set_long("This armor is an early, and less effective version, of chain mail "+
		"in which metal rings are sewn directly to leather backing, instead "+
		"of being interlaced. "
    	);
    	set_weight(30);
    	set("value", 100);
    	set_type("armour");
    	set_limbs( ({ "torso" }) );
    	set_ac(3);
}
