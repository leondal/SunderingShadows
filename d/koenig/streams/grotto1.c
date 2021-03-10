//grotto1 - Connects to Nereid's cave for Riddle quest.  Circe 12/7/03
#include <std.h>
#include "../koenig.h"

inherit ROOM;

void create() {
    	::create();
      set_terrain(NAT_TUNNEL);
      set_travel(SLICK_FLOOR);
      set_property("indoors",1);
    	set_property("light",3);
    	set_short("A tunnel behind the waterfall");
    	set_name("A tunnel behind the waterfall");
    	set_long(
		"%^BOLD%^%^CYAN%^The spray of the %^RESET%^%^CYAN%^waterfall "+
            "%^BOLD%^%^CYAN%^cascading down the %^BOLD%^%^BLACK%^rock wall "+
            "%^BOLD%^%^CYAN%^to the west hides the stream outside from view.  "+
            "Here in the tunnel, the walls are surprisingly made of "+
            "%^BOLD%^%^CYAN%^m%^WHITE%^i%^RESET%^c%^CYAN%^a %^BOLD%^%^CYAN%^"+
            "that seems to %^BOLD%^%^WHITE%^s%^RESET%^p%^BOLD%^a%^RESET%^r"+
            "%^BOLD%^k%^RESET%^l%^BOLD%^e %^BOLD%^%^CYAN%^with a %^YELLOW%^radiance "+
            "%^BOLD%^%^CYAN%^all its own.  The cave arches overhead where "+
            "small deposits of %^YELLOW%^topaz %^BOLD%^%^CYAN%^shimmer, "+
            "surrounded by patches of %^BOLD%^%^GREEN%^phosphorescent moss "+
            "%^BOLD%^%^CYAN%^that provide a gentle light to the cavern.  "+
            "A slender %^BOLD%^%^BLUE%^ribbon %^BOLD%^%^CYAN%^of the stream winds "+
            "its way along the floor of the cavern, bounded on one side "+
            "by a wide %^BOLD%^%^WHITE%^ledge %^BOLD%^%^CYAN%^wide enough "+
            "for several people to sit comfortably for awhile.  Atop the "+
            "ledge, the rock seems to have formed several natural "+
            "%^BOLD%^%^BLUE%^seats%^BOLD%^%^CYAN%^, complete with sloping "+
            "backs.  You could make your way through the %^RESET%^%^CYAN%^"+
            "waterfall %^BOLD%^%^CYAN%^into the stream beyond.  The cavern "+
            "also leads further to the east, where it seems to open into a "+
            "wider cave."+
            "\n"
      );
     	set_smell("default","The crisp, clear scent of water masks all other smells.");
     	set_listen("default","An ethereal voice singing rises above the roar of the waterfall.");
    	set_exits(([
       	"west" : VILSTREAM"stream25",
         	"east" : VILSTREAM"grotto2",
    	] ));
    	set_items(([
         ({"wall","mica","walls"}) : "The walls are made of layers of the translucent "+
            "rock mica that sparkles and adds its own radiance to the cavern.  The walls "+
            "arch overhead, forming a relatively smooth ceiling.",
         ({"ceiling","topaz","deposits","moss","phosphorescent moss"}) : "%^YELLOW%^The "+
            "ceiling is carved of mica just like the walls.  Small deposits of yellow "+
            "topaz sparkle in the radiance of the %^GREEN%^phosphorescent moss "+
            "%^YELLOW%^growing alongside it.",
         ({"waterfall","stream","ribbon"}) : "The roaring water of the waterfall crashes "+
            "over the opening to the west, protecting this small cavern from view.  "+
            "A narrow stream gently bubbles down from the west, leading to the larger "+
            "cavern there.",
         ({"ledge","ground","floor"}) : "Made of mica like the rest of the cavern, "+
            "the floor is rather slick with water from the waterfall and stream.  "+
            "On the southern side of the stream, there is a wide ledge where "+
            "several people could relax at once.",
         ({"seat","seats","chairs"}) : "Near the back of the ledge, where the ground "+
            "meets the wall, several chairs have been formed naturally from the rock.  "+
            "Their backs are sloped, and they look surprisingly comfortable.",
         ({"large cave","large cavern","wider cave"}) : "To the east, an archway "+
            "in the tunnel here seems to lead to a larger cavern.  It turns back "+
            "sharply to the southeast, though, and you cannot see much."
    	] ));
}

void reset() {
   ::reset();
   switch(random(4)){
      case 0:   tell_room(TO,"%^BOLD%^%^CYAN%^A sudden rush in the waterfall sprays the room with chilled water.");
                break;
      case 1:   tell_room(TO,"%^BOLD%^A gentle song rises above the roar of the waterfall, coming from the east.");
                break;
      case 2:   tell_room(TO,"%^BOLD%^%^BLUE%^The soothing babble of the stream ripples through the cavern.");
                break;
      case 3:   tell_room(TO,"%^BOLD%^%^GREEN%^The phosphoresent moss %^YELLOW%^glows%^GREEN%^, brightening the cavern.");
                break;
      default:  break;
   }
}
