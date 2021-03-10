#include <std.h>
#include "short.h"

inherit CITYOUT;

void create() {
   ::create();
   set_short("Inside the gazebo");
   set_terrain(GARDEN);
   set_travel(DIRT_ROAD);
   set_property("indoors",0);
   set_property("light",3);
   set_long(
@DESC
A few pink petals from surrounding dogwood trees drift through 
the trellised white sides of the gazebo and land around you.  
The gazebo has been designed to allow lots of sunlight through 
and has open panels on the roof. There are several rows of 
benches and a raised platform at the far end. Two statues of 
angels stand on either side of the platform and peer into the room.  
Sprigs of flowering ivy hang down from the boards of the ceiling, 
hiding its true height when you gaze across it. A family of 
sparrows has built a nest in some of the ivy just above you.
DESC
   );
   set_exits(([
      "out" : "/d/attaya/seneca/churchyard",
   ]));
   set_items(([
      "trees" : "The trees represent species gathered from every corner of this world.  Many are flowering and they provide a mystical touch all around you.",
      "ivy" : "The flowering ivy is all over the roof and hangs from the side trellaces as well.",
      "nest" : "It is a small sparrows nest from which comes a loud peeping of chicks.",
      "statues" : "They are angels praying.  They stand at either side of the platform and appear to look out at you.",
      "petals" : "delicate pink petals litter the benches and the floor.  They drift down into the gazebo from nearby dogwood trees.",
      "floor" : "It is made of white wooden planks and is covered with dogwood petals.",
      "bushes" : "Tropical hibiscus and other bushes make natural walls in places and soften the walls of the cathedral and the fences that surround the yard.",
      "gazebo" : "The white gazebo is a favorite spot for weddings on sunny days.  It is large and surrounded by pink flowering dogwood trees.",
      "pond" : "The crystal clear waters of the pond cast your reflection back at you.",
      "cathedral" : "The rear of the cathedral is as ominous as the front.",
   ]));
}
