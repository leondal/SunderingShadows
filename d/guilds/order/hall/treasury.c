#include <std.h>

inherit ROOM;
inherit "/d/guilds/inherit/g_money.c";

void create() {
    room::create();
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_property("light", 2);
    set_property("night light", 2);
    set_short("%^BOLD%^Treasury of the Order");
    set_long(
@DESC
   %^BOLD%^%^YELLOW%^Treasury of the Order%^RESET%^
 %^BOLD%^%^BLUE%^You enter into a large, open, chamber with guards standing at either side of the door. Piles of %^RESET%^%^BOLD%^%^YELLOW%^gold%^RESET%^%^BOLD%^%^BLUE%^ lay piled around you, the %^RESET%^%^BOLD%^light%^RESET%^%^BOLD%^%^BLUE%^ almost blinding you as it reflects off of each coin's shiny surface. On the far wall you notice a sign, detailing what you may do here.%^RESET%^
DESC
    );
    set_exits( ([
          "west":"/d/guilds/order/hall/main2.c"

      ]) );
}

void init() {
    room::init();
    money::init();
}
