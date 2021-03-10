#include <std.h>
#include "../../antioch.h"
inherit ROOM;

void create()
{
	::create();
	set_property("indoors",1);
	set_property("light",2);
	set_short("Mina's Tailor Storage Room");
	set_long("Various items are stored here.");
	set_property("no teleport",1);
	set_exits((["down" : ROOMS+"tailor"]));
}

void reset()
{
   object obj;
	::reset();
if(!present("robe"))
 new(OBJ+"robe")->move(TO);
if(!present("r_dress"))
 new(OBJ+"r_dress")->move(TO);
if(!present("r_skirt"))
 new(OBJ+"r_skirt")->move(TO);
if(!present("r_top"))
 new(OBJ+"r_top")->move(TO);
if(!present("r_shirt"))
 new(OBJ+"r_shirt")->move(TO);
if(!present("r_tunic"))
 new(OBJ+"r_tunic")->move(TO);
if(!present("r_pants"))
 new(OBJ+"r_pants")->move(TO);
if(!present("r_scarf"))
 new(OBJ+"r_scarf")->move(TO);
if(!present("r_hchief"))
 new(OBJ+"r_hchief")->move(TO);
if(!present("r_shorts"))
 new(OBJ+"r_shorts")->move(TO);
if(!present("satin gloves"))
 new(OBJ+"satin_gloves")->move(TO);
if(!present("satin gown"))
 new(OBJ+"satin_gown")->move(TO);
if(!present("summer dress"))
 new(OBJ+"summer_dress")->move(TO);
if(!present("plain tunic"))
 new(OBJ+"cotton_tunic")->move(TO);
if(!present("workman's pants"))
 new(OBJ+"work_pants")->move(TO);
if(!present("colorful scarf"))
 new(OBJ+"colorful_scarf")->move(TO);
if(!present("colorful skirt"))
 new(OBJ+"colorful_skirt")->move(TO);
if(!present("waterproof cloak") && !random(2)){
  obj = new("/d/attaya/seneca/obj/clothing/plcloak");
   obj->move(TO);
   obj->add_id("mina_clothing");
}
if(!present("grey cloak")){
  obj = new(OBJ+"grey_cloak");
   obj->move(TO);
   obj->add_id("mina_clothing");
}
}
