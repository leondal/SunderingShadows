
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
"northwest" : "/d/attaya/crafters/desert/stuff/slip_test",
]));


set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear the wind as it blows the sand.");

}


int climb_down() {

write("as you try to climb the icy cliffs you slip onto your ass and slide down the mountain!");
TP->do_damage(3,3);
if(random(2) == 1) {
TP->move("/d/attaya/crafters/desert/stuff/slip_testa");
} else {
TP->move("/d/attaya/crafters/desert/stuff/slip_testb");
}
}
