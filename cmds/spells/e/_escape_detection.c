#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define SCRY_D "/daemon/ic_scry_locate_d"

inherit SPELL;

object blocker;

void create() {
    ::create();
    set_spell_name("escape detection");
    set_spell_level( ([ "psywarrior" : 3, "psion" : 4 ]) );
    set_spell_sphere("clairsentience");
    set_discipline("seer");
    set_syntax("cast CLASS escape detection [on TARGET]");
    set_description("The target of this power can be a room or a person. "
       "If cast on a person, the power's effect moves with them, sweeping "
       "the areas they pass though.  If manifested without a target, the "
       "effect is centered on the room and remains there.\n\nBy means of "
       "this power, the psionic character blocks all scrying attempts on "
       "him/her by means of scrying spells and abilities like magic mirror and "
       "remote viewing, or scrying objects like a crystal ball.  The power "
       "protects against scrying attempts based on the level of the person "
       "attempting the scrying as opposed to the level of the manifester "
       "with an intelligence adjustment. If the level of the person scrying "
       "is high enough, the scryer 'burns through' the spell and the scry "
       "is successful.  A successful 'burn through' does not end this power, "
       "and it does not alert the protected person that it has been thwarted. "
       "If the protection is successful, magical feedback interferes with "
       "the scrying magic and dispels it.\n\nA scry detection power, such as "
       "'detect remote viewing' or certain magical items will detect a "
       "successful scrying attempt and thus can be used in addition to this "
       "power to see if the scry protection has been thwarted. This power "
       "can be manifested only while at peace.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
    set_components(([
      "psywarrior" : ([ "tourmaline": 2, ]),
    ]));
    set_helpful_spell(1);
}

int preSpell() {
    if(!query_arg()){
        target = caster;
        return 1;
    }else{
        target = present(query_arg(), query_place());
    }
    return 1;
}


string query_cast_string() {
   return "%^RESET%^%^MAGENTA%^As "+caster->QCN+" %^RESET%^%^MAGENTA%^"
      "glances around, the air shimmers p%^BOLD%^u%^RESET%^%^MAGENTA%^r"
      "p%^BOLD%^l%^RESET%^%^MAGENTA%^e and %^GREEN%^gr%^BOLD%^e%^RESET%^"
      "%^GREEN%^en%^MAGENTA%^, the colors of t%^BOLD%^o%^RESET%^%^MAGENTA%^"
      "u%^GREEN%^r%^MAGENTA%^ma%^BOLD%^%^GREEN%^l%^RESET%^%^MAGENTA%^i"
      "%^BOLD%^n%^RESET%^%^MAGENTA%^e.%^RESET%^";
}

void spell_effect(int prof) {
    int num, int_bonus,power, mylevel;
    int duration;
    object temp;

    ::spell_effect();
    place = PLACE;
    caster = CASTER;

    if(!objectp(target)) {
        tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" abruptly frowns "
           "in confusion.%^RESET%^",caster);
        tell_object(caster,"%^BOLD%^%^MAGENTA%^The target of your power is not here!");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(temp = target->query_property("block scrying")){
       if(!objectp(temp)){
          target->remove_property("block scrying");
       }else{
          tell_object(caster,"%^BOLD%^%^MAGENTA%^There is already blocking "
    	    	"magic working for that target!%^RESET%^");
            if(objectp(TO)) TO->remove();
            return;
       }
    }
    if(target == place){
       tell_room(place,"%^RESET%^%^GREEN%^The %^BOLD%^s%^MAGENTA%^h%^RESET%^"
          "%^MAGENTA%^i%^GREEN%^m%^BOLD%^m%^MAGENTA%^e%^RESET%^%^MAGENTA%^r"
          "%^GREEN%^i%^BOLD%^n%^MAGENTA%^g %^RESET%^%^GREEN%^brightens to a "
          "blinding intensity before fading away, leaving behind a crackling energy.%^RESET%^");
    }else{
       tell_room(place,"%^RESET%^%^GREEN%^The %^BOLD%^s%^MAGENTA%^h%^RESET%^%^MAGENTA%^i"
          "%^GREEN%^m%^BOLD%^m%^MAGENTA%^e%^RESET%^%^MAGENTA%^r%^GREEN%^i%^BOLD%^n%^MAGENTA%^g "
          "%^RESET%^%^GREEN%^brightens to a blinding intensity before fading away, leaving "
          "behind a crackling energy around "+target->QCN+".%^RESET%^");
    }
    target->set_property("spelled",({TO}));
    blocker = SCRY_D->add_block_scrying(target);
    if(!objectp(blocker)) {
        tell_object(caster,"%^BOLD%^RED%^Something is wrong that "
            "a wiz might want to look at!");
        dest_effect();
        return;
    }
    int_bonus = calculate_bonus(caster->query_stats(get_casting_stat()));

    mylevel = clevel;

    power = mylevel + int_bonus + random(6);
    blocker->set_block_power(power);
    duration = 9 * mylevel;
    spell_successful();
    spell_duration = (clevel / 2 + roll_dice(1, 20)) * ROUND_LENGTH;
    set_end_time();
    call_out("dest_effect",spell_duration);
    return;
}

void dest_effect() {

    if(objectp(target)) target->remove_property_value("spelled", ({TO}) );
    if(objectp(blocker)) blocker->self_destruct();
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
