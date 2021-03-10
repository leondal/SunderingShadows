inherit "/d/common/obj/weapon/club_lg";

void create()
{
  	::create();
  	set_id(({"club","large club"}));
  	set_name("club");
  	set_short("A large club");
  	set_long("This club looks more like someone stripped the "+
	"bark from a tree than a crafted weapon.  Thinner "+
	"towards the handle end, the club is nearly six feet "+
	"long.  A large knot in the wood looks like it could "+
	"deal a nasty blow.");
   	/*set_weight(8);
   	set_size(3);
   	set("value",3);
   	set_wc(1,8);
   	set_large_wc(1,6);
  	set_type("bludgeoning");
  	set_weapon_speed(9);*/
}
