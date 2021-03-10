
#include <std.h>
#include "../tunnel.h"

inherit MTUNNEL;


void GoThroughDoor();

void create(){
    ::create();

    set_exits(([
                "southeast":TUNNELS + "tun05",
                "north":TUNNELS + "tun08",
      ]));

  set_post_exit_functions(({"north",}),({"GoThroughDoor",}));
}

void GoThroughDoor()
{
  find_object_or_load(TUNNELS+"tun08")->on_entry(TP);
}