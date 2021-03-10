#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
}

void reset() {
   ::reset();
   if(file_name(TO) == "/d/dagger/aketon/rooms/councilroom") {
      COUNCILOR_D->make_councilors();
   }
}
