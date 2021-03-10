#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Living area upon the tree");
   set_long("%^GREEN%^Living area upon the tree%^RESET%^
This room is not very well decorated. Some oil lamps, forks, dishes and "
      "many other things are placed onto a large dinning table. Six "
      "armchairs are next to the table. A single glass cupboard with many "
      "shelves displays a number of weird items. There is a four sitter couch here. "
       "A bearskin rug is on the floor. Some windows are open on the east side. An "
      "archway leads back to the corridors and another leads south into "
      "a large room.");
   set_items( (["lamps":"Some oil lamps made of ordinary copper.",
      "forks":"Some forks which you use in meals.",
      "dishes":"People use it to hold food.",
      "things":"Many things you will use in your daily life.",
      "table":"It is made of some hard wood. It is place in the center of "
      "the room.",
      "armchairs":"They are quite large and looks comfortable to sit on.",
      "cupboard":"With glass doors, many weird items are displayed there.",
      "items":"Some odd looking statues and other items you have never "
      "seen before.",
      "couch":"A four sitter couch covered with some pretty clothes.",
      ({"skin","sheet"}):"A sheet of bear skin placed on the floor before "
      "the couch.",
      "windows":"You can see the views outside.",
      "archway":"It leads to other room."]) );
   set_smell("default","You smell incense from the south.");
   set_listen("default","You hear sounds of the city from outside the "
       "windows.");
   set_exits( (["south":RPATH1+"1three21",
      "west":RPATH1+"1three16"]) );
}
