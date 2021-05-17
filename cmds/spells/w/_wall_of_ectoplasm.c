#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i;
object endplace, outside, wall, wall2;
string *dir_listing(string tempfil);

void create() {
    ::create();
    set_spell_name("wall of ectoplasm");
    set_spell_level(([ "psion" : 4 ]));
    set_spell_sphere("metacreativity");
    set_syntax("cast CLASS wall of ectoplasm on <exit>");
    set_description("Wall of ectoplasm is a potent power in the hands "
       "of a practiced psion.  The power calls into being a field of "
       "ectoplasm to block an exit. The wall can be ended by typing <remove wall>.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() {
    return "%^ORANGE%^"+caster->QCN+" closes "+caster->QP+" eyes, "+
       "placing "+caster->QP+" palms together before "+caster->QO+".";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs, arg;
    object *exits, *inexits, *burned;
    int i, j,mylevel;
    ::spell_effect();
    if (ARG)
        arg=lower_case(ARG);
    if (member_array(arg,place->query_exits()) < 0) {
        tell_object(caster,"You must specify an exit to block with this power!");
        return;
    }
    mylevel = clevel;
    wall=new("/d/magic/obj/ecto_wall.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    if (objectp(wall))
        wall->move(place);
    else
        return;
    wall->block(caster,arg);
    tell_room(place,"%^CYAN%^A shimmering field suddenly springs up, "+
       "blocking the "+arg+"!");
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
        if ( base_name(place) ==
             (string)outside->query_exit(ins[i]) ||
             base_name(place)+".c" ==
             (string)outside->query_exit(ins[i]) ||
             base_name(place) ==
             (string)outside->query_exit(ins[i])+".c") {
            wall2=new("/d/magic/obj/ecto_wall.c");
            wall2->set_property("spell",TO);
            wall2->move(outside);
            wall2->block(caster,ins[i]);
            tell_room(outside,"%^CYAN%^A shimmering field suddenly "+
                      "springs up, blocking the "+
                      ins[i]+"!%^RESET%^");
/*
            tell_room(outside,"%^CYAN%^A shimmering field suddenly "+
                      "spring up, blocking the "+
                      ins[i]+"!\n%^BOLD%^%^CYAN%^A burst of energy "+
                      "comes hurtling from the field!");
            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if(living(burned[j])){
                        tell_room(outside,"%^BOLD%^%^MAGENTA%^"+
                                  burned[j]->QCN+" is "+
                                  "lashed by the energy!",
                                  burned[j]);
                        tell_object(burned[j],"%^BOLD%^%^MAGENTA%^The "+
                           "energy lashes you severely!");
                        limbs = burned[j]->query_limbs();
                        if ( burned[j]->query_property("undead") )
                            damage_targ(burned[j],limbs[random(sizeof(limbs))],(4+random(13)),"force" );
                        else
                            damage_targ(burned[j],limbs[random(sizeof(limbs))],(2+random(7)),"force" );
                }
            }
*/
            break;
        }
    }
    spell_successful();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 10;
    set_end_time();
    call_out("dest_effect",(spell_duration));
    return;
}

void dest_effect() {
    if (objectp(wall))
        wall->remove_wall();
    if (objectp(wall2))
        wall2->remove_wall();
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
