#include <std.h>
#include "../witchlair.h"
inherit CROOM;

void create(){
   ::create();
   set_property("light",-1);
   set_property("no sticks",0);
   set_property("no teleport",0);
   set_property("no starve",0);
   set_property("no magic",0);
   set_property("no steal",0);
   set_short("%^BOLD%^%^BLACK%^With%^RESET%^%^BLUE%^i"
"%^BOLD%^%^BLACK%^n a d%^RESET%^%^BLUE%^a%^BOLD%^%^BLACK%^rk "
"t%^RESET%^%^ORANGE%^u%^GREEN%^n%^BOLD%^%^BLACK%^n"
"%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^l%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^It seems you've reached the end of "
"this hellish tunnel. The sides merge before you into a convex wall,"
" complete with a small monument of sorts, carved from the very stone"
" of this tunnel. Something is placed on the monument that perhaps you"
" could, or should, take.%^RESET%^");
   set_smell("default","The scents of dirt and plant decay "
"tickle your nose.");
   set_listen("default","It is quiet in here, unsettlingly so.");
   set_exits(([
     "south":ROOMS"roots.c",
   ]));
}

void reset(){
object ob;
   ob = new(OBJ"keyshard");
   if(!present ("shard3")){
     ob->shard_pick(3);
     ob->move(TO);
   }
}
