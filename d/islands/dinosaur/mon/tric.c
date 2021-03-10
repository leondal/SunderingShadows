#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_name("triceratops");
    set_property("plant eater", 1);
    set_short("Triceratops");
    set_id( ({"dino", "dinosaur", "tric", "tricera", "triceratops"}) );
    set_long(
      "This large plant eating dinosaur has its face covered with large bony plates, protecting its face, where the rest of the body is not armored.  Most remarkable about this dinosaur is the two three foot long horns on its forhead, and the shorter horn on its nose.  You don't want to get hit with those."
    );
    set_size(3);
    set_hd(15+random(5), 1);
    set_attack_bonus(7);
    set_overall_ac(-5);
    set_max_hp(200 + (8*query_hd()));
    set_exp(query_hd()*400);
    set_hp(query_max_hp());
    set_race("dinosaur");
    if(random(2)) set_gender("male");
      else set_gender("female");
    set("aggressive", 19);
    set_body_type("quadruped");
    add_limb("spiked tail", "spiked tail", 0, 0, 0);
    set_attack_limbs( ({"spiked tail", "right claw", "left claw"}) );
    set_base_damage_type("piercing");
    set_attacks_num(3);
    set_damage(2,8);
    set_funcs( ({"rush_spec"}) );
    set_func_chance(60);
    set_moving(1);
    set_speed(11);
}

int rush_spec(object targ){

    if(random(20)+1 < Thaco(0,targ,0)){
      tell_object(targ, "%^BOLD%^The Triceratops rushes at you, but you are able to step out of its way!");
      tell_room(ETO, "%^BOLD%^"+targ->query_cap_name()+" is able to step out of the way of the rush of the Triceratops!", targ);
    } else {
      tell_object(targ, "%^BOLD%^The Triceratops begins running at you with its head down!");
      tell_room(ETO, "%^BOLD%^The Triceratops rushes madly at "+targ->query_cap_name()+"!!", targ);
      call_out("rush_hit", 5, targ);
    }
    set_func_chance(0);
    return 0;
}

void rush_hit(object targ){

    if(!objectp(targ)) return;
    if(!present(targ, ETO)){
      tell_object(targ, "%^BOLD%^You have evaded the rush of the Triceratops!");
      tell_room(ETO, "%^BOLD%^"+targ->query_cap_name()+" has avoided the Triceratops's rush!", targ);
      return;
    }
    tell_object(targ, "%^BOLD%^The Triceratops slams into you!");
    tell_room(ETO, "%^BOLD%^The Triceratops slams into "+targ->query_cap_name()+"!", targ);
    targ->do_damage("torso", roll_dice(5,15));
    targ->set_paralyzed(6, "You have been stunned by the Triceratops's rush!");
}

int free_movement() { return 1; }
