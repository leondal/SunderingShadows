
#include <std.h>
#include "/d/common/common.h"

inherit "std/room";
void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set("short", "Fighters storage");
    set("long", "Fighter things are kept here.\n");

}

void reset() {
   if(!present("gamedart999")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 2")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 3")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 4")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 5")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 6")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 7")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 8")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 9")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
   if(!present("gamedart999 10")) new("/d/shadow/room/city/cguild/fighter/dart")->move(TO);
 if (!present("weapsheath 1")) new(CSHEATH"sheath_randomizer")->move(TO);
 if (!present("weapsheath 2")) new(CSHEATH"sheath_randomizer")->move(TO);
 if (!present("weapsheath 7")) new(CSHEATH"sheath_randomizer")->move(TO);
 if (!present("weapsheath 8")) new(CSHEATH"sheath_randomizer")->move(TO);
 if (!present("weapsheath 9")) new(CSHEATH"sheath_randomizer")->move(TO);
 if (!present("weapsheath 10")) new(CSHEATH"sheath_randomizer")->move(TO);
}
