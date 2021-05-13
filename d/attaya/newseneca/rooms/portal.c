#include <std.h>
#include <daemons.h>
#include "../seneca.h"
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("Inside a Marble Rotunda");
    set_short("%^BOLD%^%^WHITE%^Inside a Marble Rotunda%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Inside a Marble Rotunda, Seneca%^RESET%^\n"+
       "This rotunda has been constructed from pure %^BOLD%^white marble"+
       "%^RESET%^.  The walls have been formed from perfectly cut stones, "+
       "all intersecting flawlessly to leave no holes or gaps between them.  "+
       "The room is also a perfect circle, with a raised dias dominating the "+
       "center of the room.  On that dias is a%^BOLD%^%^BLACK%^ complicated "+
       "carving %^RESET%^of a circle, several feet in diameter.  At "+
       "evenly-spaced intervals around the circle are three small pillars, "+
       "each seemingly embedded within the marble itself and carved from "+
       "what appear to be varied kinds of precious rocks and "+
       "gems in shades of %^BLUE%^blue%^RESET%^, %^BOLD%^white %^RESET%^and "+
       "%^BOLD%^%^BLACK%^black%^RESET%^.  The room is bright and airy, "+
       "though there are no obvious sources of light.  A single broad "+
       "doorway is set into western wall, leading through a small hallway "+
       "back to the %^ORANGE%^street%^RESET%^.  Beside the doorway, a small "+
       "%^ORANGE%^sign %^RESET%^has been tacked up and printed in clear writing.\n");
    set_listen("default","The soft murmur of chanting voices drifts around you.");
    set_smell("default","The clean scent of the ocean rises on the breeze.");
    set_items(([
      ({"circle","dust","carving"}) : "A perfect circle has been carved "+
         "into the %^BOLD%^%^WHITE%^marble floor%^RESET%^ and filled "+
         "with some kind of %^BOLD%^gli%^RESET%^t%^BOLD%^ter%^RESET%^"+
         "i%^BOLD%^ng %^RESET%^dust, perhaps for some magical reason, "+
         "or perhaps only to make it more visible against the %^BOLD%^"+
         "%^WHITE%^pure white %^RESET%^of the stone it is carved into.  "+
         "At even intervals around its circumference are three stone pillars, "+
         "each formed of a different mineral.",
      ({"pillars","gemstones","rocks","stones"}) : "Around the "+
         "circumference of the circle are three pillars, evenly spaced "+
         "apart. Each appears to be made of some precious mineral, in "+
         "different hues - one of %^BOLD%^%^BLACK%^obsidian%^RESET%^, "+
         "one of %^BOLD%^%^WHITE%^moonstone%^RESET%^, and one of %^BLUE%^"+
         "bl%^CYAN%^u%^BLUE%^e ame%^CYAN%^t%^BLUE%^hyst.%^RESET%^",
      "sign":"A small %^ORANGE%^sign %^RESET%^has been tacked up by the "
"doorway, printed with clear writing that you could read.",
    ]));
    set_exits(([
      "west" : ROOMS"wstreet35"
    ]));
    add_location("shadow",0,95,"/d/darkwood/room/road1");
    add_location("tonovi",0,95,"/d/dagger/tonovi/road2");
    add_location("eldebaro",20,95,"/d/islands/common/eldebaro/newrooms/east_oasis1");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/nomad")->move(TO);
      tell_room(TO,"A robed human enters quietly into the room, to stand behind the etched circle.");
    }
}
