#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit DINOS;

void create(){
    ::create();
    set_property("no stab", 1);
    set_property("meat eater", 1);
    set_name("tyrannosaurus");
    set_short("Tyrannosaurus");
    set_id( ({"dino", "dinosaur", "tyrano", "tyrannosaurus", "rex"}) );
    set_long(
      "This gigantic two legged monstrosity grins at you with its mouth full of gigantic teeth, before it dives at you trying to grab and rip you with its forearms to eat alive with its gigantic mouth."
    );
    set_size(3);
    set_hd(35+random(5), 1);
    set_attack_bonus(5);
    set("aggressive", 22);
    set_overall_ac(-3);
    set_max_hp(250 + (8*query_hd()));
    set_exp(query_hd()*1100);
    set_hp(query_max_hp());
    set_race("dinosaur");
    if(random(2)) set_gender("male");
      else set_gender("female");
    set_body_type("quadruped");
    add_limb("mouth", "mouth", 0, 0, 0);
    add_limb("tail", "tail", 0, 0, 0);
    set_attack_limbs( ({"mouth", "right forepaw", "left forepaw"}) );
    //set_hit_funcs( (["mouth":(:TO, "bite":)]) );
    set_base_damage_type("piercing");
    set_funcs( ({"tail","bite","bite"}) );
    set_func_chance(75);
    set_attacks_num(4);
    set_damage(3,8);
    set_moving(1);
    set_speed(9);
}

int bite(object targ){
    if(!objectp(targ)) return 1;
    if(random(3)) return random(10);

    if("daemon/saving_throw_d"->reflex_save(targ,-30)){
      tell_object(targ, "%^BOLD%^%^RED%^The great Tyrannosaurus snaps at you with its great jaws, ripping into your flesh with its teeth!");
      tell_room(ETO, "%^BOLD%^%^RED%^The Tyrannosaurus snaps at "+targ->query_cap_name()+" ripping into "+targ->query_possessive()+" flesh!", targ);
      return roll_dice(5,10);
    } else {
      tell_object(targ, "%^BOLD%^%^RED%^The Tyrannosaurus grabs you in its gigantic mouth and starts to chew you up!!!");
      tell_room(ETO, "%^BOLD%^%^RED%^The Tyrannosaurus is attempting to swallow "+targ->query_cap_name()+" alive!", targ);
      targ->set_paralyzed(5, "You are caught in the Tyrannosaurus' jaws!");
      call_out("next", 5, targ);
      set_attacks_num(0);
      return roll_dice(5,15);
    }
}

void next(object targ){
    if(!objectp(targ)){
      set_attacks_num(4);
      return;
    }

    if(!present(targ, ETO)){
      set_attacks_num(4);
      return;
    }
    
	
	if(!"daemon/saving_throw_d"->reflex_save(targ,-25,"reflex")){
		tell_object(targ, "The Tyrannosaurus continues to chew on you, thrashing his head from side to side!");
		tell_room(ETO, "%^BOLD%^%^RED%^The Tyrannosaurus continues to chew on "+targ->query_cap_name()+"!", targ);
		targ->do_damage("torso", roll_dice(2,12));
		targ->set_paralyzed(6, "You are caught in the Tyrannosaurus' jaws!");
		call_out("next", 6, targ);
	}
	else{
		tell_object(targ, "%^BOLD%^%^RED%^The Tyrannosaurus tosses you to the side, licking blood from its teeth!");
		tell_room(ETO, "%^BOLD%^%^RED%^The Tyrannosaurus tosses "+targ->query_cap_name()+" to the side, and licks blood from its teeth!", targ);
        set_attacks_num(4);
        return;
	}
}

void tail(object targ){
    object *inv;
    int i;

    tell_room(ETO, "%^BOLD%^The T-Rex whips his tail around at you!");
    inv = all_living(ETO);
    inv -= ({TO});
    for(i=0;i<sizeof(inv);i++){
	  if( inv[i]->query_true_invis()){
	    continue;
	  }
      if(random(3)){
      tell_object(inv[i], "%^BOLD%^%^RED%^The T-rex hits you with his tail!");
       inv[i]->do_damage("torso",roll_dice(7,10));
      } else {
        tell_object(inv[i], "%^BOLD%^%^RED%^The T-Rex's tail doesn't strike you with its full might, but still slams you to the ground.");
       inv[i]->do_damage("torso",roll_dice(4,10));
        inv[i]->set_paralyzed(random(20), "You're on the ground.");
      }
    }
    return 1;
}

int free_movement() { return 1; }
