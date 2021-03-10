inherit "/std/armour";

void create() {
    ::create();
    set_name("necklace");
    set_id(({ "necklace" }));
    set_short("plain necklace");
    set_long("This is a plain, undecorated necklace.  It's probably not worth much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs( ({ "neck" }) );
    set_ac(0);
}
