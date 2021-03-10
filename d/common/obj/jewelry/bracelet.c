inherit "/std/armour";

void create() {
    ::create();
    set_name("bracelet");
    set_id(({ "bracelet" }));
    set_short("plain bracelet");
    set_long("This is a plain, undecorated bracelet.  It's probably not worth much, but it seems well-made.");
    set_weight(2);
    set_value(5);
    set_type("ring");
    set_limbs(({"left arm", "right arm"}));
    set_ac(0);
}
