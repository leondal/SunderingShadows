#include <std.h>
#include "../inherits/area_stuff.h"

inherit VENDOR;

void create()
{
    object ob;
    ::create();


    set_class("sorcerer");
    set_alignment(5);
    set_hd(30,12);
    set_hp(750);
    set_max_hp(query_hp());

    set_stats("strength", 15 + random(3));
    set_stats("constitution", 18 + random(4));
    set_stats("dexterity", 11 + random(3));
    set_stats("wisdom", 25 + random(3));
    set_stats("intelligence", 26 + random(3));
    set_stats("charisma", 17 + random(3));
    set_overall_ac(-10);
    set_mob_magic_resistance("average");
    set_property("damage resistance", 10);
    set_gender("male");
    switch(random(2))
    {
        case 0:
            set_name("xelhor");
            set_id( ({ "gnome", "xelhor", "xelhor morkendal", "merchant", "crystal merchant"}) );
            set_short("%^BOLD%^%^BLACK%^X%^BOLD%^%^GREEN%^el%^BOLD%^%^BLACK%^hor Morkendal, "+
            "Gnomish Crystal Merchant%^RESET%^");

            set_long("%^BOLD%^%^BLACK%^This small gnome looks old. He stands a little over two feet tall "+
            "but his entire body is almost a mass of wrinkles. His wrinkled flesh is an almost green color with "+
            "some very noticeable hints of gray, which is almost the exact same color as the stone in "+
            "this cavern. His %^BOLD%^%^GREEN%^deep green%^BOLD%^%^BLACK%^ "+
            "eyes portray an immense curiosity that betrays his apparent old age. He has a mop of "+
            "almost black hair that is very long and unkept. He darts back and forth constantly digging through "+
            "crystals and attempting to sort them out, with apparently very little luck. His system of order "+
            "obviously leaves very much to be desired.%^RESET%^");

            set_race("gnome");
            set_body_type("gnome");

            break;
        case 1:
            set_name("gydore");
            set_id( ({"halfling", "gydore", "gydore deepingdawn", "merchant", "crystal merchant"}) );

            set_short("%^BOLD%^%^WHITE%^Gyd%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^r%^BOLD%^%^BLACK%^e %^BOLD%^%^WHITE%^"+
            "D%^BOLD%^%^CYAN%^ee%^BOLD%^%^WHITE%^p%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^ngd%^BOLD%^%^CYAN%^a"+
            "%^BOLD%^%^WHITE%^wn, Halfling Crystal Merchant%^RESET%^");

            set_long("%^RESET%^%^GREEN%^This chubby halfling has ears which are much more pointed, in fact almost "+
            "elven in shape. His skin is almost pale, perhaps from the lack of sunlight down "+
            "here. His eyes are a curiously %^BOLD%^%^CYAN%^bright blue%^RESET%^%^GREEN%^. He has short and "+
            "kept %^RESET%^%^ORANGE%^light brown%^RESET%^%^GREEN%^ hair that comes down to right above "+
            "his ears. He glances around at the mass of crystals and the disarray in almost what you would "+
            "consider exasperation mixed with some sort of acceptance.%^RESET%^");
            set_race("halfling");
            set_body_type("halfling");
            break;
    }

    ob = new("/d/common/obj/armour/srobe.c");
    ob->set_property("enchantment", 3);
    ob->move(TO);
    ob->set_item_bonus("caster level", 1);

    if(random(4)) ob->set_property("monsterweapon", 1);
    command("wear robe");
    set_new_exp(30, "normal");

    set_monster_feats(({"perfect caster", "toughness", "improved toughness", "resistance", "deathward", "spellpower",
    "magic arsenal","improved spell power"}));

    set_spells(({"meteor swarm", "prismatic spray",
    "cone of cold"}));
    set_spell_chance(99);

    set_items_allowed("crystal");
    set_storage_room(MINH+"crystal_storage");
}

void catch_say(string msg)
{
    ::catch_say(msg);
    if(!objectp(TP)) return;
    if(interactive(TP))
    {
        call_out("response",1,msg,TP);
    }
}

