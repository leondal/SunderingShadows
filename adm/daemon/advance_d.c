//      /adm/daemon/advanced.c
//      from the Nightmare mudlib
//      the advancment daemon
//      created by Descartes of Borg 05 december 1992

#include <rooms.h>
#include <daemons.h>
#include <titles.h>
#include <dirs.h>
#include <new_exp_table.h>

#define MY_CLASS_HALL  "/adm/daemon/titles"
#define ASSASSIN_LOWER_LIMIT 100

int get_exp(int level, string myclass, object who);
int get_real_exp(int level, string myclass, object who);
int train_player(object tp, string which, int amount);
int get_stat_cost(int x, int lev);
string previous_title(object tp);
string get_new_title(object ob);
void class_news(string myclass, string mess);
int get_hp_bonus(string myclass, int con, int level, object who);
int m_exp(int a, int b);

void create(){
    seteuid(getuid());
}

int get_exp(int level, string myclass, object who){
    return get_real_exp(level,myclass,who);
}

int get_real_exp(int level, string myclass, object who){
    int val,iter;
    float val2;

    if (avatarp(who))
        return 0;

    if (level == 1 || level == 0)
        return 0;

    if(who->query("new_class_type")) { return EXP_NEEDED[level]; }

    val = 0;
    val2 = 0.0;

    switch ( myclass ) {
    case "cavalier":
    case "fighter":
        for (iter = 2;(iter <= level);iter ++) {
            if ( iter < 8 ) {
                val = 1000 * m_exp(2, iter - 1);
            } else if ( iter == 8 ) {
                val = 125000;
            } else if ( iter == 9 ) {
                val = 250000  ;
            } else if ( iter == 10 ) {
                val = 500000;
            } else if ( iter == 34 ) {
                    val = 16252818;
            } else {
                val2 = to_float(val);
                val2 += ((val2 * 6)/100);
                val = to_int(val2)+ 280000;
            }
        }
        break; // Fighter and Cavalier
    case "thief":
    case "bard":
    case "psywarrior":
        for (iter = 2;(iter <= level);iter ++) {
            if (iter < 8) {
                val = 1250 * m_exp(2, iter - 2);
            } else if ( iter == 8 ) {
                val = 70000;
            } else if ( iter == 9 ) {
                val = 110000;
            } else if ( iter == 10 ) {
                val = 160000;
            } else if (iter == 11) {
                    val = 220000;
            } else if (iter == 35) {
                    val = 11562023;
            } else {
                val2 = to_float(val);
                val2 += ((val2 * 6)/100);
                val = to_int(val2)+ 210000;
            }
        }
        break; // Thief and Bard
    case "illusionist":
    case "mage":
    case "psion":
        for (iter = 2;(iter <= level);iter ++) {
            if (iter < 7) {
                val = 2500 * m_exp(2, iter - 2);
            } else if (iter < 9) {
                val = 30000 * ( iter - 5 );
            } else if ( iter == 9 ) {
                val = 135000;
            } else if ( iter == 10 ) {
                val = 250000;
            } else if (iter == 11) {
                    val = 375000;
            } else if (iter == 20){
                val = 4458418;
            } /*else if (iter == 35) {
                    val = 14114978;
            } */else {
                val2 = to_float(val);
                val2 += ((val2 * 5)/100);
                val = to_int(val2)+ 290000;
            }
        }
        break; // Illusionist or mage
    case "druid":
        for (iter = 2;(iter <= level);iter ++) {
            if ( iter == 2 ) {
                val = 2000;
            } else if ( iter == 3 ) {
                val = 4000;
            } else if ( iter == 4 ) {
                val = 7500;
            } else if ( iter == 5 ) {
                val = 12500;
            } else if ( iter == 6 ) {
                val = 20000;
            } else if ( iter == 7 ) {
                val = 35000;
            } else if ( iter == 8 ) {
                val = 60000;
            } else if ( iter == 9 ) {
                val = 90000;
            } else if ( iter == 10 ) {
                val = 125000;
            } else if ( iter == 11 ) {
                val = 200000;
            } else if ( iter == 12 ) {
                val = 300000;
            } else if ( iter == 13 ) {
                val = 750000;
            } else if ( iter == 14 ) {
                val = 1500000;
            } else if ( iter == 15 ) {
                val = 3000000;
            } else if ( iter == 16 ) {
                val = 3500000;
            } else if (iter == 38) {
                val = 27322517;
            } else {
                val2 = to_float(val);
                val2 += ((val2 * 5)/100);
                val = to_int(val2)+ 400000;
            }
        }
        break; // For the future bunny loving druids of Crystal.
    case "cleric":
        for (iter = 2;(iter <= level);iter ++) {
            if (iter < 5) {
                val = 750 * m_exp(2, iter - 1);
            } else if ( iter == 5 ) {
                val = 13000;
            } else if (iter < 9) {
                val = 27500 * m_exp(2, iter - 6);
            } else if (iter == 9) {
                val = 225000;
            } else if (iter == 33) {
                    val = 13614888;
            } else {
                val2 = to_float(val);
                val2 += ((val2 * 5.0)/100.0);
                val = to_int(val2)+ 250000;
            }
        }
        break; // Clerics
    case "antipaladin" :
    case "paladin":
    case "ranger":
        for (iter = 2;(iter <= level);iter ++) {
            if (iter < 7) {
                val = 2250 * m_exp(2, iter - 2);
            } else if (iter < 9) {
                val = 75000 * ( iter - 6 );
            } else if (iter == 9) {
                val = 300000;
            } else if (iter == 10) {
                val = 600000;
            } else if (iter == 35) {
                val = 20966173;
            } else {
                val2 = to_float(val);
                val2 += ((val2 * 7)/100);
                val = to_int(val2)+ 280000;
            }
        }
        break;
    }
    return val;
}

