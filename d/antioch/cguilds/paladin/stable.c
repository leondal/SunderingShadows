#include <std.h>

inherit STABLE;

void create(){
    ::create();
    set_id("stables");
//  set_property("no teleport", 1);
    set_name("stable of the paladins");
    set_short("%^BOLD%^%^BLUE%^Stable of the Paladins%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^Stable of the Paladins %^RESET%^\n"+
    "This massive chamber serves as the stable for the legions of "+
    "paladins that faithfully serve the city of Antioch and the "+
    "surrounding region.  The floor of this chamber may very well "+
    "be made from stone, but it is impossible to determine, as it is "+
    "littered with a thick layer of fresh straw.  The straw is "+
    "apparently used to keep the horse manure from being spread "+
    "throughout the keep and judging by the fact that it is fresh, "+
    "you can safely assume that someone keeps this place "+
    "meticulously clean.  The north and west walls are lined with "+
    "recently constructed oak stables.  The wood that constructs "+
    "them has been dyed a darker brown color and seems to meld "+
    "well with the horses held within.");

    set_exits(([
        "east" : "/d/antioch/cguilds/paladin/hall3",
    ]));
    set_items(([
    ]));
    set_smell("default","You smell horses here.");
    set_listen("default","An occasional shifting of horses' hooves can be heard here.");
    
    set_animal(({"war horse", "barded war horse"}),({"/d/shadow/room/city/cguild/paladin/war_horse","/d/shadow/room/city/cguild/paladin/barded_war_horse"}));
    set_animal_price(({"war horse","barded war horse"}),({500, 2500}));
    set_stalls(15);
    ::fill_stalls();
}

void reset(){
  object ob;
  ::reset();
    if(present("stable hand")) {
        ob = present("stable hand");
        ob->set_long("%^RESET%^This young man looks to be in his "+
        "early twenties.  His body is toned, well kept, and "+
        "seems perfumed as it emits a light sweet odor, even "+
        "during the middle of a hot day.  His green eyes reflect a "+
        "youthful curiosity that is mixed with an obvious "+
        "determination.  The pile of hair atop his head falls "+
        "down to only near his ears, he keeps it cropped off "+
        "and always straight.  Most of all, he has a handsome "+
        "and smooth face, that somehow reveals his innocent lack "+
        "of experience and his desire to do his job well.");
        ob->set_short("A handsome young lad");
        ob->set_id(({"young lad","stable hand","hand",
        "handsome lad","lad"}));
    }
}