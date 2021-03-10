#include <std.h>
#include <daemons.h>
#include "../tharis.h"
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A small stone building");
    set_short("%^BOLD%^%^WHITE%^A small stone building");
    set_long("%^BOLD%^%^WHITE%^A small stone building%^RESET%^\n"
"This building is no more or less remarkable than countless others in Tharis, with plain walls of %^ORANGE%^stone "
"%^RESET%^and a slate roof.  Two square windows offer only a short view as far as the walls of neighbouring buildings, "
"though the %^CYAN%^street %^RESET%^beyond can be seen through the open doorway.  Within the centre of the single room "
"that makes up the building itself, a sunken section supports a simple circle of dust that %^BOLD%^gli%^RESET%^t%^BOLD%^te"
"%^RESET%^r%^BOLD%^s %^RESET%^as it completes its circuit. At evenly-spaced intervals around the circle are three small "
"pillars, each seemingly embedded within the marble itself, and carved from what appear to be varied kinds of precious "
"rock and gem in shades of %^BLUE%^blue%^RESET%^, %^BOLD%^white %^RESET%^and %^BOLD%^%^BLACK%^black%^RESET%^.  Two steps "
"lead down from the raised edge around it, to the doorway where a sign has been added and printed in clear writing.\n");
    set_listen("default","Out on the street beyond, criers yell, a man swears, many folk seem to take issue to others..");
    set_smell("default","The thick smell of the city drifts in through the open doorway, rich perfumes mingled with the sweat of laborers.");
    set_items(([
      ({"circle","dust","glittering dust"}):"A perfect circle has been carved "
"into the %^BOLD%^%^WHITE%^marble rooftop%^RESET%^, and filled with some kind "
"of %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i%^BOLD%^ng %^RESET%^dust, "
"perhaps for some magical reason, or perhaps only to make it more visible "
"against the %^BOLD%^%^WHITE%^pure white %^RESET%^of the stone it is carved "
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
      "east" : ROOMS"north1",
    ]));
    add_location("enclave",0,75,"/d/shadow/room/city/portal/foyer");
    add_location("seneca",15,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("tonovi",0,55,"/d/dagger/tonovi/road2");    
    add_location("verbobone",15,75,"/d/deku/town/road13");    
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/evilnomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}

void init() {
    ::init();
    if(!present("tharisambiancexxx",TP)) new(OBJ"ambiance")->move(TP);
}
