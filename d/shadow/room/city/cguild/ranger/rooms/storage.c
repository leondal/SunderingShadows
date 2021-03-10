#include "/d/shadow/room/city/cguild/ranger/ranger.h"
#include <daemons.h>
inherit ROOM;
 
void create() {
  ::create();
   set_property("no teleport",1);
   set_property("indoors",1);
   set_property("light",2);
  set_short("Ranger Storage Room");
   set_long("You should not be here. If you are found here you will die very painfully, I suggest leaving immediately.");
   set_exits((["up":RROOM"shop"]));
}
 
void reset() 
{
	int x, val;
	object TrapOb;
	::reset();
   	if(!present("shortbow")) new("/d/common/obj/lrweapon/shortbow")->move(TO);
   	if(!present("long bow")) new("/d/common/obj/lrweapon/longbow")->move(TO);
   	if(!present("sleeve")) new("/d/common/obj/sheath/sheath_lgstaff")->move(TO);
// bye tripwires! New feats taking over! N, 4/15
/*        if(!present("trip wire"))
	{
      	new(ROBJ+"tripwire")->move(TO);
      	new(ROBJ+"tripwire")->move(TO);
        } */
	if(!present("playersettabletrapkit"))
	{
		x = 2 + random(2);
		while(x)
		{
			if(!random(3)) 
			{
				TrapOb = TRAP_D->get_trap_object("mid", "random");
				val = 750 + random(251);
			}
			else 
			{
				TrapOb = TRAP_D->get_trap_object("low", "random");
				val = 400 + random(201);
			}
			if(objectp(TrapOb)) 
			{
				TrapOb->move(TO);
				TrapOb->set_value(val);
			}
			x--;
			continue;
		}
	}
   	if(!present("flint")) new("/d/common/obj/misc/flint")->move(TO);
   	if(!present("skinning kit") && random(2)) 
	{
		new("/d/common/obj/misc/tools/skinningkit")->move(TO);
	}
   	if(!present("bowyer kit") && random(2)) 
	{
		new("/d/common/obj/misc/tools/bowyerkit")->move(TO);
	}
   	if(!present("skinning knife")) 
	{
	     	switch(random(5)) 
		{
       		case 0: new("/d/common/obj/misc/tools/skinningknife")->move(TO); break;
      		 case 1: new("/d/common/obj/misc/tools/skinningknife2")->move(TO); break;
      		 case 2: new("/d/common/obj/misc/tools/skinningknife3")->move(TO); break;
       		case 3: new("/d/common/obj/misc/tools/skinningknife4")->move(TO); break;
       		case 4: new("/d/common/obj/misc/tools/skinningknife5")->move(TO); break;
     		}
   	}
   	if(!present("waterskin")) new("/d/antioch/antioch2/obj/waterskin")->move(TO);
   	if(!present("mixed nuts") && !random(3)) 
	{
		new("/d/antioch/antioch2/obj/nuts")->move(TO);
	}
   	if(!present("dried fruits") && !random(3)) 
	{
		new("/d/antioch/antioch2/obj/dried_fruits")->move(TO);
	}
   	if(!present("standard rations") && !random(2)) 
	{
		new("/d/antioch/antioch2/obj/standard_rations")->move(TO);
	}

   	if(!present("leather")) new("/d/common/obj/armour/leather")->move(TO);
   	if(!present("studded") && random(2)) new("/d/common/obj/armour/studded")->move(TO);
   	if(!present("hide")) new("/d/common/obj/armour/hide")->move(TO);
   	if(!present("leather coif") && random(2)) 
	{
		new("/d/common/obj/armour/coif_leather")->move(TO);
	}
   	if(!present("buckler") && random(4)) new("/d/common/obj/armour/buckler")->move(TO);
   	if(!present("tunic") && random(2)) new("/d/antioch/antioch2/obj/tunic")->move(TO);
   	if(!present("breeches") && random(2)) new("/d/antioch/antioch2/obj/breeches")->move(TO);
   	if(!present("deerskin shirt")) new("/d/antioch/antioch2/obj/deerskin_shirt")->move(TO);
   	if(!present("deerskin boots")) new("/d/antioch/antioch2/obj/deerskin_boots")->move(TO);
   	if(!present("leather vest")) new("/d/antioch/antioch2/obj/vest")->move(TO);
   	if(!present("leather bodice")) new("/d/antioch/antioch2/obj/leather_bodice")->move(TO);
        if(!present("partitioned quiver")) {
          new("/d/common/obj/lrweapon/limitlessquiver")->move(TO);
          new("/d/common/obj/lrweapon/limitlessquiver")->move(TO);
        }
}
