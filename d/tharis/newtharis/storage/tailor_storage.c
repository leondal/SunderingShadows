#include <std.h>
#include <objects.h>
#include "../../tharis.h"
inherit ROOM;

void create() {
  ::create();
   set_property("no teleport",1);
    set_properties((["light":1, "indoors":1]));
    set_short("A storage room for the clothery.");
    set_long("Clothes are stored here.\n");
    set_exits( (["up" : ROOMS"thief_tailor"]) );
}

void reset() {
object obj;
::reset();
	if(!present("thief clothesxx")){
	   switch(random(3)){
  	      case 0:  new("/d/tharis/obj/clothing/bodysuit")->move(TO);
	               break;
	      case 1:  new("/d/tharis/obj/clothing/leather_gloves")->move(TO);
	               break;
	      case 2:  new("/d/tharis/obj/clothing/tabi_boots")->move(TO);
	               break;
	   }
	}
	if(!present("thief clothesxx 2") && !random(3)){
	   switch(random(3)){
  	      case 0:  new("/d/tharis/obj/clothing/bodysuit")->move(TO);
	               break;
	      case 1:  new("/d/tharis/obj/clothing/leather_gloves")->move(TO);
	               break;
	      case 2:  new("/d/tharis/obj/clothing/tabi_boots")->move(TO);
	               break;
	   }
	}
	if(!present("studded"))
	   new("/d/common/obj/armour/studded")->move(TO);
	if(!present("buckler"))
	   new("/d/common/obj/armour/buckler")->move(TO);
	if(!present("leather"))
	   new("/d/common/obj/armour/leather")->move(TO);
	if(!present("thief tools"))
         new("/d/common/obj/misc/thief_tools")->move(TO);
	if(!present("rope"))
	   new("/d/common/obj/misc/rope")->move(TO);
	if(!present("potion")){
	   switch(random(7)){
	      case 0:  obj = new("/d/common/obj/potion/cure_poison");
	               obj->set_value(25);
	               break;
	      case 1:  obj = new("/d/tharis/obj/clothing/det_invis");
	               obj->set_value(500);
	               break;
	      case 2:  obj = new("/d/common/obj/potion/hurt");
	               obj->set_value(150);
	               break;
	      case 3:  obj = new("/d/tharis/obj/clothing/invisible");
	               obj->set_value(750);
	               break;
	      case 4:  obj = new("/d/common/obj/potion/paralyze");
	               obj->set_value(150);
	               break;
	      case 5:  obj = new("/d/common/obj/potion/poison");
	               obj->set_value(75);
	               break;
	      case 6:  obj = new("/d/common/obj/potion/weaken");
	               obj->set_value(150);
	               break;
	   }
	   obj->move(TO);
	}
	if(!present("potion 2") && !random(3)){
	   switch(random(7)){
	      case 0:  obj = new("/d/common/obj/potion/cure_poison");
	               obj->set_value(25);
	               break;
	      case 1:  obj = new("/d/tharis/obj/clothing/det_invis");
	               obj->set_value(500);
	               break;
	      case 2:  obj = new("/d/common/obj/potion/hurt");
	               obj->set_value(150);
	               break;
	      case 3:  obj = new("/d/tharis/obj/clothing/invisible");
	               obj->set_value(750);
	               break;
	      case 4:  obj = new("/d/common/obj/potion/paralyze");
	               obj->set_value(150);
	               break;
	      case 5:  obj = new("/d/common/obj/potion/poison");
	               obj->set_value(75);
	               break;
	      case 6:  obj = new("/d/common/obj/potion/weaken");
	               obj->set_value(150);
	               break;
	   }
	   obj->move(TO);
	}
	if(!present("sheath")){
	   new("/d/common/obj/sheath/sheath_small")->move(TO);
	   new("/d/common/obj/sheath/sheath_small")->move(TO);
      }
	if(!present("shirt"))
 	   new("/d/tharis/obj/clothing/shirt")->move(TO);
	if(!present("bandoleer"))
	   new("/d/common/obj/misc/bandoleer")->move(TO);
	if(!present("leather breastplate") && !random(2))
	   new("/d/common/obj/armour/leather_plate")->move(TO);
}
