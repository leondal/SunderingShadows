//updated to current standards, including size, etc. ~Circe~ 7/31/19

#include <std.h>
#include "../derrodefs.h"

inherit MONSTER;

object ob;
int flag;

void create(){
   ::create();
   set_name("derro warrior");
   set_id(({"derro","dwarf","fierce","fierce derro"}));
   set_race("dwarf");
   set_gender("male");
   set_short("%^RESET%^%^BLUE%^Fierce Derro%^BOLD%^%^RED%^%^");
   set_long("%^CYAN%^With skin the color of an iced-over lake and pupilless, staring eyes, this degenerate creature looks out of place in these giant halls.  The ever-present %^RED%^red glow %^CYAN%^makes the creature's %^RESET%^white%^CYAN%^/%^BOLD%^blue %^RESET%^%^CYAN%^complexion look the color of maggots under a dusk sun.  They have features of both human and dwarf, reminding each race of the other when they see these evil creatures.%^RESET%^");
   set_ac(4);
   set_property("swarm",1);
   set_size(2);
   set_mob_magic_resistance("average");
   set_body_type("human");
   set_class("fighter");
   set("aggressive",15);
   set_mlevel(15);
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
   add_money("gold",random(100));
   set_hp(75+random(75));
   set_max_hp(query_hp());
   set_exp(3000);
   ob=new(OBJ"aklys.c");
   flag=(random(20));
   if(flag>3)ob->set_property("monsterweapon",1);
   ob->move(TO);
   ob=new(OBJ"spikedbuckler.c");
   if(flag>2)ob->set_property("monsterweapon",1);
   ob->move(TO);
   command("wield club in left hand");
   command("wield buckler in right hand");
   switch(random(2)){
      case 0: ob=new("/d/common/obj/rand/rand_shirts.c");
              if(flag>2)ob->set_property("monsterweapon",1);
              ob->set_property("enchantment",1);
              ob->move(TO);
              command("wear shirt");
              break;
      default: ob=new(OBJ"kather.c");
               if(flag>2)ob->set_property("monsterweapon",1);
               ob->move(TO);
               command("wear kather");
               break;
   }
   set_emotes(15,({"%^RED%^Derro tries to get behind you!%^RESET%^"}),1);
}
