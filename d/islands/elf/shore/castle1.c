#include <std.h>
#include "../elf.h"
inherit WATER;
int flag;

void create(){
   ::create();
   set_short("%^BOLD%^BLUE%^Castle Ruins%^RESET%^");
   set_long(query_short()+"\nThis is the underwater ruins"+
    " inside a %^CYAN%^castle%^RESET%^.  There is a broken %^CYAN%^chair%^RESET%^ behind"+
    " a decaying %^CYAN%^desk%^RESET%^.  The stone walls are falling "+
    "over the ceiling is barely holding up.  "+
    "There looks to be some half burried dead %^CYAN%^bodies%^RESET%^ here.");
   set_listen("default","You hear the swushing of water currents.");
   set_smell("default","It is hard to smell being underwater.");
   set_exits(([
      "north" : ROOMS"/shore/castle0",
     
   ]));
   set_property("no teleport",1);
   set_door("gate",ROOMS"/shore/castle1","north","nokey");
   set_open("gate",0);
   set_locked("gate",0);
   set_items(([
      (({"castle"})) :
        "The castle is just rubble.  There should be hallways and windows but everything has fallen down.",
      (({"desk"})) : "The desk is broken.  It is mostly decayed and laying crooked on the ground.",
      (({"bodies"})) : "Bits of bodies can be seen partly sticking out of the mud.  Some of the flesh has been picked clean by fish and only bones remain.",
      (({"chair"})) : "This chair is ruined. Three of the four legs are broken it is just leaning against a rock to stand up.",
   ]));
   set_search("room",(:TO,"search_room":));
}
void reset(){
   ::reset();
   if(!present("noble",TO))
      new(MON"capn")->move(TO);
   flag = 0;
}
int search_room(string str){
  
  if (flag == 1) {
  tell_object(TP,"It seems like someone has"+
      " searched around here already.");
  return 1;
  }
  new(OBJ"agechains")->move(TO);
  tell_object(TP,"You search the room and find"+
   " some strange chains in the broken desk.");
  flag =1;
  return 1;
}