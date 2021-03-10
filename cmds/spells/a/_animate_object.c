// reduced max items/wt. controlled per level  *Styx*
#include <magic.h>
#include <std.h>
#include <spell.h>
#include <security.h>

inherit SPELL;

object *animated, *monsters, control;
int amount;


int object_save(object thisob, mixed targ)
{
    if (!objectp(thisob)) return 0;
    if (!objectp(targ)) return 0;
    if (is_enchanted(thisob)) return 0;
    if (thisob->query_property("no animate")) return 0;
    if (thisob->query_property("monsterweapon")) return 0;
    if (!thisob->query_name()) return 0;
    if (thisob->is_corpse()) return 0;
    if (thisob->query_weight()>=10000)  return 0;
    if(!interactive(targ)) { targ->set_property("my animated stuff",({ thisob })); }
    return 1;
}


void create()
{
    ::create();
    set_spell_name("animate object");
    set_spell_level(([ "cleric" : 6, "bard" : 6, "psion" : 1 ]));
    set_spell_sphere("alteration");
    set_discipline("kineticist");
    set_domains("chaos");
    set_syntax("cast CLASS animate object on <object> || <room>");
    set_description("This spell allows you to animate objects and command then.  <command objects to command> will "
        "command the object to act as instructed.  Forcing an object to do something will affect your alignment when appropriate"
        ".  If you cast the spell on 'room', you will animate the objects located on the floor of the room (non living).  If you "
        "cast it on a non-living target, that object will become animated.  If you cast it on a living being, items from that "
        "being\'s inventory will be animated.\n\nEnchanted objects cannot be animated.  Objects will take damage in combat and "
        "may be destroyed.  The objects will remain animated until the spell ends or you <dismiss objects>.\n\nThere is a level "
        "effect that limits how large or how many objects you can animate.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    animated=({});
    monsters=({});
    set_save("will");
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^BOLD%^%^GREEN%^"+caster->QCN+" studies "+caster->QP+" environment carefully then lifts "+caster->QP+" head to the sky and chants deeply some prayer.";
}


int preSpell()
{
    if (!arg)
    {
        tell_object(caster,"%^BOLD%^You haven't focused your god's energy.");
        tell_room(place,"%^BOLD%^You feel the woosh of power flow by as it disperses unused!",caster);
        return 0;
    }

    if (present("devicex999", caster))
    {
        tell_object(caster, "%^CYAN%^You are incapable of controlling two sets of beings.\n");
        return 0;
    }
    return 1;
}


void spell_effect(int prof)
{
    object *inven, *livings;
    int tlevel;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    if (!objectp(place)) { place = environment(caster); }

    amount=clevel/12 + 1;

    if (arg=="room")
    {
        inven   =  all_inventory(place);
        livings =  all_living(place);
        inven   -= livings;
        tell_object(caster,"%^YELLOW%^You send forth your god's power into the objects surrounding you.");
        tell_room(place,"%^YELLOW%^You see the power of "+caster->QCN+"'s god flow forth into the room.",caster);
        do_animate(inven);
        return;
    }

    if(caster->is_player())
    {
        if(!objectp(target = present(caster->realName(arg),place)))
        {
            target = present(arg,place);
        }
    }
    else { target = present(arg,place); }

    if (objectp(target))
    {
        if(!interactive(target))
        {
            spell_kill(target,caster);
            target->set_property("animated by",({caster}));
        }
        if (living(target) && !target->query_property("no animate"))
        {
            tlevel = target->query_highest_level();
            if(!do_save(target,2))
            {
                inven = all_inventory(target);
                tell_object(caster,"%^BLUE%^You send forth your god's power around "+target->QCN+".");
                tell_room(place,"%^BLUE%^You see the power of "+caster->QCN+"'s god flow forth around "+target->QCN+".",caster);
                inven = filter_array(inven,"object_save",TO,target);
                if (sizeof(inven)) { do_animate(inven); }
                else { tell_room(place,"%^BLUE%^The spell's power fails to affect anything.."); }
            }
            else
            {
                tell_room(place,"%^BLUE%^The spell's power fails to affect anything.");
            }
        }
        else
        {
            tell_object(caster,"%^BLUE%^You send forth your god's power around "+target->QCN+".");
            tell_room(place,"%^BLUE%^You see the power of "+caster->QCN+"'s god flow forth around "+
                target->QCN+".",caster);
            do_animate(({target}));
        }
    }
    else
    {
        tell_object(caster,"%^BOLD%^You haven't focused your god's energy on something here.");
        tell_room(place,"%^BOLD%^You feel the woosh of power flow by as it disperses unused!",caster);
        dest_effect();
        return;
    }
    spell_successful();
}


void do_animate(object *stuff)
{
    int i, j, block_time;

    j = sizeof(stuff);

    for (i=0;i<j;i++)
    {
        if (!objectp(stuff[i])) continue;
        if (is_enchanted(stuff[i])) continue;
        if (stuff[i]->query_worn()) continue;
        if (stuff[i]->query_wielded()) continue;
        if (stuff[i]->query_property("no animate")) continue;
        if (stuff[i]->query_property("monsterweapon")) continue;
        if (stuff[i]->query_property("plot_item")) continue;
        if (stuff[i]->query_property("soulbound")) continue;
        if (!stuff[i]->query_name()) continue;
        if (stuff[i]->is_corpse()) continue;
        if (amount < 1) break;
        if (stuff[i]->query_weight()>=10000)  continue;
        if (stuff[i]->query_weight()>=500)
        {
            if (amount < 15)   continue;
            if (sizeof(animated)==0)
            {
                make_animate(stuff[i]);
                amount=0;
                animated+=({stuff[i]});
            }
            else { continue; }
        }
        else if ( stuff[i]->query_weight()>100)
        {
            if (amount < 7) continue;
            make_animate(stuff[i]);
            amount-=7;
            animated += ({stuff[i]});
        }
        else if (stuff[i]->query_weight() >= 50)
        {
            if (amount < 4) continue;
            make_animate(stuff[i]);
            amount-=4;
            animated += ({stuff[i]});

        }
        else if (stuff[i]->query_weight() >= 25)
        {
            if (amount < 2) continue;
            make_animate(stuff[i]);
            amount-=2;
            animated += ({stuff[i]});

        }
        else
        {
            make_animate(stuff[i]);
            amount--;
            animated+=({stuff[i]});
        }
    }

    control = new("/d/magic/obj/objectremote");
    control->set_mons(monsters);
    control->set_caster(caster);
    control->move(caster);
    control->set_my_spell(TO);
    control->set_property("spelled", ({TO}));
    control->set_property("spell", TO);
    call_out("dest_effect",( 2 + clevel) * 10);
    block_time = (2 + sizeof(monsters) ) / 2;
    caster->setAdminBlock(block_time);
    tell_object(caster,"%^BOLD%^%^YELLOW%^You begin concentrating on imposing your will on the objects.");
    call_out("release_block", block_time, caster);
}


void release_block(object caster)
{
    if (!objectp(caster))
    {
        remove_call_out("dest_effect");
        dest_effect();
        return ;
    }
    tell_object(caster,"%^BOLD%^%^RED%^You finish concentrating on organizing your army.");
}


int is_enchanted(object item)
{
     if (!objectp(item)) return 1;
     return item->query_property("enchantment");
}


void make_animate(object thing)
{
    object ob, *inven;
    string *limbs,type;
    int i,j,cond;

    if (!objectp(thing)) return;
    thing->move("/d/magic/obj/place.c");
    ob=new("/d/magic/obj/aobject.c");
    caster->add_follower(ob);
    ob->set_caster(caster);
    if ((int)thing->query_weight()<11) ob->set_size(1);
    else if ((int)thing->query_weight()<101) ob->set_size(2);
    else ob->set_size(3);
    tell_room(place,"%^GREEN%^You see "+thing->query_name()+" start to move and come to life!");
    ob->set_object(thing);
    ob->set_long(thing->query_long());
    ob->set_short(thing->query_short());
    if(objectp(caster)) ob->set_property("minion", caster);
    // changing to add check for stringp and set a name if original object's isn't valid
    // the objects have bugged at times in combat trying to log QCN
    // this fix suggested by Garrett - *Styx*  10/18/02
    if ( !stringp(thing->query_name()) ) {
        ob->set_name("magic object");
    } else {
        ob->set_name(thing->query_name());
    }
    ob->set_id(thing->query_id());
    ob->add_id("animated_object");
    ob->add_id("summoned monster");
    if (thing->is_armor()) {
        limbs=(string *)thing->query_limbs();
        j=sizeof(limbs);
        for (i=0;i<j;i++) {
            ob->add_limb(limbs[i],limbs[i],0,0,0);
        }
        ob->set_heart(2);
        ob->set_attack_limbs(limbs);
        ob->set_attacks_num(1);
        ob->set_base_damage_type("bludgeon");
        ob->set_damage(1,(int)thing->query_ac());
        ob->set_overall_ac(7-(int)thing->query_ac());
        ob->set_hd( ( ((int)thing->query_ac()*2) +1),8); //added +1 for cases=0
        ob->set_max_hp(12*clevel);
        cond = thing->query("condition");
        if (cond == 0) cond = 100;
        ob->set_hp((cond * (int)ob->query_max_hp())/100);
        ob->set_exp(100);
        ob->set_heart(3);
        ob->move(place);
        ob->set_property("spelled", ({TO}));
        ob->set_property("spell", TO);
        ob->set_stats("strength",10);
        ob->set_stats("dexterity",10);
        ob->set_stats("intelligence",1);
        monsters+=({ob});
        return;
    }
    if (thing->is_weapon()) {
        type=thing->query_type();
        ob->set_heart(3);
        switch (type) {
        case "slashing":
        case "thiefslashing":
            ob->add_limb("blade","blade",0,0,0);
            ob->add_limb("hilt","hilt",0,0,0);
            ob->set_attack_limbs(({"blade"}));
            ob->set_base_damage_type("slashing");
            break;
        case "piercing":
        case "thiefpiercing":
        case "magepiercing":
            ob->add_limb("tip","tip",0,0,0);
            ob->add_limb("handle","handle",0,0,0);
            ob->set_attack_limbs(({"tip"}));
            ob->set_base_damage_type("piercing");
            break;
        case "bludgeon":
        case "magebludgeon":
            ob->add_limb("head","head",0,0,0);
            ob->add_limb("handle","handle",0,0,0);
            ob->set_attack_limbs(({"head"}));
            ob->set_base_damage_type("bludgeon");
            break;
        default:
            break;
            // was return, but that would have skipped the next step if not a listed weapon type
        }
        ob->add_limb("body","body",0,0,0);   // added for these cases *Styx*
        ob->set_attack_limbs(({"body"}));    // added for these cases *Styx*
        ob->set_base_damage_type("bludgeon"); // added for these cases *Styx*
        ob->set_attacks_num(1);
        ob->set_damage(1,(int)thing->query_wc());
        ob->set_overall_ac(5);
        //        ob->set_hd(15,8);      // wonder why hd is always 15 for weapons... *Styx*
        // changed to be based on wc's so it's more balanced *Styx* 12/03/02
        ob->set_hd( (int)thing->query_wc()+(int)thing->query_large_wc(), 8);
        ob->set_exp(100);
        ob->set_stats("strength",10);
        ob->set_max_hp(clevel*8);
        cond = thing->query("condition");
        if (cond == 0) cond = 100;
        ob->set_hp((cond * (int)ob->query_max_hp())/100);
        ob->move(place);
        ob->set_property("spelled", ({TO}));
        ob->set_property("spell", TO);
        monsters+=({ob});
        return;
    }
    if (thing->is_container()) {
        inven=all_inventory(thing);
        ob->set_max_internal_encumbrance(500);
        j=sizeof(inven);
        for (i=0;i<j;i++) {
            inven[i]->move(ob);
        }
    }
    ob->add_limb("body","body",0,0,0);
    ob->set_attack_limbs(({"body"}));
    ob->set_base_damage_type("bludgeon");
    ob->set_attacks_num(1);
    ob->set_overall_ac(10);
    j=thing->query_weight();
    switch (j) {
    case 0..5:
        ob->set_damage(1,2);
        ob->set_hd(j,8);
        if (j = 0) ob->set_hd(1,2);
        ob->set_hp(ob->query_max_hp());
        break;
    case 6..25:
        ob->set_heart(2);
        ob->set_damage(1,2);
        ob->set_hd(j,8);
        ob->set_hp(ob->query_max_hp());
        // was missing this break, would have made small things more powerful?- Styx 6/02
        break;
    case 26..100:
        ob->set_heart(3);
        ob->set_damage(1,j/7);
        ob->set_hd(j/6,8);
        ob->set_hp(ob->query_max_hp());
        ob->set_stats("strength",16);
        break;
    case 101..499:
        ob->set_heart(4);
        ob->set_damage(1,20);
        ob->set_hd(16,8);
        ob->set_hp(ob->query_max_hp());
        ob->set_stats("strength",17);
        break;
    default:
        ob->set_heart(4);
        ob->set_damage(1,25);
        ob->set_hd(25,8);         //was 30, cut back to 25
        ob->set_stats("strength",20);     //added to keep from maxing to 25
        ob->set_hp(250);
        break;
    }
    // added to insure hp aren't 0 after seeing div by zero errors - might be related
    // to decay or items falling through the cracks of getting specs *Styx* 9/16/02
    if (ob->query_hp() == 0)  ob->set_hp(1);
    ob->set_max_hp(ob->query_hp());
    cond = thing->query("condition");
    if (cond == 0) cond = 100;
    ob->set_hp((cond * (int)ob->query_max_hp())/100);
    ob->set_exp(100);
    ob->move(place);
    ob->set_property("spelled", ({TO}));
    ob->set_property("spell", TO);
    ob->set_property("spell_creature", TO);
    monsters+=({ob});
    return;
}


void dest_effect() {
    int i,j;
    object ob;
    int hp,mhp, per;

    if (objectp(caster)) {
        tell_room(environment(caster),"%^ORANGE%^You see the animated objects lose their power.");
    }
    j=sizeof(monsters);
    seteuid(UID_ROOT);
    for (i=0;i<j;i++) {
        if (!objectp(monsters[i])) continue;
        ob=monsters[i]->query_object();
        hp = monsters[i]->query_hp();
        mhp = monsters[i]->query_max_hp();
        if (mhp > 0)
            per = (hp *100)/mhp;
        else
            per = 0;
        if (per == 0) per = 1;
        if (!objectp(ob)) continue;
        ob->set("condition",per);
        if (objectp(ob))   ob->move(environment(monsters[i]));
        monsters[i]->remove();
    }
    if (objectp(control))
        destruct(control);
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
