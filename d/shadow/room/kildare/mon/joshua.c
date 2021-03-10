#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("joshua");
   set_id(({"joshua","man","tanner"}));
   set_short("Joshua, a tanner");
   set_long(
      "Joshua's face is tanned and leathery although he seems to be "+
      "only in his thirties.  He spends most of his time outdoors here "+
      "working on his craft.  He wears a leather apron with pockets full "+
      "of knives and scrapers over a plain blue tunic and leather breeches.  "+
      "A wedding band on his left hand binds him to his wife, who is also "+
      "his partner in the trade."
      );
   set_gender("male");
   set_race("human");
   set_body_type("humanoid");
   set_hd(12,4);
   set_stats("strength",14);
   set_exp(1);
   set_emotes(1,({
      "Joshua scrapes fur from one of the skins on the table.",
      "Joshua shapes the edges of a skin with a sharp knife.",
      "Joshua removes fat and other deposits from the underside of a skin with his knife."
      }),0);
}
