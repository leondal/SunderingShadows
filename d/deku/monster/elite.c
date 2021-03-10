//Made stronger by saide - added exp/hps/hd/better desc and 
//change for weapons to be magical - Saide
#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

create() {
  object ob;
  ::create();
  set_name("Darkelf");
  set_id(({"darkelf","guard","drow","elf", "elite"}));
  set_race("drow");
  set_gender("male");
  set_short("A drow elf");
  set_long("%^BOLD%^%^BLACK%^This tall ebony skinned elf is accented "+
  "with %^RED%^intense red%^BOLD%^%^BLACK%^ eyes and a flowing, "+
  "%^BOLD%^%^WHITE%^white mane%^BOLD%^%^BLACK%^.  He carries himself "+
  "lightly and glances around frequently.  He wears a dark cloak "+
  "and strangely, a suit of common chainmail.  The visible parts "+
  "of his body are well toned and you safely assume that he is an "+
  "experienced warrior.  He carries two long swords, each of them "+
  "kept ever ready.%^RESET%^");
  
  set("aggressive",26);
  set_property("swarm",1);
  set_alignment(9);
  set_hd(23 + random(3),2);
  set_overall_ac(3);
  set_stats("intelligence",16);
  set_stats("wisdom",12);
  set_stats("strength",17);
  set_stats("dexterity",16);
  set_stats("constitution",10);
  ob = new(CWEAP"longsword");
  if(!random(15)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield sword");
  ob = new(CWEAP"longsword");
  if(!random(15)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield sword");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear chain");
  new("/d/deku/armours/cloak1")->move(TO);
  command("wear cloak");
  //set_hp(query_hd() * 10 + random(31));
	set_hp(288 + random(55));
  //set_exp(query_max_hp() * (15 + random(6)));
	set_new_exp(20, "high");
  add_money("gold",150 + random(500));
  set_property("full attacks",1);
  set_mob_magic_resistance("average");
  set_funcs(({"hack"}));
  set_func_chance(30);
}

void init(){
  ::init();
  if(random(5) >= 3 && TO->query_attack_bonus() < 2 &&!TP->query_invis()) {
   TO->force_me("emote readies his weapons aggressively");
   TO->add_attack_bonus(1);
  }
}

void hack(object targ) {
  int need, i, tac, tlevel, roll;
  tlevel = TO->query_level();
  need = "/daemon/bonus_d.c"->thaco(tlevel, "fighter");
  tac = targ->query_ac();
  if(!((roll >= (need - tac)) || (roll == 20))) {
    tell_room(environment(targ), "%^RED%^The Drow guard recieves a burst of power, but nothing happens!");
    return 1;
  }
  tell_room(environment(targ), "%^BOLD%^%^RED%^The Drow recieves a burst of unknown power, and hacks upon "+targ->query_cap_name()+"!");
  set_func_chance(0);
  for(i=0;i<2;i++) {
    TO->execute_attack();
  }
  set_func_chance(35);
  tell_room(environment(targ), "%^RED%^The Drow's power fades away!\n");
  return 1;
}
