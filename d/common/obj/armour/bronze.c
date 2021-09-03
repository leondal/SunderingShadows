inherit "/std/plate";

void create() {
    ::create();
    set_max_dex_bonus(3);
    set_armor_prof("heavy");
    set_name("plate");
    set("id", ({ "bronze", "armor", "bronze plate mail","mail","plate" }) );
    set("short", "A suit of bronze plate mail");
    set("long", 
	"This is a plate mail armor - a combination of metal plates, "
	"chain mail or brigadine, leather and padding - made of softer "
	"bronze. It is easier and cheaper to make, but it does not "
	"protect as well. A large breastplate and other metal plates "
	"cover areas of the body, but other materials must protect " 
	"the joints and movable parts of the body."
       );
    set_weight(40);
    set("value", 400);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(7);
    set_ac(9);
}

int is_metal() { return 1; }