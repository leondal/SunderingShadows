#include <std.h>

inherit "/std/identifier";

void create()
{
    ::create();
    set_name("leepuringa");
    set_id(({"leepuringa", "leepuringa","wandering","wizard","mage","wandering wizard",}));
    set_short("%^RESET%^%^MAGENTA%^Leepuringa, %^CYAN%^Wandering %^WHITE%^Wizard%^RESET%^");
    set_long("Leepuringa is one of the wizards that the city of Shadow has recently "+
             "hired. She is perhaps middle aged, but it is "+
             "difficult to tell, her skin is mostly smooth, but wrinkled around her mouth, "+
             "which is almost always smiling. Her eyes are a very deep piercing "+
             "green. She gives off a mixed aura, as if she is kind but also not very trusting "+
             "of anyone. The rest of her body is mostly cloaked with a gray robe with "+
             "the insignia of Shadow, three coins of gold, silver and copper.");
    set_race("human");
    set_gender("female");

    set_stats("intelligence",22);
    set_stats("strength",14);
    set_stats("charisma",22);
    set_stats("wisdom",15);
    set_stats("dexterity",10);
    set_stats("constitution",18);
    set_hp(555+random(76));
    set_max_hp(query_hp());
    set_class("mage");
    set_mlevel("mage",30);
    set_guild_level("mage",30);
    set_spells(({"lightning bolt","burning hands","scorcher","magic missile","powerword stun"}));
    set_spell_chance(60);
    set_id_uses(20);
    set_detect_uses(20);
    set_speed(60);
    set_highmod(4);
    /* set_nogo(({"/d/deku/forest/dforest15-5", "/d/deku/forest/dforest23-5", "/d/deku/hhouse/rooms/cy1", "/d/deku/forest/dforest21-2"})); */
}
