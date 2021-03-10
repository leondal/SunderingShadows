#include "/d/dagger/tonovi/town/short.h"

inherit "/std/vendor.c";

void create(){
    ::create();
    set_name("Deleanek");
    set_short("Deleanek the clerk");
    set_id( ({ "Deleanek", "deleanek", "Gtonovimon", "clerk"}) );
    set_long(
   "Deleanek is a well-trimmed human of about 35 years of age. He tends the store with a professionally detached, almost cold manner.  He is dressed in relatively fine clothes for this region of Dagger, and his skin is fair and unworn by the wind and harsher elements that adventurers face."
    );
    set_gender("male");
    set_race("human");
    set_hd(10,10);
   set_body_type("human");
    set_exp(5);
    set_alignment(6);
    set_storage_room(STOR "general_storage");
    set_property("no attack", 1);
    set_hp(150);
    set_max_hp(150);
    set_items_allowed("misc");
    add_money("gold", random(500));
}
