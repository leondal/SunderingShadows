#include <std.h>
#include "../include/tabor.h"

inherit ROOM;

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_indoors(1);
	set_name("The Attuned Mind Foyer");
	set_short("The Attuned Mind Foyer");
	set_long(
"%^BOLD%^Foyer of the %^CYAN%^A%^BLUE%^t%^CYAN%^t%^WHITE%^u%^CYAN%^"+
"n%^BLUE%^e%^CYAN%^d Mind%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^The walls of this enclave are made of a softly "+
"s%^BOLD%^h%^RESET%^%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^m"+
"%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^n"+
"%^BOLD%^g %^RESET%^%^CYAN%^crystalline blue.  They are "+
"hewn smooth, almost soft to the touch, and the light seems to "+
"shift within them, now %^BOLD%^%^BLACK%^dark%^RESET%^"+
"%^CYAN%^, now a brilliant %^BOLD%^azure%^RESET%^%^CYAN%^.  "+
"The floor presents a faintly mirrored sheen, reflecting "+
"the countenance of all who walk upon it.  A %^RESET%^g"+
"%^BOLD%^l%^RESET%^i%^BOLD%^t%^RESET%^t%^BOLD%^e%^RESET%^r"+
"%^BOLD%^i%^RESET%^n%^BOLD%^g chandelier %^RESET%^%^CYAN%^"+
"spirals down from the vaulted ceiling, sending cascades of "+
"soft %^YELLOW%^light %^RESET%^%^CYAN%^all around.  While the "+
"room is not rounded, the walls themselves seem to have no corners, "+
"simply merging into one another.  Several doorways open "+
"off from this main room, each one distinctly different.%^RESET%^\n"
	);
	set_smell("default","A crisp, clean fragrance permeates the air.");
	set_listen("default","A faint whispering seems just beyond hearing.");
	set_items( ([
       ({"wall","walls","floor","here"}) : "The walls, floor, and "+
          "ceiling have been carved from a smooth crystalline "+
          "substance that seems somewhat unlike natural rock.  "+
          "They have a reflective sheen, allowing you to catch a "+
          "brief glimpse of yourself.",
       ({"chandelier","light","lights"}) : "A breathtaking chandelier "+
          "is suspended from the ceiling, spiralling downward "+
          "in a cascade of %^RED%^p%^ORANGE%^r%^YELLOW%^i%^GREEN%^s"+
          "%^CYAN%^m%^BLUE%^a%^RESET%^%^MAGENTA%^t%^BOLD%^i%^RED%^c "+
          "%^RESET%^facets.  The chandelier is massive, filling most "+
          "of the ceiling and adding its soft radiance to the room.",
       ({"doorway","doorways"}) : "Light from the radiant chandlier "+
          "spills through each of the doorways, adding to the "+
          "illumination within.  There are four you might look at: "+
          "the north, east, south, and west doorways.",
       ({"west", "west doorway","west door"}) : "The doorway to the "+
          "west bears an onion-shaped dome, its raised edge carved "+
          "from deep obsidian.  That doorway leads back out to the "+
          "streets of Tabor, just visible through a scintillating "+
          "haze.",
       ({"north","north doorway","north door"}) : "The northern "+
          "doorway is fashioned to look much like a carved "+
          "crystal finished in an oval cut.  Facets have been worked "+
          "into the doorframe, adding to the overall look.  The "+
          "shop inside seems to sell large crystals, each threaded "+
          "on a silken cord.",
       ({"east","east doorway","east door"}) : "The eastern doorway "+
          "leads to a narrow hall and is carved in the shape of a "+
          "star.  This doorway is edged with three inches of "+
          "polished clear quartz, making the hallway seem brighter.",
       ({"south","south doorway","south door"}) : "The southern "+
          "doorway is a simple, large circle leading into a "+
          "bazaar filled with crystals in all shapes, colors, and "+
          "sizes.  Despite the somewhat cluttered appearance of "+
          "several scattered wooden tables, the crystals seem to "+
          "have been neatly sorted into bins."
    ]) );
    set_exits(([
        "west" : ROOMDIR+"psientry",
        "north" : ROOMDIR+"psistore",
        "east" : ROOMDIR+"psihall",
        "south" : ROOMDIR+"psicomps"
    ]) );
}

void reset(){
   ::reset();
   if(!present("aged gemcutter")) new("/d/darkwood/tabor/mon/psi_gemcutter")->move(TO);
}
