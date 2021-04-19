inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("greater shadow evocation");
    set_spell_level(([ "mage" : 8, "oracle" : 8 ]));
    set_mystery(({"darkness","shadow"}));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS greater shadow evocation on SPELL_NAME [on SPELL_ARGS]");
    set_description("You create an illusory version of an evocation spell of 7th level or lower. The source of the illusion can differ based on the caster.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage greater shadow evocation on chain lightning on goblin>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "invocation_evocation";
}
