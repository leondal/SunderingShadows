//NOT ACTIVELY USED

/*==============================================================================================================================================
An upcoming game features daemon. 

GAME_FEATURES = (["Feature Name" : (["Feature Name" : "blah", "Feature Description" : "blah blah blah", "Voting Expires In" : time (-1 for never), 
                                  "Feature Author" : "saide", "Name Votes" : ({}), "IP Votes" : ({}), "Account Votes" : ({}), "ETA" : "date", time, "TBA?", 
                                  "Yes Votes" : 0, "No Votes" : 0])
                                  
feature command theory
    (immortal only) feature add Name, Description, Expires, ETA. 
    feature vote name | yes or no (records IP, name, account - 1 per)
    feature 
        lists feature name / author / ETA / Yes Votes / No Votes / when voting expires  
    feature view name 
        lists feature description
    feature remove name 
        LAW access or feature author only - removes a feature prematurely - if feature author - send notification to players who are online and have opted
        in to be notified. 
    feature notifications | on or off
        on (default) turns on feature notifications if you have not voted / or when voting expires
        off turns off feature notifications entirely.     

================================================================================================================================================*/

#include <std.h>
#include <daemons.h>
#include <security.h>
#define FEATURES_SAVE "/daemon/save/game_features"
#define MINLEN 60
#define HRLEN 3600
#define DAYLEN 86400
inherit DAEMON;

mapping GAME_FEATURES;
mapping OLD_FEATURES;

void game_features_save();
void game_features_restore();
void check_features();
mixed get_feature_information(string featureName, string info);
void game_features_save()
{
    seteuid(UID_ROOT);
    save_object(FEATURES_SAVE);
    seteuid(geteuid());    
}

void game_features_restore()
{
    seteuid(UID_ROOT);
    restore_object(FEATURES_SAVE);
    seteuid(geteuid());    
}

void create()
{
    if(!mapp(GAME_FEATURES)) game_features_restore();
    if(!mapp(GAME_FEATURES)) 
    {
        GAME_FEATURES = ([]);
    }
    check_features();
    set_heart_beat(900);
    return;
}

int can_insert_feature(object who, string featureName)
{
    string *current_features;
    if(!objectp(who)) return -1; //invalid object
    if(!stringp(featureName)) return -4; //invalid featureName
    featureName = FILTERS_D->filter_colors(featureName);
    if(!wizardp(who)) return -2; //invalid access
    if(who->query_position() == "apprentice" || who->query_position() == "builder") return -2; //invalid access
    current_features = keys(GAME_FEATURES);
    if(member_array(featureName, current_features) != -1) return -3; //feature with same name already exists
    return 1; //can insert the feature     
}

int can_vote_on_feature(object who, string featureName, string myVote)
{
    string *current_features;
    string *name_votes, *ip_votes, *account_votes;
    string *myName, myIp, myAccount;
    mixed res;
    if(!objectp(who)) return -1; //invalid object;
    if(!stringp(featureName)) return -4; //invalid featureName
    featureName = FILTERS_D->filter_colors(featureName);
    current_features = keys(GAME_FEATURES);
    if(member_array(featureName, current_features) == -1) return -4; //invalid featureName
    name_votes = GAME_FEATURES[featureName]["Name Votes"];
    ip_votes = GAME_FEATURES[featureName]["IP Votes"];
    account_votes = GAME_FEATURES[featureName]["Account Votes"];
    res = get_feature_information(featureName, "Voting Expires In");
    if(res == "EXPIRED") return -8;   
    myName = who->query_true_name();
    myIp = who->query_ip();
    myAccount = who->query("user_account");
    if(member_array(myName, name_votes) != -1) return -5; //already voted
    if(member_array(myIp, ip_votes) != -1) return -5; //already voted
    if(member_array(myAccount, account_votes) != -1) return -5; //already voted
    if(!stringp(myVote)) { return 1; }// not trying to vote yet, just checking 
    else if(stringp(myVote) && (myVote == "yes" || myVote == "Yes" ||
    myVote == "No" || myVote == "no" || myVote == "abstain" || myVote == "Abstain"))
    {
        name_votes += ({myName});
        ip_votes += ({myIp});
        if(stringp(myAccount)) account_votes += ({myAccount});
        if(myVote == "yes" || myVote == "Yes") GAME_FEATURES[featureName]["Yes Votes"]++;
        else if(myVote == "no" || myVote == "No") GAME_FEATURES[featureName]["No Votes"]++;
        else if(myVote == "abstain" || myVote == "Abstain") GAME_FEATURES[featureName]["Abstain Votes"]++;
        GAME_FEATURES[featureName]["Name Votes"] = name_votes;
        GAME_FEATURES[featureName]["IP Votes"] = ip_votes;
        GAME_FEATURES[featureName]["Account Votes"] = account_votes;
        game_features_save();
        return 1; //successfully voted;        
    }
    return -6; //did not vote successfully - something broke    
}