void response(string msg, object ob)
{
    if(!objectp(TO)) return;
    if(!objectp(ob)) return;
    if(!stringp(msg)) return;
    msg = lower_case(msg);
    if(strsrch(msg, "hello") != -1 || strsrch(msg, "hi") != -1
    || strsrch(msg, "howdy") != -1 || strsrch(msg, "greeting") != -1
    || strsrch(msg, "salutation") != -1 || strsrch(msg, "whaddup") != -1
    || strsrch(msg, "hai") != -1 || strsrch(msg, "whatsup") != -1)
    {
        command("speech say excitedly");
        command("emoteat "+ob->query_name()+" turns to $N and offers a flashy smile before speaking");
        command("speak wizish");
        command("say Greetings adventurer! Would you be up for helping us out? We've unearthed a way-gate!!");
        return;
    }
    if(strsrch(msg, "way-gate") != -1 || strsrch(msg, "waygate") != -1 || strsrch(msg, "way gate") != -1
    || strsrch(msg, "help") != -1)
    {
        command("speech talk rapidly");
        command("speak wizish");
        command("say the way-gate we've unearthed is just north of the encampment here. We aren't "+
        "quite sure where it leads to yet. Unfortunately it requires some type of power supply, thus the "+
        "reason we've so many crystals laying about.");
        command("emote frowns deeply before continuing");
        command("say unfortunately these laying about do NOTHING!! I mean NOTHING!! to power the way-gate.");
        command("emote grins mischeviously");
        command("say I do have some for sell that will power it. So far we've only found two types of crystals "+
        "that do anything. The bright pink one will take you to the surface.");
        command("emote takes a deep breath before continuing");
        command("say the dark yellow crystal, that's a different story. Where you come in perhaps?!?! Just "+
        "ask and I'll tell you what we know about it!");
        return;
    }
    if(strsrch(msg, "bright pink crystal") != -1)
    {
        command("speech say half-heartedly");
        command("speak wizish");
        command("say the bright pink crystal.... it is useful but not so exciting. If used to power the "+
        "way-gate it will take you to the surface. It is something that we conjured up to make trips to the "+
        "surface easier for when we need to resupply");
        return;
    }
    if(strsrch(msg, "dark yellow crystal") != -1)
    {
        command("speech speak with some hesistation");
        command("speak wizish");
        command("say the dark yellow crystal... well when used to power the way-gate it leads to some strange "+
        "cavern. We aren't quite sure what to make of it. We've taken to calling it the '%^BOLD%^%^CYAN%^Mystic "+
        "Caves%^RESET%^'. We haven't went far into it at all, because we've been trying to find something else.... "+
        "with no luck yet.");
        command("speech say with eagerness");
        command("say however, we've started to believe that there might be some more crystals or runes or even "+
        "fragments of either inside the '%^BOLD%^%^CYAN%^Mystic Caves%^RESET%^'. If you're up for going into them and exploring. I'll "+
        "reward you for any that you find and bring back to me!");
        return;
    }
    if(strsrch(msg, "mystic cave") != -1 || strsrch(msg, "mystic caves") != -1)
    {
        command("speech speak carefully");
        command("speak wizish");
        command("say there is very little we know about the '%^BOLD%^%^CYAN%^Mystic "+
        "Caves%^RESET%^'... There was a failed expedition... but we've fixed the magic since then. "+
        "You'll be okay getting out.... ");
        command("emote ponders to himself for a moment");
        command("say yes... yes... I'm quite sure of it. The magic is working fine now.");
        command("emote offers a broad grin");
        command("say HOWEVER!! Once you go in you have to find your way back to where you land "+
        "in the caverns and simply say something about needing to get out, something like "+
        "'HELP' or 'bring me home' something like that will work and we'll pull you out of there just "+
        "like that!");
        command("emote hmms thoughtfully for a few seconds");
        command("say of course you shouldn't try it if you're fighting anything.... which you might be if you go in... "+
        "and there's no promises of your safety AT ALL! BUT I will reward you for any crystals, runes, or fragments of "+
        "such that you find and bring back!");
        return;
    }
    command("emote looks around thoughtfully for a moment before going back to his business");
    return;
}

void receive_given_item(object ob)
{
    string item, *nams;
    int val, gold, exp;
    if(!objectp(ob)) return 1;
    if(!objectp(TP)) return 1;
    if(!objectp(TO)) return 1;
    nams = ob->query_id();
    if(!ob->id("mizatseekingshard") || !ob->query_property("max mizat value"))
    {
        command("say I have no need for that.");
        command("give "+nams[0]+" to "+TPQN);
        return 1;
    }
    command("speech speak quickly with obvious excitement");
    command("speak wizish");
    command("say YES, YES, YES!! That is exactly what we are looking for.");
    command("emote quickly hides the "+ob->query_short()+" inside a pocket on "+
    "his robes");
    val = ob->query_property("max mizat value");
    ob->remove();
    command("say now, for a matter of reward!");
    command("emoteat "+TPQN+" tosses $N a pouch of gold");
    gold = 250 + random(val/2);
    TP->add_money("gold", gold);
    command("emoteat "+TPQN+" faces $N and chants in a mysterious language!");
    tell_object(TP, "%^BOLD%^%^CYAN%^You suddenly feel yourself become more experienced!%^RESET%^");
    if(objectp(ETP)) tell_room(ETP, TPQCN+"%^BOLD%^%^CYAN%^ suddenly looks more experienced!%^RESET%^", TP);
    exp = (1000 + random(val)) * (2+random(3));
    TP->add_exp(exp);
    command("say thank you again for the help "+TPQCN+"!");
    return 1;
}
