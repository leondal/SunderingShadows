#include "../tormdefs.h"
inherit CELLAR;
void create(){
  ::create();
  set_short(
  "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
  "  You stand in the cellars of the Torm townhall."
  "  This dark hallways is lined in rough dressed stone.  Heavy doors"+
  " lay to the north and south of you."
  );
  set_exits(([
  "north":TCITY+"c146",
  "south":TCITY+"c155",
  "east":TCITY+"c150",
  ]));
  set_items(([
  "walls":"The walls are made of dull grey stone.",
   "floor":"The floors are made of dull grey stone.",
  ({"ceiling","roof"}):"The ceiling is made of dull grey stone and roughly finished.",
  ]));
  set_door("north door","/d/dagger/Torm/city/c146","north","masterkey");
  set_door("south door","/d/dagger/Torm/city/c155","south","masterkey");
  set_open("north door",0);
  set_open("south door",0);
  set_locked("north door",1);
  set_locked("south door",1);
}
