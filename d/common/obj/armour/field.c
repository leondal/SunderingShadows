inherit "/std/plate";

void create() {
    ::create();
    set_max_dex_bonus(3);
    set_armor_prof("heavy");
    set_name("plate");
    set("id", ({ "field", "armor", "field plate","plate" }) );
      set("short", "A suit of Field Plate armor");
    set("long", 
	"This is the most common version of full plate armor, consisting "
	"of shaped and fitted metal plates rivited and interlocked to cover "
	"the entire body. It includes gauntlets, boots and a visored helm. "
	"A thick layer of padding must be worn underneath. However, the "
	"weight of the suit is well distributed over the whole body. Such "
	"armor hampers movement only slightly."
       );
    set_weight(32);
    set("value", 1500);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(8);
    set_ac(10);
}

int is_metal() { return 1; }
