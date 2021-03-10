/*====================================
New User Daemon to cut out some functions
from the user chain - starting small - Saide, November 2016


=====================================*/
#include <std.h>
#include <daemons.h>
#include <monks.h>
#define ANSI(p) sprintf("%c["+(p)+"m", 27)
#define ESC(p) sprintf("%c"+(p), 27)

inherit DAEMON;
mapping RP_FLAGS;

void reset_all_status_problems(object who)
{
    object *myFeats;
    int x;
    if(!objectp(who)) return;
    POISON_D->ClearAllPoisons(who);
    who->set_bound(0,0);
    who->set_blind(0);
    who->set_blindfolded(0);
    who->set_temporary_blinded(0);
    who->set_tripped(0,0);                                                       
    who->set_unconscious(0,0);
    who->set_gagged(0,0);                                                          
    who->set_asleep(0,0);
    who->remove_paralyzed();          
    who->remove_all_disable();
    myFeats = (object *)who->query_property("active_feats");
    if(pointerp(myFeats))
    {
        for(x = 0;x < sizeof(myFeats);x++)
        {
            if(objectp(myFeats[x])) myFeats[x]->dest_effect();
            continue;
        }
    }
    if(who->query("negative level")) who->delete("negative level");
    if(!avatarp(who))
    {
        if(who->query_invis())
        {
            who->set_magic_hidden(0);
            who->set_invis();
        }
    }
}

mixed check_rem_rooms(object who, string *arr, mapping rem)
{
    int x, y, flag = 0;
    string *INVALID = ({"/d/deku/dark/", "/d/islands/common/eldebaro/rooms/"});
    string match, *tmp = ({});
    if(!objectp(who)) return rem; 
    if(!pointerp(arr)) return rem;
    if(!mapp(rem)) return rem;
    for(x = 0;x < sizeof(arr);x++)
    {
        for(y = 0;y < sizeof(INVALID);y++)
        {
            match = rem[arr[x]];
            if(!stringp(match)) continue;
            //tell_object(who, "match = "+match);
            if(strsrch(match, INVALID[y]) != -1)
            {
                //tell_object(who, "Should be removing "+match);
                map_delete(rem, arr[x]);
                tmp += ({arr[x]});
                flag = 1;
                continue;
            }
            //tell_object(who, "Not removing "+match);
            continue;
        }
        continue;
    }        
    if(flag) 
    {
        arr -= tmp;
        who->set_rem_rooms(rem, arr);
    }
    return rem;
}

/*Monk Ki Functions, Saide November 2016 */

int spend_ki(object ob, int amount)
{
    int avail;
    if(!intp(amount)) return 0;
    if(!objectp(ob)) return 0;
    avail = (int)ob->query("available ki");
    if(amount > avail) return 0;
    avail -= amount;
    ob->set("available ki", avail);
    return 1;
}

int can_spend_ki(object ob, int amount)
{
    int avail;
    if(!intp(amount)) return 0;
    if(!objectp(ob)) return 0;
    avail = (int)ob->query("available ki");
    if(avail >= amount) return 1;
    return 0;
}

int has_ki(object ob)
{
    if(!objectp(ob)) return 0;
    if(!ob->query("available ki")) return 0;
    return 1;
}

string *query_ki_spells(object ob)
{
    string *ki_spells = ({});
    if(!objectp(ob)) return ki_spells;
    if(!ob->is_class("monk")) return ki_spells;
    if(pointerp(ki_spells = ob->query("ki spells")))
    {
        return ki_spells;
    }
    return ({});
}

void remove_ki_spell(object ob, string str)
{    
    string *ki_spells;
    if(!objectp(ob)) return;
    if(!stringp(str)) return;
    ki_spells = ob->query_ki_spells();
    if(member_array(str, ki_spells) != -1)
    {
        ki_spells -= ({str});
        ob->delete("ki spells");
        ob->set("ki spells", ki_spells);
        return;
    }
    return;
}

