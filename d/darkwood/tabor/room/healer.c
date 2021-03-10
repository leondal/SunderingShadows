//updated by Circe 6/1/04 with color, etc
#include <std.h>
#include <objects.h>
#include <money.h>
#include <move.h>
#include "../include/tabor.h"

inherit HEALER;

void create() {
    ::create();
    set_light(3);
    set_property("training",1);
    set_indoors(1);
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_short("Tabor Infirmary");
    set_long(
@TABOR
%^BOLD%^Tabor Infirmary%^RESET%^
You have entered the hospital for the city of Tabor.  The room is 
relatively clean, and the %^ORANGE%^pallets %^RESET%^that patients sleep on seem to have 
%^YELLOW%^fresh hay %^RESET%^without many %^GREEN%^insects%^RESET%^.  Since most people take care of sickness 
and injury at home, this infirmary is usually only used to treat guards 
and others wounded in the course of their activities.  There are 
numerous %^BOLD%^sharp implements %^RESET%^about that show what is sometimes deemed 
necessary to heal patients.  Luckily, for adventurers with a bit of 
%^YELLOW%^coin%^RESET%^, more effective (and less dangerous) treatments and potions are 
available.
TABOR
    );
    set_items(([
       ({"beds","pallets","hay","pallet"}) : "The pallets seem to "+
          "be mattresses made of thin muslin stuffed with hay.  They "+
          "look mostly clean, and you notice only one or two bugs "+
          "crawling about.",
       ({"implements","tools"}) : "Shiny, sharp implements rest "+
          "on a tray on the counter.  Most of them look more like "+
          "torture devices than healing implements, and you find "+
          "yourself hoping you never have to rely on such measures.",
    ]));
    set_smell("default", "There is a strong odor of herbs and hay in here.");
    set_listen("default", "You hear metal impliments being sharpened nearby.");
    set_exits( ([
        "east" : ROOMDIR+"math6"
    ] ));
    set_name("Barnaby");
}

void reset(){
    ::reset();
    if(!present("barnaby")) 
        new("/d/darkwood/tabor/mon/barnaby.c")->move(TO);
}
