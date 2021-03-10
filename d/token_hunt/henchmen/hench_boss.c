#include <std.h>
#include <daemons.h>
#include "henchmen.h"

inherit NPC;

nosave int talking,ATTACKED_TIME;
nosave mapping decision,timer;
nosave string MY_ROOM = "/d/shadow/room/forest/road3";

void talk_func(string str, object ob);

void create()
{
    ::create();
    set_name("");
    set_id( ({ "captain","merc captain","sault","Sault", "mercenary captain","merc_boss" }) );
    set_short("Sault, a %^RESET%^%^GREEN%^y%^BOLD%^o%^ORANGE%^u%^GREEN%^n%^RESET%^%^GREEN%^g %^BOLD%^%^WHITE%^m%^RESET%^e%^BOLD%^r%^RESET%^c%^BOLD%^e%^RESET%^n%^BOLD%^a%^RESET%^r%^BOLD%^y %^RESET%^%^GREEN%^ca%^YELLOW%^p%^RESET%^%^GREEN%^t%^YELLOW%^a%^RESET%^%^GREEN%^in%^WHITE%^");
    set_name("Sault");
    set_long("Sault seems to be a man in his mid twenties with a rakish mop of dark hair cropped so it falls "
        "lazily across the right side of his face.  He keeps it out of his eyes with a floppy black bandana that "
        "looks like it has seen its share of use.  A leather satchel hangs on his right hip, and judging by the "
        "holes that are worn into it, it appears to hold a book that gets used a great deal.");

    set("aggressive", 0);
    set_level(60);
    set_gender("male");
    set_race("human");
    set_body_type("human");
    set_size(2);
    set_hd(35,50);
    set_attacks_num(20);
    set_damage(1,10);
    set_max_hp(6500);
    set_hp(query_max_hp());
    timer = ([]);
    decision = ([]);

}

void db(string str)
{
    object the_room;
    the_room = find_object_or_load("/realms/ares/workroom");
    tell_room(ETO,str);
    if(the_room != ETO) { tell_room(the_room,str); }

    return;
}


string get_response(string word)
{
    switch(word)
    {
    case "kitten":
    case "kittens":
    case "hooker":
    case "hookers":
        return "strange";

    case "hi":
    case "hello":
    case "greetings":
    case "heya":
    case "hey":
        return "greeting";

    case "mercenary":
    case "henchman":
    case "hirelings":
    case "job":
    case "merc":
        return "describe";

    case "cost":
    case "price":
    case "much":
    case "gold":
    case "expensive":
        return "cost";

    case "hire":
    case "buy":
    case "rent":
        return "hire";

    case "yes":
    case "yah":
    case "yep":
        return "yes";

    case "no":
        return "no";

    case "hired":
        return "hired";

    case "too_poor":
        return "too_poor";

    default:
        return "none";
    }
    return "none";
}


void process_speech_event(mapping map)
{
    int *the_keys,count,cost,money;
    string str,race,pick_race;
    object player,merc,hench_d;

    if(!mapp(map)) { return; }

    if(sizeof(TO->query_attackers()))
    {
        talking = 0;
        return;
    }

    count = map["count"];
    the_keys = keys(map["say"]);

    str = map["say"][count];
    if(!stringp(str))
    {
        talking = 0;
        return;
    }


    if(strsrch(str,"hired@") != -1)
    {
        player = map["player"];
        cost = map["cost"];

        if(!objectp(player))
        {
            talking = 0;
            return;
        }

        if(!cost || cost == -1)
        {
            tell_object(player,"Error with cost, contact a wiz...");
            talking = 0;
            return;
        }

        money = (int)player->query_gold_equiv();
        if(money < cost)
        {
            TO->force_me("say huh, you just had the gold right here.");
            TO->force_me("say did you just get robbed?");
            talking = 0;
            return;
        }

        race = (string)player->query_visual_race();

        switch(race)
        {
        case "beastman":
        case "elf":
        case "gnome":
        case "half-elf":
        case "centaur":
        case "halfling":
        case "voadkyn":

            pick_race = "half-elf";
            break;

        case "firbolg":
        case "dwarf":
        case "human":
        case "shade":
        case "wemic":

            pick_race = "human";
            break;

        case "half-orc":
        case "bugbear":
        case "drow":
        case "gnoll":
        case "goblin":
        case "half-drow":
        case "half-ogre":
        case "hobgoblin":
        case "kobold":
        case "minotaur":
        case "orc":
        case "ogre":
        case "ogre-mage":
        case "yuan-ti":

            pick_race = "half-orc";
            break;

        default:

            pick_race = "human";
            break;
        }

        hench_d = find_object_or_load(HENCH_D);
        if(!objectp(hench_d))
        {
            tell_object(player,"Error, no hench_d");
            talking = 0;
            return;
        }
        player->use_funds("gold",cost);
        hench_d->remove_penalty(player);

        merc = new(PATH+"/henchman");
        merc->setup_merc("cleric",pick_race,player);
        merc->move(ETO);
        merc->parse_speech("hello",player);

        decision[player] = ([]);
        talking = 0;
        return;

    }
    else if(strsrch(str,"cost@") != -1)
    {
        player = map["player"];
        cost = map["cost"];

        if(!objectp(player))
        {
            talking = 0;
            return;
        }
        if(!cost || cost == -1)
        {
            tell_object(player,"Error with cost, please contact a wiz.");
            talking = 0;
            return;
        }
        money = (int)player->query_gold_equiv();
        if(money < cost)
        {
            call_out("talk_func",1.4,"too_poor",player);
            return;
        }
        else
        {
            call_out("talk_func",1.4,"hired",player);
            return;
        }
    }
    else if(strsrch(str,"question@") != -1)
    {
        player = map["player"];
        if(!mapp(decision[player])) { decision[player] = ([]); }
        decision[player]["asked"] = 1;
        decision[player]["asked time"] = time() + 15;
        talking = 0;
        return;
    }
    else if(strsrch(str,"emote@") != -1)
    {
        str = replace_string(str,"emote@","");
        TO->force_me("emote "+str);
    }
    else if(strsrch(str,"say@") != -1)
    {
        str = replace_string(str,"say@","");
        TO->force_me("speak wizish");
        TO->force_me("speech speak energetically");
        TO->force_me("say "+str);
    }

    if(count < sizeof(the_keys)-1)
    {
        count++;
        map["count"] = count;
        call_out("process_speech_event",1.3,map);
        return;
    }
    talking = 0;
    return;
}

