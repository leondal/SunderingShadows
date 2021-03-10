#include "/d/shadow/room/pepitom/Pepitom.h"
#include <dirs.h>

inherit "/std/vendor";

int count;

void create() {
   ::create();
   set_name("Stella");
   set_id( ({ "stella", "clerk", "shop keeper", "shopkeeper"}) );
    set_short("Stella, the clerk of Shadow's Weapon Store");
   set("aggressive", 0);
   set_level(19);
   set_long("She buys and sells weapons.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(2);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room(ROOMS+"weapon_storage");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   set_items_allowed("weapon");
   count = 0;

}

int test_heart(){ return 1;}

void heart_beat(){

	::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if((hour(time()) >= 17) || (hour(time()) <= 5) && (base_name(ETO) != ROOMS+"weaponhome.c")) {
	go_home();
   }
   if((hour(time()) >= 6) && (hour(time()) <=16) && (base_name(ETO) != ROOMS+"weapon.c")) {
goto_work();
   }
}

void go_home()
{
	string thisroom;
	
	thisroom = base_name(ETO);
	switch (thisroom)
    {
		case ROOM+"weapon.c":
			force_me("east");
            break;
		case ROOM+"wroad11.c":
			force_me("north");
            break;
		case ROOM+"wroad12.c":
			force_me("north");
            break;
		case ROOM+"raod13.c":
            force_me("east");
            break;
		default:
			move(ROOMS+"weaponhome.c");
            break;
    }
}



