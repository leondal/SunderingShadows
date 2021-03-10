#include <std.h>
#include <daemons.h>
#include <magic.h>
inherit FEAT;

int duration, basemax, newmax, deltahp, feattracker, cooldown, myFlag, BonusFlag;

void rage_me();
void check();

void create() {
   ::create();
   feat_type("instant");
   feat_category("KiOffense");
   feat_name("flurry of blows");
   feat_desc("This feat allows the monk to focus her mind. She is able to uncanningly spot the weaknesses in the defenses of her enemies  by doing so, which allows her to attack at least once more, possibly  twice, at the expense of 1 Ki per combat round. This feat functions only  when unarmored and unarmed or wielding small weapons while the monk has  Ki available.");
   feat_prereq("Monk L2");
   feat_syntax("flurry_of_blows on|off");
   set_target_required(0);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
   if(!objectp(ob)) { return 0; }
   if((int)ob->query_class_level("monk") < 2 || (int)ob->query_alignment() > 3)
   {
      dest_effect();
      return 0;
   }
    return ::prerequisites(ob);
}

int cmd_flurry_of_blows(string str)
{
   object feat;
   if(!objectp(TP)) { return 0; }
   if(str) str = lower_case(str);
   if((int)TP->query_alignment() > 3) return 0;
   if(!TP->is_class("monk")) return 0;
   if(str != "on" && str != "off")
   {
      tell_object(TP,"Use flurry_of_blows on or flurry_of_blows off.");
      return 1;
   }
   if(!(int)USER_D->can_spend_ki(TP, 1) && str == "on")
   {
       tell_object(TP, "%^BOLD%^%^CYAN%^You lack the needed ki to enable flurry of blows.%^RESET%^");
       dest_effect();
       return 1;
   }
   feat = new(base_name(TO));
   feat->setup_feat(TP,str);
   return 1;
}

void execute_feat()
{
    object myFB;
    int i;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        caster->send_paralyzed_message("info",caster);
        dest_effect();
        return;
    }
    ::execute_feat();
    switch(arg)
    {
        case "off":
            if(!objectp(myFB = caster->query_property("flurry of blows")))
            {
                tell_object(caster,"%^CYAN%^You currently are not focusing your mind on spotting the weaknesses "+
                "in the defense of your enemies.%^RESET%^");
                dest_effect();
                break;
            }
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            break;
        case "on":
            if(objectp(myFB = caster->query_property("flurry of blows")))
            {
                tell_object(caster,"%^CYAN%^You are already focusing your mind on spotting the weaknesses in "+
                "the defenses of your enemies.%^RESET%^");
                dest_effect();
                break;
            }
            if((int)caster->query_property("using instant feat"))
            {
                tell_object(caster,"%^BOLD%^You are already in the middle of using a feat.%^RESET%^");
                dest_effect();
                break;
            }
            if(caster->query_casting())
            {
                tell_object(caster,"%^BOLD%^You are already in the middle of casting a spell.%^RESET%^");
                dest_effect();
                break;
            }
            if(!(int)USER_D->can_spend_ki(caster, 1))
            {
                tell_object(caster, "%^BOLD%^%^CYAN%^You lack the needed ki to focus your mind so completely.%^RESET%^");
                dest_effect();
                return;
            }
            tell_object(caster,"%^BOLD%^%^CYAN%^You focus your mind enabling yourself to see the weak spots in your "+
            "enemies defenses.%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^%^"+caster->QCN+" begins focusing intently.%^RESET%^",caster);
            call_out("check",ROUND_LENGTH);
            caster->set_property("flurry of blows", TO);
            return;
            break;
    }
    return;
}

int calculate_my_dam(object victim, int crit)
{
    object myFB;
    int dam, mycrit_range=20;
    if(!objectp(caster))
    {
        return 0;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        return 0;
    }
    if((int)caster->query_alignment() > 3)
    {
        return 0;
    }
    dam = (int)caster->query_unarmed_damage();
    if(FEATS_D->usable_feat(caster, "weapon finesse")) dam += BONUS_D->query_stat_bonus(caster, "dexterity");
    else dam += BONUS_D->query_stat_bonus(caster, "strength");
    dam += (int)caster->query_damage_bonus();
    if(caster->is_class("monk")) dam += "/std/class/monk.c"->effective_enchantment(caster);
	if(FEATS_D->usable_feat(caster, "lethal strikes")){
		mycrit_range=19;
	}
	if(crit >= mycrit_range) dam = "/daemon/combat_d.c"->crit_damage(caster, victim, 0, (int)victim->query_size(), dam, 0);
    return dam;
}

