//  /d/dragon/town/balcony.c
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("Church of Sanctuary");
    set_long("%^BOLD%^%^BLUE%^
This is the balcony overlooking inside the temple.  There are several 
rows of benches here for the choir to sit on.  Along the back wall is a
huge organ with hundreds of pipes lining the entire back wall.  You
would guess that it would fill the entire church with music.  Looking
over the balcony you see the temple below and the sight is overwhelming.
The way the light comes through the windows is breathtaking.
  ");
    set_exits(([
       "down" : "/d/dragon/town/church"
    ] ));
    set_items(([
    ] ));
}
