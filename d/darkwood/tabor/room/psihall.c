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
	set_name("The Attuned Mind Hallway");
	set_short("The Attuned Mind Hallway");
	set_long(
"%^BOLD%^Hallway of the %^CYAN%^A%^BLUE%^t%^CYAN%^t%^WHITE%^u%^CYAN%^"+
"n%^BLUE%^e%^CYAN%^d Mind%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^The walls of this enclave are made of a softly "+
"s%^BOLD%^h%^RESET%^%^CYAN%^i%^BOLD%^m%^RESET%^%^CYAN%^m"+
"%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^i%^RESET%^%^CYAN%^n"+
"%^BOLD%^g %^RESET%^%^CYAN%^crystalline blue.  They are "+
"hewn smooth, almost soft to the touch, and the light seems to "+
"shift within them, now %^BOLD%^%^BLACK%^dark%^RESET%^"+
"%^CYAN%^, now a brilliant %^BOLD%^azure%^RESET%^%^CYAN%^.  "+
"The floor presents a faintly mirrored sheen, reflecting "+
"the countenance of all who walk upon it.  This hallway "+
"itself is rather nondescript, featuring three doorways "+
"leading north, east, and south, while the western corridor "+
"leads back to the foyer through a star-shaped archway.  "+
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
       ({"doorway","doorways","arches","archway"}) : "A star-shaped archway leads "+
          "westward into the main foyer, while simple oval "+
          "arches lead north, east, and south.",
       ({"north archway","north arch","arch 1","northern archway","northern arch"}) : "The "+
          "northern archway leads into a quiet lounge area where "+
          "psions are often seen conversing.  The focal point of "+
          "the room mahogany table supporting a crystal ball surrounded by "+
          "various divans and cushions.",
       ({"east archway","eastern archway","east arch","eastern arch","arch 2"}) : "The "+
          "archway on the eastern end of the hall leads into a tranquil "+
          "room.  The sound of gently falling water emanates from it, "+
          "bringing with it a calming presence.",
       ({"south archway","southern archway","south arch","southern arch","arch 3"}) : "The "+
          "southern archway opens upon another shop, this one featuring "+
          "shelves piled with small wooden boxes."
    ]) );
    set_exits(([
        "west" : ROOMDIR+"psifoyer",
        "north" : ROOMDIR+"psilounge",
        "east" : ROOMDIR+"psimeditate",
        "south" : ROOMDIR+"psicomps2"
    ]) );
}
