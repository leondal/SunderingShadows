//based on Magic Mirror by Thorn
//~Circe~ 7/30/05
// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define CONTROL "/d/magic/obj/mcrystal_ball"
#define SCRY_D "/daemon/ic_scry_locate_d"
#define DELAY 300

inherit SPELL;

object scry_control;
int cfail;
string former_short;

int checkMirror(object mirror);
void control_failure();

void create() {
    ::create();
    set_spell_name("remote viewing");
    set_spell_level(([ "psion" : 5 ]));
    set_spell_sphere("clairsentience");
    set_syntax("cast CLASS remote viewing on <object> (a crystal ball or equivalent)");
    set_description("By means of this power, the psion changes a normal crystal ball into a scrying device. The details "
"of the use of such a scrying device can be accessed by typing <help crystal ball> after a successful cast on a crystal "
"ball.  You will be able to scry a player character or a location with the scrying device made by this power.\n\nThe "
"crystal ball used must be of finely polished crystal of a minimum cost of 1,000 gp - such ones are generally found only "
"in psion enclaves as they are both large and fragile, making them impossible to carry around.\n\nYou will not be able "
"to scry a character that you have not recognized previously with the 'recognize' command.  Your chance of success in "
"using the crystal ball on a character is less if you recognize someone as something other than their true name, but its "
"better than nothing.  You may not scry locations at all unless they are in memory via the remember command.\n\nThere is "
"also a chance that the target of the power may notice that they are being scryed.  This depends on their class, and is "
"adjusted significantly by intelligence, and operates independently of any scry detection magic or devices.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_peace_needed(1);
}

string query_cast_string() {
    return "%^CYAN%^"+caster->QCN+" gently tosses four stones "+
       "into the air, sending them hovering in a slow circle.";
}

int preSpell(){
    if(caster->query_property("remote scrying")){
        tell_object(caster,"You have already focused your "+
            "sight elsewhere!");
        return 0;
    }
    if(avatarp(caster)) return 1; // let avatars use to follow players regardless of timer.
    if((int)caster->query_property("remote scrying time")+DELAY > time()){
        tell_object(caster,"You cannot command a scrying device again so soon.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int num,bonus,power,mylevel;
    int duration;
    string *ids,myname;

    ::spell_effect();

    spell_successful();

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^RED%^The stones fall to the floor "+
           "as "+caster->QCN+" looks around, confused.",caster);
        tell_object(caster,"%^BOLD%^RED%^The target of your spell is not here!");
        TO->remove();
		return;
    }
    mylevel = clevel;

    ids = target->query_id();
    if(target->is_crystal_ball() != 1) {
        tell_room(place,"%^BOLD%^RED%^The stones fall to the floor "+
           "as "+caster->QCN+" looks around, confused.",caster);
        tell_object(caster,"%^BOLD%^RED%^The focus of your power "+
           "must be a crystal ball.");
        TO->remove();
		return;
    }
    if(!checkMirror(target)) {
        tell_room(place,"%^BOLD%^RED%^The stones fall to the floor "+
           "as "+caster->QCN+" looks around, confused.",caster);
        tell_object(caster,"%^BOLD%^RED%^There appears to be "+
           "something wrong with the object you are focusing upon.");
        TO->remove();
        return;
    }
    myname = "mirror";
    if(target->is_crystal_ball() == 1) myname = "crystal ball";
    tell_room(place,"%^BOLD%^BLUE%^The gems spin faster before "+
       ""+caster->QCN+", and the "+myname+" begins to %^CYAN%^glow "+
       "%^BLUE%^faintly in response.",caster);
    tell_object(caster,"%^CYAN%^You lightly toss four crystals into "+
       "the air, causing them to spin in a slow circle.\n%^BOLD%^"+
       "%^BLUE%^You focus on the "+myname+" as the crystals spin "+
       "faster, causing the "+myname+" to %^CYAN%^glow %^BLUE%^"+
       "faintly.");

    target->set_property("spelled",({TO}));
    target->set_property("magic mirror",1);
    tell_object(caster,"%^BOLD%^YELLOW%^To learn the commands for this "
        "device, type <help "+myname+">.");
    former_short = target->query_short();
    target->set_short(former_short+" (glowing slightly)");
	scry_control = new(CONTROL);
	scry_control->set_observer(caster);
	scry_control->set_parent(TO);
      bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
      power = mylevel + random(6) + bonus;
	scry_control->set_scry_power(power);
	scry_control->move(environment(target));
    duration = 60+ (10 * mylevel);
    if(avatarp(caster)) duration = 400;
    addSpellToCaster();
    caster->set_property("remote scrying",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {
    if(objectp(scry_control)) SCRY_D->stop_scry(scry_control, 0);
    if(objectp(target)) target->set_short(former_short);
    if(objectp(caster)) {
      caster->remove_property("remote scrying");
      caster->remove_property("remote scrying time");
      caster->set_property("remote scrying time",time());
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
void control_failure() {
    TO->remove_call_out("dest_effect");
    tell_room(environment(target),"%^BOLD%^YELLOW%^The faint glow "+
       "fizzles out as the image fades.");
    target->remove_property_value("spelled", ({TO}) );
    target->remove_property("magic mirror");
    target->set_short(former_short);
    if(objectp(caster)) caster->remove_property("remote scrying");
    TO->remove();
    return;
}

int checkMirror(object mirror) {
    string *ids;
    int value;

    if(!objectp(mirror)) return 0;
    value = mirror->query_value();
    if(value < 1000) return 0;
    if(mirror->query_property("magic mirror")) return 0;
    return 1;
}
