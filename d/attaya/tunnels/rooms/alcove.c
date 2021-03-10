#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit ROOM;

void create() {
 ::create();
 set_property("indoors",0);  // is 0 if outdoors
 set_property("light",1);    // 2 is pretty much average lighting
 set_terrain(NAT_CAVE);
 set_travel(SLICK_FLOOR);
 set_name("An alcove");
 set_short("A small alcove behind a waterfall");
 set_long("The waterfall cascades down in front of this narrow"
         +" alcove, but you can just about make out the main features of"
         +" the large cavern beyond. Towards the back of the alcove a set"
         +" of steep stairs, cut from the rock itself, spirals upwards"
         +" out of sight.");

  set_smell("default","The air smells of damp stone");
  set_listen("default","The roaring cascade of the waterfall drowns"
                      +" out all other sounds");

  set_items(([
         "waterfall":"%^BOLD%^%^BLUE%^The %^CYAN%^water%^BLUE%^"
                    +" g%^WHITE%^u%^BLUE%^shes through the air above you"
                    +"  and t%^WHITE%^u%^RESET%^%^CYAN%^m%^BOLD%^"
                    +"%^BLUE%^bl%^CYAN%^e%^BLUE%^s down out of sight,"
                    +" %^CYAN%^spl%^WHITE%^a%^RESET%^%^CYAN%^%^s%^BOLD%^"
                    +"%^WHITE%^h%^CYAN%^ing%^BLUE%^ and %^CYAN%^spraying"
                    +"%^BLUE%^ as it goes. A fine %^RESET%^%^CYAN%^m"
                    +"%^RESET%^i%^CYAN%^st%^BOLD%^%^BLUE%^ forms"
                    +" constantly around it, and the %^RESET%^s%^BOLD%^"
                    +"%^BLACK%^la%^RESET%^te %^BOLD%^%^BLUE%^surfaces"
                    +" nearby are %^RESET%^slick%^BOLD%^%^BLUE%^ and"
                    +" treacherous.",

            "stairs": "A risky looking set of steep stone stairs"
                     +" spirals out of sight",

        ]));

  set_exits(([
           "out" : TUNNELS +"ugstream", 
           "up" : TUNNELS +"deadend2", 
   ]));

}
