#include <std.h>
#include "../tomb.h"

inherit VENDOR;

create()
{
   ::create();
   set_name("kapriz");
   set_id( ({ "kapriz" ,"clerk", "shop keeper", "shopkeeper"}) );
   set_short("%^BOLD%^%^BLUE%^Kapriz,%^BLACK%^ shop keeper%^RESET%^");
   set("aggressive", 0);
   set_level(20);
   set_class("fighter");
   set_property("undead",1);
   set_long("This human seems to be trapped inside own head, he stands still as a statue, moving and speaking only when it is required. His eyes are white empty and it is unclear whether he is alive or not. He wears simple black robes.
%^BOLD%^<help shop>%^RESET%^ will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(3);
   set_race("human");
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(20,6);
   set_max_hp(query_hp());
   set_storage_room(STORAGE+"/trader_storage");
   remove_std_db();
}
