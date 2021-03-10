#include <std.h>
#include "../gantioch.h"

inherit VENDOR;

create() {
        ::create();
        set_race("human");
        set_gender("male");
        set_name("gorge");
        set_short("Gorge, the Merchant");
        set_id(({"gorge","merchant","human"}));
        set_long(
           "%^BOLD%^%^WHITE%^Gorge is a simply dressed man, with a simple"+
           " silver ring on his finger. He stands confidently behind his counter,"+
           " looking out over everyone as they enter. He has long blonde hair"+
           " which goes part way down his back.");
        set_alignment(8);
        set_hd(19,5);
        set_languages( ({ "wizish" }) );
        command("speak wizish");
        set_items_allowed("misc");
        set_max_hp(200);
        set_property("swarm",0);
        set_hp(200);
        set_exp(10);
        set_storage_room(EXTROOM+"merch_storage");
        remove_std_db();
        set_db("miscvendors");
}
