
#include <std.h>
#include "../tunnel.h"

inherit HTUNNEL;

void create(){
  ::create();
  set_exits( ([ "north" : TUNNELS + "tun14" ,
	          "southeast" : TUNNELS + "tun12"]) );
  set_post_exit_functions(({"north",}),({"GoThroughDoor",}));

}

int GoThroughDoor()
{
  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }

  find_object_or_load(TUNNELS + "tun14.c")->enter_room();
  return 1;
}
