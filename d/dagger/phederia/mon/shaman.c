#include <std.h>
#include "../phedefs.h"
inherit MONSTER;
object ob,targ,targ2;
void create(){
  ::create();
  set_name("phederian dark shaman");
  set_id(({"phederian","shaman","dark shaman","phederian dark shaman"}));
  set_race("human");
  set_mob_magic_resistance("average");
  if(!random(2)){set_gender("male");} else {set_gender("female");}
   set_short("%^BLUE%^Phederian dark shaman%^BOLD%^RED%^");
  set_long(
  "  This human cleric has sworn to the cause of the Warlord Phederia."
  "  "+TP->query_subjective()+" follows Phederia in service to an evil god and the gold doesnt hurt as well."
  "  They show no fear or compasion and fight to the death to further the cause they've sold their souls to join."
  );
  set_ac(-4);
  set_property("swarm",1);
  set_size(2);
  set_body_type("human");
  set_class("cleric");
  set("aggressive",18);
  set_mlevel("cleric",25);
  set_guild_level("cleric",25);
  set_attack_bonus(2);
  add_search_path("/cmds/priest");
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
  set_hp(150+(random(50)));
  set_exp(5000);
  set_emotes(15,({
  }),1);
  set_spell_chance(80);
  set_spells(({
  "limb attack","limb attack","limb attack"
  "animate object","sticks into snakes","flame strike"
  }));
  new(OBJ"barmor.c")->move(TO);
  command("wearall");
  new(OBJ"mace.c")->move(TO);
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO)) return;
  targ=present("dark crusader");
  targ2=present("dark magus");
  if(query_paralyzed()) return;
  if(targ){
  if(!targ->query_property("HEaled")){
  if((int)targ->query_hp() < 75){
  new("/cmds/spells/h/_heal.c")->use_spell(TO,targ,25,100,"cleric");
  targ->set_property("HEaled",1);
  }
  }
  }
  if(targ2){
  if((int)targ2->query_hp()<75){
  if(!targ2->query_property("HEaled")){
  new("/cmds/spells/h/_heal.c")->use_spell(TO,targ2,25,100,"cleric");
  targ2->set_property("HEaled",1);
  }
  }
  }
  if(TO->query_property("HEaled")) return;
  if((int)TO->query_hp() < 75){
  new("/cmds/spells/h/_heal.c")->use_spell(TO,TO,25);
  new("/cmds/spells/s/_sticks_into_snakes.c")->use_spell(TO,TO,25,100,"cleric");
  TO->set_property("HEaled",1);
  }
}
int query_watched(){
  return 25;
}
