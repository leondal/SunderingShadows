#include <std.h>
#include "/d/darkwood/yntala/mon/"
inherit WEAPONLESS;

void create (){
::create ();
   set_name("Rabid Squirrel");
   set_id(({"squirrel","rabid squirrel"}));
   set_short("%^RESET%^%^ORANGE%^An overly large squirrel%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^This is an overly large squirrel that looks to be quite"
" pissed off.  His dark, walnut-red fur"
" is matted in some places and fluffy in others.  His mouth constantly drips a clear fluid and his wild eyes"
" never cease to glance madly around.  His large buck teeth stick out over his lower lip and his razor sharp"
" claws look as though they could deliver quite a beating.%^RESET%^");
   set_race("squirrel");
   set_gender("male");
   set_body_type("quadruped");
   set_hd(8,1);
   set_overall_ac(-2);
   set_size(2);
   set_stats("intelligence",16);
   set_stats("strength",19);
   set_stats("wisdom",13);
   set_stats("dexterity",16);
   set_stats("constitution",12);
   set_stats("charisma",14);
   set_hp(random(100)+75);
   set_max_hp(query_hp());  
   set_exp(750);
   set_speed(25);
   set_alignment(9);
   set_damage(1,6);
   set_property("full attacks",1);
   set("aggressive",19);
   add_limb("left claws","left arm",0,0,0);
   add_limb("right claws","right arm",0,0,0);
   add_limb("teeth","mouth",0,0,0);
   set_attack_limbs(({"left claws","right claws","teeth"}));
   set_base_damage_type("slashing");
   set_func_chance(10);
   set_funcs(({"bite"}));
   set_achats(2, ({"The squirrel makes several clicking noise with its teeth as its tail twitches irritably!","%^RESET%^%^ORANGE%^The squirrel bares its teeth at you and makes chattering noises!"}) );
}
void bite(object target) {
   if(!"daemon/saving_d"->saving_throw(target,"paralyzation_poison_death")) {
   tell_room(ETO,"%^RESET%^%^ORANGE%^%^The squirrel lunges at "+target->query_cap_name()+"'s head and wrapping his claws around it, he bites at it repeatedly!",target);
   tell_object(target, "%^RESET%^%^ORANGE%^The squirrel launches itself at your head and grabs on!  He bites at your head several times with his amazingly sharp teeth!");
   target->set_paralyzed(10,"You are still reeling in pain.");
   tell_room(ETO,"%^BOLD%^BITE!",target);
   tell_object(target,"%^BOLD%^BITE!");
   target->do_damage("torso",roll_dice(1,4));
   tell_room(ETO,"%^BOLD%^BITE!",target);
   tell_object(target,"%^BOLD%^BITE!");
   target->do_damage("torso",roll_dice(1,4));
   tell_room(ETO,"%^BOLD%^BITE!",target);
   tell_object(target,"%^BOLD%^BITE!");
   target->do_damage("torso",roll_dice(1,4));
   tell_room(ETO,"%^BOLD%^BITE!",target);
   tell_object(target,"%^BOLD%^BITE!");
   target->do_damage("torso",roll_dice(1,4));
   return 1;
   } 
   tell_room(ETO,"%^BOLD%^%^BLACK%^"+target->query_cap_name()+" dives out of the way just as the squirrel launches itself at "+target->query_objective()+" !%^RESET%^",target);
   tell_object(target, "%^BOLD%^%^BLACK%^You dive out of the way as the squirrel launches itself at you!");
   return 1;
}


