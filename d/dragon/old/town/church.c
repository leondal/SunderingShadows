//  /d/dragon/town/church.c
#include <std.h>
#include <objects.h>

int AL;

inherit VAULT;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_door("door","/d/dragon/town/grave1","north",0);
    set_open("door", 0);
    set_string("door","open","You open the door that leads you to the graveyard.");
    set_short("Church of Sanctuary");
    set_long("%^BOLD%^%^BLUE%^
You're inside the %^CYAN%^%^BOLD%^Temple of Alphonsus%^BOLD%^BLUE%^.  The temple is the only thing within the
city that is still beautiful.  Stained glass windows covers the west and
east walls of the church.  This church could easily hold 1000 people, but
there aren't that many people within the city limits.  Looking in the back
of the church you see a large balcony where the choir usually would be
seated during services.  Also toward the north, you see a barred door.  
There is also a set of stairs leading up to the balcony.\n");
    set_exits(([
       "up" : "/d/dragon/town/balcony",
       "down" : "/d/dragon/town/healer",
       "south" : "/d/dragon/town/roadW4",
       "north" : "/d/dragon/town/grave1"
    ] ));
    set_items(([
    ] ));
}

