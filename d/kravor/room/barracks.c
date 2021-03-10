inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_property("indoors",1);
set_short("Keep barracks");
set_long(
@MILT
You step into what once was Kravor Keep's barracks.  This building used
to house some of the mightiest soldiers in the realms.  As you look around
the room you can almost envision the soldiers going about their daily
business.
MILT
);
set_exits((["out"  :  ROOMS + "keep3",
]));
}
