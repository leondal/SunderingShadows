#include <std.h>
#include "../tormdefs.h"
inherit BATH;
void create(){
  ::create();
  set_long(
  "  You stand in the northeast corner of the bathhouse of Torm."
    "  West of you the marble deck runs to a curtained off room, while south of you lies the entrance."
  "  There are many pegs and shelves here with the clothes of the bathers on them."
   "  To the east is a door that is marked as a sauna, with a sign hanging from"+
   " it asking people to please keep it shut so the steam does not escape."
  );
   set_door("door",TCITY+"c158","east","Torm masterkey");
  set_exits(([
  "south":TCITY+"c113",
  "west":TCITY+"c115",
   "east" : TCITY+"c158",
  ]));
}
