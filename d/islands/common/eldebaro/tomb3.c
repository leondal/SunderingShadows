#include <std.h>
#include <daemons.h>
#include "area_stuff.h"
#include <move.h>
inherit ROOM;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_climate("arctic");
    set_name("Inside an ebon chamber");
    set_short("%^BOLD%^%^BLACK%^Inside a %^BOLD%^%^CYAN%^fr%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^g"+
    "%^BOLD%^%^WHITE%^i%^BOLD%^%^CYAN%^d%^BOLD%^%^BLACK%^ ebon chamber%^RESET%^");
    
    
    set_long("%^BOLD%^%^BLACK%^You find yourself in a very large chamber composed of interlocked "+
    "%^BOLD%^%^WHITE%^ebon stones%^BOLD%^%^BLACK%^. The very first thing that you notice here is that "+
    "it is freezing, a %^BOLD%^%^CYAN%^cold%^BOLD%^%^BLACK%^ and %^BOLD%^%^CYAN%^frigid%^BOLD%^%^BLACK%^ "+
    "air hangs heavily in here, almost as if it has been somehow trapped by the %^BOLD%^%^WHITE%^stones"+
    "%^BOLD%^%^BLACK%^ or perhaps it is radiating outward from the stones. Strange %^BOLD%^%^CYAN%^"+
    "symbols%^BOLD%^%^BLACK%^ cover everything, you get the sense that they are serving as some "+
    "type of %^BOLD%^%^CYAN%^ward%^BOLD%^%^BLACK%^ but for what you are not sure. The entire chamber "+
    "looks ancient but seems so sturdy that no amount of time would ever have the power to erode it. "+
    "In the center of the chamber there are three pedestals forming a triangle around a fourth. The pedestals "+
    "look important and very old, perhaps even older than the chamber itself. They are all that has been "+
    "untouched by the %^BOLD%^%^CYAN%^strange symbols%^BOLD%^%^BLACK%^.%^RESET%^");
    

    set_listen("default", "%^CYAN%^\nYour footsteps echo through the chamber and loud "+
    "cracking sounds are heard all around you.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells ancient and an odor of stagnation hangs "+
    "heavily here.%^RESET%^");

    set_items(([
        ({"symbols", "glowing symbols", "strange symbols", "ward"}) : "%^BOLD%^%^CYAN%^These strange symbols cover "+
        "everything in this chamber, save for the pedestals. They are not in any language that you have ever before encountered, in fact "+
        "you are unsure if they actually mean that you could understand at all. You do get some sense that they are "+
        "serving as a ward of some type, though you are not sure for what. Simply looking at them "+
        "fills you with a strong urge to %^BOLD%^%^BLACK%^observe%^BOLD%^%^CYAN%^ them. %^RESET%^",
        
        ({"chamber", "large chamber", "stones", "ebon stones", "walls", "floor", "ceiling"}) : "%^BOLD%^%^BLACK%^This chamber is massive and "+
        "composed entirely of interlocked ebon stones. The floor, the ceiling, and the walls are composed of these "+
        "same stones. Each is covered with %^BOLD%^%^CYAN%^strange symbols%^BOLD%^%^BLACK%^ and each is giving "+
        "off a %^BOLD%^%^WHITE%^freezing cold aura%^BOLD%^%^BLACK%^, which chills the entire chamber. The chamber "+
        "looks ancient but seems so sturdy that not even time would be enough to erode the stones which compose "+
        "it.%^RESET%^",
        
        ({"pedestal", "pedestals"}) : (:TO, "pedestal_desc":),
        ({"pedestal 1", "first pedestal"}) : (:TO, "pedestal_one":),
        ({"pedestal 2", "second pedestal"}) : (:TO, "pedestal_two":),
        ({"pedestal 3", "third pedestal"}) : (:TO, "pedestal_three":),
        ({"pedestal 4", "fourth pedestal", "center pedestal"}) : (:TO, "pedestal_four":),
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    
    set_property("traps_known_to_monsters", ELMON);
    set_property("random trap frequency", 85);
    set_property("random traps", "epic");
   
    if(!present("Enormous ice block", TO)) 
    {
        new(ELOB+"asantra_ice_block")->move(TO);        
    }
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^CYAN%^A frigid cold hangs heavily here.%^RESET%^";
}

//eventually these pedestals will unlock the way into the large tombs - but for now they are simply "decoration" - Saide

string pedestal_desc()
{
    string ret;
    ret = "%^RESET%^%^MAGENTA%^Three pedestals here form a perfect triangle around a fourth that has been carefully "+
    "placed in the center of the triangle. Atop each of the pedestals extend three %^BOLD%^%^WHITE%^bony fingers"+
    "%^RESET%^%^MAGENTA%^ each curled at the tip and you think that maybe at one point in time you could have "+
    "placed something in each. However, you get the sense that whatever magic was once contained in them is "+
    "either now dead or currently defunct. You could look more closely at each pedestal if you were so inclined.%^RESET%^";
    
    return ret;
}

string pedestal_one()
{
    string ret;
    ret = "%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^bony fingers%^RESET%^%^MAGENTA%^ extending from the top "+
    "of this pedestal face the center of the triangle. Beneath them and barely noticeable is the word '%^BOLD%^%^CYAN%^"+
    "origato%^RESET%^%^MAGENTA%^'.%^RESET%^";
    
    return ret;
}
string pedestal_two()
{
    string ret;
    ret = "%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^bony fingers%^RESET%^%^MAGENTA%^ extending from the top "+
    "of this pedestal face the center of the triangle. Beneath them and barely noticeable is the word '%^BOLD%^%^CYAN%^"+
    "ve%^RESET%^%^MAGENTA%^'.%^RESET%^";
    
    return ret;    
}
string pedestal_three()
{
    string ret;
    ret = "%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^bony fingers%^RESET%^%^MAGENTA%^ extending from the top "+
    "of this pedestal face the center of the triangle. Beneath them and barely noticeable is the word '%^BOLD%^%^CYAN%^"+
    "crodr%^RESET%^%^MAGENTA%^'.%^RESET%^";
    
    return ret;
}
string pedestal_four()
{
    string ret;
    ret = "%^RESET%^%^MAGENTA%^The %^BOLD%^%^WHITE%^bony fingers%^RESET%^%^MAGENTA%^ extending from the top "+
    "of this pedestal seem to almost point toward the ceiling. Beneath them and barely noticeable is the word '%^BOLD%^%^CYAN%^"+
    "jaka%^RESET%^%^MAGENTA%^'.%^RESET%^";
    
    return ret;
}


void init()
{
    ::init();
    add_action("observe_symbols", "observe");
}

int observe_symbols(string str)
{
    object ob;
    if(!objectp(TO)) return 0;
    if(!objectp(TP)) return 0;
    if(!stringp(str)) return 0;
    if(str != "symbols" && str != "strange symbols" && str != "glowing symbols") { return 0; }
    if (TP->query_bound() || 
    TP->query_unconscious() || 
    TP->query_paralyzed()) 
    {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    if(present("eldebarosymbolobservationxxsaide", TP))
    {
        tell_object(TP, "You are already observing the symbols!");
        return 1;
    }
    ob = new(ELOB+"symbol_observation");
    ob->move(TP);
    ob->start_observing();
    
    return 1;
}

void reset()
{
    ::reset();
    if(random(8)) return;
    if(!present("Enormous ice block", TO) && !present("asantra", TO)) 
    {
        new(ELOB+"asantra_ice_block")->move(TO);
    }
}