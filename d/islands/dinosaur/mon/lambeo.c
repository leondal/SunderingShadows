#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_name("lambeosaurus");
    set_property("plant eater", 1);
    set_short("Lambeosaurus");
    set_id( ({"dino", "dinosaur", "lambeo", "lamb", "lambeosaurus"}) );
    set_long(
      "This medium sized duck billed dinosaur wanders aimlessly in its herd, eating plants.  It seems to be rather calm and weak, not a danger in any way."
    );
    set_size(2);
    set_hd(8+random(5), 0);
    set_attack_bonus(random(10));
    set_overall_ac(-1);
    set_max_hp(100 + (8*query_hd()));
    set_hp(query_max_hp());
    set_exp(query_hd()*100);
    set_race("dinosaur");
    if(random(2)) set_gender("male");
      else set_gender("female");
    set("aggressive", 4);
    set_body_type("quadruped");
    add_limb("mouth", "mouth", 0, 0, 0);
    add_limb("tail", "tail", 0, 0, 0);
    set_attack_limbs( ({"mouth", "right forepaw", "left forepaw"}) );
    set_base_damage_type("bludgeoning");
    set_attacks_num(1);
    set_damage(2,6);
    set_moving(1);
    set_speed(13);
}

int free_movement() { return 1; }
