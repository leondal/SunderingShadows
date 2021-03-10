#include <std.h>
#include "../derrodefs.h"
inherit OBJECT;
void create(){
  ::create();
  set_name("chains");
  set_id(({"chains","chain","blackened chains"}));
  set_short("%^BOLD%^%^BLACK%^Blackened chains%^RESET%^");
   set_long("  These chains are blackened with corrosion and seem to twitch with their own life at times."
  "  They keep trying to wrap themselves about the shoulders of anyone who holds them as if looking for something to chain."
   "  They glow with a black magic and seem to radiate a power from within themselves."
);
  set_weight(10);
  set_value(10);
}
int drop(){
  if(!interactive(ETO)){
  ::drop();
  return 1;
  }
  tell_object(TP,"The chains vanish from your hands as you try to move them!");
   tell_room(ETP,"The chains vanish from "+TPQCN+"'s hands as "+TP->query_subjective()+" tries to move them!",TP);
/* changing to use remove() so it won't screw up encumbrance *Styx*  11/14/03, last chg. 11/21/00
  destruct(TO);
*/
  remove();
  return 1;
}
