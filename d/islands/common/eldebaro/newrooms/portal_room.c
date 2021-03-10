#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit "/std/psionportal";

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_name("Eastern oasis gets there with ease");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis get there with ease%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. Unlike most of the tents in the oasis this one is "+
    "mostly bare. However, in the dead center of it there is an %^BOLD%^odd circle%^RESET%^%^ORANGE%^ sewn into the fabric of "+
    "the tent. Small pillars made from precious rocks and gems in shades of %^BOLD%^%^BLUE%^blue%^RESET%^%^ORANGE%^, "+
    "%^RESET%^%^WHITE%^white%^RESET%^%^ORANGE%^, and %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^ are evenly spaced around the "+
    "circle. A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. "+
    "It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA strange odor hangs heavily in the air here.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^This tent is mostly bare, save for the circle sewn into the "+
        "dead center of it, the pillars spaced evenly around it, and the large bed in the back corner.%^RESET%^",
        
        ({"circle", "odd circle"}) : "%^BOLD%^%^YELLOW%^"+
        "This perfect circle has been carefully stitched into the fabric of the tent. There appears to be some "+
        "glittering dust sprinkled through out it though you are unsure of its purpose.%^RESET%^",
        
        ({"pillars", "gems", "rocks", "gem pillars", "rock pillars"}) : "%^BOLD%^%^CYAN%^There are six of these pillars, "+
        "spaced evenly around the cirlce. Each is made of a mixture of rock and precious gems in shades of blue, white, and "+
        "black, though you cannot determine with any certainty what the mixture is.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"14"]));
    add_location("azha",0,55,"/d/azha/town/wroad");
    add_location("torm",0,55,"/d/dagger/Torm/road/path12");
    add_location("verbobone",15,75,"/d/deku/town/road13");
    add_location("seneca",25,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("enclave",10,75,"/d/shadow/room/city/portal/foyer");
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("portalpsion")) find_object_or_load(ELMON+"portal_psion")->move(TO);

}