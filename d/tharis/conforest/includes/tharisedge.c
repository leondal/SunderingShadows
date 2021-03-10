#include <std.h>
#include "../defs.h"
inherit ROOM;

void create()
{
  
  ::create();
   set_terrain(HEAVY_FOREST);
   set_travel(GAME_TRACK);
  set_property("indoors",0);
  set_property("light",1);
  set_short("%^BOLD%^Near Tharis Forest%^RESET%^");
  set_long("Only a few rays of sunlight manage to find their "+
	"way through the densely packed trees.  The forest seems "+
	"very quiet here...as you look around, you fail to find "+
	"any signs of wildlife.  To the south, the trees begin to "+
	"change slightly...twisting, almost as if they are wracked "+
	"with pain.  An unsettling, ominous presence seems to "+
	"radiate from the southern woods.  A small break in the "+
	"trees allows entrance into those dark woods.");
  set("night long","The moon's light is almost completely consumed "+
	"by the densely packed trees.  The forest is "+
	"very quiet here...as you look around, you fail to find "+
	"any signs of wildlife.  To the south, the trees begin to "+
	"change slightly...twisting, almost as if they are wracked "+
	"with pain.  An unsettling, ominous presence seems to "+
	"radiate from the southern woods.  A small break in the "+
	"trees allows entrance into those dark woods.");
  set_smell("default","The crisp, fresh scent of pine fills the air.");
  set_listen("default","The forest seems unusually quiet.");
  set_items(
    ([
    ({"tree","trees","pine","oak"}):"Huge, sprawling oak trees fight "+
        "for space amongst the tall pine trees."
    ]) );
}

void reset()
{
  ::reset();
  if(base_name(TO) == "/d/tharis/conforest/includes/tharisedge")
	return;
  if(!present("monster")) 
  {
    if(!random(5))
       call_out("loader",0,TO);
   }
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
