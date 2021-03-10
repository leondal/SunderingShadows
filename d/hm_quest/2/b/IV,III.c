#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "north" : MAZEDIR+"2/b/IV,II",
                "south" : MAZEDIR+"2/b/IV,IV",
                "east"  : pass_exit("3","I,III"),
                "west"  : MAZEDIR+"2/b/III,III"
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "north" : MAZEDIR+"2/b/IV,II",
                "south" : MAZEDIR+"2/b/IV,IV",
                "east"  : pass_exit("3","I,III"),
                "west"  : MAZEDIR+"2/b/III,III"
           ]) );
  return 1;
}
