// Inheritable Jungle Room for Volcania Island
// Thorn@ShadowGate
// jungleRoom.c

#include "/d/islands/volcania/volcania.h"

inherit ROOM;

create() {
        ::create();
        set_light(1);
        set_indoors(0);
        set_short("In the Jungle on Volcania Island");
        set_long(
@VOLCANIA
%^BOLD%^GREEN%^In the Jungle%^RESET%^
  You have found yourself in the middle of the dark, steamy jungles
of Volcania Island.  The vegetation here is so thick that you
have trouble passing.  You find your troubles are compounded by
the fact that the jungle seems to swallow up the path you just
took to get here while opening up new ones at the same time.  
Getting lost here seems a sure bet....
VOLCANIA
	);
	set_climate("tropical");
}

init() {
        ::init();
}

reset() {
        ::reset();
}

