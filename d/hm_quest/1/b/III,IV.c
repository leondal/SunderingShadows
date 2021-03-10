#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/b/III,III",
                "south" : pass_exit("4","III,I"),
                "east"  : MAZEDIR+"1/b/IV,IV",
                "west"  : MAZEDIR+"1/b/II,IV"
           ]) );
  set_pre_exit_functions( ({"south"}) , ({"go_south"}) );
}

int go_south()
{
  set_exits( ([
            "north" : MAZEDIR+"1/b/III,III",
            "south" : pass_exit("4","III,I"),
            "east"  : MAZEDIR+"1/b/IV,IV",
            "west"  : MAZEDIR+"1/b/II,IV"
           ]) );
  return 1;
}
