#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>
inherit SPELL;

void create() {
    ::create();
    set_spell_name("tornado blast");
    set_spell_level(([ "psion" : 9 ]));
    set_discipline("kineticist");
    set_spell_sphere("psychokinesis");
    set_syntax("cast CLASS tornado blast on TARGET");
    set_description("This power enables a kineticist to draw upon his knowledge of energy to create a whirling vortex in "
"the area.  The vortex is directed at the target, who suffers a chance to be knocked down and lose anything he might be "
"holding.  Others in the area may also be tossed about by the winds, suffering serious harm.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^BLACK%^The %^CYAN%^wind %^BLACK%^around "+
       ""+caster->QCN+" picks up, blowing "+caster->QP+" hair "+
       "to the side.%^RESET%^";
}

void spell_effect(int prof) {
    int dam,alldam,i,mycheck,yourcheck;
    string *ids;
    object *weapons,*foes,*ownparty;

    if (!objectp(target) || !objectp(caster)) {
        dest_effect();
        return;
    }
    foes = ({});
    ownparty = ({});
    dam = sdamage;
    tell_object(caster,"%^BOLD%^%^BLACK%^You summon a whirling vortex, "+
       "its %^CYAN%^winds %^BLACK%^screaming above "+target->QCN+"!");

    tell_object(target,"%^BOLD%^%^BLACK%^A whirling vortex appears over "+
       "your head, threatening to suck the life from you!");
    tell_room(place,"%^BOLD%^%^BLACK%^A whirling vortex appears above "+
       ""+target->QCN+"'s head, directed by "+caster->QCN+"'s whim!",({caster,target}));
    damage_targ(target,"torso",dam,"bludgeoning");
    if(!random(2)){
       mycheck = roll_dice(1,20)+(int)caster->query_stats("intelligence");
       yourcheck = roll_dice(1,20)+(int)caster->query_stats("dexterity");
       if(mycheck > yourcheck) {
          tell_object(target,"%^BOLD%^%^CYAN%^Winds buffet against you, "+
             "tossing you to the ground!");
          target->set_tripped(random(2),"You are struggling to get to your feet!");
       }
       if(!do_save(target,0)) {
          weapons = target->query_wielded();
          if(sizeof(weapons) && !target->query_property("no disarm")){
             tell_object(target,"%^BOLD%^%^WHITE%^Your weapons fly "+
                "from your grasp!");
             for (i=0,sizeof(weapons)>0;i<sizeof(weapons);i++)
             {
                 if(!objectp(weapons[i])) { continue; }
                ids = weapons[i]->query_id();
                if(!weapons[i]->query_property("monsterweapon")) target->force_me("unwield "+ids[0]);
	          target->remove_property("disarm time");
		    target->set_property("disarm time",(time() + (ROUND_LENGTH * roll_dice(1,4))));
             }
          }
       }
    }
    tell_object(place,"%^BOLD%^%^BLACK%^The %^CYAN%^vortex %^BLACK%^widens, "+
       "striking all in its path!");
    foes += target_selector();
    if(member_array(target,foes) != -1) foes -= ({target});

    for(i=0;i<sizeof(foes);i++){
       if(foes[i]->id(""+caster->query_name()+" summoned")) continue;
       if(foes[i]->id(""+(string)caster->query_name()+" retainer")) continue;
       tell_object(foes[i],"%^RESET%^%^CYAN%^You are whipped about by "+
          "the gale-force winds!");
       tell_room(place,"%^RESET%^%^CYAN%^"+foes[i]->QCN+" is whipped "+
          "about by the winds!",foes[i]);
       damage_targ(foes[i],foes[i]->return_target_limb(),dam,"bludgeoning");
       if(!sizeof(foes)) break;
    }
    spell_successful();
    if(!sizeof(foes)){
       dest_effect();
       return;
    }
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
