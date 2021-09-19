//      party daemon for the Nightmare mudlib
//      created by Descartes of Borg 10 Nov 1992

#include <party.h>
#include <ansi.h>

mapping party;
mapping invited;

string party_member(object ob);
void manage_party(string group);
void remove_party(string group);
void remove_invitation(mixed *bing);
int invited_now(object ob, string str);

void create() {
    party = ([]);
    invited = ([]);
    call_out("manage_all_parties", 300);
}

int add_member(object ob, string group) {
    if(!party) party = ([]);
    if(party_member(ob)) return ALREADY_MEMBER;
    if(!party[group]) {
        tell_object(ob, "You are the leader of party "+group+".\n");
        party[group] = ({});
    }
    party[group] += ({ ob });
    if(invited) if(invited[group]) if(member_array(ob, invited[group]) != -1) {
       remove_invitation( ({ ob, group, 1 }) );
    }
    ob->set_party(group);
    manage_party(group);
    return OK;
}

int remove_member(object ob) {
    string group;
    if(!party) return NOT_MEMBER;
    group = party_member(ob);
    if(!group) return NOT_MEMBER;
    party[group] -= ({ ob });
    tell_object(ob, "You are no longer in the party "+group+".\n");
    ob->set_party(0);
    manage_party(group);
    return OK;
}

string party_member(object ob) {
    string *groups;
    int i;

    if(!party) return 0;
    groups = keys(party);
    for(i=0; i<sizeof(groups); i++) {
        if(member_array(ob, party[groups[i]]) != -1) return groups[i];
    }
    return 0;
}

int change_leader(object ob) {
    string group;
    object *this_party;
    int x;

    if(!party) return NOT_MEMBER;
    group = party_member(ob);
    if(!group) return NOT_MEMBER;
    manage_party(group);
    this_party = party[group];
    x = member_array(ob, this_party);
    if(!x) return ALREADY_LEADER;
    this_party[x] = this_party[0];
    this_party[0] = ob;
    tell_object(ob, "You are now the leader of party "+group+".\n");
    party[group] = this_party;
    manage_party(group);
    return OK;
}

void manage_party(string group) {
    object *tmp;
    object *who;
    object ob;
    int i, j;

    tmp = ({});
    if(!party) return;
    if(!party[group]) return;
    if(!sizeof(party[group])) {
        remove_party(group);
        return;
    }
    ob = party[group][0];
    who = party[group];
    for(i=0; i<sizeof(who); i++) {
        if(!who[i]) continue;
        if(!living(who[i])) {
            who[i]->set_party(0);
            continue;
        }
        tmp += ({ who[i] });
    }
    if(!sizeof(tmp)) {
        remove_party(group);
        return;
    }
    if(tmp[0] != ob) tell_object(tmp[0], "You are now the leader of the party "+group+".\n");
    party[group] = tmp;
    return;
    // This is all after the return so it's not doing anything anyway -Ares
    /*
    tmp = ({});
    for(i=0; i<sizeof(party[group]); i++) {
        if((who = party[group][i]->query_attackers())) {
            for(j=0; j<sizeof(who); j++) {
                if(member_array(who[j], tmp) == -1) tmp += ({ who[j] });
            }
        }
    }
    for(i=0; i < sizeof(party[group]); i++) party[group][i]->set_attackers(tmp);*/
}

void remove_party(string group) {
    if(!party) return;
    if(undefinedp(party[group])) return;
    map_delete(party, group);
}

