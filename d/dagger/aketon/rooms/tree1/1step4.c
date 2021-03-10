#include "/d/dagger/aketon/short.h"
#include <daemons.h>

inherit ROOM;

void create() {
   ::create();
   set_property("light",2);
   set_short("Steps around the giant tree");
   set_long("%^GREEN%^Steps around the giant tree%^RESET%^
You are on the steps around the giant tree. These steps connects the two "
      "different levels of the city built on this huge tree hidden in the "
      "Kilkean forest. The steps continue twisting up and down the huge "
      "tree trunk. Below you is the lowest level and more levels can be "
      "seen above.");
   set_items( (["steps":"These steps twist around the giant tree trunk.",
      ({"forest","kilkean"}):"The dense Kilkean forest is all around you.",
      "city":"You can see shadows moving around upon the tree branches.",
      "levels":"You can see the lowest level of the tree branches below "
      "and some more levels above you.",
      "trunk":"This is a party of the huge tree body."]) );
   set_exits( (["up":RPATH1+"1two1",
      "down":RPATH1+"1one1"]) );
   set_pre_exit_functions( ({"up"}),({"up_func"}) );
}

int up_func() {
   object obj;
   if( obj = present("standing guard") ) {
      if( (int)SAVE_D->is_member("aketon_list",TPQN) == -1 ) {
         obj->force_me("say What is your business here? You are not "
            "allowed to go up there!");
         return 0;
      }
      else {
         obj->force_me("say All citizens are welcomed here.");
         return 1;
      }
   }
   return 1;
}

void reset() {
   ::reset();
   if(!present("standing guard")) {
      new(MPATH+"guardD")->move(TO);
      new(MPATH+"guardD")->move(TO);
   }
   else if(!present("standing guard 2"))
      new(MPATH+"guardD")->move(TO);
   else
      return;
}
