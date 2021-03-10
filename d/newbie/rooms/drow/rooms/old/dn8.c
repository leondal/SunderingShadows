#include <std.h>
#include "../drownew.h"

inherit CAVERN;

/* changing to have inherit handle it with CROOM controls *Styx*  3/20/03
void reset() {
        ::reset();
        if(present("drowf") || present("drowt")) return;
        if(!random(10)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(15)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(15)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
        if(!random(20)) {
            new(DNMONS+"ndrowt")->move(TO);
            return;
        }
        if(!random(25)) {
            new(DNMONS+"ndrowfr")->move(TO);
            return;
        }
}
*/

void create(){
::create();
  	set_exits(([
		"east" : DNROOMS+"dn9",
		"southeast" : DNROOMS+"dn11"
    	]));
}