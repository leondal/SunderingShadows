//Octothorpe (6/4/16)
//Shadow, Valchor

#include <std.h>
#include "../defs.h"

inherit VENDOR;

void create()
{
   ::create();
   set_name("Valchor");
   set_id( ({ "valchor", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Valchor, the shopkeeper of Valchor's Weaponsmithy");
   set("aggressive",0);
   set_level(19);
   set_long("%^ORANGE%^Valchor is clearly showing his age but he "+
      "still looks pretty spry. The deep lines in his face and "+
      "friendly smile make him look a little grandfatherly to most "+
      "young adventurers. He seems to enjoy providing a good selection "+
      "of weapons and advice now and then. He generally mucks around "+
      "behind the counter arranging the various weapons and mumbling "+
      "as if to try to remember this or that.");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_storage_room(STOR"weapon_storage");
   set_property("no attack",1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_items_allowed("weapon");
}