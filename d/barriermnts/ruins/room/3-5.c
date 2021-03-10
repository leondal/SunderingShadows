#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l1a";

object gob1,gob2;

void create() {
    ::create();
    set_long("%^ORANGE%^You are standing within an extensive hallway, set with strong pillars at " 
"regular intervals.  The roof reaches high above your head, supported by curved arches from these "
"pillars, decorated ornately but covered in a thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  "
"The floor beneath your feet is perfectly flat, without rubble or upturned stones to impede your "
"progress, though it is coated in still more %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Tall windows of "
"%^MAGENTA%^mu%^BLUE%^lt%^GREEN%^ic%^ORANGE%^ol%^RED%^ou%^MAGENTA%^re%^BLUE%^d%^ORANGE%^ glass are set "
"within the stone walls of the building, but they are %^BLACK%^%^BOLD%^darkened%^RESET%^%^ORANGE%^ with "
"dirt and hard to see through.  A corridor to the south leads away from the main hallway.  It seems very "
"%^BLUE%^lifeless%^ORANGE%^ here, though a heavy feeling rests upon your shoulders, making you feel a "
"little uneasy.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"2-5",
      "south" : ROOMS+"4-5",
      "west" : ROOMS+"3-4"
    ]));
}

void reset(){
   int i;
   ::reset();
   if(sizeof(children(MON"gobshaman")) < 4) {
     if(random(3)) return;
     gob1 = new(MON"gobshaman");
     gob1->move(TO);
     gob2 = new(MON"goblin");
     gob2->move(TO);
     gob1->add_follower(gob2);
     for(i=0;i<2;i++) {
       gob2 = new(MON"goblin2");
       gob2->move(TO);
       gob1->add_follower(gob2);
     }
   }
}
