#include <spell.h>
#include <magic.h>
inherit SPELL;

string heritage;
object *mons = ({});
void check();
void check2();
void do_summons();

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("beckoned from beyond");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS beckoned from beyond on <swarm|guardian>");
    set_description("This invocation extends the warlock's innate personal force into the plane with which they are linked, calling forth creatures to serve at their bidding. Such spellcraft can compel the (temporary!) loyalty of a swarm of lesser outsiders, capable of speed and flight but not possessed of great intellect or a capacity to follow complex commands beyond the warlock's direct protection.

Alternatively, a single greater guardian can be summoned forth, which can be directed to the caster's far more specific requirements. Only one or the other may be called at a time, and the guardian is considered a greater summons. You can give it weapons and equipment if you wish so, outsider will bring them back from outer planes.
To command outsider, use %^ORANGE%^<command outsider to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^.
To make lost outsider to follow you, %^ORANGE%^<command outsider to follow>%^RESET%^.
To dismiss outsider, %^ORANGE%^<dismiss outsider>%^RESET%^.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    tell_object(caster,"%^RED%^Voicing the syllables of the summoning, you extend your will out and beyond...%^RESET%^");
    tell_room(place,"%^RED%^"+caster->QCN+" voices unsettling syllables in a commanding tone, and the air behind "+caster->QO+" trembles.%^RESET%^",caster);
    return "display";
}

int preSpell() {
    if(arg != "guardian" && arg != "swarm") {
      tell_object(caster,"You may only call upon a guardian or a swarm.");
      return 0;
    }
    if(caster->query_property("creatures_beckoned")) { // only one active copy of this spell at a time in any version!
      tell_object(caster,"You can't summon more creatures than you already have!");
      return 0;
    }
    if(arg == "guardian") {
      if(caster->query_property("has_elemental") || caster->query_property("mages_sword")) { // one greater summons only
        tell_object(caster,"You already have a powerful summoned creature under your control.");
        return 0;
      }
    }
    else {
      if(present(caster->query_name()+"beckoned 4",place)) { // per snakes/plants
        tell_object(caster,"You can't summon more creatures than you already have!");
        return 0;
      }
    }
    return 1;
}

void spell_effect(int prof) {
    object mon;
    int i, num;
    heritage = (string)caster->query("warlock heritage");

    caster->set_property("creatures_beckoned",1);
    addSpellToCaster();
    spell_successful();
    if(arg == "guardian") {
      do_summons();
      return;
    }
    tell_object(caster,"%^RED%^Your power ensnares a swarm of lesser outsiders, and you draw them forth into the prime to defend you!%^RESET%^");
    tell_room(place,"%^RED%^A rift appears momentarily in the rippling air, and from it emerges a swarm of creatures!%^RESET%^",caster);

    num = (clevel/4) + random(3); // this spell is intensely variable - trying to remove that!
    if(num < 3) num = 3;
    if (num > 12) num = 12;
    for (i=0;i<num;i++)
    {
        mon = new("/d/magic/mon/warlock_lesser_summons");
        if(!objectp(mon))
        {
            tell_object(caster, "Your warlock swarm did not work... please let a wiz know this message.");
            break;
            continue;
        }
        mons += ({ mon });
        mon->set_mytype(heritage);
        mon->set("aggressive",1);
        mon->remove_property("swarm");
        mon->set_mlevel("fighter",clevel);
        mon->set_guild_level("fighter",clevel);
        mon->set_attacks_num(0);
        mon->set_hp(clevel+30);
        mon->set_property("spelled", ({TO}));
        mon->set_property("spell_creature", TO);
        mon->set_property("spell", TO);
        mon->add_id(caster->query_name()+"beckoned");
//        mon->set_short("tiny outsider");
        mon->set_stats("strength",14);
        mon->set_stats("dexterity",14);
        mon->set_stats("constitution",14);
        mon->set_new_exp(1,"low");
        mon->set_property("minion", caster);
        mon->move(environment(caster));
        caster->add_follower(mon);
        caster->add_protector(mon);
    }
    duration = time() + 300 + (ROUND_LENGTH * clevel);
    check();
}

