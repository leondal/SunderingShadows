#include <std.h>;
#include "../defs.h"
#include "/d/common/common.h"
inherit ROOM;

void create() {
   ::create();
   set_name("Armor store storage");
   set_short("Armor store storage");
   set_long("Storage room for Darol'dralych armor store.");
   set_property("no teleport",1);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
}

void reset() {
   ::reset();
   if(!present("medium sheath")) new(CSHEATH"sheath_medium")->move(TO);
   if(!present("large sheath") && random(2)) new(CSHEATH"sheath_large")->move(TO);
   if(!present("small sheath")) new(CSHEATH"sheath_small")->move(TO);
   if(!present("small sheath 2") && random(2)) new(CSHEATH"sheath_small")->move(TO);
   if(!present("medium holster") && !random(2)) new(CSHEATH"sheath_mbludgeon")->move(TO);
   if(!present("large holster") && !random(3)) new(CSHEATH"sheath_lgbludgeon")->move(TO);
   if(!present("medium sleeve") && !random(2)) new(CSHEATH"sheath_mstaff")->move(TO);
   if(!present("large sleeve") && !random(3)) new(CSHEATH"sheath_lgstaff")->move(TO);
   if(!present("shield strap") && !random(2)) new(CSHEATH"shieldstrap")->move(TO);
   if(!present("dleather")) new(OBJ"armor/leather")->move(TO);
   if(!present("dleather 2")) new(OBJ"armor/leather")->move(TO);
   if(!present("studded")) new(OBJ"armor/studded")->move(TO);
   if(!present("hide") && random(2)) new(OBJ"armor/hide")->move(TO);
   if(!present("mesh")) new(OBJ"armor/mesh")->move(TO);
   if(!present("breastplate") && random(3)) new(OBJ"armor/breastplate")->move(TO);
   if(!present("fullplate")) new(OBJ"armor/fullplate")->move(TO);
   if(!present("helm") && random(2)) new(OBJ"armor/helm")->move(TO);
   if(!present("shield") && random(2)) new(OBJ"armor/shield")->move(TO);
   if(!present("buckler")) new(OBJ"armor/buckler")->move(TO);
   if(!present("dark bracers")) new(OBJ"armor/bracers2")->move(TO);
   if(!present("blackened bracers") && random(2)) new(OBJ"armor/bracers1")->move(TO);
   if(!present("bandoleer")) new("/d/common/obj/misc/bandoleer")->move(TO);
   if(!present("leather pouch")) new(CMISC"pouch")->move(TO);
}
