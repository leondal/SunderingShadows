#include <std.h>
#include <magic.h>
inherit SPELL;

object *mons = ({});

void create() {
    ::create();
    set_spell_name("night swarm");
    set_spell_level(([ "innate" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS night swarm");
    set_description("This spell creates eight bats that will guard the caster blindly.");
	set_helpful_spell(1);
}

string query_casting_string() {
    return "%^BOLD%^%^RED%^"+caster->query_cap_name()+" waves "+caster->QP+" hands, creating high-pitched noise.";
}

int preSpell() {
    if (present(caster->query_name()+"batswarm",place)) {
        tell_object(caster,"You can't summon multiple sets of guardians.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object ob;
    int i;
    tell_room(place,"%^RED%^A swarm of bats flies into the area and surrounds "+caster->QCN+".%^RESET%^");
    for (i=0;i<prof/12;i++) {
        ob = new("/d/magic/mon/vbat");
        ob->move(place);
        caster->add_protector(ob);
        ob->set_property("spelled", ({TO}) );
        ob->set_property("spell_creature", TO);
        ob->set_property("spell", TO);
        ob->set_property("minion", caster);
        ob->set_damage_bonus(clevel/5);
        ob->set_attack_bonus(clevel/5);
        ob->set_attacks_num(1);
        ob->set_exp(0);
        ob->add_id("summoned monster");
        ob->add_id(caster->query_name()+"batswarm");
        caster->add_follower(ob);
        mons += ({ob});
    }
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;
    for (i=0;i<sizeof(mons);i++) {
        if (objectp(mons[i]))
        {
            if(objectp(caster))
            {
                caster->remove_protector(mons[i]);
            }
            mons[i]->die();
        }
    }
    removeSpellFromCaster();
    ::dest_effect();
    if(objectp(TO))
    {
	   TO->move("/d/shadowgate/void");
         TO->remove();
    }
}
