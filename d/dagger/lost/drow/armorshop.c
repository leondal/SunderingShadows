#include <std.h>
#include <objects.h>
      
        inherit ROOM;
      
      void create() {
          room::create();
       set_light(2);
       set_indoors(1);
set_short("Drow house of armours");
   set_long(
"%^BLUE%^This appears to be a armours and sheilds store that the Drow Regime has in place for Drow from other cities to do business with while in Underdark."
" It is full of various forms of armors and shields. You dread doing business here as the Drow are renown for their ability to fool mortals about the quality of their goods and products.%^RESET%^"
     );
set_smell("default","There is an oily smell in the air.");
      set_items(([
"armours":"There are many pieces of armour laying about for purchase. Type: list to view them.",
"shields":"A few good shields lay scattered about."
        ] ));
set_exits(([
"south":"/d/dagger/drow/rooms/city16.c"
]));
  }
 void reset(){
 ::reset();
	if(!present("zokrath"))
new("/d/dagger/drow/mon/merchant2.c")->move(TO);
}
