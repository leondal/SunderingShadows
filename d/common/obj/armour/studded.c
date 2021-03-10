inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(7);
    set_armor_prof("light");
    set_name("studded");
    set("id", ({ "studded","armor", "studded armor" }) );
    set("short", "A suit of studded leather armor");
    set("long", 
     "This armor is made from leather (not hardened like regular "
	"leather armor) reinforced with close-set metal rivets. Similar "
      "to the brigandine armor, except the spacing is wider."
       );
    set_weight(12);
    set("value", 20);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(3);
}

int is_metal() { return 0; }
