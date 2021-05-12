/**
 * @file
 * @brief User library with user-related calculations.
 */

#include <std.h>
#include <daemons.h>
#include <class_types.h>
#include <monks.h>
#include <favored_types.h>
#define ANSI(p) sprintf("%c["+(p)+"m", 27)
#define ESC(p) sprintf("%c"+(p), 27)

inherit DAEMON;
mapping RP_FLAGS;

void process_pkill_input(object who, mixed arg)
{
    object PK_OB;
    if(!objectp(who)) return;
    if(!arg) return;
    if(!objectp(PK_OB = present("pkill_tracking_object", who))) return;
    PK_OB->log_pkill_input(arg);
    return;
}

void reset_all_status_problems(object who)
{
    object *myFeats;
    int x;
    if (!objectp(who)) {
        return;
    }
    if (who->query("alternative world") && who->query_ghost()) {
        who->set("previous alternative world", who->query("alternative world"));
        who->delete("alternative world");
        who->delete("alternative world check");
    }
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
    string *INVALID = ({"/d/deku/dark/", "/d/islands/common/eldebaro/rooms/", "/d/islands/dallyh/marsh/rooms"});
    string match, *tmp = ({});
    if (!objectp(who)) {
        return rem;
    }
    if (!pointerp(arr)) {
        return rem;
    }
    if (!mapp(rem)) {
        return rem;
    }
    for (x = 0; x < sizeof(arr); x++) {
        if (!stringp(rem[arr[x]]) || rem[arr[x]] == "") {
            continue;
        }
        for (y = 0; y < sizeof(INVALID); y++) {
            match = rem[arr[x]];
            if (!stringp(match)) {
                continue;
            }
            //tell_object(who, "match = "+match);
            if (strsrch(match, INVALID[y]) != -1) {
                //tell_object(who, "Should be removing "+match);
                map_delete(rem, arr[x]);
                tmp += ({ arr[x] });
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
    return spend_pool(ob, amount, "ki");
}

int can_spend_ki(object ob, int amount)
{
    return can_spend_pool(ob, amount, "ki");
}

int has_ki(object ob)
{
    return has_pool(ob, "ki");
}

string *query_ki_spells(object ob)
{
    int level = ob->query_prestige_level("monk");
    return collapse_array(values(filter_mapping(MAGIC_D->index_ki_spells_by_level(ob), (:$1 <= $3:), level)));
}

int sort_ki_spells(int kiLev, int compLev)
{
    if(compLev >= kiLev) return 1;
    return 0;
}

void init_ki(object ob)
{
    int avail, newmax, oldmax, diff;
    string myWay;
    if(!objectp(ob)) return;
    if((int)ob->query_class_level("monk") < 2) return;
    //giving way of the elements 1.5 ki per level - may need some tweaking - Saide
    myWay = (string)ob->query("monk way");
    if(FEATS_D->usable_feat(ob,"grandmaster of the way")) { myWay = "grandmaster of the way"; }
    if(stringp(myWay))
    {
        if(myWay == "way of the elements" || myWay == "grandmaster of the way")
        {
            newmax = to_int((int)ob->query_guild_level("monk")*2);
        }
        else newmax = (int)ob->query_guild_level("monk");
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
    return;
}
//END OF MONK FUNCS :P

//Resource Functions, Wedex October 2020
//pool_type: ki, arcana, grace
//added focus for psionics, Tlaloc 2021
int spend_pool(object ob, int amount, string pool_type)
{
    int avail;
    if (!intp(amount)) {
        return 0;
    }
    if (!objectp(ob)) {
        return 0;
    }
    avail = (int)ob->query("available " + pool_type);
    if (amount > avail) {
        return 0;
    }
    avail -= amount;
    
    if(pool_type == "focus")
        tell_object(ob, "%^BOLD%^You lose your psionic focus.%^RESET%^");
    
    ob->set("available " + pool_type, avail);
    return 1;
}

int can_spend_pool(object ob, int amount, string pool_type)
{
    int avail;
    if (!intp(amount)) {
        return 0;
    }
    if (!objectp(ob)) {
        return 0;
    }
    avail = (int)ob->query("available " + pool_type);
    if (avail >= amount) {
        return 1;
    }
    return 0;
}

int has_pool(object ob, string pool_type)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (!ob->query("available " + pool_type)) {
        return 0;
    }
    return 1;
}

varargs void regenerate_pool(object ob, int amount, int pass, string pool_type)
{
    int avail, max, delay;
    if (!intp(amount)) {
        return 0;
    }
    if (!objectp(ob)) {
        return 0;
    }
    if (pass == 1 && (time() < (int)ob->query("last " + pool_type + " regen"))) {
        return;
    }
    avail = (int)ob->query("available " + pool_type);
    max = (int)ob->query("maximum " + pool_type);
    avail += amount;
    if (pool_type == "ki") {
        object class_ob;
        class_ob = find_object_or_load(DIR_CLASSES + "/monk.c");
        if (pass && (class_ob->monk_check(ob, "way of the fist")) && (int)ob->query_class_level("monk") > 10) {
            avail += 1;
        }
    }
    if (avail > max) {
        avail = max;
    }
    ob->set("available " + pool_type, avail);
    if (pass) {
        switch (pool_type) {
        case "arcana":
            if ((int)ob->is_class("magus")) {
                delay = 20 + roll_dice(6, 4);
                delay -= (int)BONUS_D->query_stat_bonus(ob, "intelligence");
                if (delay < 20) {
                    delay = 20;
                }
            }
            break;
        case "ki":
            if ((int)ob->is_class("monk")) {
                delay = 10 + roll_dice(3, 4);
                delay -= (int)BONUS_D->query_stat_bonus(ob, "wisdom");
                if (delay < 5) {
                    delay = 5;
                }
            }
            break;
        case "grace":
            if ((int)ob->is_class("paladin") || ob->is_class("cleric")) {
                delay = 30 + roll_dice(9, 4);
                if(ob->is_class("cleric"))
                    delay -= (int)BONUS_D->query_stat_bonus(ob, "wisdom");
                if(ob->is_class("paladin"))
                    delay -= (int)BONUS_D->query_stat_bonus(ob, "charisma");
                if (delay < 40) {
                    delay = 40;
                }
            }
            break;
        //Focus is either 1 or 0
        case "focus":
            if(ob->is_class("psion") || ob->is_class("psywarrior"))
            {
                delay = 90;
                delay -= BONUS_D->query_stat_bonus(ob, "intelligence");
            }
            break;

        }
        ob->set("last " + pool_type + " regen", time() + delay);
    }
    return;
}

void init_pool(object ob, string pool_type)
{
    int avail, newmax, oldmax, diff, divisor;
    if (!objectp(ob)) return;

    switch (pool_type) {
    case "arcana":
        if (!(int)ob->is_class("magus")){
            ob->delete("available " + pool_type);
            ob->delete("maximum " + pool_type);
            return;
        }else {
            divisor = 2;
            if (FEATS_D->usable_feat(ob, "greater arcane pool")) {
                divisor = 1;
            }
            newmax = (int)ob->query_class_level("magus") / divisor;
            newmax = (newmax > 0 ? newmax : 1) + (int)BONUS_D->query_stat_bonus(ob, "intelligence");
        }
        break;
    case "ki":
        if ((int)ob->query_class_level("monk") < 2) {
            ob->delete("available " + pool_type);
            ob->delete("maximum " + pool_type);
            return;
        }
        else {
            string myWay;
            myWay = (string)ob->query("monk way");
            if (FEATS_D->usable_feat(ob, "grandmaster of the way")) { myWay = "grandmaster of the way"; }
            if (stringp(myWay))
            {
                if (myWay == "way of the elements" || myWay == "grandmaster of the way")
                {
                    newmax = to_int((int)ob->query_guild_level("monk") * 2);
                }
                else newmax = (int)ob->query_guild_level("monk");
            }
            else newmax = (int)ob->query_class_level("monk");
        }
        break;
    case "grace":
        if ((int)ob->query_class_level("paladin") < 1 && ob->query_class_level("cleric") < 1) {
            ob->delete("available " + pool_type);
            ob->delete("maximum " + pool_type);
            return;
        }
        else {
            newmax = 2 + (int)ob->query_class_level("paladin") / 10 + ob->query_class_level("cleric") / 10;
            newmax += (FEATS_D->usable_feat(ob, "extra grace") * 2);
        }
        break;
    case "focus":
        if(!ob->is_class("psion") && !ob->is_class("psywarrior"))
        {
            ob->delete("available " + pool_type);
            ob->delete("maximum " + pool_type);
            return;
        }
        else
        {
            newmax = 1;
        }
    }
    if (!intp(avail = (int)ob->query("available " + pool_type))) avail = newmax;
    if (intp(oldmax = (int)ob->query("maximum " + pool_type)))
    {
        diff = newmax - oldmax;
        avail += diff;
    }
    ob->set("available " + pool_type, avail);
    ob->set("maximum " + pool_type, newmax);
    return;
}
//END of Generic Resource

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
    rname = file_name(environment(who));
    cur_flags = keys(RP_FLAGS);
    myName = who->query_true_name();
    message("info","%^BOLD%^%^WHITE%^RP Spears impale the ground of "+rname->query_short()+"\n",users());
    IPC->ipc_send_all("SPEAR:RP Spears impale the ground of " + strip_colors(rname->query_short()) + "\n");
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
    int lev;
    if(!objectp(who))
        return 50;
    lev = (int)who->query_base_character_level();
    if(lev>20&&lev<51)
        ret = 50+50*lev/60;
    else
        ret = 50;
    ret += who->query("ctp");
    if(ret < 50)
        ret= 50;
    if(ret > 100)
        ret = 100;
    return ret;
}

int set_character_improvement_tax_percent(object who, int perc)
{
    int base, lev;
    if(!objectp(who)) return 0;
    perc = to_int(perc);
    lev = (int)who->query_base_character_level();
    if(lev>20&&lev<51)
        base = 50+50*lev/60;
    else
        base = 50;

    if(perc<base)
    {
        tell_object(who,"%^BOLD%^%^WHITE%^Your character improvement tax can't be less than %^CYAN%^"+base+"%^WHITE%^.");
        tell_object(who,"%^BOLD%^%^WHITE%^Forcing it to be set at %^CYAN%^"+base+"%^WHITE%^.");
        perc=base;
        who->set("ctp", perc-base);
        return 0;
    }
    if(perc>100)
    {
        tell_object(who,"%^BOLD%^%^WHITE%^Your character improvement tax can't be more than %^CYAN%^100");
        return 0;
    }
    who->set("ctp", perc-base);
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
        case "feature notifications":
            if(!who->query("feature notifications")) return "On";
            return "Off";
            break;
        case "simple inventory":
            if(!who->query("simple inventory")) return "Off";
            return "On";
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
        tell_object(who, "%^BOLD%^%^WHITE%^You scale your character level down to "+lev+".");
        hp_perc = percent(who->query_hp(), who->query_max_hp());
        who->set("scaledlevel", lev);
        new_hp = (to_float(who->query_max_hp()) / 100) * hp_perc;
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

varargs mapping myTerm(object who, int flag)
{
    string ret, term;
    mapping tmp;
    if(objectp(who))
    {
        term=who->getenv("TERM");
        if (!TERMINAL_D->query_term_support(term))
            term="unknown";
        if(flag)
            term="ansi";
    }
    else
        term="unknown";

    return TERMINAL_D->query_term_info(term);
}

string* determine_lines(object who)
{
    int i;
    string* gstore, * mychannels = ({}), * restricted_channels = ({}), myclasses = ({});
    if (!objectp(who)) {
        return ({});
    }
    restricted_channels = who->query_restricted_channels();

    mychannels = ({ "newbie", "ooc", "wiz" });

    if (avatarp(who)) {
        mychannels += ({ "discuss", });
    }

    if (avatarp(who) &&
        !wizardp(who)) {
        mychannels += ({ "telepathy", "petition", "avatar" });
    }

    if (member_group(who->query_true_name(), "law_c")) {
        mychannels += ({ "law" });
    }
    CHAT_D->add_user(mychannels, who);
    return mychannels;
}

mixed query_mini_quest_info(object who, string quest, string qInfo)
{
    mapping whoQuests;
    string *quests;
    if(!objectp(who) || !sizeof(quests = keys(whoQuests = who->query_mini_quest_map())) || member_array(quest, quests) == -1)
    {
        if(qInfo == "time") return -1;
        return "This quest has no description";
    }
    if(qInfo == "time") return whoQuests[quest][0];
    return whoQuests[quest][1];
}

int is_valid_enemy_cat(string str)
{
    if (member_array(str, keys(VALID_ENEMY)) != -1) {
        return 1;
    }

    return 0;
}

int is_valid_enemy(string id, string cat)
{
    if (member_array(id, VALID_ENEMY[cat]) != -1) {
        return 1;
    }

    return 0;
}

int is_valid_terrain_cat(string str)
{
    if (member_array(str, keys(VALID_TERRAIN)) != -1) {
        return 1;
    }

    return 0;
}

int is_valid_terrain(string id, string cat)
{
    if (member_array(id, VALID_TERRAIN[cat]) != -1) {
        return 1;
    }

    return 0;
}

/**
 * Checks whether player belongs to pk race.
 * Used to drop pk flag and is intended for infreequent use.
 */
int is_pk_race_player(object ob)
{
    string racefile;

    racefile = "/std/races/" + ob->query("race") + ".c";

    if (file_exists(racefile)) {
        if (ob->query("no pk")) {
            if (racefile->is_pk_race(ob->query("subrace")) ||
                ob->is_undead()) {
                return 1;
            }
        }
    }

    return 0;
}