void check() {
    object mon,*attackers,att;
    int i,j;

    mons -= ({ 0 });
    if( (!objectp(caster)) || (time() > duration) || (!sizeof(mons)) || (!objectp(place = environment(caster))) ) {
        dest_effect();
        return;
    }
    for(i=0;i<sizeof(mons);i++) {
        if(!objectp(mon = mons[i])) continue;
        if(environment(mon) != place) {
            tell_room(environment(mon),"%^RED%^With its master gone, "+mon->QCN+" winks out of existence.%^RESET%^");
            mon->move("/d/shadowgate/void");
            mon->remove();
            continue;
        }
        caster->add_protector(mon);
        caster->add_follower(mon);

        if(!sizeof(attackers = (object*)caster->query_attackers())) continue;

        for(j=0;j<sizeof(attackers);j++) {
            if(!objectp(att = attackers[j])) continue;
            if(member_array(att,(object*)mon->query_attackers()) != -1) continue;
            mon->kill_ob(att,0);
        }
    }
    call_out("check",5);
}

void do_summons() {
	if (!objectp(caster)) {
      	TO->remove();
        	return;
    	}

    	if (environment(caster) != place) {
      	tell_object(caster,"Your movement causes the spellcasting to fail.");
      	tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
      	TO->remove();
      	return;
    	}
    	tell_object(caster,"%^RED%^Extending a hand before you, you motion "
      "into being a weakness between the planes. The air shimmers and grows hazy.%^RESET%^");

    	tell_room(place,"%^RED%^"+caster->QCN+" extends a hand before "+caster->QO+", "
      "and the air shimmers and grows hazy.%^RESET%^",caster);

    	call_out("do_summons_2",ROUND_LENGTH);
}

void do_summons_2() {
   	object device,mon;
    	if (!objectp(caster)) {
      	TO->remove();
        	return;
    	}
    	if (environment(caster) != place) {
      	tell_object(caster,"Your movement causes the spellcasting to fail.");
      	tell_room(place,caster->QCN+" stops casting and looks a little disoriented.",caster);
        caster->remove_property("creatures_beckoned");
      	TO->remove();
      	return;
    	}

    	tell_room(place,"%^RED%^As you watch, the hazy air ripples and a form takes "
      "shape, its outline vague as though distant or deeply hidden. It grows clearer, approaching "
      "rapidly from beyond until it steps forth onto the material plane...%^RESET%^");

      mon = new("/d/magic/mon/warlock_greater_summons");
      if(!objectp(mon)) {
        tell_object(caster,"Your greater summons didn't work! Please contact a wiz with this error message.");
        dest_effect();
        return;
      }
     mons += ({ mon });
    mon->set_property("spelled", ({TO}));
    device = new("/d/magic/obj/gateholder");
    device->set_property("spell", TO);
    device->set_elemental(mon);
    device->set_caster(caster);
    caster->add_follower(mon);
    device->move(caster);
    mon->set_property("spell_creature", TO);
    mon->set_property("spell", TO);
    mon->add_id("summoned monster");
    mon->move(place);
    mon->setup_beastie(caster,heritage);
    mon->set_mylevel(clevel);
    mon->set_caster(caster);
    mon->set_property("minion", caster);
    caster->set_property("has_elemental",1);
    //gets set earlier in the code - Saide, December 2016
    //addSpellToCaster();
    check2();
}

void check2() { // this is basically just spell cleanup. Guardian is custom commandable so doesn't auto follow or defend
    object mon,*attackers,att;
    int i,j;

    mons -= ({ 0 });
    if((!objectp(caster)) || (!sizeof(mons))) {
        dest_effect();
        return;
    }
    if(!objectp(mons[0])) {
        dest_effect();
        return;
    }
    call_out("check2",5);
}

void dest_effect() {
      int num, i;
      object * wheretold = ({ });
      if (find_call_out("check") != -1) remove_call_out("check");
      if (find_call_out("check2") != -1) remove_call_out("check2");
      if(objectp(caster)) caster->remove_property("creatures_beckoned");
    	if(arg == "swarm") {
        num=sizeof(mons);
        for(i=0;i<(num);i++) {
          if(mons[i] && objectp(mons[i])) {
            if(objectp(caster)) {
              if(member_array(environment(mons[i]),wheretold) == -1) {
                tell_room(environment(mons[i]),"%^RED%^The swarming outsiders suddenly disappear!%^RESET%^");
                wheretold= distinct_array(wheretold + ({ environment(mons[i]) }));
              }
              caster->remove_follower(mons[i]);
            }
            mons[i]->move("/d/shadowgate/void");
            mons[i]->remove();
          }
        }
    	}
      if(arg == "guardian") {
        if(objectp(caster)) caster->remove_property("has_elemental");
        if(sizeof(mons)) {
          if(objectp(mons[0])) {
      	tell_room(environment(mons[0]),"%^RED%^The extraplanar being quite suddenly disappears!%^RESET%^");
      	mons[0]->move("/d/shadowgate/void");
      	mons[0]->remove();
          }
        }
      }
    	::dest_effect();
    	if(objectp(TO)) TO->remove();
}