// 0 for okay, 1 for on timer
int check_timer(string type)
{
    int the_time;

    switch(type)
    {
        case "greeting":    the_time = 60;  break;
        case "describe":    the_time = 60;  break;
        case "cost":        the_time = 10;  break;
        case "hire":        the_time = 8;   break;
        case "no":          the_time = 8;   break;
        case "yes":         the_time = 10;  break;
        case "too_poor":    the_time = 15;  break;
        case "hired":       the_time = 10;  break;
    }

    if(!timer[type])
    {
        timer[type] = time() + the_time;
        return 0;
    }
    if(timer[type] > time()) { return 1; }
    return 0;
}

string remove_punctuation(string str)
{
    string *bad = ({ ".", ",", "<", ">", "-", "@","#","$","*","=" });
    int i;

    if(!stringp(str) || str == " " || str == "") { return ""; }
    for(i=0;i<sizeof(bad);i++)
    {
        str = replace_string(str,bad[i],"");
    }
    return str;
}


void talk_func(string str, object ob)
{
    mapping speech = ([]);
    string choice, *words=({});
    int i,cost,late,dead;
    object hench_d;

    if(!objectp(ob)) { return; }
    if(!stringp(str) || str == "" || str == " ") { return; }
    str = remove_punctuation(str);
    words = explode(str," ");
    if(!sizeof(words)) { return; }
    for(i=0;i<sizeof(words);i++)
    {
        choice = get_response(words[i]);
        if(choice != "none") { break; }
    }
    if(choice == "none") { return; }

    hench_d = find_object_or_load(HENCH_D);
    cost = hench_d->calculate_price(ob);
    late = hench_d->is_late((string)ob->query_true_name());
    dead = hench_d->got_killed((string)ob->query_true_name());

    speech["say"] = ([]);
    speech["count"] = 0;
    speech["cost"] = cost;
    speech["late"] = late;
    speech["dead"] = dead;
    speech["player"] = ob;

    switch(choice)
    {
    case "strange":

        speech["say"]  += ([ 0 : "emote@looks at you strangely" ]);
        speech["say"]  += ([ 0 : "say@You might have been out in the sun too long." ]);
        break;

    case "greeting":

        if(check_timer("greeting")) { return; }
        speech["say"]  += ([ 0 : "say@Howdy there." ]);
        speech["say"]  += ([ 1 : "say@Hope you're doing well." ]);
        speech["say"]  += ([ 2 : "say@...and have a pocket full of coin to hire one of my mercenaries with." ]);
        speech["say"]  += ([ 3 : "emote@chuckles" ]);

        break;

    case "describe":

        if(check_timer("describe")) { return; }
        speech["say"]  += ([ 0  : "emote@nods" ]);
        speech["say"]  += ([ 1  : "say@yeah, we're a small mercenary group." ]);
        speech["say"]  += ([ 2  : "say@it took forever to get permission to operate around here." ]);
        speech["say"]  += ([ 3  : "say@so many damn rules we had to agree to." ]);
        speech["say"]  += ([ 4  : "emote@smirks" ]);
        speech["say"]  += ([ 5  : "say@like not getting involved in any disputes between adventurers." ]);
        speech["say"]  += ([ 6  : "emote@chuckles" ]);
        speech["say"]  += ([ 7  : "say@so don't get any ideas about hiring one of my men and going to kill your nemesis." ]);
        speech["say"]  += ([ 8  : "emote@hmms" ]);
        speech["say"]  += ([ 9  : "say@also not taking part in any armed conflicts against cities in the area." ]);
        speech["say"]  += ([ 10 : "emote@rolls his eyes" ]);
        speech["say"]  += ([ 11 : "say@AND..." ]);
        speech["say"]  += ([ 12 : "say@there can only be one mercenary for each three adventurers in a group." ]);
        speech["say"]  += ([ 13 : "emote@smirks again" ]);
        speech["say"]  += ([ 14 : "say@so you and your friends can't each hire a merc if you plan to travel together." ]);
        speech["say"]  += ([ 15 : "emote@sighs" ]);
        speech["say"]  += ([ 16 : "say@so many rules." ]);
        speech["say"]  += ([ 17 : "say@I hope you people around here have a lot of gold." ]);

        break;

    case "cost":

        if(check_timer("cost")) { return; }
        speech["say"]  += ([ 0 : "emote@nods" ]);
        speech["say"]  += ([ 1 : "emote@pulls a small book out of his satchel" ]);
        speech["say"]  += ([ 2 : "emote@quickly thumbs through the pages while mumbling to himself" ]);

        if(!late && !dead)
        {
            speech["say"]  += ([ 3  : "say@looks like I don't have any marks against you." ]);
            speech["say"]  += ([ 4  : "emote@smiles" ]);
            speech["say"]  += ([ 5  : "emote@frowns in consideration as he looks you over" ]);
            speech["say"]  += ([ 6  : "say@for an adventurer of your skill, a mercenary will cost you "+cost+" gold for one day." ]);
            speech["say"]  += ([ 7  : "say@if you keep the merc for longer than a day, it'll cost you double" ]);
            speech["say"]  += ([ 8  : "say@my guys won't stay with you for more than two days though." ]);
            speech["say"]  += ([ 9  : "emote@smirks" ]);
            speech["say"]  += ([ 10 : "say@so don't go getting any bright ideas about keeping your hired hand forever." ]);
            speech["say"]  += ([ 11 : "emote@chuckles" ]);
        }

        if(late && !dead)
        {
            speech["say"]  += ([ 3  : "emote@glances up with what's obviously a look of fake disappointment" ]);
            speech["say"]  += ([ 4  : "say@looks like you kept one of my guys late the last time" ]);
            speech["say"]  += ([ 5  : "emote@shrugs and makes a note in his book" ]);
            speech["say"]  += ([ 6  : "say@well, at least you didn't get him killed." ]);
            speech["say"]  += ([ 7  : "say@still..  it's going to cost you extra to hire somebody now." ]);
            speech["say"]  += ([ 8  : "emote@looks back down at his ledger" ]);
            speech["say"]  += ([ 9  : "say@it's going to be "+cost+" gold to hire one of my guys for a day now." ]);
            speech["say"]  += ([ 10 : "say@keep that in mind in the future, if you don't want to pay double every time." ]);
        }

        if(!late && dead)
        {
            speech["say"]  += ([ 3  : "emote@grimaces as he looks over his ledger" ]);
            speech["say"]  += ([ 4  : "say@damn, looks like one of my guys died the last time he was out with you." ]);
            speech["say"]  += ([ 5  : "emote@sighs and makes a note in the book" ]);
            speech["say"]  += ([ 6  : "say@you know how much it costs to have all that equipment repaired after a trip to Kelemvor?" ]);
            speech["say"]  += ([ 7  : "emote@grumbles and shakes his head" ]);
            speech["say"]  += ([ 8  : "say@well, I guess you're going to be footing the bill, if you hire another one of my guys." ]);
            speech["say"]  += ([ 9  : "emote@shrugs and taps on the ledger with his quill" ]);
            speech["say"]  += ([ 10 : "say@for you, it'll cost "+cost+" gold to hire one of my mercs." ]);
        }

        if(late && dead)
        {
            speech["say"]  += ([ 3  : "emote@gets a blank look on his face and then slowly shakes his head" ]);
            speech["say"]  += ([ 4  : "emote@looks up and frowns" ]);
            speech["say"]  += ([ 5  : "say@not only did you keep my guy late..." ]);
            speech["say"]  += ([ 6  : "say@but then you had to go and get him killed." ]);
            speech["say"]  += ([ 7  : "emote@shakes his head again" ]);
            speech["say"]  += ([ 8  : "say@that's more gold for equipment repair, and for time, and pain and suffering for my merc." ]);
            speech["say"]  += ([ 9  : "emote@looks down at his ledger and raises an eyebrow then looks up again" ]);
            speech["say"]  += ([ 10 : "say@I hope you've got a lot of coin." ]);
            speech["say"]  += ([ 11 : "say@it's going to cost you "+cost+" to hire one of my guys now." ]);
        }

        break;

    case "hire":

        if(check_timer("hire")) { return; }

        if(present("merc_whistle_999",ob))
        {
            speech["say"]  += ([ 0: "emote@hmms" ]);
            speech["say"]  += ([ 1: "say@don't you already have one of my guys under contract?" ]);
        }
        else
        {
            speech["say"]  += ([ 0: "emote@nods" ]);
            speech["say"]  += ([ 1: "say@right, to hire one of my guys, it's going to be..." ]);
            speech["say"]  += ([ 2: "say@"+cost+" gold." ]);
            speech["say"]  += ([ 3: "say@do you still want to hire one?" ]);
            speech["say"]  += ([ 4: "question@ " ]);
        }

        break;

    case "no":

        if(check_timer("no")) { return; }
        if(!decision[ob]) { decision[ob] = ([]); }
        if(!decision[ob]["asked time"]) { decision[ob]["asked time"] = 0; }
        if(!decision[ob]["asked time"] || time() > decision[ob]["asked time"])
        {
            decision[ob] = ([]);
            talking = 0;
            return;
        }
        speech["say"]  += ([ 0: "emote@nods" ]);
        speech["say"]  += ([ 1: "say@suit yourself" ]);
        speech["say"]  += ([ 2: "say@just know that the price isn't going to go down" ]);
        speech["say"]  += ([ 3: "emote@puts his ledger back into his satchel" ]);

        decision[ob] = ([]);

        break;

    case "yes":

        if(check_timer("yes")) { return; }
        if(!mapp(decision[ob]))
        {
            talking = 0;
            return;
        }
        if(time() > decision[ob]["asked time"]) // if they don't answer within 15 seconds, forget they asked.
        {
            decision[ob] = ([]);
            talking = 0;
            return;
        }
        if(decision[ob]["asked"])
        {
            speech["say"]  += ([ 0: "emote@smiles and then nods" ]);
            speech["say"]  += ([ 1: "say@right, now there's just the matter of the coin." ]);
            speech["say"]  += ([ 2: "cost@ " ]);
        }

        break;

    case "too_poor":

        if(check_timer("too_poor")) { return; }
        speech["say"]  += ([ 0: "emote@raises an eyebrow" ]);
        speech["say"]  += ([ 1: "say@well this is embarrassing" ]);
        speech["say"]  += ([ 2: "say@you don't seem to have enough money" ]);
        speech["say"]  += ([ 3: "emote@snickers" ]);
        speech["say"]  += ([ 4: "say@better luck next time." ]);

        decision[ob] = ([]);

        break;


    case "hired":

        if(check_timer("hired")) { return; }
        speech["say"]  += ([ 0: "say@right, I'll get one of my guys" ]);
        speech["say"]  += ([ 1: "emote@takes the "+cost+" gold coins" ]);
        speech["say"]  += ([ 2: "hired@ " ]);
        break;
    }

    talking = 1;
    call_out("process_speech_event",0.4,speech);

    return;
}



