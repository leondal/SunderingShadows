#include <std.h>
inherit ROOM;
void touch_nest(string str);
int hornet_wait;

void create(){
  ::create();
  set_property("light", 2);
  set_short("The East Branch.");
  set("day long",
@GIL
%^GREEN%^You are out on the East limb of the huge oak tree.
A giant hive can be seen here.
The leaves close around you and green is all you can see.
You can only go West.
GIL
);
  set("night long",
@GIL
%^CYAN%^You are out on the East limb of the huge oak tree.
A giant hive can be seen here.
The dark closes around you as the leaves block out all light.
You can only go West.
GIL
);
set_smell("default", "%^BOLD%^%^GREEN%^You can smell the fresh smell of oak leaves.");
set_listen("default", "You can hear the wind in the oak leaves.");
  set_items(([
"leaves" : "The leaves are dark green and full of life.",
"tree" : "This huge oak grows beside the road.",
"hive" : "It's a Giant Hornets Nest, you better not touch it!",
"limb" : "This is a big limb growing east over the road.",
]));

set_exits(([
     "west" : "/d/dagger/westroad/tree1",
]));
hornet_wait = 0;

}
void init() {
  ::init();

  add_action("touch_nest","touch");
}

int touch_nest(string str) {

  object nest;
  if(str != "nest" || hornet_wait != 0)
  return 0;
    if(present("hornet"))
    {
     tell_object(this_player(),"Dont you think one was enough? \n");
  tell_room(environment(TP),TPQCN+" has lost their mind, they are touching the giant nest again looking for more Hornets! RUN AAAWWAAAYYY!!",TP);
     return 1;
}
  hornet_wait = 1;
   new("/d/dagger/westroad/mon/hornet")->move(this_object());
  tell_object(this_player(), "%^YELLOW%^A Giant Hornet bursts out from the nest!!");
 tell_room(environment(TP),TPQCN+" touches the nest and a Giant Hornet bursts out!!",TP);
  return 1;
}

void reset()
{
  ::reset();
  if(hornet_wait != 0)
    hornet_wait--;
}
