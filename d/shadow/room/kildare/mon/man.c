#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("man");
   set_id(({"man","human","warrior","villager"}));
   set_short("A village warrior");
   set_long(
      "This man appears to be in his early twenties.  He has dark "+
      "brown hair shorn close around the sides and pulled back into "+
      "a topknot.  His vivid green eyes are intelligent and focused, "+
      "and his build suggests that he is used to hard work.  His hands "+
      "are calloused, and his cheeks ruddy from the mountain air.  He "+
      "has a quiver at his back, and a long sword sheathed at his side.  "+
      "He is dressed in dark brown suede breeches and a simple white tunic."
      );
   set_gender("male");
   set_race("human");
   set_body_type("humanoid");
   set_hd(10,3);
   set_stats("strength",14);
   set_exp(1);
   set_emotes(1,({
      "The warrior sharpens a knife on a whetstone.",
      "The warrior pulls an arrow from his quiver and repairs the fletchings."
      }),0);
}
