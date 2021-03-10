#include <std.h>
inherit VENDOR;

void create()
{
   ::create();
   set_name("Jerat");
   set_short("Jerat, a jewelry vendor");
   set_id(({"Jerat","jewelry vendor","vendor","jerat"}));
   set_long("Jerat is a rather short man with a mop of blonde curls"+
   " on his head. His blue eyes squint carefully at things and he"+
   " wears a jeweler's lense over one ear that he can quickly access"+
   " to appraise any item you might bring in. He is known for his"+
   " excellent and durable work, and some say that he was at one time"+
   " apprenticed to a dwarven craftsman.");
   set_race("human");
   set_gender("male");
   set_hd(10,5);
	set_max_hp(50+random(25));
	set_hp(query_max_hp());
	set_alignment(1);
	set_overall_ac(5);
	set_level(10);
	set_exp(10);
	set_property("swarm",1);
   remove_std_db();
   remove_dbs(({"tailor"}));
   remove_random_act_dbs(({"tailorrandom"}));
   set_items_allowed("clothing");
   set_storage_room("/d/dagger/Daggerdale/shops/jewelry.c");
    set_nwp("tailor",0);
    set_nwp("jewelling",20);
	set("aggressive",0);
}
