// Detect Invisibility
#include <spell.h>
#include <magic.h>
inherit SPELL;

object oldenv, *conceal;
int i, num = 0;

void dest_effect();
object *invisobs();
void env_change();
void see_room();
void see_changes();

void create() {
    ::create();
    set_spell_name("shadow sight");
    set_spell_level(([ "monk" : 9 ]));
    set_spell_sphere("divination");
    set_monk_way("way of the shadow");
    set_syntax("cast CLASS shadow sight");
    set_description("This spell allows the caster to see into the shadows to know what "+
    "may be hidden there, including creatures and objects that are normally or magically hidden. "+
    "It functions much like the mage spell, detect invisibility.");
//    set_verbal_comp();
//    set_somatic_comp();
    set_components(([
    ]));
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" closes "+
    caster->QP+" eyes and focuses intently!%^RESET%^";
}

int preSpell(){
    if(caster->detecting_invis())
    {
        tell_object(caster, "You are already detecting invisible.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int bonus = prof;

    oldenv=environment(caster);
    spell_successful();
    tell_room(environment(caster),"%^BOLD%^%^BLACK%^%^"+
    caster->QCN+"'s eyes snap open and flash a "+
    "deep black for a instant before returning to their normal shade of "+
    (string)caster->query_eye_color()+".",caster);

    tell_object(caster,"%^BOLD%^%^BLACK%^Your eyes snap open and flash deep black "+
    "for an instant before returning to their normal shade of "+
    (string)caster->query_eye_color()+"!%^RESET%^");

    caster->set_detecting_invis(1);
    caster->set_property("spelled", ({TO}) );
    clevel = ((clevel*prof)/100);
    if (clevel < 1 )
    {
        dest_effect();
        return;
    }
    if (prof < 100 && random(100) > prof) {
        call_out("flip", random(20), 0);
    }else {
        addSpellToCaster();
    }
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 6;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void flip(int onOff)
{
    if(objectp(caster))
    {
        caster->set_detecting_invis(onOff);
        call_out("flip",random(20),!onOff);
    }
}

void dest_effect() {

    if (objectp(caster))
    {
        tell_object(caster,"%^BOLD%^%^BLACK%^Your vision is suddenly hazy as your "+
        "eyes return to normal.%^RESET%^");
        tell_room(environment(caster),"%^BOLD%^%^BLACK%^"+caster->QCN+
                  "'s eyes glaze over for a brief instant before "+
                  "returning to normal.%^RESET%^", caster);
        caster->set_detecting_invis(0);
        caster->remove_property_value("spelled", ({TO}) );
        remove_call_out("flip");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