void add_ki_spell(object ob, string str)
{
    string *ki_spells;
    if(!objectp(ob)) return;
    if(!stringp(str)) return;
    ki_spells = ob->query_ki_spells();
    if(member_array(str, ki_spells) == -1)
    {
        ki_spells += ({str});
        ob->delete("ki spells");
        ob->set("ki spells", ki_spells);
        return;
    }
    return;
}

varargs void regenerate_ki(object ob, int amount, int pass)
{
    int avail, max, delay;
    if(!intp(amount)) return 0;
    if(!objectp(ob)) return 0;
    if(pass == 1 && (time() < (int)ob->query("last ki regen"))) return;
    avail = (int)ob->query("available ki");
    max = (int)ob->query("maximum ki");
    avail += amount;
    if(pass && (string)ob->query("monk way") == "way of the fist" && (int)ob->query_class_level("monk") > 10) avail += 1;
    if(avail > max) avail = max;
    ob->set("available ki", avail);
    if(pass)
    {
        delay = 10 + random(11);
        delay -= (int)"/daemon/bonus_d.c"->query_stat_bonus(ob, "wisdom");
        if(delay < 5) delay = 5;
        ob->set("last ki regen", time() + delay);
    }
    return;
}

int sort_ki_spells(int kiLev, int compLev)
{
    if(compLev >= kiLev) return 1;
    return 0;    
}

void init_ki_spells(object ob, string myWay)
{
    int myLev, x, *kiLevels;
    string *myMastered, *ShouldHave;
    mapping kiSpells;
    if(!objectp(ob)) return;
    if(!stringp(myWay)) return;
    if(myWay != "way of the shadow" && myWay != "way of the elements") return;
    myLev = ob->query_class_level("monk");
    myMastered = ob->query_ki_spells();
    ShouldHave = ({});            
    if(!mapp(kiSpells = KI_SPELLS[myWay])) return;
    kiLevels = keys(kiSpells);
    if(!sizeof(kiLevels)) return;    
    //should sort the array so that only 
    //ki spell levels of less than or equal to the 
    //monk's level show up 
    kiLevels = filter_array(kiLevels, "sort_ki_spells", "/daemon/user_d.c", myLev);    
    //tell_object(find_player("saide"), "kiLevels = "+identify(kiLevels));
    for(x = 0;x < sizeof(kiLevels);x++)
    {
        if(pointerp(kiSpells[kiLevels[x]])) ShouldHave += kiSpells[kiLevels[x]];
        continue;
    }
    //tell_object(find_player("saide"), "ShouldHave = "+identify(ShouldHave));
    myMastered -= ShouldHave;   
    //tell_object(find_player("saide"), "myMastered = "+identify(myMastered));
    if(sizeof(myMastered))
    {
        for(x = 0;x < sizeof(myMastered);x++)
        {
            if(objectp(ob)) remove_ki_spell(ob, myMastered[x]);
            continue;
        }
    }
    myMastered = ob->query_ki_spells();
   // tell_object(find_player("saide"), "myMastered = "+identify(myMastered));
    ShouldHave -= myMastered;
    //tell_object(find_player("saide"), "ShouldHave = "+identify(ShouldHave));
    if(sizeof(ShouldHave))
    {
        for(x = 0;x < sizeof(ShouldHave);x++)
        {
            if(member_array(ShouldHave[x], myMastered) != -1) continue;
            if(objectp(ob)) add_ki_spell(ob, ShouldHave[x]);
            continue;
        }
    }
    return;    
}

void init_ki(object ob)
{
    int avail, newmax, oldmax, diff;
    string myWay;
    if(!objectp(ob)) return;
    if((int)ob->query_class_level("monk") < 2) return;
    //giving way of the elements 1.5 ki per level - may need some tweaking - Saide
    myWay = (string)ob->query("monk way");
    if(stringp(myWay))
    {
        if(myWay == "way of the elements")
        {
            newmax = to_int((int)ob->query_class_level("monk")*2);
        }
        else newmax = (int)ob->query_class_level("monk");
    }
    else newmax = (int)ob->query_class_level("monk");
    if(!intp(avail = (int)ob->query("available ki"))) avail = newmax;
    if(intp(oldmax = (int)ob->query("maximum ki")))
    {
        diff = newmax - oldmax;
        avail += diff;
    }
    ob->set("available ki", avail);
    ob->set("maximum ki", newmax);
    if(stringp(myWay))
    {
        if(myWay == "way of the elements" || myWay == "way of the shadow")
        {
            init_ki_spells(ob, myWay);
            return;
        }
        else 
        {
            ob->delete("ki spells");
            return;
        }
    }
    return;
}
//END OF MONK FUNCS :P