void calculate_exp(string group, int exp, object tmp) {
   int tot, x, i, j;
   float blah;
   string file, *tmp2, file2;
   int size;
   object env, *tmp3;

   tmp3 = ({});
   if(!party) {
      previous_object()->fakeparty_exp(exp, tmp);
      return;
   }
   if(!party[group]) {
        previous_object()->fakeparty_exp(exp, tmp);
        return;
    }
    if(sizeof(party[group]) == 1) {
       previous_object()->fakeparty_exp(exp, tmp);
       return 0;
    }
    manage_party(group);
      j = sizeof(party[group]);
    env = environment(previous_object());
    tmp2 = explode(base_name(env),"/");
    file = "/"+tmp2[0]+"/"+tmp2[1];
    for(i=0;i<j;i++){
        tmp2 = explode(base_name(environment(party[group][i])),"/");
       file2 = "/"+tmp2[0]+"/"+tmp2[1];

       if(file == file2){
               tmp3 += ({party[group][i]});
       }
    }
       size = sizeof(tmp3);
    for(i=0, tot=0; i<size; i++) 
    {
        x = (int)tmp3[i]->query_highest_level();
        tot += x;
    }
    for(i=0,sizeof(tmp3)>0; i<size=sizeof(tmp3); i++) 
    {
       x = (int)tmp3[i]->query_level();
       if(size > 1)
       {
        //tmp3[i]->fix_exp( (x*exp)/(tot - (x/size))+1,tmp);
         if(x <= ((int)previous_object()->query_level()-30))
           blah =  (to_float(x)/to_float(tot))*0.05;
        else if (x <= ((int)previous_object()->query_level()-23))
           blah =  (to_float(x)/to_float(tot))*0.1;
        else if (x <= ((int)previous_object()->query_level()-12))
           blah =  (to_float(x)/to_float(tot))*0.5;
         else
           blah = (to_float(x)/to_float(tot))*1.5;
        
        
         //if(blah >= 1.0)
         //  blah = 0.9;
        // next 3 lines added to try to encourage groups, previously was the two lines above -Ares
        size = sizeof(query_party_members(group));
        if(!size) { blah = blah; }
        else { blah = blah + ( size * 0.1); }  // additional 10% exp per person in group, larger groups = more exp
        //
        tmp3[i]->party_exp(to_int(exp*blah), tmp);
       }else
        tmp3[i]->party_exp(exp,tmp);
    }
}



string *query_parties() {
    if(!party) return 0;
    return keys(party);
}

mapping query_parties_full(){
       if(!party) party = ([]);
       return party;
}

object *query_party_members(string group) {
    if(!party) return 0;
    if(!party[group]) return 0;
    manage_party(group);
    return party[group];
}

object query_leader(string str) {
    if(!party) return 0;
    if(!party[str]) return 0;
    manage_party(str);
    return party[str][0];
}

void message_party(string str, string what) {
    int i, sz;

    if(!party) return;
    if(!party[str]) return;
    manage_party(str);
    sz = sizeof(party[str]);

    for(i=0; i<sz; i++) {
           message("party","%^RESET%^"+this_player()->query_cap_name()+"  %^BOLD%^%^RED%^"+"<"+str+" info>: "+what+"\n",party[str][i]);
    }
}

void notify_party(string str, string what) {
    int i, sz;

    if(!party) return;
    if(!party[str]) return;
    manage_party(str);
    sz = sizeof(party[str]);
    for(i=0; i<sz; i++) {
           message("partyinfo","%^BOLD%^%^RED%^"+"<"+str+" info>: "+what+"\n",party[str][i]);
    }
}

void party_emote(string str, string what) {
    int i, sz;

    if(!party) return;
    if(!party[str]) return;
    manage_party(str);
    sz = sizeof(party[str]);
    for(i=0; i<sz; i++) {
      message("partyemote","%^BOLD%^%^RED%^"+"<"+str+" info> "+what+"\n",party[str][i]);
    }
}

void add_invited(object ob, string str) {
    if(!invited) return;
    if(!invited[str]) invited[str] = ({});
    invited[str] += ({ ob });
    call_out("remove_invitation", 60, ({ ob, str, 0 }));
}

object *query_invited(string str) {
    if(!invited) return 0;
    if(!invited[str]) return 0;
    return invited[str];
}

int invited_now(object ob, string str) {
    if(!invited) return 0;
    if(!invited[str]) return 0;

    if(member_array(ob, invited[str]) == -1) return 0;
    return 1;
}

void remove_invitation(mixed *bing) {
    if(!invited) return;
    if(!invited[bing[1]]) return;
    if(member_array(bing[0], invited[bing[1]]) == -1) return;
    invited[bing[1]] -= ({ bing[0] });
    if(!bing[2]) tell_object(bing[0], "You are no longer invited to be a member of the party.\n");
}

void manage_all_parties() {
    string *grps;
    int i;
    if(i = sizeof(grps = keys(party)))
      while(i--) manage_party(grps[i]);
    call_out("manage_all_parties", 300);
}
