// inherit to handle all trees & randomize more/repop less while fixing typos *Styx*  3/23/03

#include <std.h>
#include "./forest.h"

inherit CROOM;

void create() {
    if(base_name(TO) != "/d/tharis/forest/forest_up") {
      switch(random(15)) {
       case 0..1:   
	set_monsters( ({ MONS"e_archer" }), ({ 1 }) );
	break;
       case 2:   
	set_monsters( ({ MONS"e_archer", MONS"sprite" }), ({ 1, 1 }) );
	break;
       case 3:	
	set_monsters( ({ MONS"e_archer", MONS"sprite", MONS"earcher" }), ({ 1, 2, 1 }) );
	break;
       case 4:
	set_monsters( ({ MONS"earcher" }), ({ random(2)+1 }) );
	break;
       default:  break;
     }
    }
    ::create();
    set_repop(20);
    set_name("Look out");
    set_property("indoors",0);
    set_property("light",1);
    set_short("A look out high in the trees");
    set_terrain(BRANCHES);
    set_travel(LEDGE);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^You are perched upon a large branch%^RESET%^
This outpost allows you to see quite a distance in several directions.
Guards often stand up here and shoot into any fights that might develop below.
As you look out of this dark area, you see the grand forest stretch out as a
perched bird might see it.  You are awed by its beauty.
OLI
    );
    set_exits(([
            ]));
    set_items(([
            "tree":"This is truly a magnificent creature in which you are perched."
            ]));

    set_smell("default","The winds bring you the sweet smells of the forest.");
    set_listen("default","You hear a slight resulting of the leaves as the wind passes.");
}

/* adding this inherit and changing to use CROOM while I'm fixing typos - so they'll clean up and not repop as quickly if they get killed  *Styx*  3/23/03
void reset(){
    ::reset();

    if(!present("archer"))
        if(random(10) < 9)
            new(MONS"e_archer")->move(TO);
    if(!present("sprite"))
        if(random(10) < 5){
            new(MONS"sprite")->move(TO);
            new(MONS"sprite")->move(TO);
        }
}
*/
