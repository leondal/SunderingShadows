#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(3);
  set_exits( ([
                "north" : MAZEDIR+"3/b/I,II",
                "south" : MAZEDIR+"3/b/I,IV",
                "east"  : MAZEDIR+"3/b/II,III",
                "west"  : pass_exit("2","IV,III")
           ]) );
  set_pre_exit_functions( ({"west"}) , ({"go_west"}) );
}

int go_west()
{
  set_exits( ([
                "north" : MAZEDIR+"3/b/I,II",
                "south" : MAZEDIR+"3/b/I,IV",
                "east"  : MAZEDIR+"3/b/II,III",
                "west"  : pass_exit("2","IV,III")
           ]) );
  return 1;
}
