#include "/d/antioch/areadefs.h"
#include <std.h>
inherit WEAPON;
 
void create() {
  ::create();
  set_name("an elemental wand");
    set_id(({"wand","a wand","elemental wand","assembled wand"}));
  set_short("an elemental wand");
    set_long(
@ANTIOCH
The handle of the wand fits perfectly into the palm of your hand.
The wand seems to be giving off a strange feeling of power, but you
find that you have no knowledge of harnessing that power.  The wand
is made up of many colors swirled together, constantly moving and
changing its appearance.
It looks very fragile, you should be careful not to drop it.
ANTIOCH
    );
  set_weight(4);
  set_type("bludgeoning");
  set_wc(1,4);
  set_large_wc(1,6);

}

int drop(){
  if(!interactive(ETO)){
    ::drop();
    return 1;
  }
  tell_object(TP,"%^BOLD%^%^BLUE%^You drop the wand and it shatters!!!");
  tell_room(ETP,"%^BOLD%^%^BLUE%^"+TPQCN+" drops the wand and it shatters!!!\n",TP);
  destruct(TO);
  return 1;
}


void init(){
  ::init();
  add_action("no_give","give");
}
no_give(string str) {
   string what, who;

   if (sscanf(str,"%s to %s", what, who) != 2) 
      return 0;
   if(id(what))
     return notify_fail("You can't give this wand away.\n");
   else
     return 0;
}
