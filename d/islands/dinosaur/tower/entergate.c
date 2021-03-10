#include <std.h>
#include "/d/islands/dinosaur/short.h"

inherit ROOM;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
    set_short("%^BLUE%^Gates of the Tower of Rakatan%^RESET%^");
    set_long(
      "%^BOLD%^%^RED%^You are standing at the entrance to the tower known as %^RESET%^%^BLUE%^The "+
      "Tower of Rakatan.%^BOLD%^%^RED%^  You have heard rumors about this place, of the strange cult "+
      "of clerics and mages that have taken up residence here, how they revived the ancient and "+
      "gigantic dinosaurs.  You shiver as you try not to think of what they may be doing now."+
      "\n%^BOLD%^%^BLUE%^The tower itself stands many stories high.  Few windows of any kind, "+
      "even arrow slits, peer from its round sides.  A perfect cylinder, the tower walls are "+
      "almost perfectly smooth.  You are standing before the locked main gate and portcullis of "+
      "the tower.  There is no obvious other way to enter the tower."
    );
    set_items( ([
      "portcullis" : "A large metal mesh grate lowered to keep out unwanted visitors.  It is large, heavy, and lowered.",
      "gate" : "The twin wooden gates, reinforced with large metal bands, are closed and blocking your way.",
      "windows" : "There are few windows, none that you could even dream about climbing to.",
      "walls" : "The walls are perfectly straight, and smooth as glass, even for rock.",
    ]) );
    set_exits( ([
      "cliffs" : RPATH "cliff19.c",
    ]) );
    set_smell("default", "You smell mildew");
    set_listen("default", "The silence is eerie");
}
