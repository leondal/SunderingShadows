// new enchant_ob..  make a new one of these for each person who's enchanting something.
//adjust flat level calculation -- Yves 12/18
#include <std.h>
#include <daemons.h>
#include <valid_bonuses.h>
#include <dirs.h>

#define allowed_armor  ({ "stun","trip","heal","attack","repair","disarm","reflect","bleed","blind" })
#define allowed_weapon ({ "stun","trip","heal","attack","repair","poison","bleed","blind" })

#define restricted_skills ({ "craft, armorsmith", "craft, jeweller", "craft, leatherworker", "craft, weaponsmith", "craft, woodworker", "craft, tailor", "craft, leatherwork", "light", "fast healing", "spellTurning", "missChance" })

#define EXTRA_BONUSES ({ "enchantment","special" })

#define CRAFTING_CLASSES ({ "mage","warlock" }) // classes that are innate crafters get a bonus to their crafting DC check

inherit DAEMON;

int DEST_TIMER;


int clean_up()
{
    if(DEST_TIMER < 900) { return 1; }
    destruct(TO);
    return 1;
}


void create()
{
    ::create();
    clean_me();
}


void clean_me()
{
    DEST_TIMER++; // is set to 0 anytime the menu is used, this is just a failsafe basically
    if(DEST_TIMER > 900)
    {
        destruct(TO);
        return;
    }
    call_out("clean_me",1);
    return;
}


void db(object ob, string str)
{
    if(!objectp(ob)) { return; }
    tell_object(ob,str);
}


// this function will need updating if we change the way that player crafted items work
int check_player_crafted(object obj)
{
    string info;
    int length;

    if(!objectp(obj)) { return 0; }
    if(strsrch(base_name(obj),"/d/players") == -1) { return 0; }

    info = obj->query("long");
    length = strlen(info);
    info = info[(length-13)..(length-1)];

    if(info != "Mastercrafted") { return 0; }

    if(obj->query_property("enchantment") && !obj->query_property("player enchanted")) { return 0; } // don't let them use other means to enchant their item, like the enchanter on tonerra, etc

    return 1;
}


varargs int calculate_cost(object tp, object item, string bonus, int amt, string special)
{
    int i, *values = ({}), total, num, flat_level;
    mapping bonuses;
    string *bonus_names,*specials=({}),tmp;

    if(amt < 0) { return to_int(pow(2,32)); }

    if(bonus && bonus == "enchantment")
    {
        flat_level = (item->query_property("enchantment") + amt) * 7;
    }
    else
    {
        flat_level = item->query_property("enchantment") * 7;
    }

    if(flat_level < 0) flat_level = flat_level * -1;

    bonuses = item->query_item_bonuses();
    if(sizeof(keys(bonuses))) { bonus_names = keys(bonuses); }

    for(i=0;sizeof(bonus_names),i<sizeof(bonus_names);i++)
    {
        if(bonus && bonus_names[i] == bonus)
        {
            num = CHECK_D->get_bonus_value(bonus_names[i], bonuses[bonus_names[i]] + amt, item, tp);
        }
        else
        {
            num = CHECK_D->get_bonus_value(bonus_names[i], bonuses[bonus_names[i]], item, tp);
        }
        values += ({ num });
    }

    values += ({ flat_level });

    if(item->query_property("hit")) { tmp = item->query_property("hit"); }
    if(item->query_property("struck")) { tmp = item->query_property("struck"); }
    if(tmp) { specials = explode(tmp, ", "); }

    // so weapons/armor with hit and struck functions disenchant for correct amount
    if(item->query_hit() && !item->query_property("hit"))       { specials += ({ "hit special" }); }
    if(item->query_struck() && !item->query_property("struck")) { specials += ({ "struck special" }); }
    if(item->query_lrhit() && !item->query_property("hit"))     { specials += ({ "lrhit special" }); }
    ////

    for(i=0;sizeof(specials),i<sizeof(specials);i++)
    {
        num = flat_level;
        if(item->is_armor()) { num = to_int(flat_level * 1.3); }
        values += ({ num });
    }

    if(stringp(special))
    {
        num = flat_level;
        if(item->is_armor()) { num = to_int(flat_level * 1.3); }
        values += ({ num });
    }

    for(i=0;sizeof(values),i<sizeof(values);i++)
    {
        total += values[i];
    }

    return to_int(pow(total,2.2)); // will probably have to do some adjusting here
}


int use_materials(object tp, int amt)
{
    object *inv;
    int i, count, needed;

    if(!objectp(tp)) { return 0; }
    if(avatarp(tp)) { return 1; }

    if(amt < 0) { return 0; }

    if(!check_materials(tp,amt)) { return 0; }

    inv = all_inventory(tp);
    needed = amt;

    // they should have enough if they made it past check_materials
    // but they might be in multiple boxes
    for(i=0;sizeof(inv),i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(!inv[i]->is_enchanting_material()) { continue; }
        count = inv[i]->query_count();
        if(count >= needed)
        {
            inv[i]->add_count(-1 * needed);
            break;
        }
        needed -= count;
        inv[i]->add_count(-1 * count);
    }

    tell_object(tp,"%^RESET%^%^BOLD%^%^GREEN%^Using %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+" %^RESET%^%^BOLD%^%^GREEN%^crafting materials.\n");

    return 1;
}


int check_materials(object tp,int amt)
{
    object *inv;
    int i, count;

    if(!objectp(tp)) { return 0; }
    if(avatarp(tp)) { return 1; }

    if(amt < 0) { return 0; }

    inv = all_inventory(tp);

    for(i=0;sizeof(inv),i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) { continue; }
        if(!inv[i]->is_enchanting_material()) { continue; }
        count += inv[i]->query_count();
    }

    if(count < amt)
    {
        db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^You don't seem to have enough enchanting materials for that.  You "
                "only seem to have %^RESET%^%^BOLD%^%^MAGENTA%^"+count+"%^RESET%^%^BOLD%^%^YELLOW%^, but you "
                "need %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+"%^RESET%^%^BOLD%^%^YELLOW%^.\n");
        return 0;
    }

    return 1;
}



