#include <std.h>
inherit VENDOR;
create() {
   ::create();
   set_name("thrach");
   set_id( ({ "thrach","Thrach", "clerk", "shop keeper", "shopkeeper", "lowscar", "thrach lowscar", "human", "wererat"}) );
   set("aggressive", 0);
   set_acquired_template("wererat");
   set_short("%^RESET%^%^MAGENTA%^Thrach Tailscar, underpaths caravaneer");
   set_long("This crooked human wears leather armor. He sells and buys various goods off his gnarw.

%^BOLD%^<help shop>%^RESET%^ will get you a list of shop commands.\n");
   set_gender("male");
   set_alignment(4);
   set_race("human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_storage_room("/d/shadow/ratpaths/storage/trach_storage");
   remove_std_db();
}
