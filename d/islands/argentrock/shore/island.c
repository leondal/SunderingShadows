#include <std.h>
#include "/d/islands/argentrock/argabbr.h"
inherit ROOM;

void create() {
    ::create();
	set_name("Watcher isle");
    set_short("Watcher isle");
    set_terrain(JUNGLE);
    set_travel(FRESH_BLAZE);
	set_property("no teleport",1);
	set_long("%^BOLD%^%^GREEN%^Watcher isle%^RESET%^
%^GREEN%^This island is a small ring of trees and thick underbrush on top of a large black rock jutting out of the sea near the argentrock coastline. The area provide a good spot to look out around the whole of this side of the island for ships and also at the shore. There is a small covered area here that has been cleared for a makeshift camp. It looks like to get back to the main island one would have to %^YELLOW%^<descend>%^RESET%^%^GREEN%^ down. It is a long fall to hit the water so one should stay clear of the edge.");
   set_climb_exits((["descend":({SHO+"island1",20,roll_dice(10,8),100})]));
   if(!present("watcher")) new(MON+"watcher")->move(TO);
}


void reset() {
    object *pplz,myroom;  //stealing N's code
    int flag,i;
    ::reset();
    pplz = all_living(TO);
    if(!pplz) flag = 0; // noone in the room
    else {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }
    myroom = find_object_or_load(SHO+"island1");
    pplz = all_living(myroom);
    if(!pplz) flag = 0; // noone in the room
    else {
      for(i = 0;i<sizeof(pplz);i++) {
        if(userp(pplz[i]) && !pplz[i]->query_true_invis()) flag = 1;
      }
    }

  if(!present("watcher") && flag == 0)
   new(MON+"watcher")->move(TO);
}
