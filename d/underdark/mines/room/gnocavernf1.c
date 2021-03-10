//Octothorpe (1/25/09)
//Underdark Mining Caverns, Svirfneblin Boss Room

#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",1);
   set_property("no teleport",1);
   set_travel(DECAYED_FLOOR);
   set_terrain(BUILT_TUNNEL);

   set_name("A large, hollowed out chamber");
   set_short("A large, hollowed out chamber");
   set_long("A large, hollowed out chamber\n "+
      "This large void in the limestone is the epicenter of the "+
      "svirfneblin mining efforts in the area. The svirfneblin have "+
      "cleverly carved out natural ramps along the walls of the chamber "+
      "that lead up to rich veins of faerzress-infused ore. In keeping "+
      "with the surrounding environs, a muted %^GREEN%^g%^RESET%^"+
      "%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w %^RESET%^serves as "+
      "a source of some light for the chamber. A circle of runes are "+
      "inscribed on the floor in the middle of the chamber, enclosing "+
      "a pile of assorted rocks.\n");
   set_items(([
      ({"void","chamber"}):"The area grew out of the tunnel exacavation "+
         "in the nearby area. The ceiling of this chamber is around fifty "+
         "feet in height. No conventional scaffolding is present, which "+
         "would lead you to believe that the gnomes carved out the "+
         "sloping ramps along the walls to serve the same purpose. "+
         "The walls are awash in the eerie %^GREEN%^g%^RESET%^"+
         "%^MAGENTA%^l%^BOLD%^o%^RESET%^%^GREEN%^w %^RESET%^coming "+
         "from the exposed faerzress.",
      "ramps":"These ramps have been carved out of the limestone and "+
         "spiral up the walls of the chamber. Most of the ramps lead "+
         "up to exposed veins of ore and faerzress.",
      ({"runes","pile of rocks","rocks","floor"}):"A small pile of rocks "+
         "are found on the floor in the middle of the chamber. "+
         "Everything from the limestone found in the cavern complex, "+
         "%^BOLD%^%^WHITE%^gra%^BLACK%^ni%^WHITE%^te%^RESET%^%^ORANGE%^, "+
         "sandstone%^RESET%^, and basalt are to be found in this pile. "+
         "Circumscribed around the pile is a band of mysterious runes. "+
         "The language is indiscernable to you, but most likely is some "+
         "sort of svirfneblin dialect.",
   ]));
   set_exits(([
      "northeast":RMS"gnocaverne2",
   ]));
   set_smell("default","A cloud of calcite nearly chokes your lungs.");
   set_listen("default","You can hear the crumbling of limestone and "+
      "the clanging of metallic tools.");
}

void reset(){
   ::reset();
   if(!present("svirfneblin")){
      new(MON+"gnominer2")->move(TO);
      new(MON+"gnominer2")->move(TO);
      new(MON+"gnowarr2")->move(TO);
   }
   if(!present("pietram")){
      new(MON+"gnowarden")->move(TO);
   }
}