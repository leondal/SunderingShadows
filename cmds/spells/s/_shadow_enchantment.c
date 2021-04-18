inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("shadow enchantment");
    set_spell_level(([ "mage" : 5, "bard" : 5 ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shadow enchantment on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of an enchantment mage spell of 4th level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage shadow enchantment on haste on friend>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "enchantment_charm";
}
