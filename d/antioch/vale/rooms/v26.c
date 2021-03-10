#include <std.h>
#include "../vale.h"
inherit GRASS;

void create()
{
   ::create();
   set_long(
   "You are in the northern half of Moonstone Vale. There is a feeling"+
   " of peace here and everything seems to be full of life. Lush grass"+
   " reaches up at least six inches, and seems to flourish at the edges"+
   " of the forest. A few small animals are scampering about and"+
   " looking for food in this area. Colorful butterflies float"+
   " on the breeze, occasionally stopping at one of the few flowers"+
   " that've managed to push their way above the grass. It is much"+
   " calmer here than on the other side of the vale. To the northeast is"+
   " one of the huts that are scattered about the vale."
   );
   set("night long",
   "You are in the northern half of Moonstone Vale. Starlight bathes"+
   " everything in a pale silver, making it seem as though you've"+
   " passed into a mystical plane. The grass is ruffled by a gentle"+
   " breeze and everything seems calm and peaceful. You can hear a few"+
   " nightingales singing a beautiful melody from somewhere in the"+
   " distance. The forest is not too far away, but unlike the Dark"+
   " Forest on the other side, this one seems fairly normal and serene."+
   " To the northeast is one of the huts that are scattered about the vale."
   );
   set_exits(([
   "west" : ROOMS+"v27",
   "east" : ROOMS+"c8",
   "north" : ROOMS+"c11",
   "south" : ROOMS+"rbank14",
   ]));
}
