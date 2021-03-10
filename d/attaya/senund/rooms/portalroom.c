#include <std.h>
#include "../areadefs.h"
inherit VAULT;

void create()
{
        ::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(PAVED_ROAD);
    set_property("indoors", 1);
    set_property("light",2);
    set_property("no teleport",1);
    set_name("Portal Room");
    set_short("Portal Room");
        set_long(
@BRUENOR
%^BOLD%^%^CYAN%^The Portal Room%^RESET%^
You exit the portal and find yourself in a large room carved into rock.
The room is in the shape of a large sphere much like where you first 
appeared.  Once again a rock %^GREEN%^platform%^RESET%^ floats in the center of the room.
In front of you lies a %^YELLOW%^wooden bridge%^RESET%^ that leads to the %^GREEN%^platform%^RESET%^. Spaced 
out on the edge of the platform are five glowing giant sized %^CYAN%^mirrors%^RESET%^. 
BRUENOR
    );
    set_items( ([ "room": "This is a big room.",
                  "bridge": "The bridge is old a rickety but it should"+
                  " support your weight.",
                  "platform": "The platform you stand on seems to be"+
		  " somehow floating in midair. The ground below you"+ 
		  " is rather far away and there are no rails to keep"+
                  " you from falling over.",
                  "mirrors": "The mirrors are huge. When you look"+
                  " into them you cannot focus on you're reflection"+
                  " due to the wavy movement of the 'glass' surface.",
                  "gate" : "This gate is a large iron gate.  The gate"+
                  " completely blocks off the exit,  panning from the"+ 
                  " bottom to top of the cavern. It has a smaller gate"+
                  " which opens as a doorway within itself which appears"+ 
                  " unlocked. All you see beyond the gate is dark tunnels"
             ]) );

    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_door("iron gate",ROOMS+"rm35","west","gate key");
    set_door_description("iron door","This huge gate is made of rusty "+
                         "steel, thought it looks sturdy for its age.");
    set_string("iron gate","open","The large gate creeks open");
    set_exits( 
    ([
        "west" : ROOMS+"rm35",
        "redmirror" : "/d/islands/tonerra/mountain/mount2",
        "bluemirror" : "/d/shadow/room/pass/pass1",
        "yellowmirror" :"/d/laerad/wasteland/waste1",
        "greenmirror" : "/d/azha/town/wroad",
        "blackmirror" : "/d/attaya/seneca3"
    ]) );
}
void reset()
{
    ::reset();
  
}

