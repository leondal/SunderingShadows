#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Bedroom on top of the tree");
   set_long("%^GREEN%^Bedroom on top of the tree%^RESET%^
You have stepped into a highly decorated bedroom. A large ornate bed sits "
      "quietly towards the east side of the room. Facing it is a mirror. "
      "Two windows open at the sides. You see as far as you can through "
       "the windows. A dressing table is placed beside the bed. A chest of "
      "drawers is towards the other side of the bed. The floor is also "
      "covered with a thick layer of carpet.");
   set_items( (["house":"The house is quite large and is built on the "
      "tree branches.",
      "windows":"You can see the other parts of the house through the "
      "windows.",
      "carpet":"These beautiful carpets are made by craftsmen in Tonovi.",
      "bed":"It is made of brass and covered in gold.",
      "mirror":"A large mirror. You can see yourself inside it.",
      ({"table","dressing","dressing table","dresser"}):"There is nothing "
      "on the wooden table.",
      "chest":"It is an chest with six drawers arranged from in a column.",
      "drawers":"They are part of the chest.",
      "lamp":"The only source of light in the room."]) );
   set_smell("default","Smells of perfume fill your nostrils.");
   set_listen("default","It is quiet here.");
   set_exits( (["northwest":RPATH1+"1five2",
      "southwest":RPATH1+"1five5"]) );
}

void reset() {
   ::reset();
   if(!present("naxterr",find_object_or_load(RPATH1+"1five1")) &&
   !present("naxterr",find_object_or_load(RPATH1+"1five2")) &&
   !present("naxterr",find_object_or_load(RPATH1+"1five3")) &&
   !present("naxterr",find_object_or_load(RPATH1+"1five5")) &&
   !present("naxterr"))
      new(MPATH+"naxterr")->move(TO);
}
