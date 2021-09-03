//non-metal medium armor to give low-level druids an option
//~Circe~ 3/22/13

#include <std.h>

inherit ARMOUR;

void create(){
    ::create();
    set_max_dex_bonus(5);
    set_armor_prof("medium");
    set_name("wooden armor");
    set_id(({ "armor", "wooden armor", "wood", "wood armor", "scale", "wooden scale", "wooden scale armor"}) );
    set_short("A suit of wooden scale armor");
    set_long("Crafted to mimic the scales of a snake, this armor "
       "is made of small, overlapping wooden pieces attached to "
       "seasoned leather.  The suit consists of a shirt and a "
       "separate pair of pants, covering most of the wearer's body.  "
       "The leather has been well-crafted and well-oiled to allow "
       "for a wide range of movement while still offering a decent "
       "amount of protection."); 
    set_weight(30);
    set_value(75);
    set_type("leather");
    set_limbs( ({ "torso" }) );
    //set_ac(5);
    set_ac(7);
}

int is_metal() { return 0; }