//various FLAG command Functions
int no_exp(object who)
{
    if(!objectp(who)) return 0;
    if(!who->query("noexp")) return 0;
    return 1;
}

string *get_environments()
{
    object *usrs;
    string *envs = ({});
    int x;
    usrs = users();
    for(x = 0;x < sizeof(usrs);x++)
    {
        if(!objectp(usrs[x])) continue;
        if(!objectp(environment(usrs[x]))) continue;
        envs += ({base_name(environment(usrs[x]))});
        continue;
    }
    return envs;
}

void clean_up_old_flags()
{
    int x;
    string *misc_flags, to_remove, to_add;
    string oroom;
    object OldRoom, player;
    if(!mapp(RP_FLAGS) || !sizeof(keys(RP_FLAGS))) return;
    if(!pointerp(misc_flags = keys(RP_FLAGS))) return;
    to_add = ({});
    for(x = 0;x < sizeof(misc_flags);x++)
    {          
        if(misc_flags[x] == "MiscFlags") continue;
        oroom = RP_FLAGS[misc_flags[x]];
        OldRoom = find_object_or_load(oroom);
        if(!objectp(OldRoom))
        {
            map_delete(RP_FLAGS, misc_flags[x]);
            continue;
        }
        if(!sizeof(filter_array(all_living(OldRoom), "is_non_immortal_player", FILTERS_D)))
        {
            map_delete(RP_FLAGS, misc_flags[x]);
            continue;
        }        
        if(!objectp(player = find_player(misc_flags[x])))
        {
            map_delete(RP_FLAGS, misc_flags[x]);
            to_add += ({oroom});
            continue;
        }        
        if(environment(player) != OldRoom)
        {
            map_delete(RP_FLAGS, misc_flags[x]);
            to_add += ({oroom});
            continue;
        }
    }    
    if(!pointerp(misc_flags = RP_FLAGS["MiscFlags"])) 
    {
        if(sizeof(to_add)) RP_FLAGS["MiscFlags"] = to_add;
        return;
    }    
    //tell_object(find_player("saide"), "miscflags = "+identify(misc_flags));
    to_remove = ({});
    for(x = 0;x < sizeof(misc_flags);x++)
    {
        oroom = misc_flags[x];
        OldRoom = find_object_or_load(oroom);
        if(!objectp(OldRoom))
        {
            to_remove += ({oroom});
            continue;
        }
        if(!sizeof(filter_array(all_living(OldRoom), "is_non_immortal_player", FILTERS_D)))
        {
            to_remove += ({oroom});
            continue;
        }        
    }
    misc_flags -= to_remove;
    misc_flags += to_add;
    misc_flags = distinct_array(misc_flags);
    RP_FLAGS["MiscFlags"] = misc_flags;
    
    return;
}

mapping identify_rp_flags() { return identify(RP_FLAGS); }

mixed *get_rp_flags()
{
    object *RP_ROOMS, CurRoom;
    string *flag_keys, room_file, *rpflags, *miscflags;
    int x, y;
    if(!mapp(RP_FLAGS) || !sizeof(keys(RP_FLAGS))) return ({});
    clean_up_old_flags();
    RP_ROOMS = ({});
    rpflags = keys(RP_FLAGS);
    for(x = 0;x < sizeof(rpflags);x++)
    {
        if(rpflags[x] == "MiscFlags")
        {
            miscflags = RP_FLAGS["MiscFlags"];
            for(y = 0;y < sizeof(miscflags);y++)
            {
                room_file = miscflags[y];
                if(!objectp(CurRoom = find_object_or_load(room_file))) continue;
                RP_ROOMS += ({CurRoom});
                continue;
            }
            continue;
        }
        room_file = RP_FLAGS[rpflags[x]];
        if(!objectp(CurRoom = find_object_or_load(room_file))) continue;
        RP_ROOMS += ({CurRoom});
        continue;        
    }
    if(sizeof(RP_ROOMS)) { RP_ROOMS = distinct_array(RP_ROOMS); return RP_ROOMS; }
    return ({});
}

