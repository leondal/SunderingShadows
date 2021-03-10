#include "/d/islands/giant/giant.h"

inherit MONSTER;
int weapon= random(4) +1;

void create() {
   ::create();
   set_name("Hill Giant Grunt");
   set_id(({"grunt","giant","hill giant","hill giant grunt"}));
   set_short("%^ORANGE%^Hill Giant Grunt%^RESET%^");
   set_long(
@TERRATO
   %^ORANGE%^This is one of the common hill giant grunt who wanders
around the keep on guard duty.  They are usually not very alert
but have all the strength of a hill giant.%^RESET%^
TERRATO
   );
   set_race("giant");
   set_body_type("human");
   set_hd((9+random(5)),15);
   set_exp(500*query_hd());
   set_size(4);
   set_stats("strength",19);
   set_stats("intelligence",7);
    set_stats("wisdom",8);
   set_stats("dexterity",11);
   set_stats("constitution",20);
   set_stats("charisma",5);
   set_money("gold",random(400));
   set_money("copper",random(1000));
   set_class("fighter");
   set_guild_level("fighter",18);
   add_search_path("cmds/fighter");
   add_search_path("cmds/paladin");
   set_overall_ac(0);
   set_property("full attacks",1);
   set_alignment(3);
   set_emotes(20, ({
      "%^MAGENTA%^"+TO->query_cap_name()+" says%^RESET%^: Destroy the intruders!",
   }),1);
   set("aggressive","aggfunc");
   switch(weapon){
      case 1:
          new(HOBJ+"mace1.c")->move(TO);
         break;
      case 2:
          new(HOBJ+"mace2.c")->move(TO);
         break;
      case 3:
          new(HOBJ+"club1.c")->move(TO);
         break;
      case 4:
         new(HOBJ+"club2.c")->move(TO);
         break;
   }
   command("wield club");
   command("wield mace");
}

void aggfunc(){
   command("say Prepare to die!");
   TP->kill_ob(TO,0);
}