int kill_feature(object who, string featureName)
{
    string *current_features;
    if(!objectp(who)) return -1; //invalid object
    if(!stringp(featureName)) return -4; //invalid featureName;
    featureName = FILTERS_D->filter_colors(featureName);
    if(!GAME_FEATURES[featureName]) return -4; //invalid featureName;    
    if(GAME_FEATURES[featureName]["Feature Author"] == who->query_true_name() ||
    member_group(who->query_true_name(), "law") == 1)
    {
        GAME_FEATURES[featureName]["Voting Expires In"] = 1;            
        return 1; //successfully removed on next check
    }
    return -7; //unable to remove feature 
}

void inject_feature(mapping featureMap, object who)
{   
    string *insert_features, featureName;
    int x;
    if(!objectp(who)) return;
    if(!mapp(featureMap)) return;
    insert_features = keys(featureMap);
    if(!sizeof(insert_features)) return;    
    for(x = 0;x < sizeof(insert_features);x++)
    {
        insert_features[x] = FILTERS_D->filter_colors(insert_features[x]);
        if(can_insert_feature(who, insert_features[x]) != 1) return;
        featureName = insert_features[x];
        continue;
    }
    GAME_FEATURES += ([featureName : (["Feature Name" : featureName, "Feature Description" : "", "Voting Expires In" : -1,
                                       "Feature Author" : who->query_true_name(), "Name Votes" : ({}), "IP Votes" : ({}),
                                       "Account Votes" : ({}), "ETA" : "TBA", "Yes Votes" : 0, "no Votes" : 0, "Abstain Votes" : 0]), ]);
    
    GAME_FEATURES[featureName]["Feature Description"] = featureMap[featureName]["description"];
    GAME_FEATURES[featureName]["Voting Expires In"] = featureMap[featureName]["expires"];
    GAME_FEATURES[featureName]["ETA"] = featureMap[featureName]["ETA"];
    game_features_save();
    tell_object(who, "You have successfully added the feature "+featureName+" for player voting. You can "+
    "verify this by typing 'game features' and making sure the name shows up on the list.");
    return;
}

string make_time_display(int time)
{
   int days, temp, hours, min, sec; 
   days = time/DAYLEN;
   temp = time%DAYLEN;
   hours = temp/HRLEN;
   temp = temp%HRLEN;
   min = temp/MINLEN;
   sec = temp%MINLEN;  
   return "%^RESET%^%^BOLD%^"+days+" d "+ hours + " h "+ min + " m";
}

mixed get_feature_information(string featureName, string info)
{
    mixed res;
    if(!stringp(featureName)) return "";
    if(!stringp(info)) return "";
    if(!GAME_FEATURES[featureName]) return "";
    if(!GAME_FEATURES[featureName][info]) return "";
    if(info == "Voting Expires In")
    {
        res = GAME_FEATURES[featureName][info];
        if(res != -1) 
        {
            res = to_int(res);
            res -= time();      
            if(res < 0) res = "EXPIRED";
            else res = make_time_display(res);
        }
        else res = "Never";
        return res;
        
    }
    return GAME_FEATURES[featureName][info];
}

string *parsable_features(object who) { return keys(GAME_FEATURES); }