void setup_rp_flag(object who)
{
    object old_room;
    string *cur_flags, *cur_misc_flags;
    string myName, rname, oname;
    if(!objectp(who)) return;
    if(!mapp(RP_FLAGS) || !sizeof(keys(RP_FLAGS))) RP_FLAGS = ([]);
    if(!objectp(environment(who))) return;
    clean_up_old_flags();
    rname = base_name(environment(who));    
    cur_flags = keys(RP_FLAGS);
    myName = who->query_true_name();
    if(member_array(myName, cur_flags) == -1)
    {
        RP_FLAGS += ([myName : rname ]);
        return 1;        
    }
    else
    {
        oname = RP_FLAGS[myName];
        old_room = find_object_or_load(oname);
        if(!objectp(old_room))
        {
            RP_FLAGS[myName] = rname;
        }
        else
        {
            if(sizeof(filter_array(all_living(old_room), "is_non_immortal_player", FILTERS_D)))
            {
                if(RP_FLAGS["MiscFlags"])
                {
                    cur_misc_flags = RP_FLAGS["MiscFlags"];
                    if(member_array(oname, cur_misc_flags) == -1) cur_misc_flags += ({oname});
                    RP_FLAGS["MiscFlags"] = cur_misc_flags;
                }
                else
                {
                    cur_misc_flags = ({oname});
                    RP_FLAGS["MiscFlags"] = cur_misc_flags;
                }
            }
            else
            {
                if(RP_FLAGS["MiscFlags"])
                {
                    cur_misc_flags = RP_FLAGS["MiscFlags"];
                    if(member_array(oname, cur_misc_flags) != -1) cur_misc_flags -= ({oname});
                    RP_FLAGS["MiscFlags"] = cur_misc_flags;                    
                }
            }
        }
        return 1;
    }    
}

int toggle_no_exp(object who)
{
    int cur;
    if(!objectp(who)) return 0;
    cur = to_int(who->query("noexp"));
    if(!cur)
    {
        tell_object(who, "%^BOLD%^%^WHITE%^You are disabling "+
        "experience, you will no longer gain ANY.%^RESET%^");
        who->set("noexp", 1);
        return 1;
    }
    if(cur)
    {
        tell_object(who, "%^BOLD%^%^WHITE%^You are enabling "+
        "experience, you will now gain it as you normally "+
        "would.%^RESET%^");
        who->set("noexp", 0);
        return 1;
    }
    return 0;
}

int get_character_improvement_tax_percent(object who)
{
    int ret;
    if(!objectp(who)) return 50;
    ret = who->query("ctp");
    if(ret < 50) return 50;
    if(ret > 100) return 100;
    return ret;
}

int set_character_improvement_tax_percent(object who, int perc)
{
    int cur;
    if(!objectp(who)) return 0;
    perc = to_int(perc);    
    if(perc < 50) 
    {
        tell_object(who, "%^BOLD%^%^RED%^Your %^CYAN%^character improvement"+
        " tax%^RED%^ percentage cannot be set to less than 50.");
        return 1;
    }
    if(perc > 100)
    {
        tell_object(who, "%^BOLD%^%^RED%^Your %^CYAN%^character improvement"+
        " tax%^RED%^ percentage cannot be set to more than 100.");
        return 1;
    }
    cur = who->query("ctp");
    if(!cur || cur < 50 || cur > 100) cur = 50;
    tell_object(who, "%^BOLD%^%^WHITE%^Adjusting your %^CYAN%^character improvement "+
    "tax%^BOLD%^%^WHITE%^ from "+cur+" to "+perc+". This means that "+perc+"% of "+
    "all future gained experience will go toward paying off any character improvement "+
    "taxes that you have.%^RESET%^");
    who->set("ctp", perc);
    return 1;
}

