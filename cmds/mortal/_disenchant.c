#include <std.h>
#include <daemons.h>
#include <move.h>

#define ENCHANT_OB "/cmds/mortal/obj/enchant_ob.c"

inherit DAEMON;


int doing_check(object tp)
{
    if(!objectp(tp)) { return 1; }

    if(tp->query_casting()) { return 1; }
    if(tp->query_property("working")) { return 1; }
    if(sizeof(tp->query_attackers())) { return 1; }
    return 0;
}

int status_check(object tp)
{
    if(!objectp(tp)) { return 0; }
    if(tp->query_paralyzed()) { return 0; }
    if(tp->query_blind()) { return 0; }
    if(tp->query_paralyzed() || tp->query_tripped()) { return 0; }
    return 1;
}

void disenchant_item(mapping map)
{
    object obj, tp, etp, mats_ob, start_room;
    int pass, value, flat_level, max_count, max_value, count;

    tp = map["tp"];
    obj = map["obj"];
    value = map["value"];
    count = map["count"];
    start_room = map["start room"];

    max_count = value / 25;
    if(max_count < 2) { max_count = 2; }
    if(max_count > 5) { max_count = 5; }

    if(!objectp(tp)) { return; }
    if(!objectp(obj))
    {
        tp->remove_property("disenchanting");
        return;
    }
    if(!value)
    {
        tp->remove_property("disenchanting");
        return;
    }

    etp = environment(tp);

    if(!start_room)
    {
        start_room = etp;
        map["start room"] = start_room;
    }

    if(start_room != etp)
    {
        tp->remove_property("disenchanting");
        tell_object(tp,"The movement causes the disenchanting to fail.");
        return 1;
    }
    if(doing_check(tp))
    {
        tp->remove_property("disenchanting");
        tell_object(tp,"You start doing something else and stop disenchanting.");
        return 1;
    }
    if(!status_check(tp))
    {
        tp->remove_property("disenchanting");
        tell_object(tp,"You can't do that right now.");
        return 1;
    }

    tp->set_property("disenchanting",1);

    if(count < max_count && !avatarp(tp))
    {
        switch(random(5))
        {
        case 0:

            tell_object(tp,"%^GREEN%^You scrape "+obj->query_short()+"%^GREEN%^ with a delicate cutting edge, harvesting some of its materials.\n");
            tell_room(etp,"%^GREEN%^"+tp->QCN+"%^GREEN%^ scrapes "+obj->query_short()+"%^GREEN%^ with a delicate blade, harvesting some of its materials.\n",tp);
            break;

        case 1:

            tell_object(tp,"%^CYAN%^You whisper incantations of unmaking, carefully unravelling the enchantments around "+obj->query_short()+"%^CYAN%^.\n");
            tell_room(etp,"%^CYAN%^"+tp->QCN+" whispers incantations of unmaking, carefully unravelling the enchantments around "+obj->query_short()+"%^CYAN%^.\n",tp);
            break;

        case 2:

            tell_object(tp,"%^YELLOW%^You tap on the side of the "+obj->query_short()+"%^YELLOW%^ with a small golden hammer.\n");
            tell_room(etp,"%^YELLOW%^"+tp->QCN+" taps on the side of the "+obj->query_short()+"%^YELLOW%^ with a small golden hammer.\n",tp);
            break;

        case 3:

            tell_object(tp,"%^RESET%^%^BOLD%^%^BLACK%^You use very thin paper and a small piece of charcoal to make a copy of a nearly invisible rune inscribed on the "+obj->query_short()+"\n");
            tell_room(etp,"%^RESET%^%^BOLD%^%^BLACK%^"+tp->QCN+" uses very thin paper and a small piece of charcoal to make a copy of a nearly invisible rune inscribed on the "+obj->query_short()+"\n",tp);
            break;

        case 4:

            tell_room(etp, "%^MAGENTA%^A %^CYAN%^s%^GREEN%^t%^CYAN%^ra%^ORANGE%^n%^GREEN%^g%^CYAN%^e %^MAGENTA%^noise, "
                "like %^WHITE%^glass %^MAGENTA%^pushed to the edge of breaking, %^BOLD%^%^BLACK%^r%^RESET%^i"
                "p%^BOLD%^%^BLACK%^pl%^RESET%^e%^BOLD%^%^BLACK%^s %^RESET%^%^MAGENTA%^through the room.%^WHITE%^\n");
            break;
        }

        count++;
        map["count"] = count;
        call_out("disenchant_item",2.5,map);
        return;
    }

    tp->remove_property("disenchanting");
    flat_level = obj->query_property("enchantment");
    if(obj->query_property("magic") > flat_level) { flat_level = obj->query_property("magic"); }
    flat_level = flat_level * 7;

    // 3 penalty to dc to disenchant if they don't have the crafting feats
    if(!FEATS_D->usable_feat(tp,"craft magical equipment") && !FEATS_D->usable_feat(tp,"imbue item"))
    {
        flat_level += 3;
    }

    pass = ENCHANT_OB->skill_check(tp, obj, flat_level, 0, 1);

    max_value = 250 + roll_dice(1,125);

    if(pass) { value = value / (14 + roll_dice(1,8)); }
    else { value = value / (23 + roll_dice(2,10)); }

    if(value > max_value) { value = max_value; } // given this a max value, cause some items were worth considerably more than expected.


    if(!value)
    {
        tell_object(tp,"Well that's not good, there's nothing taking after you tried to disenchant the "+obj->query_short()+"...");
        obj->move("/d/shadowgate/void");
        obj->remove();
        return;
    }

    tell_object(tp,"You manage to salvage "+value+" materials from the "+obj->query_short()+".");

    obj->move("/d/shadowgate/void");
    obj->remove();
    mats_ob = new("/cmds/mortal/obj/enchanting_mats.c");
    mats_ob->set_count(value);

    if(mats_ob->move(tp) != MOVE_OK)
    {
        tell_object(tp,"%^YELLOW%^Oops, you dropped your new mats on the ground...");
        mats_ob->move(etp);
    }
    return;
}


