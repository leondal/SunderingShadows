//genstore.c - updated 10/20/03 by Circe.
#include <std.h>
#include "../koenig.h"

inherit ROOM;

int searched;

void create() {
    ::create();
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_light(2);
    set_short("A destroyed general store");
    set_name("A destroyed general store");
    set_long(
      "This abandoned room smells of %^YELLOW%^sulfur %^RESET%^rising "+
      "from the %^BOLD%^%^BLACK%^scattered ash %^RESET%^along "+
      "the floor.  The charred remains of %^ORANGE%^shelves %^RESET%^lining "+
      "the walls hold %^ORANGE%^jars%^RESET%^, now "+
      "broken and blackened around the edges.  %^CYAN%^Strange liquids %^RESET%^tinted "+
      "%^BOLD%^%^BLACK%^gray %^RESET%^with %^BOLD%^%^BLACK%^soot %^RESET%^"+
      "hold curious objects suspended inside.  Most of the %^ORANGE%^shelves %^RESET%^"+
      "are bare, however, and "+
      "it seems that anything of value has probably been removed from the store ages "+
      "ago.  Despite the time it has obviously been since the unknown disaster destroyed "+
      "the store, no attempt has been made to clean it up or reopen it.  A long %^BLUE%^counter "+
      "%^RESET%^about four and a half feet high stands near the back wall, covered in strange "+
      "%^CYAN%^symbols %^RESET%^and %^BOLD%^%^BLACK%^blackened ash%^RESET%^.  "+
      "The few narrow windows seem to have been set with "+
      "glass at one time, but they stand empty now, allowing the wind to cut through the room."+
      "\n"
    );
    set_smell("default","The smell of ash and sulfur fills the air.");
    set_listen("default","You hear the whine of the wind through the broken windows.");
    set_exits(([
      "east" : VILROOMS"k_road10",
      ] ));
    set_items(([
      ({"ash","soot"}) : "The deep gray ash from a fire covers all the parts of this room.  "+
         "The wind sweeping through the window stirs it, covering footprints and making it "+
         "difficult to breathe.",
      ({"symbols","strange symbols"}) : "Odd symbols adorn the counter here, and a few "+
         "more are spaced along the walls.  The ones on the walls seem much more recently placed, "
         "though, than those on the counter.",
      ({"walls","shelves","shelf"}) : "The walls are made of stone and were once covered in "+
         "a thin layer of plaster which was probably painted a pleasant color.  Now, however, "+
         "the plaster has peeled and blackened.  Wooden shelves lining the walls are cracked "+
         "and broken, though some still hold jars and various other unrecognizable items.",
      ({"jar","jars"}) : "The broken glass jars on the shelves are filled with gray liquid.  "+
         "Some are probably water, but others have a greasy sort of look to them.  Unusual "+
         "materials float within the cracked and jagged jars, leaving little clue as to their "+
         "original purpose.",
      ({"counter","long counter","wooden counter"}) : "There seems little doubt that the only "+
         "reason the wooden counter still stands is that it is quite thick and was at one time "+
         "very sturdy.  Now, it has a blackened top and cracked sides, making it seem unsteady.",
      ({"floor","footprints"}) : "The wooden floor of the abandoned store is covered in thick soot "+
         "and dirt.  Despite the many feet that have probably found their way here, few footprints "+
         "remain.  A strong gust of wind through the vacant windows stirs the ash, revealing the reason "+
         "for the lack of footprints.",
      ({"window","windows"}) : "The tall, narrow windows set within the stone walls once had "+
         "wooden frames that held glass.  Now only broken panes remain, and most of that has been "+
         "carted away to be used by those less fortunate."
  ] ));
    set_search("default","The shelves behind the counter seems to have been disturbed.");
//    set_search("ash", (: TO, "search_ash" :) ); //removed, changing for morganus' house
//    set_search("floor", (: TO, "search_ash" :) );
    set_search("shelves", (: TO, "search_shelves" :) );
    set_search("jars","You rifle through the nasty liquid, which leaves your skin tinged gray and reeking.");
}

void init(){
   ::init();
   add_action("symbols_fun","trace");
}

int search_shelves(){
  if(searched) {
    tell_object(TP,"It looks as if someone has removed anything of value on the shelves.");
    return 1;
  }
  tell_object(TP,"You search through the ash and muck on the shelves and find something of value!");
  tell_room(ETP,""+TPQCN+" searches through the muck on the shelves and finds something!",TP);
  searched = 1;
  switch(random(4)){
    case 0:  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"kit");
             break;
    case 1:  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"stuff");
             break;
    case 2:  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"component");
             break;
    case 3:  "/d/common/daemon/randstuff_d.c"->find_stuff(TO,"coins");
             break;
  }
  return 1;
}

int search_ash(){
   if(member_array("down",ETP->query_exits()) == -1) {
      tell_object(TP,"You search behind the counter and find a trap door hidden in the ash.");
      tell_room(ETP,""+TPQCN+" searches behind the counter and finds a trap door.",TP);
      add_exit("/d/guilds/legion/hall/main","down");
      return 1;
   }
   tell_object(TP,"The outline of the trap door is easily visible behind "+
         "the counter.  You find nothing else of interest.");
   return 1;
}

int symbols_fun(string str){
   if(!str) return 0;
   if(str != "symbols") return 0;
   tell_object(TP,"%^CYAN%^You press your hand against a symbol upon the "
"wall, tracing its outline with a fingertip, and you suddenly appear "
"elsewhere!");
   tell_room(ETP,"%^CYAN%^"+TPQCN+ " presses "+TP->QP+" hand against the "
"wall, and suddenly disappears!",TP);
   TP->move_player("/d/player_houses/morganus/rooms/foyer");
   return 1;
}
