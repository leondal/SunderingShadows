inherit "/std/armour";

void create() {
    ::create();
    set_max_dex_bonus(4);
    set_armor_prof("medium");
    set_name("brigadine");
    set("id", ({ "brigandine", "armor", "brigandine armor" }) );
    set("short", "A suit of brigandine armor");
    set("long", 
             "This armor is made from small metal plates, sewn or "
             "riveted to a layer of canvas or leather and protected "
             "by an outer layer of cloth. It is rather stiff and does "
             "not provide adequate protection to the joints, where the "
             "metal plates must be wide spaced, or left off."   
       );
    set_weight(32);
    set("value", 120);
    set_type("armour");
    set_limbs( ({ "torso" }) );
    //set_ac(6);
    set_ac(8);
}

int is_metal() { return 1; }
