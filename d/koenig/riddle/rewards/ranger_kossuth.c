//ranger_kossuth.c - Reward for Riddle Quest.  Circe 1/27/04
#include <std.h>
#include "../../nereid.h"

inherit NBOW;

void create(){
   ::create();
//   set_name("kossuth bow");
   set_id(({"red longbow","bow","longbow","long bow","wrath","wrath of flame","flame"}));
   set_obvious_short("A smoldering red longbow");
   set_short("%^BOLD%^%^RED%^Wrath %^YELLOW%^of %^RED%^Fl%^YELLOW%^a%^RED%^me%^RESET%^");
   set_long(
@CIRCE
%^RED%^This unusual longbow has been made of deep red cherry wood.  The suface of the bow is smooth, but writhing underneath the surface is a seething mass of %^BOLD%^fl%^YELLOW%^a%^RED%^mes%^RESET%^%^RED%^ that seem to flicker and move with the wind.  The bow appears to have a life of its own that feeds off the feelings of its master.  The top end of the bow has been set with a gilded flame to which the reddish string is attached.
CIRCE
   );
   set_lore(
@CIRCE
Rangers of the Firelord generally keep long-term goals in mind when tending to the wild lands of the realms.  They realize that at times, fire must be used to burn areas so that they may regrow.  Sometimes this puts them at odds with other rangers, who believe that the woodlands should be left to themselves for the most part.  The bowmen of Kossuth are enamored with this weapon, which is thought to have been blessed by the Lord of Flames himself.  It reappears in the hands of a worthy ranger when the time is right.  No mortal now living knows the secrets of its construction.
CIRCE
   );
   set_property("lore difficulty",12);
	set_unwield("%^RED%^The warmth of the flames leaves your veins as you lower the bow.");
}