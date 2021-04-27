inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("greater shadow alteration");
    set_spell_level(([ "mage" : 9]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow alteration on SPELL_NAME [on SPELL_ARGS]");
    set_description("You create an illusory version of an alteration spell of 8th level or lower. The source of the illusion can differ based on the caster.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage greater shadow alteration on haste on friend>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "alteration";
}
