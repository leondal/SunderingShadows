#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "north" : MAZEDIR+"3/a/I,II",
                "east"  : MAZEDIR+"3/a/II,III",
                "west"  : pass_exit("2","IV,III")
           ]) );
  set_pre_exit_functions( ({"west"}) , ({"go_west"}) );
}

int go_west()
{
  set_exits( ([
                "north" : MAZEDIR+"3/a/I,II",
                "east"  : MAZEDIR+"3/a/II,III",
                "west"  : pass_exit("2","IV,III")
           ]) );
  return 1;
}
