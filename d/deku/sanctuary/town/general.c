#include <std.h>
#include "../dragon.h";
     
inherit BTOWN;
      
void create() {
   ::create();
   set_light(0);
   set_indoors(1);
   set_short("Ruined building");
   set_long(
      "%^BOLD%^%^BLACK%^Above a wrecked counter a sign reads %^RED%^'Sanctuary Traders' Hall'%^BLACK%^."+
      " That is the only thing that remains intact in this hall, that was once a shop. The"+
      " walls of this area are in such bad condition that they can barely be called walls."+
      " Everything from the counter to the shelves are strewn about."+
      " The hall leads north into an abandoned storage space and east into"+
      " what appeared to be the town stable house. A pair of heavy wooden"+
      " doors lay in pieces to the east."
   );
   set_exits(([
      "south": TOWN+"roadE1",
      "north": TOWN+"tchamber",
      "east": TOWN+"stable"
   ]));
   set_items(([
      "shelves":"These shelves are broken in half and hold decaying, worthless goods."
   ] ));
}
