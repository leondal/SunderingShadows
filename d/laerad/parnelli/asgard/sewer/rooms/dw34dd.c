#include <std.h>
#include "../lizard.h"

inherit DEEP3;

// int FLAG;

/* changing search to use set_search to avoid problems & conform with standard searching while moving the boots to the new mobs Dinji coded for them (too easy to get this way)
moved the whole thing to the inherit to be in random of the four of these
   *Styx*  6/27/03
void init() {
    ::init();
    add_action("search","search");
}
*/

void create(){
   ::create();
/*   set_long("%^BOLD%^%^BLUE%^You are beneath the surface in an underground lake.  "+
        "Blurry darkness surrounds you in all directions.  On the floor you see a body.  "+
        "A corpse from someone who could not swim very well no doubt, or maybe he just fell "+
        "victim to the weapons of the lizardmen.  %^RESET%^");
   add_item("corpse":"Not much is left of the body of this doomed adventurer, maybe something of his gear is still useable.");
   FLAG = 0;
*/
   set_exits(([
   	"northwest":LROOMS+"dw28dd",
   	"up":LROOMS+"dw34d"
   ]));
}

/* see note in init
int search(string str) {
  if(!str) {
    tell_object(TP,"Search what?");
    return 1;
  }
   if(FLAG == 0) {
        FLAG = 1;
    if((str == "corpse")){
    tell_object(TP,"You search the corpse and find a green key and some other items!  \n");
    tell_room(environment(TP),""+this_player()->query_cap_name()+" searches the corpse and finds a green key and some other items.\n");
        new(LOBJ+"wcloak")->move(TO);
        new(LOBJ+"lsboots")->move(TO);
        new(LOBJ+"green_key")->move(TO);
       return 1;
  }
}else {
        tell_object(TP,"There is nothing left of value on the corpse.");
        return 1;
    }
}
*/

