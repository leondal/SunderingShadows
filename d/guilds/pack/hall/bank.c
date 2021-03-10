#include <std.h>
#include "/d/guilds/pack/short.h"

inherit BANK;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("no steal", 1);
    set_short("%^BOLD%^%^BLUE%^Destiny Keep's Bank");
    set_long(
@SEETH
%^BOLD%^GREEN%^Welcome to Destiny Keep's Bank%^RESET%^
%^MAGENTA%^This is one of many banks connected to the network. As you look around the room, you notice there is a counter on the far wall, with a teller behind it. He looks bored. The rest of the bank is busy with customers. A sign by the teller details all commands. To the east is the %^YELLOW%^Gold storage room. %^RESET%^%^MAGENTA%^And to the north is the %^BOLD%^%^GREEN%^Guild Store.
SEETH
    );
    set_items( ([
	"sign" : "Reading it will give you a list of commands.",
	"teller" : "The teller awaits your decision.",
      ]) );
    set_exits( ([
    "west" : HALL "hall.c",
    //"east" : HALL "bookie.c",
    "north" : HALL "store1.c",
      ]) );

    set_smell("default", "The smell of money fills your nose.");
    set_listen("default", "The sounds of rustling coins fill your ears.");

}
