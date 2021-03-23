inherit "/cmds/spells/c/_clairvoyance";

int clairvoyance_delay()
{
    return 0;
}

void create()
{
    ::create();
    set_spell_name("vision");
    set_spell_level(([ "mage":7, "cleric":7, "druid" : 7 ]));
    set_discipline("divination");
    set_mystery(({"ancestor", "lore"}));
    set_domains(({}));
    set_syntax("cast CLASS vision on TARGET");
    set_description("This spell functions exactly like clairvoyance, except it is harder to block and has no use delay.");
    set_silent_casting(1);
}
