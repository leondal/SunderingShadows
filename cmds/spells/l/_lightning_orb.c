// variation of fireball
//    Lighting Orb - Cythera 5/05
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

int effect,x,i,y;
string tmp,YOU,HIM;
object victim,tempob,*foes,*oldfoes,*tempfoes,*watchers,*allies;

void damage();

void create() {
    ::create();
    set_author("cythera");
    set_spell_name("lightning orb");
    set_spell_level(([ "mage" : 3 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS lightning orb on TARGET");
    set_description("This spell allows a mage to tap into the Para-Elemental Plane of Lightning and borrow some of its "
"energy to create an orb of pure lightning.  Once the orb is launched into the air, the first thing it strikes will cause "
"it to burst open, releasing the shocking attack on the mage's foes.  Though care should be taken as it is possible to "
"accidently catch the mages allies in the blast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    splash_spell(1);
    set_components(([
      "mage" : ([ "magnets" : 1, "beeswax" : 1, ]),
    ]));
    set_immunities( ({"lightning"}) );
    set_save("reflex");
}

string query_cast_string() {
    return "%^BOLD%^%^YELLOW%^"+caster->QCN+" chants rapidly,"+
	" creating an orb of lightning in "+caster->QP+" hand.";
}

spell_effect(int prof) {
    YOU=caster->QCN;

    if(!present(target,caster->is_room()?caster:environment(caster))){
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    spell_successful();
    if ( !interactive(caster) && !caster->query_invis() )
        YOU=caster->QCN;
    HIM=target->QCN;
    foes=target_selector();

    if (member_array(target,foes) != -1)
        foes -= ({ target});


    tmp="";
    if (interactive(caster))
        tmp="'s finger";
    tell_object(target,"%^BOLD%^%^YELLOW%^An orb of lightning "+
	"speeds through the air from "+YOU+tmp+", heading straight for you!");
    if(living(caster)) {
        tell_object(caster,"%^BOLD%^%^YELLOW%^An orb of lightning"+
		" speeds through the air from your hand, heading straight for "+HIM+"!");
    }
    tell_room(place, "%^BOLD%^%^YELLOW%^An orb of lightning speeds through"+
		" the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^The lightning orb explodes as it hits you!",target);
    tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of lightning explodes"+
		" as it hits "+target->QCN+"!",target);
    oldfoes=foes;
    foes = ({});
    allies = ({});
    y=2+to_int((clevel-5)/2);
    if (sizeof(oldfoes) < y)
        y = sizeof(oldfoes);
    for (x=0;x < y;x++) {
        tempob=oldfoes[random(sizeof(oldfoes))];
        if(do_save(tempob,0))
        //if ("/daemon/saving_d"->saving_throw(tempob, "spell"))
            allies += ({ tempob});
        else
            foes += ({ tempob});
        oldfoes -= ({ tempob});
    }
    y=clevel;
/*
    if(y>10)
        y=10;
*/
    if(do_save(target,0))
    //if ("/daemon/saving_d"->saving_throw(target, "spell"))
        damage_targ(target, "torso", to_int(sdamage / 2),"electricity" );
    else
        damage_targ(target, "torso", sdamage,"electricity" );
    for (x=0;x < sizeof(foes);x++) {
        if (!objectp(foes[x])) continue;
        tell_room(environment(foes[x]),"%^BOLD%^%^YELLOW%^Bolts of lightning"+
		" from the orb shock "+foes[x]->QCN+"!",foes[x]);
        tell_object(foes[x],"%^BOLD%^%^YELLOW%^You are jolted with bolts of lighting from the orb.");
        if(do_save(foes[x],0))
        //if ("/daemon/saving_d"->saving_throw(foes[x], "spell"))
            damage_targ(foes[x], "torso", to_int(sdamage / 2),"electricity" );
        else
            damage_targ(foes[x], "torso", sdamage,"electricity" );
    }
    sdamage/=2;
    for (x=0;x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
        tell_room(environment(allies[x]),"%^BOLD%^%^YELLOW%^Bolts of "+
		"lightning from the orb shock "+allies[x]->QCN+"!",allies[x]);
        tell_object(allies[x],"%^BOLD%^%^YELLOW%^Bolts of lightning from the orb shock you!");
        if(do_save(allies[x],0))
        //if ("/daemon/saving_d"->saving_throw(allies[x], "spell"))
            damage_targ(allies[x], "torso", to_int(sdamage / 2),"electricity" );
        else
            damage_targ(allies[x], "torso", sdamage,"electricity" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
