#include <std.h>
inherit "std/Object";
void create(){
  ::create();
  set_name("a small stone cube");
  set_id(({"stone cube","cube","stone"}));
  set_short("small stone cube");
   set_long(" This is a stone cube that is small enough to fit in the palm of a human hand.   It's featureless and rather boring looking.");
 set_weight(1);
}
int drop(){
  if(!interactive(ETO)){
  ::drop();
  return 1;
  }
  tell_object(TP,"The stone fades away as it leaves your hands!");
   tell_room(ETP,"The stone in "+ETO->query_cap_name()+"'s hands fades away and then vanishes!\n",TP);
  destruct(TO);
  return 1;
}
