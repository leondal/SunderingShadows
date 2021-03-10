// at present, on parity with wall of fire. Should be upgraded when that is.
#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

int i, hpcount;
string tempstr, element;
object endplace, outside, wall, wall2;

string *dir_listing(string tempfil);

void create() {
    ::create();
    set_spell_name("wall of perilous fire");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS wall of perilous fire [on <exit>]");
    set_description("This invocation is quite similar to the mage spell 'wall of fire', save that it is conjured purely "
"of planar energy. It allows the caster to create a wall of brilliant blue flames around himself, protectively, or in "
"front of an exit, so all who pass through that exit will be scorched by the flames. Half of the damage done is fire, "
"but the rest results from supernatural power and cannot be resisted. The warlock who casts this spell must keep "
"concentration on the wall to maintain its existence, and may type <remove wall> to quench the flames.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_helpful_spell(1);
}

string query_cast_string() 
{
    tell_object(caster,"%^BOLD%^%^WHITE%^You lift a hand to direct your invocation with a fingertip.%^RESET%^");
    if(objectp(place)) { tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" lifts a hand to direct "+caster->QP+" invocation with a fingertip.%^RESET%^",caster); }
    return "display";
}

void spell_effect(int prof) {
    string *outs, *ins, *limbs;
    object *exits, *inexits, *burned;
    int i, j, dmg;
    ::spell_effect();

    hpcount=caster->query_hp();
    if(arg && arg != "" && arg != " ") arg=lower_case(arg);

    if (member_array(arg,place->query_exits()) < 0) {
        tell_object(caster,"%^BOLD%^%^CYAN%^As your finger motions out an arc, a ring of %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^er%^BOLD%^%^BLUE%^ie cob%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^lt f%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^ame %^BOLD%^%^CYAN%^rises up around you!%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^As "+caster->QP+" finger motions out an arc, a ring of %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^er%^BOLD%^%^BLUE%^ie cob%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^lt f%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^ame %^BOLD%^%^CYAN%^rises up around "+caster->QCN+"!%^RESET%^", caster);
        wall=new("/d/magic/obj/pfirewall.c");
        wall->set_property("spell",TO);
        wall->set_property("spelled", ({TO}) );
        wall->move(place);
        wall->surround(caster);
        return;
    }
    wall=new("/d/magic/obj/pfirewall.c");
    wall->set_property("spell",TO);
    wall->set_property("spelled", ({TO}) );
    wall->block(caster,arg);
    if (objectp(wall)) wall->move(place);
    else return;

    tell_object(caster,"%^BOLD%^%^CYAN%^As your finger motions out a line, a wall of %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^er%^BOLD%^%^BLUE%^ie cob%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^lt f%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^ame %^BOLD%^%^CYAN%^rises up, blocking the "+arg+"!%^RESET%^");
    tell_room(place,"%^BOLD%^%^CYAN%^As "+caster->QCN+"'s finger motions out a line, a wall of %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^er%^BOLD%^%^BLUE%^ie cob%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^lt f%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^ame %^BOLD%^%^CYAN%^rises up, blocking the "+arg+"!%^RESET%^",caster);
    outside = find_object_or_load(place->query_exit(arg));
    ins = outside->query_exits();
    for (i=0;i<sizeof(ins);i++) {
      if(base_name(place) == (string)outside->query_exit(ins[i]) || base_name(place)+".c" == (string)outside->query_exit(ins[i]) || base_name(place) == (string)outside->query_exit(ins[i])+".c") {
            wall2=new("/d/magic/obj/pfirewall.c");
            wall2->set_property("spell",TO);
            wall2->block(caster,ins[i]);
            wall2->move(outside);
            tell_room(outside,"%^BOLD%^%^CYAN%^A ring of %^BOLD%^%^BLUE%^e%^BOLD%^%^CYAN%^er%^BOLD%^%^BLUE%^ie cob%^BOLD%^%^CYAN%^a%^BOLD%^%^BLUE%^lt f%^BOLD%^%^CYAN%^l%^BOLD%^%^BLUE%^ame %^BOLD%^%^CYAN%^rises up, blocking the "+ins[i]+"!\n%^BOLD%^%^BLUE%^Waves of heat roll off the wall of fire towards you!%^RESET%^");

            burned = all_inventory(outside);
            for (j=0;j<sizeof(all_inventory(outside));j++) {
                if ( living(burned[j]) ) {
                    tell_room(outside,"%^BOLD%^%^CYAN%^"+burned[j]->QCN+" is burned by the wall's searing heat!%^RESET%^",burned[j]);
                    tell_object(burned[j],"%^BOLD%^%^CYAN%^The searing heat of the wall of flames burns you badly!%^RESET%^");
                    limbs = burned[j]->query_limbs();
                    if(burned[j]->query_property("undead")) dmg = 4+random(13);
                    else dmg = 2+random(7);
                    damage_targ(burned[j],limbs[random(sizeof(limbs))],dmg/2,"fire");
                    damage_targ(burned[j],limbs[random(sizeof(limbs))],dmg/2,"untyped");
                }
            }
            break;
      }
    }
    call_out("concentration",4);
    return;
}

void concentration() {
    int flag = 0;
    if ( caster->query_paralyzed() ||
         !objectp(wall) ||
         !objectp(wall2))
        flag = 1;
    if ((int)caster->query_hp() != hpcount) {
        if ((int)caster->query_hp() < hpcount - 30 ) {
            tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" looks as though "+caster->QS+" just lost "+caster->QP+" concentration!%^RESET%^",caster);
            tell_object(caster,"%^CYAN%^You lose your concentration on maintaining the wall of flames you invoked!%^RESET%^");
            flag = 1;
        } else
            hpcount = caster->query_hp();
    }
    if (flag)
        call_out("dest_effect",clevel*3);
    else
        call_out("concentration",4);
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
