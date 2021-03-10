#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

void create (){
   ::create();
   set_name("Pirate Captain");
   set_id(({"pirate","captain rust","captain","rust"}));
   set_short("Captain Rust");
   set_long("This disgusting pig of a man seems to be the leader of the pirates.  He moves with an "
"assured swagger that hints at his inflated ego.  His fat belly hangs out over his belt, and his red "
"coat is stained by his apparently rather disgusting eating habits.  Instead of a left hand, he has "
"a vicious looking hook, which could account for his lack of manners at the table.  You can see the "
"skin from his last bite of chicken hanging out of his mouth.  A horrendous stench rises from the "
"captain, seeming to emanate from his sweat-stained coat.");
   set_race("half-orc");
   set_gender("male");
   set_body_type("human");
   set_hd(35,5);
   set_size(2);
   set_max_hp(300);
   set_hp(300);
   set_exp(7500);
   set_stats("strength",20);
   set_stats("intelligence",10);
   set_stats("wisdom",12);
   set_stats("dexterity",17);
   set_stats("constitution",15);
   set_stats("charisma",6);
   set_overall_ac(-4);
   set_mlevel("fighter",24);
   set_guild_level("fighter",24);
   set_wielding_limbs(({"left hand","right hand"}));
   new(OBJ"hook")->move(TO);
     command("wield hook");
   "/d/common/daemon/randgear_d.c"->arm_me(TO,"edgedm",75,random(2)+2);
   new(OBJ"redcoat")->move(TO);
     command("wear coat");
   set_funcs(({"bodyslam","sholderblock","backbreaker","rushem","flashem","flashem","flashem"}));
   set_func_chance(30);
   set_emotes(5, ({"The captain takes a huge bite of meat.","The captain burps loudly."}),0);
//   set_property("full attacks",1);
   set("aggressive",3);
   set_property("swarm",1);
   add_money("gold", random(300)+100);
   add_money("platinum", random(30)+10);
   set_mob_magic_resistance("average");
}

void bodyslam(object targ){
  tell_object(targ,"%^BOLD%^%^MAGENTA%^The captain leaps into the air and executes a %^WHITE%^"
"bodyslam%^MAGENTA%^ on you!%^RESET%^");
  tell_room(environment(targ),"%^BOLD%^%^BLUE%^The captain leaps into the air and executes a "
"%^WHITE%^bodyslam%^BLUE%^ on %^WHITE%^"+targ->query_cap_name()+"%^BLUE%^!%^RESET%^",targ);
  targ->do_damage("torso",random(15)+15);
  targ->set_paralyzed(random(5)+5,"%^BOLD%^The wind is knocked out of you!%^RESET%^");
}

void sholderblock(object targ){
   tell_object(targ,"%^BOLD%^%^YELLOW%^The Captain runs at you and executes a %^GREEN%^shoulderblock"
"%^YELLOW%^!%^RESET%^");
  tell_room(environment(targ),"%^BOLD%^%^RED%^The captain runs at %^WHITE%^"+targ->query_cap_name()+
"%^RED%^ and executes a %^WHITE%^shoulderblock%^RED%^!%^RESET%^",targ);
  targ->set_paralyzed(random(5)+10,"%^BOLD%^The wind is knocked out of you!%^RESET%^");
}

void backbreaker(object targ){
   tell_object(targ,"%^BOLD%^%^WHITE%^The Captain executes a %^RED%^backbreaker%^WHITE%^ on you!"
"%^RESET%^");
   tell_room(environment(targ),"%^BOLD%^%^CYAN%^The captain executes a %^WHITE%^backbreaker %^CYAN%^on "
"%^WHITE%^"+targ->query_cap_name()+"%^CYAN%^!%^RESET%^",targ);
   targ->do_damage("torso",random(5)+20);
}

void rushem(object targ){
  command("rush "+targ->query_cap_name());
}

void flashem(object targ){
  command("flash "+targ->query_cap_name());
}