void view_feature(object who, string featureName)
{
    mixed res;
    if(!objectp(who)) return;
    if(!stringp(featureName))
    {
        tell_object(who, "Error in attempting to view a feature. Invalid feature name.");
        return;
    }
    if(!GAME_FEATURES[featureName])
    {
        tell_object(who, capitalize(featureName) + " is not a valid game feature that is currently being "+
        "voted on.");
        return;
    }
    tell_object(who, "%^BOLD%^%^CYAN%^Feature Name%^RESET%^: "+capitalize(featureName));
    tell_object(who, "%^BOLD%^%^CYAN%^Feature Author%^RESET%^: "+capitalize(GAME_FEATURES[featureName]["Feature Author"]));
    tell_object(who, "%^BOLD%^%^CYAN%^Feature ETA if implemented%^RESET%^: "+GAME_FEATURES[featureName]["ETA"]);
    tell_object(who, "%^BOLD%^%^CYAN%^Current Yes Votes%^RESET%^: "+GAME_FEATURES[featureName]["Yes Votes"]);
    tell_object(who, "%^BOLD%^%^CYAN%^Current No Votes%^RESET%^: "+GAME_FEATURES[featureName]["No Votes"]);
    tell_object(who, "%^BOLD%^%^CYAN%^Current Abstains%^RESET%^: "+GAME_FEATURES[featureName]["Abstain Votes"]);
    if(can_vote_on_feature(who, featureName) == 1) tell_object(who, "%^BOLD%^%^RED%^You have NOT yet voted.\n%^RESET%^");
    res = get_feature_information(featureName, "Voting Expires In");
    tell_object(who, "%^BOLD%^%^CYAN%^Voting expires in : %^RESET%^"+res);
    tell_object(who, "%^BOLD%^%^CYAN%^Feature Description : \n%^RESET%^"+GAME_FEATURES[featureName]["Feature Description"] + "\n");
    return;    
}

void check_features()
{
    object *usrs, targ;
    string *current_features, cName, *notify, msg;
    mapping notifications = ([]), enotifications = ([]);
    int x, y, expire;
    usrs = users();
    current_features = keys(GAME_FEATURES);
    for(x = 0;x < sizeof(current_features);x++)
    {
        expire = GAME_FEATURES[current_features[x]]["Voting Expires In"];
        expire = to_int(expire);
        for(y = 0; y < sizeof(usrs);y++)
        {
            if(usrs[y]->query("feature notifications") == 1) continue;
            cName = usrs[y]->query_true_name();
            if(can_vote_on_feature(usrs[y], current_features[x]) == 1)
            {                
                if(!notifications[cName])
                {
                    notifications += ([ cName : ({current_features[x]}) ]);
                }
                else { notifications[cName] += ({current_features[x]}); }                
            }       
            if(expire < time() && expire != -1)
            {
                if(usrs[y]->query("feature notifications") != 1)
                {
                    if(!enotifications[cName])
                    {
                        enotifications += ([ cName : ({current_features[x]}), ]);     
                        continue;
                    }
                    else
                    {
                        enotifications[cName] += ({current_features[x]});  
                        continue;
                    }
                }
            }
            continue;            
        }
        if(expire < time() && expire != -1)
        {
            if(!mapp(OLD_FEATURES))
            {
                OLD_FEATURES = ([current_features[x] : GAME_FEATURES[current_features[x]]]);
            }
            else OLD_FEATURES += ([current_features[x] : GAME_FEATURES[current_features[x]]]);
            map_delete(GAME_FEATURES, current_features[x]);
            continue;
        }
        continue;
    }
    notify = keys(notifications);
    for(x = 0;x < sizeof(notify);x++)
    {
        if(!objectp(targ = find_player(notify[x]))) continue;
        msg = "%^B_CYAN%^%^YELLOW%^You are able to still vote on the "+
        "following features:\n\n";
        msg += implode(notifications[notify[x]], "\n");
        msg += "\nYou can view more information about a particular feature listed "+
        "above by doing flag feature | view <feature name>, this will summarize what a "+
        "particular feature means as well as current votes.";
        msg += "\n\nIf you want to turn these notifications off then you can "+
        "do so by typing %^RESET%^%^BOLD%^%^WHITE%^flag feature | notifications off.%^RESET%^";         
        tell_object(targ, msg);
        continue;
    }
    notify = keys(enotifications);
    for(x = 0;x < sizeof(notify);x++)
    {
        if(!objectp(targ = find_player(notify[x]))) continue;
        msg = "%^B_CYAN%^%^YELLOW%^Voting for the following features has expired:\n\n";
        msg += implode(enotifications[notify[x]], "\n");
        msg += "\n\nIf you want to turn these notifications off then you can "+
        "do so by typing %^RESET%^%^BOLD%^%^WHITE%^flag feature | notifications off.%^RESET%^";
        tell_object(targ, msg);
        continue;
    }
    game_features_save();
    return;
}

void heart_beat()
{
    if(!objectp(TO)) return;
    if(!mapp(GAME_FEATURES)) game_features_restore();
    if(!mapp(GAME_FEATURES)) GAME_FEATURES = ([]);
    check_features();    
    return;
}
