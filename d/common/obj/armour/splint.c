inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(4);
    set_armor_prof("medium");
    set_name("splint");
    set("id", ({ "splint","armor", "splint mail","mail" }) );
    set("short", "A suit of splint mail armor");
    set("long", 
	"This armor is made of narrow verticle strips, riveted to a " 
	"backing of leather and cloth padding. The joints are protected "
	"by chainmail."
       );
    set_weight(32);
    set("value", 80);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(6);
    set_ac(8);
}

int is_metal() { return 1; }
