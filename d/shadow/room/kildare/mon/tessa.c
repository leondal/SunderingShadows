#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("tessa");
   set_id(({"tessa","woman","lady","tanner"}));
   set_short("Tessa, a tanner");
   set_long(
      "Tessa is a young woman in her thirties with long chestnut brown "+
      "hair pulled up into a ponytail.  She wears a leather apron over "+
      "a simple white tunic and brown pants.  She has bright emerald "+
      "eyes that seem to sparkle, and she has a ready smile.  She has a "+
      "rosy complexion that seems to resist all attempts of the sun to tan "+
      "it.  The wedding ring she wears ties her to her partner and husband."
      );
   set_gender("female");
   set_race("human");
   set_body_type("humanoid");
   set_hd(12,3);
   set_stats("strength",12);
   set_exp(1);
   set_emotes(1,({
      "Tessa rubs salt on the skins drying on the racks.",
      "Tessa lifts a bucket of ash and coats one of the skins.",
      "Tessa rubs oil into one of the skins that is nearly finished."
      }),0);
}
