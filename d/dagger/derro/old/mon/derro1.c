// didn't find reason for 

#include <std.h>
#include "../derrodefs.h"

inherit MONSTER;

void init(){
  ::init();
  if (TP->query_invis()) return 1;
  if(TP->query_lowest_level()>25 && !avatarp(TP)){
  message("environment","%^BOLD%^%^RED%^Derro beserks wildly!%^RESET%^",environment(TO));
  if (!TO->query_property("beser")){
  TO->set_property("beser",1);
  add_attack_bonus(4);
  }
   call_out("force_me",1,"rush "+TPQN);
    }
}

void create(){
   int flag;
   object ob;
  ::create();
  set_name("derro warrior");
  setenv("MIN", "$N scampers in looking for something to kill.");
  setenv("MOUT", "$n scampers out looking for something to kill $D.");
  set_id(({"derro","dwarf","warrior","derro warrior"}));
  set_property("no bows",1);
  set_race("dwarf");
  set_mob_magic_resistance("average");
  set_gender("male");
  set_short("%^RESET%^%^BLUE%^Derro warrior%^BOLD%^%^RED%^%^");
  set_long(
  "  With skin the color of an iced over lake and pupilless staring eyes these degenerate creatures look out of place in these giants halls."
  "  The everpresent red glow gives their white/blue complexion that of maggots under a dusk sun."
  "  These look like no dwarves you ever seen before.  They have features of both those of a human and dwarf to make both races reminded of the other when they see these evil creatures."
  );
  set_ac(4);
  set_property("swarm",1);
  set_size(1);
  set_moving(1);
  set_speed(20);
  set_body_type("human");
  set_class("fighter");
  set("aggressive",19);
  set_mlevel(15);
  set_attack_bonus(2);
  add_search_path("/cmds/fighter");
  set_alignment(9);
  set_hd(15,5);
  set_property("full attacks",1);
  set_stats("strength",18);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  set_guild_level("fighter",15);
  add_money("platinum",random(100));
  set_hp(75+random(75));
  set_max_hp(query_hp());
  set_exp(3000);
  ob=new(OBJ"hook-fauchard.c");
  flag=random(20);
  if (flag>3)ob->set_property("monsterweapon",1);
  ob->move(TO);
  command("wield spear");
  ob=new(OBJ"kather.c");
  if(flag>1)ob->set_property("monsterweapon",1);
  ob->move(TO);
  command("wear kather");
  set_emotes(15,({
  "%^RED%^Derro tries to get behind you!%^RESET%^",
  "Derro giggles and closes for the kill.",
  }),1);
}

void heart_beat(){
  ::heart_beat();
  if(!objectp(TO)) return;
  if(!objectp(ETO)) return;
  if(present("horse",ETO)){
  command("rush horse");
  }
  if(present("king",ETO)){
  command("rush king");
  }
  if(present("elemental",ETO)){
  command("rush elemental");
  }
}
