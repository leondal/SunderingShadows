#include <std.h>
inherit "/std/comp_vend.c";

void create(){
    ::create();
    set_name("Shihab");
    set_id(({"shihab","writer","bard"}));
    set_short("Shihab, an aspiring writer");
    set_long("Shihab is a relatively short, swarthy man with the olive complexion and narrow eyes common to citizens of "
"the Tsarven empire.  His beard and moustache are impeccably tended, the former meeting at a pointed tip beneath his "
"chin.  His dark eyes betray a sharp wit, while his softness of frame and hands suggests a life unaccustomed to hard "
"labor.\n"+
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
    set_gender("male");
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
