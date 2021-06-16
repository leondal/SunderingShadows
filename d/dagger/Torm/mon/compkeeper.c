#include <std.h>
inherit VENDOR;

void create() {
    ::create();
    set_name("Alvero");
    set_id(({"shopkeeper","alvero"}));
    set_short("Alvero, the alchemist");
    set("aggressive", 0);
    set_level(19);
    set_long(
        "  Alvero looks you back over and nods."
        "  She has long black hair that is kept in a neat braid that trails down past her waist.  Her eyes are a piercing shade of %^BOLD%^ice blue%^RESET%^%^CYAN%^ and she seems to regard you carefully.  She wears %^RESET%^gray robes%^CYAN%^ that are drawn in with a %^WHITE%^%^BOLD%^silver%^RESET%^%^CYAN%^ belt."
        "  She stands behind a counter piled high with the things mages use to draw on their magics."
        "  \n<help shop> will show you a list of shop commands."
    );
    set_gender("female");
    set_alignment(5);
    set("race", "human");
    set_hd(19,1);
    set_exp(20);
    set_body_type("human");
    set_property("no bump", 1);
    set_storage_room("/d/dagger/Torm/mon/compkeeper_storage.c");
    set_items_allowed("misc");
    set_mymaxvalue(1);
}

