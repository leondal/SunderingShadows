#include <std.h>
#include <daemons.h>
#include "../tormdefs.h"
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A long stone building");
    set_short("%^BOLD%^%^CYAN%^A long stone building%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^A long stone building%^RESET%^\n"
"%^CYAN%^This long, stone building is rather plain in appearance, with "
"%^WHITE%^pillars %^CYAN%^at intervals along the street front allowing "
"permanent access inside and out.  Here in the western end of the building "
"there is no furniture, only a circle carved into the stone of the floor "
"itself, and filled with %^BOLD%^%^WHITE%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i"
"%^BOLD%^ng %^RESET%^%^CYAN%^dust to mark its path against the darker floor.  "
"At evenly-spaced intervals around the circle are three small pillars, each "
"seemingly embedded within the floor, and carved from what appear to be "
"varied kinds of precious rock and gem in shades of %^BLUE%^blue%^CYAN%^, "
"%^WHITE%^white %^CYAN%^and %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^.  Stairs "
"lead up from the street itself to the building, which to the east is "
"bordered by a desktop of what appears to be a shop.  Tacked onto one of the "
"nearer pillars is a small %^ORANGE%^sign %^CYAN%^printed in clear "
"writing.%^RESET%^\n");
    set_listen("default","The hustle and bustle of the city goes on in the streets below.");
    set_smell("default","Wafting scents of food and animals drift along the wind from the nearby marketplace.");
    set_items(([
      ({"circle","dust","glittering dust"}):"A perfect circle has been carved "
"into the stone floor, and filled with some kind "
"of %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i%^BOLD%^ng %^RESET%^dust, "
"perhaps for some magical reason, or perhaps only to make it more visible "
"against the %^BOLD%^%^BLACK%^dark stone %^RESET%^of the floor it is carved "
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
      "north":TCITY+"c6",
      "east":TCITY+"psion",
    ]));
    add_location("shadow",0,55,"/d/darkwood/room/road1");
    add_location("asgard",15,75,"/d/laerad/parnelli/asgard/as01");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}