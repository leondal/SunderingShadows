#include <std.h>
inherit OBJECT;

void create(){
  ::create();
  set_name("star gem");
   set_id(({"star","star gem","star sapphire","sapphire"}));
   set_short("%^RESET%^%^CYAN%^st%^BOLD%^ar sa%^CYAN%^pph%^RESET%^%^CYAN%^ire%^RESET%^");
   set_long(" This small blue gem has a brilliant white cross in its center."
   "  Looking closely you notice it has setting marks as if it has been pried out of a piece of jewelry."
  );
  set_property("no animate",1);
  set_weight(5);
  set_value(random(2220)+1000);
}

int drop(){
  if(!interactive(ETO)){
  ::drop();
  return 1;
  }
   tell_object(TP,"%^BOLD%^%^CYAN%^The star flashes in your hands and disappears!\n");
   tell_room(ETP,"%^BOLD%^%^CYAN%^The star flashes and disappears from "+TP->query_cap_name()+"'s hands!\n",TP);
/* changing to use remove() so it won't screw up encumbrance *Styx*  11/14/03, last chg. 2/27/02
  destruct(TO);
*/
  remove();
  return 1;
}

int is_scimitar_gem(){ return 1; }