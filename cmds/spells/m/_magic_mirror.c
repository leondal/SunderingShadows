// Has uses and a time limit
// Thorn
// 29 December 2000

// Scry power stuff added by ~Circe~ 6/20/08 to fix problems with
// a scry blocker always thwarting scry, no matter the level of
// the casters involved.
//changed to have delay for followers - they should not be better spies than pc mages - Tsera
// duration on all scrying spells (and between-cast delays where relevant) rebalanced. Nienne, 5/15.

#include <spell.h>
#include <magic.h>
#include <daemons.h>
#define CONTROL "/d/magic/obj/mmirror"
#define SCRY_D "/daemon/ic_scry_locate_d"
#define DELAY 1500 + random(1500)
#define SCRY_DELAY 60
//minimum 25 minute delay with a random 25 minutes added to it.  Should work out to an average of 38 minutes or so. - Tsera
inherit SPELL;
object scry_control;
int cfail;
string former_short;
int checkMirror(object mirror);
void control_failure();
object puppeteer;

void create() {
    ::create();
    set_spell_name("magic mirror");
    set_spell_level(([ "mage" : 7,]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS magic mirror on <object> (a scrying mirror)");
    set_description("By means of this spell, the wizard changes a normal mirror into a scrying device similar to a "
"crystal ball. The details of the use of such a scrying device can be accessed by typing <help mirror> after a successful "
"cast on a mirror.  You will be able to scry a player character or a location with the scrying device made by this spell."
"\n\nThe mirror used must be of finely wrought and highly polished silver of a minimum cost of 1,000 gp.  These mirrors "
"are generally found only in wizard's laboratories as they are both large and fragile, making them impossible to carry "
"around.\n\nYou will not be able to scry a character that you have not recognized previously with the 'recognize' command"
".  Your chance of success in using the mirror on a character is less if you recognize someone as something other than "
"their true name, but its better than nothing.  You may not scry locations at all unless they are in memory via the "
"remember command.\n\nThere is also a chance that the target of the spell may notice that they are being scryed.  This "
"depends on their class, and is adjusted significantly by intelligence.  This operates independantly of any scry "
"detection magic or devices.  This spell can only be cast while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_non_living_ok(1);
    set_peace_needed(1);
    set_components(([
      "mage" : ([ "copper":1, "zinc":1, "nitric acid":1, "eye of roc":1, ]),
    ]));
}

int preSpell(){
    string* theids;
    if (userp(caster)) {
        return 1;
    }
    theids = caster->query_id();
    if (member_array("retainer", theids) != -1) {
        puppeteer = caster->get_followee();
        if (!objectp(puppeteer)) {
            tell_object(caster, "Your master is AWOL!");
            caster->force_me("shake");
            caster->force_me("say I have noone to direct me.");
            return 0;
        }
        if ((int)puppeteer->query_property("mirror time") + DELAY > time()) {
            tell_object(caster, "You are already too drained to try that again so soon.");
            caster->force_me("shake");
            caster->force_me("say I cannot do that for you right now.");
            return 0;
        }
    }
    if (caster->query_property("mirror time") + SCRY_DELAY > time()) {
        tell_object(caster,"You're exhausted from your previvous attempt.");
        return 0;
    }

    if (caster->query_property("remote scrying")) {
        tell_object(caster, "You are already looking upon someone from afar.");
        return 0;
    }
    if(caster->query("no pk")){
        tell_object(caster,"%^YELLOW%^You are unable to scry while you have a %^MAGENTA%^NoPK %^YELLOW%^flag.%^RESET%^");
        return 0;
    }
    return 1;
}

string query_cast_string() {
    return "%^BOLD%^CYAN%^"+caster->QCN+" begins chanting slowly...";
}

void spell_effect(int prof) {
    int num,power,bonus;
    int duration;
    string *ids;
    ::spell_effect();
    puppeteer = caster->get_followee();
    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^RED%^"+caster->QCN+" abruptly "
            "stops chanting and looks around.",caster);
        tell_object(caster,"%^BOLD%^RED%^The target of your spell is not here!");
        TO->remove();
        return;
    }
    ids = target->query_id();
    if(target->is_scrying_mirror() != 1) {
        tell_room(place,"%^BOLD%^RED%^"+caster->QCN+" abruptly "
            "stops chanting and shrugs.",caster);
        tell_object(caster,"%^BOLD%^RED%^The target of your spell is not a "
            "mirror!");
        TO->remove();
                return;
    }
    if(!checkMirror(target)) {
        tell_room(place,"%^BOLD%^RED%^"+caster->QCN+" chants, "
           "but nothing seems to happen.",caster);
        tell_object(caster,"%^BOLD%^RED%^The magic does not appear to be "
            "taking to this mirror for some reason.");
        TO->remove();
        return;
    }
    tell_room(place,"%^BOLD%^GREEN%^As "+caster->QCN+" chants, "
        "a faint glow flickers around the "+target->query_name()+" and then slowly becomes "
        "constant.",caster);
    tell_object(caster,"%^BOLD%^GREEN%^As you chant, a faint glow flickers "
        "around the "+target->query_name()+" and then slowly becomes constant.");
    target->set_property("spelled",({TO}));
    target->set_property("magic mirror",1);
    tell_object(caster,"%^BOLD%^YELLOW%^To learn the commands for this "
        "device, type <help mirror>.");
    former_short = target->query_short();
    target->set_short(former_short+" (glowing slightly)");
        scry_control = new(CONTROL);
        scry_control->set_observer(caster);
        scry_control->set_parent(TO);
//Bonus stuff by ~Circe~ 6/20/08
//updated again by ~Circe~ 9/16/11 to use bonuses correctly
      bonus = calculate_bonus(caster->query_stats(get_casting_stat()));
      power = CLEVEL + random(6) + bonus;
//random(6) provides 0-5, allowing for some randomness
    scry_control->set_scry_power(power);
//End bonus stuff
    scry_control->move(environment(target));
//    duration = 8 * (int)CLEVEL;
    duration = 60 + (5 * CLEVEL);
    if (avatarp(caster)) {
        duration = 400;
    }
    // Bards don't get greater scrying
    if (spell_type == "bard") {
        duration = 60 + (CLEVEL);
    }
    caster->set_property("remote scrying",1);
    spell_duration = duration;
    set_end_time();
    call_out("dest_effect",spell_duration);
    addSpellToCaster();
//below code added to delay followers from chain scrying -Tsera 3-31-12
   if(!userp(caster)) { // only run checks if it's not a player object casting
     puppeteer->set_property("mirror counter",1);
     if((int)puppeteer->query_property("mirror counter") > 1){
       if(member_array("retainer",caster->query_id())) {
         puppeteer->remove_property("mirror time");
         puppeteer->set_property("mirror time",time());
       }
       puppeteer->remove_property("mirror counter");
     }
   }

   return;
}

void dest_effect()
{
    if (objectp(caster)) {
        caster->remove_property("remote scrying");
        set_property("mirror time", time());
    }
    if (objectp(scry_control)) {
        SCRY_D->stop_scry(scry_control, 0);
    }
    if (objectp(target)) {
        target->set_short(former_short);
    }
    // For some reason there was an error, so I'll try to protect against it?
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

// Handle premature end of the scry gracefully, probably
// due to subject quitting, or some strange occurrence.

void control_failure() {
    TO->remove_call_out("dest_effect");
    if(objectp(target)) {
      tell_room(environment(target),"%^BOLD%^YELLOW%^The faint glow around the "+target->query_name()+" fizzles out.");
      target->remove_property_value("spelled", ({TO}) );
      target->remove_property("magic mirror");
      target->set_short(former_short);
    }
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