int train_player(object tp, string which, int amount){
    return 1;
}

int get_stat_cost(int x, int lev){
    int z;

    if ( x == 1 )
        z = ((lev/10)*(lev/10)*10000) + (lev/3)*1000;
    else
        z = (lev/7)*(lev/7)*(lev*900);
    if ( z < 1000 )
        z = 1000;
    return z;
}

string get_new_title(object ob){
    string myclass, *schools;
    int level, choice;

    if (!ob)
        return notify_fail("not an object.\n");
    if (!interactive(ob))
        return notify_fail("not an interactive.\n");
    myclass = ob->query_class();
    level = ob->query_level();
    if (level > 20 || high_mortalp(ob))
        return(string)ob->getenv("TITLE");
    switch (myclass) {
    case "fighter" : return "$N "+MALE_FIGHTER[level-1];
    case "ranger"  : return "$N "+MALE_RANGER[level-1];
    case "cavalier": return "$N "+MALE_CAVALIER[level-1];
    case "paladin" : return "$N "+MALE_PALADIN[level-1];
    case "antipaladin": return "$N "+MALE_ANTIPALADIN[level-1];
    case "mage"    :{
            schools = ({ "abjuration", "conjuration_summoning",
                       "divination", "enchantment_charm",
                       "illusion", "invocation_evocation", "necromancy",
                       "alteration"});
            choice=member_array(ob->query_school(),schools,0);
            if ((string)ob->query_gender() == "female")
                choice=choice+8;
            switch (choice) {
            case 0 : return "$N "+MALE_ABJURE[level-1];
            case 1 : return "$N "+MALE_CONJ[level-1];
            case 2 : return "$N "+MALE_DIVINE[level-1];
            case 3 : return "$N "+MALE_ENCHANT[level-1];
            case 4 : return "$N "+MALE_ILLUS[level-1];
            case 5 : return "$N "+MALE_INVOKE[level-1];
            case 6 : return "$N "+MALE_NECRO[level-1];
            case 7 : return "$N "+MALE_ALTER[level-1];
            case 8 : return "$N "+FEMALE_ABJURE[level-1];
            case 9 : return "$N "+FEMALE_CONJ[level-1];
            case 10 : return "$N "+FEMALE_DIVINE[level-1];
            case 11 : return "$N "+FEMALE_ENCHANT[level-1];
            case 12 : return "$N "+FEMALE_ILLUS[level-1];
            case 13 : return "$N "+FEMALE_INVOKE[level-1];
            case 14 : return "$N "+FEMALE_NECRO[level-1];
            case 15 : return "$N "+FEMALE_ALTER[level-1];
            }
            return "$N, the mage";
        }
    case "cleric"  : if ((string)ob->query_gender() == "female")
            return "$N "+FEMALE_CLERIC[level-1];
        else
            return "$N "+MALE_CLERIC[level-1];
    case "druid"   : if ((string)ob->query_gender() == "female")
            return "$N "+FEMALE_DRUID[level-1];
        else
            return "$N "+MALE_DRUID[level-1];
    case "thief"   : return "$N "+MALE_THIEF[level-1];
    case "bard"    : return "$N "+MALE_BARD[level-1];
    case "psion"   : return "$N the psion";
    case "psywarrior" : return "$N the psywarrior";
    default        : return "$N the child";
    }
    return "";
}

