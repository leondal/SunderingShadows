#include <std.h>
#include <move.h>
#include "../../tecqumin.h"

inherit VAULT;

void create() {
  ::create();
  set_indoors(1);
  set_property("light", 2);
  set_terrain(STONE_BUILDING);
  set_travel(DECAYED_FLOOR);
  set_name("An abandoned entry hall");
  set_short( "%^ORANGE%^An %^RESET%^abandoned %^ORANGE%^entry hall" );
  set_long( "%^ORANGE%^A short, wide corridor leads from the"
    +"%^BOLD%^%^WHITE%^ grand entrance %^RESET%^%^ORANGE%^to the"
    +" main hall of the building. The walls hold long empty sconces,"
    +" where torches once burned. %^BOLD%^%^BLACK%^Dust%^RESET%^"
    +" %^ORANGE%^and %^RESET%^l%^ORANGE%^i%^RESET%^ch%^GREEN%^e"
    +"%^RESET%^n%^ORANGE%^ cover most surfaces, and a few %^GREEN%^"
    +"v%^ORANGE%^i%^GREEN%^nes%^ORANGE%^ and %^BOLD%^%^GREEN%^cr"
    +"%^RESET%^%^GREEN%^ee%^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^e"
    +"%^BOLD%^rs %^RESET%^%^ORANGE%^have found their way in"
    +" through aged cracks in the %^RESET%^stonework%^ORANGE%^. A"
    +" %^BOLD%^%^BLACK%^carved door %^RESET%^%^ORANGE%^leads north"
    +" into the main hall." );
  set_items(([ ({"sconce", "sconces"}): "The empty sconces would once"
    +" have held brightly burning torches" ]));
  set_smell("default","The air is heavy with %^CYAN%^humidity%^ORANGE%^"
                    +" and the heady scent of %^GREEN%^j%^BOLD%^"
                    +"%^GREEN%^u%^RESET%^%^GREEN%^ngle %^ORANGE%^plant"
                    +" life.\n");
  set_listen("default","There is the constant hum of insect activity, the"
                     +" bustle and shrill calls of exotic birds. Small"
                     +" animals can be heard scurrying in the undergrowth"
                     +" and larger creatures are occasionally heard"
                     +" further in the distance.\n");
  set_exits((["south"   : CITY_ROOM + "palace_entrance",
              "north" : CITY_ROOM + "throne_room"   ]));
  set_door("double door", CITY_ROOM + "palace_entrance", "south", 0);
  set_string("double door","open","The heavy stone doors swing open"
    " silently, with the lightest touch");
  set_string("double door","close","The heavy stone doors swing closed"
    +" silently, with just the slightest whoosh as they form an airtight"
    +" seal");
  set_door_description("double door", "These double doors are made of"
    +" stone. They are enormously heavy, but set on a cunning mechanism"
    +" that allows them to swing silently open with the lightest touch.");
  set_door("carved door", CITY_ROOM + "throne_room", "north", 0);
  set_door_description("carved door", "This grand door is made of"
    +" %^BOLD%^%^BLACK%^time-blackened h%^RESET%^%^ORANGE%^a%^BOLD%^"
    +"%^BLACK%^rdw%^RESET%^%^ORANGE%^oo%^BOLD%^%^BLACK%^d%^RESET%^,"
    +" and carved with symbols of the %^CYAN%^Tecqumin gods");
  
}

void init(){
  ::init();
}

