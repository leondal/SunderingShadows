//~Circe~ 11/2/07 for Seneca
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "../seneca.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_name("Seneca Hospital");
    set_short("Seneca Hospital");
    set_long("%^BOLD%^Seneca Hospital%^RESET%^\n"+
       "This house of modern medicine features %^BOLD%^clean "+
       "surfaces %^RESET%^and whitewashed walls.  This seems "+
       "to be a waiting room of some sort, complete with a few "+
       "small %^ORANGE%^wooden chairs %^RESET%^that look rather "+
       "uncomfortable.  A raised platform on the northern wall "+
       "supports a %^BOLD%^%^BLACK%^black walnut desk %^RESET%^"+
       "filled with supplies, and a %^CYAN%^sign %^RESET%^upon "+
       "the desk lists simple services one may request.  A "+
       "%^ORANGE%^doorway %^RESET%^set in the eastern wall seems "+
       "to lead to rooms where more serious cases may be seen.\n");
    set_items(([
       ({"desk","black walnut desk","walnut desk","platform"}) : "%^BOLD%^%^BLACK%^"+
          "The desk on the raised platform has been stained a deep "+
          "brown, almost black.  It is polished to a high shine and "+
          "holds all manner of supplies needed for simple remedies.  "+
          "There is a %^RESET%^%^CYAN%^sign %^BOLD%^%^BLACK%^atop "+
          "the desk for you to look at.%^RESET%^",
       "supplies" : "The supplies are visible occasionally as the "+
          "healer opens the drawers.  They seem to consist mostly of "+
          "dried and powdered herbs, bandages, small knives, alcohol, "+
          "and other such implements.",
       "walls" : "The walls are simple planed wood, and they have been "+
          "whitewashed to add to the sanitary atmosphere.",
       ({"chair","chairs"}) : "The chairs are much lighter wood than "+
          "the desk.  They are armless, and the back is rather straight, "+
          "making them somewhat uncomfortable.",
       ({"door","doorway"}) : "The doorway in the eastern wall opens "+
          "and closes often, giving a view of the hallway beyond.  "+
          "Several rooms open off the hallway, likely smaller rooms for "+
          "patients who require extended care.",
       "sign" : "The sign is a framed %^CYAN%^list %^RESET%^that you should read."
    ]));
    set_smell("default","The delightful fragrance of the ocean is masked "+
       "by the antiseptic smell of alcohol and herbs.");
    set_listen("default","An occasional moan comes from the hallway.");
    set_exits(([
        "west" : ROOMS"skyline46"
    ]));
    set_name("Cyril");
}

void reset(){
    ::reset();
    if(!present("cyril")) 
        new(MON"cyril")->move(TO);
}
