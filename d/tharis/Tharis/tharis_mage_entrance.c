#include <std.h>

inherit ROOM;

void create(){
   ::create();
   set_terrain(CITY);
   set_travel(DIRT_ROAD);
   set_property("indoors",1);
   set_property("light",2);
   set_property("no teleport",1);
   set_name("Entrance Hall");    
   set_short("%^ORANGE%^Entrance Hall%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^You find yourself back on your feet "+
      "inside the entrance hall of the mage hub.  The music is "+
      "louder in here, yet, after a cursory look around, you cannot "+
      "immediately discern its source.  There is a small row of"+
      "%^RESET%^ %^ORANGE%^amber%^RESET%^ %^BOLD%^%^WHITE%^hooks "+
      "on the eastern wall, where visitors may hang their cloaks "+
      "and hats after rain.  The light from outside casts %^GREEN%^"+
      "c%^MAGENTA%^o%^CYAN%^l%^WHITE%^o%^RED%^r%^YELLOW%^f%^RESET%^"+
      "%^CYAN%^u%^MAGENTA%^l %^BOLD%^%^WHITE%^shades on the white "+
      "marble floors as it permeates through the small %^RED%^s"+
      "%^CYAN%^t%^MAGENTA%^a%^GREEN%^i%^WHITE%^n%^YELLOW%^e%^RED%^d "+
      "%^GREEN%^g%^YELLOW%^l%^RED%^a%^CYAN%^s%^GREEN%^s %^WHITE%^"+
      "windows.  High above you, the ceiling opens up, revealing "+
      "the inside of the hollow, onion-bulb%^RESET%^ %^ORANGE%^co"+
      "%^YELLOW%^ppe%^RESET%^%^ORANGE%^r %^BOLD%^%^WHITE%^dome.  "+
      "There are no doors to speak of - the building simply "+
      "continues its semi-circle east and westwards.  Its curve "+
      "is rather tight though, not allowing immediate view of the "+
      "rooms ahead.  There is a %^CYAN%^plaque %^WHITE%^you can "+
      "%^CYAN%^view %^WHITE%^across from the entrance.%^RESET%^\n");
   set_smell("default","%^YELLOW%^It smells clean here, as though "+
      "the floors have been recently polished.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^Your ears catch the spirited "+
      "tune of a cord instrument.%^RESET%^");
   set_items(([
      "plaque" : "%^BOLD%^%^WHITE%^A pair of %^BLACK%^unfurling, "+
         "black leathery wings %^WHITE%^has been engraved in the "+
         "simple, white marble slab - the symbol of the one who has "+
         "commissioned and designed the building.%^RESET%^"
   ]));
   set_exits(([
      "east" : "/d/tharis/Tharis/tharis_mage_comps",
      "west" : "/d/tharis/Tharis/tharis_mage_carver",
      "exit" : "/d/tharis/Tharis/tharis_mage_outside"
   ]));
}

void init(){
   ::init();
   add_action("view_em","view");
}

int view_em(string str){
   if(!str) return 0;
   if(str != "plaque") return 0;
   tell_object(TP,"%^BOLD%^%^WHITE%^A pair of %^BLACK%^unfurling, "+
         "black leathery wings %^WHITE%^has been engraved in the "+
         "simple, white marble slab - the symbol of the one who has "+
         "commissioned and designed the building.%^RESET%^");
   tell_room(TO,""+TPQCN+" looks over the plaque.");
   return 1;
//view plaque added at Sevotharte's request
}