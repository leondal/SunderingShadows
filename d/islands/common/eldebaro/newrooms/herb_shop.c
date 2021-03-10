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
    set_name("Eastern oasis herbals and more");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis herbals and more%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^tables%^RESET%^"+
    "%^ORANGE%^ lining the walls, with various containers, of all different shapes and sizes organized carefully on "+
    "top of each. Something is %^RESET%^%^GREEN%^growing%^RESET%^%^ORANGE%^ inside each container, some of it is "+
    "impossible to identify. Beneath each table there are %^BOLD%^containers%^RESET%^%^ORANGE%^ with multiple locked "+
    "drawers. Everything that is growing looks remarkably healthy. In what you think is "+
    "probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening. There are a few smaller %^BOLD%^containers%^RESET%^%^ORANGE%^ "+
    "placed carefully on the surface of the counter, from which smaller plants are growing. "
    "A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA strange odor hangs heavily in the air here.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are numerous tables lining the walls of this "+
        "tent. There are containers of different shapes and sizes organized carefully on top of each table, with "+
        "something growing inside each. In the dead center of the tent is a "+
        "wooden counter in the shape of a half circle which faces the tent opening. There are a few smaller containers "+
        "placed carefully on the surface of the counter, from which smaller plants are growing.%^RESET%^",
        
        ({"tables", "containers", "growing", "drawers", "locked drawers"}) : "%^BOLD%^%^YELLOW%^"+
        "These tables line the walls of the tent. On the top of each, organized carefully, are containers of "+
        "various sizes and shapes. Inside each container something is growing and everything that is growing looks "+
        "remarkably healthy. Beneath each table there are other containers, each with multiple locked drawers."+
        "%^RESET%^",
        
        ({"counter", "wooden counter", "large counter"}) : "%^RESET%^%^GREEN%^This large wooden counter is in "+
        "the shape of a half circle and faces the opening of the tent. There are a few smaller containers placed "+
        "carefully on the surface of it, from which smaller plants are growing vibrantly.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"11"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("herb merchant")) find_object_or_load(ELMON+"herb_merchant")->move(TO);

}