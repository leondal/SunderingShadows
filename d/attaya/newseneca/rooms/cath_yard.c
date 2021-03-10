//cath_yard.c - entrance to the cathedral
//for new Seneca ~Circe~ 11/13/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create() {
   ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_name("Pathway to the Cathedral");
   set_short("Pathway to the Cathedral");
   set_long("%^BOLD%^Pathway to the Cathedral, Seneca%^RESET%^\n"+
      "Leading across the %^GREEN%^beach grass %^RESET%^poking through the "+
      "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n sand "+
      "that covers the ground here is a %^BOLD%^pristine cobblestone "+
      "path%^RESET%^.  Unlike the colored stones that make up the broad "+
      "thoroughfares of this beautiful city, the stones for this pathway "+
      "were chosen for their %^BOLD%^pure white s%^RESET%^h%^BOLD%^e%^RESET%^e"+
      "%^BOLD%^n %^RESET%^kept magically clean despite the large number "+
      "of feet that traverse it daily.  The %^BOLD%^sa%^RESET%^n%^BOLD%^d"+
      "st%^YELLOW%^o%^BOLD%^%^WHITE%^ne %^RESET%^w%^BOLD%^al%^YELLOW%^l"+
      "%^BOLD%^%^WHITE%^s %^RESET%^protect this small pathway on three sides, "+
      "with the impressive %^BOLD%^bell tower %^RESET%^rising to the south.  "+
      "The walls are liberally plated with %^BOLD%^silver %^RESET%^and "+
      "highlighted with %^YELLOW%^gold%^RESET%^, emphasizing the wealth "+
      "and care of this particular building.  Directly to the west is a "+
      "pair of open %^BOLD%^archways %^RESET%^separated by a %^BOLD%^silver "+
      "column%^RESET%^.  Above the arched entrance is a %^YELLOW%^golden panel "+
      "%^RESET%^sculpted in relief with the image of four %^BOLD%^silver "+
      "columns %^RESET%^supporting archways, through which an %^YELLOW%^"+
      "altar room%^RESET%^ is visible.  Shattering this serene white facade "+
      "are numerous huge %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
      "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
      "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
      "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^with their riot of color.  The "+
      "windows march along the length of the cathedral, creating a "+
      "%^BOLD%^d%^CYAN%^a%^WHITE%^z%^CYAN%^z%^WHITE%^l%^CYAN%^i%^WHITE%^n"+
      "%^CYAN%^g %^RESET%^effect.\n");
   set_exits(([
      "west" : ROOMS"cath_foyer",
      "east" : ROOMS"skyline46"
   ]));
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"grass","beach grass","sand","golden sand"}) : "The soft "+
         "%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^WHITE%^e%^RESET%^n sand "+
         "that covers the ground here is broken by stiff %^GREEN%^beach grass "+
         "%^RESET%^coarse both to look at and to touch.",
      ({"path","pathway","cobblestone path","cobblestone"}) : "A wide "+
         "%^BOLD%^cobblestone pathway %^RESET%^leads through the %^GREEN%^"+
         "beach grass %^RESET%^between the main thoroughfare to the east "+
         "and the entrance to the %^BOLD%^cathedral %^RESET%^to the west.  "+
         "The stones are smooth and pristinely white - so white they seem to "+
         "repel any dirt that touches them.",
      ({"tower","bell tower"}) : "The bell tower to the south quickly rises "+
         "out of clear view this close up.  It features several open archways "+
         "on its side, allowing brief glimpses of stairways within.",
      ({"wall","walls"}) : "Each of the walls is made of smooth sandstone blocks, "+
         "fitted so well that there are no cracks or seams to be seen.  Along the "+
         "corners of the walls and in other appropriate places, %^YELLOW%^gold "+
         "%^RESET%^or %^BOLD%^silver %^RESET%^has been set to add detail "+
         "to the cathedral.",
      ({"archway","archways","doorway","door"}) : "No doorways close off this "+
         "grand building from the streets of Seneca.  Instead, twin archways "+
         "allow entry into a foyer so that all may access the holy place "+
         "at any time of day or night.  The archways are separated only by "+
         "a fluted %^BOLD%^column of silver%^RESET%^ and are set below a "+
         "%^YELLOW%^golden panel%^RESET%^.",
      ({"panel","golden panel"}) : "%^YELLOW%^The golden panel has been "+
         "sculpted in relief, showing four %^WHITE%^silver columns %^YELLOW%^"+
         "supporting archways.  Through the archways, an altar room is visible, "+
         "complete with several bowed heads facing the altar.%^RESET%^",
      ({"windows","stained glass windows","stained glass","window"}) : "Each "+
         "of the %^BOLD%^%^GREEN%^s%^RESET%^%^CYAN%^t%^BOLD%^%^BLUE%^"+
         "a%^CYAN%^i%^YELLOW%^n%^RED%^e%^MAGENTA%^d %^CYAN%^g%^YELLOW%^l%^BLUE%^a"+
         "%^GREEN%^s%^MAGENTA%^s %^RED%^w%^YELLOW%^i%^CYAN%^n%^GREEN%^d%^WHITE%^o"+
         "%^BLUE%^w%^RESET%^%^CYAN%^s %^RESET%^is a veritable riot of color, "+
         "breaking the almost dull serenity of the rest of the cathedral.  "+
         "The windows are graceful arching curves ending in points at the "+
         "top.  Each window features countless small colored panels of different "+
         "shapes and sizes."
   ]));
}
