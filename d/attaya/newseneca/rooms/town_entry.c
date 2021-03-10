#include <std.h>
#include "/d/attaya/newseneca/seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_name("City Gates, Seneca");
   set_short("%^BOLD%^%^BLACK%^City Gates, Seneca%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^City Gates, Seneca%^RESET%^\n"+
      "This broad entryway leads through the %^BOLD%^co%^MAGENTA%^"+
      "q%^WHITE%^ui%^BLACK%^n%^WHITE%^a walls %^RESET%^surrounding "+
      "the city.  A massive %^BOLD%^%^BLACK%^iron portcullis %^RESET%^"+
      "guards the northern side while a smaller %^ORANGE%^oaken "+
      "gate %^RESET%^set with an %^BOLD%^%^BLACK%^iron grate "+
      "%^RESET%^grants access to the streets of %^BOLD%^Seneca%^RESET%^.  "+
      "Despite the elegant facade of this Attayan city, the "+
      "heavy gates and the %^BOLD%^%^BLACK%^murder holes %^RESET%^"+
      "set within the ceiling remind visitors that this is a "+
      "city often under siege.  It looks as though both gates "+
      "may be sealed at a moment's notice, helping to protect the "+
      "citizens of %^BOLD%^Seneca%^RESET%^.\n");
   set_smell("default","The aroma of burnt oil seems to have permeated the
wooden floor.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in "+
         "Seneca can be heard.");
   }
   set_items(([
      ({"hole","holes","murder holes","murderholes"}) : "The wooden "+
         "ceiling is riddled with numerous holes blackened around "+
         "the edges.  Each hole is ringed with a slightly iridescent "+
         "sheen."
   ]));
   set_exits(([
      "north" : ROOMS"boardwalk3",
      "south" : ROOMS"street7"
   ]));
   set_door("gate","/d/attaya/newseneca/rooms/street7","south",0,0);
   set_door_description("gate","%^ORANGE%^To the south is the thick "+
      "%^BOLD%^%^BLACK%^iron-bound %^RESET%^%^ORANGE%^oaken gate that "+
      "grants entry to the city.  It has a very small window with "+
      "%^BOLD%^%^BLACK%^iron bars %^RESET%^%^ORANGE%^but is otherwise "+
      "solid.%^RESET%^");
  
set_door("portcullis","/d/attaya/newseneca/rooms/boardwalk3","north","Senec
gate key","lock");
   set_door_description("portcullis","The portcullis is made from %^ORANGE%^"+
      "oaken planks %^RESET%^plated and bound with %^BOLD%^%^BLACK%^iron"+
      "%^RESET%^.  It may be raised or lowered from inside the guard house "+
      "to the east by means of a series of pulleys and chains.");
   lock_difficulty("portcullis",-90, "lock");
   set_open("portcullis",1);
   set_lock_description("portcullis", "lock",
      "You cannot see the means to open the gate from here.");
   set_string("portcullis","open","Screeching, the porcullis shudders into
motion and rises.");
   set_string("portcullis","close","The portcullis shuts quickly, sliding
into place.");
}
void reset(){
   ::reset();
   if(!present("psion"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
   if(!present("psion 2"))new("/d/attaya/newseneca/mon/psi_guard")->move(TO);
   if(!present("Seneca Guard 3"))
    new("/d/attaya/newseneca/mon/city_guard")->move(TO);
   if(!present("Seneca Guard 4"))
    new("/d/attaya/newseneca/mon/city_guard")->move(TO);
}