int bonus_allowed(object tp, object item, string bonus, int amt)
{
    mapping bonuses;
    string *bonus_names,*files,*specials=({});
    int i, total, value, flat_level;

    if(!objectp(tp) || !objectp(item)) { return 0; }

    if(bonus != "special" && bonus != "enchantment")
    {
        if(member_array(bonus,VALID_BONUSES) == -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^The bonus %^RESET%^%^BOLD%^%^MAGENTA%^"+bonus+"%^RESET%^%^BOLD%^%^YELLOW%^ appears to be "
                    "invalid.  If you think this is wrong please notify a wiz.\n"
                    );
            return 0;
        }
        if(member_array(bonus,restricted_skills) != -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^The following skills have been restricted and can no longer be crafted "
                    "on items: %^RESET%^%^BOLD%^%^MAGENTA%^"+implode(restricted_skills," - ")+"\n"
                    );
            return 0;
        }
    }

    if(bonus == "shieldMiss")
    {
        if(item->query_type() != "shield")
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^You can only enchant shields with the %^RESET%^%^BOLD%^%^MAGENTA%^shieldMiss%^RESET%^%^BOLD%^%^YELLOW%^ bonus, your "
                    ""+item->query_short()+" %^RESET%^%^BOLD%^%^YELLOW%^appears to be a %^RESET%^%^BOLD%^%^MAGENTA%^"+item->query_type()+"%^RESET%^%^BOLD%^%^YELLOW%^ instead.\n"
                    );
            return 0;
        }
    }

    if(!CHECK_D->valid_limb_check(item,tp))
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^Your "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^ appears to have invalid limbs set, please contact a wiz.\n"
                );
        return 0;
    }

    if(item->is_instrument() || item->is_ammo())
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^You are not allowed to enchant instruments or ammo.\n"
                );
        return 0;
    }


    files = deep_inherit_list(item);
    for(i=0;sizeof(files),i<sizeof(files);i++)
    {
        if(strsrch(files[i],"/d/common/obj/sheath/") != -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^Sorry, you are not allowed to enchant sheaths.\n"
                    );
            return 0;
        }
        if(strsrch(files[i],"/d/common/obj/misc/carving") != -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^You are not allowed to enchant carvings.\n"
                    );
            return 0;
        }
    }


    bonuses = copy(item->query_item_bonuses());
    bonus_names = keys(bonuses);

    if(bonus && bonus == "enchantment")
    {
        flat_level = (item->query_property("enchantment") + amt) * 7;
    }
    else
    {
        flat_level = item->query_property("enchantment") * 7;
    }

    if(bonus == "enchantment" && flat_level > (tp->query_base_character_level() - 7))
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^You can't create an item with an enchantment that high.  The max level enchantment that "
                "you can create is %^RESET%^%^BOLD%^%^MAGENTA%^"+((tp->query_base_character_level() - 7) / 7)+"%^RESET%^%^BOLD%^%^YELLOW%^.\n"
                );
        return 0;
    }

    if(item->query_property("hit") || item->query_property("struck"))
    {
        bonuses += ([ "special" : flat_level ]);
    }

    bonuses += ([ "enchantment" : flat_level ]);
    bonus_names = keys(bonuses);

    // if they're already at the max amount of bonuses, they could still add another 'type' of special,
    // like if they have a damage special, they could add a stun special too
    if(sizeof(bonus_names) >= 3)
    {
        if(member_array(bonus,bonus_names) == -1 || (member_array(bonus,bonus_names) >= 0 && bonus == "special"))
        {
            if(!avatarp(tp) || sizeof(bonus_names) >= 3)
            {
                db(tp,
                        "%^RESET%^%^BOLD%^%^YELLOW%^No item can have more than three different "
                        "bonuses.  A weapon or armor special counts as one bonus, and the magical "
                        "property of the item also counts as a bonus.  For example, "
                        "a +1 sword with a +1 sight bonus counts as two bonuses.\n"
                        );
                return 0;
            }
        }
    }

    if(!sizeof(bonus_names) || member_array(bonus,bonus_names) == -1)
    {
        if(bonus == "special" || bonus == "enchantment")
        {
            value = flat_level;
        }
        else
        {
            value = CHECK_D->get_bonus_value(bonus, amt, item, tp);
        }
    }
    else
    {
        if(bonus == "special" || bonus == "enchantment")
        {
            value = flat_level;
        }
        else
        {
            value = CHECK_D->get_bonus_value(bonus, bonuses[bonus] + amt, item, tp);
        }
    }

    if(flat_level == 0 && bonus != "enchantment")
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^Your item is not yet enchanted. %^RESET%^%^BOLD%^%^MAGENTA%^(+'s)%^RESET%^%^BOLD%^%^YELLOW%^  %^RESET%^%^BOLD%^%^YELLOW%^The first thing that you "
                "must do to enchant an item is increase it's base %^RESET%^%^BOLD%^%^MAGENTA%^enchantment%^RESET%^%^BOLD%^%^YELLOW%^ property to make it magical enough "
                "to hold the properties that you wish to put on it.\n"
                "%^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM %^RESET%^%^BOLD%^%^GREEN%^1 enchantment\n"
                );
        return 0;
    }


    if(value > flat_level)
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^A %^RESET%^%^BOLD%^%^MAGENTA%^"+bonus+" %^RESET%^%^BOLD%^%^YELLOW%^bonus "
                "of %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+" %^RESET%^%^BOLD%^%^YELLOW%^would require a base item level "
                "of %^RESET%^%^BOLD%^%^MAGENTA%^"+value+"%^RESET%^%^BOLD%^%^YELLOW%^.  The item you "
                "are trying to add the bonus to is only level "
                "%^RESET%^%^BOLD%^%^MAGENTA%^"+flat_level+"%^RESET%^%^BOLD%^%^YELLOW%^.  This level is determined by "
                "the item's base enchantment level.  You must increase its base enchantment first.\n"
                );
        return 0;
    }

    return 1;
}


int special_allowed(object tp, object item, mapping special_info)
{
    string type, *specials;

    if(!objectp(tp) || !objectp(item)) { return 0; }

    type = special_info["type"];
    if(!type)
    {
        db(tp,
                "%^B_RED%^%^BOLD%^%^CYAN%^You don't seem to have a special type set, please contact a wiz.%^RESET%^"
                );
        return 0;
    }

    if(!item->query_property("enchantment"))
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^Only magical items can be enchanted to have specials.  To encahnt your "
                ""+item->query_short()+" please use %^RESET%^%^BOLD%^%^GREEN%^enchant "
                "%^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT \"enchantment\"%^RESET%^\n"
                );
        return 0;
    }

    if(item->is_armor())
    {
        if(member_array(type, allowed_armor) == -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^A %^RESET%^%^BOLD%^%^MAGENTA%^"+type+" %^RESET%^%^BOLD%^%^YELLOW%^bonus "
                    "is not allowed for armors, only the following specials are allowed for armors: \n"
                    "    %^RESET%^%^BOLD%^%^MAGENTA%^"+implode(allowed_armor,", ")+".\n"
                    );
            return 0;
        }
        if(item->query_property("struck")) { specials = explode(item->query_property("struck"),", "); }
        if(sizeof(specials))
        {
            if(member_array(type, specials) != -1)
            {
                db(tp,
                        "Your "+item->query_short()+" already seems to have a "+type+" specials.  You can have more "
                        "than one special on an item, but they must be different types of specials.\n"
                        );
                return 0;
            }
        }
    }
    if(item->is_weapon())
    {
        if(member_array(type, allowed_weapon) == -1)
        {
            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^A %^RESET%^%^BOLD%^%^MAGENTA%^"+type+" %^RESET%^%^BOLD%^%^YELLOW%^bonus "
                    "is not allowed for weapons, only the following specials are allowed for weapons:\n"
                    "    %^RESET%^%^BOLD%^%^MAGENTA%^"+implode(allowed_weapon,", ")+".\n"
                    );
            return 0;
        }
        if(item->query_property("hit")) { specials = explode(item->query_property("hit"),", "); }
        if(sizeof(specials))
        {
            if(member_array(type, specials) != -1)
            {
                db(tp,
                        "Your "+item->query_short()+" already seems to have a "+type+" specials.  You can have more "
                        "than one special on an item, but they must be different types of specials.\n"
                        );
                return 0;
            }
        }
    }

    if(!sizeof(specials)) { return 1; }

    if(member_array(type,specials) != -1)
    {
        db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^Your "+item->query_short()+" %^RESET%^%^BOLD%^%^YELLOW%^already "
                "has a %^RESET%^%^BOLD%^%^MAGENTA%^"+type+" %^RESET%^%^BOLD%^%^YELLOW%^special, and "
                "can't have another of the same type.\n"
                );
        return 0;
    }

    return 1;
}


void detail_log(object tp, object item)
{
    mapping bonuses;
    string specials, display;
    int num;

    if(!objectp(tp) || !objectp(item)) { return; }


    bonuses = item->query_item_bonuses();
    num = item->query_property("enchantment");
    if(!num) { num = "no enchantment"; }
    if(item->is_armor()) { specials = item->query_property("struck"); }
    else { specials = item->query_property("hit"); }

    display  = ""+tp->query_true_name()+"'s "+base_name(item)+" now has the following: \n";

    display += "enchantment: "+num+"\n";

    if(bonuses)
    {
        display += "item bonuses: "+identify(bonuses)+"\n";
    }

    if(specials)
    {
        display += "specials: "+specials+"\n";
    }

    display += "\n";

    return;
}


int do_exp_cost(object tp, object item, int cost)
{
    int exp_cost;

    if(!objectp(tp) || !objectp(item)) { return 0; }
    if(avatarp(tp)) { return 1; }
    if(!cost) { return 0; }

    exp_cost = cost * (10 * (tp->query_base_character_level() / 2));  // might need some tweaking here.

    if((int)"/daemon/config_d.c"->check_config("character improvement") == 0)
    {
        db(tp,"\n%^RESET%^%^BOLD%^%^YELLOW%^Subtracting %^RESET%^%^BOLD%^%^MAGENTA%^"+exp_cost+"%^RESET%^%^BOLD%^%^YELLOW%^ "
            "experience points to enchant your "+item->query_short()+"\n");
        tp->add_exp(exp_cost * -1);
    }
    else if((int)"/daemon/config_d.c"->check_config("character improvement") == 1)
    {
        if((int)tp->set_XP_tax(exp_cost, 0, "improvement") == -1)
        {
            db(tp,
                "%^RESET%^%^BOLD%^%^YELLOW%^You don't have enough exp left to spend to enchant your "
                ""+item->query_short()+".  It would require %^RESET%^%^BOLD%^%^MAGENTA%^"+exp_cost+" "
                "%^RESET%^%^BOLD%^%^YELLOW%^experience points.\n"
                );
            return 0;
        }

        db(tp,"\n%^RESET%^%^BOLD%^%^YELLOW%^Adding tax of %^RESET%^%^BOLD%^%^MAGENTA%^"+exp_cost+"%^RESET%^%^BOLD%^%^YELLOW%^ "
            "experience points to enchant your "+item->query_short()+"\n");

    }

    return 1;
}


