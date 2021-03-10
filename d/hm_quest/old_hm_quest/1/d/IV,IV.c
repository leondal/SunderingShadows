#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
               "north" : MAZEDIR +"1/d/IV,III",
               "east"  : pass_exit("2","I,IV")
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "north" : MAZEDIR +"1/d/IV,III",
                "east"  : pass_exit("2","I,IV")
           ]) );
  return 1;
}
