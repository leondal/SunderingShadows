#include <std.h>
#include <move.h>

inherit ROOM;

int used;

void create()
{
  ::create();
  set_property("indoors",1);
  set_property("light",2);
  set_short("The Tower of Wizardry");
  set_long(
@CASTLE
%^BOLD%^First Floor of the Tower of Wizardry%^RESET%^
%^BLUE%^You are in the circular central room on the first floor. It
appears that this 

A spiral staircase in the center of the room leads to the other 
levels of the tower. There is a small crevice in the wall with a 
sign on the wall next to it.
CASTLE
  );
  set_items(([
    "crevice":"There is a scroll inside the crevice.",
    "sign":"The sign reads: %^BOLD%^In case of Emergency Only%^RESET%^.",
    ]));
  set_exits( ([
    "north":"/d/darkwood/castle/tower1n",
    "south":"/d/darkwood/castle/tower1s"
    ]) );
}

void init(){
  ::init();
  add_action("get_scroll","take");
}

int get_scroll(string str){
  object ob;
  int res;
  
  if(!str) return notify_fail("Take what?\n");
  if(str != "scroll") return notify_fail("You can't take that.\n");
  if(used) return notify_fail("The scroll has already been taken from here.\n");
  ob = new("/d/darkwood/castle/obj/amscroll");
  res = ob->move(TP);
  if (res == MOVE_OK) {
    tell_object(TP,"You take the scroll from the crevice.");
    tell_room(TO,TPQCN+" takes a scroll from the crevice.", TP);
  }
  else if(res == MOVE_NO_ROOM) {
    ob->move(TO);
    tell_object(TP,"You drop the scroll as soon as you take it.");
    tell_room(TO,"You see "+TPQCN+" drop a scroll on the floor.",TP);
  }
  used = 1;
  return 1;
}

void reset(){
  ::reset();
  used = 0;
}
    
