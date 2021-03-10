#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit "/std/church";

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_name("Eastern oasis church");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis church%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. Unlike most of the tents in the oasis this one is "+
    "mostly bare. However, in the dead center of it there is a %^BOLD%^%^BLACK%^stone altar"+
    "%^RESET%^%^ORANGE%^. Around the altar there are several comfortable and %^BOLD%^%^MAGENTA%^plush%^RESET%^%^ORANGE%^"+
    " chairs. Along the northern wall of the tent there multiple locked %^BOLD%^containers%^RESET%^%^ORANGE%^, each have several "+
    "drawers which slide out when unlocked. A few large and %^BOLD%^comfortable beds%^RESET%^%^ORANGE%^"+
    " rests along the far wall. Each is big enough for a few people to sleep comfortably in. "+
    "It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThe smell of the ocean drifts into the tent.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^This tent is mostly bare. A stone altar rests in "+
        "the dead center of it. Around the altar there are several comfortable and plush chairs. Along the "+
        "northern wall there are multiple locked containers, each with several "+
        "drawers which slide out when unlocked. A few large and comfortable beds rests along the far wall, each "+
        "big enough for a few people to sleep comfortably in.%^RESET%^",
        
        ({"altar", "stone altar"}) : "%^BOLD%^%^BLACK%^"+
        "This stone altar rests in the dead center of the tent. It looks quite simple and plain, though it serves the "+
        "purpose of allowing the dead to find their way here.%^RESET%^",
        
        ({"chairs", "plush chairs", "comfortable chairs"}) : "%^BOLD%^%^MAGENTA%^These comfortable plush chairs have been "+
        "set up around the altar. They have been placed here to allow the weary to rest.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"beds", "comfortable beds"}) : "%^BOLD%^%^YELLOW%^These large and comfortable eds rests along the far wall of the "+
        "tent. It looks like several people could sleep in each of them without any issues at all.%^RESET%^",
        
        ({"containers", "locked containers", "drawers"}) : "%^BOLD%^%^YELLOW%^These large locked containers "+
        "line the north wall of the tent. They are lined with drawers which pull out easily when they are unlocked.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"10"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();

}