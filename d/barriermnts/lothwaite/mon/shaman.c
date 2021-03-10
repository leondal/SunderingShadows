//shaman.c - Shaman for the firbolg chapel.  Circe 10/18/04
#include <std.h>
#include "../lothwaite.h"
inherit NPC;

void create()
{
   ::create();
   set_name("murchadh");
   set_id(({"murchadh","Murchadh","shaman","Shaman"}));
   set_short("Murchadh, Shaman of Lothwaite");
   set_long("This aging firbolg is the spiritual counsellor for the "+
      "village of Lothwaite.  His %^BOLD%^sky blue eyes %^RESET%^"+
      "%^CYAN%^are clouded, and it is clear from his ever-outstretched "+
      "hands that his sight has long since faded.  Long, grizzled "+
      "%^RESET%^gray hair %^CYAN%^flows down his back, bound only "+
      "by a simple %^ORANGE%^braided cord%^CYAN%^.  He is always "+
      "dressed in a well-made robe of layered linen colored in all "+
      "shades of blue from %^BOLD%^nearly white sky blue %^RESET%^"+
      "%^CYAN%^to the darkest %^BLUE%^midnight blue%^CYAN%^.  Each "+
      "robe bears embroidery of various symbols associated with the "+
      "%^BOLD%^%^WHITE%^Goddess of the Winds%^RESET%^%^CYAN%^, from "+
      "simple %^RESET%^clouds %^CYAN%^to the most intricate %^BOLD%^"+
      "%^BLUE%^birds%^RESET%^%^CYAN%^.  He spends much of his time "+
      "praying and tending to the temple, though he answers questions "+
      "asked of him and offers guidance to the people of the town."
   );
   set_gender("male");
   set_race("firbolg");
   set_hd(18,5);
   set_alignment(2);
   set_max_hp(200+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-6);
   set_class("cleric");
   set_mlevel("cleric",18);
   set_level(18);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",16);
   set_stats("intelligence",14);
   set_stats("charisma",14);
   set_stats("dexterity",12);
   set_exp(500);
   set_spells(({
   "limb attack",
   "cause blindness",
   "hold person",
   "winds of akadi",
   "airbolt"
   }));
   set_spell_chance(75);
   set("aggressive",0);
}

void reset(){
   ::reset();
   if(query_night()){
      tell_room(ETO,"%^BOLD%^%^GREEN%^Murchadh yawns lightly and turns to leave.");
      TO->move("/d/shadowgate/void");
      destruct(TO);
   }
}