void do_ring_of_protection_stuff(object tp, object item)
{
    if(!objectp(tp) || !objectp(item)) { return; }

// this isn't necessary, & likely to cause issues. Lib checks on wear both for rops and for generally enchanted hand items,
// but any 'ring' (jewelry) type on another slot should be able to stack within standard limitations of equipment. N, 11/17.
/*    if(item->query_type() == "ring" && !item->id("ring of protection"))
    {
        item->add_id("ring of protection");
    } */
    return;
}


void do_add_bonus(object tp, object item, string bonus, int amt, int cost)
{
    string *bonus_names, bonuses;
    object etp;
    int total, value, flat_level, current, DC;

    if(!objectp(tp)) { return; }
    etp = environment(tp);

    if(!objectp(item))
    {
        db(tp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^It seems that the item you were trying to enchant has gone missing.%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^"+tp->QCN+" looks around as if "+tp->QS+" is missing something.%^RESET%^",tp);
        return;
    }

    bonuses = item->query_item_bonuses();
    bonus_names = keys(bonuses);

    flat_level = item->query_property("enchantment") * 7;

    DC = item->query_property("enchantment") * 5;
    DC += 3; // 3 DC for this bonus
    if(item->query_property("hit")) { DC += 3; } // 3 DC if item already has hit special
    if(item->query_property("struck")) { DC += 3; } // 3 DC if item already has struck special
    if(item->query_item_bonuses()) { DC += 3; } // 3 DC is item already has a bonus

    if(!skill_check(tp, item, DC, cost)) { return; }

    if(check_materials(tp,cost)) // lets make sure they have enough mats before we charge them exp
    {
        if(!do_exp_cost(tp,item,cost)) { return; }
    }

    if(!use_materials(tp,cost))
    {
        db(tp,"\n\n%^RESET%^%^BOLD%^Well this is strange, your materials aren't there anymore.  You know "
            "you had them before.. where did they go?%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^"+tp->QCN+" seems suddenly alarmed.",tp);
        return;
    }

    if(!sizeof(bonus_names) || member_array(bonus,bonus_names) == -1)
    {
        item->set_item_bonus(bonus,amt);
    }
    else
    {
        current = to_int(bonuses[bonus]);
        current += amt;

        item->set_item_bonus(bonus, current);
    }

    do_ring_of_protection_stuff(tp, item);

    detail_log(tp,item);

    item->set_property("player enchanted",1); // exclude other means of increasing enchantment if this is set

    db(tp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^You finish with your enchanting, "
        "adding a %^RESET%^%^BOLD%^%^MAGENTA%^"+bonus+"%^RESET%^%^BOLD%^%^YELLOW%^ "
        "of %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+" %^RESET%^%^BOLD%^%^YELLOW%^to your "+item->query_short());

    tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" seems drained after "
        "finishing with "+tp->QP+" "+item->query_short(),tp);

    destruct(TO);
    return;
}


void do_add_enchantment(object tp, object item, string bonus, int amt, int cost)
{
    object etp;
    int flat_level, DC;

    if(!objectp(tp)) { return; }
    etp = environment(tp);

    if(!objectp(item))
    {
        db(tp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^The item you were trying to enchant has gone missing.%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^"+tp->QCN+" looks around as if "+tp->QS+" is missing something.",tp);
        return;
    }

    flat_level = item->query_property("enchantment");
    flat_level += amt;
    DC = flat_level * 5; // cost to increase enchantment is just 5 per enchantment, since it's the first on the item.
    flat_level = flat_level * 7;

    if(!skill_check(tp, item, DC, cost)) { return; }

    if(check_materials(tp,cost)) // lets make sure they have enough mats before we charge them exp
    {
        if(!do_exp_cost(tp,item,cost)) { return; }
    }

    if(!use_materials(tp,cost))
    {
        db(tp,"\n\n%^RESET%^%^BOLD%^Well this is strange, your materials aren't there anymore.  You know "
            "you had them before.. where did they go?%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^"+tp->QCN+" seems suddenly alarmed.",tp);
        return;
    }

    item->set_property("no curse",1);
    item->set_property("enchantment",amt);
    item->set_property("player enchanted",1); // want to exclude other means of increasing enchantment if this is set
    item->set_property("no curse",-1);


    do_ring_of_protection_stuff(tp, item);

    detail_log(tp,item);

    db(tp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^You finish adding %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+" "
        "%^RESET%^%^BOLD%^%^YELLOW%^enchantment to your %^RESET%^%^BOLD%^%^MAGENTA%^"+item->query_short());

    tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" seems drained after "
        "finishing with "+tp->QP+" "+item->query_short(),tp);

    destruct(TO);
    return;
}


void do_add_special(object tp, object item, string bonus, int amt, int cost, mapping special_info)
{
    mapping messages = ([]);
    object etp;
    string special, type, property;
    int flat_level,DC;

    if(!objectp(tp)) { return; }
    etp = environment(tp);

    if(!objectp(item))
    {
        db(tp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^It seems that the item you were trying to enchant has gone missing.%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^"+tp->QCN+" looks around as if "+tp->QS+" is missing something.%^RESET%^",tp);
        return;
    }

    flat_level = item->query_property("enchantment") * 7;

    DC = item->query_property("enchantment") * 5;
    DC += 3; // 3 DC for this special
    if(item->query_item_bonuses()) { DC += 3; } // another 3 DC if it already has bonuses

    if(!skill_check(tp, item, DC, cost)) { return; }

    if(check_materials(tp,cost)) // lets make sure they have enough mats before we charge them exp
    {
        if(!do_exp_cost(tp,item,cost)) { return; }
    }

    if(!use_materials(tp,cost))
    {
        db(tp,"\n\n%^RESET%^%^BOLD%^Well this is strange, your materials aren't there anymore.  You know "
            "you had them before.. where did they go?%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^"+tp->QCN+" seems suddenly alarmed.",tp);
        return;
    }

    special = special_info["special"];
    type = special_info["type"];

    if(special_info["user message"] && special_info["target message"] && special_info["room message"])
    {
        messages["user"] = special_info["user message"];
        messages["target"] = special_info["target message"];
        messages["room"] = special_info["room message"];
    }

    if(!item->query_property(special))
    {
        item->set_property(special,type);
    }
    else
    {
        item->set_property(special, ", "+type);
    }

    if(sizeof(keys(messages)))
    {
        item->set_property(type+" message",messages);

    }

    do_ring_of_protection_stuff(tp, item);

    detail_log(tp,item);

    item->set_property("player enchanted",1);

    db(tp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^You finish adding a %^RESET%^%^BOLD%^%^MAGENTA%^"+type+" "
        "%^RESET%^%^BOLD%^%^YELLOW%^special to your "+item->query_short());

    tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" seems drained after finishing "
        "with "+tp->QP+" "+item->query_short(),tp);

    destruct(TO);
    return;
}



varargs int skill_check(object tp, object item, int DC, int cost, int flag)
{
    object etp,*inv,class_ob;
    string skill_name, *skill_names = ({});
    string repair_type, *repair_types;
    int skill,roll, max_cost, i, count, needed,*classes;


    if (cost < 0) {
        return 0;
    }
    if (!objectp(tp)) {
        return 0;
    }
    if (avatarp(tp)) {
        return 1;
    }

    etp = environment(tp);
    if (!objectp(etp)) {
        return 0;
    }

    if (!objectp(item)) {
        db(tp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^It seems that the item you were trying to enchant has gone missing.%^RESET%^");
        tell_room(etp, "\n\n%^RESET%^%^BOLD%^%^CYAN%^" + tp->QCN + " looks around as if " + tp->QS + " is missing something.%^RESET%^", tp);
        return;
    }

    repair_types = item->query_property("repairtype");

    if (!sizeof(repair_types)) {
        switch (item->query_type()) {
        case "clothing":
            skill_names += ({ "craft, tailor" });
            break;
        case "bracer": case "ring":
            skill_names += ({"craft, jeweller"});
            break;
        case "chain": case "armour": case "shield": case "armor": case "plate":
            skill_names += ({ "craft, armorsmith" });
            break;
        case "leather": case "thiefshield":
            skill_names += ({ "craft, leatherworker" });
            break;
        case "wood":
            skill_names += ({ "craft, woodworker" });
            break;
        }
    } else{
        foreach(repair_type in repair_types)
        {
            switch (repair_type) {
            case "tailor":
                skill_names += ({ "craft, tailor" });
                break;
            case "woodwork":
                skill_names += ({ "craft, woodworker" });
                break;
            case "leatherwork":
                skill_names += ({ "craft, leatherworker" });
                break;
            case "jewel":
                skill_names += ({ "craft, jeweller" });
                break;
            case "armorsmith":
                skill_names += ({ "craft, armorsmith" });
                break;
            }
        }
    }

    if (item->is_weapon()) {
        skill_names += ({ "craft, weaponsmith" });
    }

    if (!sizeof(skill_names)) {
        db(tp, "\n\n%^YELLOW%^Your " + item->query_short() + " %^YELLOW%^appears to have an invalid %^RESET%^%^BOLD%^%^MAGENTA%^type%^YELLOW%^, please contact a wiz.");
        return 0;
    }

    skill = max(map_array(skill_names, (:$2->query_skill($1):), tp));

    classes = tp->query_classes();

    for (i = 0; sizeof(classes), i < sizeof(classes); i++) {
        class_ob = find_object_or_load(DIR_CLASSES + "/" + classes[i] + ".c");
        if (!objectp(class_ob)) {
            continue;
        }
        if (class_ob->is_prestige_class()) {
            continue;
        }
        if (member_array(classes[i], CRAFTING_CLASSES) == -1) {
            continue;
        }
        skill += tp->query_prestige_level(classes[i]) / 15;     // max bonus is +3 from mage or warlock levels at level 45
    }

    roll = roll_dice(1,20);
    if(roll == 20) { return 1; }

    skill = skill + roll;

    if(flag) // external check, used for disenchanting, unsure if we need fail/pass messages for that
    {
        if(roll == 1 || (DC > skill)) { return 0; }
        return 1;
    }

    if(roll == 1 || (DC > skill))
    {
        db(tp,"\n\n%^RESET%^%^BOLD%^%^RED%^You curse the Lord of Hell's hairy arse as the enchantment fails, ruining "
            "some of your materials!");
        tell_room(etp,"\n%^RED%^"+tp->QCN+" curses the Lord of Hell's hairy arse!");

        cost = cost / 8;
        cost += roll_dice(1,cost);

        inv = all_inventory(tp);
        needed = cost;

        for(i=0;sizeof(inv),i<sizeof(inv);i++)
        {
            if(!objectp(inv[i])) { continue; }
            if(!inv[i]->is_enchanting_material()) { continue; }
            count = inv[i]->query_count();
            if(count >= needed)
            {
                inv[i]->add_count(-1 * needed);
                break;
            }
            needed -= count;
            inv[i]->add_count(-1 * count);
        }

        tell_object(tp,"%^RESET%^%^BOLD%^%^MAGENTA%^"+cost+" %^RESET%^%^BOLD%^%^GREEN%^materials wasted!");

        return 0;
    }
    return 1;
}

varargs void add_bonus(object tp, object item, string bonus, int amt, mapping special_info)
{
    mapping info=([]);
    int cost;

    if(!objectp(tp) || !objectp(item)) { return; }

    cost = calculate_cost(tp,item,bonus,amt);

    if(!check_materials(tp,cost)) { return; }

    if(!bonus_allowed(tp,item,bonus,amt)) { return; }

    if(bonus == "special" && !special_allowed(tp,item,special_info)) { return; }

    info["tp"] = tp;
    info["item"] = item;
    info["bonus"] = bonus;
    info["amt"] = amt;
    info["count"] = 0;
    info["cost"] = cost;
    info["special info"] = special_info;

    if(bonus == "special")
    {
        info["type"] = "special";
    }
    else if(bonus == "enchantment")
    {
        info["type"] = "enchantment";
    }
    else
    {
        info["type"] = "bonus";
    }

    play_crafting_reel(info);
    return;
}


varargs void enchant_item(object tp, object item, string bonus, int amt, mapping special_info)
{
    if(!objectp(tp)) { return 0; }
    if(!objectp(item))
    {
        db(tp,"Not a valid item.");
        return 0;
    }
    if(member_array(bonus, VALID_BONUSES + EXTRA_BONUSES) == -1)
    {
        db(tp,"Not a valid bonus.");
        return 0;
    }
    if(!bonus)
    {
        db(tp,"Not a valid bonus.");
        return 0;
    }

    if(!amt) { amt = 1; }

    if(!check_player_crafted(item))
    {
        db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^Can only enchant base mastercrafted items made by players, if your item was "
            "previously enchanted at an enchanter then it can no longer be enchanted via crafting magical objects.");
        return 0;
    }

    switch(bonus)
    {
    case "enchantment":

        add_bonus(tp,item,bonus,amt);
        break;

    case "special":

        add_bonus(tp,item,bonus,amt,special_info);
        break;

    default:

        add_bonus(tp,item,bonus,amt);
        break;
    }

    return;
}


void play_crafting_reel(mapping info)
{
    mapping special_info;
    object tp, item, etp;
    int count, cost, max_count, amt;
    string type, bonus;



    type    = info["type"];
    count   = info["count"];
    cost    = info["cost"];
    tp      = info["tp"];
    item    = info["item"];
    bonus   = info["bonus"];
    amt     = info["amt"];
    special_info = info["special info"];

    if(!objectp(tp)) { return; }

    etp = environment(tp);
    if(!info["start room"]) { info["start room"] = etp; }
    if(etp != info["start room"])
    {
        db(tp,"%^RED%^Movement causes the enchantment to fail...");
        destruct(TO);
        return;
    }

    max_count = cost / 100;
    if(max_count < 4) { max_count = 10; }
    if(max_count > 20) { max_count = 20; }

    info["max count"] = max_count;

    if(doing_check(tp))
    {
        db(tp,"%^RED%^You start doing something else and stop enchanting...");
        destruct(TO);
        return;
    }

    if(!avatarp(tp))
    {


        switch(random(5))
        {
        case 0:

            tell_room(etp, "%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^temperature %^BOLD%^%^BLACK%^of the air fluctuates "
                "and shifts %^RESET%^erratically %^BOLD%^%^BLACK%^as "+tp->QCN+" draws power from "+tp->QP+" surroundings..%^RESET%^\n",tp);
            tell_object(tp, "%^BOLD%^%^BLACK%^The %^RESET%^%^CYAN%^temperature %^BOLD%^%^BLACK%^of the air fluctuates and "
                "shifts %^RESET%^erratically %^BOLD%^%^BLACK%^as you draw power to yourself, focusing it on "+item->query_short()+".%^RESET%^\n");
            break;

        case 1:

            tell_room(etp, "%^BOLD%^%^BLACK%^Eyes cast downward in concentration, "+tp->QCN+" traces strange runes in the air "
                "while m%^RESET%^ur%^BOLD%^%^BLACK%^m%^RESET%^u%^BOLD%^%^BLACK%^ri%^RESET%^n%^BOLD%^%^BLACK%^g %^RESET%^powerful "
                "%^BOLD%^%^BLACK%^words of %^RESET%^%^CYAN%^binding%^BOLD%^%^BLACK%^.%^RESET%^\n",tp);
            tell_object(tp, "%^BOLD%^%^BLACK%^Concentrating deeply, you carefully %^RESET%^weave %^BOLD%^%^BLACK%^your "
                "spell, tracing its familiar patterns in the air.%^RESET%^\n");
            break;

        case 2:

            tell_room(etp, "%^MAGENTA%^A %^CYAN%^s%^GREEN%^t%^CYAN%^ra%^ORANGE%^n%^GREEN%^g%^CYAN%^e %^MAGENTA%^noise, "
                "like %^WHITE%^glass %^MAGENTA%^pushed to the edge of breaking, %^BOLD%^%^BLACK%^r%^RESET%^i"
                "p%^BOLD%^%^BLACK%^pl%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^through the room.%^WHITE%^\n");
            break;

        case 3:

            tell_room(etp, "%^BOLD%^%^BLACK%^Closing "+tp->QCN+" eyes in concentration, "+tp->QP+" voice %^RESET%^rises "
                "%^BOLD%^%^BLACK%^and %^RESET%^falls %^BOLD%^%^BLACK%^in a r%^RESET%^h%^BOLD%^%^BLACK%^yth%^RESET%^m"
                "i%^BOLD%^%^BLACK%^c, m%^RESET%^%^MAGENTA%^es%^WHITE%^m%^BOLD%^%^BLACK%^eri%^RESET%^%^MAGENTA%^zi"
                "n%^BOLD%^%^BLACK%^g mantra.%^RESET%^\n",tp);
            tell_object(tp, "%^BOLD%^%^BLACK%^You close your eyes and chant, feeling the %^MAGENTA%^p%^RESET%^%^MAGENTA%^o%^BOLD%^w"
                "er %^BLACK%^within you grow quickly...%^RESET%^\n");
            break;

        case 4:

            tell_room(etp, "%^BOLD%^%^BLACK%^Strange, %^GREEN%^gl%^RESET%^%^GREEN%^o%^BOLD%^wing symb%^RESET%^%^GREEN%^o%^BOLD%^l"
                "s %^BLACK%^appear on the item as "+tp->QCN+" traces "+tp->QP+" fingers along its surface.%^RESET%^\n",tp);
            tell_object(tp, "%^BOLD%^%^BLACK%^You %^RESET%^%^GREEN%^confidently %^BOLD%^%^BLACK%^trace your fingers along "
                "the surface of the "+item->query_short()+", enthralled by the symbols that %^GREEN%^flare %^BLACK%^to "
                "life beneath your touch.%^RESET%^\n");
            break;

        default:
            break;
        }


        if(count < max_count)
        {
            count++;
            info["count"] = count;
            call_out("play_crafting_reel", 2.5, info);
            return;
        }
    }

    switch(type)
    {
    case "enchantment":
        do_add_enchantment(tp, item, bonus, amt, cost);
        return;

    case "special":
        do_add_special(tp, item, bonus, amt, cost, special_info);
        return;

    default:
        do_add_bonus(tp, item, bonus, amt, cost);
        return;
    }

    return;
}


int enchanting_menu(string str, mapping map)
{
    mapping special_info = ([]);
    object etp, tp, item;
    string choice, *info=({}), thing, type,special, message;
    int amt, cost, i;

    if(map && mapp(map) && sizeof(keys(map)))
    {
        if(objectp(map["tp"])) { tp = map["tp"]; }
    }

    if(!objectp(tp))
    {
        if(objectp(TP))
        {
            tp = TP;
            if(!mapp(map)) { map = ([]); }
            map["tp"] = tp;
        }
    }

    if(!objectp(tp))
    {
        destruct(TO);
        return 0;
    }

    etp = environment(tp);
    if(!map["start room"]) { map["start room"] = etp; }
    if(map["start room"] != etp)
    {
        db(tp,"%^RED%^Movement causes your enchanting to fail...");
        destruct(TO);
        return 1;
    }

    DEST_TIMER = 0;

    if(!str) { choice = "default"; }
    else { choice = str; }
    info = explode(choice," ");
    if(!sizeof(info)) { info = ({ "default" }); }
    choice = lower_case(choice);

    info[0] = lower_case(info[0]);

    switch(info[0])
    {
        case "exit":
        case "q":

            db(tp,"%^RESET%^%^BOLD%^%^GREEN%^\nExiting menu...\n%^RESET%^");
            destruct(TO);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "list":

            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^The following bonuses are available for enchanting an item: \n\n"

                    ""+sort_valid_bonuses()+"\n\n"

// please remove this blurb once temp feats are back in.
                    "%^RESET%^%^BOLD%^%^YELLOW%^In addition, you are also able to increase the base "
                    "%^RESET%^%^BOLD%^%^GREEN%^enchantment %^RESET%^%^BOLD%^%^YELLOW%^of an item.  You "
                    "are also able to give an item specials.\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^Armors are allowed the following specials : \n%^RESET%^%^BOLD%^%^GREEN%^"+implode(allowed_armor,", ")+"\n\n"
                    "%^RESET%^%^BOLD%^%^YELLOW%^Weapons are allowed the following specials : \n%^RESET%^%^BOLD%^%^GREEN%^"+implode(allowed_weapon,", ")+".\n"
                    );

            input_to("enchanting_menu",map);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "cost":

            if(sscanf(str,"cost %s %d %special %s", thing, amt, type, special) != 4)
            {
                if(type != "special" && sscanf(str, "cost %s %d %s", thing, amt, type) != 3)
                {
                    db(tp,
                            "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: cost %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT TYPE  \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^cost bracers 2 attack bonus \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^cost bracers 1 enchantment \n\n"
                            "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: cost %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT%^RESET%^%^BOLD%^%^YELLOW%^ special %^RESET%^%^BOLD%^%^MAGENTA%^TYPE \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^cost sword 1 special stun\n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^cost bracers 1 special bleed\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }
            }

            if(!objectp(item = present(thing, tp)))
            {
                db(tp,
                        "%^RESET%^%^BOLD%^%^YELLOW%^Can't find "+thing+" %^RESET%^%^BOLD%^%^YELLOW%^please make sure it's the first "+thing+" %^RESET%^%^BOLD%^%^YELLOW%^in your inventory.\n"

                        "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            if(!check_player_crafted(item))
            {
                db(tp,
                        "%^RESET%^%^BOLD%^%^YELLOW%^You are only allowed to enchant player made mastercrafted items that have "
                        "not been tainted by unusual enchanting techniques.\n"

                        "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            if(special)
            {
                if(!bonus_allowed(tp,item,"special",0))
                {
                    db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }

                special_info["type"] = special;

                if(!special_allowed(tp,item,special_info))
                {
                    db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }

                cost = calculate_cost(tp,item, "special", 1, special);

                db(tp,
                        "%^RESET%^%^BOLD%^%^YELLOW%^It would require %^RESET%^%^BOLD%^%^MAGENTA%^"+cost+" %^RESET%^%^BOLD%^%^YELLOW%^crafting "
                        "materials to enchant "+item->query("short")+" %^RESET%^%^BOLD%^%^YELLOW%^with "
                        "a %^RESET%^%^BOLD%^%^MAGENTA%^"+special+" %^RESET%^%^BOLD%^%^YELLOW%^special.\n"

                        "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            if(!bonus_allowed(tp,item,type,amt))
            {
                db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            cost = calculate_cost(tp,item,type,amt);

            db(tp,
                    "%^RESET%^%^BOLD%^%^YELLOW%^It would require %^RESET%^%^BOLD%^%^MAGENTA%^"+cost+" %^RESET%^%^BOLD%^%^YELLOW%^crafting "
                    "materials to enchant "+item->query("short")+" %^RESET%^%^BOLD%^%^YELLOW%^with %^RESET%^%^BOLD%^%^MAGENTA%^"+amt+" "+type+"%^RESET%^%^BOLD%^%^YELLOW%^.\n"

                    "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

            input_to("enchanting_menu",map);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "enchant":

            if(sscanf(str,"enchant %s %d %special %s", thing, amt, type, special) != 4)
            {
                if(type != "special" && sscanf(str, "enchant %s %d %s", thing, amt, type) != 3)
                {
                    db(tp,
                            "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT TYPE \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^enchant bracers 2 attack bonus \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^enchant bracers 1 enchantment \n"
                            "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT %^RESET%^%^BOLD%^%^YELLOW%^special %^RESET%^%^BOLD%^%^MAGENTA%^TYPE \n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^enchant sword 1 special stun\n"
                            "    %^RESET%^%^BOLD%^%^YELLOW%^example: %^RESET%^%^BOLD%^%^GREEN%^enchant bracers 1 special poison\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }
            }

            if(amt < 0)
            {
                db(tp,
                        "Sorry, negative numbers are not allowed.\n"

                        "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            if(!objectp(item = present(thing, tp)))
            {
                db(tp,
                        "%^RESET%^%^BOLD%^%^YELLOW%^Can't find "+thing+" %^RESET%^%^BOLD%^%^YELLOW%^please make sure it's the first "+thing+" %^RESET%^%^BOLD%^%^YELLOW%^in your inventory.\n"

                        "%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            if(special)
            {
                if(!bonus_allowed(tp,item,"special",0))
                {
                    db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }

                special_info["type"] = special;

                if(!special_allowed(tp,item,special_info))
                {
                    db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                    input_to("enchanting_menu",map);
                    return;
                }

                if(item->is_weapon()) { special_info["special"] = "hit"; }
                else { special_info["special"] = "struck"; }
                map["special info"] = special_info;

                map["confirmation type"] = "special messages";
                map["item"] = item;
                map["tp"] = tp;

                db(tp,
                        "%^RESET%^%^BOLD%^%^GREEN%^You have decided to enchant your "
                        ""+item->query("short")+" %^RESET%^%^BOLD%^%^GREEN%^with "
                        "a %^RESET%^%^BOLD%^%^MAGENTA%^"+special+" special.  %^RESET%^%^BOLD%^%^MAGENTA%^(Specials are "
                        "things that happen when you strike someone with a weapon or when you are "
                        "wearing something when someone else strikes you.  So if you have a "
                        "heal special on a suit of armor, then there will be a chance that you "
                        "will be healed when you are struck in combat.) %^RESET%^%^BOLD%^%^GREEN%^"
                        "You can now enter your own custom special messages if you would like.\n\n"

                        "%^RESET%^%^BOLD%^%^YELLOW%^If you want to enter your own special messages please "
                        "enter %^RESET%^%^BOLD%^%^MAGENTA%^<yes>%^RESET%^%^BOLD%^%^YELLOW%^.  "
                        "Enter %^RESET%^%^BOLD%^%^MAGENTA%^<no> %^RESET%^%^BOLD%^%^YELLOW%^to use the "
                        "default special messages or anything else to abort and return to the menu."
                        );

                input_to("enchanting_menu",map);
                return;
            }

            if(!bonus_allowed(tp,item,type,amt))
            {
                db(tp,"\n\n%^RESET%^%^BOLD%^%^GREEN%^Press any key to continue...");

                input_to("enchanting_menu",map);
                return;
            }

            db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^Attempting to enchant your "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^.%^RESET%^\n");

            enchant_item(tp,item,type,amt);

            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "user":

            message = str;
            if(strsrch(message,"USER ") == -1 && strsrch(message,"user ") == -1)
            {
                db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^No %^RESET%^%^BOLD%^%^MAGENTA%^USER %^RESET%^%^BOLD%^%^YELLOW%^found in front of message, aborting...\n");
                destruct(TO);
                return;
            }

            if(strsrch(message,"USER ") == 0) { message = replace_string(message,"USER ","",1); }
            else if(strsrch(message, "user ") == 0) { message = replace_string(message, "user ","",1); }

            db(tp,
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$T  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your attacker or target's name\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for target  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers\n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$U  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your name \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$US %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for yourself  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers \n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$O  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your item's short desc \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$W  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your enemy's weapon %^RESET%^%^BOLD%^(%^RESET%^%^BOLD%^%^MAGENTA%^only for armor specials%^RESET%^%^BOLD%^) \n\n");

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^Your %^RESET%^%^BOLD%^%^MAGENTA%^user %^RESET%^%^BOLD%^%^YELLOW%^special message reads as follows: \n\n"
                ""+message+"\n\n");

            if(!message_check(message,"user"))
            {
                db(tp,"%^RESET%^%^BOLD%^%^RED%^Your message doesn't contain any of the target or user substitutions or doesn't contain the correct ones, "
                    "ie %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RED%^, %^MAGENTA%^$U%^RESET%^%^BOLD%^%^RED%^,  please enter %^MAGENTA%^no %^RED%^to correct this.\n\n");
            }

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^If you are happy with this message, "
                "please enter %^RESET%^%^BOLD%^%^MAGENTA%^<yes> %^RESET%^%^BOLD%^%^YELLOW%^otherwise enter %^RESET%^%^BOLD%^%^MAGENTA%^<no>%^RESET%^%^BOLD%^%^YELLOW%^\n"
                );

            map["confirmation type"] = "user message";
            map["user message"] = message;

            input_to("enchanting_menu",map);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "target":

            message = str;
            if(strsrch(message,"TARGET ") == -1 && strsrch(message,"target ") == -1)
            {
                db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^No %^RESET%^%^BOLD%^%^MAGENTA%^TARGET %^RESET%^%^BOLD%^%^YELLOW%^found in front of message, aborting...\n");
                destruct(TO);
                return;
            }

            if(strsrch(message,"TARGET ") == 0) { message = replace_string(message,"TARGET ","",1); }
            else if(strsrch(message, "target ") == 0) { message = replace_string(message, "target ","",1); }

            db(tp,
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$T  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your attacker or target's name\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for target  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers\n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$U  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your name \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$US %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for yourself  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers \n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$O  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your item's short desc \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$W  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your enemy's weapon %^RESET%^%^BOLD%^(%^RESET%^%^BOLD%^%^MAGENTA%^only for armor specials%^RESET%^%^BOLD%^) \n\n");

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^Your %^RESET%^%^BOLD%^%^MAGENTA%^target %^RESET%^%^BOLD%^%^YELLOW%^special message reads as follows: \n\n"
                ""+message+"\n\n");

            if(!message_check(message,"target"))
            {
                db(tp,"%^RESET%^%^BOLD%^%^RED%^Your message doesn't contain any of the target or user substitutions or doesn't contain the correct ones, "
                    "ie %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RED%^, %^MAGENTA%^$U%^RESET%^%^BOLD%^%^RED%^,  please enter %^MAGENTA%^no %^RED%^to correct this.\n\n");
            }

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^If you are happy with this message, please "
                "enter %^RESET%^%^BOLD%^%^MAGENTA%^<yes> %^RESET%^%^BOLD%^%^YELLOW%^otherwise enter %^RESET%^%^BOLD%^%^MAGENTA%^<no>\n"
                );

            map["confirmation type"] = "target message";
            map["target message"] = message;

            input_to("enchanting_menu",map);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "room":

            message = str;
            if(strsrch(message,"ROOM ") == -1 && strsrch(message,"room ") == -1)
            {
                db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^No %^RESET%^%^BOLD%^%^MAGENTA%^ROOM %^RESET%^%^BOLD%^%^YELLOW%^found in front of message, aborting...\n");
                destruct(TO);
                return;
            }

            if(strsrch(message,"ROOM ") == 0) { message = replace_string(message,"ROOM ","",1); }
            else if(strsrch(message, "room ") == 0) { message = replace_string(message, "room ","",1); }

            db(tp,
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$T  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your attacker or target's name\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for target  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers\n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$U  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your name \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$US %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for yourself  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers \n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$O  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your item's short desc \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$W  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your enemy's weapon %^RESET%^%^BOLD%^(%^RESET%^%^BOLD%^%^MAGENTA%^only for armor specials%^RESET%^%^BOLD%^) \n\n");

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^Your %^RESET%^%^BOLD%^%^MAGENTA%^room %^RESET%^%^BOLD%^%^YELLOW%^special message reads as follows: \n\n"
                ""+message+"\n\n");

            if(!message_check(message,"room"))
            {
                db(tp,"%^RESET%^%^BOLD%^%^RED%^Your message doesn't contain any of the target or user substitutions or doesn't contain the correct ones, "
                    "ie %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RED%^, %^MAGENTA%^$U%^RESET%^%^BOLD%^%^RED%^,  please enter %^MAGENTA%^no %^RED%^to correct this.\n\n");
            }

            db(tp,"%^RESET%^%^BOLD%^%^YELLOW%^If you are happy with this message, please "
                "enter %^RESET%^%^BOLD%^%^MAGENTA%^<yes>%^RESET%^%^BOLD%^%^YELLOW%^ otherwise enter %^RESET%^%^BOLD%^%^MAGENTA%^<no>\n"
                );

            map["confirmation type"] = "room message";
            map["room message"] = message;

            input_to("enchanting_menu",map);
            return;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "yes":

            item = map["item"];
            if(!objectp(item))
            {
                db(tp,"\n\n%^B_RED%^%^BOLD%^%^CYAN%^ERROR: mixed up your item somehow, contact a wiz.%^RESET%^");
                return;
            }

            if(map["confirmation type"] == "room message")
            {
                special_info = map["special info"];

                message = map["user message"];
                if(message && !message_check(message))
                {
                    db(tp,"%^RED%^No substitutions found in your user message: \n\n"+message+"\n\n"
                          "%^RESET%^%^BOLD%^%^GREEN%^Aborting...");
                    destruct(TO);
                    return;
                }
                else
                {
                    special_info["user message"] = message;
                }

                message = map["target message"];
                if(message && !message_check(message))
                {
                    db(tp,"%^RED%^No substitutions found in your target message: \n\n"+message+"\n\n"
                          "%^RESET%^%^BOLD%^%^GREEN%^Aborting...");
                    destruct(TO);
                    return;
                }
                else
                {
                    special_info["target message"] = message;
                }

                message = map["room message"];
                if(message && !message_check(message))
                {
                    db(tp,"%^RED%^No substitutions found in your user message: \n\n"+message+"\n\n"
                          "%^RESET%^%^BOLD%^%^GREEN%^Aborting...");
                    destruct(TO);
                    return;
                }
                else
                {
                    special_info["room message"] = message;
                }

                db(tp,"\n\n%^RESET%^%^BOLD%^%^YELLOW%^Finished entering your special messages..  attempting to enchant your "
                    ""+item->query("short")+"%^RESET%^%^BOLD%^%^YELLOW%^.%^RESET%^\n\n");

                enchant_item(tp, item, "special", 1, special_info);
                return;
            }


            db(tp,
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$T  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your attacker or target's name\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for target  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers\n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$U  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your name \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$US %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for yourself  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers \n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$O  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your item's short desc \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$W  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your enemy's weapon %^RESET%^%^BOLD%^(%^RESET%^%^BOLD%^%^MAGENTA%^only for armor specials%^RESET%^%^BOLD%^) \n\n");


            if(map["confirmation type"] == "special messages")
            {
                db(tp,  "%^RESET%^%^BOLD%^%^GREEN%^Please enter a user message, this is what "
                        "%^RESET%^%^BOLD%^%^MAGENTA%^you%^RESET%^%^BOLD%^%^GREEN%^ see while you are wearing "
                        "or wielding the item when the special happens.\n"

                        "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget "
                        "the %^RESET%^%^BOLD%^%^MAGENTA%^USER%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER%^RESET%^%^BOLD%^%^YELLOW%^ As %^RESET%^%^BOLD%^%^MAGENTA%^$T "
                                "%^RESET%^%^BOLD%^%^YELLOW%^strikes your %^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^%^YELLOW%^is knocked off balance and "
                                "looses %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^%^YELLOW%^footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like the following to %^RESET%^%^BOLD%^%^MAGENTA%^you%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As Casualtys strikes your "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, he is knocked off "
                            "balance and looses his footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER %^RESET%^%^BOLD%^%^YELLOW%^You "
                                "shoot the front of %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^'s knee, "
                                "knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^you%^RESET%^%^BOLD%^%^GREEN%^: \n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^You shoot the front of Casualty's knee, knocking him to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER %^RESET%^%^BOLD%^%^YELLOW%^You "
                                "sweep your %^RESET%^%^BOLD%^%^MAGENTA%^$O %^RESET%^%^BOLD%^%^YELLOW%^at %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^%^YELLOW%^to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^you%^RESET%^%^BOLD%^%^GREEN%^: \n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^You sweep your "+item->query_short()+" %^RESET%^%^BOLD%^%^YELLOW%^at Casualty, knocking him to the ground!\n");
                }

                map["confirmation type"] = "user message";
                input_to("enchanting_menu",map);
                return;
            }


            if(map["confirmation type"] == "user message")
            {
                db(tp,  "%^RESET%^%^BOLD%^%^GREEN%^Please enter a %^RESET%^%^BOLD%^%^MAGENTA%^target %^RESET%^%^BOLD%^%^GREEN%^message, this is what your "
                            "%^RESET%^%^BOLD%^%^MAGENTA%^target %^RESET%^%^BOLD%^%^GREEN%^sees when they "
                            "hit you while you are wearing armor or you hit them while you are wielding "
                            "a weapon.\n"
                        "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget "
                            "the %^RESET%^%^BOLD%^%^MAGENTA%^TARGET%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET %^RESET%^%^BOLD%^%^YELLOW%^As you "
                                "strike %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^'s "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "you are knocked off balance and loose your footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As you strike "+tp->QCN+"%^RESET%^%^BOLD%^%^YELLOW%^'s "
                                ""+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, you are knocked off "
                                "balance and loose your footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET $U%^RESET%^%^BOLD%^%^YELLOW%^ shoots "
                                "the front of your knee, knocking you to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" shoots the front of your knee, knocking you to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET $U%^RESET%^%^BOLD%^%^YELLOW%^ sweeps "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$UP $O%^RESET%^%^BOLD%^%^YELLOW%^ at you, knocking you to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" sweeps "+tp->QP+" "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^ at you, knocking you to the ground!\n");
                }


                input_to("enchanting_menu",map);
                return;
            }


            if(map["confirmation type"] == "target message")
            {
                db(tp,"%^RESET%^%^BOLD%^%^GREEN%^Please enter a room message, this is what other people in the room see when the special happens.\n"
                    "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget the %^RESET%^%^BOLD%^%^MAGENTA%^ROOM%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^ROOM%^RESET%^%^BOLD%^%^YELLOW%^ As %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^ "
                                "strikes %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^'s %^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, %^RESET%^%^BOLD%^%^MAGENTA%^$TS "
                                "%^RESET%^%^BOLD%^%^YELLOW%^is knocked off balance and looses %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^%^YELLOW%^footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As Casualty strikes "+tp->QCN+"%^RESET%^%^BOLD%^%^YELLOW%^'s "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, he is knocked off balance "
                            "and looses his footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: ROOM %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^ "
                                "shoots the front of %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^'s knee, knocking "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" shoots the front of Casualty's knee, knocking him to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^ROOM $U %^RESET%^%^BOLD%^%^YELLOW%^sweeps "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$UP $O %^RESET%^%^BOLD%^%^YELLOW%^at %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^"
                                ", knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" sweeps "+tp->QP+" "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^ at Casualty, knocking him to the ground!\n");
                }


                input_to("enchanting_menu",map);
                return;
            }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        case "no":

            item = map["item"];
            if(!objectp(item))
            {
                db(tp,"%^B_RED%^%^BOLD%^%^CYAN%^ERROR: mixed up your item somehow, contact a wiz.");
                return;
            }

            if(map["confirmation type"] == "special messages")
            {
                special_info = map["special info"];
                if(!sizeof(keys(special_info)))
                {
                    db(tp,"ERROR: lost your special information somehow, contact a wiz.");
                    return;
                }

                db(tp, "You have decided to use the default messages for your item.  Beginning "
                    "enchanting...");
                enchant_item(tp, item, "special", 1, special_info);
                return;
            }

            db(tp,  "  %^RESET%^%^BOLD%^%^MAGENTA%^$T  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your attacker or target's name\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for target  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her\n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for target %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers\n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$U  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your name \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$US %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Subjective for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^he%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^she \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UO %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Objective for yourself  %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^him%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^her \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$UP %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Possessive for yourself %^RESET%^%^BOLD%^- %^RESET%^%^BOLD%^%^MAGENTA%^his%^RESET%^%^BOLD%^/%^RESET%^%^BOLD%^%^MAGENTA%^hers \n\n"

                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$O  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your item's short desc \n"
                    "  %^RESET%^%^BOLD%^%^MAGENTA%^$W  %^RESET%^%^BOLD%^= %^RESET%^%^BOLD%^%^GREEN%^Your enemy's weapon %^RESET%^%^BOLD%^(%^RESET%^%^BOLD%^%^MAGENTA%^only for armor specials%^RESET%^%^BOLD%^) \n\n");

            if(map["confirmation type"] == "user message")
            {
                map["user message"] = 0;

                db(tp,  "%^RESET%^%^BOLD%^%^GREEN%^Please enter a user message, this is what "
                        "%^RESET%^%^BOLD%^%^MAGENTA%^you%^RESET%^%^BOLD%^%^GREEN%^ see while you are wearing "
                        "or wielding the item when the special happens.\n"

                        "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget "
                        "the %^RESET%^%^BOLD%^%^MAGENTA%^USER%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER%^RESET%^%^BOLD%^%^YELLOW%^ As %^RESET%^%^BOLD%^%^MAGENTA%^$T "
                                "%^RESET%^%^BOLD%^%^YELLOW%^strikes your %^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$TS %^RESET%^%^BOLD%^%^YELLOW%^is knocked off balance and "
                                "looses %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^%^YELLOW%^footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like the following to you:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As Casualtys strikes your "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, he is knocked off "
                            "balance and looses his footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER %^RESET%^%^BOLD%^%^YELLOW%^You "
                                "shoot the front of %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^'s knee, "
                                "knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to you: \n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^You shoot the front of Casualty's knee, knocking him to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^USER %^RESET%^%^BOLD%^%^YELLOW%^You "
                                "sweep your %^RESET%^%^BOLD%^%^MAGENTA%^$O %^RESET%^%^BOLD%^%^YELLOW%^at %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO %^RESET%^%^BOLD%^%^YELLOW%^to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to you: \n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^You sweep your "+item->query_short()+" %^RESET%^%^BOLD%^%^YELLOW%^at Casualty, knocking him to the ground!\n");
                }


                input_to("enchanting_menu",map);
                return;
            }


            if(map["confirmation type"] == "target message")
            {
                map["target message"] = 0;

                db(tp,  "%^RESET%^%^BOLD%^%^GREEN%^Please enter a %^RESET%^%^BOLD%^%^MAGENTA%^target %^RESET%^%^BOLD%^%^GREEN%^message, this is what your "
                            "%^RESET%^%^BOLD%^%^MAGENTA%^target %^RESET%^%^BOLD%^%^GREEN%^sees when they "
                            "hit you while you are wearing armor or you hit them while you are wielding "
                            "a weapon.\n"
                        "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget "
                            "the %^RESET%^%^BOLD%^%^MAGENTA%^TARGET%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET %^RESET%^%^BOLD%^%^YELLOW%^As you "
                                "strike %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^'s "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, "
                                "you are knocked off balance and loose your footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As you strike "+tp->QCN+"%^RESET%^%^BOLD%^%^YELLOW%^'s "
                                ""+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, you are knocked off "
                                "balance and loose your footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET $U%^RESET%^%^BOLD%^%^YELLOW%^ shoots "
                                "the front of your knee, knocking you to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" shoots the front of your knee, knocking you to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^TARGET $U%^RESET%^%^BOLD%^%^YELLOW%^ sweeps "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$UP $O%^RESET%^%^BOLD%^%^YELLOW%^ at you, knocking you to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to your %^RESET%^%^BOLD%^%^MAGENTA%^target%^RESET%^%^BOLD%^%^GREEN%^:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" sweeps "+tp->QP+" "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^ at you, knocking you to the ground!\n");
                }


                input_to("enchanting_menu",map);
                return;
            }


            if(map["confirmation type"] == "room message")
            {
                map["room message"] = 0;

                db(tp,"%^RESET%^%^BOLD%^%^GREEN%^Please enter a room message, this is what other people in the room see when the special happens.\n"
                    "%^RESET%^%^BOLD%^%^MAGENTA%^IMPORTANT%^RESET%^%^BOLD%^%^GREEN%^, don't forget the %^RESET%^%^BOLD%^%^MAGENTA%^ROOM%^RESET%^%^BOLD%^%^GREEN%^ in front of the message.\n\n");

                if(item->is_armor())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^ROOM%^RESET%^%^BOLD%^%^YELLOW%^ As %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^ "
                                "strikes %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^'s %^RESET%^%^BOLD%^%^MAGENTA%^$O%^RESET%^%^BOLD%^%^YELLOW%^, %^RESET%^%^BOLD%^%^MAGENTA%^$TS "
                                "%^RESET%^%^BOLD%^%^YELLOW%^is knocked off balance and looses %^RESET%^%^BOLD%^%^MAGENTA%^$TP %^RESET%^%^BOLD%^%^YELLOW%^footing!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^As Casualty strikes "+tp->QCN+"%^RESET%^%^BOLD%^%^YELLOW%^'s "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^, he is knocked off balance "
                            "and looses his footing!\n");
                }
                else if(item->is_lrweapons())
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: ROOM %^RESET%^%^BOLD%^%^MAGENTA%^$U%^RESET%^%^BOLD%^%^YELLOW%^ "
                                "shoots the front of %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^'s knee, knocking "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" shoots the front of Casualty's knee, knocking him to the ground!\n");
                }
                else
                {
                    db(tp,  "%^RESET%^%^BOLD%^%^YELLOW%^Syntax: %^RESET%^%^BOLD%^%^MAGENTA%^ROOM $U %^RESET%^%^BOLD%^%^YELLOW%^sweeps "
                                "%^RESET%^%^BOLD%^%^MAGENTA%^$UP $O %^RESET%^%^BOLD%^%^YELLOW%^at %^RESET%^%^BOLD%^%^MAGENTA%^$T%^RESET%^%^BOLD%^%^YELLOW%^"
                                ", knocking %^RESET%^%^BOLD%^%^MAGENTA%^$TO%^RESET%^%^BOLD%^%^YELLOW%^ to the ground!\n\n"

                            "%^RESET%^%^BOLD%^%^GREEN%^The above special would look like this to %^RESET%^%^BOLD%^%^MAGENTA%^others%^RESET%^%^BOLD%^%^GREEN%^ in the room:\n\n"

                            "%^RESET%^%^BOLD%^%^YELLOW%^"+tp->QCN+" sweeps "+tp->QP+" "+item->query_short()+"%^RESET%^%^BOLD%^%^YELLOW%^ at Casualty, knocking him to the ground!\n");
                }


                input_to("enchanting_menu",map);
                return;
            }

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        default:

            db(tp,

                    "%^RESET%^%^BOLD%^%^GREEN%^Welcome to the enchanting menu. You see this menu if you are trying to "
                    "magically enchant equipment. You have the following options available:\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^exit \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^Leaves the menu and stops the enchanting process.\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^list \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^Lists all the available bonuses that you can add to or improve\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^cost %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT TYPE \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^Will tell you the cost to enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM%^GREEN%^ with %^RESET%^%^BOLD%^%^MAGENTA%^AMOUNT%^RESET%^%^BOLD%^%^GREEN%^ of \n"
                    "    %^RESET%^%^BOLD%^%^MAGENTA%^TYPE%^RESET%^%^BOLD%^%^GREEN%^ bonus.\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^cost %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT%^RESET%^%^BOLD%^%^YELLOW%^ special %^RESET%^%^BOLD%^%^MAGENTA%^TYPE%^RESET%^%^BOLD%^%^YELLOW%^"
                    "    example: cost sword 1 special stun\n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^When the %^RESET%^%^BOLD%^%^MAGENTA%^SPECIAL %^RESET%^%^BOLD%^%^GREEN%^argument is %^RESET%^%^BOLD%^%^MAGENTA%^\"special\"%^RESET%^%^BOLD%^%^GREEN%^, the next argument \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^can be one of the weapon or armor special types, damage, stun, \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^etc.  All of the specials require the same amount of materials.\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT TYPE\n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^This will enchant an item with either an enchantment (additional +)\n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^or with one of the item bonuses, (attack bonus, damage bonus, etc)\n\n"

                    "%^RESET%^%^BOLD%^%^YELLOW%^enchant %^RESET%^%^BOLD%^%^MAGENTA%^ITEM AMOUNT %^RESET%^%^BOLD%^%^YELLOW%^special %^RESET%^%^BOLD%^%^MAGENTA%^TYPE\n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^This will enchant an item with a special function.  This function \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^will have a chance to hit on attack with weapons and when you are \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^getting hit with armor.  You will be asked if you would like to \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^enter your own custom messages for the special and will be given \n"
                    "    %^RESET%^%^BOLD%^%^GREEN%^an example message to help better understand.\n\n"

                    "\n    %^RESET%^%^BOLD%^%^YELLOW%^Please note that the menu is only case sensative when adding \n"
                    "    special messages to an item.  The %^RESET%^%^BOLD%^%^MAGENTA%^USER%^RESET%^%^BOLD%^%^GREEN%^, %^RESET%^%^BOLD%^%^MAGENTA%^TARGET%^RESET%^%^BOLD%^%^GREEN%^, %^RESET%^%^BOLD%^%^YELLOW%^and %^RESET%^%^BOLD%^%^MAGENTA%^ROOM %^RESET%^%^BOLD%^%^YELLOW%^tags to \n"
                    "    identify which person should see the message should be in caps.\n"
                );

            input_to("enchanting_menu", map);
            return;
    }

    return;
}


int message_check(string message, string type)
{
    string replace = ({ "$T","$TS","$TO","$TP","$U","$US","$UO","$UP","$O","$W" });
    int i, count;

    if(!message || !stringp(message) || !strlen(message)) { return 0; }

    for(i=0;i<sizeof(replace);i++)
    {
        if(strsrch(message,replace[i]) == -1) { continue; }
        count++;
    }
    switch(type)
    {
    case "user":
        if(strsrch(message,"$T") == -1) { return 0; }
    case "target":
        if(strsrch(message,"$U") == -1) { return 0; }
    case "room":
        if(strsrch(message,"$T") == -1) { return 0; }
        if(strsrch(message,"$U") == -1) { return 0; }
    }

    if(!count) { return 0; }
    return 1;
}


string sort_valid_bonuses()
{
    string *bonuses = VALID_BONUSES - restricted_skills, display;
    bonuses = filter_array(bonuses, (:!regexp($1, " percent"):));
    display = format_page(bonuses,3);
    display = "%^RESET%^%^BOLD%^%^GREEN%^"+display;
    return display;
}


int doing_check(object tp)
{
    if(!objectp(tp)) { return 1; }

    if(tp->query_casting()) { return 1; }
    if(tp->query_property("working")) { return 1; }
    if(sizeof(tp->query_attackers())) { return 1; }
    return 0;
}
