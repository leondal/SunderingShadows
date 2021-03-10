//Coded by Bane//  More random critters added by Styx via this inherit 11/15/01.
// changed to use CROOM now that it can handle random mobs and cleans them up *Styx*  3/1/03
//updated by ~Circe~ 3/29/13 for the tarrasque plot. Will be put back afterward.

#include <std.h>
#define MONS "/d/laerad/mon/"
#define MOBLIST ({ "panther", "wisp", "pixie", "stag", "gbear", "wspider", "dwolf", "wolverine", "jaguar"})

inherit CROOM;

void pick_critters();
 
void create() {
    ::create();
    pick_critters();
    set_repop(30);
    set_terrain(LIGHT_FOREST);
    set_travel(GAME_TRACK);
    set_name("Parnelli forest");
    set_short("%^BOLD%^%^BLACK%^Parnelli forest%^RESET%^");
    set_long( (: TO, "ldesc" :) );
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The scent of char and dust fills the air.");
    set_listen("default","Howls and rustlings reach your ears as the forest itself seems alive.");
    set_exits( ([
     	"west":"/d/laerad/parnelli/forest/carr3",
    	"east":"/d/laerad/parnelli/forest/for011",
     	"north":"/d/laerad/parnelli/forest/for002",
   	"south":"/d/laerad/parnelli/forest/for003"
    ]) );
}

void reset(){
   int active;
   active = has_mobs();
   if (!active) {
     if(mons)  mons = ([]);
     pick_critters();
   }
   ::reset();
}

/*
string ldesc(string str) {
   return("%^BOLD%^GREEN%^The Parnelli Forest%^RESET%^\n"+
    "You have walked into a magical forest.  The trees sway back and forth "+
    "as if hypnotized.  Leaves dance around happily in the wind.  The brush "+
    "looks as if it is glowing with pure energy.  You notice the occasional "+
    "firefly or pixie flitter through the air.  The sky above is the most "+
    "beautiful blue you have ever seen.  You feel such a serene peace here "+
    "that you just don't ever want to leave."
    );
}
*/


string ldesc(string str) {
    return("%^BOLD%^BLACK%^The Parnelli Forest%^RESET%^\n"+
           "%^GREEN%^What was once a peaceful forest filled with magical creatures has been "
           "twisted. Trees are %^ORANGE%^broken%^GREEN%^ and %^BOLD%^%^BLACK%^trampled%^RESET%^%^GREEN%^, though by what, it's hard to say. "
           "The fae themselves are hesitant and wary, so unlike their typical playful "
           "nature. A hush pervades the forest, most unnatural for this usually energetic, mystical place.%^RESET%^\n"
    );
}
 
void pick_critters() {
string mon1, mon2, mon3;
  mon1 = MONS+MOBLIST[random(sizeof(MOBLIST))];
  mon2 = MONS+MOBLIST[random(sizeof(MOBLIST))];
  mon3 = MONS+MOBLIST[random(sizeof(MOBLIST))];
  switch(random(5)) {    // to choose which mobs CROOM will set
    case 0:   
          set_monsters( ({mon1, mon2, mon3}), ({random(3)+1, random(3)+1, random(3)+1}) );
	break;
    case 1:
          set_monsters( ({mon1, mon2}), ({random(3)+1, random(3)+1}) );
	break;
    case 2:
          set_monsters( ({mon3}), ({ random(3) }) );
	break;
    case 3:
        set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
        break;
    default:
       break;
  }
}
