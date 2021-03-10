#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1c";

object gob1,gob2;

void create() {
    ::create();
    set_long("%^ORANGE%^This corridor extends northward and turns to the east, lined by stone walls on "
"either side.  The roof spans high above your head, supported by curved arches from both walls, "
"decorated ornately but covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  The floor "
"beneath your feet is perfectly flat, without rubble or upturned stones to impede your progress, though "
"it is coated in still more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  No windows mark this length of "
"corridor, making it a little darker here.  The corridor itself continues into darkness in both "
"directions.  It seems very %^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your "
"shoulders, making you feel a little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"7-1",
      "east" : ROOMS+"8-2",
    ]));
}

void reset(){
   int i;
   ::reset();
   if(sizeof(children(MON"gobshaman")) < 4) {
     if(random(3)) return;
     gob1 = new(MON"gobshaman");
     gob1->move(TO);
     for(i=0;i<2;i++) {
       gob2 = new(MON"goblin");
       gob2->move(TO);
       gob1->add_follower(gob2);
     }
     gob2 = new(MON"goblin2");
     gob2->move(TO);
     gob1->add_follower(gob2);
   }
}
