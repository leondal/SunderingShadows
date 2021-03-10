#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^You can guess that this was a storage area,"+
      " from all the broken crates, for whatever was being sold to the south."+
      " The area is covered in rubble from decrepit walls and pieces of the ceiling that"+
      " have caved in on the structure."
   );
   set_exits(([
      "south" : TOWN+"general"
   ] ));
   set_items(([
      "rubble" : "There are rocks and chipped stones everywhere."
   ] ));
}
