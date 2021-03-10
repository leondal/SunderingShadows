#include <std.h>
#include <priest.h>
#include <daemons.h>
inherit SPELL;

int counter,chance,toggle,mylevel;
object targ;

void create() {
    ::create();
    set_spell_name("timeless body");
    set_spell_level(([ "psion" : 9, "oracle":8, "bard" : 5 ]));
    set_mystery("ancestor");
    set_spell_sphere("combat");
    set_syntax("cast CLASS timeless body");
    set_description("This power will enable a psion to take on a ghostly state, making him difficult to hit in combat.  "
"The power has an equal chance each round to make the psion untouchable or not.  The psion's body fades, becoming "
"partially on this plane and partially on the Astral Plane.

%^BOLD%^%^RED%^See also:%^RESET%^ timeless body *feats");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
    set_feats_required(([ "bard" : "timeweaver" ]));
}

string query_cast_string() {
   return "%^BOLD%^%^CYAN%^The color begins to fade from "+caster->QCN+"'s eyes.";
}

int preSpell() {
    if (caster->query_property("amorpha") || caster->query_property("timeless body")) {
//together these were broken, stacking regularly 100% miss chance. N, 4/14
        tell_object(caster, "You are already protected by a spell of concealment.");
        return 0;
    }
    if (caster->query_blinking()) {
        tell_object(caster, "You can't maintain such a spell while blinking.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{

    mylevel = clevel;

    targ = CASTER;
    if(!FEATS_D->usable_feat(targ,"armored manifester")){
       if (!targ->is_ok_armour("mage")){
          if(!FEATS_D->usable_feat(targ,"armored caster")){
            tell_object(targ,"The power cannot offer protection while you "+
               "wear such armor.");
            TO->remove();
            return;
          }
       }
    }
    tell_room(place,"%^BOLD%^%^WHITE%^The color drains from the rest "+
       "of "+targ->QCN+"'s body, giving "+targ->QO+" a ghostlike appearance!",targ);
    tell_object(targ,"%^BOLD%^%^WHITE%^The color drains away from "+
       "your body, giving you a ghostly appearance!");
    toggle = 1;
    targ->set_missChance(targ->query_missChance() + 65);
    targ->set_property("timeless body",1);
    targ->set_property("spelled", ({TO}) );
    spell_successful();
    addSpellToCaster();
    place->addObjectToCombatCycle(TO,1);
    call_out("test",2);
}

void test()
{
    if (!objectp(TO) || !objectp(targ))
        return;
    place = environment(targ);
    if(!FEATS_D->usable_feat(targ,"armored manifester")){
    if (!targ->is_ok_armour("mage"))
    {
        if(!FEATS_D->usable_feat(targ,"armored caster"))
        {
            tell_object(targ,"The power cannot offer protection while you "+
               "wear such armor.");
            TO->dest_effect();
            return;
        }
    }
    }
    call_out("test", 5);
}

int flag;

void execute_attack(){
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(targ)) {
        dest_effect();
        return;
    }
    place = environment(targ);
    if(random(2))
    {
        if(!toggle)// added a toggle to reduce spam so the message only appears when the state changes -Ares
        {
            tell_room(place,"%^BOLD%^%^WHITE%^The color drains from the rest "+
                "of "+targ->QCN+"'s body, giving "+targ->QO+" a ghostlike appearance!",targ);
            tell_object(targ,"%^BOLD%^%^WHITE%^The color drains away from "+
                "your body, giving you a ghostly appearance!");
            toggle = 1;
            targ->set_missChance(targ->query_missChance()+ 50);
//            tell_object(targ,"Total miss chance = "+(int)targ->query_missChance()+".");
        }
    }
    else
    {
        if(toggle)
        {
            tell_room(place,"%^BOLD%^%^BLUE%^"+targ->QCN+" suddenly "+
                "seems substantial again!",targ);
            tell_object(targ,"%^BOLD%^%^BLUE%^You feel yourself grow "+
                "more substantial again!");
            toggle = 0;
            chance = (int)targ->query_missChance()-50;
//giving them a base 25 miss chance when "off" since it no longer stacks with concealing
//amorpha. Without it, the average miss chance is only 37%, barely more than the level 2 spell.
//          chance = (int)targ->query_missChance()-75;
            targ->set_missChance(chance);
//            tell_object(targ,"Total miss chance = "+(int)targ->query_missChance()+".");
        }
    }
    counter++;
    if(FEATS_D->usable_feat(TO,"slippery caster")) {
    if (counter > (mylevel+6 * 1.33)) {
        dest_effect();
        return;
    }
    }else{
    if (counter > (mylevel+6)) {
        dest_effect();
        return;
    }
    }
    place->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
   if (objectp(targ)) {
      if(toggle) {
         chance = (int)targ->query_missChance() - 65;
      }else{
         chance = (int)targ->query_missChance()-15;
      }
      targ->set_missChance(chance);
      targ->remove_property("timeless body");
      targ->remove_property_value("spelled", ({TO}) );
      tell_object(targ,"%^BOLD%^%^BLUE%^Your body ceases to fade "+
         "into mistiness.");
      tell_room(environment(targ),"%^BOLD%^%^BLUE%^"+targ->QCN+" grows "+
         "completely substantial once more.", targ);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
