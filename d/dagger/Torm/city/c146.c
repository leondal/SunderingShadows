#include "../tormdefs.h"
inherit CELLAR;
inherit "/std/jail_cell.c";
void create(){
  ::create();
  set_property("indoors",1);
  set_exits(([
  "south":TCITY+"c149",
  ]));
  set_door("door","/d/dagger/Torm/city/c149","south","masterkey");
   set_open("door",0);
   set_locked("cagedoor",1,"lock");
   lock_difficulty("cagedoor",-50,"lock");
   set_property("teleport proof",100);
}
