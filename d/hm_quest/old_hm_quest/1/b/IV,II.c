#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "north" : MAZEDIR+"1/b/IV,I",
                "south" : MAZEDIR+"1/b/IV,III",
                "east"  : pass_exit("2","I,II"),
                "west"  : MAZEDIR+"1/b/III,II"
           ]) );
  set_pre_exit_functions( ({"east"}) , ({"go_east"}) );
}

int go_east()
{
  set_exits( ([
                "north" : MAZEDIR+"1/b/IV,I",
                "south" : MAZEDIR+"1/b/IV,III",
                "east"  : pass_exit("2","I,II"),
                "west"  : MAZEDIR+"1/b/III,II"
           ]) );
  return 1;
}
