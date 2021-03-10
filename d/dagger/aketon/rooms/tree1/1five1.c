#include "/d/dagger/aketon/short.h"

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("Stairways");
   set_long("%^GREEN%^Stairways%^RESET%^
You have reached almost the top of the giant tree. A house is build here. "
      "From the beautiful decorations you guess this house is probabily "
      "belong to someone very important. Look out of the windows you can "
      "see the other parts of the house to your east and west also. The "
      "house was built entirely on the branches of the tree with some "
      "wooden supports below the floor. The floor is covered by some "
      "thick carpet. Rails around the staircase are also covered in gold. "
      "Some framed drawings hang quietly on the wall by the windows.");
   set_items( (["house":"The house is quite large and is built on the "
      "tree branches.",
      "windows":"You can see the other parts of the house through the "
      "windows.",
      "supports":"It is under your feet through the floor, use infrared.",
      "carpet":"These beautiful carpets are made by craftsmen in Tonovi.",
      "rails":"Gold covered handrails. You saw anywhere before?",
      "drawings":"These are the drawings of the mayors of Aketon."]) );
   set_smell("default","Smells of perfume fills your nosetrils.");
   set_listen("default","It is quiet here.");
   set_exits( (["up":RPATH1+"1top",
      "down":RPATH1+"1four1",
      "north":RPATH1+"1five2",
      "west":RPATH1+"1five3"]) );
   find_object_or_load(RPATH1+"1five2");
   find_object_or_load(RPATH1+"1five3");
   find_object_or_load(RPATH1+"1five4");
   find_object_or_load(RPATH1+"1five5");
}
