inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("spectres");
    set_spell_level(([ "mage" : 9 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS spectres on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of a necromancy mage spell of 8th level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage scpectres on create greater undead>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "necromancy";
}
