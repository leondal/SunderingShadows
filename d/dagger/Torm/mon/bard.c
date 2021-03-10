#include <std.h>
#include "../tormdefs.h"
inherit VENDOR;

void create()
{
   ::create();
   remove_std_db();
   remove_dbs(({"miscvendors"}));
   set_name("Thomas");
   set_id( ({"thomas", "instrument maker", "maker","Thomas","bard", "vendor"}) );
   set_short("Thomas, the instrument maker");
   set_long(
   "Thomas is dressed in a brightly colored silk shirt with a brown"+
   " leather vest and matching trousers. He has sandy blonde hair, a"+
   " dark tan, and charming hazel eyes. He seems like a friendly enough"+
   " sort and is quite handsome. He spends his time making instruments"+
   " for his fellow bards, and in this diverse town he has learned"+
   " how to create some of the more rare and exotic instruments that"+
   " are usually found in distant lands."
   );
   set_property("always interact",1);
   set_race("human");
   set_gender("male");
   set_hd(10,10);
   set_class("bard");
   set_alignment(5);
   add_money("silver",random(100));
   set_storage_room(TSP+"instruments");
   set_property("no attack",1);
   set_items_allowed("misc");
   set_exp(10);
}
