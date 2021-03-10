#include <std.h>
#include "../dragon.h";

inherit MONSTER;

void create(){
object ob;
   ::create();
   set_name("minotaur");
   set_id(({"armored minotaur","minotaur"}));
   set_short("A massive armored minotaur");
   set_long(
      "This massive beast of a man has a body built to physical perfection."+
      " He stands at over seven feet tall while covered in hair. His lower"+
      " body takes after that of a bull, while his torso is built like a human."+
      " However, his head takes after his bull side the snout and horns."
   );
   set_class("fighter");
   set_guild_level("fighter",20);
   set_race("minotaur");
   set_gender("male");
   set_hd(20,10);
   set_alignment(9);
   set_max_hp(1000);
   set_hp(1000);
   set_overall_ac(-6);
   set_mob_magic_resistance("average");
   set_property("no dominate", 1);
   set_property("no hold", 1);
   set_property("no bows", 1);
   set_property("no paralyze", 1);
   set_property("no poison", 1);
   set_size(3);
   set("aggressive",30);
   set_exp(33000);
//   set_wielding_limbs(({"right fist","left fist"}));
   set_stats("strength",25);
   set_stats("dexterity",18);
   ob = new(OBJ+"plate")->move(TO);
   force_me("wear plate");
   ob = new(OBJ+"axe")->move(TO);
   force_me("wield axe");
   set_funcs( ({"overhead","slash","charge"}) );
   set_func_chance(80);
   set_max_level(23);
}

void overhead(object targ) {
   tell_object(targ, "%^BOLD%^%^RED%^The minotaur delivers an overhead strike with its axe!");
   tell_room(ETO, "%^BOLD%^%^RED%^The minotaur delivers an overhead strike on "+targ->query_cap_name()+" with its axe!",targ);
   targ->do_damage("torso",(30));
}

void slash(object targ) {
   tell_object(targ, "%^BOLD%^%^RED%^The minotaur delivers a viscious slash with its axe!");
   tell_room(ETO, "%^BOLD%^%^RED%^The minotaur delivers a viscious slash on "+targ->query_cap_name()+" with its axe!",targ);
   targ->do_damage("torso",(30));
}

void charge(object targ) {
   tell_object(targ, "%^BOLD%^%^BLUE%^The minotaur charges head first into you, knocking the wind out of you!");
   tell_room(ETO, "%^BOLD%^%^BLUE%^The minotaur charges head first into "+targ->query_cap_name()+"!",targ);
   targ->do_damage("torso",(30));
   targ->set_paralyzed(10, "%^BOLD%^%^BLUE%^You are trying to catch your breath!%^RESET%^");
}
