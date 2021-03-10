#include "/d/islands/giant/giant.h"

inherit MONSTER;

int clothes= random(2)+1;
void create(){
   ::create();
   set_name("Hill Giant Kid");
   set_id(({"kid","giant","giant kid","ugly mofo"}));
   set_short("%^ORANGE%^Hill Giant Child%^RESET%^");
   set_long(
@TERRATO
   %^ORANGE%^This is one of the many younge children of this particular
Hill Giant clan.  They are raised to hate all that is not a giant, and
are fierce combatants from a very younge age due to thier heritage.
They engage in various battle games all day as thier only form
or entertainment.  They have a great time just hanging around
and beating the stufing out of eachother.
TERRATO
   );
   set_race("hill giant");
   set_body_type("human");
   set_hd((5+random(10)),10);
   set_exp(250*query_hd());
   set_size(4);
   set_stats("strength",18);
   set_stats("wisdom",6);
   set_stats("intelligence",5);
   set_stats("dexterity",13);
   set_stats("constitution",15);
   set_stats("charisma",5);
   set_class("fighter");
   set_guild_level("fighter",12);
   add_search_path("cmds/fighter");
   set_overall_ac(3);
   set_property("full attacks",1);
   set_alignment(3);
   set_emotes(5, ({
      "%^MAGENTA%^"+TO->query_cap_name()+" says%^WHITE%^: Are you my new TOY?",
      "%^BOLD%^"+TO->query_cap_name()+" smiles and wipes it's nose on it's sleeve",
   }),1);
   set("aggressive",18);
// new(
   switch(clothes){
      case 1:
         new(HOBJ+"kidcloth.c")->move(TO);
         break;
      case 2:
         new(HOBJ+"kidcloth2.c")->move(TO);
         break;
   }
   command("wield club");
   command("wear clothes");
}
