inherit "/std/armour";

void create() {
    ::create();
    set_name("robe");
    set("id", ({ "robe","cloak", "armor" }) );
    set("short", "A mage robe");
    set("long", 
"%^BOLD%^%^WHITE%^This is mage's robe. It sparkles and shines with magic and protects the wearer from damage in combat.%^RESET%^",
       );
    set_weight(10);
    set("value", 500);
    set_type("clothing");
    set_limbs( ({ "torso" }) );
    set_ac(1);
}
