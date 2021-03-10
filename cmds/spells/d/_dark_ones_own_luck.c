#include <spell.h>
#include <daemons.h>
#include <magic.h>
inherit SPELL;

string thesave;
int thebonus, active;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("dark ones own luck");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS dark ones own luck on fortitude|reflex|will");
    set_description("The caster draws upon their connection with the planes beyond, seeking the "
"luck (or perhaps misfortune for their foes?) to better their chances at avoiding harm. This "
"is manifested in the form of a bonus to one saving throw of choice, selected from fortitude, "
"reflex or will. This does not work together with the 'force of personality' feat.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
    set_arg_needed();
}

int preSpell() {
    if (caster->query_property("saves invocation")) {
        tell_object(caster, "You are already subject to similar magic.");
        return 0;
    }
    if (FEATS_D->has_feat(caster,"force of personality") || FEATS_D->usable_feat(caster,"force of personality")) {
        tell_object(caster, "You are already subject to similar magic.");
        return 0;
    }
    if(member_array("force of personality",(string*)caster->query_temporary_feats()) != -1) {
        tell_object(CASTER,"You are already under the influence of a similar effect.");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    tell_object(caster,"%^ORANGE%^With a snap of your fingers you invoke your inner strength.%^RESET%^");
    tell_room(place,"%^ORANGE%^A snap of "+caster->QCN+"'s fingers draws your attention.%^RESET%^",caster);
    return "display";
}

void spell_effect(int prof) {
    if (!arg) {
      tell_object(caster,"The invocation wavers and then fails. You realise you can only seek such fortune to fortitude, reflex or will saves.");
      dest_effect();
      return;
    }
    if (arg != "fortitude" && arg != "reflex" && arg != "will") {
      tell_object(caster,"The invocation wavers and then fails. You realise you can only seek such fortune to fortitude, reflex or will saves.");
      dest_effect();
      return;
    }

    thesave = arg;
    switch(thesave) {
      case "fortitude":
        tell_object(caster,"%^ORANGE%^A resol%^RED%^u%^ORANGE%^te feeling washes over you.%^RESET%^");
        tell_room(place,"%^ORANGE%^"+caster->QCN+" seems to grow more st%^RED%^e%^ORANGE%^adfast and assured.%^RESET%^",caster);
      break;
      case "reflex":
        tell_object(caster,"%^ORANGE%^You feel suddenly lig%^YELLOW%^h%^RESET%^%^ORANGE%^t and limber.%^RESET%^");
        tell_room(place,"%^ORANGE%^"+caster->QCN+"'s motions seem to become more lig%^YELLOW%^h%^RESET%^%^ORANGE%^t and graceful.%^RESET%^",caster);
      break;
      case "will":
        tell_object(caster,"%^ORANGE%^Your mind grows calmed and f%^GREEN%^o%^ORANGE%^cussed.%^RESET%^");
        tell_room(place,"%^ORANGE%^"+caster->QCN+"'s gaze takes on a depth of f%^GREEN%^o%^ORANGE%^cus.%^RESET%^",caster);
      break;
    }

    active = 1;
    thebonus = ((int)caster->query_stats("charisma") - 10)/2;
    caster->add_saving_bonus(thesave,thebonus);
    caster->set_property("saves invocation",1);
    spell_successful();
    addSpellToCaster();
    call_out("test",ROUND_LENGTH);
}

void test() {
    if (!objectp(caster)) {
        if(objectp(TO)) TO->remove();
        return;
    }

    if (FEATS_D->has_feat(caster,"force of personality") || FEATS_D->usable_feat(caster,"force of personality")) {
        tell_object(caster,"The invocation wavers and then fails as it comes into conflict with similar magic.");
        TO->dest_effect();
        return;
    }
    if(member_array("force of personality",(string*)caster->query_temporary_feats()) != -1) {
        tell_object(caster,"The invocation wavers and then fails as it comes into conflict with similar magic.");
        TO->dest_effect();
        return;
    }
    call_out("test",ROUND_LENGTH);
}


void dest_effect() {
    if(find_call_out("test") != -1) remove_call_out("test");
    if(objectp(caster) && active){
      tell_object(caster,"%^ORANGE%^You feel the supernatural fortune ebb away.%^RESET%^",caster);
      thebonus *= -1;
      caster->add_saving_bonus(thesave,thebonus);
      caster->set_property("saves invocation",-1);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