int advance(object tp, string myclass)
{
    int con, lev, exp, num,i, ret, gexp, hpbonus,check,*rolls,prof;
    string cl,file;

    ret  = 0;
    con  = (int)tp->query_base_stats("constitution");
    lev  = (int)tp->query_class_level(myclass);
    exp  = (int)tp->get_general_exp(myclass);
    cl   = myclass;
    file = DIR_CLASSES+"/"+myclass+".c";

    if(tp->query("new_class_type")) { check = tp->query_base_character_level(); }
    if(check == 0)
    {
        tp->set_mlevel(myclass, 1);
        file->advanced_func(tp);
    }

    // if(tp->query("new_class_type")) { check = tp->query_adjusted_character_level(); }
    // if(tp->query("new_class_type")) { check = tp->query_adjusted_character_level(); }
    // else { check = lev; }
    // Not sure why this was here --  marking them as adjusted to clear
    //     them off my list  -- garrett 06/22/2020

    if (!interactive(tp))
        return 0;
    if(!file_exists(file))
        return 0;

    gexp = get_exp(check+1,cl, tp);

    if((gexp < exp) && !wizardp(tp)) {
        if ((tp->query_lowest_level() > 5 || lev + 1 > 5) && !tp->query_description())
        {
            tell_object(tp,"Please take a moment to set a description first.");
            return 0;
        }
        // Let whoever called us know we advanced.
        ret = 1;
        tp->set_mlevel(myclass,lev+1);

        // new leveling stuff all in the class file, guild level, thief skills, max lance prof, etc
        file->advanced_func(tp);

        hpbonus = get_hp_bonus(cl, con, (int)tp->query_base_character_level(),tp); // this is setting the number in the array
        hpbonus = 30; // don't need it anymore so using it as a variable, starting chars get +30 hp
        if((string)tp->query_race() == "human" && (string)tp->query("subrace") == "tonaz'tlacar") hpbonus += 10; // 10hp bonus 'dauntless' for 'tlacar human subrace

        rolls = (int*)tp->query("hp_array");

        // NOTE this needs to keep using base_character_level as LA levels get automatic HP on their own. Only class levels get rolled.
        for(i=0;i<(int)tp->query_base_character_level()+1;i++) // always adds up the array of hitpoint rolls on advance now, hopefully fixing the errors
        {
            hpbonus += rolls[i];
        }
        tp->set_max_hp(hpbonus);


        tp->setenv("TITLE", get_new_title(tp));
        if(tp->query("new_class_type"))
        {
            tell_object(tp,"You are now level "+(lev+1)+" in your "+myclass+" class.");
            tell_object(tp,"Your total character level is "+tp->query_base_character_level()+".");
            tell_object(tp,"Your adjusted character level is "+tp->query_adjusted_character_level()+".");
            if((int)tp->query_base_character_level() == 1 || (int)tp->query_base_character_level()%3==0 && (((int)tp->query_other_feats_gained() *3) <= (int)tp->query_base_character_level()))
            {
                tell_object(tp,"%^B_RED%^%^CYAN%^You earned new feats this level, please type help feats.%^RESET%^");
            }
        }
        else
        {
            tell_object(tp,"You are now level "+(lev+1)+".");
        }

        if (!tp->query("test_character")) {
            CLASS_NEWS->class_news(myclass, capitalize((string)tp->query_name()) + " advances a level.");
        }

        if (newbiep(tp) && ((int)tp->query_lowest_level() == 6)) {
            tp->set_position("player");
        }
//        NWP_D->advance_player(tp,class,lev+1); //nwps no longer exist! N, 1/14.

    } else {
        // You didn't have enough exp to advance, or you were a Wizard.
    }
    tp->update_channels();
    if((tp->is_class("sorcerer") || tp->is_class("psywarrior") || tp->is_class("psion") || tp->is_class("warlock"))) tp->set("can_swap_spells",1); // flag to let sorcs swap spells on even levels; added psionic classes ~Circe~ 9/20/15; added warlocks, N 12/15.
    if(tp->is_class("monk") || myclass == "monk" || myclass == "grandmaster_of_the_way" || FEATS_D->usable_feat(tp, "grandmaster of the way"))
    {
        USER_D->init_pool(tp, "ki");
    }
    if (tp->is_class("magus"))
    {
        USER_D->init_pool(tp, "arcana");
    }
    if (tp->is_class("paladin") || tp->is_class("cleric"))
    {
        USER_D->init_pool(tp, "grace");
    }
    if (tp->is_class("psion") || tp->is_class("psywarrior"))
    {
        USER_D->init_pool(tp, "focus");
    }
    return ret;
}

