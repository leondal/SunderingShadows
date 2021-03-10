#include <std.h>
inherit "/std/comp_vend";

void create(){
    ::create();
    set_name("eva");
    set_id(({"eva","bardess","bard"}));
    set_short("Eva, the bardess");
    set_long("Eva is only a young woman, her face the very picture of contentment.  She can often be seen with a small "
"book in hand, scribbling notes for her next song or performance as she wanders about the small shop.  Her mouse-brown "
"hair is as unassuming as her garb, cheerful but simple in a light cotton dress and a woolen shawl.\n"+
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
    set_property("always interact",1);
    set_gender("female");
    set_alignment(5);
    set_race("human");
    set_class("bard");
    set_guild_level("bard",10);
    set_hd(10,6);
    set_max_hp(200);
    set_hp(200);
    set_exp(10);
    set_spell_chance(100);
    set_property("no attack",1);
    set_spells(({"sound burst","sound burst","shout","shout","monster summoning iii",}));
    set_shop_type("bard");
    set_components(40);
}
