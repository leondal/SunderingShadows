#include <std.h>;
#include "../defs.h"
#include "/d/common/common.h"
inherit ROOM;

object ob;

void create() {
   ::create();
   set_name("Muuldaan smith storage");
   set_short("Muuldaan smith storage");
   set_long("Storage room for Muuldaan's smith.");
   set_property("no teleport",1);
}

void reset() {
   ::reset();
   if(!present("dagger")) new(CWEAP"dagger")->move(TO); 
   if(!present("shortsword")) new(CWEAP"shortsword")->move(TO); 
   if(!present("halberd")) new(CWEAP"halberd")->move(TO);
   if(!present("large club")) new(CWEAP"club_lg")->move(TO);
   if(!present("hammer") && !random(3)) new(CWEAP"warhammer")->move(TO); 
   if(!present("scourge") && !random(5)) new(CWEAP"scourge")->move(TO); 
   if(!present("spear") && !random(4)) new(CWEAP"spear_sm")->move(TO); 
   if(!present("bastard") && !random(5)) new(CWEAP"giant_bastard")->move(TO); 

   if(!present("weapsheath")) new(CSHEATH"sheath_randomizer")->move(TO);
   if(!present("weapsheath 2")) new(CSHEATH"sheath_randomizer")->move(TO);
   if(!present("pouch")) new(CMISC"pouch")->move(TO);
   if(!present("buckler")) new(CARMOR"buckler")->move(TO);
   if(!present("mshield") && random(4)) new(CARMOR"mshield")->move(TO);
   if(!present("leather")) {
     ob = new(CARMOR"leather");
     ob->move(TO);
     ob->set_size(random(3)+1);
   }
   if(!present("hide")) {
     ob = new(CARMOR"hide");
     ob->move(TO);
     ob->set_size(random(3)+1);
   }
   if(!present("studded")) {
     ob = new(CARMOR"studded");
     ob->move(TO);
     ob->set_size(random(3)+1);
   }
   if(!present("banded") && !random(3)) {
     ob = new(CARMOR"banded");
     ob->move(TO);
     ob->set_size(random(2)+2);
   }
   if(!present("breastplate") && !random(2)) {
     ob = new(OBJ"breastplate");
     ob->move(TO);
     ob->set_size(random(2)+2);
   }
   if(!present("robe")) {
     ob = new(CARMOR"robe");
     ob->move(TO);
     ob->set_size(random(2)+2);
   }
   if(!present("robe 2")) {
     ob = new(CARMOR"robe");
     ob->move(TO);
     ob->set_size(random(2)+2);
   }
}
