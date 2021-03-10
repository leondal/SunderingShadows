#include <std.h>
#include "../kildare.h"
inherit MONSTER;

void create()
{
   ::create();
   set_name("thalia");
   set_id(({"thalia","girl","child","little girl"}));
   set_short("Thalia, a little girl");
   set_long(
      "Thalia is a young girl around four years of age.  She is "+
      "dressed in a simple, pale yellow dress that sets off her "+
      "rosy cheeks and emerald green eyes.  Her black hair has "+
      "been pulled into pigtails that curl down near her ears.  "+
      "She is never without a worn rag doll, which she often "+
      "sits down to play with."
      );
   set_gender("female");
   set_race("human");
   set_body_type("humanoid");
   set_hd(1,10);
   set_stats("strength",4);
   set_exp(1);
   set_emotes(1,({
      "Thalia bounces the doll along her knee, humming quietly.",
      "Thalia straightens the doll's dress and brushes back her hair.",
      "Thalia grins to herself as she talks gibberish with her doll."
      }),0);
}
