// Fixed typo in bounty collection 8/7/02, last change had been 11/30/02  *Styx*
// removed automatic alignment changes *Styx* 1/14/04, last change 8/8/03
// (noted MC) disabling mycause until better system developed *Styx* 5/21/06, last chg. 3/21/05
// Reactivating mycause system based on renown rather than purely alignment actions. Nienne, 02/10.
// Dual factors influence; renown, once it reaches 200 (20 per PK) will add you to the mycause list.
// The old alignment adjustments will determine, at this point, whether you are added to the evil, neutral or good list.

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <dieties.h>

#define SAVE_KILLS "/daemon/save/kills"

inherit DAEMON;

mapping __newBounties;
mapping __newBountiesAlias;
mapping __Personal_Bounties;
string *__Evil;
string *__Good;
string *__Neutral;

protected void SAVE() {
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_KILLS);
    seteuid(getuid());
}

void create() {
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_KILLS);
    seteuid(getuid());

    if (!__newBounties) __newBounties = ([]);
    if (!__newBountiesAlias) __newBountiesAlias = ([]);
    if (!__Personal_Bounties) __Personal_Bounties = ([]);
    if (!__Good) __Good = ({});
    if (!__Evil) __Evil = ({});
    if (!__Neutral) __Neutral = ({});
    SAVE();
}

void do_bad_pkill(object attacker, object victim) {
    // if attacker is collecting a bounty on victim, do nothing
    if (legal_bounty(victim, attacker)) return;
    if (personal_bounty(attacker, victim)) return;
}

void check_actions(object attacker, object victim) {
    int number, align, myrenown, myalignmod;
    string *akills, *vkills;
    object *a_atk, *v_atk;

    if (!objectp(attacker) || !objectp(victim)) {
        return;
    }
    if (member_array(victim->query_name(), keys(__newBounties)) != -1) {
        return;
    }
    a_atk = attacker->query_attackers();
    v_atk = victim->query_attackers();
    if (!pointerp(a_atk)) {
        a_atk = ({});
    }
    if (!pointerp(v_atk)) {
        v_atk = ({});
    }
    if (member_array(victim, a_atk) != -1) {
        return;
    }
    if (member_array(attacker, v_atk) != -1) {
        return;
    }
    if (pointerp(victim->query_atnames()) && sizeof(victim->query_atnames())) {
        if (member_array(attacker->query_name(), victim->query_atnames()) != -1) {
            return;
        }
    }

    // if victim is not interactive or not a monster with alignment changing properties, do nothing
    if (!(number = victim->query_property("alignment adjustment")) && !userp(victim)) {
        return;
    }

}

protected int personal_bounty(object attacker, object victim) {
    int money;
    string who, *pkilled, *pkilled2;
    int palign, aalign, valign, exp;

    if (member_array((string)victim->query_name(),keys(__Personal_Bounties)) == -1) return 0;
    if (!attacker->query("is_assassin")) return 0;

    // victim has a personal bounty, do collection for attacker
    money = __Personal_Bounties[victim->query_name()]["money"];
    who = __Personal_Bounties[victim->query_name()]["poster"];
    map_delete(__Personal_Bounties, victim->query_name());
    SAVE();

    exp = (int)victim->query_lowest_level() * 5000;

    // announce bounty collection, add money to attacker, set mini quest
    pbounty_shout((string)attacker->query_name(), (string)victim->query_name(), who);
    log_file("bounties",">>>"+capitalize(attacker->query_name())+" collected the personal bounty on "+capitalize(victim->query_name())+" posted by "+capitalize(who)+" at "+ctime(time())+"!\n");
    attacker->add_money("gold",money);
    attacker->set_mini_quest("Assassinated "+capitalize(victim->query_name())+" for the guild.",exp,"Assassinated "+capitalize(victim->query_name())+" for the guild.");
}

