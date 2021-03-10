#include "../defs.h"

inherit INH+"assassin";

void create()
{
    set_short("%^BOLD%^%^BLACK%^A Room of Doors%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A Room of Doors%^RESET%^
%^RESET%^%^ORANGE%^The light barely illuminates this room, leaving the edges of sight to fade into %^BOLD%^%^BLACK%^inky shadows%^RESET%^%^ORANGE%^. Filling up the rest of the room are a %^WHITE%^myriad %^ORANGE%^collection of %^MAGENTA%^doorways %^ORANGE%^and %^MAGENTA%^archways%^ORANGE%^, unattached to the walls and leaning against each other or piled in a heap together. A few of the doors have slipped ajar, letting strange lights and sounds filter into the room.%^WHITE%^
");
    set_smell("default","%^RESET%^%^GREEN%^Exotic scents drift in from the opened doors.%^WHITE%^");
    set_listen("default","%^RESET%^%^CYAN%^The sounds of a crowded city spill into the room.%^WHITE%^");
    set_items(([
                   ({"doorways", "archways", "doors"}) : "%^RESET%^%^MAGENTA%^Peeking through a few of the cracked or opened doors reveals a portal to another place, each entrance leading to a separate locale. ",
                   ({"floor","wall","ceiling"}) : "%^RESET%^%^ORANGE%^Dark stones, resilient but old, hold together this sunken tower. The persistent dampness from the flowing river outside of the crumbling walls allows for %^BOLD%^%^GREEN%^gr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^n m%^RESET%^%^GREEN%^o%^ORANGE%^s%^BOLD%^%^GREEN%^s %^RESET%^%^ORANGE%^to flourish between the cracks. %^CYAN%^Water %^ORANGE%^trickles in and pools in the corners of the uneven floors, making every slippery step seem perilous.%^WHITE%^",

                   ]));
    set_property("no teleport",1);
    set_indoors(1);
    set_exits(([
                   "east":ROOMS+"/assassinhall",
                   "asgard" :"/d/laerad/parnelli/asgard/as59",
                   "azha"   :"/d/tharis/road/wroad30",
                   "deku":"/d/deku/forest/dforest15-5",
                   "eldebaro":"/d/islands/common/eldebaro/newrooms/east_oasis15",
                   "graez":"/d/undead/rooms/town/street12",
                   "juran":"/d/shadow/room/forest/owagon26",
                   "kinaro":"/d/dagger/kinaro/path3",
                   "muuldaan":"/d/shadow/room/muuldaan/rooms/path6",
                   "shadow":"/d/darkwood/room/road18",
                   "seneca":"/d/attaya/newseneca/rooms/boardwalk3",
                   "tabor":"/d/darkwood/tabor/road/road1",
                   "tharis":"/d/tharis/road/road8",
                   "tonovi":"/d/dagger/tonovi/crossrd",
                   "torm":"/d/dagger/Torm/road/path12",
                   "antioch":"/d/antioch/antioch2/rooms/trail6",
                   ]));
}
