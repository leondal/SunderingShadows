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
    set_name("Eastern oasis weapon shop");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis weapon shop%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are %^BOLD%^numerous weapons"+
    "%^RESET%^%^ORANGE%^ set up on %^BOLD%^display "+
    "%^RESET%^%^ORANGE%^around the walls of it, which makes the purpose of this "+
    "particular tent quite obvious. In what you think is probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening and is itself "+
    "decorated with several %^BOLD%^fine weapons%^RESET%^%^ORANGE%^. A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is remarkably %^BOLD%^well kept%^RESET%^%^ORANGE%^ and "+
    "%^BOLD%^clutter%^RESET%^%^ORANGE%^ free, with each item "+
    "incredibly well organized. It is also amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells slightly of body odor.%^RESET%^");

    set_items(([
        ({"tent", "large tent", "weapons tent", "well kept", "clutter free" }) : "%^RESET%^%^ORANGE%^This large tent is very well kept and "+
        "clutter free. There are numerous weapons set up on display around the walls of it. "+
        "A wooden counter in the shape of a half circle rests in the dead center of it. It is decorated with several fine "+
        "weapons and set up so that it faces the tent opening. A large and comfortable bed rests in the back corner.",
        
        ({"weapons", "numerous weapons", "fine weapons" }) : "%^BOLD%^%^WHITE%^"+
        "There are weapons of all types on display around the walls of the tent. There are also several "+
        "fine weapons decorating the wooden counter that rests in the center of the tent. Each of them are very well organized and "+
        "well kept.%^RESET%^",
        
        ({"wooden counter", "counter", "half circle counter"}) : "%^RESET%^%^GREEN%^This large wooden counter almost shines, as if it "+
        "is frequently and perhaps obsessively polished. It is set in the center of the tent and faces the opening, as if to invoke the "+
        "immediate attention of anyone who enters. There are several fine weapons attached, as a sort of decoration, to the front of "+
        "it.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"9"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("weapon merchant")) find_object_or_load(ELMON+"weapon_merchant")->move(TO);

}