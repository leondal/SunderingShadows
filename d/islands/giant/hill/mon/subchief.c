#include "/realms/terrato/giant/giant.h"

inherit MONSTER;

void create() {
   ::create();
   set_name("Sub-Chief Browntooth");
   set_id(({"sub-chief","sub chief","sub","browntooth","Browntooth","giant","hill giant"}));
   set_short("%^ORANGE%^Sub-Chief Browntooth%^RESET%^");
   set_long(
@TERRATO
   %^ORANGE%^Sub-Chief Browntooth is Glacor's second in command and best
friend.  He is fanatically loyal to his Chief and would gladly lay down
his life to protect Glacor.  He wields a viscious looking club with
stunning fluidity, well, for a giant.%^RESET%^
TERRATO
   );
   set_race("giant");
   set_body_type("human");
   set_hd(20,10);
   set_max_hp(200);
   set_hp(200);
   set_exp(15000);
   set_size(4);
   set_stats("strength",19);
   set_stats("intelligence",15);
   set_stats("wisdom",17);
   set_stats("dexterity",11);
   set_stats("constitution",19);
   set_stats("charisma",10);
   set_money("gold",1300);
   set_money("silver",5400);
   set_class("fighter");
   set_guild_level("fighter",18);
   add_search_path("cmds/fighter");
   add_search_path("cmds/paladin");
   set_overall_ac(0);
   set_property("full attacks",1);
   set_alignment(3);
   set_emotes(20, ({
      "%^MAGENTA%^Browntooth says%^RESET%^: You will never touch the Chief!",
      "%^MAGENTA%^Browntooth says%^RESET%^: Your people will be our slaves!",
      "%^MAGENTA%^Browntooth says%^RESET%^: I will tan your flesh and wear it in winter!",
   }),1);
   set("aggressive","aggfunc");
   new(HOBJ+"sclub.c")->move(this_object());
   command("wield club in left hand and right hand");
}

void aggfunc(){
   command("say Prepare to die!");
   TP->kill_ob(TO,0);
}
