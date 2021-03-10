inherit "/std/armour";

void create() {
    ::create();
    set_name("studded");
    set("id", ({ "studded","armor", "studded armor" }) );
    set("short", "A suit of studded leather armor");
    set("long", 
      "This armor is made from leather (not hardened like regular "
      "leather armor) reinforced with close-set metal rivets. Similar "
      "to the brigadine armor, except the spacing is wider."
    );
    set_weight(25);
    set("value", 350);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(3);
   set_property("enchantment",3);
}
