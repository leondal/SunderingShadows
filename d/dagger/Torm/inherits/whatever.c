#include <std.h>
#include "../tormdefs.h"
inherit VAULT;

void create()
{
    ::create();
    set_property("light",2);
    set_short("In the city of Torm");
    set_smell("default","You smell salt in the air from the Dagger Sea.");
    set_listen("default","The waves of the sea wash against the docks.");
    set_items(([
	({"dagger sea","sea"}) : "The Dagger Sea stretches off to the east"+
   " from the city.  The great harbor is full of ships in the day and"+
   " eerily quiet at night, if it can be seen at all.",
	"gates" : "These gates are thin looking bronze with runes inscribed"+
   " in them.  They don't look that strong but the runes have an odd"+
   " glow about them...",
   "marketplace" : "Torm's marketplace emcompasses a huge open area just"+
   " in from the docks and south of the walled park.  During the day"+
   " it's packed with people of all types from all corners of the lands"+
   " while at night it lies deserted and empty.",
	"fog" : "Fog covers the city in a light, wispy blanket at night,"+
   " mostly clinging to the ground and avoiding the buildings and"+
   " any people that might be about.",
	"houses" : "The houses of the people of Torm lie along all the roads,"+
   " their doors shut against the world at night.",
   ({"walls","city walls"}) : "The walls that surround Torm and the"+
   " mansions and park within it are made of a strange green stone with"+
   " no seams.  There are many aquatic scenes carved into them.  The"+
   " walls themselves are exceedingly thin for defensive walls, with not"+
   " even enough room for a walkway atop them, only guardtowers here and"+
   " there along their length.",
	({"mansion","fortress"}) : "You can only see the tops of spires over"+
   " the walls that surround the mansions.",
   ({"buildings","building","shops"}) : "The majority of the structures"+
   " in Torm are more elaborate than they really need to be, with gilded"+
   " corners and tall gleaming spires from their peaks.",
   ]));
}

void reset(){
    object ob;
    ::reset();
   if(!(query_night())) {
	   if(!present("dayperson",TO)) {
	      switch(random(10)){
            case 0..6:
               new(MON+"citizen.c")->move(TO);
               break;
            case 7:
               new(MON+"begger.c")->move(TO);
               break;
            case 8:
               new(MON+"guard2.c")->move(TO);
               break;
            case 9:
               new(MON+"fisherman.c")->move(TO);
               break;
         }
      }
   }
}
