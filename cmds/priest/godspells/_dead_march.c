//_dead_march.c

#include <std.h>

inherit SPELL;

object remote;
object *monsters;

void make_animate(object thing);

void create() {
    ::create();
    set_spell_name("dead march");
    set_spell_sphere("necromatic");
    set_spell_type("priest");
    set_spell_level(4);
    set_diety("kelemvor");
    set_verbal_comp();
    set_somatic_comp();
    monsters = ({});
}

string query_cast_string() {
    return "%^BLACK%^%^BOLD%^With a blank face, "+caster->query_cap_name()+" looks at the dead and calls to the now lifeless corpses.";
}

void spell_effect(int prof) {
    int i;
    object corpse;

    tell_room(place,"%^BLUE%^A darkness falls over the room, as the spirits of the fallen relinquish their hold on their corpses.");
    tell_object(caster,"%^RED%^Kelemvor allows you to take control of the husks of the fallen.");

    if (!(remote = present("devicex998",caster))) {
        remote = new ("/d/magic/obj/corpseremote");
        remote->set_caster(caster);
        remote->move(caster);
        remote->set_property("spell", TO);
        remote->set_property("spelled", ({TO}) );
    }
     else { 
        remote->set_property("spelled", ({TO}) );
     }

    i=0;
    while ((corpse = present("remains",place)) && i < 10) {
        make_animate(corpse);
        i++;
        corpse = 0;
    }

    call_out("dest_effect",clevel*60);

}


void make_animate(object thing) {
    object ob, *inv;
    string *limbs,type;
    int i,j,cond;

    if (!objectp(thing)) return;
    thing->set_property("no_decay",1);
    thing->move("/d/magic/obj/place.c");
    ob=new("/d/magic/obj/aobject.c");
    tell_room(place,"%^GREEN%^You see "+thing->query_name()+" start to move and come to life!");
    caster->add_follower(ob);
    ob->set_race(thing->query_race());
    ob->set_object(thing);
    ob->set_long(thing->query_cont_long());
    ob->set_short(thing->query_short());
    ob->set_name(thing->query_name());
    ob->set_id((string *)thing->query_id()-({"remains"}));
    ob->add_id("summoned monster");
    limbs = thing->query_limbs();
    for (i=0;i<sizeof(limbs);i++) {
        ob->add_limb(limbs[i],"",0,0,0);
    }
    ob->set_attack_limbs(thing->query_wielding());
    ob->set_wielding_limbs(thing->query_wielding());
    ob->set_damage(1,4);
    ob->set_base_damage_type("bludgeon");
    ob->set_attacks_num(1);
    ob->set_overall_ac(10-(clevel/3));
    ob->set_hd(clevel/3 + 1);
    ob->set_max_hp(ob->query_hp());
    cond = thing->query("condition");
    if (cond == 0) cond = 100;
    ob->set_hp((cond * (int)ob->query_max_hp())/100);
    ob->set_exp(100);
    ob->move(place);
    ob->set_property("spell",TO);
    ob->set_property("spelled",({TO}));
    ob->set_property("spell_creature", TO);
    remote->add_mon(ob);
    monsters += ({ob});

    i= sizeof(inv = all_inventory(thing));
    while (i--) inv[i]->move(place);

    ob->move(place);
    return;
}

void dest_effect() {
    int i,j;
    object ob;
    int hp,mhp, per;

    j=sizeof(monsters);
    if (objectp(caster)) {
       tell_room(environment(caster),"%^ORANGE%^You see the animated corpses slip to the ground in rest.");
   }

    for (i=0;i<j;i++) {
        if (!(objectp(monsters[i]))) {
             continue;
       }
        ob=(object) monsters[i]->query_object();
        hp = monsters[i]->query_hp();
        mhp = monsters[i]->query_max_hp();
        if (mhp > 0)
            per = (hp *100)/mhp;
        else
            per = 0;
        if (per == 0) per = 1;
        if (!objectp(ob)) continue;
        ob->set("condition",per);
        if (objectp(ob)) {
            ob->move(environment(monsters[i]));
            ob->remove_property("no_decay");
        }
        if(objectp(remote)) {
            remote->remove_mon(monsters[i]);
        }
        monsters[i]->remove();
        
//        if (objectp(ob)) ob->remove();
    }
    if (objectp(remote)) {
        if(sizeof(remote->query_mons()) < 1) {
            remote->remove();   
        }
    }
//  destruct(remote);
    TO->remove();
}

int help() {
    write(
@OLI
Spell  : Dead March
Level  : 4th Level
Sphere : Necromatic
Deity  : Kelemvor
Syntax : chant dead march

This spell allows you to gain control over the mindless husks of
the dead. You can build an army of animated corpses. But they need
directing in every manner. command corpses to <action> will direct
your army. Each casting will build your army more.
OLI
);
    return 1;
}
