#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A rustic wooden building");
    set_short("%^RED%^A rustic wooden building%^RESET%^");
    set_long("%^RED%^A rustic wooden building%^RESET%^\n"
"%^ORANGE%^This building is made entirely of large logs, all carefully cut "
"and ordered to give the effect of an old, rustic establishment.  Heavy "
"brackets of %^BOLD%^%^BLACK%^wro%^RESET%^%^WHITE%^u%^BOLD%^%^BLACK%^ght "
"ir%^RESET%^%^WHITE%^o%^BOLD%^%^BLACK%^n %^RESET%^%^ORANGE%^are secured at "
"each corner of the room. Each holds a softly-glowing %^BOLD%^%^MAGENTA%^"
"crys%^RESET%^%^MAGENTA%^t%^BOLD%^al%^RESET%^%^ORANGE%^ that sheds just "
"enough light around the room to see, yet not enough to be considered harsh, "
"or detract from the %^RED%^cosy %^ORANGE%^feeling of the building itself.  "
"At the centre of the room is a circle carved into the wooden floor, and "
"filled in with %^RESET%^gli%^BOLD%^t%^RESET%^ter%^BOLD%^i%^RESET%^ng "
"%^ORANGE%^dust to mark its path. At evenly-spaced intervals around the "
"circle are three small pillars, each embedded within the floorboards, and "
"carved from what appear to be varied kinds of precious rock and gem in "
"shades of %^BLUE%^blue%^ORANGE%^, %^WHITE%^white %^ORANGE%^and "
"%^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^.  A small door leads eastward "
"into what appears to be a crystal shop, while two larger doors lead out onto "
"the street.  A small %^WHITE%^sign %^ORANGE%^has been tacked up between "
"them, printed in clear writing.%^RESET%^");
        set_smell("default","A soft oaky scent permeates the room.");
        set_listen("default","The quiet murmur of a small town filters in through the doorway.");
    set_items(([
      ({"circle","dust","glittering dust"}):"A perfect circle has been carved "
"into the %^ORANGE%^wooden floor%^RESET%^, and filled with some kind "
"of %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i%^BOLD%^ng %^RESET%^dust, "
"perhaps for some magical reason, or perhaps only to make it more visible "
"against the %^RED%^dull grain %^RESET%^of the wood it is carved "
"into. At even intervals around its circumference are three stone pillars, "
"each formed of a different mineral.",
      ({"pillars","gemstones","rocks","stones"}):"Around the "
"circumference of the circle are three pillars, evenly spaced apart. Each "
"appears to be made of some precious mineral, in different hues - one "
"of %^BOLD%^%^BLACK%^obsidian%^RESET%^, one of %^BOLD%^%^WHITE%^moonstone"
"%^RESET%^, and one of %^BLUE%^bl%^CYAN%^u%^BLUE%^e "
"ame%^CYAN%^t%^BLUE%^hyst.%^RESET%^",
      "sign":"A small %^ORANGE%^sign %^RESET%^has been tacked up by the "
"doorway, printed with clear writing that you could read.",
    ]));
    set_exits(([
      "west":"/d/deku/town/sroad1",
      "south":"/d/deku/town/sroad2",
      "east":"/d/deku/town/crystals",
    ]));
    add_location("shadow",10,75,"/d/darkwood/room/road1");
    add_location("tonovi",10,75,"/d/dagger/tonovi/road2");
    if(!present("portalpsion")) 
    {
        new("/d/shadow/mon/nomad")->move(TO);
    }
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}