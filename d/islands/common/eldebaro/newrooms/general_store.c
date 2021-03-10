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
    set_name("Eastern oasis odds and ends");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis odds and ends%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. There are numerous %^BOLD%^shelves%^RESET%^"+
    "%^ORANGE%^ which line the walls of it. Each of the %^BOLD%^shelves%^RESET%^%^ORANGE%^ is stacked with various items. "+
    "There are %^BOLD%^boxes%^RESET%^%^ORANGE%^ sitting by each shelf, some of them partially unpacked and each quite obviously in a state of "+
    "disarray. "+
    "They all seem quite disorganized as if whoever unpacked the boxes and organized the shelves did so quickly without "+
    "much thought. In what you think is "+
    "probably the dead center of it there is a "+
    "large %^RESET%^%^GREEN%^wooden counter%^RESET%^%^ORANGE%^ in the shape of a half circle. The %^RESET%^%^GREEN%^"+
    "counter%^RESET%^%^ORANGE%^ faces the tent opening. The counter is also fairly disorganized, with heaps of different "+
    "items stacked on the either end of it and with only a small cleared off space in the center of it. "
    "A large and %^BOLD%^comfortable bed%^RESET%^%^ORANGE%^"+
    " rests in the back corner. It is big enough for a few people to sleep comfortably in. You recognize that whoever "+
    "runs the shop also sleeps here. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat.%^RESET%^");     

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nBody odor hangs heavily in the air here, mixing with something stale.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^There are numerous shelves lining the walls of this "+
        "tent. Each is stacked with various items. Boxes, which seem only half unpacked, sit near each shelf. They are "+
        "all in quite a state of disarray. It is almost as if whoever unpacked them and filled the shelves did so "+
        "as quickly as possible without much thought or care. In the center of the tent there is a large wooden "+
        "counter, also quite disorganized. There are heaps of items on either end of the counter with only a small "+
        "cleared off space in the center of it.%^RESET%^",
        
        ({"shelves", "numerous shelves", "boxes", "unpacked boxes", "partially unpacked boxes"}) : "%^BOLD%^%^YELLOW%^"+
        "These shelves line the walls of the tent. They are each stacked with various items. Near each of them are "+
        "boxes which are partially unpacked at best. All of it seems incredibly disorganized, as if whoever was in "+
        "charge of setting up the shelves and unpacking the boxes do so hastily without a care as to who would see them.%^RESET%^",
        
        ({"counter", "wooden counter", "large counter", "heaps"}) : "%^RESET%^%^GREEN%^This large wooden counter is in "+
        "the shape of a half circle and faces the opening of the tent. It is also quite disorganized. There are heaps of items "+
        "stacked up on either end of it, with only a small cleared off area in the center.%^RESET%^",
        
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat.%^RESET%^",
        
        ({"bed", "comfortable bed"}) : "%^BOLD%^%^YELLOW%^This large and comfortable bed rests in the back corner of the tent. "+
        "It looks like several people could sleep in it without any issues at all. Apparently whoever runs this shop also sleeps here.%^RESET%^",
    ]));
    
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"4"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    ::reset();
     if(!present("armor merchant")) find_object_or_load(ELMON+"general_merchant")->move(TO);

}