mixed get_flag(object who, string flag)
{
    int check;
    object where;
    if(!objectp(who)) return "ERROR";
    if(!stringp(flag)) return "ERROR";
    switch(flag)
    {
        case "experience gain":
            check = no_exp(who);
            if(check) return "Off";
            else return "On";
            break;
        case "character improvement tax":
            return get_character_improvement_tax_percent(who) + "%";
            break;
        case "roleplay flag":
            where = environment(who);
            if(!objectp(where)) return "None";
            if(member_array(where, get_rp_flags()) == -1) return "None";
            return "Flying";
            break;
        case "player kill":
            if(!who->query("no pk")) return "Enabled";
            return "Disabled";
            break;
        case "scaled level":
            if(!to_int(who->query("scaledlevel"))) return "No";
            return "Scaled to "+who->query("scaledlevel");
            break;
    }
    return "Unsupported";
}

varargs mixed get_scaled_class_level(object who, string myclass)
{   
    float bc, tl;
    int clvl, sc;
    if(!objectp(who)) return "NIL";
    if(!intp(sc = who->query("scaledlevel")) || sc < 6) return "NIL";
    if(!stringp(myclass)) return sc;
    tl = to_float(who->query_base_character_level());
    bc = to_float(who->query_base_class_level(myclass));
    clvl = to_int((bc/tl)*sc);
    if(clvl < 1) clvl = 1;
    return clvl;
}

mixed get_scaled_level(object who)
{
    if(!objectp(who)) return "NIL";
    if(!intp(who->query("scaledlevel")) || who->query("scaledlevel") < 6) return "NIL";
    return to_int(who->query("scaledlevel"));
}

void scale_level_to(object who, int lev)
{
    //stuff to finish - 1. item scaling, 2. hp scaling
    object *inv;
    int base, i, ac;
    float hp_perc, new_hp;
    string myName;
    if(!objectp(who)) return;
    if(!intp(lev)) return;
     base = who->query_base_character_level();
    if(lev == base)
    {
        if((int)who->query("scaledlevel") < 1)
        {
            tell_object(who, "You level is currently not scaled down.");
            return 1;
        }
        hp_perc = percent(who->query_hp(), who->query_max_hp());
        who->delete("scaledlevel");
        new_hp = (to_float(who->query_max_hp()) / 100) * hp_perc;
        who->set_hp(to_int(new_hp));
        ac = 10;
        who->set_ac(ac);
        inv = deep_inventory(who);
        myName = who->query_true_name();
        for(i = 0;i < sizeof(inv);i++)
        {
            if(!objectp(inv[i])) continue;
            if(inv[i]->query_worn() || inv[i]->query_wielded())
            {
                if((string)inv[i]->query("scaledfor") == myName) 
                {
                    inv[i]->run_item_bonuses("remove",who,inv[i]->query_item_bonuses());
                    inv[i]->delete("scaledlevel");
                    inv[i]->delete("scaledfor");
                    inv[i]->run_item_bonuses("equip",who,inv[i]->query_item_bonuses());
                }
                if(inv[i]->query_ac() && inv[i]->is_armour()) ac -= (int)inv[i]->query_ac();                
            }            
            else if((string)inv[i]->query("scaledfor") == myName)
            {
                inv[i]->delete("scaledlevel");
                inv[i]->delete("scaledfor");
            }
            continue;
        }
        who->set_ac(ac);
        tell_object(who, "You revert your character level back to normal.");
        return 1;
    }
    else
    {
        who->delete("scaledlevel");
        tell_object(who, "%^BOLD%^%^WHITE%^You scale your character level down to "+lev+
        " please NOTE this is highly experimental as Saide tries to work out any unforseen "+
        "kinks so use at YOUR OWN RISK and immediately BUG REPORT anything out of whack.");
        hp_perc = percent(who->query_hp(), who->query_max_hp());    
        //tell_object(who, "hp_perc = "+hp_perc);
        who->set("scaledlevel", lev);
        new_hp = (to_float(who->query_max_hp()) / 100) * hp_perc;   
        //tell_object(who, "new_hp = "+new_hp);
        who->set_hp(to_int(new_hp));
        inv = deep_inventory(who);
        myName = who->query_true_name();
        who->break_all_spells();
        ac = 10;
        who->set_ac(ac);
        for(i = 0;i < sizeof(inv);i++)
        {
            if(!objectp(inv[i])) continue;
            if(inv[i]->query_worn() || inv[i]->query_wielded())
            {
                inv[i]->run_item_bonuses("remove",who,inv[i]->query_item_bonuses());
                inv[i]->set("scaledlevel", lev);
                inv[i]->set("scaledfor", myName);
                inv[i]->run_item_bonuses("equip",who,inv[i]->query_item_bonuses());
                if(inv[i]->query_ac() && inv[i]->is_armour()) ac -= (int)inv[i]->query_ac();                
            }            
            else 
            {
                inv[i]->set("scaledlevel", lev);
                inv[i]->set("scaledfor", myName);
            }
            continue;
        }
        who->set_ac(ac);        
        return 1;
    }
}

