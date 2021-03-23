#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

int olight;
object shape, *were;

void create()
{
    ::create();
    set_author("tlaloc");
    set_spell_name("lunar veil");
    set_spell_level(([ "mage" : 7, "cleric" : 7 ]));
    set_domains("moon");
    set_spell_sphere("illusion");
    set_syntax("cast CLASS lunar veil");
    set_damage_desc("Darkens the area and reverts lycanthropes to their true forms");
    set_description("You conjure a tremendous area of shadow to obscure moonlight within the area, creating something akin to a lunar eclipse. The area becomes darker. Lycanthropes in the area must make a Will save every round or revert to their humanoid forms.");
    set_save("will");
    set_verbal_comp();
    set_somatic_comp();
    aoe_spell(1);
    set_aoe_message("(%^MAGENTA%^swirling with darkness%^RESET%^)");
}

string query_cast_string()
{
    return "%^CYAN%^WHITE%^" + caster->QCN+" whispers in an arcane tongue as the area begins to dim.%^RESET%^";
}

void spell_effect()
{
    tell_room("%^MAGENTA%^BOLD%^Darkness blots out the sky and the moon disappears as a swirling magic flits about the area.%^RESET%^");
    olight = place->query_light();
    if(olight > -2)
        place->set_light(-2);
    
    spell_successful();
    
    call_out("remove_were", ROUND_LENGTH - 1);
    call_out("dest_effect", clevel / 8 + 1);
}

void remove_were()
{
    were = target_selector();
    were = filter_array(were, (: $1->is_were() :));
    
    tell_room(place, "%^BOLD%^WHITE%^Chill darkness permeates the area as swirling magic seeks its target.%^RESET%^");
    
    foreach(object ob in were)
    {
        if (do_save(ob, 0))
            tell_object(caster, "%^BOLD%^The magic wills the true form of " + ob->QCN + ", but nothing happens.%^RESET%^");
        else if (objectp(shape = target->query_property("shapeshifted")))
            shape->reverse_shape(target);
    }
    
    call_out("remove_were", ROUND_LENGTH - 1);
}

void dest_effect()
{
    tell_room(place, "The dispelling magics seem to dissapate and the darkness subsides.");
    
    place->set_light(olight);
    
    if(find_call_out("remove_were") >= 0)
        remove_call_out("remove_were");
    
    ::dest_effect();
    
    if(objectp(this_object()))
        this_object()->remove();
}
