#include <std.h>
#include "../ninja.h";

inherit MONSTER;

object ob;

void create() {
   ::create();
   set_name("Woman");
   set_id(({"ninja","temple ninja","real ninja","woman","woman drapped in silk","guard"}));
   set_short("Woman drapped in fine silks");
   set_long(
   "This woman is one of many students that has taken residence here at this temple."+
   " Women come at an early age for many different reasons. Some are orphans,"+
   " others were outcasts, and some simply come seeking knowledge."+
   " During their training, the women usually become protectors of this sacred place,"+
   " like this woman standing before you. She is garbed in fine white silks"+
   " which wraps around her body leaving little of herself in view."+
   " She wears the silks in many layers, some tight and some loose,"+
   " making it quite easy for her to conceal small objects."+
   " She lets the silk cover the lower half of her face, but"+
   " wears a forehead protector to keep her hair up and out of her face."
   );
   set_class("fighter");
   set_mlevel("fighter", 45);
   set_guild_level("fighter", 45);
   set_max_hp(6500);
   set_hp(6500);
   set_exp(70000);
   set_overall_ac(-25);
   set_body_type("humanoid");
   set_gender("female");
   set_race("human");
   set_alignment(3);
   set_mob_magic_resistance("average");
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
   set_func_chance(100);
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
   ob = new(MON+"rninja2");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new(MON+"rninja2");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new(MON+"rninja2");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new(MON+"rninja2");
   ob->move(ETO);
   ob->set_attackers(query_attackers());
   execute_attack();
   ob = new(MON+"rninja2");
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
   tell_room(ETO, "%^RESET%^%^BLUE%^She rushes at "+targ->query_cap_name()+" both palms exposed, dips under "+targ->query_cap_name()+"'s guard, takes a second to gain her footing and pushes forward%^RESET%^!\n"
   "%^RESET%^%^CYAN%^She drives her hands forward with all her strength and stops just short of "+targ->query_cap_name()+"'s chest, but it looks like a solid hit was made nonetheless%^RESET%^!",targ);
   tell_object(targ, "%^RESET%^%^BLUE%^She rushes at you both palms exposed, dips under your guard, takes a second to gain her footing and pushes forward%^RESET%^!\n"
   "%^RESET%^%^CYAN%^She drives her hands forward with all her strength and stops just short of your chest, but you feel as if she just ran you through with a sword%^RESET%^!");
   set_property("magic", 1);
   targ->do_damage("torso", random(100)+100);
   remove_property("magic");
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