void flurry_hit()
{
    string myWay, dam_type,*ways = ({ "way of the fist","way of the shadow","way of the elements" });
    object myVic, myFB;
    int dam, crit, mybonus, DC;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_alignment() > 3)
    {
        myFB->dest_effect();
        dest_effect();
        return;
    }

    myWay = (string)caster->query("monk way");
    if(FEATS_D->usable_feat(caster,"grandmaster of the way")) // maybe give the grandmaster its own hit func at some point
    {
        myWay = ways[random(sizeof(ways))];
    }

    myVic = caster->query_current_attacker();
    if(!objectp(myVic)) return;
    if(caster->query_paralyzed()) return;
    DC = (int)caster->query_class_level("monk");
    DC += (int)"/daemon/bonus_d.c"->query_stat_bonus(caster, "wisdom");
    DC += 5;
    if((crit = (int)BONUS_D->process_hit(caster, myVic, 1, 0, 0, 1)))
    {
        dam = calculate_my_dam(myVic, crit);
        dam_type = "bludgeoning";
        tell_object(caster, "%^BOLD%^%^BLACK%^You strike "+myVic->QCN+
        " with a sudden ferocity!%^RESET%^");
        tell_object(myVic, caster->QCN+"%^BOLD%^%^BLACK%^ strikes you with "+
        "a sudden ferocity!%^RESET%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), caster->QCN+"%^BOLD%^%^BLACK%^ strikes "+myVic->QCN+
            "%^BOLD%^%^BLACK%^ with a sudden ferocity!%^RESET%^", ({caster, myVic}));
        }
        if(myWay == "way of the fist" && !random(5))
        {
            if(do_save(myVic,DC) || myVic->query_property("no paralyze") || myVic->query_property("no death"))
            {
                tell_object(myVic, "%^BOLD%^%^RED%^Your body shudders violently for "+
                "a brief instant but you manage to shake off most of the strike.%^RESET%^");
                if(objectp(environment(caster)))
                {
                    tell_room(environment(caster), myVic->QCN+"%^BOLD%^%^RED%^'s body "+
                    "shudders violently for a brief instant but "+myVic->QS+
                    " manages to shake off most of the strike.%^RESET%^", ({myVic}));
                }
            }
            else
            {
                tell_object(myVic, "%^BOLD%^%^GREEN%^Your body shudders violently for "+
                "a brief instant before you collapse!%^RESET%^");
                myVic->set_tripped(1, "%^BOLD%^%^GREEN%^You are struggling to get back to "+
                "your feet!%^RESET%^");
                if(objectp(environment(caster)))
                {
                    tell_room(environment(caster), myVic->QCN+"%^BOLD%^%^GREEN%^'s body "+
                    "shudders violently for a brief instant before "+myVic->QS+
                    " collapses!%^RESET%^", ({myVic}));
                }
            }
        }
        else if(myWay == "way of the shadow" && (int)caster->query_class_level("monk") > 16)
        {
            tell_object(caster, "%^BOLD%^%^BLACK%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
            "%^BLACK%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^ of "+
            "sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o"+
            "%^BOLD%^%^BLACK%^w lash out at "+myVic->query_cap_name()+
            "%^BOLD%^%^BLACK%^!%^RESET%^");

            mybonus = ((int)caster->query_class_level("monk")/10)+1;
            dam += roll_dice(mybonus,4);

            tell_object(myVic, "%^BOLD%^%^BLACK%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
            "%^BLACK%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^"+
            "l%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^ of "+
            "sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o"+
            "%^BOLD%^%^BLACK%^w lash out at you from "+caster->QCN+
            "%^BOLD%^%^BLACK%^!%^RESET%^");

            if(objectp(environment(caster)))
            {
                tell_room(environment(caster), "%^BOLD%^%^BLACK%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
                "%^BLACK%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^BLACK%^r%^BOLD%^%^WHITE%^"+
                "l%^BOLD%^%^BLACK%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^BLACK%^ of "+
                "sh%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^d%^BOLD%^%^WHITE%^o"+
                "%^BOLD%^%^BLACK%^w lash out at "+myVic->QCN+"%^BOLD%^%^BLACK%^ "+
                "from "+caster->QCN+"%^BOLD%^%^BLACK%^!%^RESET%^", ({caster, myVic}));
            }
            dam_type = "divine";
        }
        else if(myWay == "way of the elements")
        {
            dam_type = caster->query("monk_ele_focus");
            if(!stringp(dam_type)) dam_type = "fire";
            switch(dam_type)
            {
                case "cold":
                    tell_object(caster, "%^BOLD%^%^WHITE%^Sh%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^"+
                    "rds of Ic%^BOLD%^%^CYAN%^"+
                    "e%^BOLD%^%^WHITE%^ shoot out at "+myVic->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

                    tell_object(myVic, "%^BOLD%^%^WHITE%^Sh%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^"+
                    "rds of Ic%^BOLD%^%^CYAN%^"+
                    "e%^BOLD%^%^WHITE%^ shoot out at you from "+caster->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^BOLD%^%^WHITE%^Sh%^BOLD%^%^CYAN%^a%^BOLD%^%^WHITE%^"+
                        "rds of Ic%^BOLD%^%^CYAN%^"+
                        "e%^BOLD%^%^WHITE%^ shoot out at "+myVic->QCN+"%^BOLD%^%^WHITE%^ "+
                        "from "+caster->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ({caster, myVic}));
                    }
                    break;
                case "electricity":
                    tell_object(caster, "%^BOLD%^%^YELLOW%^Arcs of %^BOLD%^%^BLUE%^e%^YELLOW%^"+
                    "l%^BLUE%^e%^YELLOW%^ctr%^BLUE%^i%^YELLOW%^c%^BLUE%^i%^YELLOW%^ty %^YELLOW%^ "+
                    "jump from you to "+myVic->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^");

                    tell_object(myVic, "%^BOLD%^%^YELLOW%^Arcs of %^BOLD%^%^BLUE%^e%^YELLOW%^"+
                    "l%^BLUE%^e%^YELLOW%^ctr%^BLUE%^i%^YELLOW%^c%^BLUE%^i%^YELLOW%^ty %^YELLOW%^ "+
                    "jump to you from "+caster->QCN+"%^BOLD%^%^YELLOW%^!%^RESET%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^BOLD%^%^YELLOW%^Arcs of %^BOLD%^%^BLUE%^e%^YELLOW%^"+
                        "l%^BLUE%^e%^YELLOW%^ctr%^BLUE%^i%^YELLOW%^c%^BLUE%^i%^YELLOW%^ty%^YELLOW%^ "+
                        "jump to "+myVic->QCN+"%^BOLD%^%^YELLOW%^ from "+caster->QCN+
                        "%^YELLOW%^!%^RESET%^", ({caster, myVic}));
                    }
                    break;
                case "acid":
                    tell_object(caster, "%^BOLD%^%^GREEN%^An %^RESET%^%^GREEN%^a%^BOLD%^"+
                    "c%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c mist sprays "+
                    myVic->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^");

                    tell_object(myVic, "%^BOLD%^%^GREEN%^An %^RESET%^%^GREEN%^a%^BOLD%^"+
                    "c%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c mist from "+
                    caster->QCN+" sprays you!%^RESET%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^BOLD%^%^GREEN%^An %^RESET%^%^GREEN%^a%^BOLD%^"+
                        "c%^RESET%^%^GREEN%^i%^BOLD%^d%^RESET%^%^GREEN%^i%^BOLD%^c mist from "+
                        caster->QCN+"%^BOLD%^%^GREEN%^ sprays "+
                        myVic->QCN+"%^BOLD%^%^WHITE%^!%^RESET%^", ({caster, myVic}));
                    }
                    break;
                default:
                    tell_object(caster, "%^BOLD%^%^RED%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
                    "%^RED%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^"+
                    "i%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^l%^BOLD%^%^RED%^s of "+
                    "fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e"+
                    "%^BOLD%^%^RED%^ lash out at "+myVic->query_cap_name()+
                    "%^BOLD%^%^RED%^!%^RESET%^");

                    //mybonus = ((int)caster->query_class_level("monk")/10)+1;
                    //dam += roll_dice(mybonus,2);

                    tell_object(myVic, "%^BOLD%^%^RED%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
                    "%^RED%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^"+
                    "i%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^l%^BOLD%^%^RED%^s of "+
                    "fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e"+
                    "%^BOLD%^%^RED%^ lash out at you from "+caster->QCN+
                    "%^BOLD%^%^RED%^!%^RESET%^");

                    if(objectp(environment(caster)))
                    {
                        tell_room(environment(caster), "%^BOLD%^%^RED%^T%^BOLD%^%^WHITE%^e%^BOLD%^"+
                        "%^RED%^n%^BOLD%^%^WHITE%^d%^BOLD%^%^RED%^r%^BOLD%^%^WHITE%^"+
                        "l%^BOLD%^%^RED%^l%^BOLD%^%^WHITE%^s%^BOLD%^%^RED%^ of "+
                        "fl%^BOLD%^%^YELLOW%^a%^BOLD%^%^RED%^m%^BOLD%^%^YELLOW%^e"+
                        "%^BOLD%^%^RED%^ lash out at "+myVic->QCN+"%^BOLD%^%^RED%^ "+
                        "from "+caster->QCN+"%^BOLD%^%^RED%^!%^RESET%^", ({caster, myVic}));
                    }
                    break;
            }
        }
        myVic->cause_typed_damage(myVic, (string)myVic->return_target_limb(), dam, dam_type);
        return;
    }
    else
    {
        tell_object(caster, "%^BOLD%^%^WHITE%^You strike out at "+myVic->QCN+
        "%^BOLD%^%^WHITE%^ but miss your mark!%^RESET%^");
        tell_object(myVic, caster->QCN+"%^BOLD%^%^WHITE%^ strikes out at you, but "+
        "you manage to avoid the blow!%^RESET%^");
        if(objectp(environment(caster)))
        {
            tell_room(environment(caster), caster->QCN+"%^BOLD%^%^WHITE%^ strikes out at "+
            myVic->QCN+"%^BOLD%^%^WHITE%^ but misses "+caster->QP+" mark!%^RESET%^", ({caster, myVic}));
        }
    }
    return;
}

