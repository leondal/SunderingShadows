//updated to current code, including size, etc. ~Circe~ 7/31/19

#include <std.h>
#include "../derrodefs.h"

inherit MONSTER;

void create(){
   object ob;
   ::create();
   set_name("Derro Savant");
   set_id(({"derro","dwarf","mage","student","savant","student savant"}));
   set_race("dwarf");
   set_gender("male");
   set_short("%^RESET%^%^CYAN%^Derro savant%^BOLD%^%^RED%^");
   set_mob_magic_resistance("average");
   set_long("%^CYAN%^With skin the color of an iced-over lake and pupilless, staring eyes, this degenerate creature looks out of place in these giant halls.  The ever-present %^RED%^red glow %^CYAN%^makes the creature's %^RESET%^white%^CYAN%^/%^BOLD%^blue %^RESET%^%^CYAN%^complexion look the color of maggots under a dusk sun.  Magic seems to emanate from this Derro, and its gaze is directed at you!%^RESET%^");
   set_ac(0);
   set_property("no bows",1);
   set_property("swarm",1);
   set_size(2);
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
   new(OBJ"ssecari.c")->move(TO);
   command("wield dagger");
   ob=new("/d/common/obj/rand/randrobe.c");
   ob->move(TO);
   ob->set_size(2);
   force_me("wear robes");
   set_property("add kit", 25);
   ob=new("/d/magic/scroll");
   ob->set_spell(9);
   ob->move(TO);
   set_spell_chance(80);
   set_spells(({"magic missile","acid arrow","lightning bolt","magic missile","magic missile","magic missile","ray of enfeeblement","meteor swarm"}));
   set_emotes(15,({
      "%^CYAN%^Derro savant calls for reinforcements and you can hear the sound of running feet!",
      "%^BOLD%^%^BLACK%^Savant suddenly glows with black power and reaches for your heart!",
      "%^BOLD%^%^YELLOW%^Lightning crackles in a shield around the Savant!%^RESET%^"
   }),1);
}

void init(){
   ::init();
   if(TP->query_invis()&&!avatarp(TP)){
      tell_room(ETO,"%^BOLD%^%^BLACK%^Derro savant calls on his magic to deal with his foes!%^RESET%^");
      TP->set_invis();
      kill_ob(TP,1);
   }
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("snake",ETO)){
      new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,query_level(),100,"mage");
   }
   if(present("horse",ETO)){
      command("kill horse");
   }
}