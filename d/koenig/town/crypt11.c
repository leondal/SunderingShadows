#include <std.h>

inherit ROOM;

void look_stones(string str);

int skeleton_wait;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(DIRT_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Dark Room Beneath the Crypt");
  set_long("%^BOLD%^%^BLACK%^You find yourself traveling down a long, narrow hallway..."+
      "Hmmm, that's not quite right, this reminds you more of a tunnel. "+
           "The walls and ceiling are nothing but %^RESET%^%^ORANGE%^dirt%^BOLD%^%^BLACK%^ and %^RESET%^stone%^BOLD%^%^BLACK%^, and there is "+
           "a bit of moisture running down the walls. You catch glimpses of "+
           "some very %^BOLD%^%^WHITE%^white stone%^BOLD%^%^BLACK%^. The %^RESET%^%^GREEN%^stench%^BOLD%^%^BLACK%^ down here is very unpleasant.%^RESET%^\n");
  set_items( ([
                "walls" : "The walls are of dirt and stone with little "
                          "rivlets of moisture running down over some bright "
                          "white stones."
           ]) );
  set_exits( ([
     "east" : "/d/koenig/town/crypt10",
     "west" : "/d/koenig/town/crypt12"
           ]) );
  skeleton_wait = 0;
}


void init()
{
  ::init();
  add_action("look_stones", "look");
}


int look_stones(string str)
{
  object sk1, sk2, sk3, sk4, sk5;
  if((str != "stones" && str != "stone") || (skeleton_wait != 0))
    return 0;
  if(present("skeleton") || present("giant skeleton"))
   {
     tell_object(this_player(),"No more skeletons assemble.");
     tell_room(environment(TP),TPQCN+" searches the wall but no more "
                                     "skeletons assemble.",TP);
     return 1;
   }
  skeleton_wait = 1;

  sk1 =  new("/d/koenig/town/mon/skeleton1.c");
  sk1 -> move(this_object());
  sk1 -> kill_ob(this_player(),1);

  sk2 =  new("/d/koenig/town/mon/skeleton2.c");
  sk2 -> move(this_object());
  sk2 -> kill_ob(this_player(),1);

  sk3 =  new("/d/koenig/town/mon/skeleton3.c");
  sk3 -> move(this_object());
  sk3 -> kill_ob(this_player(),1);

  sk4 =  new("/d/koenig/town/mon/skeleton4.c");
  sk4 -> move(this_object());
  sk4 -> kill_ob(this_player(),1);

  sk5 =  new("/d/koenig/town/mon/gskeleton1.c");
  sk5 -> move(this_object());
  sk5 -> kill_ob(this_player(),1);

  tell_object(this_player(),"%^BOLD%^%^RED%^Thousands of bones burst from the wall to form "
                            "skeleton fighters of the UNDEAD!%^RESET%^");
  tell_room(environment(TP),TPQCN+" takes a closer look at the wall and "
                                  "suddenly thousands of bones burst from the "
                                  "wall and assemble into several skeleton "
                                  "fighters!",TP);
  return 1;
}


void reset()
{
  ::reset();
  if(skeleton_wait != 0)
    skeleton_wait--;
  }
