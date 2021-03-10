#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_name("elasmosaurus");
    set_property("meat eater", 1);
    set_short("Elasmosaurus");
    set_id( ({"dino", "dinosaur", "elas", "elasmosaurus"}) );
    set_long(
      "This dinosaur looks much like a snake with much much larger teeth, and a large fin down its back.  About 50 feet long, it looks hungry, and it looks like its headed your way!"
    );
    set_size(3);
    set_hd(15+random(5), 0);
    set_attack_bonus(random(5)+1);
    set_max_hp(100 + (8*query_hd()));
    set_exp(query_hd()*250);
    set_hp(query_max_hp());
    set_race("dinosaur");
    set_overall_ac(0);
    set("aggressive", 25);
    if(random(2)) set_gender("male");
      else set_gender("female");
    set_body_type("snake");
    set_stats("strength", 19);
    set_attack_limbs( ({"mouth"}) );
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(3,4);
}
int free_movement() { return 1; }
