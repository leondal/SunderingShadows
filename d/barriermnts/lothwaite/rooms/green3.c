//Village Green for Lothwaite.  Circe 9/18/04
#include <std.h>
#include "../lothwaite.h"

inherit STORAGE"green";

void create(){
   ::create();
   set_long( ::query_long()+"  A tall %^ORANGE%^wooden pole %^GREEN%^"+
      "stands on a low mound here.  You can see the ends of %^BOLD%^"+
      "%^MAGENTA%^r%^CYAN%^i%^BLUE%^b%^GREEN%^b%^MAGENTA%^o%^CYAN%^n"+
      "%^BLUE%^s %^RESET%^%^GREEN%^waving on the breeze from its tip.\n");
   add_item(({"pole","wooden pole","ribbons"}),"Used in a springtime "+
      "festival, this pole is decorated each spring with ribbons, which "+
      "the young girls of the village weave around the pole's base.  "+
      "Spring is seen as a time of celebration after the harsh winters "+
      "brought by Auril, and no firbolg maiden would dare miss this "+
      "joyful celebration.");
   set_exits(([
      "south" : PATHEXIT"green1",
      "east" : PATHEXIT"green4",
      "southeast" : PATHEXIT"green2"
   ]));
}