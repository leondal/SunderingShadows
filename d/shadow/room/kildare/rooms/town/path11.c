//path11.c
#include "../../kildare.h"

inherit PATHEND;

void create()
{
   ::create();
   set_long(
@CIRCE
%^BOLD%^%^WHITE%^A Rocky Path
%^RESET%^%^CYAN%^Despite the hard stone of the mountain, this well-worn footpath 
runs through this tiny valley.  On a small, rocky rise to the north is the 
most impressive building in this village, complete with an ornate 
%^YELLOW%^oak door%^RESET%^%^CYAN%^.  It has two small windows set with glass and 
hung with deep %^RED%^maroon curtains.  %^CYAN%^The path curves here, leading 
to both the southwest and southeast.
CIRCE
    );
   set_items(([
      ({"stone","mountain"}) : "The deep gray stone of the mountain is "+
      "broken only by fitful clumps of coarse grass.",
      ({"rise","rocky rise"}) : "To the north, a small rise bears "+
      "an impressive stone house.",
      ({"building","house","stone building"}) : "The large stone building "+
      "is built squat but sturdy to protect it from the fierce winds "+
      "that gust along the mountainside.  The windows and oak door suggest "+
      "someone of import must reside here.",
      ({"ornate door","ornate oak door"}) : "The polished oak door on the "+
      "house has been carved with a crest - a shepherd's crook crossed with "+
      "a longsword over a large shield.",
      ({"window","windows","curtains"}) : "The two %^BOLD%^%^CYAN%^glass windows %^RESET%^are spotless "+
      "and clear.  They are set with %^RED%^woven maroon curtains %^RESET%^that have the "+
      "delicate look of silk."
      ]));

   set_exits(([
      "southwest" : TROOMS"path12",
      "southeast" : TROOMS"path10",
      "north" : TROOMS"leader"
      ]));
   set_door("oak door",TROOMS"leader","north",0);
}
