#include <std.h>
#include "../derrodefs.h"
inherit MONSTER;
void init(){
  ::init();
  //if(present("kit")){force_me("get kit");}
  if(TP->query_invis()&&!avatarp(TP)){
  tell_room(ETO,"%^BOLD%^%^BLACK%^Derro savant calls on his magic to deal with his foes!.");
  TP->set_invis();
  kill_ob(TP,1);
  }
}
void create(){
  object ob;
  ::create();
  set_name("Derro Savant");
  set_id(({"derro","dwarf","mage","student","savant","student savant"}));
  set_race("dwarf");
  set_gender("male");
  set_short("%^RESET%^%^CYAN%^Derro savant%^BOLD%^%^RED%^");
  set_mob_magic_resistance("average");
  set_long(
  "  With skin the color of an iced over lake and pupilless staring eyes these degenerate creatures look out of place in these giants halls."
  "  The everpresent red glow gives thier white/blue complexion that of maggots under a dusk sun."
  "  Magic seems to seep from this Derro and it's directed at you!"
  );
  set_ac(0);
  set_property("no bows",1);
  set_property("swarm",1);
  set_size(1);
  set_body_type("human");
  set_class("mage");
  set("aggressive",18);
  add_attack_bonus(2);
  set_mlevel(25);
  set_alignment(9);
  set_hd(25,5);
  set_property("full attacks",1);
  set_stats("strength",19);
  set_stats("dexterity",18);
set_stats("constitution",19);
  set_stats("intelligence",15);
  set_stats("wisdom",15);
  set_stats("charisma",13);
  set_guild_level("mage",25);
  add_money("gold",random(100));
  set_hp(250);
  set_exp(15000);
  new(OBJ"ssecari.c")->move(this_object());
  command("wield dagger");
  ob=new("/d/tharis/obj/randrobe.c");
  ob->move(TO);
  ob->set_size(1);
  force_me("wear robe");
  //ob=new("/d/common/obj/potion/healing");
  //ob->move(TO);
  //ob->set_uses(50);
  set_property("add kit", 25);
ob=new("/d/magic/scroll");
  ob->set_spell(9);
  ob->move(TO);
  set_spell_chance(80);
  set_spells(({"magic missile","acid arrow","lightning bolt",
  "magic missile","magic missile","magic missile",
  "ray of enfeeblement",
  "meteor swarm",
  }));
  set_emotes(15,({
  "%^CYAN%^Derro savant calls for reinforcements and you can hear the sound of running feet!",
  "%^BOLD%^%^BLACK%^Savant suddenly glows with black power and reaches for your heart!",
  "%^BOLD%^%^YELLOW%^Lightning crackles in a shield around the Savant!%^RESET%^",
  }),1);
}
void heart_beat(){
  ::heart_beat();
  if(!objectp(TO) || !objectp(ETO)) return;
  if(present("snake",ETO)){new("/cmds/wizard/_dispel_magic")->use_spell(TO,0,query_level());
  if(present("vial",ETO)){command("get kit");}
  }
  if(present("horse",ETO)){
  command("kill horse");
  }
 /* if(query_hp()<100  && present("vial",TO)){
  command("open vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("drink vial");
  command("offer bottle");
  command("offer bottle");
  command("offer bottle");
  command("offer bottle");
  command("offer bottle");
  command("offer bottle");
  }*/
}
int query_blinking(){
  //return 50;
}
