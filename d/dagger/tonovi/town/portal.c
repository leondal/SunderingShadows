#include <std.h>
#include <daemons.h>
inherit "/std/psionportal";

void create(){
    ::create();
    set_property("indoors",1);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_name("A high-roofed hall");
    set_short("%^MAGENTA%^A high-roofed hall%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^A high-roofed hall%^RESET%^\n"
"%^ORANGE%^This opulent building seems to have been recently requisitioned from another purpose, as it is far too "
"big and secure for the purpose it now serves.  Vast windows shed light into the unfurnished hall, offering a view "
"through their %^BOLD%^%^BLACK%^metal-barred slats %^RESET%^%^ORANGE%^into the town beyond.  The walls are %^BLUE%^heavy "
"stone%^ORANGE%^, with only one strong wooden doorway offering a means in and out, though it is no longer held closed "
"against intruders.  The floor is polished stone, upon which has been painted a single %^RESET%^gli%^BOLD%^t%^RESET%^ter"
"%^BOLD%^i%^RESET%^ng %^ORANGE%^circle that takes up the best part of the room. At evenly-spaced intervals around "
"the circle are three small pillars, embedded somehow within the stone floor and each carved of what appears to be some "
"kind of precious rock or gemstone - %^BLUE%^blue%^ORANGE%^, %^RESET%^white %^ORANGE%^and %^BOLD%^%^BLACK%^black%^RESET%^"
"%^ORANGE%^. Beside the doorway, a small %^RESET%^sign %^ORANGE%^has been tacked up and printed with clear writing"
".\n%^RESET%^");
    set_listen("default","The bustle of a busy city is dulled by the thick stone walls.");
    set_smell("default","Even here, the air smells dank and oppressive.");
    set_items(([
      ({"circle","glittering circle"}):"%^ORANGE%^A circle has been painted upon the %^RESET%^stone floor%^ORANGE%^, that "
"%^RESET%^gli%^BOLD%^t%^RESET%^te%^BOLD%^r%^RESET%^s %^ORANGE%^of its own accord, perhaps simply to highlight its "
"presence. At even intervals around its circumference are three %^RESET%^stone pillars%^ORANGE%^, each formed of a "
"different mineral.%^RESET%^",
      ({"pillars","gemstones","rocks","stones"}):"%^ORANGE%^Around the circumference of the circle are three pillars"
", evenly spaced apart and somehow embedded in the stone floor. Each appears to be made of some precious mineral, in "
"different hues - one of %^BOLD%^%^BLACK%^obsidian%^RESET%^%^ORANGE%^, one of %^RESET%^moons%^BOLD%^t%^RESET%^one"
"%^ORANGE%^, and one of %^BLUE%^bl%^CYAN%^u%^BLUE%^e ame%^CYAN%^t%^BLUE%^hyst%^ORANGE%^.%^RESET%^",
      "sign":"A small %^ORANGE%^sign %^RESET%^has been tacked up by the doorway, printed with clear writing that you "
"could read.",
    ]));
    set_exits(([
      "west":"/d/dagger/tonovi/town/street9",
    ]));
    add_location("tharis",0,55,"/d/tharis/road/road8");
    add_location("juran",0,55,"/d/shadow/room/forest/owagon26");
    add_location("verbobone",15,75,"/d/deku/town/road13");
    add_location("seneca",25,95,"/d/attaya/newseneca/rooms/boardwalk3");
    add_location("enclave",10,75,"/d/dagger/tonovi/town/cguilds/psions/foyer");
}

void reset(){
    ::reset();
    if(!present("nomad")) {
      new("/d/shadow/mon/evilnomad")->move(TO);
      tell_room(TO,"%^CYAN%^A robed human enters quietly into the room, to stand behind the etched circle.%^RESET%^");
    }
}
