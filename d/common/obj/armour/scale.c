inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(5);
    set_armor_prof("medium");
    set_name("scale");
    set("id", ({ "scale","armor", "scale mail","mail" }) );
    set("short", "A suit of scale mail armor");
    set("long", 
	"This is a coat and leggings of leather covered with overlapping "
        "pieces of metal, much like the scales of a fish."
       );
    set_weight(16);
    set("value", 120);
    set_type("chain");
    set_limbs( ({ "torso" }) );
    //set_ac(4);
    set_ac(6);
}

int is_metal() { return 1; }
