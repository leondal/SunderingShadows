#include <std.h>
#include "../gantioch.h"

inherit VENDOR;

create() {
        ::create();
        set_race("human");
        set_gender("male");
        set_name("faris");
        set_short("Faris, the Merchant");
        set_id(({"faris","merchant","human"}));
        set_long(
           "%^BOLD%^%^WHITE%^Faris is a well-dressed man, adorned in fine"+
           " silks and jewelry. He stands confidently behind his counter,"+
           " looking out over everyone as they enter. He has short dark hair"+
           " which has been spiked. His calm %^BOLD%^%^BLUE%^blue eyes%^BOLD%^%^WHITE%^"+
           " have a peaceful demeanor about them.");
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
