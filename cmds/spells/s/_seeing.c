inherit "/cmds/spells/c/_clairvoyance";

int clairvoyance_delay()
{
    return 60;
}

void create()
{
    ::create();
    set_spell_name("seeing");
    set_spell_level(([ "psion" : 2 ]));
    set_discipline("clairsentience");
    set_domains(({}));
    set_syntax("cast CLASS seeing on TARGET");
    set_description("This power is the psionic version of clairvoyance.");
    set_silent_casting(1);
}
