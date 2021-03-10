inherit "/std/room";
#include "kravor.h"

inherit ROOM;

create(){

  ::create();

set_property("light",2);
set_short("Keep gate");
set_long(
@MILT
You stand before the gates of Kravor Keep.  Once standing proud and
impenetrable, these gates including the wall surrounding the keep have
kept countless invaders out and peace and safety within.  But over the
centuries the keep slowly fell into ruins as all great things do and
what you see in front of you is only a reminder of a once great past.
MILT
);
set_items((["gates":"You gaze upon the once mighty gates of Kravor Keep which now are rusted and broken beyond any use."]));
set_smell("default","The vibrant smells of the forest fills your nostrals.");
set_listen("default","You hear the chirping of birds.");
set_exits((["north"  : ROOMS + "keep1",
            
]));
}
