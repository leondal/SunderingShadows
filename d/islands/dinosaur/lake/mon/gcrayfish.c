#include <std.h>

inherit WEAPONLESS;
int pinch(object targ);

void create(){
    ::create();
    set_property("waterbreather", 1);
    set_property("no swim", 1);
    set_name("Giant Crayfish");
    set_id( ({"fish", "crayfish", "giant", "giant crayfish"}) );
    set_short("%^BOLD%^%^RED%^Giant Crayfish");
    set_long(
      "This monster is a giant crayfish, covered with a hard shell, long legs and pinchers reach out from below it, directed by two eyestalks to take you to your doom."
    );
    set_overall_ac(-4);
    set_body_type("quadruped");
    set_race("Giant Crayfish");
    set_gender("male");
    set_hd(29,5);
    set_hp(200+random(100));
    set_attacks_num(3);
    set_damage(3,6);
    add_limb("right claw", "torso", 0,0,0);
    add_limb("left claw", "torso", 0,0,0);
    set_attack_limbs( ({"right claw", "left claw"}) );
    set_funcs( ({"pinch"}) );
    set_func_chance(40);
    set_invis();
    set_exp(11000 + random(2500));
}

void init(){
    object *inv;
    ::init();
    if(wizardp(TP)) return;
    kill_ob(TP, 1);
    if(!query_invis()) return;
    if(random(2)) return;
    tell_room(ETO, "The Giant Crayfish rises from the muck on the floor to attack!");
    set_invis();
    return;
}

int pinch(object targ){
    if(random(20) < ((int)targ->query_stats("intelligence") - 4)){
      tell_room(ETO, "%^BOLD%^The crayfish tries to grab "+targ->query_cap_name()+" in its pinchers, but misses!%^RESET%^", targ);
      tell_object(targ, "%^BOLD%^The giant Crayfish tries to grab you in its pinchers, but you are able to avoid the attack!");
    } else {
      tell_room(ETO, "%^BOLD%^%^RED%^The Giant Crayfish grabs "+targ->query_cap_name()+" in its pinchers, and starts to cut "+targ->query_objective()+" in half!", targ);
      tell_object(targ, "%^BOLD%^%^RED%^The giant Crayfish grabs you in its pinchers, and starts to crush you!");
      targ->do_damage("torso", roll_dice(5,10));
      targ->set_paralyzed(10+random(10), "The crab has you at its mercy!");
    }
    return 1;
}
