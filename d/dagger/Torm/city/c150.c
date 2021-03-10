#include "../tormdefs.h"
inherit CELLAR;
void create(){
  ::create();
  set_short(
  "Beneath the Torm townhall"
  );
  set_property("indoors",1);
  set_long(
  "  This dark stone passageway has closed doors north, south and east."
  "  The hallways runs off to the west."
  " A strange chill seems to have settled into this deathly silent hall."
  );
  set_exits(([
  "north":TCITY+"c147",
  "south":TCITY+"c152",
  "east":TCITY+"c151",
  "west":TCITY+"c149",
  ]));
  set_items(([
  "walls":"The walls are made of dull grey stone.",
   "floor":"The floors are made of dull grey stone.",
  ({"ceiling","roof"}):"The ceiling is made of dull grey stone and roughly finished.",
  ]));
  set_door("north door","/d/dagger/Torm/city/c147","north","masterkey");
  set_door("south door","/d/dagger/Torm/city/c152","south","masterkey");
  set_door("barred door","/d/dagger/Torm/city/c151","east","masterkey");
  set_open("north door",0);
  set_open("south door",0);
  set_open("barred door",0);
  set_locked("north door",1);
  set_locked("south door",1);
  set_locked("barred door",1);
}
