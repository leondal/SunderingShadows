#include <std.h>
#include "../phedefs.h"
inherit MONSTER;
  object ob,targ,targ2;
void create(){
  ::create();
  set_name("phederian dark crusader");
  set_id(({"phederian","crusader","phederian dark crusader","dark crusader"}));
  set_race("human");
  set_mob_magic_resistance("average");
  if(!random(2)){set_gender("male");} else {set_gender("female");}
  set_short("%^BLUE%^Phederian dark crusader%^BOLD%^RED%^");
  set_long(
  "  This human warrior has sworn to the cause of the Warlord Phederia."
  "  Their armor and weapons are created and damned by the Warlords shaman and " +TO->query_possessive()+" purse flows with gold from her evil conquests."
  "  They show no fear or compasion and fight to the death to further the cause they've sold their souls to join."
  );
  set_ac(-4);
  set_property("swarm",1);
  set_size(2);
  set_body_type("human");
  set_class("fighter");
  set("aggressive",18);
  set_mlevel("fighter",20);
  set_attack_bonus(2);
  add_search_path("/cmds/fighter");
  add_search_path("/cmds/mortal");
  set_alignment(9);
  set_hd(20,5);
  set_property("full attacks",1);
  set_stats("strength",19);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",25);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  add_money("gold",random(100));
  set_hp(150+(random(70)));
  set_exp(5000);
  set_emotes(15,({
  }),1);
  switch(random(3)){
  case 0:
  new(OBJ"bardiche.c")->move(TO);
  command("wield axe");
  break;
  case 1:
  new(OBJ"halberd.c")->move(TO);
  command("wield halberd");
  break;
  case 2:
  new(OBJ"lochebar.c")->move(TO);
  command("wield axe");
  break;
  }
  new(OBJ"barmor.c")->move(TO);
  command("wear armor");
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO)) return;
  targ=present("dark magus");
  targ2=present("dark shaman");
  if(targ){
  if(!targ->query_property("PRotected")){
  targ2->add_protector(TO);
  targ->set_property("PRotected",1);
  }
  }
  if(targ2){
  if(!targ2->query_property("PRotected")){
  targ2->add_protector(TO);
  targ2->set_property("PRotected");
  }
  }
}
int query_watched(){
  return 25;
  }
