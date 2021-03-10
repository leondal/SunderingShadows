//cath_workroom.c 
//for new Seneca ~Circe~ 06/01/08
#include <std.h>
#include "../seneca.h"

inherit ROOM;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Workroom of the Cathedral, Seneca");
   set_short("Workroom of the Cathedral, Seneca");
   set_long("%^BOLD%^Workroom of the Cathedral, Seneca%^RESET%^\n"+
      "Far from a typical %^BOLD%^%^RED%^forge %^RESET%^or a room "+
      "dedicated to a specific craft, this workroom has been "+
      "arranged to provide space and %^BOLD%^tools %^RESET%^"+
      "for many types of professions.  In the northeastern "+
      "corner stands a series of %^ORANGE%^potter's wheels "+
      "%^RESET%^by a top-loading %^ORANGE%^kiln %^RESET%^with a "+
      "%^BOLD%^%^BLACK%^slate-tiled top%^RESET%^.  A workbench "+
      "in that section of the room provides ample space for "+
      "working clay as well as storage room for various %^BOLD%^"+
      "sponges%^RESET%^, %^ORANGE%^brushes%^RESET%^, %^RED%^"+
      "paints%^RESET%^, and other tools.  A collection of "+
      "%^BOLD%^looms %^RESET%^in the western portion of the room "+
      "is arranged around several low %^ORANGE%^stools%^RESET%^ "+
      "while %^YELLOW%^wicker baskets%^RESET%^ there provide "+
      "storage for sewing materials.  The southern part of the "+
      "room is a hodge podge of other crafts.  There, %^ORANGE%^"+
      "wooden stands %^RESET%^for drying skins rest among small "+
      "%^BOLD%^%^BLACK%^tool cases %^RESET%^for all sorts of "+
      "minor repairs such as those for armor, weapons, or jewelry.  "+
      "It looks as though one could find most any supply needed "+
      "for a craft here.\n");
   set_exits(([
      "west" : ROOMS"cath_hall1"
   ]));
   set_smell("default","The light fragrance of beeswax fills the air.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"wall","walls"}) : "%^BOLD%^%^WHITE%^The stone walls are "+
         "smooth and whitewashed for a pristine appearance.%^RESET%^",
      "floor" : "The smooth stone floor was hewn at one point but "+
         "has also been worn by countless feet over the years, "+
         "making it seem almost soft.",
      ({"wheel","wheels","potter's wheels","potter's wheel","potters wheels","potters wheel"}) :
         "The potter's wheels are in various sizes but are all "+
         "operated by means of a foot pedal that allows some "+
         "control in how quickly the wheel spins.  The monks "+
         "seem to keep the wheels impeccably clean.",
      ({"bench","benches","workbench","workbenches"}) : "Several "+
         "workbenches are spread around the room, offering plenty "+
         "of space for many different people to work at once.  Each "+
         "surface is kept clear except when in use, so that one "+
         "person is never cleaning up another's mess.",
      ({"kiln","top-loading kiln"}) : "The kiln in the corner of "+
         "the room is a top-loading variety, making it easier "+
         "to stack it properly.  It is fitted with a top made "+
         "of %^BOLD%^%^BLACK%^slate %^RESET%^that can be "+
         "secured once the items are stacked inside.",
      ({"sponges","brushes","paints"}) : "The workbench in "+
         "the northeastern corner is fitted with shelves "+
         "underneath that hold a collection of materials to be "+
         "used when creating pottery.  Brushes and paints are "+
         "set among pots of glaze, and sponges and other "+
         "implements to mark pots are gathered in neat piles.",
      ({"looms","loom"}) : "%^ORANGE%^The wooden frames of "+
         "simple vertical looms stand in the northwestern portion "+
         "of the room, providing places for tailors to weave their "+
         "cloths.  A few of them have half-finished projects "+
         "loaded upon them while others stand empty.%^RESET%^",
      ({"stool","stools","baskets","wicker baskets"}) : "The "+
         "stools are simple four-legged affairs crafted at "+
         "different heights to allow a weaver to choose which "+
         "one is needed for work on a particular piece of cloth.  "+
         "Spread among them are a series of %^YELLOW%^wicker "+
         "baskets %^RESET%^that hold needles, scissors, and "+
         "other materials necessary for tailoring.",
      ({"stands","wooden stands","skins","drying skins"}) : "The "+
         "wooden stands in the southern part of the room are for "+
         "stretching and tanning drying skins.  A few of them are "+
         "in use, and you can see that they are mostly for smaller "+
         "skins such as rabbits and foxes rather than the larger "+
         "ones.  Like everything else produced here, the monks "+
         "use the skins within the cathedral or for their own "+
         "needs.",
      ({"cases","tool cases"}) : "Tool cases of every size and "+
         "shape are spread around the room, each one holding "+
         "tools needed for a particular task.  Some hold hammers, "+
         "brads, tongs, and other implements for metalworking, "+
         "while others hold a collection of leather-working "+
         "tools.  It looks as though you would be able to find "+
         "many different sorts of tools here."
   ]));
}
