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
    set_name("Eastern oasis armor shop");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis armor shop%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are %^BOLD%^various armors"+
    "%^RESET%^%^ORANGE%^ set up on %^BOLD%^display "+
    "%^RESET%^%^ORANGE%^around the walls of it, which makes the purpose of this "+
    "particular tent quite obvious. In what you think is probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening and is itself "+
    "decorated with several %^BOLD%^shiny shields%^RESET%^%^ORANGE%^. A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. There are pieces of different armors laying around the tent, as if someone is "+
    "either in the process of creating or repairing them. There are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nThis place smells slightly of body odor.%^RESET%^");

    set_items(([
        ({"tent", "large tent", "armor tent", "pieces of armor" }) : "%^RESET%^%^ORANGE%^This large tent is quite cluttered with "+
        "pieces of different armors laying around it, as if someone is either in the process of creating or repairing them. "+
        " There are various armors set up on display around the walls of it. "+
        "A wooden counter in the shape of a half circle rests in the dead center of it. It is decorated with several shiny "+
        "shields and set up so that it faces the tent opening. A large and comfortable bed rests in the back corner.",
        
        ({"armors", "various armors", "shields", "shiny shields"}) : "%^BOLD%^%^WHITE%^"+
        "There are various armors of different sizes and types on display around the walls of the tent. There are also several "+
        "shiny shields decorating the wooden counter that rests in the center of the tent. Each of those which is complete look to be "+
        "in remarkable condition. However, there are several pieces of different armors scattered through the tent, as if someone "+
        "is either in the process of creating or repairing them.%^RESET%^",
        
        ({"wooden counter", "counter", "half circle counter"}) : "%^RESET%^%^GREEN%^This large wooden counter is quite dull and "+
        "showing its age, though it still looks quite solid. It is set in the center of the tent and faces the opening, as if to invoke the "+
        "immediate attention of anyone who enters. There are several shiny shields attached, as a sort of decoration, to the front of "+
        "it.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"7"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("armor merchant")) find_object_or_load(ELMON+"armor_merchant")->move(TO);

}