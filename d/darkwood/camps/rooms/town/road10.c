#include <std.h>
#include "../../elfisland1.h";
inherit BTOWN;

void create() {
   ::create();
   set("long",
      "%^RESET%^%^GREEN%^This path starts off as a narrow passageway from the clearing to the northeast"+
      " but opens up into wide trail the further you head southwest. To the southwest the thick of the"+
      " forest spreads further and further from the path. As you look up, you can see several platforms"+
      " extending from the trees that once created the broder for the path. The boundary is replaced"+
      " by tall grass that edges"+
      " around the path."
   );
   set_items( ([
      "grass":"Tall grass edges around the border of the path." 
   ]) );
   set_exits( ([
      "northeast" : TOWN+"center",
      "northwest" : TOWN+"road12",
      "southwest" : TOWN+"road11",
   ]) );
}
