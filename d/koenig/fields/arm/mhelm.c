inherit "/std/armour";

void create() {
    	::create();
    	set_name("helmet");
    	set_id( ({ "helm","helmet", "armor", "hat" }) );
    	set_short("A stout helm");
    	set_long(
@KAYLA
This is a smallish rounded helm, made of remarkably strong material.
KAYLA
	);
    	set_weight(15);
    	set("value", 5);
    	set_type("helmet");
    	set_limbs( ({ "head" }) );
    	set_ac(1);
    	set_property("enchantment",1);
}