mapping myTerm(object who) 
{
    string ret;
    mapping tmp;
    if(objectp(who))
    {
        switch(who->getenv("TERM"))
        {
            case "ansi":        
                tmp = ([ "RESET":ANSI("0;37;40"), "BOLD":ANSI(1), "ULINE":ANSI(4), "FLASH":ANSI(5),
                "BLACK":ANSI(30), "RED":ANSI(31), "GREEN":ANSI(32),
                "ORANGE":ANSI(33),"YELLOW":ANSI(1)+ANSI(33), "BLUE": ANSI(34),
                "CYAN":ANSI(36), "MAGENTA":ANSI(35), "BLACK":ANSI(30),
                "WHITE": ANSI(37), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
                "B_ORANGE":ANSI(43), "B_YELLOW":ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
                "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
                "CLEARLINE":ESC("[L")+ESC("[G"), "B_MAGENTA":ANSI(45), "STATUS":"",
                "WINDOW":"", "INITTERM":ESC("[H")+ESC("[2J"), "ENDTERM":"" ]);
                break;
            default:
                tmp = ([ "RESET": "", "BOLD": "", "ULINE": "", "FLASH":"", "BLACK":"", "RED":"",
                "BLUE":"", "CYAN":"", "MAGENTA":"", "ORANGE":"", "YELLOW":"",
                "GREEN":"", "WHITE":"", "BLACK":"", "B_RED":"", "B_ORANGE":"",
                "B_YELLOW":"", "B_BLACK":"", "B_CYAN":"","B_WHITE":"", "B_GREEN":"",
                "B_MAGENTA":"", "STATUS":"", "WINDOW":"", "INITTERM": "",
                "ENDTERM":""]);
                break;
        }
    }
    else
    {
        tmp = ([ "RESET":ANSI(37)+ANSI(1)+ANSI(37), "BOLD":ANSI(1), "ULINE":ANSI(4), "FLASH":ANSI(5),
        "BLACK":ANSI(30), "RED":ANSI(31), "GREEN":ANSI(32),
        "ORANGE":ANSI(33),"YELLOW":ANSI(1)+ANSI(33), "BLUE": ANSI(34),
        "CYAN":ANSI(36), "MAGENTA":ANSI(35), "BLACK":ANSI(30),
        "WHITE": ANSI(37), "B_RED":ANSI(41), "B_GREEN":ANSI(42),
        "B_ORANGE":ANSI(43), "B_YELLOW":ANSI(1)+ANSI(43), "B_BLUE":ANSI(44),
        "B_CYAN":ANSI(46), "B_BLACK":ANSI(40), "B_WHITE": ANSI(47),
        "CLEARLINE":ESC("[L")+ESC("[G"), "B_MAGENTA":ANSI(45), "STATUS":"",
        "WINDOW":"", "INITTERM":ESC("[H")+ESC("[2J"), "ENDTERM":"" ]);
    }
    return tmp;
}
