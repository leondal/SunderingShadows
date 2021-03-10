//updated to current standards, including size, etc. ~Circe~ 7/31/19

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
   set_long("%^CYAN%^With skin the color of an iced-over lake and pupilless, staring eyes, this degenerate creature looks out of place in these giant halls.  The ever-present %^RED%^red glow %^CYAN%^makes the creature's %^RESET%^white%^CYAN%^/%^BOLD%^blue %^RESET%^%^CYAN%^complexion look the color of maggots under a dusk sun.  They have features of both human and dwarf, reminding each race of the other when they see these evil creatures.%^RESET%^");
   set_ac(0);
   set_property("swarm",1);
   set_size(2);
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_class("mage");
   set("aggressive",15);
   add_attack_bonus(2);
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
   ob=new("/d/common/obj/rand/randrobe.c");
   ob->set_size(2);
   ob->move(TO);
   if(flag>3) ob->set_property("monsterweapon",1);
   force_me("wear robe");
   set_property("add kits",10);
   set_spell_chance(80);
   set_spells(({"magic missile","acid arrow","lightning bolt","ray of enfeeblement"}));
   set_emotes(15,({
      "%^CYAN%^Derro savant calls for reinforcements and you can hear the sound of running feet!",
      "The student starts chanting in a low and mournful tone!"
   }),1);
}

void heart_beat(){
   ::heart_beat();
   if(!objectp(TO) || !objectp(ETO)) return;
   if(present("snake",ETO)){
      new("/cmds/spells/d/_dispel_magic")->use_spell(TO,0,query_level(),100,"mage");
   }
}
