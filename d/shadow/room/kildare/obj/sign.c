#include <std.h>
#include "../kildare.h"
inherit OBJECT;

void create()
{
   ::create();
   set_name("sign");
   set_short("A small wooden sign");
   set_id(({"sign","sign post"}));
   set_long(
      "A wooden sign has been pounded into the ground here.  "+
      "It has some faded writing on it that you could read."
      );
   set("read",
@CIRCE
%^BOLD%^%^CYAN%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

                   %^RESET%^%^GREEN%^Kildare Glen

%^BOLD%^%^CYAN%^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
CIRCE
   );
   set_weight(1000000);
   set_property("no animate",1);
   set_value(0);
}
