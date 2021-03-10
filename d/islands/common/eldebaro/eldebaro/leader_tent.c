#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit ROOM;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_property("no teleport", 1);
    set_property("scry proof", 1);
    set_name("Eastern oasis command post");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis command post%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears slightly larger inside. However, it is somewhat cramped because of "+
    "several %^RESET%^%^GREEN%^tables%^RESET%^%^ORANGE%^ set up in the center of it. There are various %^BOLD%^maps"+
    "%^RESET%^%^ORANGE%^ and %^BOLD%^writings%^RESET%^%^ORANGE%^ scattered all over them. There are also "+
    "several engravings of an %^BOLD%^%^WHITE%^upright skeletal arm holding a scales of justice%^RESET%^%^ORANGE%^, "+
    "the recognizable symbol of %^RESET%^%^WHITE%^Lysara%^RESET%^%^ORANGE%^ on each of the tables. The material "+
    "of the tent is even more impressive from the inside, it is %^BOLD%^%^CYAN%^m%^BOLD%^%^MAGENTA%^u%^BOLD%^%^WHITE%^"+
    "l%^BOLD%^%^YELLOW%^t%^BOLD%^%^GREEN%^i%^BOLD%^%^CYAN%^c%^BOLD%^%^MAGENTA%^o%^BOLD%^%^WHITE%^l%^BOLD%^%^YELLOW%^o"+
    "%^BOLD%^%^GREEN%^r%^BOLD%^%^CYAN%^e%^BOLD%^%^MAGENTA%^d%^RESET%^%^ORANGE%^ and appears very thick. "+
    "There are %^BOLD%^%^CYAN%^magical runes%^RESET%^%^ORANGE%^ stitched onto it, forming patterns. You "+
    "think that the runes serve the purpose of some type of warding from something. You are just "+
    "not sure what. A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^ rests in the back corner. It is "+
    "big enough for a few people to sleep comfortably in. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^%^RESET%^");
    
    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThe lingering odor of magic hangs heavily in the air.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^This tent is slightly larger on the inside. However, it "+
        "is quite cramped because of several tables set up in the center of it. The material that composes this "+
        "tent is quite remarable. It is multicolored and very thick, with magical runes stitched onto it in "+
        "patterns. They serve as some type of warding.%^RESET%^%^RESET%^",
        
        ({"tables", "writings", "maps", "engravings"}) : "%^BOLD%^%^WHITE%^"+
        "%^RESET%^%^GREEN%^These tables have been set up in the center of the tent here, making the "+
        "tent much more cramped than it otherwise would be. They are covered with writings, maps, and "+
        "engravings of the symbol of Lysara. The writings and maps mostly seem unimportant, however, "+
        "one larger map is shrouded by something and no matter how you look at it, you cannot make out "+
        "any locations on it. It seems to be a map of the Eldebaro Island, but for whatever reason it "+
        "has obviously been warded against prying eyes.%^RESET%^",
        
        ({"material", "magical runes", "patterns", "warding"}) : "%^BOLD%^%^CYAN%^These magical runes "+
        "are stitched into the multicolored material that the tent is composed of. They are stitched in "+
        "obvious patterns and you are able to tell that they serve as a type of warding.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. %^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"8"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("dyveryll wyndar")) find_object_or_load(ELMON+"dyveryll_wyndar")->move(TO);
}