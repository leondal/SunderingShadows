#include <std.h>
#include <daemons.h>
#include "lair.h"
inherit ROOM;

void create(){
   ::create();
   set_property("light",-2);
   set_property("no teleport",1);
   set_property("indoors",1);
   set_name("A narrow, winding tunnel");
   set_short("%^BLUE%^A narrow, winding tunnel%^RESET%^");
   set_terrain(CEMETERY);
   set_travel(FOOT_PATH);
   set_smell("default","%^ORANGE%^The dank smell of %^BOLD%^%^BLACK%^sto%^RESET%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^"
"and the underground fills the air.%^RESET%^");
   set_listen("default","%^GREEN%^Somewhere nearby you can hear %^CYAN%^dripping%^GREEN%^ water.%^RESET%^");
   set_items( ([ 
     ({"walls","tunnel","floor","roof","stalagmites"}):"%^BLUE%^This tunnel is seemingly naturally-formed, so %^BOLD%^"
"%^CYAN%^na%^RESET%^%^CYAN%^rr%^BOLD%^ow %^RESET%^%^BLUE%^that only a small group of human-sized creatures could move "
"through it at a time.  The occasional glitter of a %^YELLOW%^spa%^WHITE%^r%^YELLOW%^kling coin %^RESET%^%^BLUE%^can be "
"spotted in the darkness, strewn across the rocky floor.%^RESET%^",
     "coins":"%^BLUE%^The occasional sparkle of a %^YELLOW%^c%^WHITE%^o%^YELLOW%^in %^RESET%^%^BLUE%^catches your eye, "
"lying upon the stone floor.  Some are damaged, and others appear to be almost eaten entirely through by... something"
".%^RESET%^",
   ]) );
}

void reset() {
   ::reset();
   switch(random(9)){
     case 0..1: tell_room(TO,"%^ORANGE%^From somewhere nearby you hear the quiet drip, drip of %^CYAN%^water%^ORANGE%^.%^RESET%^"); break;
     case 2: tell_room(TO,"%^CYAN%^A coin %^YELLOW%^clinks %^RESET%^%^CYAN%^underfoot, startlingly loud in the silence of "
"the tunnel.%^RESET%^"); break;
     case 3..4: tell_room(TO,"%^GREEN%^The musty air tickles at your nose."); break;
     case 5: tell_room(TO,"%^BOLD%^%^BLACK%^A tiny %^RESET%^%^RED%^spider %^BOLD%^%^BLACK%^crawls over your foot and "
"across the floor.%^RESET%^"); break;
     case 6: tell_room(TO,"%^BOLD%^%^CYAN%^A chilling breath of %^WHITE%^wind %^CYAN%^whistles down the tunnel, making "
"you shiver.%^RESET%^"); break;
     case 7: tell_room(TO,"%^MAGENTA%^An uneasy feeling causes the hairs on the back of your neck tingle, sending %^CYAN%^"
"chills %^MAGENTA%^down your spine.%^RESET%^"); break;
     case 8: tell_room(TO,"%^RED%^The air is heavy and still, so silent you can hear your own %^MAGENTA%^heartbeat%^RED%^"
".%^RESET%^"); break;
     default: break;
   }
}