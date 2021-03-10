//bed5.c - updated by Circe 11/5/03.  Changed description to show the chest open and closed.
#include <std.h>
#include "/d/deku/inherits/deku.h"
inherit HH_ROOMS+"bed2i";
int chest_open;
void create() {
    ::create();
    set_long("This was once a large bedroom but now is simply decaying and "
      "dirty.  Damp %^CYAN%^mold %^RESET%^covers portions of the walls and "
      "ceiling and rubbish is strewn liberally around the floor.  In the "
      "center is a single mattress which has been badly torn and has the "
      "stuffing mostly strewn around the room.  Under the window is a large "
      "%^ORANGE%^pine chest%^RESET%^, the wood badly split from age and decay.");
    set_exits(([ "west" : HH_ROOMS+"hall9" ] ));
    set_items(([
       "chest" : "The chest is not locked and will probably open easily.",
       "mattress" : "The mattress contains nothing but remnants of stuffing.",
       "mold" : "The mold looks harmless but seems to be overtaking everything."
    ] ));
    hauntings();
chest_open = 0;
}

void reset() {
  ::reset();
}

void init() {
  ::init();
  add_action("open_it","open");
  add_action("close_it","close");
}

open_it(string str) {
  if(!str) return 0;
  if(str != "chest") {
    tell_object(TP,"What would you like to open?");
    return 1;
  }
  if(chest_open){
      tell_object(TP,"The chest is already open!");
      return 1;
  }
  tell_object(TP,"The chest opens easily and you only find dust and cobwebs.  "
    "It looks like it's been empty for a very long time.");
  tell_room(ETP,""+TPQCN+" opens the chest at the end of the bed.",TP);
  add_item("chest","The old chest at the end of the bed is open.");
  chest_open = 1;
  return 1;
}

int close_it(string str){
   if(!str) return 0;
   if(str != "chest"){
      tell_object(TP,"What are you trying to close?");
      return 1;
   }
  if(!chest_open){
      tell_object(TP,"The chest is already closed!");
      return 1;
  }
   tell_object(TP,"You shut the lid of the old chest, sending up a cloud of dust.");
   tell_room(ETP,""+TPQCN+" closes the chest at the end of the bed.",TP);
   add_item("chest","The chest is not locked and will probably open easily.");
   chest_open = 0;
   return 1;
}