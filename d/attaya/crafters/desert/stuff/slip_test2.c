
#include <std.h>
inherit ROOM;
void init(){
    ::init();
    add_action("climb_fun", "climb");
}
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

set_climb_exits(([
"climb" : ({"/d/attaya/crafters/desert/stuff/slip_test3.",5,40,400}),
"descend" : ({"/d/attaya/crafters/desert/stuff/slip_test.c",4,50,500}),

]));

set_smell("default", "You can smell nothing.");
set_listen("default", "You can hear the wind as it blows the sand.");

}
int climb_fun(string str) {
if(!str){
notify_fail("What?\n");
return 0;
}
write("You slip while trying to walk south.");
say(this_player()->query_cap_name()+" slips while trying to climb the hill!", this_player());
this_player()->add_hp(-80);
return 1;
}
