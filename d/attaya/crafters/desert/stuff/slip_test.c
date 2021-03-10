
#include <std.h>
inherit ROOM;
void create(){
    :: create();
    set_light(2);
    set_property("indoors", 0);
    set_climate("arctic");
    set_short("%^ORANGE%^You have suddenly entered a frozen place.%^RESET%^
");
set_long(
@ZERINA
%^ORANGE%^You have suddenly entered a frozen place.%^RESET%^
The wind and weather here has suddenly become very cold. Snow and
ice cover the ground as you wander close to the Crafters Stronghold.
You ponder yet again the wisdom of traveling further. It would almost
seem as if this wall of cold was conjured here by some unknown force...
to keep the power and evil within and those not wanted out.
You are moving uphill now. 

ZERINA
);

set_items(([
"ice" : "The ice is so cold it would appear to almost have a blue inge to it.",
]));

set_exits(([
"northwest" : "/d/attaya/crafters/desert/stuff/slip_testa",
"northeast" : "/d/attaya/crafters/desert/stuff/slip_testb",
"southwest" : "/d/attaya/crafters/desert/stuff/slip_testc",
"southeast" : "/d/attaya/crafters/desert/stuff/slip_testd",
]));

set_pre_exit_functions( ({"northwest"}), ({"climb_down"}) );
set_pre_exit_functions( ({"northeast"}), ({"climb_down"}) );
set_pre_exit_functions( ({"southwest"}), ({"climb_down"}) );
set_pre_exit_functions( ({"southeast"}), ({"climb_down"}) );

set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear the wind as it blows the sand.");

}


int climb_down() {

write("it works");
return 1;
}
