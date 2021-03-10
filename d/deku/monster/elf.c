//Made stronger by saide - added exp/hps/hd/better desc and 
//change for weapons to be magical - Saide
#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

create() {
  object ob;
  ::create();
  set_name("darkelf");
  set_id(({"darkelf","drow","elf","guard"}));
  set_race("drow");
  set_short("A drow elf");
  set_long("%^BOLD%^%^BLACK%^This dark skinned elf is accented with "+
  "%^RED%^light red%^BOLD%^%^BLACK%^ eyes and a thick %^BOLD%^%^WHITE%^"+
  "white mane%^BOLD%^%^BLACK%^.  His ebony colored flesh is very well "+
  "toned and pulled tight in several places.  He appears to be a "+
  "very capable warrior and his eyes are always glancing "+
  "about, revealing a heightened sense of alertness.  He carries two "+
  "weapons, each of which are always ready.%^RESET%^");
  set_gender("male");
  set_alignment(9);
  set_hd(20 + random(3),2);
  set_overall_ac(5);
  set_stats("intelligence",13);
  set_stats("wisdom",12);
  set_stats("strength",18);
  set_stats("dexterity",19);
  set_stats("constitution",11);
  set_hp(225 + random(35));
  set("aggressive", 16);
  set_property("swarm",1);
  set_race("drow");
  ob = new(CWEAP"dagger");
  if(!random(20)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield dagger");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear armor");
  ob = new(CWEAP"longsword");
  if(!random(20)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield sword");
  add_money("gold",random(100));
  //set_exp(query_max_hp() * (14 + random(5)));
  set_mob_magic_resistance("average");
  set_property("full attacks",1);
  add_money("gold",50 + random(151));
  if(!random(3)) add_money("platinum",5 + random(11));
	set_new_exp(20, "normal");
}

void init(){
  ::init();
  if(TP->query_invis()) return;
  if(interactive(TP))
  if(present("darkelf queen",ETO)){
    TO->force_me("say They are attacking our queen! KILL THEM!!");
    TO->kill_ob(TP);
  }
  if(random(5) >= 3 && TO->query_attack_bonus() < 2) {
   TO->force_me("emote readies his weapons aggressively");
   TO->add_attack_bonus(1);
  }
}
