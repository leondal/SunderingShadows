//Octothorpe (6/4/16)
//Shadow, Flugar

#include <std.h>
#include "../defs.h"

inherit VENDOR;

void create()
{
   ::create();
   set_name("Flugar");
   set_id(({
      "flugar",
      "clerk",
      "shop keeper",
      "shopkeeper"
   }));
   set_short("Flugar, the shopkeeper of Flugar's Armory");
   set("aggressive",0);
   set_level(19);
   set_long("%^ORANGE%^Flugar is an older man but still heavily "+
      "muscled, no doubt from years of blacksmith work hammering "+
      "out the metals for the armor he sells. Nowadays he has "+
      "apprentices doing the hard work so he has more time to "+
      "answer questions and advise young adventurers. He still "+
      "usually wears a blacksmith apron over his woolen shirt and "+
      "heavy breeches. The wrinkles in his forehead deepen when he "+
      "smiles and he seems to like giving advice about armor and "+
      "talking about some of the surrounding area.");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   set_body_type("human");
   set_storage_room(STOR"armor_storage");
   set_property("no attack",1);
   set_hd(19,3);
   set_items_allowed("armor");
   set_max_hp(query_hp());
   set_exp(20);
}