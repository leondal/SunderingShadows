// Web

#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass, caster, target, place;
int waittime, clevel, pbound;

void dest_effect();
void waiter(int num);

create() {
    ::create();
    set_spell_name("web thorn");
    set_spell_level(2);
    set_spell_type("wizard");
    set_spell_sphere("invocation_evocation");
    set_components(([
                    "spider web" : 1,
                    ]));
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_xp_bonus(5);
    pbound = 0;
}

string query_cast_string() {
    return caster->query_cap_name()+" steps away from "+target->query_cap_name()+" and starts a low chant.";
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;
    caster=CASTER;
    target=TARGET;
    clevel=CLEVEL;
    place=PLACE;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }
    tell_object(caster,"%^YELLOW%^You jab your finger at "+target->query_cap_name()+" and strands of sticky web shoot out towards "+target->query_objective()+"!");
    tell_object(target,"%^YELLOW%^"+caster->query_cap_name()+" jabs "+caster->query_possessive()+" finger at you, shooting out strands of sticky web!");
    tell_room(place,"%^YELLOW%^"+caster->query_cap_name()+" jabs "+caster->query_possessive()+" finger at "+target->query_cap_name()+", shooting out strands of sticky web!", ({caster, target}) );
    waittime=10;
    power=target->query_stats("strength");
    if (power > 17) {
        waittime=to_int(waittime/2);
    }
    if (power <= 13 && power >= 9) {
        waittime=waittime*2;
    }
    if (power < 9) {
        waittime=waittime*4;
    }
    save = roll_dice(1, 20);
    neededroll = "/daemon/saving_d"->return_throw("spell",(string)target->query_class(), (int)target->query_level());
    if ( (save == 20) || (neededroll <= (save)) || target->query_property("no web")) {
        tell_object(caster,"%^BOLD%^%^RED%^"+target->query_cap_name()+" manages to dodge your mass of webs!");
        tell_object(target,"%^BOLD%^%^RED%^You manage to dodge the mass of webs!");
        tell_room(environment(caster),"%^BOLD%^%^RED%^"+target->query_cap_name()+" manages to dodge the mass of webs!",({caster, target}) );
        dest_effect();
        return;
    } else {
        strength="furiously wrap around";
        spell_successful();
        tell_object(caster,"%^BOLD%^%^RED%^Your mass of webs "+strength+" "+target->query_cap_name()+" trapping "+target->query_objective()+" within!");
        tell_object(target,"%^BOLD%^%^RED%^"+caster->query_cap_name()+"'s mass of webs "+strength+" you, trapping you within!");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->query_cap_name()+"'s mass of webs "+strength+" "+target->query_cap_name()+" trapping "+target->query_objective()+" within!", ({caster,target}) );
    }
    if(target->is_player()) pbound = 1;
    if(!pbound) {
        oldenv=environment(target);
        mass=new("/d/magic/obj/webmass.c");
        mass->set_spell(TO);
        mass->move(oldenv);
        web=new("/d/magic/room/in_web.c");
        target->move(web);
    }
    else {
        target->set_property("spelled",({TO}));
        target->set_bound(waittime+2);
    }
    call_out("waiter",ROUND_LENGTH,1);
}

void waiter(int num) {
    object *tempinv;
    if(!target){
        tell_object(caster, "Got here, but shouldn't have.");
        dest_effect();
        return;
    }
    if(!pbound && !objectp(web)){
        tell_object(caster, "Got here, but shouldn't have.");
        dest_effect();
        return;
    }
    if(!pbound) {
        if (!present(target,web)) {
            tell_object(caster, "Got here, but shouldn't have.");
            mass->remove();
            web->move("/d/shadowgate/void.c");
            while ( tempinv=(object *)web->all_inventory() ) {
                tempinv[0]->move(oldenv);
                return;
            }
        }
    }
    if(!target->query_bound()) {
    	dest_effect();
    	return;
    }
    if ( (to_float(num)/2)==to_int(num/2) )
    tell_object(caster, "Got here. 4");
    if (num < waittime)
        call_out("waiter",ROUND_LENGTH,num+1);
    else
        dest_effect();
    return;
}

void helped() {
    if (target)
        tell_object(target,"You hear someone tearing through the the surface of the web.");
    waittime--;
    return 1;
}

void dest_effect() {
    int i;
    object *tempinv;

    ::dest_effect();
    if(pbound) {
    	if(target->query_bound()) {
	        target->set_bound(0);
	        tell_object(target,"%^BOLD%^%^RED%^You manage to break through the mass of webs!");
	        tell_room(place,"%^BOLD%^%^RED%^"+target->query_cap_name()+" manages to break through the mass of webs!",target );
		}
		else {
	        tell_object(target,"%^BOLD%^%^GREEN%^You walk away from the broken mass of webs!");
	        tell_room(place,"%^BOLD%^%^GREEN%^"+target->query_cap_name()+" walks away from the mass of webs!",target);		
		}
        TO->remove();
        return;
    }
    if (objectp(mass))
        mass->remove();
    if (objectp(target) && objectp(web))
        if (present(target,web)) {
            tell_object(target,"%^BOLD%^%^RED%^You manage to break through the mass of webs!");
            tell_room(place,"%^BOLD%^%^RED%^"+target->query_cap_name()+" manages to break through the mass of webs!",target );
            target->move(oldenv);
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
        }
    if (objectp(target) && objectp(web)) {
        if (!present(target,web)) {
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
            TO->remove();
        }
    } else if(objectp(web)) {
        tempinv=all_inventory(web);
        for (i=0;i++;i<sizeof(tempinv)) {
            if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
        }
        TO->remove();
        web->remove();
    } else {
        TO->remove();
    }
   if(objectp(TO))
    TO->remove();
    return;
}

int help() {
    return 0;
    write(
@EndText
Syntax: cast web on <target>

When a victim is unfortunate enough to be victim of a web spell,
he/she might as well get a new hobby.  If the web is successful, the
victim will be trapped within a massive web for quite some time.  The
time it takes for the victim to escape varies with strength.

Material component required:
A spider web
EndText
);
    return 1;
}
