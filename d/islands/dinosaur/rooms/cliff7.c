// hades hid a spear here 8/10
#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;
int items = 1;
void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(RUTTED_TRACK);
    set_short("%^YELLOW%^Rocky Cliffs");
    set_long(
      "You are on the face of the northern cliffs above the jungle.  From
here you can see all out over the jungle, even to the rocky cliffs in the
ocean to the south.  To the east in the distance you can barely make out a
tower on the cliffs.  There is a strange pool of %^CYAN%^water%^RESET%^ here."
    );
    set_listen("default", "from time to time you can hear the call of a strange flying animal.");
    set_items( ([
      "tower" : "You can't make out any details from this vantage point.",
      "ocean" : "The ocean looks very blue from here.",
	  "water" : "There is a pool of dark water along the cliff.",
    ]) );
    set_exits( ([
      "northwest" : RPATH "cliff5",
    ]) );
 set_search("default","Where do you want to search?");
 set_search("water",(:TO,"search_water":));   
}

int search_water(string str){
     object obj;
     if (!items) {
     tell_object(TP,"It seems like someone has"+
      " searched around here already.");
      return 1;}
     obj = new(OPATH"frostfire");
     obj->move(TO);
     tell_object(TP,"You find a strange spear "+
      "in the murky depths.");
     items=0;
      return 1;
}
