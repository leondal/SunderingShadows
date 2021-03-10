#include <std.h>
#include "../vale.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",0);
   set_property("light",3);
   set_short("In front of a hut");
   set_long(
   "%^GREEN%^To the north there is a break in the large wall of brush and"+
   " %^BOLD%^brambles%^RESET%^%^GREEN%^ that surrounds the center of the clearing. You can"+
   " see a%^BOLD%^%^CYAN%^ pool%^RESET%^%^GREEN%^ in the area beyond, with a bridge going across it."+
   " You're almost afraid to try and walk between the wall of thorns,"+
   " it seems like it might crush you rather quickly if it wanted to."+
   " Silly as that may seem, you notice the ground inbetween the wall"+
   " is dark, moist earth that has many scratches on it as though the"+
   " wall actually did close together. To the west is the entrance"+
   " of one of the %^ORANGE%^huts%^GREEN%^.\n"
   );
   set("night long",
   "%^BLUE%^To the north there is a break in the large wall of brush and"+
   " %^BOLD%^%^GREEN%^brambles%^RESET%^%^BLUE%^ that surrounds the center of the clearing."+
   " %^BOLD%^%^WHITE%^Starlight%^RESET%^%^BLUE%^"+
   " reflects off the many spikey %^ORANGE%^thorns%^BLUE%^, reminding you just how"+
   " deadly the wall can be. You're almost afraid to try and walk"+
   " between the wall of thorns, it seems like it might crush you"+
   " rather quickly if it wanted to. Silly as that may seem, you"+
   " notice the ground inbetween the wall is dark, moist earth that"+
   " has many scratches on it as though the wall actually did close"+
   " together. You can see a %^BOLD%^%^CYAN%^pool%^RESET%^%^BLUE%^"+
   " that reflects the %^BOLD%^%^WHITE%^moonlight%^RESET%^%^BLUE%^ like a"+
   " mirror in the area beyond, with a bridge going across it."+
   " To the west is the entrance of one of the %^ORANGE%^huts%^BLUE%^.\n"
   );
   set_smell("default","The delicate scent of flowers fills your nostrils.");
   set_listen("default","Bird song echoes throughout the vale.");
   set_items(([
   "grass" : "%^BOLD%^%^GREEN%^The grass is much shorter here, and a lighter shade of green.",
   "flowers" : "%^MAGENTA%^Several flowers have sprouted up along the ground,"+
   " there is a plethora of beautiful hues.",
   "huts" : "%^ORANGE%^There are several huts that you can see scattered"+
   " throughout the clearing. They appear to be rather simple.",
   ({"wall","brambles","bushes"}) : "%^GREEN%^There's a gap in the large wall"+
   " to the north that looks as though you could walk through it."+
   " However, you have the feeling that the wall can easily close"+
   " the gap, and would not want to be caught in the middle if it"+
   " decided to do just that!",
   "thorns" : "%^ORANGE%^Looking closely you can see sharp thorns in the wall"+
   " of brambles. You can all too easily imagine the wall closing in"+
   " on you as you try to walk through it and piercing you with its"+
   " sharp thorns.",
   ]));
   set_exits(([
   "west" : ROOMS+"hut1",
   "east" : ROOMS+"c13",
   "north" : ROOMS+"entrance",
   "south" : ROOMS+"c7",
   ]));
   set_door("door",ROOMS+"hut1","west",0);
}
