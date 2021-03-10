#include <std.h>
#include "darcy.h"

inherit ROOM;

void create(){
    ::create();
    set_property("light" , 1);
    set_property("indoors" , 1);
    set_short("A Cavern Below the Chateau");
    set_long(
@DARCY
%^BOLD%^A Cavern Below the Chateau%^RESET%^
  You are in a tunnel under the Chateau d'Arcy. This tunnel, unlike
the rest of the tunnels and caves in the cavern appears to have been
man made by mining through solid rock.  The air in here is damp, and
musty with a slight scent of burning wood. You see lit torchs all
along the walls of the tunnel, making the cave at least visible if
not exactly cheerful.

  This gallery opens up on a manmade chamber to the north and another
section of torchlit tunnel to the south.

DARCY
);
    set_exits(([
        "north"       :  ROOMDIR+"1to2",
        "south"       :  ROOMDIR+"cav6"
    ]));
    set_smell("default","There is a damp and musty scent here.");
    set_listen("default","You hear the dripping of water.");
}

void init(){
	::init();
	do_random_encounters(({ MONDIR+"merc" }),40,2);
}

