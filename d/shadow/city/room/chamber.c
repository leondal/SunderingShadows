//Titania 2/2/2020
//Shadow Sewers : Rat Tunnel Chamber

#include <std.h>
#include "../defs.h"
inherit CROOM;


void create(){ 
   ::create();
   set_property("light",-1);
   set_property("indoors",1);
   set_terrain(NAT_CAVE);
   set_travel(PAVED_ROAD);
   set_name("%^BOLD%^%^BLACK%^A stone chamber%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^A stone chamber%^RESET%^");
   set_long("%^RESET%^%^CYAN%^The tunnel both widens and abruptly ends here. "+
	"You have reached a %^BOLD%^%^BLACK%^stone chamber %^RESET%^%^CYAN%^where "+ 
	"there appears to be nothing to do but turn around and go back the "+ 
	"way you came. The far wall is lit by two "+ 
	"%^BOLD%^%^RED%^t%^RESET%^%^RED%^o%^BOLD%^rc%^RESET%^%^ORANGE%^h%^RED%^e%^BOLD%^s%^RESET%^%^CYAN%^, "+ 
	"and between them sits a single %^ORANGE%^wooden chair%^CYAN%^, "+ 
	"ensconced in dimness. %^BOLD%^%^BLACK%^Shadows %^RESET%^%^CYAN%^flicker "+ 
	"and dance from the torchlight. "+ 
	"It is otherwise a very plain room to find yourself in. A hint of "+ 
	"%^WHITE%^light %^CYAN%^from somewhere far overhead suggests the "+ 
	"chamber is open to the air and skies, but there does not seem "+ 
	"to be any easy way upwards.\n%^WHITE%^");
	set_smell("default","The torches put off a not wholly unpleasant scent of smoke and pine.");
	set_listen("default","You do not hear anything particularly interesting.");
	set_items(([
	({"walls","floor","wall"}) : " %^BOLD%^%^BLACK%^The stones of the chamber are smooth and shades of gray and black. They are not fancy, nor are they decrepit.%^RESET%^",
	({"torches"}) : "%^YELLOW%^Simple lights for simple chambers.%^RESET%^",
	({"crack"}) : "%^RESET%^%^ORANGE%^It is just a small crack of little consequence. The rat is long gone by now. Forget about it, and move on with your day.%^RESET%^",
	({"up","ceiling","roof"}) : "%^MAGENTA%^Smoke from the torches drifts upward and presumably out, but it's much too high for you to worry about%^WHITE%^.",
	]));
	   set_exits(([
      "northwest" : ROOMS"tunnel13",
   ]));
       set_climb_exits((["climb": ({20, 30, 100})]));
}

void reset()
{
    ::reset();
    if(!present("chrin")) {
        new(MON"chrin.c")->move(TO);
    }
}


