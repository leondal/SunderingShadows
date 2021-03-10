#include <std.h>
#include "../include/tabor.h"

inherit "/std/psi_lab";

void create(){
	::create();
	set_travel(PAVED_ROAD);
	set_terrain(CITY);
	set_light(2);
//	set_property("no teleport", 1); //removed by Circe 6/18/08 after discussions with others
	set_indoors(1);
	set_name("The Attuned Mind Workroom");
	set_short("The Attuned Mind Workroom");
	set_long(
"%^BOLD%^Workroom of the %^CYAN%^A%^BLUE%^t%^CYAN%^t%^WHITE%^u%^CYAN%^"+
"n%^BLUE%^e%^CYAN%^d Mind%^WHITE%^, Tabor%^RESET%^\n"+
"%^CYAN%^This room seems to be a center of learning and "+
"exploration for psions.  The walls are lined with deep "+
"%^BOLD%^%^BLACK%^mahogany bookshelves %^RESET%^%^CYAN%^"+
"filled with rows of %^RESET%^tomes%^CYAN%^ on all manner "+
"of learning.  Slender plush %^MAGENTA%^divans %^CYAN%^are "+
"spread around the room, allowing people to recline and "+
"peruse the books at their leisure.  The focal point of the "+
"room is an elegant %^BOLD%^%^BLACK%^mahogany table %^RESET%^"+
"%^CYAN%^upon which a %^BOLD%^crystal ball %^RESET%^%^CYAN%^"+
"rests.  Two straight-backed chairs sit beside the table, "+
"offering a prime viewing point for those gazing into the "+
"ball.  The furthest wall of the room is roped off, and "+
"occasionally a psion will step back there to open up a "+
"small %^BOLD%^%^WHITE%^dimensional rift%^RESET%^%^CYAN%^, "+
"depositing crystals into a storage space.%^RESET%^\n\n"+
"The command <help workroom> will instruct you in its use.\n"
	);
	set_smell("default","A crisp, clean fragrance permeates the air.");
	set_listen("default","A faint whispering seems just beyond hearing.");
	set_items( ([
       ({"wall","walls","floor","here"}) : "The walls, floor, and "+
          "ceiling have been carved from a smooth crystalline "+
          "substance that seems somewhat unlike natural rock.  "+
          "They have a reflective sheen, allowing you to catch a "+
          "brief glimpse of yourself.",
       ({"tomes","books","shelves","bookshelves"}) : "The mahogany "+
          "bookshelves are crafted in an elegant manner without "+
          "being ornate.  They support books of various disciplines "+
          "of learning, from gemcrafting to studies of energies to "+
          "the creation of demiplanes - any subject which might "+
          "interest a psion.",
       ({"divan","divans","couch","couches"}) : "The divans are "+
          "spread around the room, offering psions a place to "+
          "sit or lounge while the read.  Many of them are often "+
          "filled, some with people talking quietly to one another "+
          "while others are reading alone.",
       ({"table","chairs","chair"}) : "The table and chairs are "+
          "in the center of the room, offering prime access to the "+
          "crystal ball that sits atop the table.  They are well-"+
          "made, featuring fluorishing curves and lines.",
       ({"dimensional rift","rope","rift"}) : "The roped off area "+
          "provides a safe place for people to open the rifts to store "+
          "their crystals."
    ]) );
    set_exits(([
        "south" : ROOMDIR+"psihall"
    ]) );
   setOwner("none");
   setLabId("tabor");
}

void reset(){
   ::reset();
   if(!present("crystal ball")) new("/d/magic/obj/crystal_ball")->move(TO);
}
