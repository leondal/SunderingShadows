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
   set_name("A broad mining tunnel");
   set_short("%^BOLD%^%^BLACK%^A broad mining tunnel%^RESET%^");
   set_long("This tunnel is wide enough that it could easily fit several "
"people across, or perhaps a fair-sized cart.  It leads through winding turns "
"deeper into the mountain side, on what seems to be a relatively flat level.  "
"The shaft is obviously not naturally formed, cut into the %^ORANGE%^solid "
"stone %^RESET%^of the mountainside and supported by %^RED%^sturdy wooden "
"struts %^RESET%^and %^BOLD%^%^BLACK%^metal bars %^RESET%^at regular "
"intervals.  From within the stone walls themselves glitter hints of "
"%^BOLD%^%^WHITE%^met%^RESET%^a%^BOLD%^%^WHITE%^ls %^RESET%^and precious "
"%^RED%^g%^ORANGE%^e%^GREEN%^m%^BLUE%^s%^RESET%^, just waiting to be "
"extracted.  Along the ground run a pair of %^BOLD%^%^BLACK%^thick metal "
"rails%^RESET%^, which occasionally branch to tunnels on either side of this "
"main thoroughfare.");
   set_smell("default","The air carries a dry and dusty smell.");
   set_listen("default","The occasional sound of metal on stone reaches your ears.");
   set_items(([
     ({"walls","roof","ceiling","rock","stone"}):"This tunnel has been cut "
"directly into the mountainside, forming a wide thoroughfare that traces a "
"winding, but fairly flat-level, path.  %^BOLD%^%^BLACK%^Solid bars%^RESET%^ "
"and %^RED%^wooden struts %^RESET%^provide support to the tunnel at regular "
"intervals.  From within the stone walls sparkle hints of%^BOLD%^%^WHITE%^ "
"met%^RESET%^a%^BOLD%^%^WHITE%^l %^CYAN%^o%^WHITE%^re %^RESET%^and precious "
"%^RED%^ ge%^ORANGE%^ms%^GREEN%^to%^BLUE%^ne%^MAGENTA%^s%^RESET%^.",
     ({"bars","struts"}):"Thick %^RED%^wooden beams %^RESET%^provide support "
"to the tunnel at regular intervals, supported at each join by "
"%^BOLD%^%^BLACK%^solid metal bars%^RESET%^.",
     ({"gems","metals","gemstones","ore"}):"Glittering traces of "
"%^BOLD%^%^WHITE%^met%^RESET%^a%^BOLD%^%^WHITE%^l %^CYAN%^o%^WHITE%^re "
"%^RESET%^ and precious %^RED%^ge%^ORANGE%^ms%^GREEN%^to%^BLUE%^ne%^MAGENTA%^"
"s%^RESET%^ show in the stone walls around you.",
     ({"rails","ground","floor"}):"Along the stone ground run a pair of "
"%^BOLD%^%^BLACK%^thick metal rails%^RESET%^, leading back toward the mine's "
"entrance.  Presumably they are designed to carry mining carts back and "
"forth.",
   ]));
}
