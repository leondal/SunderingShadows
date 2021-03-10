inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("shadow necromancy");
    set_spell_level(([ "mage" : 4, "innate":4]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow necromancy on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of a necromancy mage spell of 3rd level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage shadow necromancy on vampiric touch on goblin>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "necromancy";
}