void check()
{
    object myFB, *weapons, myWeapon;
    int x, myDam;
    string myWay;
    if(!objectp(caster))
    {
        dest_effect();
        return;
    }
    if(!objectp(myFB = caster->query_property("flurry of blows")))
    {
        dest_effect();
        return;
    }
    if((int)caster->query_alignment() > 3)
    {
        myFB->dest_effect();
        dest_effect();
        return;
    }
    if(!(int)USER_D->can_spend_ki(caster, 1))
    {
        call_out("check",ROUND_LENGTH);
        return;
    }
    if(caster->query_bound() || caster->query_tripped() || caster->query_paralyzed())
    {
        call_out("check",ROUND_LENGTH);
        return;
    }
    if(caster->is_in_combat())
    {
        //only very rare chance of getting extra attacks when doing either - Saide
        myWay = (string)caster->query("monk way");
        if((int)caster->query_property("using instant feat") || caster->query_casting())
        {
            //higher chance of procs for way of the elements monks when casting or using another
            //feat
            if(myWay == "way of the elements" && random(3))
            {
                call_out("check", ROUND_LENGTH);
                return;
            }
            else if(random(10))
            {
                call_out("check",ROUND_LENGTH);
                return;
            }
        }
        weapons = (object *)caster->query_wielded();
        for(x = 0;x < sizeof(weapons);x++)
        {
            if(!objectp(weapons[x])) continue;
            //allow small weapons only - Saide
            if((int)weapons[x]->query_size() > 1)
            {
                call_out("check",ROUND_LENGTH);
                return;
            }
            continue;
        }
        if(!caster->is_ok_armour("barb"))
        {
            call_out("check",ROUND_LENGTH);
            return;
        }
        if(!(int)USER_D->can_spend_ki(caster, 1))
        {
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            return;
        }
        tell_object(caster, "%^BOLD%^%^CYAN%^You spot a weakness in your enemy's defense and "+
        "launch an attack!%^RESET%^");
        /*if(objectp(environment(caster)))
        {
            tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches an attack!%^RESET%^", caster);
        }*/
        flurry_hit();
        //redesigning so that extra hits are successful if
        //making a touch attack - do not use weapon at all - bare hands/tendrils
        //higher chance of second hit for way of the shadow monks with shadow opportunist feat
        if(FEATS_D->usable_feat(caster, "shadow opportunist"))
        {
            if(!random(2))
            {
                tell_object(caster, "%^BOLD%^%^CYAN%^You spot a weakness in your enemy's defense and "+
                "launch an attack!%^RESET%^");
                flurry_hit();
            }
        }
        else if(!random(6) && (int)caster->query_class_level("monk") >= 15)
        {
            tell_object(caster, "%^BOLD%^%^CYAN%^You spot a weakness in your enemy's defense and "+
            "launch an attack!%^RESET%^");
            /*if(objectp(environment(caster)))
            {
                tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^ launches an attack!%^RESET%^", caster);
            }*/
            flurry_hit();
        }
        caster->spend_ki(1);
        //making it simply not function when out of ki - Saide
        /* if(!(int)"/daemon/user_d.c"->can_spend_ki(caster, 1))
        {
            if(objectp(myFB)) myFB->dest_effect();
            dest_effect();
            return;
        }*/
    }
    call_out("check",ROUND_LENGTH);
    return;
}

void dest_effect()
{
    object myFB;
    if(!objectp(caster))
    {
        ::dest_effect();
        remove_feat(TO);
        return;
    }
    if(objectp(myFB = caster->query_property("flurry of blows")))
    {
        if(myFB == TO)
        {
            tell_object(caster, "%^BOLD%^%^CYAN%^Your focus suddenly wavers and returns to normal, your "+
            "uncanning ability to spot the weakness in the defenses of your enemies gone for now.%^RESET%^");
            if(objectp(environment(caster)))
            {
                tell_room(environment(caster), caster->QCN+"%^BOLD%^%^CYAN%^'s focus suddenly returns to "+
                "normal.%^RESET%^", caster);
            }
            caster->remove_property("flurry of blows");
        }
    }
    ::dest_effect();
    remove_feat(TO);
    return;
}
