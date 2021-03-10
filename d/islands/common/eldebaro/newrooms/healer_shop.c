#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit HEALER;

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_name("Eastern oasis house of health");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis house of health%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^shelves%^RESET%^"+
    "%^ORANGE%^ which line the walls of it. Each of the shelves is stacked full of %^RESET%^%^GREEN%^herbs%^RESET%^"+
    "%^ORANGE%^, %^BOLD%^%^CYAN%^vials%^RESET%^%^ORANGE%^, %^RESET%^%^MAGENTA%^salves%^RESET%^%^ORANGE%^, and "+
    "%^BOLD%^powders%^RESET%^%^ORANGE%^ of various types. They all look remarkably well organized, as if they are "+
    "in a specific and predetermined location, likely to make retrieval when they are needed much quicker. In the dead center "+
    "of it there are several large and %^BOLD%^%^MAGENTA%^pl%^RESET%^%^MAGENTA%^u%^BOLD%^sh chairs%^RESET%^%^ORANGE%^ set up in "+
    "a circle. You recognize that there purpose is to make those who have to visit here as comfortable as possible. "+
    "A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is remarkably %^BOLD%^well kept%^RESET%^%^ORANGE%^ and "+
    "%^BOLD%^clutter%^RESET%^%^ORANGE%^ free, with each item "+
    "incredibly well organized. It is also amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells remarkably clean and fresh.%^RESET%^");

    set_items(([
        ({"tent", "large tent", "well organized"}) : "%^RESET%^%^ORANGE%^This large tent is very well organized, perhaps "+
        "obsessively so. There are numerous shelves set up around the walls of it, which are stacked full of herbs, "+
        "vials, salves, and powder, all of which seem to be in a specific and predetermined location. "+
        "A circle of large and plush chairs are set up in the center of it, as a means to make any required "+
        "visit here as comfortable as possible.%^RESET%^",
        
        ({"herbs", "vials", "salves", "powders", "shelves", "numerous shelves" }) : "%^BOLD%^%^YELLOW%^"+
        "There are numerous shelves lining the walls of the tent. They are stacked full of herbs, vials, salves, and "+
        "powder, all of which look remarkably well organized. It appears that each is in some specific and predetermined "+
        "location. Likely this is to make it so that retrieval of them, when they are needed, is as quick as possible.%^RESET%^",
        
        ({"chairs", "large chairs", "plush chairs"}) : "%^BOLD%^%^MAGENTA%^These chairs are set up in a circle in the "+
        "center of the tent. They all look quite comfortable, very clean, and in remarkable condition. It is obvious that they "+
        "are intended to make any required visit to this place as comfortable as possible for the one seeking treatment.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"5"]));
    set_name("nomad");
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("eldebaro_healer")) find_object_or_load(ELMON+"healer_npc")->move(TO);

}