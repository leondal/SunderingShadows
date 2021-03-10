#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("An enclosed back-room");
    set_short("%^BOLD%^%^WHITE%^An enclosed back-room");
    set_long("%^BOLD%^%^WHITE%^An enclosed back-room%^RESET%^\n"
"%^ORANGE%^This small back-room features walls of planks hewn smooth and lightly "
"%^YELLOW%^varnished%^RESET%^%^ORANGE%^.  No furniture impedes progress here, "
"leaving the room pleasantly uncluttered.  The eastern wall is fitted with "
"%^BOLD%^%^CYAN%^windows %^RESET%^%^ORANGE%^set with plain glass of a somewhat "
"low quality, still showing a slight distortion and a few bubbles.  The only "
"object of any interest in the room is the circle carved into the floor, filled "
"in with %^RESET%^gli%^BOLD%^t%^RESET%^ter%^BOLD%^i%^RESET%^ng %^ORANGE%^dust "
"to mark its path. At evenly-spaced intervals around the circle are three small "
"pillars, secured to the floorboards and each carved of what appears to be some "
"kind of precious rock or gemstone - %^BLUE%^blue%^ORANGE%^, %^RESET%^white "
"%^ORANGE%^and %^BOLD%^%^BLACK%^black%^RESET%^%^ORANGE%^. Beside the doorway, a "
"small %^RESET%^sign %^ORANGE%^has been tacked up and printed with clear writing"
".%^RESET%^\n");
    set_listen("default","The ring of hammer and chisel mingle with fragments of conversation.");
    set_smell("default","The light fragrance of a woodsy incense reaches you.");
    set_items(([
      ({"circle","dust","glittering dust"}):"A perfect circle has been carved "
"into the %^ORANGE%^wooden floor%^RESET%^, and filled with some kind "
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
      "down":"/d/laerad/parnelli/asgard/asgardpsicomps",
    ]));
    add_location("torm",10,75,"/d/dagger/Torm/road/path12");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}