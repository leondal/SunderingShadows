//updated 10/31/04 by Circe to reflect Silvanus's withdrawal
//updated 3/26/13 by ~Circe~ to reflect Silvanus's impending return
#include <std.h>
inherit ROOM;
//inherit "/std/temple";

void create()
{
   ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(FOOT_PATH);
   set_light(2);
   set_indoors(0);
//   set_temple("silvanus");
   set_smell("default","The air is filled with the smell of the forest that surrounds you.");
   set_listen("default","The sounds of the forest surround you.");
   set_short("A small, quiet shrine");
/*
   set_long(
@DESC
%^BOLD%^%^GREEN%^The Temple of Silvanus%^RESET%^
You have entered a large clearing deep in the heart of the forest
that serves as a temple of Silvanus. Trees rise to great heights 
all around you, and there is a feeling of harmony here. Silvanus's 
faithful will defend such a place to the death, if needed.
Silvanus' charge to his followers is displayed on one of the walls.
DESC
   );
*/
   set_long(
"%^BOLD%^%^GREEN%^A small, quiet shrine%^RESET%^%^GREEN%^\n"
"This clearing deep in the forest of Deku is lush with "
"%^BOLD%^vines %^RESET%^%^GREEN%^and %^BOLD%^moss%^RESET%^%^GREEN%^.  Nature "
"abounds all around the grove border, and a calm hush fills "
"the grove itself, invoking a sense of reverence.  Great oaks rise "
"all around you, their branches waving lazily upon the wind.  At the "
"base of one %^ORANGE%^great oak %^GREEN%^is a small, crude altar.\n"
   );
   set_exits(([
      "out":"/d/deku/forest/dforest11-al2"
   ]));
   set_items(([
      "trees":"You are surrounded by huge trees reaching to the sky.",
//      "wall":"You see Silvanus's charge to his followers on the wall.",
//      "charge":"Maybe you should read it.",
   ]));
}

/*
void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Silvanus charged his followers with this message:%^RESET%^
%^CYAN%^
All is in a cycle, deftly and beautifully balanced - it is your duty 
to see this cycle and the sacred Balance as clearly as possible, to 
make others see it, and to work against all beings and things who 
seek to disturb the Balance. Fight against the felling of forests, 
banish disease wherever it is found, and defend the trees and plant 
new ones whenever possible. Kill only when needful, for all things 
in the forest are in balance. Destroy fire and those who employ it, 
and beware those who bring axes into the forest.
CHARGE
   );
   if((string)TP->query_diety() == "silvanus" || avatarp(TP))
   write(
@EXTRA
============================================================================
%^BOLD%^As a follower of Silvanus ...
%^RED%^  allied deities are: %^RESET%^Istishia, Mielikki, Lathander
%^RED%^  enemy deities are: %^RESET%^Malar, Talos, Beshaba

%^BOLD%^This is information only followers of Silvanus should know.
EXTRA
   );
   return 1;
}
*/