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
    set_name("Eastern oasis components shop");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis components shop%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^shelves%^RESET%^"+
    "%^ORANGE%^ which line the walls of it. Each of the %^BOLD%^shelves%^RESET%^%^ORANGE%^ is stacked full of "+
    "various spell components, some of them drip down on the ones below them, making %^BOLD%^hissing sounds%^RESET%^%^ORANGE%^ and "+
    "puffs of %^RESET%^%^WHITE%^smoke%^RESET%^%^ORANGE%^. "+
    "They all seem quite disorganized at first glance but you quickly realize that they seem to be grouped "+
    "with similar items. In what you think is "+
    "probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening. The counter seems to be quite bare and clean, as if it "+
    "wiped off regularly and judging by some of the components you can easily understand why. "
    "A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA strange odor hangs heavily in the air here.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are numerous shelves lining the walls of this "+
        "tent. Each of them is stacked full of various spell components, some of them drip down on the ones below "+
        "them to make hissing sounds or even the ocassional puff of smoke. In the dead center of the tent is a "+
        "wooden counter in the shape of a half circle which faces the tent opening. The counter is clean and bare, as if "+
        "it is wiped down quite frequently.%^RESET%^",
        
        ({"shelves", "numerous shelves", "components", "puffs of smoke", "smoke", "hissing sounds"}) : "%^BOLD%^%^YELLOW%^"+
        "These shelves line the walls of the tent. They are each stacked full of various spell components, some of them "+
        "drip down on the ones below them, making hissing sounds and puffs of smoke, which only last for a very brief "+
        "moment. They all seem quite disorganized at first but you quickly recognize that they are grouped with similar "+
        "items in such a way that retrieval is as painless as possible.%^RESET%^",
        
        ({"counter", "wooden counter", "large counter"}) : "%^RESET%^%^GREEN%^This large wooden counter is in "+
        "the shape of a half circle and faces the opening of the tent. It is clean and bare as if it is wiped down "+
        "quite frequently. Judging by some of these components it is very understandable.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"15"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("comp merchant")) find_object_or_load(ELMON+"comp_merchant")->move(TO);

}