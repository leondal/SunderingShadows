inherit "/std/armour";

void create() {
    ::create();
    set_name("circlet");
    set_id(({ "circlet" }));
    set_short("plain circlet");
    set_long("This is a plain, undecorated circlet.  It's probably not worth much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs( ({ "head" }) );
    set_ac(0);
}
