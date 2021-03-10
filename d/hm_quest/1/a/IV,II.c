#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/a/IV,I",
                "east"  : pass_exit("2","I,II")
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
            "north" : MAZEDIR+"1/a/IV,I",
            "east"  : pass_exit("2","I,II")
           ]) );
  return 1;
}
