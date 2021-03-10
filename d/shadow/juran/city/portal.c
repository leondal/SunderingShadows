#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A cellar");
    set_short("%^ORANGE%^A ruined cellar%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A ruined cellar%^RESET%^\n"
"%^CYAN%^This is the remnants of a cellar, beneath a %^ORANGE%^crumbling building%^CYAN%^.  Time and the ruination of "
"the buildings upstairs has done little to change this place.  While there are gaps in the %^BLUE%^stonework %^CYAN%^of "
"the walls, the surrounding earth seems firmly packed enough that nothing has crumbled inwards, leaving the whole "
"structure surprisingly sturdy.  Recent efforts appear to have been made to tidy the place up, as the floor has been "
"swept clean.  A large circle has been cut into the dirt floor, and at three evenly-spaced intervals around its "
"circumference stand tiny glittering stone pillars, one each of %^BLUE%^blue%^CYAN%^, %^RESET%^white %^CYAN%^and "
"%^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^. They are possibly the most valuable thing you've seen in this entire town, if "
"you could even call it that.  Beside the pile of rubble that serves as stairs to the building above, a small %^RESET%^"
"sign %^CYAN%^has been tacked up and printed with scrawled writing.\n%^RESET%^");
    set_listen("default","Aside from the wind blowing through the room upstairs it is as quiet as death here.");
    set_smell("default","The smell of decay and rotted wood fills the air.");
    set_items(([
      ({"circle","floor"}):"%^CYAN%^A circle has been cut into the %^ORANGE%^dirt floor%^CYAN%^.  At even intervals "
"around its circumference are three %^RESET%^stone pillars%^CYAN%^, each formed of a different mineral.%^RESET%^",
      ({"pillars","gemstones","rocks","stones"}):"%^CYAN%^Around the circumference of the circle are three pillars, "
"evenly spaced apart.  Each appears to be made of some precious mineral, in different hues - one of %^BOLD%^%^BLACK%^"
"obsidian%^RESET%^%^CYAN%^, one of %^RESET%^moons%^BOLD%^t%^RESET%^one%^CYAN%^, and one of %^BLUE%^bl%^CYAN%^u%^BLUE%^e "
"ame%^CYAN%^t%^BLUE%^hyst%^CYAN%^.%^RESET%^",
      "sign":"A small %^ORANGE%^sign %^RESET%^has been tacked up by the doorway, printed with clear writing that you "
"could read.",
    ]));
    set_exits(([
      "up":"/d/shadow/juran/city/psion",
    ]));
    add_location("tonovi",0,55,"/d/dagger/tonovi/road2");
    add_location("systyquah",15,75,"/d/laerad/parnelli/systyquah/sys001");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/duergarnomad")->move(TO);
      tell_room(TO,"%^CYAN%^A short robed figure makes its way down the pile of rubble, to stand motionless behind the "
"circle on the floor.%^RESET%^");
    }
}