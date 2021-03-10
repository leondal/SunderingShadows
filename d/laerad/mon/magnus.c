//Coded by Bane//
#include <std.h>
inherit "/std/vendor";

void create() {
    ::create();
    set_id(({"magnus","shopkeeper","magnus the shopkeeper", "Magnus"}));
    set_name("magnus");
    set_short("Magnus the shopkeeper");
    set_long(
	"Magnus is a very large brutal looking man.  He has a massive beard "+
	"that reaches down past his chest and he stands over 7 feet tall.  "+
	"He stands at his counter waiting for customers to help.  You can "+
	"<help shop> to get a list of the shop commands."
    );
   set_gender("male");
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_alignment(5);
    set_storage_room("/d/laerad/parnelli/asgard/gen_storage");
    set_hd(19,3);
    set_hp(155);
    set("aggressive",0);
    remove_std_db();
    remove_dbs( ({"/d/db/vendor"}) );
}

