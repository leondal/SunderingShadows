inherit "/std/armour";

void create() {
    ::create();
    set_name("leather");
    set("id", ({ "leather", "armor", "leather armor" }) );
    set("short", "A suit of leather armor");
    set("long", "A suit of leather armor.");
    set_weight(175);
    set("value", 295);
    set_type("body");
    set_limbs( ({ "torso" }) );
    set_ac(3);
}
