#include <std.h>
#include <daemons.h>
#include "../defs.h"
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A restored wooden building");
    set_short("%^MAGENTA%^A restored wooden building%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^A restored wooden building%^RESET%^\n"
"%^BOLD%^%^BLUE%^This small building seems to have been recently "
"restored from some kind of %^RESET%^%^ORANGE%^wooden structure%^BOLD%^"
"%^BLUE%^, long aged. Despite this, it has been cleaned up quite well, with "
"the %^CYAN%^windows %^BLUE%^freshly replaced and the wooden floors well "
"oiled. In the centre of the room is a circle carved into the floor, filled "
"in with %^RESET%^gli%^BOLD%^t%^RESET%^ter%^BOLD%^i%^RESET%^ng "
"%^BOLD%^%^BLUE%^dust to mark its path. At evenly-spaced intervals around the "
"circle are three small pillars, secured to the floorboards and each carved "
"of what appears to be some kind of precious rock or gemstone - "
"%^RESET%^%^BLUE%^blue%^BOLD%^, %^RESET%^white %^BOLD%^%^BLUE%^and "
"%^BLACK%^black%^BLUE%^. Beside the doorway, a small %^RESET%^sign "
"%^BOLD%^%^BLUE%^has been tacked up and printed with clear "
"writing.\n%^RESET%^");
    set_listen("default","The bustle of a busy city filters in through the windows.");
    set_smell("default","The building is filled with the scent of freshly oiled wood.");
    set_items(([
      "windows":(:TO,"window_desc":),
      ({"circle","dust","glittering dust"}):"%^BOLD%^%^BLUE%^A circle has "
"been carved into the %^RESET%^%^ORANGE%^wooden floor%^BOLD%^%^BLUE%^, and "
"filled with some kind of %^RESET%^gli%^BOLD%^t%^RESET%^ter%^BOLD%^i%^RESET%^"
"ng %^BOLD%^%^BLUE%^dust, perhaps to highlight its presence. At even "
"intervals around its circumference are three %^RESET%^stone pillars"
"%^BOLD%^%^BLUE%^, each formed of a different mineral.%^RESET%^",
      ({"pillars","gemstones","rocks","stones"}):"%^BOLD%^%^BLUE%^Around the "
"circumference of the circle are three pillars, evenly spaced apart. Each "
"appears to be made of some precious mineral, in different hues - one "
"of %^BLACK%^obsidian%^BLUE%^, one of %^RESET%^moons%^BOLD%^t%^RESET%^one"
"%^BOLD%^%^BLUE%^, and one of %^RESET%^%^BLUE%^bl%^CYAN%^u%^BLUE%^e "
"ame%^CYAN%^t%^BLUE%^hyst%^BOLD%^.%^RESET%^",
      "sign":"A small %^ORANGE%^sign %^RESET%^has been tacked up by the "
"doorway, printed with clear writing that you could read.",
    ]));
    set_exits(([
      "northwest" : ROOMS"psion1",
      "southwest" : ROOMS"crossways3",
    ]));
    add_location("azha",0,55,"/d/azha/town/wroad");
    add_location("enclave",0,75,"/d/shadow/room/city/portal/foyer");
    add_location("seneca",0,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("tonovi",0,55,"/d/dagger/tonovi/road2");    
    add_location("torm",0,55,"/d/dagger/Torm/road/path12");
    add_location("verbobone",0,75,"/d/deku/town/road13");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"%^CYAN%^A robed human enters quietly into the room, to stand behind the etched circle.%^RESET%^");
    }
}

string window_desc() {
   if ((string)EVENTS_D->query_time_of_day() == "night") {
     return("%^BOLD%^%^BLUE%^These appear to be brand new, perhaps installed "
"only recently. The panes of glass are %^CYAN%^clear %^BLUE%^and%^RESET%^ "
"polished%^BOLD%^%^BLUE%^, allowing pale %^WHITE%^moonlight %^BLUE%^to filter "
"into the room.%^RESET%^");
   }
     return("%^BOLD%^%^BLUE%^These appear to be brand new, perhaps installed "
"only recently. The panes of glass are %^CYAN%^clear %^BLUE%^and%^RESET%^ "
"polished%^BOLD%^%^BLUE%^, allowing bright %^YELLOW%^sunlight %^BLUE%^to "
"filter into the room.%^RESET%^");
}
