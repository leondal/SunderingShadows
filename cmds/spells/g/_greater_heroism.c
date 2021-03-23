inherit "/cmds/spells/h/_heroism";

void create() {
    ::create();
    set_spell_name("greater heroism");
    set_spell_level(([ "mage" : 6, "bard" : 5, "oracle" : 6, "magus" : 5, "cleric" : 6 ]));
    set_domains("good");
    set_mystery("ancestor");
    set_syntax("cast CLASS greater heroism [on TARGET]");
    set_damage_desc("+4 to attack bonus, saving throws, skills");
    set_description("This spell allows the caster to draw upon their personal presence and charm, granting them or an ally a bonus to morale on attacks, saves and core skills. It does not stack with other morale-boosting spells, such as good hope. This spell won't work together with resistance spell.");
    set_target_required(1);
}

int query_heroism_bonus()
{
    return 4;
}
