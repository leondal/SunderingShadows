#include <std.h>
#include <magic.h>
#include <daemons.h>
#include "../lair.h"
inherit MONSTER;

int rath, active;

void create() {
   object equipment;
   ::create();
   set_name("Rath'argh");
   set_id(({ "drow","rathargh","rath'argh","Rath'argh"}));
   set_short("%^RESET%^%^RED%^Rath'argh%^RESET%^");
   set_long("%^RESET%^%^MAGENTA%^This agile creature moves with a grace bordering on the su%^RED%^p%^MAGENTA%^ernatural.  "
"Most of his features are shrouded within the hooded clo%^BOLD%^%^BLACK%^a%^RESET%^%^MAGENTA%^k he wears, which swirls "
"around him and reaches nearly to the ground.  Jet black, when he stands motionless he is hard to separate from the shad"
"%^BLUE%^o%^MAGENTA%^ws.  Beneath the cloak's hood, gleaming c%^BOLD%^%^RED%^r%^RESET%^%^MAGENTA%^imson eyes and whisps "
"of bone-w%^RESET%^h%^MAGENTA%^ite hair give enough hints to deduce that he is a drow, but not enough features are "
"visible to set him apart from any other of his species. An obsid%^BOLD%^%^BLACK%^i%^RESET%^%^MAGENTA%^an dagger is held "
"in his hand, and from the precision of his movements you would assume he knows how to use it.%^RESET%^");
   set_race("drow");
   set_gender("male");
   set_body_type("humanoid");
   set_alignment(9);
   set_size(2);
   set_exp(1);
   set_hd(50,6);
   set_class("thief");
   set_mlevel("thief",40);
   set_guild_level("thief",40);
   set_class("mage");
   set_mlevel("mage",40);
   set_guild_level("mage",40);
   set_property("full attacks",1);
   set_max_hp(2500);
   set_hp(query_max_hp());
   set_property("weapon resistance",4);
   set_mob_magic_resistance("average");
   set_property("spell penetration",60);
   set_property("no animate", 1);
   set_property("no steal", 1);
   set_property("no hold", 1);
   set_property("no dominate", 1);
   set_property("no bows", 1);
   set_property("no knockdown", 1);
   set_property("no tripped", 1);
   set_property("no web", 1);
   set_overall_ac(-22);
   set_funcs(({"bladefan","bladefan","darts","darts","stabfun","stabfun","silencedust"}));
   set_func_chance(75);
   equipment = new(OBJ"sheoldagger");
     equipment->set_property("monsterweapon",1);
     equipment->move(TO);
     command("wield dagger");
}

void init() {
   string whoami;
   ::init();
   whoami=TP->query_name();
   if(whoami != "Arkhon Bloodscale" && !TP->query_true_invis()) {
//     TO->force_me("kill "+whoami+"");
     TO->add_attacker(TP);
     TP->add_attacker(TO);
   }
}

void bladefan(object target) {
   object *vars;
   int i;

   tell_room(ETO,"%^RESET%^%^BLUE%^With a flick of his wrist, Rath'argh sends a fan of %^RESET%^glinting%^BLUE%^ blades "
"whirling through the air!%^RESET%^");
   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   for(i=0;i<5;i++){
     target = vars[random(sizeof(vars))];
     if(!objectp(target)) continue;
     if(!interactive(target)) continue;
     tell_object(target,"%^CYAN%^A blade slices through your skin!%^RESET%^");
     target->do_damage("torso",50+random(50));
   }
   return;
}

void darts(object target){
   object *vars;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_room(ETO,"%^RESET%^%^MAGENTA%^Rath'argh produces a tiny %^CYAN%^dart %^MAGENTA%^from beneath the folds of his "
"cloak, and he flings it directly at "+target->QCN+"!%^RESET%^",target);
   tell_object(target,"%^RESET%^%^MAGENTA%^Rath'argh produces a tiny %^CYAN%^dart %^MAGENTA%^from beneath the folds of "
"his cloak, and he flings it directly at you! A momentary numbness races through your limbs as the %^GREEN%^po%^BOLD%^i"
"%^RESET%^%^GREEN%^son %^MAGENTA%^takes hold.%^RESET%^");
   target->set_paralyzed(20,"%^GREEN%^You're still trying to fight off the haze of the poison!%^RESET%^");
}

void stabfun(object target) {
   object *vars;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_room(ETO,"%^RESET%^%^BLUE%^Rath'argh swirls his %^BOLD%^%^BLACK%^sh%^RESET%^ad%^BOLD%^%^BLACK%^owy cloak %^RESET%^"
"%^BLUE%^around himself and disappears!%^RESET%^");
   tell_object(target,"%^RESET%^%^RED%^Suddenly he solidifies from the shadows behind you, and %^BOLD%^seari%^MAGENTA%^n"
"%^RED%^g pain %^RESET%^%^RED%^erupts through your back as he stabs his dagger viciously between your "
"shoulders!%^RESET%^");
   tell_room(ETO,"%^RESET%^%^RED%^Suddenly he solidifies from the shadows behind "+target->QCN+", and his dagger %^BOLD%^"
"gleams %^RESET%^%^RED%^as he stabs it viciously between "+target->QP+" shoulders!%^RESET%^",target);
   //scaling slightly to give squishies half a chance
   if((int)target->query_max_hp() > 300) {
     target->do_damage("torso",random(75)+75);
     return;
   }
   if((int)target->query_max_hp() > 400) {
     target->do_damage("torso",random(75)+150);
     return;
   }
   if((int)target->query_max_hp() > 500) {
     target->do_damage("torso",random(75)+225);
     return;
   }
   target->do_damage("torso",random(75)+250);
}

void silencedust(object target) {
   object *vars, dustobj;

   vars = all_living(ETO);
   vars = filter_array(vars,"is_non_immortal_player",FILTERS_D);
   if(!sizeof(vars)) return;
   target = vars[random(sizeof(vars))];
   if(!objectp(target)) return;
   if(!interactive(target)) return;
   tell_object(target,"%^GREEN%^You find yourself choking and coughing suddenly, as Rath'argh casts a handful of "
"%^ORANGE%^dust %^GREEN%^directly into your face!%^RESET%^");
   tell_room(ETO,"%^GREEN%^"+target->QCN+" suddenly starts coughing and spluttering, as Rath'argh casts a handful of "
"%^ORANGE%^choking dust %^GREEN%^directly into "+target->QP+" face!%^RESET%^",target);
   if(dustobj = present("choking-dust-obj",target)) dustobj->remove();
   new(OBJ"chokingdust")->move(target);
}

void die(object ob){
   tell_room(ETO,"%^BLUE%^%^Rath'argh staggers back, %^RED%^gr%^BOLD%^i%^RESET%^%^RED%^evously %^BLUE%^wounded and with "
"one hand clutched to his side.%^RESET%^");
   tell_room(ETO,"%^BOLD%^%^BLACK%^His eyes narrow as he appraises the state of the battle.  Quickly coming to a "
"conclusion, he swirls his cloak about himself and melts away into the shadows.%^RESET%^");
   if(present("Arkhon Bloodscale",ETO))
     tell_room(ETO,"%^BOLD%^%^RED%^Arkhon lets out an enraged roar as his ally vanishes, and turns upon you with renewed "
"vigor!%^RESET%^");
   TO->move("/d/shadowgate/void");
   TO->remove();
}
