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
	set_name("The Attuned Mind Entryway");
	set_short("The Attuned Mind Entryway");
	set_long(
"%^BOLD%^Entryway of the %^CYAN%^A%^BLUE%^t%^CYAN%^t%^WHITE%^u%^CYAN%^"+
"n%^BLUE%^e%^CYAN%^d Mind%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^The walls of this enclave are made of a softly "+
"s%^BOLD%^h%^RESET%^%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^m"+
"%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^n"+
"%^BOLD%^g %^RESET%^%^CYAN%^crystalline blue.  They are "+
"hewn smooth, almost soft to the touch, and the light seems to "+
"shift within them, now %^BOLD%^%^BLACK%^dark%^RESET%^"+
"%^CYAN%^, now a brilliant %^BOLD%^azure%^RESET%^%^CYAN%^.  "+
"The floor presents a faintly mirrored sheen, reflecting "+
"the countenance of all who walk upon it.  The entryway "+
"leads east, deeper into the quiet calm of the enclave, while "+
"the bustling city of Tabor is through the doorway to the west.  "+
"A faint %^BOLD%^light %^RESET%^"+
"%^CYAN%^seems to radiate from the rock itself.%^RESET%^\n"
	);
	set_smell("default","A crisp, clean fragrance permeates the air.");
	set_listen("default","A faint whispering seems just beyond hearing.");
	set_items( ([
       ({"wall","walls","floor","here"}) : "The walls, floor, and "+
          "ceiling have been carved from a smooth crystalline "+
          "substance that seems somewhat unlike natural rock.  "+
          "They have a reflective sheen, allowing you to catch a "+
          "brief glimpse of yourself.",
       ({"light","lights"}) : "The light in this hallway seems "+
          "to come merely from the radiance of the rock walls "+
          "themselves.",
    ]) );
    set_exits(([
        "east" : ROOMDIR+"psifoyer",
        "out" : ROOMDIR+"math10"
    ]) );
}
