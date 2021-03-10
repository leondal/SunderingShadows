
#include <std.h>

inherit "std/quest_ob";

string owner;

void create()
{
  ::create();
    set_name("Muileann Quest");
     set_id(({"Finished Shar's failed Deed","Stone Quest"}));
      set_short("Deku QO");
    set_long("This is a terrified little boy.");
    set_quest_points(20);
}

