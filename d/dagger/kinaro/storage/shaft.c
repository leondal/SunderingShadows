#include <std.h>
#include "../defs.h"
inherit ROOM;

void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   if(!random(4)) set_property("no teleport",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("A sloped mining shaft");
   set_short("%^BOLD%^%^BLACK%^A sloped mining shaft%^RESET%^");
   set_long("%^ORANGE%^This tunnel leads at an angle down into deeper reaches of this mine.  The shaft is "
"obviously not naturally formed, cut into the recesses of the mountainside and supported by %^RED%^wooden "
"struts %^ORANGE%^and %^BOLD%^%^BLACK%^bars %^RESET%^%^ORANGE%^at regular intervals.  From within the stone "
"walls themselves glitter hints of %^WHITE%^met%^BOLD%^a%^RESET%^ls %^ORANGE%^and precious%^BOLD%^%^RED%^ "
"g%^YELLOW%^e%^RESET%^%^GREEN%^m%^BLUE%^s%^ORANGE%^, just waiting to be extracted.  Along the ground run "
"%^BOLD%^%^BLACK%^sturdy metal rails%^RESET%^%^ORANGE%^, probably designed to carry mining carts back and "
"forth.%^RESET%^");
   set_smell("default","The air carries a dry and dusty smell.");
   set_listen("default","The occasional sound of metal on stone reaches your ears.");
   set_items(([
     ({"walls","roof","ceiling","rock","stone"}):"%^ORANGE%^This tunnel has been cut directly into the "

"mountainside, forming a sloped shaft that gradually leads deeper underground.  %^BOLD%^%^BLACK%^Solid bars "
"%^RESET%^%^ORANGE%^and %^RED%^wooden struts%^ORANGE%^ provide support to the tunnel at regular intervals.  "
"From within the stone walls sparkle hints of %^WHITE%^met%^BOLD%^a%^RESET%^l %^BOLD%^%^CYAN%^o%^RESET%^re "
"%^ORANGE%^and precious %^BOLD%^%^RED%^ge%^YELLOW%^ms%^RESET%^%^GREEN%^to%^BLUE%^ne%^MAGENTA%^s%^ORANGE%^."
"%^RESET%^",
     ({"bars","struts"}):"%^ORANGE%^Thick %^RED%^wooden beams %^ORANGE%^provide support to the tunnel at "
"regular intervals, supported at each join by %^BOLD%^%^BLACK%^solid metal bars%^RESET%^%^ORANGE%^.%^RESET%^",
     ({"gems","metals","gemstones","ore"}):"%^ORANGE%^Glittering traces of %^WHITE%^met%^BOLD%^a%^RESET%^l "
"%^BOLD%^%^CYAN%^o%^RESET%^re %^ORANGE%^and precious %^BOLD%^%^RED%^ge%^YELLOW%^ms%^RESET%^%^GREEN%^to%^BLUE%^"
"ne%^MAGENTA%^s%^ORANGE%^ show in the stone walls around you.%^RESET%^",
     ({"rails","ground","floor"}):"%^ORANGE%^Along the stone ground run a pair of %^BOLD%^%^BLACK%^sturdy "
"metal rails%^RESET%^%^ORANGE%^, leading back toward the mine's entrance.  Presumably they are designed to "
"carry mining carts back and forth.%^RESET%^",
   ]));
}
