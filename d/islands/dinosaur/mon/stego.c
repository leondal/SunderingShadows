#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_name("stegosaurus");
    set_property("plant eater", 1);
    set_short("Stegosaurus");
    set_id( ({"dino", "dinosaur", "stego", "stegosaurus"}) );
    set_long(
      "This large and awe inspiring dinosaur is covered in huge bony plates along its entire body, except for its tail which has several huge spikes protruding from it.  The dinosaur silently munches on its plants as it regards you with one eye."
    );
    set_size(3);
    set_hd(15+random(10), 1);
    set_attack_bonus(7);
    set_overall_ac(-2);
    set_max_hp(225 + (8*query_hd()));
    set_exp(query_hd()*450);
    set_hp(query_max_hp());
    if(random(2)) set_gender("male");
      else set_gender("female");
    set_race("dinosaur");
    set_body_type("quadruped");
    set("aggressive", 13);
    add_limb("tail", "tail", 0, 0, 0);
    set_attack_limbs( ({"tail"}) );
    set_base_damage_type("piercing");
    set_attacks_num(2);
    set_damage(2,7);
    set_property("no stab", 1);
    set_hit_funcs( (["tail":(:TO, "tail_hit":)]) );
    set_stabbed_func( (:TO, "stabbed":) );
    set_moving(1);
    set_speed(18);
}

int tail_hit(object targ){
    if(!objectp(targ)) return random(10);
    if(random(6)) return 1;

    if("daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
      tell_object(targ, "%^BOLD%^%^BLUE%^The Stegosaurus grazes you with its spiked tail!");
      tell_room(ETO, "%^BOLD%^%^BLUE%^The stegosaurus grazes "+targ->query_cap_name()+"with its spiked tail!", targ);
      return roll_dice(3,5);
    } else {
      tell_object(targ, "%^BOLD%^%^BLUE%^The Stegosaurus impales you with its spiked tail!");
      tell_room(ETO, "%^BOLD%^%^BLUE%^The stegosaurus impales "+targ->query_cap_name()+"with its spiked tail!", targ);
      return roll_dice(6,5);
    }
}

int free_movement() { return 1; }

void stabbed(){
    if(!objectp(TP))
        return;
    tell_object(TP, "%^YELLOW%^To reach the Stegosaurus's back, you impale your arm upon several sharp spikes.");
    if(query_hp() < (query_max_hp()/2)) set_hp(query_max_hp()/2);
    TP->do_damage("torso", roll_dice(3,10));
}
