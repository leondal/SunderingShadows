// variation of fireball
//    Frost Orb - Cythera 5/05
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
    set_spell_name("frost orb");
    set_spell_level(([ "mage" : 3, "cleric" : 3, "druid": 3 ]));
    set_domains("cold");
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS frost orb on TARGET");
    set_description("This spell allows a mage to tap into the Para-Elemental Plane of Ice and borrow some of its energy "
"to create an orb of frost and ice.  Once the freezing orb is launched into the air, the first thing it strikes will "
"cause it to burst open, releasing the chilling attack on the mage's foes.  Though care should be taken as it is "
"possible to accidently catch the mages allies in the blast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "crystal":1, "beeswax":1, ]),
    ]));
    set_save("reflex");
    set_immunities( ({"cold"}) );
    splash_spell(1);
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" chants rapidly,"+
	" creating an orb of frost in "+caster->QP+" hand.";
}

void spell_effect(int prof) {

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
    tell_object(target,"%^BOLD%^%^CYAN%^An orb of frost and ice "+
	"speeds through the air from "+YOU+tmp+", heading straight for you!");
    if(living(caster)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^An orb of frost and ice"+
		" speeds through the air from your hand, heading straight for "+HIM+"!");
    }
    tell_room(place, "%^BOLD%^%^CYAN%^An orb of frost and ice speeds through"+
		" the air from "+YOU+tmp+", heading straight for "+HIM+"!",({ caster, target}) );
    tell_object(target,"%^BOLD%^%^WHITE%^The frost orb explodes as it hits you!",target);
    tell_room(environment(target),"%^BOLD%^%^WHITE%^The orb of frost explodes"+
		" as it hits "+target->QCN+"!",target);
    oldfoes=foes;
    foes = ({});
    allies = ({});
    y=2+to_int((clevel-5)/2);
    if (sizeof(oldfoes) < y)
        y = sizeof(oldfoes);
    for (x=0;x < y;x++) {
        tempob=oldfoes[random(sizeof(oldfoes))];
        if(do_save(tempob))
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
    if(do_save(target))
        damage_targ(target, "torso", to_int(sdamage / 2),"cold" );
    else
        damage_targ(target, "torso", sdamage,"cold" );
    for (x=0;x < sizeof(foes);x++) {
        if (!objectp(foes[x])) continue;
        tell_room(environment(foes[x]),"%^BOLD%^%^CYAN%^Shards of ice and frost freeze "+foes[x]->QCN+"!",foes[x]);
        tell_object(foes[x],"%^BOLD%^%^CYAN%^You are struck with shards of ice and frost from the orb.");
        if(do_save(foes[x]))
            damage_targ(foes[x], "torso", to_int(sdamage / 2),"cold" );
        else
            damage_targ(foes[x], "torso", sdamage,"cold" );
    }
    sdamage/=2;
    for (x=0;x < sizeof(allies);x++) {
        if (!objectp(allies[x])) continue;
        tell_room(environment(allies[x]),"%^BOLD%^%^CYAN%^Shards of ice and"+
		" frost strike "+allies[x]->QCN+"!",allies[x]);
        tell_object(allies[x],"%^BOLD%^%^CYAN%^Shards of ice and frost freeze you from the orb!");
        if(do_save(allies[x]))
            damage_targ(allies[x], "torso", to_int(sdamage / 2),"cold" );
        else
            damage_targ(allies[x], "torso", sdamage,"cold" );
    }
    dest_effect();
}

void dest_effect() {
   ::dest_effect();
    if(objectp(TO)) TO->remove();

}
