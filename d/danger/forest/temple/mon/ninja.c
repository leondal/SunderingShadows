#include <std.h>
#include "../ninja.h";

inherit MONSTER;

object ob;

void create() {
   ::create();
   set_name("Woman");
   set_id(({"ninja","temple ninja","real ninja","woman","woman in overcoat","guard"}));
   set_short("Woman in a long gray overcoat");
   set_long(
   "This woman is one of many students that has taken residence here at this temple."+
   " Women come at an early age for many different reasons. Some are orphans,"+
   " others were outcasts, and some simply come seeking knowledge."+
   " During their training, the women usually become protectors of this sacred place,"+
   " like this woman standing before you. She is dressed in the traditional"+
   " garb of the temple. A dark brown loose fitting body suit, which is tightned"+
   " at the wrists and ankles by bandages, with a gray overcoat and forehead protector."
   );
   set_class("fighter");
   set_mlevel("fighter", 45);
   set_guild_level("fighter", 45);
   set_max_hp(5000);
   set_hp(5000);
   set_exp(70000);
   set_overall_ac(-25);
   set_body_type("humanoid");
   set_gender("female");
   set_race("human");
   set_alignment(3);
   set_property("weapon resistance", 4);
   set_property("full attacks", 1);
   set_property("swarm", 1);
   ob = new(OBJ+"dagger")->move(TO);
   ob = new(OBJ+"dagger")->move(TO);
   force_me("wield dagger");
   force_me("wield dagger 2");
   set_stats("strength", 20);
   set_stats("dexterity", 20);
   set_stats("constitution", 14);
   set_stats("wisdom", 16);
   set_stats("intelligence", 12);
   set_stats("charisma", 11);
   set_funcs(({"firebreath","bunshin","shuriken","flurry1","flurry2","flurry3"}));
   set_func_chance(50);
}

void firebreath(object targ) {
   tell_room(ETO, "%^RESET%^%^MAGENTA%^Quickly she executes six hand seals and spits out%^RESET%^: %^BOLD%^%^RED%^Breath of fire!%^RESET%^", targ);
   tell_room(ETO, "%^BOLD%^%^RED%^She spews flame from her mouth all over "+targ->query_cap_name()+"!%^RESET%^", targ);
   tell_object(targ, "%^RESET%^%^MAGENTA%^Quickly she executes six hand seals and spits out%^RESET%^: %^BOLD%^%^RED%^Breath of fire!%^RESET%^");
   tell_object(targ, "%^BOLD%^%^RED%^She spews flame from her mouth all over you!%^RESET%^");
   set_property("magic", 1);
   targ->do_damage("torso", random(100)+100);
   remove_property("magic");
}

void bunshin(object targ) {
   tell_room(ETO, "%^BOLD%^%^WHITE%^She slams her hands together and screams%^RESET%^: %^RESET%^%^MAGENTA%^Clones of water%^RESET%^!!\n"
      " %^BOLD%^%^BLUE%^Several versions of the woman appear from nowhere%^RESET%^!", targ);
   tell_object(targ, "%^BOLD%^%^WHITE%^She slams her hands together and screams%^RESET%^: %^RESET%^%^MAGENTA%^Clones of water%^RESET%^!!\n"
      " %^BOLD%^%^BLUE%^Several versions of the woman appear from nowhere%^RESET%^!");
   ob = new("/d/danger/forest/temple/mon/rninja");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new("/d/danger/forest/temple/mon/rninja");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new("/d/danger/forest/temple/mon/rninja");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new("/d/danger/forest/temple/mon/rninja");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new("/d/danger/forest/temple/mon/rninja");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
}

void shuriken(object targ){
   tell_room(ETO, "%^BOLD%^%^GREEN%^She reaches into one of her many pockets and unloads a handful of shurikens at "+targ->query_cap_name()+" with lightning speed%^RESET%^!", targ);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
   tell_object(targ, "%^BOLD%^%^YELLOW%^Hits you with a shuriken%^RESET%^!");
   targ->do_damage("torso", random(25)+25);
}

void flurry1(object targ){
   tell_room(ETO, "%^RESET%^%^GREEN%^She spins low and sweep kicks "+targ->query_cap_name()+" and follows up with an axe kick before delivering a viscious slash across the chest.%^RESET%^", targ);
   tell_object(targ, "%^RESET%^%^GREEN%^She spins low and sweep kicks you and follows up with an axe kick before delivering a viscious slash across the chest.%^RESET%^");
   targ->do_damage("torso", random(150)+50);
}

void flurry2(object targ){
   tell_room(ETO, "%^BOLD%^%^BLACK%^She kicks "+targ->query_cap_name()+"'s left hand aside, maintains her balance, kicks the right hand aside then pushes off the chest in order to create space to summon her own defensive measures%^RESET%^!", targ);
   tell_object(targ, "%^BOLD%^%^BLACK%^She kicks your left hand aside, maintains her balance, kicks the right hand aside then pushes off the chest in order to create space to summon her own defensive measures%^RESET%^!", targ);
   targ->do_damage("torso", random(100)+25);
   new("/cmds/spells/s/_stoneskin")->use_spell(TO,TO,35,100,"mage");
}

void flurry3(object targ){
   tell_room(ETO, "%^BOLD%^%^MAGENTA%^She slides between "+targ->query_cap_name()+"'s legs, rolls to her feet and kicks in the back of the knee, bringing her foe down. She pivots to the left and delivers a harsh kick to the head%^RESET%^!", targ);
   tell_object(targ, "%^BOLD%^%^MAGENTA%^She slides between your legs, rolls to her feet and kicks you in the back of the knee, bringing you down. She pivots to the left and delivers a harsh kick to the head%^RESET%^!");
   targ->do_damage("torso", random(75)+75);
   targ->set_paralyzed(25,"%^RESET%^%^%^MAGENTA%^You are trying to shake your head clear of the stars.");
}