string previous_title(object tp){
    string pre, post, str;

    str = (string)tp->getenv("TITLE");
    if (sscanf(str, "%s $N %s", pre, post) != 2) {
        sscanf(str, "$N %s", post);
    }
    return post;
}

void log_death(string str) { log_file("kills", str);}

void class_news(string myclass, string mess){
    object *who,*who_to;
    int i;

    who = ({});
    who_to = ({});
    for (i=0;i<sizeof(who = users());i++) {
        if (((string)who[i]->is_class(myclass)) || (wizardp(who[i])))
            who_to += ({ who[i]});
    }
    for (i=0;i<sizeof(who_to);i++)
        message("combat","%^BOLD%^"+capitalize(myclass)+" News: "+mess,who_to[i]);
    return;
}

void diety_news(string diety, string mess){
    object *who,*who_to;
    int i;

    who = ({});
    who_to = ({});
    for (i=0;i<sizeof(who = users());i++) {
        if ((string)who[i]->query_diety()==diety || wizardp(who[i]))
            who_to += ({ who[i]});
    }
    for (i=0;i<sizeof(who_to);i++)
        message("combat","%^BOLD%^"+capitalize(diety)+" News: "+mess,who_to[i]);
    return;
}

int m_exp(int a, int b){
    int answer, i;

    if ( b == 0 ) {
        return 1;
    }
    answer = a;
    for (i=0;i < b-1;i++)
        answer *= a;
    return answer;
}

/**
 * Rolls hp points character gets at a level in given class
 *
 * @param cl  class
 * @param con con bonus moved to std/living/body.c, kept here for call compatibility
 * @param lev level we roll hp for
 * @param tp  player object
 * @result HP we will get
 */
int get_hp_bonus(string cl, int con, int lev,object tp)
{
    string file;
    int hpbonus,dice,extra,roll_1,roll_2,*rolls;

    if(!objectp(tp))
        return 1;

    if(lev > 100 || lev < 1)
        return 1;

    rolls = allocate(110);

    if(!pointerp(tp->query("hp_array")))
    {
        tp->set("hp_array",rolls);
    }
    else
    {
        rolls = tp->query("hp_array");
    }

    if(sizeof(tp->query("hp_array")) < 110)
    {
        rolls = tp->query("hp_array");
        rolls += allocate((100-sizeof(rolls)));
    }

    file     = DIR_CLASSES+"/"+cl+".c";

    if(!file_exists(file))
    {
        return notify_fail("No class file for "+cl+"");
    }

    extra = 2;
    dice  = file->hit_dice(tp) + extra;

    // We need to roll hitpoints all the way up to level 40, otherwise
    // the order in which you pick your classes will give a mechanical
    // advantage.  Other thought was doing it in 5 level blocks roll
    // first 5, get the second 5 set, but seems like the less
    // complicated we make it, the better off we will be -Ares
    // This comment refers to logic in query_max_hp_base() in std/living/body.c -Illy

    if(rolls[lev])
    {
        hpbonus = rolls[lev];
    }
    else
    {
        hpbonus = dice * 3 / 4;

        if(lev == 1)
            hpbonus = dice;
    }

    if(lev < sizeof(rolls) - 1)
    {
        rolls[lev] = hpbonus;
        tp->set("hp_array",rolls);
    }

    if(hpbonus < 1) { return 1; }
    return hpbonus;
}
