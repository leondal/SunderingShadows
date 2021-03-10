//Titania (6/30/2019)
//The Thief Guild Lounge, Shadow
//Designed by Kiyoshi

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("The Guild Fence, Shadow");
   set_short("%^BOLD%^%^WHITE%^T%^RESET%^h%^BOLD%^%^BLACK%^e "+
   "%^WHITE%^G%^RESET%^u%^BOLD%^%^BLACK%^ild "+
   "%^BOLD%^%^WHITE%^F%^RESET%^e%^BOLD%^%^BLACK%^nce%^RESET%^");
   set_long("%^RESET%^%^CYAN%^Lit by a few sputtering "+
   "%^BOLD%^%^RED%^t%^ORANGE%^o%^RED%^r%^RESET%^%^RED%^c%^ORANGE%^hes%^CYAN%^, "+
   "this is the heart of the guild. Divided in half by a lengthy "+
   "%^ORANGE%^counter%^CYAN%^, the other half of the room is covered "+
   "in cabinets, bins, and shelves covered in a assortment of "+
   "%^WHITE%^e%^BOLD%^q%^RESET%^u%^BOLD%^%^BLACK%^ip%^RESET%^m%^BOLD%^e%^RESET%^n%^BOLD%^%^BLACK%^t "+
   "%^RESET%^%^CYAN%^and other "+
   "%^YELLOW%^v%^WHITE%^a%^ORANGE%^lu%^RESET%^%^ORANGE%^a%^BOLD%^b%^RESET%^%^ORANGE%^l%^BOLD%^e%^WHITE%^s%^RESET%^%^CYAN%^. "+
   "There is certainly some manner of order at work, but you "+
   "cannot conceive it at a glance. A corner of the room is "+
   "partitioned, featuring a collection of "+
   "%^BOLD%^%^WHITE%^t%^RESET%^e%^BOLD%^st "+
   "t%^RESET%^u%^BOLD%^be%^RESET%^s%^CYAN%^, "+
   "%^RED%^m%^MAGENTA%^o%^RED%^rta%^MAGENTA%^r%^RED%^s%^CYAN%^, "+
   "%^MAGENTA%^p%^RED%^e%^MAGENTA%^stl%^RED%^e%^MAGENTA%^s%^CYAN%^, "+
   "and strange %^GREEN%^g%^BOLD%^r%^RED%^a%^GREEN%^in%^RESET%^%^GREEN%^y "+
   "c%^BOLD%^o%^RED%^m%^GREEN%^p%^RESET%^%^GREEN%^o%^BOLD%^u%^RED%^n%^GREEN%^d%^RESET%^%^GREEN%^s "+
   "%^CYAN%^that supply the guild with some of their more "+
   "sinister offerings.%^RESET%^\n");
   set_smell("default","%^RESET%^%^GREEN%^There is an acrid stench coming from the corner of the room..%^RESET%^");
   set_listen("default","%^RESET%^%^ORANGE%^You can hear a few of the torches sputtering.%^RESET%^");
   set_items(([
      "counter" : "%^RESET%^%^CYAN%^This solid looking %^ORANGE%^counter "+
	  "%^CYAN%^has been carved from %^ORANGE%^o%^BOLD%^a%^RESET%^%^ORANGE%^k%^CYAN%^,"+
	  "made wide enough that leaping it would be a "+
	  "difficult task and leave one greatly %^BOLD%^%^RED%^exposed "+
	  "%^RESET%^%^CYAN%^in doing so.%^RESET%^",
      ({"test tubes","mortars","pestiles","compounds"}) : "%^RESET%^%^CYAN%^This "+
	  "paraphernalia looks to be the source of the "+
	  "%^MAGENTA%^p%^BOLD%^o%^RED%^w%^MAGENTA%^d%^RESET%^%^MAGENTA%^e%^BOLD%^r%^RESET%^%^MAGENTA%^s "+
	  "%^CYAN%^and %^GREEN%^p%^BOLD%^o%^ORANGE%^i%^GREEN%^s%^RESET%^%^GREEN%^o%^BOLD%^n%^RESET%^%^GREEN%^s "+
	  "%^CYAN%^that the guild supplies to its more valued agents.%^RESET%^",
   ]));
   set_exits(([
      "out" : ROOMS"thieflounge"
   ]));
}
void reset()
{
    ::reset();
    if(!present("granan")) {
        new(MON"granan.c")->move(TO);
    }
}