inherit "/std/armour";

void create() {
    ::create();
    set_name("ring");
    set_id(({ "ring" }));
    set_short("plain ring");
    set_long("This is a plain, undecorated ring.  It's probably not worth much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs( ({ "right hand","left hand" }) );
    set_ac(0);
}
