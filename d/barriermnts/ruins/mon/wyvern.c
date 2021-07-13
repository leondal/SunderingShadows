#include <std.h>
#include "../inherit/ruins.h"
inherit WEAPONLESS;

create() {
   ::create();
   set_name("frost wyvern");
   set_id(({ "wyvern","frost wyvern"}));
   set_short("%^WHITE%^%^BOLD%^frost wyvern%^RESET%^");
   set_long("%^WHITE%^%^BOLD%^This magnificent creature is quite a fearsome sight, despite that it must "
"still only be of a young age.  Intelligent eyes peer forth from its long, reptilian face.  A long neck "
"extends from its %^CYAN%^pale-scaled%^WHITE%^ body, along with two broad wings that are folded across "
"its back.  %^BLACK%^Razor-sharp%^WHITE%^ claws tap the floor where it stands, and its long "
"%^GREEN%^barbed%^WHITE%^ tail drips a strange black liquid that smokes as it hits the floor.%^RESET%^");
   set_race("wyvern");
   set_gender("male");
   set_body_type("dragon");
   set_alignment(8);
   set_size(3);
   set_exp(40000);
   add_limb("mouth","head",0,0,0);
   set_attack_limbs( ({"teeth","left foreclaw","right foreclaw"}) );
   set_attacks_num(4);
   set_base_damage_type("slashing");
   set_damage(2,8);
   set_hd(50,10);
   set_class("fighter");
   set_mlevel("fighter",40);
   set_guild_level("fighter",40);
   set_max_hp(random(100)+950);
   set_hp(query_max_hp());
   set_property("weapon resistance",1);
   //set_mob_magic_resistance("average");
   set_property("no animate",1);
   set_property("no death",1);
   set_property("no steal",1);
//   set_property("no hold", 1);
//   set_property("no paralyze", 1);
   set_property("no dominate", 1);
   set_property("no bows",1);
   set_overall_ac(-6);
   add_money("gold",6000+random(500));
   add_money("platinum",500+random(200));
   set_stats("intelligence",15);
   set_stats("wisdom",9);
   set_stats("strength",19);
   set_stats("charisma",8);
   set_stats("dexterity",16);
   set_stats("constitution",18);
   set_funcs(({"wing_fun","barb_fun","barb_fun","breath_fun","claws_fun","claws_fun","teeth_fun","teeth_fun"}));
   set_func_chance(15);
   set("aggressive","agg_fun");
   set_emotes(1, ({"%^BLACK%^%^BOLD%^The wyvern scratches its claws along the stone floor.",
"%^GREEN%^%^BOLD%^A drop of black liquid falls from the wyvern's barbed tail, hitting the floor with a "
"hiss.",
"%^WHITE%^%^BOLD%^The wyvern peers around with its sharp eyes, sizing up its surroundings.",
"%^CYAN%^%^BOLD%^The wyvern stretches its wings, showing their impressive span."}), 0);
   set_achats(2, ({"%^CYAN%^%^BOLD%^The wyvern hisses, and you can feel its icy breath!",
"%^GREEN%^%^BOLD%^The wyvern's tail wavers dangerously.",
"%^WHITE%^%^BOLD%^The wyvern snarls, its eyes glinting wickedly as it advances on you."}) );
}

int agg_fun() {
   force_me("emoteat "+TPQN+ " %^WHITE%^%^BOLD%^The $M's %^GREEN%^eyes%^WHITE%^ glint, as it snarls and "
"advances upon $N.");
   force_me("kill "+TP->query_name());
}

int wing_fun(object target) {
   tell_object(target,"%^WHITE%^%^BOLD%^The wyvern shifts with surprising speed, lashing out at you with "
"one wing!");
   tell_room(ETO,"%^WHITE%^%^BOLD%^The wyvern shifts with surprising speed, lashing out at "+target->QCN+ 
" with one wing!",target);
   if((random(10)+11) >= target->query_stats("dexterity")) {
     tell_object(target,"%^WHITE%^%^BOLD%^The wyvern's wing catches you and launches you back through the "
"air, into the corridor to the south!");
     tell_room(ETO,"%^WHITE%^%^BOLD%^The wyvern's wing knocks "+target->QCN+" flying backwards through "
"the air, into the darkened corridor to the south!",target);
     target->move(ROOMS+"b6-3");
     tell_object(target,"%^WHITE%^%^BOLD%^You hit the wall hard, knocking the breath from your lungs!");
     target->set_paralyzed(random(30) + 10,"You are trying to catch your breath!");
     TO->set_property("magic",1);
     target->do_damage("torso",random(10)+5);
     TO->remove_property("magic");
   }
   else {
     tell_object(target,"%^WHITE%^%^BOLD%^You manage to dodge at the last second, as the wyvern's wing "
"whistles past you through the air.");
     tell_room(ETO,"%^WHITE%^%^BOLD%^"+target->QCN+" manages to dodge the wyvern's attack at the last "
"second!",target);
   }
   return 1;
}

