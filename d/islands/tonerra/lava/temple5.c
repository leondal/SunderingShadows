#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

void create(){
  ::create();
  set_indoors(1);
  set_light(1);
  set_property("no teleport",1);
  set_property("used sticks",1);
  set_short("The guardian's house");
  set_long(
@DESC
   %^BOLD%^%^RED%^The guardian's house%^RESET%^
This room is the home of the powerful creatures of Ibrandul.
It would appear that either these creatures have lived a long
time without thier lord or that he still exists. Yes that is
correct before you stand two of the God Ibrandul's creations,
Ibrandlins.
DESC
  );
  set_listen("default","The sound of Lava has stopped here.");
  set_smell("default","You smell the excrement of the ibrandlins");
  set_exits(([
    "out":LAVA+"temple4",
    "deeper":LAVA+"temple6"

  ]));

  set_pre_exit_functions(({"deeper","out"}),({"GoThroughDoor","GoThroughDoor"}));
}

void reset(){
   ::reset();

   if(!present("ibrandlin")){
      new(MON+"ibrandlin")->move(TO);
   }
   if(!present("ibrandlin 2")){
      new(MON+"ibrandlin")->move(TO);
   }

}

int GoThroughDoor(){
   if(present("ibrandlin")){
      write("The Ibrandlin blocks your passage easily.");
      return 0;
   }
   return 1;
}

