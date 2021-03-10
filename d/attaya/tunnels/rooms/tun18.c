#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit BTUNNEL;


void create() {
  ::create();


  set_exits( ([ "west" : TUNNELS + "tun17" ,
	          "east" : TUNNELS + "tun19",]) );
  set_post_exit_functions(({"east",}),({"GoThroughDoor",}));


}


int Go_Through_Door(string str)
{

  if (!TP->is_player()||TP->query_true_invis())
  {
    return 1;
  }

  find_object_or_load(TUNNELS+"tun19")->enter_room();
  return 1;
}