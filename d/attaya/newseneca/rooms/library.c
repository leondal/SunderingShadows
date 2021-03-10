//Library for new Seneca ~Circe~ 11/19/07
//The functional library code is all Ares :)
#include <std.h>
#include "../seneca.h"

inherit LIBRARY;

void create(){
   ::create();
   set_public_library(1);
   set_deposit(1000);
   set_library_name("Seneca_Public_Library");
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_name("Seneca Public Library");
   set_short("%^BOLD%^Public Library, Seneca%^RESET%^");
   set_long("%^BOLD%^Public Library, Seneca%^RESET%^\n"+
      "This library is a place of quiet beauty featuring vaulted "+
      "%^BOLD%^ceilings %^RESET%^supported by %^BOLD%^marble "+
      "columns%^RESET%^ that rise over twenty feet before "+
      "forming %^BOLD%^archways %^RESET%^high overhead.  In "+
      "between each of the archways is a %^YELLOW%^chandelier "+
      "%^RESET%^that helps provide soft illumination.  The "+
      "%^BOLD%^columns %^RESET%^divide the room into smaller "+
      "sections, though it only emphasizes the vastness of this "+
      "chamber.  A %^BOLD%^%^BLACK%^maze %^RESET%^of %^ORANGE%^"+
      "bookshelves %^RESET%^and %^YELLOW%^scroll racks %^RESET%^"+
      "runs between the columns and is quite difficult to navigate.  "+
      "Small %^BLUE%^desks %^RESET%^have been placed in different "+
      "locations to allow a researcher a place to study for a time.  "+
      "The floor is muffled by coordinating %^GREEN%^runners %^RESET%^"+
      "that provide a touch of color as well as preserve the silence "+
      "of the library.  The outer walls are broken at intervals by "+
      "tall, narrow %^CYAN%^windows %^RESET%^that let in shafts of "+
      "%^YELLOW%^light %^RESET%^during the day.\n");
   set_smell("default","The smell of aging parchment rises over the fresh ocean breeze.");
   set_listen("default","Silence reigns in the library, though sounds occasionally drift in through the windows.");
   set_items(([
      ({"ceiling","ceilings","archway","archways"}) : "The columns "+
         "rising high overhead form archways against the ceiling.  "+
         "They are difficult to see so far up, and the light of the "+
         "chandeliers makes it more so.",
      ({"column","columns"}) : "Thick round columns of pure %^BOLD%^"+
         "white marble %^RESET%^are spread in neat rows throughout "+
         "the library.  They support the vaulted ceiling and provide "+
         "a framework for the bookshelves and scroll racks.",
      ({"chandelier","chandeliers"}) : "Hanging several feet from the "+
         "ceiling, the chandeliers are nonetheless still high overhead.  "+
         "It is hard to see what each looks like because of the glare "+
         "they create, though the light dissolves to a soft glow by "+
         "the time it reaches the floor.",
      ({"bookshelves","shelves"}) : "Spread throughout the library "+
         "are countless bookshelves.  All of them are eight feet tall, "+
         "and most have six shelves.  They are arranged to create the "+
         "illusion of hallways, and each subject is in a different "+
         "section.",
      ({"racks","scroll racks"}) : "Fewer in number than the bookshelves, "+
         "the scroll racks are placed periodically around the library "+
         "to house scrolls on the subjects in that particular area.  "+
         "Each rack is almost like a bookshelf but with the shelves "+
         "tilted and fitted with a lip to hold the scrolls.",
      "scrolls" : "The neatly-rolled scrolls are each labeled and placed "+
         "on the scroll rack so they are easy to find.  Many are ancient "+
         "and yellowing, and some look like they might crumble to dust "+
         "if touched.",
      "books" : "On the bookshelves are various %^ORANGE%^tomes %^RESET%^"+
         "on most any subject.  Some of the books are bound with leather, "+
         "some feature wooden covers, and you even see one or two you are "+
         "sure are bound in skin.",
      ({"desk","desks"}) : "Small wooden desks with single chairs are "+
         "to be found throughout the maze.  Each has enough room for "+
         "several books and a small tray for holding writing supplies.",
      ({"runner","runners"}) : "Presumably to keep the library quiet and "+
         "protect the marble, the floor has been lined with %^GREEN%^"+
         "runners%^RESET%^.  Each runner is a %^GREEN%^deep green "+
         "%^RESET%^and features various scenes along its length.  You "+
         "see %^CYAN%^minstrels %^RESET%^playing musical instruments, "+
         "%^MAGENTA%^plays %^RESET%^being performed, and %^BOLD%^"+
         "scholars %^RESET%^hard at work.  It clearly would have taken "+
         "quite some time and skill to create each of the wonderful carpets.",
      ({"wall","walls","window","windows"}) : "The walls are broken by "+
         "tall, narrow windows that let in light during the day.  The "+
         "windows are quite thick, owing to the original librarian's "+
         "belief that light was harmful to books."
   ]));
   set_door("library door","/d/attaya/newseneca/rooms/viento51","south",0,0);
   set_door_description("library door","The "+
      "library door is an oversized, fifteen-foot-high construction of thick "+
      "%^BOLD%^%^BLACK%^mahogany%^RESET%^ and %^ORANGE%^bronze reinforcements"+
      "%^RESET%^.");
   set_exits(([
      "south" : ROOMS"viento51"
   ]));
}

void reset(){
  if(!present("librarian")) 
      find_object_or_load(MON"librarian")->move(TO);
}