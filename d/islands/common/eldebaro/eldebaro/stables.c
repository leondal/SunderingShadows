#include <std.h>
#include <daemons.h>
#include "../area_stuff.h"
inherit STABLE;
#define HOR "/d/common/mounts/"+

void create()
{
    ::create();
	set_property("light",2);
	set_property("indoors",1);
    set_climate("desert");
    set_name("Eastern oasis camel house");
    set_short("%^RESET%^%^ORANGE%^East%^BOLD%^e%^RESET%^%^ORANGE%^rn o%^BOLD%^a%^RESET%^%^ORANGE%^sis camel house%^RESET%^");    
    
    set_long("%^RESET%^%^ORANGE%^This tent appears even larger inside. The floor of the tent has been covered with a "+
    "thick layer of %^BOLD%^straw%^RESET%^%^ORANGE%^, which is pelted with manure in places. It appears to have been cleaned regularly or the "+
    "manure and the smell would be much worse. There are several %^BOLD%^camels%^RESET%^%^ORANGE%^ lingering about "+
    "through the tent. Some of them are standing and others are laying down on their legs. Several %^BOLD%^%^CYAN%^"+
    "water troughs%^RESET%^%^ORANGE%^ have been set up along the walls of the tent to make sure that they have "+
    "plenty to drink. Each, somehow, looks completely full. A %^BOLD%^sign%^RESET%^%^ORANGE%^ has been attached "+
    "to one side of the tent opening. It is amazingly well lit as there are %^BOLD%^lanterns%^RESET%^%^ORANGE%^"+
    " set up at various spots around the tent. None of them seem to be %^BOLD%^burning%^RESET%^%^ORANGE%^"+
    " though, they all appear to be %^BOLD%^glowing%^RESET%^%^ORANGE%^ and are putting off no heat. The %^BOLD%^"+
    "camels%^RESET%^%^ORANGE%^ do "+
    "not seem to be bothered by the lanterns at all either.%^RESET%^");

    set_listen("default", "%^CYAN%^\nYou can hear the ocean crashing against the sandscape "+
    "somewhere outside the tent.%^RESET%^");
        
    set_smell("default", "%^YELLOW%^\nA lingering odor of manure fills the air.%^RESET%^");

    set_items(([
        ({"tent", "large tent"}) : "%^RESET%^%^ORANGE%^This large tent is serving as a house for camels. There is "+
        "straw covering the floor and it has been pelted with manure in places. Several water troughs have been "+
        "set up near the walls of the tent. Each of them appears completely full. A sign has been attached to "+
        "one sign of the tent opening.%^RESET%^",
                   
        ({"lanterns", "glowing lanterns"}) : "%^BOLD%^%^YELLOW%^These lanterns are set up at several spots throughout the tent in an "+
        "obvious effort to make it very well lit regardless of time of day. They are not burning but instead are glowing brilliantly. "+
        "They are obviously magical as they put off no heat. The camels seem to pay them no mind.%^RESET%^",
        
        ({"troughs", "water troughs"}) : "%^BOLD%^%^CYAN%^These large water troughs line the walls of the tent. There purpose "+
        "is obviously to provide water to the camels, however, they all appear completely full.%^RESET%^",
        
        ({"straw", "manure", "floor"}) : "%^RESET%^%^ORANGE%^The floor of the tent is covered with thick layers of straw, which is "+
        "pelted regularly with manure. You think that it must be replaced regularly less the smell and the manure would be "+
        "much worse.%^RESET%^",
        
        ({"camels"}) : "%^BOLD%^%^YELLOW%^These animals are mostly lounging around, for lack of a better word. Some of them are walking "+
        "around eating straw or drinking from the water troughs. A few of them are urinating and defecating as if you do not exist. Others "+
        "are laying down in the straw casually.%^RESET%^",
    ]));
    
    set_animal(
        ({"camel"}),
        ({HOR"camel"})
    );
    

    set_animal_price(
        ({"camel"}),
        ({5000})
    );
    
    set_stalls(12);
    ::fill_stalls();
    set_terrain(VILLAGE);
    set_travel(PAVED_ROAD);
    set_exits((["opening": ELROOMSE+"6"]));
    return;
}

string query_weather()
{
    return "\n%^BOLD%^%^BLACK%^Heavy st%^BOLD%^%^WHITE%^o%^BOLD%^%^BLACK%^rm clouds blanket the entire island.";
}

void reset()
{
    object ob;
    ::reset();
    if(present("stable hand")) 
    {
        ob = present("stable hand");
        NPCCRE->build_me(ob);
        ob->add_id(({"stable hand"}));
    }

}