mixed add_personal_bounty(string name, object poster, int amount) {
    int palign;

    if (member_array(name, keys(__Personal_Bounties)) != -1) {
        palign = __Personal_Bounties[name]["alignment"];
        // evil can only add to bounties posted by evil
        if (member_array(palign,({3,6,9})) != -1 && ALIGN->is_evil(poster)) {
            __Personal_Bounties[name]["money"] += amount;
            tell_object(poster,"%^BOLD%^%^RED%^Your money has been added to the present bounty.");
            return 0;
        }
        // good can only add to bounties posted by good
        if (member_array(palign,({1,4,7})) != -1 && ALIGN->is_good(poster)) {
            __Personal_Bounties[name]["money"] += amount;
            tell_object(poster,"%^BOLD%^%^RED%^Your money has been added to the present bounty.");
            return 0;
        }
        // neutral can only add to bounties posted by neutral
        if (member_array(palign,({2,5,8})) != -1 && ALIGN->is_neutral(poster)) {
            __Personal_Bounties[name]["money"] += amount;
            tell_object(poster,"%^BOLD%^%^RED%^Your money has been added to the present bounty.");
            return 0;
        }
        return "A bounty has already been issued for "+capitalize(name)+" by someone whose cause you don't want to help!";
    }

    __Personal_Bounties[name] = (["money":0, "poster":"fred","alignment":0]);
    __Personal_Bounties[name]["money"] = amount;

    if (!avatarp(poster) && !poster->query_disguised())
        __Personal_Bounties[name]["poster"] = (string)poster->query_name();
    else
        __Personal_Bounties[name]["poster"] = (string)poster->query_vis_name();

    __Personal_Bounties[name]["alignment"] = (int)poster->query_alignment();

    SAVE();
    log_file("bounties","Personal bounty placed on "+capitalize(name)+" for "+amount+" by "+capitalize(poster->query_name())+" at "+ctime(time())+".\n");
}

protected void pbounty_shout(string hunter, string hunted, string issued) {
    if (find_player(hunter))
        tell_object(find_player( hunter ),"%^BOLD%^%^YELLOW%^You have collected the bounty on "+capitalize(hunted)+" issued by a citizen.");
    //message("bounty","%^BOLD%^%^YELLOW%^"+capitalize(hunter)+" has collected the bounty on "+capitalize(hunted)+"!", users(), find_player("hunter"));
}

string *query_personals() {
    return distinct_array(keys(__Personal_Bounties));
}

mapping query_personal_bounties() {
    return __Personal_Bounties;
}

int remove_personal_bounty(string name) {
    if (member_array(name, keys(__Personal_Bounties)) != -1)
        map_delete(__Personal_Bounties, name);
    SAVE();
}

protected int legal_bounty(object victim, object attacker) {
    //This is left in so that stuff that calls it doesn't break.  bounties are
    //  now taken care of in a call to collect_law_bounty from the magistrate.
    //return 0;
    //return collect_law_bounty(victim, attacker, 1); references undefined function
}

string *query_bounties() {
    return distinct_array(keys(__newBounties));
}

int query_bounty_dead(string nme){
    return __newBounties[nme];
}

mapping query_bounties_map(){
    return __newBounties;
}

string query_bounty_alias(string name){
    if(__newBountiesAlias[name]) {
        return __newBountiesAlias[name];
    }
    return name;

}
void add_bounty(string name, int dead, string alias) {
    __newBounties[name] = dead;
    __newBountiesAlias[name] = alias;
    SAVE();
}

int remove_bounty(string name) {
    map_delete(__newBounties, name);
    map_delete(__newBountiesAlias, name);
    SAVE();
}

void add_evil(string name) {
    __Evil += ({lower_case(name)});
    __Evil = distinct_array(__Evil);
    SAVE();
}

void add_good(string name) {
    __Good += ({lower_case(name)});
    __Good = distinct_array(__Good);
    SAVE();
}

void add_neutral(string name) {
    __Neutral += ({lower_case(name)});
    __Neutral = distinct_array(__Neutral);
    SAVE();
}

void remove_evil(string name) {
    __Evil -= ({lower_case(name)});
    SAVE();
}

void remove_good(string name) {
    __Good -= ({lower_case(name)});
    SAVE();
}

void remove_neutral(string name) {
    __Neutral -= ({lower_case(name)});
    SAVE();
}

string * query_evil_bounties() {
    return distinct_array(__Evil);
}

string * query_good_bounties() {
    return distinct_array(__Good);
}

string * query_neutral_bounties() {
    return distinct_array(__Neutral);
}

void remove_all_bounties(string name) {
    if (member_array(name, keys(__Personal_Bounties)) != -1)
        map_delete(__Personal_Bounties, name);
    if (member_array(name, keys(__newBounties)) != -1) {
        map_delete(__newBounties, name);
        map_delete(__newBountiesAlias, name);
    }
    if (member_array(name,__Evil)!=-1) __Evil -= ({name});
    if (member_array(name,__Good)!=-1) __Good -= ({name});
    if (member_array(name,__Neutral)!=-1) __Neutral -= ({name});
    SAVE();
}

