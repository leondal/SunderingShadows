//tower
#include <std.h>
#include "elf.h"
inherit VAULT;


void create(){
    ::create();
set_property( "light", 2);
    set_property( "indoors", 1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("tower");
    set_short("tower");
    set_long(
"%^BOLD%^%^BLUE%^T%^RESET%^his is a lavish looking room in a tower at the highest point of the keep%^BOLD%^%^BLUE%^.%^RESET%^  "
"Everything is ornate, and one cannot help but wonder if the room was "
"decorated by no one mortal%^BOLD%^%^BLUE%^.%^RESET%^  The walls and ceiling are covered "
"with %^MAGENTA%^colorful paintings%^RESET%^ of elven lore masterfully made in every detail%^BOLD%^%^BLUE%^.%^RESET%^  "
"There are several arched windows overlooking the %^GREEN%^courtyard%^RESET%^ "
"and the %^GREEN%^grove%^RESET%^%^BOLD%^%^BLUE%^.%^RESET%^  The drapes that hang from the tops of the windows are made "
"of a scarlet velvet and sway thickly when the wind rises%^BOLD%^%^BLUE%^.%^RESET%^  There is a large "
"plush %^GREEN%^bed%^RESET%^ against the northern wall with translucent drapes much like "
"silk%^BOLD%^%^BLUE%^.%^RESET%^ There are several plush chairs and a love seat against the wall%^BOLD%^%^BLUE%^.%^RESET%^  In "
"the center of the room is a large %^BOLD%^sparkling crystal chandelier%^BOLD%^%^BLUE%^.%^RESET%^ %^RESET%^");

	set_items(([
      (({"paintings"})) :
        "The paintings are all of ancient elven stories.  Most involve gold elves and their noteable use of magic.",
      (({"grove"})) : "The grove lies below the high tower.",
      (({"courtyard"})) : "The garden courtyard lies to the north below surrounded by walls. ",
	  (({"bed"})) : "There is a nice bed here.  It is covered in a silk bedding.  The blankets are shades of gold and white.",
	  (({"drapes"})) : "The drapes that are on the windows are nice. ",
      (({"chandelier"})) : "There is a beautiful chandelier here."+
	  "   It is made from silver with glowing crystals as lights.",
	  (({"windows"})) : "The grove, cliffs and waterfall can be seen from the windows. ",
	  (({"chair,chairs"})) : "These padded green chairs.  They look to be almost completely made from jade.",
	   ]));

   //todo: add item for windows that shows beauty of place
      set_exits(([ "down" : ROOMS"corridor",  ]));

   set_listen("default","It smells like lilac incense .");
   set_smell("default",
   "The tower sways oh-so-gently in the wind and the drapes rustle.");
   set_search("room",(:TO,"search_room":));   
}
void reset() {
   ::reset();
   if(!present("carver"))
      new(MON"carver")->move(TO);

}
int search_room(string str){

     if (present("stone",TO)) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
     new(OBJ"stone10")->move(TO);
     tell_object(TP,"You find a large stone in covered with a sheet.");

      return 1;
}

