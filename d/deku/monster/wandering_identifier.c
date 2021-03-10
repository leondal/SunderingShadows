#include <std.h>

inherit "/std/identifier";

void create()
{
    ::create();
    switch(random(2))
    {
        case 0:
            set_name("zynia");
            set_id(({"zynia", "Zynia","wandering","wizard","mage","wandering wizard", "verbobone wizard"}));
            set_short("Zynia, Verbobone Wizard");
            set_long("Zynia is one of the wizards that the city of Verbobone has recently "+
            "hired to keep an eye out on the city after the recent metamorphosis of the "+
            "haunted house that lies at the north end. She is perhaps middle aged, but it is "+
            "difficult to tell, her skin is mostly smooth, but wrinkled around her mouth, "+
            "which is almost always smiling. Her eyes are a very deep piercing "+
            "green. She gives off a mixed aura, as if she is kind but also not very trusting "+
            "of anyone. The rest of her body is mostly cloaked with a deep violet robe with "+
            "a strange insignia in the shape of three orbs circling what could be an altar.");
            set_race("half-elf");
            set_gender("female");
            break;
        case 1:
            set_name("barlown");
            set_id(({"barlown", "barlown","wandering","wizard","mage","wandering wizard", "verbobone wizard"}));
            set_short("Barlown, Verbobone Wizard");
            set_long("Barlown is one of the wizards that the city of Verbobone has recently "+
            "hired to keep an eye out on the city after the recent metamorphosis of the "+
            "haunted house that lies at the north end. He looks quite young and there is an "+
            "aura of eagerness about him. His eyes are dark, almost black, and are very difficult "+
            "to read. He offers a half-hearted smile, as if his mind is elsewhere, to any who "+
            "acknowledge him. The rest of his body is mostly cloaked with a deep brown robe with "+
            "a strange insignia in the shape of three orbs circling what could be an altar.");
            set_race("half-orc");
            set_gender("male");
            break;
    }       
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
    set_nogo(({"/d/deku/forest/dforest15-5", "/d/deku/forest/dforest23-5", "/d/deku/hhouse/rooms/cy1", "/d/deku/forest/dforest21-2"}));
}
