//updated by ~Circe~ 5/6/11 to inherit the base shield after bug reports
//that it didn't have a prof set.

#include <std.h>

inherit "/d/common/obj/armour/mshield.c";

void create(){
   ::create();
   set_name("mithril medium shield");
   set_id(({"mithril medium shield","shield","mithril shield","medium shield"}));
   set_short("A mithril medium shield");
/*   set_long("%^BOLD%^This is a bright shiney Mithril medium shield.
The emblem of the Dagger Reaches is on the front.
It was forged by the Dwarves of Mt. Sholkum.
This is the standard issue shield for the Army of the Dagger Reaches.");

Old description - updating ~Circe~
*/
   set_long("%^BOLD%^This shield seems to shine, no matter how much "+
      "dirt and filth collects on its surface. It is a simple design - "+
      "circular in shape with leather straps for the bearer to use. "+
      "Etched into the metal on the front is a crest of some sort, "+
      "a square stone arch with a rugged mountain carved on the "+
      "closed gates.%^RESET%^");
   set_lore("The symbol carved into this shield identifies it as "+
      "being crafted by the dwarves of Barak Morndin. This shield is "+
      "standard issue for the Army of the Dagger Reaches, which "+
      "is commissioned to protect the Shielded Stronghold from "+
      "invaders. As such, they occasionally send out scouting parties, "+
      "which is likely where this shield originated.");
   set_property("lore difficulty",10); 
   if(!random(2)){ set_property("enchantment", 1); }
}