int breath_fun(object target) {
   object *pplz;
   int i,freeze;
   pplz = all_living(ETO);
   tell_room(ETO,"%^CYAN%^%^BOLD%^The wyvern rears back its head and draws in a hissing breath!");
   TO->set_property("magic",1);
   for(i=0;i<sizeof(pplz);i++) {
     if("daemon/saving_d"->saving_throw(pplz[i],"breath_weapon")) {
       tell_object(pplz[i],"%^CYAN%^%^BOLD%^It opens its maw, unleashing a freezing breath of ice upon "
"you, but you manage to avoid the worst of the attack!");
       pplz[i]->do_damage("torso",roll_dice(4,8));
       }
     else {
       tell_object(pplz[i],"%^CYAN%^%^BOLD%^It opens its maw and unleashes a freezing breath of ice upon "
"you, chilling you to the bone!");
       pplz[i]->do_damage("torso",roll_dice(8,8));
       freeze = pplz[i]->query_stats("constitution");
       freeze = 20-freeze;
       pplz[i]->set_paralyzed(freeze*2);
     }
   }
   TO->remove_property("magic");
   return 1;
}

int barb_fun(object target) {
   tell_object(target,"%^GREEN%^The wyvern lashes its tail at you with lightning speed, leaving a painful "
"sting with the barb!");
   tell_room(ETO,"%^GREEN%^The wyvern lashes its tail with lightning speed at "+target->QCN+"!",target);
   TO->set_property("magic",1);
//   target->add_poisoning(50);
// poisons are super borked, taking it off for now til the lib is fixed. N, 6/15.
   target->do_damage("torso",random(10)+20);
   tell_object(target,"%^GREEN%^Your veins begin to burn!");
   TO->remove_property("magic");
   return 1;
}

int claws_fun(object target) {
   tell_object(target,"%^BLACK%^%^BOLD%^The wyvern snarls and rears up, swiping both wickedly-clawed "
"forefeet at you!");
   tell_room(ETO,"%^BLACK%^%^BOLD%^The wyvern snarls and rears up, swiping both wickedly-clawed forefeet "
"at "+target->QCN+"!",target);
   target->do_damage("torso",random(20)+20);
   target->do_damage("torso",random(20)+20);
   return 1;
}

int teeth_fun(object target) {
   tell_object(target,"%^RED%^%^BOLD%^The wyvern darts forward, biting down hard on your arm and lifting "
"you from the ground!");
   tell_room(ETO,"%^GREEN%^The wyvern darts forward, biting down hard on "+target->QCN+"'s arm and "
"lifting "+target->QCN+" from the ground!",target);
   TO->set_property("magic",1);
   target->do_damage("torso",random(15)+30);
   TO->remove_property("magic");
   tell_object(target,"%^RED%^%^BOLD%^With a flick of its head, the wyvern tosses you across the room to "
"land hard on the stone floor, knocking the breath from your body!");
   tell_room(ETO,"%^RED%^%^BOLD%^With a flick of its head, the wyvern tosses "+target->QCN+" across the "
"room, to land hard on the stone floor!",target);
   target->set_paralyzed(30,"You are trying to catch your breath!");
   return 1;
}

void heart_beat() {
   int me;
   me = 0;
   ::heart_beat();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(query_paralyzed()) {
     me = 1;
     TO->set_paralyzed(0);
   }
   if(query_tripped()) {
     me = 1;
     TO->set_tripped(0);
   }
   if(me) tell_room(ETO,"%^YELLOW%^The wyvern shakes its great head, taking no notice of the dazing effect.");
   return;
}

void die(object ob) {
   object who;
   tell_room(ETO,"%^BOLD%^%^CYAN%^With a screech that shatters the icicles on the ceiling, the wyvern slumps "
"to the floor and breathes its last. Coins and precious items scatter across the %^WHITE%^frozen %^CYAN%^"
"floor.%^RESET%^");
   switch(random(4)) {
     case 0:
       new(OBJ+"bladestaff")->move(TO);
     break;
     case 1:
       new(OBJ+"sceptre")->move(TO);
     break;
     case 2:
       new(OBJ+"spindledisks")->move(TO);
     break;
     case 3:
       new(OBJ+"elbowshield")->move(TO);
     break;
   }
   new(OBJ+"sigilblue")->move(TO);
   :: die(TO);
}
