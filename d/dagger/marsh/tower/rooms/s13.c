#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit TROOM;

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_property("no teleport",1);
set_short("%^BLUE%^The Shadowland");
    set_long("%^CYAN%^"
	"The strange %^GREEN%^land%^CYAN%^ before you is extremely hard "
	"to see clearly due to the swirling %^MAGENTA%^mist%^CYAN%^ "
	"and numerous "
	"%^BLUE%^shadowy shapes%^CYAN%^ which surround you. Things "
	"seem to come into focus then "
	"fade away again. Moving %^BLUE%^shadows%^CYAN%^ "
	"roam and wander, swaying wildly in the "
	"howling %^ORANGE%^wind%^CYAN%^ in all directions. The %^ORANGE%^wind%^CYAN%^ "
	"never remains constant, it rises in tempo and shifts in "
	"direction with every heartbeat. The %^WHITE%^sky%^CYAN%^ is grey and filled with a "
	"%^MAGENTA%^smoky mist%^CYAN%^. %^BLUE%^Shadowy shapes%^CYAN%^ "
	"fly overhead in random "
	"erratic patterns. The two %^BOLD%^%^MAGENTA%^purple moons "
	"%^RESET%^%^CYAN%^fill the land with a faint eerie incandescent %^YELLOW%^light"
	"%^RESET%^%^CYAN%^.%^RESET%^"
    );
    set_listen("default",
        "The wind blows hard against your face, and a faint whispering coupled with a hollow moaning fills the mist."
    );
    set_smell("default",
        "There is a very foul and evil smell to this new land around you."
    );
    set_items(([
	"moon":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
 	"land":"You would have to enter the %^BLUE%^Shadowland%^RESET%^ to examine "
	"it closer.",
	"moons":"%^MAGENTA%^The two purple moons are very eerie to gaze upon and light the area with an "
	"incandescent glow.%^RESET%^",
	"shadows":"%^BLUE%^The shadows fill the land below and dance and stir in the wind.",
	"shapes":"%^CYAN%^The shapes move around you occasionally and are hard to make out. Every now and "
	"then a shadowy shape flies overhead.",
    ]));
    set_exits(([
        "west": RPATH "s12",
	"northeast": RPATH "s18",
	"southeast": RPATH "s9",
    ]));
    set_pre_exit_functions(({"southeast"}),({"exita_fun"}));
    set_pre_exit_functions(({"west"}),({"exita_fun"}));
    set_pre_exit_functions(({"northeast"}),({"exita_fun"}));
}
int exita_fun() {
    write(
        "%^BLUE%^You slowly wander through the mist and walk among the shadows."	
    );
    say(
 	"%^BLUE%^"+TPQCN+" slowly wanders through the mist and walks among the shadows."
    ,TP);
    return 1;
}
