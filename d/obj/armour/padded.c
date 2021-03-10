inherit "/std/armour";

void create() {
    ::create();
    set_name("padded");
    set("id", ({ "padded","padded armor", "armor" }) );
    set("short", "A suit of padded armor");
    set("long", 
	"This is the simplest type of armor, fashioned from quilted "
	"layers of cloth and batting. It tends to get hot, and after "
	"a time becomes foul with sweat,grime,lice and fleas."
       );
    set_weight(10);
    set("value", 4);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    set_ac(2);
}
