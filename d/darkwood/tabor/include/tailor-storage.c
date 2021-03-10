#include <std.h>
#include "tabor.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Shahryar's Clothier Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMDIR+"lot-tailor"]));
}

void reset()
{
   ::reset();
 if(!present("perfume")){
   switch(random(3)){
      case 0:  new(OBJDIR+"blushing_laughter")->move(TO);
               break;
      case 1:  new(OBJDIR+"joyful_heart")->move(TO);
               break;
      case 2:  new(OBJDIR+"blushing_laughter")->move(TO);
               new(OBJDIR+"joyful_heart")->move(TO);
               break;
   }
 }
 if(!present("cologne")){
   switch(random(3)){
      case 0:  new(OBJDIR+"spice_of_the_soul")->move(TO);
               break;
      case 1:  new(OBJDIR+"enraptured_gaze")->move(TO);
               break;
      case 2:  new(OBJDIR+"spice_of_the_soul")->move(TO);
               new(OBJDIR+"enraptured_gaze")->move(TO);
               break;
   }
 }
 if(!present("golden link belt"))
   if(!random(2)) new(OBJDIR+"belt")->move(TO);
 if(!present("choli"))
   new(OBJDIR+"c_choli")->move(TO);
 if(!present("choli 2"))
   new(OBJDIR+"c_choli")->move(TO);
 if(!present("ghagra"))
   new(OBJDIR+"c_ghagra")->move(TO);
 if(!present("kameez"))
   new(OBJDIR+"c_kameez")->move(TO);
 if(!present("leggings"))
   new(OBJDIR+"c_leggings")->move(TO);
 if(!present("leggings 2"))
   new(OBJDIR+"c_leggings")->move(TO);
 if(!present("pantaloons"))
   new(OBJDIR+"c_pantaloons")->move(TO);
 if(!present("pantaloons 2"))
   new(OBJDIR+"c_pantaloons")->move(TO);
 if(!present("robe"))
   new(OBJDIR+"c_robe")->move(TO);
 if(!present("salwar"))
   new(OBJDIR+"c_salwar")->move(TO);
 if(!present("sari"))
   new(OBJDIR+"c_sari")->move(TO);
 if(!present("sash"))
   new(OBJDIR+"c_sash")->move(TO);
 if(!present("sash 2"))
   new(OBJDIR+"c_sash")->move(TO);
 if(!present("turban"))
   new(OBJDIR+"c_turban")->move(TO);
 if(!present("vest"))
   new(OBJDIR+"c_vest")->move(TO);
 if(!present("vest 2"))
   new(OBJDIR+"c_vest")->move(TO);
}
