#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "south" : pass_exit("4","III,I"),
                "west"  : MAZEDIR+"1/c/II,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
            "south" : pass_exit("4","III,I"),
            "west"  : MAZEDIR+"1/c/II,IV"
           ]) );
  return 1;
}




