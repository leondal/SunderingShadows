#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("The roof of a marble building");
    set_short("%^BOLD%^%^WHITE%^The roof of a marble building");
    set_long("%^BOLD%^%^WHITE%^The roof of a marble building%^RESET%^\n"
"You stand upon the rooftop of a large %^WHITE%^marble building%^RESET%^, "
"pristine-white and austere in appearance, yet elegant in that very "
"simplicity.  No walls or pillars encircle the flat rooftop, offering no "
"restraint to prevent someone falling to the ground below. At the very centre "
"of the flat rooftop is carved a circle into the stone itself, and filled in "
"with %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^i%^BOLD%^ng %^RESET%^dust to "
"mark its path. At evenly-spaced intervals around the circle are three small "
"pillars, each seemingly embedded within the marble itself, and carved from "
"what appear to be varied kinds of precious rock and gem in shades of "
"%^BLUE%^blue%^RESET%^, %^BOLD%^white %^RESET%^and %^BOLD%^%^BLACK%^black"
"%^RESET%^.  A set of broad steps lead back down into the building itself, "
"beside which a small %^ORANGE%^sign %^RESET%^has been tacked up and printed "
"in clear writing.\n");
    set_listen("default","The hustle and bustle of the city goes on in the streets below.");
    set_smell("default","The scent of heady incense filters up from the marble building.");
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
      "down":"/d/azha/town/azha_psi_comps",
    ]));
    add_location("shadow",0,55,"/d/darkwood/room/road1");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}