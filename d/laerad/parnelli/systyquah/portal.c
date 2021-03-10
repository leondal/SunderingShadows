#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_terrain(VILLAGE);
    set_travel(DIRT_ROAD);
    set_name("A short wooden hut");
    set_short("%^ORANGE%^A short wooden hut%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^A short wooden hut%^RESET%^\n"
"%^GREEN%^This short %^ORANGE%^wooden hut %^GREEN%^is almost identical to those in the rest of the village, save that it "
"does not match the vast height of the others.  Instead, it seems of a fairly normal size for a human.  %^YELLOW%^Dried "
"grass thatching %^RESET%^%^GREEN%^spans the roof overhead, blocking out the sun and the weather.  Another difference "
"from the other huts is that it lacks the %^RED%^stench %^GREEN%^so commonly found in the living quarters of the village "
"trolls.  Instead, it consists merely of a plain dirt floor, within which a large circle has been cut.  At three evenly-"
"spaced intervals around its circumference stand tiny glittering stone pillars, one each of %^BLUE%^blue%^GREEN%^, "
"%^RESET%^white %^GREEN%^and %^BOLD%^%^BLACK%^black%^RESET%^%^GREEN%^.  Near the doorway, a small %^RESET%^sign %^GREEN%^"
"has been tacked up and printed with scrawled writing.\n%^RESET%^");
    set_listen("default","You hear the occasional scream of a troll war party.");
    set_smell("default","The breeze carries a distant, nauseating stench.");
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
      "north":"/d/laerad/parnelli/systyquah/sys009.c",
    ]));
    add_location("juran",10,75,"/d/shadow/room/forest/owagon26");
}

void reset(){
    ::reset();
    if(!present("portalpsion")) {
      new("/d/shadow/mon/duergarnomad")->move(TO);
      tell_room(TO,"%^CYAN%^A short robed figure makes its way down the pile of rubble, to stand motionless behind the "
"circle on the floor.%^RESET%^");
    }
}