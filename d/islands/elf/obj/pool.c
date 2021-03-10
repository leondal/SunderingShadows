//pool of darkness that recreates the dusk maiden
//enough light will stop the cycle
#include <std.h>
#include "../elf.h"
#include <daemons.h>
inherit BAG;
void create(){
    ::create();
    set_id(({"pool","pool of darkness"}));
    set_name("pool of darkness");
    set_short("%^RESET%^%^MAGENTA%^pool of darkness%^RESET%^");
    set_long("%^MAGENTA%^The pool seems to feed off of the darkness in the area.");
    set_weight(99999);
    call_out("animate",50,TO);
}
void animate(object targ){
	object maiden;
	object *inven;
	int lit, j,i;
	lit = 0;
	if(!objectp(ETO)) return;
	inven=filter_array(all_living(ETO),"is_non_immortal",FILTERS_D);
    j=sizeof(inven);
  for(i=0;i<j;i++) {
     if(inven[i]->query_light() > 3) lit = 1;
    }
   
	
	if(ETO->query_light() > 3 || lit == 1){
	 tell_room(ETO,"%^MAGENTA%^The light causes the pool of darkness to fizzle into mist and vanish");
	 remove();
	 return;
	}
    tell_room(ETO,"%^MAGENTA%^A figure rises from the pool.");
    maiden =new(MON"maiden");
	maiden->set("aggressive",25);
	maiden->move(ETO);
    remove();
    return;
}
