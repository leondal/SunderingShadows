#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit MTUNNEL;

void create() {
  ::create();

  set_exits( ([ "north" : TUNNELS + "tun02" ,
                "south" : TUNNELS + "ugstream"]) );


  set_post_exit_functions(({"north",}),({"GoThroughDoor",}));

}

int GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }
  find_object_or_load(TUNNELS + "tun02")->enter_room();
  return 1;
}