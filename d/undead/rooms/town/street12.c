#include "../../undead.h"
inherit INH+"street";

void create() {
    ::create();
    set_long(::query_long() +"  South of here opens a small section of the "
"city's fortified walls, revealing a %^ORANGE%^dock %^RESET%^jotting out onto "
"onto the waves of the ocean.\n\n%^BOLD%^%^MAGENTA%^There is a sign here"
".%^RESET%^\n");

    set_items(([
      ({"sign","laws"}) : ({"At the entrance to this town, a rough sign has "
"been staked prominently.  The short message upon it has been scrawled in "
"several languages to be better understood.  You should probably read "
"it.","\n%^YELLOW%^Visitors to Graez:\n\n%^BOLD%^%^CYAN%^-no stealing town "
"property\n-no damaging town property\n-no killing city guards or "
"land owners\n\n%^YELLOW%^Visitors to Graez travel at their own risk - the "
"city does not take responsibility for your wellbeing or your "
"belongings%^RESET%^","wizish"}),
    ]));
    set_exits(([
        "north":TOWN"street1",
        "south":"/d/shadow/virtual/sea/undead.dock",
        "east":TOWN"street11",
        "west":TOWN"street13"
    ]));
}
