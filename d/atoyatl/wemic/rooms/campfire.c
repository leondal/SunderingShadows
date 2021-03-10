//Coded by Lujke//
#include <std.h>
#include "../wemic.h"

inherit ROOM;

string night_desc();

void create(){
  ::create();
  set_name("A communal campfire");
  set_short("Clearing by a campfire");
  set_long( (:TO, "long_desc":) );
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","%^MAGENTA%^The fresh scents of the %^BOLD%^"
                     +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^"
                     +"%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
                     +"%^RESET%^%^MAGENTA%^ are overlain with the smell of"
                     +" %^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^h"
                     +" %^MAGENTA%^and %^RESET%^smoke");

  set_listen("default","Sounds of casual conversation mingle with the busy"
                      +" noises of the %^BOLD%^%^GREEN%^j%^RESET%^"
                      +"%^GREEN%^u%^BOLD%^%^GREEN%^ng"
                      +"%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^");

  set_exits( ([ "southwest" : ROOMS + "path04",
                   "north" : ROOMS + "path18" ]) );

  set_items( ([   ({ "log", "logs"}):"The logs have been dragged into a"
               +" rough circle around the circumferance of the campfire"
               +" area, dividing the bare earth from the strip of turf that"
               +" surrounds it.",

      "turf" : "%^BOLD%^%^GREEN%^The turf is fresh, springy and well"
              +" maintained. Large, %^BOLD%^%^YELLOW%^l%^RESET%^%^ORANGE%^e"
              +"%^BOLD%^%^YELLOW%^on%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^"
              +"ne f%^RESET%^%^ORANGE%^oo%^BOLD%^%^YELLOW%^tpr%^RESET%^"
              +"%^ORANGE%^i%^BOLD%^%^YELLOW%^nts %^GREEN%^can be made out"
              +" here and there.",

      "jungle" :"%^BOLD%^%^GREEN%^The j%^RESET%^%^GREEN%^u%^BOLD%^"
               +"%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e wraps"
               +" around the %^RESET%^clearing%^BOLD%^%^GREEN%^ on three"
               +" sides. Thick %^RESET%^%^GREEN%^foliage %^BOLD%^"
               +"%^GREEN%^and undergrowth curl around %^RESET%^"
               +"%^ORANGE%^gnarly limbed trees%^BOLD%^%^GREEN%^, making"
               +" the way unpassable", 

      ({ "fire", "campfire"}): (:TO, "fire_desc":),

      "path" : "A simple dirth path meanders back towards the village to"
              +" the east",

      "village" : "Off to the east, you can see a small gathering of"
                 +" hide-covered %^ORANGE%^yurts%^RESET%^, along with one"
                 +" or two other structures."
  ]) );

}
string fire_desc(){
  if(query_night()){
    return "%^BOLD%^%^RED%^A bright %^RESET%^%^RED%^c%^BOLD%^%^YELLOW%^a"
          +"%^RED%^%^RESET%^%^RED%^mpf%^BOLD%^%^RED%^i%^RESET%^%^RED%^re"
          +"%^BOLD%^%^RED%^ is blazing away in the centre of the circle."
          +" Great faggots of wood sputter and spit as the f%^BOLD%^"
          +"%^YELLOW%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^mes lick around"
          +" them.";
  } 

  return "A good sized bonfire has been prepared, with plenty of kindling."
        +" It sits on top of the ashes of previous nights' fires";
 }
void init(){
  ::init();

}


string long_desc(){
  if(query_night()){
    return night_desc();
  }
  return "%^ORANGE%^A series of %^RESET%^logs%^ORANGE%^ have been placed to"
        +" form the circumference of a rough circle of %^RESET%^bare"
        +" earth%^ORANGE%^. Beyond these, a strip of %^BOLD%^%^GREEN%^fresh"
        +", springy turf%^RESET%^%^ORANGE%^ gives way to the %^BOLD%^"
        +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ngle%^RESET%^"
        +"%^ORANGE%^ on three sides, while a %^RESET%^path%^ORANGE%^ leads"
        +" back to the village to the southeast. A large fire has been"
        +" built in the centre of the circle, though at this time it stands"
        +" dormant atop the %^RESET%^a%^BOLD%^%^BLACK%^s%^RESET%^hes"
        +"%^ORANGE%^ of previous burnings. Various %^BOLD%^%^YELLOW%^Wemic"
        +"%^RESET%^%^ORANGE%^ villagers and hunters frequent the area,"
        +" which clearly sees a lot of the village's social activity."
        +"%^RESET%^";
}

string night_desc(){
  return "%^BLUE%^A %^RED%^l%^ORANGE%^a%^RED%^rge c%^BOLD%^%^YELLOW%^a"
        +"%^RESET%^%^RED%^mpf%^BOLD%^%^RED%^i%^RESET%^%^RED%^re%^RESET%^"
        +"%^BLUE%^ is %^RED%^blazing%^BLUE%^ merrily in the centre of a"
        +" rough circle of bare earth. At the edges of the circle of light,"
        +" bare earth gives way to night dampened %^BOLD%^%^GREEN%^turf"
        +"%^RESET%^%^BLUE%^, and beyond that can be made out the %^BOLD%^"
        +"%^BLACK%^dark shapes%^RESET%^%^BLUE%^ of the forest, surrounding"
        +" the clearing on three sides. To the southeast, a %^ORANGE%^dirt"
        +" path %^BLUE%^meanders back toward the village. A variety of"
        +" %^ORANGE%^Wemic males%^BLUE%^, %^ORANGE%^females%^BLUE%^ and"
        +" %^ORANGE%^children%^BLUE%^ have gathered in the circle of the"
        +" campfire to talk, play, tell tales, eat and dance into the small"
        +" hours of the night.";
}