int cmd_disenchant(string str)
{
    mapping map=([]);
    object obj;
    int value;

    if(TP->query_property("disenchanting"))
    {
        tell_object(TP,"You are already disenchanting something...");
        return 1;
    }

    if(!stringp(str))
    {
        tell_object(TP,"Syntax: disenchant <item>");
        return 1;
    }

    obj = present(str, ETP);
    if(!objectp(obj)) { obj = present(str,TP); }

    if(!objectp(obj))
    {
        tell_object(TP,"Can't seem to find a "+str);
        return 1;
    }

    if(doing_check(TP))
    {
        tell_object(TP,"You are already doing something.");
        return 1;
    }

    if(obj->query_property("no disenchant"))
    {
        tell_object(TP,"There doesn't seem to be a way to disenchant that item.");
        return 1;
    }

    if(obj->query_property("no repair"))
    {
        tell_object(TP,"There doesn't seem to be a way to disenchant that item.");
        return 1;
    }

    if(strsrch(base_name(obj),"/d/magic/") != -1)
    {
        tell_object(TP,"You cannot disenchant a conjured item!");
        return 1;
    }

    if(obj->query_property("monsterweapon"))
    {
        tell_object(TP,"You cannot disenchant a conjured item!");
        return 1;
    }

    if(obj->query_worn() || obj->query_wielded())
    {
        tell_object(TP,"You can't disenchant something you are wearing or wielding.");
        return 1;
    }

    if(obj->query_weight() > 400)
    {
        tell_object(TP,"That is far too large to disenchant.");
        return 1;
    }

    if(!obj->query_property("enchantment") && !obj->query_property("magic") && !obj->isMagic())
    {
        tell_object(TP,"That "+obj->query_short()+" seems worthless for disenchanting.");
        return 1;
    }

    value = ENCHANT_OB->calculate_cost(TP,obj,"enchantment",0);

    if(!value)
    {
        tell_object(TP,"That "+obj->query_short()+" seems worthless for disenchanting");
        return 1;
    }

    map["tp"] = TP;
    map["obj"] = obj;
    map["value"] = value;
    map["count"] = 0;

    tell_object(TP,"You begin attempting to disenchant the "+obj->query_short()+"\n\n");

    disenchant_item(map);
    return 1;
}


int help()
{
    tell_object(TP, "Syntax: disenchant <item>\n"
        "This command will attempt to break down a magical item "
        "for its component parts.  The parts will be sorted into an easy to "
        "manage box of crafting mats.  The command can only be used by someone "
        "who is skilled at crafting magical equipment, either with the craft "
        "magical equipment feat, or the imbue item feat.  The strength of the "
        "magical item being disenchanted as well as the individual's skill and "
        "some degree of random chance will determine how many materials are "
        "recovered.");
    return 1;
}
