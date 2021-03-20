inherit "/cmds/spells/s/_shadow_evocation";

void create()
{
    ::create();
    set_spell_name("shades");
    set_spell_level(([ "mage" : 9, "oracle" : 9, "cleric" : 9 ]));
    set_mystery("shadow");
    set_domains("darkness");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS shades on SPELL_NAME [on SPELL_ARGS]");
    set_description("You tap energy from the Plane of Shadow to cast a quasi-real, illusory version of a conjuration mage spell of 8th level or lower.

%^BOLD%^%^RED%^E.G.%^RESET%^ <cast mage shades on seamantle>");
    set_arg_needed(1);
}

string shadow_school()
{
    return "conjuration_summoning";
}
