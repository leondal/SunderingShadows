#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "east"  : pass_exit("2","I,IV"),
                "west"  : MAZEDIR +"1/b/III,IV"
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "east"  : pass_exit("2","I,IV"),
                "west"  : MAZEDIR +"1/b/III,IV"
           ]) );
  return 1;
}
