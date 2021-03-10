#include "melnmarn.h"
#include "dir.h"
inherit "/std/vendor";

create() {
   ::create();
   set_name("Pendaxin");
   set_id( ({ "pendaxin", "clerk", "shop keeper", "shopkeeper"}) );
   set_short("Pendaxin, the clerk of Shadow's General Store");
   set("aggressive", 0);
   set_level(19);
   set_long("He buys and sells goods for adventuring.\n"+
	"<help shop> will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
// moved the storage rooms to a special dir *Styx* 12/31/03, last change 5/17/03
   set_storage_room("/d/shadow/storage/gs_storage");
   set_property("no attack", 1);
   set_hd(19,3);
    set_exp(10);
        set_property("generic db", 1);
//   set_items_allowed("misc");
   set_max_hp(query_hp());
}


