inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(4);
    set_armor_prof("medium");
    set_name("banded");
    set("id", ({ "banded", "armor", "banded armor" }) );
    set("short", "A suit of banded armor");
    set("long", 
	"This armor is made up of overlapping strips of metal "
	"sewn to a backing of leather and chainmail. Generally "
     "the strips cover only the vulnerable areas, while the "
	"chain and leather protect the joints, where freedom of "
	"movement must be assured. Through straps and buckles, "
     "the weight is more or less evenly distributed."
       );
    set_weight(32);
    set("value", 200);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(6);
    set_ac(8);
}

int is_metal() { return 1; }
