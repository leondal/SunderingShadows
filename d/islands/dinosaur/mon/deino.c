#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_name("deinonychus");
    set_property("meat eater", 1);
    set_short("Deinonychus");
    set_id( ({"dino", "dinosaur", "deino", "deinonychus"}) );
    set_long(
      "The 6 foot tall dinosaur before you snarls at you.  A definate meat eater, its large teeth look ready to rip you apart as it grasps you in its long, but thin, forearms.  It also looks ready to rip you apart with the giant claws on its hind legs."
    );
    set_size(2);
    set_hd(10+random(5), 0);
    set_attack_bonus(random(3)+1);
    set_max_hp(50 + (8*query_hd()));
    set_hp(query_max_hp());
    set_race("dinosaur");
    set_exp(query_hd()*100);
    if(random(2)) set_gender("male");
      else set_gender("female");
    set_body_type("quadruped");
    add_limb("mouth", "mouth", 0,0,0);
    add_limb("tail", "tail", 0, 0, 0);
    set_alignment(5);
    set("aggressive", 20);
    set_overall_ac(-3);
    set("aggressive", 18);
    set_attack_limbs( ({"right forepaw", "left forepaw", "right rear paw", "left rear paw", "mouth"}) );
    set_attacks_num(2);
    set_base_damage_type("piercing");
    set_damage(1,6);
    set_funcs( ({"charge"}) );
    set_func_chance(15);
    set_hit_funcs( (["right forepaw":(:TO, "claw_rake":), "left forepaw":(:TO, "claw_rake":), "right rear paw":(:TO, "claw_rake":), "left rear paw":(:TO, "claw_rake":)]) );
    set_moving(1);
    set_speed(8);
}

int claw_rake(object targ){
    if(!objectp(targ)) return random(6);
    if(random(4)) return 1;

    switch(limb) {
      case "right forepaw":
      case "left forepaw":
        tell_object(targ, "%^GREEN%^%^BOLD%^The Deinonychus holds you with its front paws and begins to rake you with its rear legs!");
        tell_room(ETO, "%^GREEN%^%^BOLD%^The Deinoychus grabs ahold of "+targ->query_cap_name()+"!", targ);
        targ->set_paralyzed(5, "The dinosaur has you in its grasp!");
        break;
      case "left rear paw":
      case "right rear paw":
        tell_object(targ, "%^RED%^The Deinonychus rakes you violently with its rear clawed legs!");
        tell_room(ETO, "%^RED%^The Deinonychus rakes "+targ->query_cap_name()+" violently with its rear legs!", targ);
        return roll_dice(2,5);
    }
    return random(6);
}

int charge(object targ){
    tell_room(ETO, "%^BOLD%^Deinonychus rushes at "+targ->query_cap_name()+" with a shrill inhuman scream!", targ);
    tell_object(targ, "%^BOLD%^Deinonychus slams into you, raking you with its rear claws while screaming an inhuman scream!");
    targ->do_damage("torso", roll_dice(2,10));
    return 1;
}
int free_movement() { return 1; }
