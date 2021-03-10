#include <std.h>
#include "../derrodefs.h"
inherit MONSTER;

int flag;
  object ob;
void create(){
  ::create();
  set_name("student savant");
  set_id(({"derro","dwarf","mage","student","savant","student savant"}));
  set_race("dwarf");
  set_gender("male");
  set_short("%^RESET%^%^CYAN%^Student savant%^BOLD%^%^RED%^");
  set_long(
  "  With skin the color of an iced over lake and pupilless staring eyes these degenerate creatures look out of place in these giants halls."
  "  The everpresent red glow gives thier white/blue complexion that of maggots under a dusk sun."
  "  These look like no dwarves you ever seen before.  They have features of both those of a human and dwarf to make both races reminded of the other when they see these evil creatures."
  );
  set_ac(0);
  set_property("swarm",1);
  set_size(1);
  set_body_type("human");
  set_mob_magic_resistance("average");
  set_class("mage");
  set("aggressive",15);
  add_attack_bonus(2);
  set_property("no bows",1);
  set_mlevel(15);
  set_alignment(9);
  set_hd(15,5);
  set_property("full attacks",1);
  set_stats("strength",19);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  set_guild_level("mage",15);
 add_money("platinum",random(100));
  set_hp(75+random(75));
  set_max_hp(query_hp());
  set_exp(4000);
  ob=new(OBJ"secari.c");
  flag=random(20);
  if(flag>3)ob->set_property("monsterweapon",1);
  ob->move(TO);
  command("wield dagger");
  ob=new("/d/tharis/obj/randrobe.c");
  ob->move(TO);
  ob->set_size(1);
  if(flag>3) ob->set_property("monsterweapon",1);
  force_me("wear robes");
  //ob=new("/d/common/obj/potion/healing");
  //ob->move(TO);
  //ob->set_uses(15);
  set_property("add kits",10);
  set_spell_chance(80);
  set_spells(({"magic missile","acid arrow","lightning bolt",
  "ray of enfeeblement",
  }));
set_emotes(15,({
  "%^CYAN%^Derro savant calls for reinforcements and you can hear the sound of running feet!",
  "The student starts chanting in a low and mournful tone!",
  }),1);
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(present("snake",ETO)){new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  }
  /*if(query_hp()<50  && present("vial",TO)){
  command("open vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("offer bottle");
  command("offer bottle");
  command("offer bottle");
}*/
}