void catch_say(string str)
{
    if(!objectp(TP)) { return; }
    if(!objectp(TO)) { return; }
    if(!interactive(TP)) { return; }
    if(talking) { return; }
//    if(timer > time()) { return; }
    if(sizeof(TO->query_attackers())) { return; }

    str = FILTERS_D->filter_colors(str);
    call_out("talk_func",0.6,str,TP);
    return;
}


void heart_beat()
{
    object my_room,*attackers;
    int i;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    my_room = find_object_or_load(MY_ROOM);
    if(!objectp(my_room)) { return; }

    if(ATTACKED_TIME && (time() > ATTACKED_TIME))
    {
        ATTACKED_TIME = 0;
        TO->move(my_room);
        if(present("merc_boss",my_room))
        {
            TO->remove();
            return;
        }
        TO->force_me("emote emerges from the tent");
        return;
    }

    if(sizeof(TO->query_attackers()))
    {
        attackers = TO->query_attackers();

        tell_room(ETO,"%^CYAN%^"+TO->QCN+" dives for the tent!%^RESET%^");
        TO->move(HENCH_ROOM);

        for(i=0;i<sizeof(attackers);i++)
        {
            if(!objectp(attackers[i])) { continue; }
            attackers[i]->remove_attacker(TO);
            TO->remove_attacker(attackers[i]);
        }

        ATTACKED_TIME = time() + 60;
        return;
    }

    ::heart_beat();
}
