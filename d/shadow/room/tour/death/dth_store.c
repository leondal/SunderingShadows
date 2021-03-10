#include "/d/shadow/room/city/melnmarn.h"
#include <daemons.h>

inherit ROOM;

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("This is an Old Shack");
    set_long(
@MELNMARN
%^BOLD%^You are standing inside of an old shack%^RESET%^
There are many things piled on the floor and tacked to the wall.
An old hag stands over one of the larger piles with a club in hand. It
seems she is the shopkeeper.  Others mill about grabbing and fighting over 
what little good equipment is left.  You may try and <buy> or <sell> items
here.  There is a poster posted on the wall.
MELNMARN
);

    set_items(([
          "poster":"To all those who would aid in the destruction "+
          "of the weak, \n"+
            "Make your way South for it is I you seek. \n\n"+
            "Quag, The Right Hand of Death.",
          "pile":"These piles countain what little equipment "+
            "there is.",
          ]));
    set_exits( ([
       "east":"/d/shadow/room/tour/death/hall1.c",
    ]));
    set_property("no castle", 1);
    set_smell("default","The smell of old leather and wet rope fill "+
       "your nostrils.");
   set_listen("default","The sounds of minions shouting and "+
       "fighting, fill your ears.");
 }


void init(){
      ::init();
      if(!present("hag",TO))
              new(MONDIR+"tr_hag")->move(TO);

}
