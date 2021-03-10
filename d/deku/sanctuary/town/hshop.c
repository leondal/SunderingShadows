#include <std.h>
#include "../dragon.h";

inherit BTOWN;

void create() {
   ::create();
   set_property("light",0);
   set_property("indoors",1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^This is one of the many buildings destroyed beyond any recognition"+
      " in the town of %^RED%^Sanctuary%^BLACK%^."+
      " The area is covered in rubble from decrepit walls and pieces of the ceiling that"+
      " have caved in on the structure. Whatever happened here must have been horrible."
   );
   set_exits(([
      "west" : TOWN+"roadS2"
   ] ));
   set_items(([
      "rubble" : "There are rocks and chipped stones everywhere."
   ] ));
}
