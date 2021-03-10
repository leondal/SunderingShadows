#include <std.h>
#include "../phedefs.h"
inherit MONSTER;
object ob,targ,targ2;
int stoned;
void create(){
  ::create();
  set_name("phederian dark magus");
  set_id(({"phederian","magus","dark magus","phederian dark magus"}));
  set_race("human");
  set_mob_magic_resistance("average");
  if(!random(2)){set_gender("male");} else {set_gender("female");}
  set_short("%^BLUE%^Phederian dark magus%^BOLD%^%^RED%^");
  set_long(
  "  This human mage has sworn to the cause of the Warlord Phederia."
  "  "+TO->query_subjective()+" draws his wages from the coffers that seem never ending with the gold from Phedeias evil conquests."
  "  They show no fear or compasion and fight to the death to further the cause they've sold their souls to join."
  );
  set_ac(-4);
  set_property("swarm",1);
  set_size(2);
  set_body_type("human");
  set_class("mage");
  set_mlevel("mage",25);
  set_guild_level("mage",25);
  set_attack_bonus(2);
  add_search_path("/cmds/wizard");
  set_alignment(9);
  set_hd(20,5);
  set_property("full attacks",1);
  set_stats("strength",18);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  add_money("gold",random(100));
  set_hp(100+(random(100)));
  set_exp(5000);
  set_emotes(15,({
  }),1);
  set_spell_chance(80);
  set_spells(({
  "magic missile",
  "acid arrow",
  "monster summoning i",
  "lightning bolt",
  "cone of cold",
  "prismatic spray",
  "fireball",
  "meteor swarm",
  }));
  new(OBJ"robe.c")->move(TO);
  command("wearall");
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO)) return;
  targ=present("dark crusader");
  targ2=present("dark shaman");
  if(targ){
  if(!targ->query_property("SToned")){
  new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,targ,25,100,"mage");
  targ->set_property("SToned",1);
  }
  }
  if(targ2){
  if(!targ2->query_property("SToned")){
  new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,targ2,25,100,"mage");
  targ2->set_property("SToned",1);
  }
  }
  if(stoned) return;
  if(!TO->query_stoneSkinned()){
  new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,25,100,"mage");
  stoned=1;
  }
  }
int query_watched(){
  return 25;
  }
