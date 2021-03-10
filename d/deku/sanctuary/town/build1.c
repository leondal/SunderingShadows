#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^This is one of the many abandoned buildings in the city of %^RED%^Sanctuary%^BLACK%^."+
      " The area is covered in rubble from decrepit walls and pieces of the ceiling that"+
      " have caved in on the structure."
   );
   set_exits(([
      "north" : TOWN+"roadE2"
   ] ));
   set_items(([
      "rubble" : "There are rocks and chipped stones everywhere."
   ] ));
}
