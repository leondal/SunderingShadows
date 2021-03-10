#include <std.h>
#include "../dragon.h";

inherit TVAULT;

void create() {
   ::create();
   set_long(
      "%^RESET%^This long hall travels east to west, with an exit to the"+
      " north. To the west is a door make of solid %^RESET%^%^ORANGE%^oak %^RESET%^and to the east"+
      " a door made of %^BOLD%^%^WHITE%^steel%^RESET%^. There are strange %^BOLD%^%^RED%^runes%^RESET%^ written onto the"+
      " steel door."
   );
   set_items( ([
      "runes" : "These are strange glowing runes placed upon the steel door to the east.",
]) ); 
   set_exits( ([
      "west" : TOWER+"lab",
      "east" : TOWER+"summoning_room",
      "north" : TOWER+"elevator",
      "downstairs" : TOWER+"balcony04",
   ]) );
   set_door("oak door",TOWER+"lab","west","tower key");
   set_door("steel door",TOWER+"summoning_room","east","tower key");
   set_pre_exit_functions(({"north"}),({"GoThroughDoor"}));
}


int GoThroughDoor() {
    object obj,stone;
    if(obj=present("red stone",TP)){
            write("You pass through the invisible barrier guarding the way.");
            return 1;
        }else{
           write("You can't seem to break the invisible barrier shielding the way north.");
            return 0;
      }
}
