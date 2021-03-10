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
    set_name("Eastern oasis crystal shop");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis crystal shop%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^boxes%^RESET%^"+
    "%^ORANGE%^ which line the walls of it. Each of the %^BOLD%^boxes%^RESET%^%^ORANGE%^ appears to be magically "+
    "sealed. They all look as if they are "+
    "in a specific and predetermined location though the reason for this is quite unknown. In what you think is "+
    "probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening. There are stacks of %^BOLD%^%^MAGENTA%^c%^CYAN%^r%^WHITE%^y"+
    "%^GREEN%^s%^WHITE%^t%^RED%^a%^BLACK%^l%^MAGENTA%^s %^RESET%^%^ORANGE%^lined up the entire length of it and are all "+
    "quite disorganized. "+
    "A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA strange odor hangs heavily in the air here.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are numerous boxes lining the walls of this "+
        "tent. Each of them is magically sealed but seems to be in a predetermined and specific location. "+
        "The purpose of this quite unknown. A large wooden counter in the shape of a half circle is set up in the "+
        "dead center of the tent, facing the opening. It is lined with stacks of crystals which seem remarkably "+
        "disorganized.%^RESET%^",
        
        ({"boxes", "magical sealed boxes", "sealed boxes"}) : "%^BOLD%^%^YELLOW%^"+
        "These magically sealed boxes are lined up and stacked almost to the ceiling of the tent along the "+
        "walls. You get the sense that each one is in a very specific and predetermined location. However, the "+
        "reason for this eludes you.%^RESET%^",
        
        ({"counter", "wooden counter", "large counter", "crystals"}) : "%^RESET%^%^GREEN%^This large wooden counter is in "+
        "the shape of a half circle and faces the opening of the tent. There are stacks of crystals the entire length of "+
        "it, which appear remarkably disorganized.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"12"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("psion merchant")) find_object_or_load(ELMON+"psion_merchant")->move(TO);

}