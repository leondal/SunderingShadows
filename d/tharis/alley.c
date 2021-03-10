//updated by Circe 11/1/04
#include <std.h>
#include "tharis.h"

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(BACK_ALLEY);
   set_property("light",2);
   set_name("Dark alley in Tharis");
   set_short("Dark alley in Tharis");
   set_long(
@JAVAMAKER
%^RED%^Dark alley through Tharis%^RESET%^
The high %^BOLD%^stone walls %^RESET%^block most of the %^YELLOW%^sun %^RESET%^from the street
in these back %^RED%^alleyways%^RESET%^.  The ground here is still %^BOLD%^stone %^RESET%^but
uncared for.  The broken stone is %^CYAN%^wet %^RESET%^to the step and it seems
that here is where the %^GREEN%^refuse%^RESET%^ and %^ORANGE%^offal%^RESET%^ get thrown.  %^GREEN%^Moss %^RESET%^grows 
in the cracks of the stone, making footing uncertain in places.  
The %^BOLD%^%^BLACK%^shadows%^RESET%^ move and shake, leaving you to wonder what might 
be hidden in these dark %^RED%^alleys%^RESET%^.
JAVAMAKER
   );
   set_smell("default","The smell here is awful.  The "+
      "refuse and the stench make you queasy.");
   set_listen("default","You hear a groan of some unfortunate soul.");
   set_items(([
      ({"stone","alley","alleyway","moss"}) : "The stones here "+
         "have not been tended since the erection of the walls "+
         "around them.  They are split and dirty with moss "+
         "growing in the cracks.",
      ({"refuse","offal"}) : "This is awful smelling stuff!  It's "+
         "been piled up over time and slowly is cleared away to the "+
         "sewers below.",
      ({"walls","wall","buildings"}) : "All around you rise the walls "+
         "of the buildings.  It is difficult to tell from here what "+
         "any of them might be, but they block the sunlight and cast "+
         "deep shadows upon the ground.",
      ({"shadow","shadows"}) : "%^BOLD%^%^BLACK%^Deep shadows move "+
         "in the alleyway, leaving you to wonder who...or what..."+
         "makes them."
   ]));
}

