inherit "/std/plate";

void create() {
    ::create();
    set_max_dex_bonus(3);
    set_armor_prof("heavy");
    set_name("plate");
    set("id", ({ "plate","armor", "plate mail","mail" }) );
    set("short", "A suit of plate mail armor");
    set("long", 
	"This armor is a combination of chain or brigadine with metal " 
      "plates covering the vital areas. The weight is distributed over "
	"the whole body and the whole thing is held together by buckles "
     "and straps. This is the most common form of heavy armor."
       );
    set_weight(28);
    set("value", 600);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(7);
    set_ac(9);
}

int is_metal() { return 1; }
