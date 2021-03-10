//shawm.c - For instrument file coded by Circe 11/28/03
#include <std.h>
inherit "/d/common/obj/instruments/instrument_inherit.c";

void create()
{
   ::create();
   set_name("shawm");
   set_short("A wooden shawm");
   set_id(({"shawm","wooden shawm","instrument"}));
   set_long("Resembling a wooden scepter, this double-reeded wind instrument "+
      "has eight finger holes and is around 28 inches in length.  This shawm "+
      "is intricately carved and appears quite valuable.  It produces an extremely "+
      "loud sound and has a deep, reedy tone.  Mastering a shawm can be quite "+
      "difficult.");
   set_weight(4);
   set_value(800);
   set_lore("Like the hautbois, the shawm is prized among aristocrats who see "+
      "it as something of a status symbol.  Many young nobles take up the shawm "+
      "and learn to become decent, if not adept, with it.  It is said that treants "+
      "adore the sound of the shawm almost as much as their own crumhorns.");
}

