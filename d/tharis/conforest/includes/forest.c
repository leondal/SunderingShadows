#include <std.h>
#include "../defs.h"
inherit ROOM;

int getmobs;
void loader();

void create()
{
// adding control so not all rooms will get mobs on a given create for population control *Styx*  3/17/05
  if(!random(5)) 
	getmobs = 1;

  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(FRESH_BLAZE);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^Deep Within Darkwood Forest%^RESET%^");
  set_long( (: "ldesc" :) );
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The trees creak as they sway in the wind.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
	"for space amongst the tall pine trees."
    ]) );
}

void reset()
{
  ::reset();
  if(!getmobs)
	return;
  if(base_name(TO) == "/d/tharis/conforest/includes/forest")
	return;
  if(!present("monster") && !random(2)) 
      loader();
}

string ldesc(string str) {
   if(query_night() == 1)
     return("%^ORANGE%^D%^MAGENTA%^eep %^MAGENTA%^Within %^MAGENTA%^D%^ORANGE%^a%^ORANGE%^r%^ORANGE%^k%^ORANGE%^w%^MAGENTA%^ood %^MAGENTA%^Fores%^ORANGE%^t
%^BLUE%^The %^MAGENTA%^t%^ORANGE%^r%^ORANGE%^e%^MAGENTA%^e%^ORANGE%^s%^BLUE%^ seem to close in around you, sucking up all of the moonlight before it can reach you. You are just noticing how quiet the forest seems when the silence is broken by a wolf howling nearby. His wailing voice is joined in by more and more wolves, until the forest echoes with their dreary song. You get the feeling you should get moving, preferably away from the wolves."
     );

     return("%^MAGENTA%^Deep %^MAGENTA%^Wi%^ORANGE%^t%^MAGENTA%^h%^ORANGE%^i%^MAGENTA%^n %^ORANGE%^D%^MAGENTA%^a%^ORANGE%^r%^MAGENTA%^k%^ORANGE%^w%^MAGENTA%^ood %^MAGENTA%^F%^ORANGE%^o%^MAGENTA%^res%^ORANGE%^t
%^GREEN%^The forest is much more dense here than it was along the path. The %^MAGENTA%^t%^ORANGE%^r%^MAGENTA%^ees%^GREEN%^ stand so close together, you don't know how they can all manage to draw enough water to grow. Something large and quick darts between the trees up ahead, and you realize this portion of the forest has grown very still and quiet. Perhaps you should return to the main path?"
     );
}

void loader()
{

  if(query_night() == 1)
  {
    switch(random(16))
    {
      case 0:
        new(MONS+"ettercap")->move(TO);
        break;
      case 1..3:
        new(MONS+"buck")->move(TO);
        break;
      case 4:
        new(MONS+"ogre")->move(TO);
        break;
      case 5..6:
        new(MONS+"orcbandit")->move(TO);
        break;
      case 7..8:
        new(MONS+"orcmarauder")->move(TO);
        break;
      case 9..11:
        new(MONS+"wolf")->move(TO);
        break;
      case 12..13:
        new(MONS+"vscout")->move(TO);
        break;
      case 14..15:
        new(MONS+"vhunter")->move(TO);
        break;
    }
  }
  else
  {
    switch(random(15))
    {
      case 0..2:
        new(MONS+"bear")->move(TO);
        break;
      case 3..5:
        new(MONS+"buck")->move(TO);
        break;
      case 6:
        new(MONS+"ogre")->move(TO);
        break;
      case 7..8:
        new(MONS+"orcbandit")->move(TO);
        break;
      case 9..10:
        new(MONS+"orcmarauder")->move(TO);
        break;
      case 11..12:
        new(MONS+"vhunter")->move(TO);
        break;
      case 13..14:
        new(MONS+"vscout")->move(TO);
        break;
    }  
  }
}
