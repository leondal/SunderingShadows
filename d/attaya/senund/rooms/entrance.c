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
    set_name("Underground Entranceway");
    set_short("Underground Entranceway");
        set_long(
@BRUENOR
%^BOLD%^%^CYAN%^An Underground Entranceway%^RESET%^
You exit the %^BOLD%^%^MAGENTA%^portal%^RESET%^ and find yourself in a large room carved into rock.
The room is in the shape of a large sphere with a rock %^GREEN%^platform%^RESET%^ in the
center which you are now standing on. In front of you lies a %^YELLOW%^wooden
%^YELLOW%^bridge%^RESET%^ that leads to a large sealed gate.
You wonder if this is your last chance to turn back...
BRUENOR
    );
    set_items( ([ "room": "This is a big room.",
                  "bridge": "The bridge is old and rickety but it should"+
                  " support your weight.",
                  "platform": "The platform you stand on seems to be"+
		  " somehow floating in midair. The ground below you"+
		  " is rather far away and there are no rails to keep"+
                  " you from falling over. In the middle of the platform,"+
                  " where you walked out of the portal, are fancy looking"+
                  " runes",
                  "gate" : "This gate is a large iron gate.  The gate"+ 
                  " completely blocks off the exit,  panning from the"+ 
                  " bottom to top of the cavern. It has a smaller gate"+
                  " which opens as a doorway within itself which appears"+ 
                  " unlocked. All you see beyond the gate is dark tunnels"
              ]) );
    set_smell("default","No abnormal odor is present here.");
    set_listen("default","It is deathly quiet.");
    set_door("iron gate",ROOMS+"rm1","east","gate key");
    set_door_description("iron gate","This huge gate is made of rusty "+
                         "steel, thought it looks sturdy for its age.");
    set_string("iron gate","open","The large gate creaks open.");
    set_exits( 
    ([
        "east" : ROOMS+"rm1"
    ]) );
    set_pre_exit_functions(({"east"}),({"exitfn"}));

}
void reset()
{
    ::reset();
  
}

int exitfn() {
    tell_room(TP,"The gate slams shut behind you as you leave");
    tell_room(TO,""+TPQCN+" exits through the large gate",TP);
    return 1;
}  
