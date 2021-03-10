#include <std.h>
#include <terrain.h>
#include "../tunnel.h"
inherit CVAULT;

int getmobs;
void pick_critters();
string long_desc();

void create() {
  if(!random(2))  getmobs = 1;
  if(getmobs) pick_critters();

  ::create();
  set_repop(65);
  set_property("indoors", 1);
  set_property("light", 2);
  set_name("A narrow tunnel");
  set_short("A narrow tunnel");
  set_long((:TO, "long_desc":));
  set_terrain(NAT_CAVE);
  set_travel(SLICK_FLOOR);
  set_smell("default","The air smells of damp stone");
  set_listen("default","You can hear the sound of music coming from deep"
                      +" within the tunnels.");

  set_items( ([
     ({ "wall", "walls"}):" %^BOLD%^%^BLACK%^The walls are of black"
                         +" s%^RESET%^l%^BOLD%^%^BLACK%^ate. They are"
                         +" smooth in places, but cracked and uneven in"
                         +" others, making it hard to know whether they"
                         +" have been worked or not..",

  ({ "cracks", "fissures"}):"the larger cracks look big enough for"
                           +" something to go into of come out of, but"
                           +" they are way up out of"
                           +" reach.", 

  "ceiling" : "the ceiling is so high up as to be out of sight.",

  "floor" : "The floor is smooth, and relatively free of dirt. There are"
           +" scuff marks on it suggesting this place is frequently"
           +" travelled." 
   ]) );


  set_search("walls","you find many small cracks and fissures in the"
                    +" slate. There appear to be larger cracks higher up"
                    +" on the walls, out of reach." );

}



void reset() 
{
  int active;
  // check first to see if this room should be getting mobs at all

  if(getmobs) 
  {
    active = has_mobs();  // counts active mobs from prior spawns
    if(!active) // if they are all killed off,  pick a new set
    {  
      if(mons)  mons = ([]);  // this clears the array
      pick_critters();
    }
  }
  ::reset();  // do NOT forget to call the super here
}

string long_desc(){
     return "%^BOLD%^%^BLACK%^This is a narrow tunnel cut through the"
           +" black rock. It is unclear whether this is a crudely"
           +" constructed tunnel or simply a natural fissure, but the"
           +" walls are steep and tall, and the ceiling is way out of"
           +" sight overhead.%^RESET%^";
}

void pick_critters()
{
  // use a switch or call a function for the new settings
  switch(random(6)) // this chooses which ones to set next
  {     
  case 0..1:  
    set_monsters( ({MOB+"devilhound"}),({6}));
    break;
  case 2:
     set_monsters( ({MOB+"devilkin"}),({4}));
     break;
  case 3:
     set_monsters( ({MOB+"devilhound", MOB+"devilkin"})
                               ,({4, 2}));
     break;
  case 4:
     set_monsters( ({MOB+"devilhound", MOB+"barbazu"})
                               ,({3, 2}));
  case 5:
     set_monsters( ({MOB+"devilkin", MOB+"barbazu"})
                               ,({4, 1}));
  }
}