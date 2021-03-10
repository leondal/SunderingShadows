inherit "/std/armour";

void create() {
    ::create();
    set_name("banded");
    set("id", ({ "banded", "armor", "banded armor" }) );
    set("short", "A suit of banded armor");
    set("long", 
	"This armor is made up of overlapping strips of metal "
	"sewn to a backing of leather and chainmail. Generally "
	"the strips cover only the vunerable ares, while the "
	"chain and leather protect the joints, where freedom of "
	"movement must be assured. Through straps and buckles, "
	"the weight is more or less evenly distibuted."
       );
    set_weight(35);
    set("value", 200);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    set_ac(6);
}
