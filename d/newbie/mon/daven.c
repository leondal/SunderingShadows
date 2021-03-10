#include <std.h>
#include "../newbie.h"
inherit VENDOR;

void create() {
	::create();
	set_name("Daven");
	set_short("Daven, weapons smith of the Laughing Blade");
	set_id(({"Daven","shop keeper","shopkeeper","daven","smith","weapons smith"}));
	set_long(
	"Daven is on the short side for a human, barely clearing five feet. He is very"+
	" muscular, his arms are twice the size of that of a normal man at least! His"+
	" brown hair is kept pulled back in a pony tail so it doesn't get in his way"+
	" while he's working. There're soot stains on his clothes and face, but he"+
	" seems very caught up in his work. His twinkling blue eyes smile at you as"+
	" he glances up from sharpening a sword. He would be more than happy to show"+
	" you anything in the store before you make up your mind on what to buy."
	);
	set_race("human");
	set_gender("male");
	set_alignment(2);
	set_hd(19,4);
	set_items_allowed("weapon");
    set_nwp("weaponsmithing",4);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_storage_room(ROOMS"special/weapon_storage");
   remove_std_db();
        set_db("weapons");
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}