void check_diety_change(object who) {
    int align,i,hp_loss;
    string diety,curclass,*classes;
    object symbol;

    align = who->query_alignment();
    diety = who->query_diety();
    symbol = present("holy symbol",who);
    if (!diety || diety == "pan") return;
    if (member_array(align,DIETIES[diety][1])==-1) {
        log_file("god_change",capitalize(who->query_name())+" has been rejected by "+capitalize(diety)+": "+ctime(time())+"\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" was rejected by "+capitalize(diety)+"!");
        tell_object(who,"%^BOLD%^%^YELLOW%^"+capitalize(diety)+" will no longer accept you as a follower!");
        tell_object(who,"%^BOLD%^%^CYAN%^A bolt of energy streaks toward you from above, exacting "+capitalize(diety)+"'s revenge.");
        tell_object(who,"%^BOLD%^You must seek out a temple and choose another diety to follow.");
        ADVANCE_D->diety_news(diety,capitalize(diety)+" has rejected "+who->query_cap_name()+" as a follower!");
        who->set("last forsake",time());
        who->set_diety(0);
        who->forget_all_cl_spells();
        if (objectp(symbol)) symbol->remove();
//         who->resetLevelForExp(-((int)who->query_exp()*1/20));
         who->general_exp_adjust_perc(-5);
    }
}

private int flag;

// two new functions added making align not actually change (original below still complete as it was last in case we ever want to put it back) *Styx* 1/14/04, last change 8/03

void align_penalty(object person, int points, int law) {
   string name = person->query_name();
   int align = person->query_alignment();
   SAVE();
/* Not quite 20% but about what it would have cost to also change back.  We don't want changes period or forcing them to cycle Tharis forest instead of RPed atonement so.... This way they don't lose their god/dess or have to deal with class changes in the meantime but we can always deduct more exp. for crappy RP or reward good atonement RP.
*/
//   person-> resetLevelForExp(-((int)(person->query_exp())*18/100));
   person->general_exp_adjust_perc(-18);
   tell_object(person, "%^YELLOW%^(ooc) You have acted against your nature (alignment) to excess and atonement is now required.  Automatic alignment changes have been removed and the experience loss is now commensurate with that loss _and_ what it would have cost to change back.\n");
   tell_object(person, "%^YELLOW%^(ooc) You do not lose class or faith but additional sanctions might be imposed by an avatar/wiz if you do not RP the realization you have made major mistakes and the atonement you need to do.\n");
   tell_object(person, "%^BOLD%^%^MAGENTA%^(ooc) Use <avatarmail> (required) to let the immortals know what you think went wrong to lead to this and what you intend to do to atone.\n");
   tell_object(person, "%^BOLD%^(ICly) Past deeds are flashing before your eyes and you feel dazed and overwhelmed by the realization you have betrayed your nature and life's path.\n");
   tell_object(person,"%^BOLD%^You feel an overwelming need to do some serious soul searching and atonement to whatever god/dess you serve or most influences your existence.");
   tell_room(environment(person), person->query_cap_name()+" seems to be having flashbacks of past deeds and be somewhat stunned for a few moments.", person);
   log_file("align_change",capitalize(name)+" hit the alignment change threshold with "+points+" of evil/good adj. and "+law+" of law/chaos adj. - alignment is "+align+" on "+ctime(time())+"\n");
   "/daemon/messaging_d"->avatars_message("alignment loss","%^BOLD%^Imm:  "+capitalize(name)+" hit an alignment change threshold and will need to atone.");
   "/cmds/avatar/_note.c"->cmd_note("ckpt "+name+" %^YELLOW%^hit the alignment change threshold (alignment is "+align+") with "+points+" and needs to atone.%^RESET%^");
   return;
}

/**
 * Checks alignment taking into account adjustment
 */
void check_align(object person)
{
    int align, points, law;
    align = person->query_true_align();
    points = person->query_align_adjust();
    law = person->query_law_align_adjust();

    if ((align % 3 == 1) && points < -99) {
        if (member_array((string)person->query_name(), __Good) != -1) {
            __Good -= ({ (string)person->query_name() });
        }
        person->reset_adjust();
        align_penalty(person, points, law);
        return;
    }

    if ((align % 3 == 0) && points > 99) {
        person->reset_adjust();
        if (member_array((string)person->query_name(), __Evil) != -1) {
            __Evil -= ({ (string)person->query_name() });
        }
        align_penalty(person, points, law);
        return;
    }

    if ((align % 3 == 2) && points < -199) {
        person->reset_adjust();
        if (member_array((string)person->query_name(), __Good) != -1) {
            __Good -= ({ (string)person->query_name() });
        }
        align_penalty(person, points, law);
        return;
    }

    if ((align % 3 == 2) && points > 199) {
        person->reset_adjust();
        if (member_array((string)person->query_name(), __Evil) != -1) {
            __Evil -= ({ (string)person->query_name() });
        }
        align_penalty(person, points, law);
        return;
    }

    if (ALIGN->is_lawful(person) && law < -99 ||
        ALIGN->is_chaotic(person) && law > 99 ||
        ALIGN->is_law_neutral(person) && law > 199 ||
        ALIGN->is_law_neutral(person) && law < -199) {
        person->reset_law_adjust();
        align_penalty(person, points, law);
        return;
    }
    SAVE();
    return;
}

void check_class_change(object who) {
    //Limitations:  Can only currently handle special classes that cannot be multiclass.
    string myclass, newclass, *classes, curclass, cl1, cl2;
    int level,exp,hp_loss,i,j,k, BoolLoss;

    BoolLoss = 0;
    level = (int)who->query_level();
    exp = (int)who->query_exp();
    classes = who->query_classes();
    myclass = who->query_class();

    //Changes:  Ranger must be good (1, 4, 7), paladin must be LG (1)
    //          Antipaladin must be LE (3), cavalier must be lawful (1,2,3)

    //spec_exp_adjust should be moved to the end?

    if (who->is_class("ranger") && member_array(who->query_alignment(), ({1,4,7})) == -1) {
        who->set_class("fighter");
        who->remove_class("ranger");
        who->set_mlevel("fighter",level);
        who->update_channels();
        who->add_search_path("/cmds/fighter");
        who->set_class_change("ranger");
        who->set_posed("fighter");
        seteuid(UID_LOG);
        log_file("class_change",who->query_cap_name()+" was changed from a "+myclass+" to a fighter at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a "+myclass+" to a fighter.");
        seteuid(getuid());
        BoolLoss = 1;
    }

    if (who->is_class("paladin") && (int)who->query_alignment() != 1) {
        who->set_class("cavalier");
        who->remove_class("paladin");
        who->set_mlevel("cavalier",level);
        who->update_channels();
        who->set_class_change("paladin");
        who->set_posed("cavalier");
        seteuid(UID_LOG);
        log_file("class_change",who->query_cap_name()+" was changed from a "+myclass+" to a cavalier at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a "+myclass+" to a cavalier.");
        seteuid(getuid());
        BoolLoss = 1;
    }

    if (who->is_class("antipaladin") && (int)who->query_alignment() != 3) {
        who->set_class("cavalier");
        who->remove_class("antipaladin");
        who->set_mlevel("cavalier",level);
        who->update_channels();
        who->set_class_change("antipaladin");
        who->set_posed("cavalier");
        seteuid(UID_LOG);
        log_file("class_change",who->query_cap_name()+" was changed from a "+myclass+" to a cavalier at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a "+myclass+" to a cavalier.");
        seteuid(getuid());
        BoolLoss = 1;
    }

    //Here is where a cavalier should degrade to a fighter
    //  must also check to see if person was previously also a paladin, need to encode this somehow.
    if (who->is_class("cavalier") && !ALIGN->is_lawful(who)) {
        who->set_class("fighter");
        who->remove_class("cavalier");
        who->set_mlevel("fighter",level);
        who->update_channels();
        //newclass should be oldclass, but hey don't want to waste variables
        if (newclass = who->query_class_change()) {
            if (newclass == "paladin") {
                who->set_class_change("cavalier#paladin");
            }
            else if (newclass == "antipaladin") {
                who->set_class_change("cavalier#antipaladin");
            }
            else {
                //Actually, if they got here its a problem, but oh well.
                who->set_class_change("cavalier");
            }
        }
        else {
            who->set_class_change("cavalier");
        }
        who->set_posed("cavalier");
        seteuid(UID_LOG);
        log_file("class_change",who->query_cap_name()+" was changed from a "+myclass+" to a cavalier at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a "+myclass+" to a cavalier.");
        seteuid(getuid());
        BoolLoss = 1;
    }

    //On to the upgrades
    //This is messed up.  Fighters can go back to cavalier or ranger, but not straight to pal/anti
    //  also must decode the query_class_change() for pal->cav->fighter
    if (who->is_class("fighter") && !BoolLoss) {
        if ((newclass = who->query_class_change())) {
            if (sscanf(newclass, "%s#%s", cl1, cl2) == 2) {
                //(anti)pal->cav->fighter...  decode and reconstruct

                //error checking.
                if (cl1 != "cavalier")
                    return;
                if (cl2 != "paladin" && cl2 != "antipaladin")
                    return;

                //Make sure of correct alignment to go to cavalier.
                if (!ALIGN->is_lawful(who))
                    return;

                //Classes should be good, change from a fighter to a cavalier.
                who->set_class("cavalier");
                who->remove_class("fighter");
                who->set_mlevel("cavalier", level);
                who->update_channels();
                who->add_search_path("/cmds/cavalier");
                who->set_posed("cavalier");
                who->set_class_change(cl2);
                seteuid(UID_LOG);
                log_file("class_change",who->query_cap_name()+" was changed from a fighter to a cavalier at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a fighter to a cavalier.");
                seteuid(getuid());
                BoolLoss = 1;
            }
            else {
                //ranger or just plain cavalier.

                //Lets take care of cavalier first since I just wrote a lot of that already.
                //Make sure of correct alignment to go to cavalier.
                if (ALIGN->is_lawful(who) && newclass == "cavalier") {
                    who->set_class("cavalier");
                    who->remove_class("fighter");
                    who->set_mlevel("cavalier", level);
                    who->update_channels();
                    who->add_search_path("/cmds/cavalier");
                    who->set_posed("cavalier");
                    who->set_class_change("");
                    seteuid(UID_LOG);
                    log_file("class_change",who->query_cap_name()+" was changed from a fighter to a cavalier at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a fighter to a cavalier.");
                    seteuid(getuid());
                    BoolLoss = 1;
                }
                if (ALIGN->is_good(who) && newclass == "ranger") {
                    who->set_class("ranger");
                    who->remove_class("fighter");
                    who->set_mlevel("ranger", level);
                    who->update_channels();
                    who->add_search_path("/cmds/ranger");
                    who->set_posed("ranger");
                    who->set_class_change("");
                    seteuid(UID_LOG);
                    log_file("class_change",who->query_cap_name()+" was changed from a fighter to a ranger at "+ctime(time())+".\n");
       "/cmds/avatar/_note.c"->cmd_note("ckpt "+who->query_name()+" changed from a fighter to a ranger.");
                    seteuid(getuid());
                    BoolLoss = 1;
                }
            }
        }
    }

    //cavalier back to paladin or anti
    if (who->is_class("cavalier") && ((int)who->query_alignment() == 1 || (int)who->query_alignment() == 3)) {
        if ((newclass = who->query_class_change())) {
            if ((ALIGN->is_good(who)&&newclass=="paladin")||(ALIGN->is_evil(who)&&newclass=="antipaladin")) {
                who->set_class(newclass);
                who->remove_class("cavalier");
                who->set_mlevel(newclass,level);
                who->update_channels();
                who->add_search_path("/cmds/"+newclass);
                who->set_posed(newclass);
                who->set_class_change("");
                seteuid(UID_LOG);
                log_file("class_change",who->query_cap_name()+" was changed from a cavalier to a "+newclass+" at "+ctime(time())+".\n");
                seteuid(getuid());
                BoolLoss = 1;
            }
        }
    }

    if (BoolLoss) {
        spec_exp_adj(who);
    }
}

void spec_exp_adj(object who) {
    int i,hp_loss, exp, x;
    string curclass;

    x = 0;

    curclass = who->query_class();
    exp = ADVANCE_D->get_exp((int)who->query_class_level(curclass),curclass, who);
        write("Exp for level["+curclass+"] "+who->query_class_level(curclass)+" = "+exp);
     write("current exp is "+who->query_exp());
    who->add_exp(exp - (int)who->query_exp());
    //who->add_exp(-((int)who->query_exp()*1/10));

    //I'm assuming that they have just one class.
    if(sizeof(who->query_classes()) > 1)
        return;

    while( (int)ADVANCE_D->get_exp(who->query_class_level(curclass), curclass, who)   >   ((int)who->query_exp())) {
/* For some reason this likes to go into an infinite loop somtimes, it probably has to do with the daemon's XP always being > current XP.  Not a common occurance, but this will make sure  the player doesn't get completely fucked.  --G */
        x++;
        if(x>5) break;
        who->set_mlevel(curclass, (int)who->query_class_level(curclass)-1);
        hp_loss = ADVANCE_D->get_hp_bonus(curclass,who->query_stats("constitution"), who->query_class_level(curclass),who);
        who->set_max_hp((int)who->query_max_hp() - hp_loss);
        who->reduce_my_skills(curclass);
        who->reduce_guild_level(curclass);
    }
    who->setenv("TITLE", (string)ADVANCE_D->get_new_title(who));
}
