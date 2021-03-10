#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1c";

object *goblins;
int i;

void create() {
    ::create();
    set_long("%^ORANGE%^This corridor extends north and south, lined by stone walls on either side.  The "
"roof spans high above your head, supported by curved arches from both walls, decorated ornately but "
"covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  The floor beneath your feet is "
"perfectly flat, without rubble or upturned stones to impede your progress, though it is coated in still "
"more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  No windows mark this length of corridor, making it a "
"little darker here.  To the north, an expansive hall opens, and the corridor itself continues "
"southward.  It seems very %^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your "
"shoulders, making you feel a little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"3-1",
      "south" : ROOMS+"5-1",
    ]));
}

void reset(){
   ::reset();
   goblins = allocate(4);
   for(i=0;i<4;i++) {
     if(objectp(goblins[i])) { return; }
   }
   if(!random(3)) return;
   goblins[0] = new(MON+"gobshaman");
   goblins[0]->move(TO);
   goblins[1] = new(MON+"goblin");
   goblins[1]->move(TO);
   goblins[2] = new(MON+"goblin");
   goblins[2]->move(TO);
   goblins[3] = new(MON+"goblin2");
   goblins[3]->move(TO);
   for(i=1;i<4;i++) { goblins[0]->add_follower(goblins[i]); }
}
