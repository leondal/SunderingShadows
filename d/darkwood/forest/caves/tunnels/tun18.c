#include <std.h>

inherit ROOM;

void create()
{
  ::create();
  set_property("light",0);
  set_property("indoors",1);
  set_short("a dark tunnel");
  set_long("%^BLUE%^a Dark Tunnel%^RESET%^\n"
           "This tunnel leads far down into the earth below the Darkwoods. "
           "It is dark and damp and makes you feel most unwelcome. Upon "
           "a cursory inspection of the walls and floor you determine "
           "that the tunnel is neither made by nature or man.");
  set_smell("default","A heavy musk hangs in the air.");
  set_listen("default","You hear something scrapping against the stone "
             "walls and floor from somewhere deeper in the tunnel.");
  set_exits( ([
     "east" : "/d/darkwood/forest/caves/tunnels/tun19",
     "west" : "/d/darkwood/forest/caves/tunnels/tun17"
	       ]) );
  }
