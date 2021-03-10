#include <std.h>
#include "../kildare.h"
inherit "/std/vendor";

void create()
{
   ::create();
   set_name("david");
   set_id(({"gstorekeeper","david","butcher","man"}));
   set_short("David, the Village Butcher");
   set_long(
      "This rotund man stands just under five and a half feet tall.  "+
      "He is rather young, but his black hair has already started "+
      "balding, and he has a small round baldpatch centered on the "+
      "back of his head.  He wears a plain blue cotton tunic with "+
      "tan suede pants, all underneath and enormous stark white apron.  "+
      "He has a ready smile and a twinkle in his eyes that speaks of "+
      "a youth spent in much mischief, though he seems to have settled "+
      "down to his life as the town butcher now.  Aside from the food "+
      "in his shop, he also keeps a few odds and ends that travelers "+
      "may need."
      );
   set_gender("male");
   set_race("human");
   set_body_type("humanoid");
   set_hd(10,5);
   set_stats("strength",16);
   set_exp(1);
   set("aggressive", 0);
   set_storage_room(STOR"butcher");
   set_items_allowed("misc");
   set_emotes(1,({
      "David sweeps around behind the counter, humming a merry tune.",
      "David squints slightly as he sharpens the cleaver.",
      "David grins and laughs to himself, shaking his head."
      }),0);
   set_nwp("skinning",10);
}
