#include <std.h>
#include "/d/guilds/pack/short.h"
inherit "/std/vendor";


create() {
   ::create();
set_name("strife");
   set_id( ({ "strife", "clerk"}) );
   set_short("%^RED%^Strife the Store Owner");
   set("aggressive", 0);
   set_level(11);
  set_long(
@SEETH

SEETH
);
   set_languages( ({ "common" }) );
   set_gender("male");
  set_alignment(9);
  set_race("human");
   set_body_type("human");
  set_storage_room(HALL "storage1");
 set_property("no attack", 1);
   set_hd(19,3);
   set_items_allowed("all");
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(200));
   set_max_mp(query_mp());
}



