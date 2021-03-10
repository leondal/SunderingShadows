#include <magic.h>
#include <std.h>
#include <spell.h>
inherit SPELL;

object *animated, *monsters, control;
string arg;
int amount;

void create() {
    ::create();
    set_spell_name("unseen servant");
    set_spell_level(([ "mage" : 1,"bard":1,"oracle":1, "warlock":1, "magus" : 1 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS unseen servant");
    set_mystery("ancestor");
    set_description("What could be more annoying that doing things yourself?.. Call to your ancestor to summon one of them to open doors before you, carry your luggage or scratch your back.

To remove servant use %^ORANGE%^<dismiss servant>%^RESET%^
To command servant use %^ORANGE%^<command servant to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
To force lost servant to follow use %^ORANGE%^<command servant to follow>%^RESET%^");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "book of shadows"]));
}

int preSpell(){
   if(caster->query_property("unseen_servant")) {
        tell_object(caster,"%^CYAN%^You are incapable of controling two such summonings.%^RESET%^");
        return 0;
   }
   return 1;
}

string query_cast_string(){
   tell_object(caster,"%^CYAN%^You make a subtle motion to the side with one hand.%^RESET%^");
   tell_room(place,"%^CYAN%^"+caster->QCN+" makes a subtle motion to the side with one hand.%^RESET%^",caster);
   return "display";
}

void spell_effect(int prof){
	if(!objectp(environment(caster)))
    {
		dest_effect();
		return;
	}
	place = environment(caster);
    summon_servant();
}

void summon_servant() {
    object ob, thing;

    tell_object(caster,"%^CYAN%^You barely notice some movement at the edge of you sight. You feel you can <command servant to> perform various actions.%^RESET%^");

    ob=new("/d/magic/mon/unseen_servant.c");
    ob->setup_servant(caster,clevel);

    control = new("/d/magic/obj/holder");
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    control->set_caster(caster);
    control->set_elemental(ob);

    caster->add_follower(ob);

    ob->move(environment(caster));
    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("minion", caster);

    addSpellToCaster();

    caster->set_property("unseen_servant",ob);
    return;
}

void dest_effect() {
    object sword;

    if (objectp(caster)) {
        tell_object(caster,"%^CYAN%^Unseen servant fades away.%^RESET%^");
    }

    if(objectp(control)) {
		if (objectp(sword = control->query_mon())){
			sword->remove();
			destruct(control);
		}
    }
    if(objectp(caster)) { caster->remove_property("unseen_servant"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
