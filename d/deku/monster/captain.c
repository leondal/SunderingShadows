#include <std.h>
#include "/d/common/common.h"

inherit "/std/monster";

void create() {
  object ob;
  ::create();
  set_name("captain");
  set_id(({"darkelf", "captain", "drow", "elf"}));
  set_race("drow");
  set_gender("male");
  set_short("A drow elf");
  set_long("%^BOLD%^%^BLACK%^This dark skinned elf is accented with "+
  "%^RED%^light red%^BOLD%^%^BLACK%^ eyes and a thick %^BOLD%^%^WHITE%^"+
  "white mane%^BOLD%^%^BLACK%^.  His ebony colored flesh is very well "+
  "toned and pulled tight in several places.  He appears to be a "+
  "very capable warrior and his eyes are always glancing "+
  "about, revealing a heightened sense of alertness.  He carries two "+
  "weapons, each of which are always ready.%^RESET%^");
  set("aggressive", 18);
  set_alignment(9);
  set_size(2);
  set_hd(20 + random(2),4);
  set_hp(275 + random(20));
  set_exp(query_hp() * 13);
  set_overall_ac(3);
  set_stats("intelligence",12);
  set_stats("wisdom",10);
  set_stats("strength",16);
  set_stats("dexterity",15);
  set_stats("constitution",10);
  ob = new(CWEAP"longsword");
  if(!random(17)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield sword");
  ob = new(CWEAP"longsword");
  if(!random(17)) ob->set_property("enchantment",1);
  ob->move(TO);
  command("wield sword");
  new("/d/common/obj/armour/chain")->move(TO);
  command("wear chain");
  set_emotes(5,({query_cap_name()+" laughs evilly at you."}),1);
  set_new_exp(20, "normal");
  set_funcs(({"attack"}));
  set_func_chance(25);
  set_mob_magic_resistance("average");
  set_property("full attacks",1);
}

void init(){
  ::init();
  if(random(5) >= 3 && TO->query_attack_bonus() < 8 &&!TP->query_invis()) {
   TO->force_me("emote readies his weapons aggressively");
   TO->add_attack_bonus(2);
  }
}


void attack(object targ) {
  if(query_wielded() == ({})) return roll_dice(1,4)+4;
  tell_room(environment(targ), "%^GREEN%^The Drow tumbles to the side, and thrusts both "+
  "longswords toward "+targ->query_cap_name()+"!",targ);
  tell_object((targ), "%^BLUE%^The Drow tumbles to the side and thrusts both longswords "+
  "doing some extreme damage.");
  targ->do_damage("torso", roll_dice(5,8)+4);
  return 1;
}
