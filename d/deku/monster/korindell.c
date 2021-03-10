#include <std.h>
inherit TOWNSMAN;
void create() {
    ::create();
    set_nwp("healing", 10);
    set_name("Korindell");
    set_id( ({ "korindell", "healer", "man"}) );
    set_short("%^RESET%^%^CYAN%^Korindell, %^WHITE%^healer%^CYAN%^ of Deku");
    set_long("%^RESET%^The old man before you stands proudly at "+
    "approximately six feet.  His body, though obviously once "+
    "stout, has grown stooped and it is with a great deal of "+
    "visible agony that he now serves verbobone as the town "+
    "healer.  His %^GREEN%^deep green%^RESET%^ eyes reflect "+
    "an almost eager youthful life from somewhere within him, "+
    "perhaps his only visible feature that hints at youth.  "+
    "His hair is short and now %^BOLD%^%^WHITE%^shines%^RESET%^ "+
    "an almost pure white, matching the thick beard that grows "+
    "out from his chin and lower jawline.  His flesh is wrinkled "+
    "but appears strangely healthy and you believe his "+
    "reputation for being a marvelous healer is well earned.");
    set("aggressive",0);
    set_alignment(5);
    set_race("human");
    add_money("gold", random(20));
    set_hd(19,3);
    set_stats("strength", 17);
    set_stats("intelligence", 14);
    set_stats("wisdom", 14);
    set_stats("dexterity", 18);
    set_stats("constitution", 15);
    set_max_hp(149);
    set_exp(query_max_hp() * 5);
    set_hp(149);
    set_property("always interact",1);
    set_nwp("healing",10);
}


