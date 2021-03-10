#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Felyndra's Arcane Arts");
   set_short("%^BLUE%^Felyndra's Arcane Arts%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Felyndra's Arcane Arts%^RESET%^\n"
"%^BLUE%^This building only seems to consist of a single room, fairly small but surprisingly light and airy.  The usually "
"dark and oppressive %^BOLD%^%^BLACK%^s%^RESET%^t%^BOLD%^%^BLACK%^one %^RESET%^%^BLUE%^of the structure itself has been "
"shaped by some masterful hand, forming a vault of curved columns and sweeping arches that intertwine in an %^CYAN%^e"
"%^GREEN%^le%^CYAN%^ga%^GREEN%^n%^CYAN%^t %^BLUE%^dance.  Spaces between them reveal the darkened cavern roof beyond, "
"while within, they are lit by %^BOLD%^%^WHITE%^gl%^BOLD%^%^MAGENTA%^e%^BOLD%^%^WHITE%^a%^BOLD%^%^CYAN%^m%^BOLD%^%^GREEN%^i"
"%^BOLD%^%^WHITE%^ng %^RESET%^%^BLUE%^arcane lights.  Gauze curtains have been artfully placed about, catching the sparkle "
"of the lights and casting their own drifting shadows.  Comfortable %^RED%^cu%^MAGENTA%^s%^RED%^hi%^BOLD%^%^RED%^o%^BOLD%^"
"%^MAGENTA%^n%^RESET%^%^RED%^s %^BLUE%^are strewn about, and a small table nearby is set with a drink and several delicate "
"morsels, as well as two thick %^ORANGE%^books%^BLUE%^.  Little else clutters the area, but the simple elegance and "
"decadence of this place is more than apparent.%^RESET%^\n");
   set_smell("default","%^ORANGE%^A faint %^MAGENTA%^perf%^RED%^u%^MAGENTA%^me %^ORANGE%^fills the air.");
   set_listen("default","%^GREEN%^It is particularly %^CYAN%^q%^GREEN%^ui%^CYAN%^et %^GREEN%^in here.");

   set_items(([
   ]));
   set_exits(([
     "west":ROOMS"outer22",
   ]));
}

void reset(){
   ::reset();
   if(!present("felyndra")) {
       new(MON"felyndra")->move(TO);
       tell_room(TO,"%^GREEN%^Felyndra strolls casually in and reclines upon the cushions, looking completely relaxed.%^RESET%^");
       return;
   }
}