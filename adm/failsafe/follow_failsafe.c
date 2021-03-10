//	/std/living/follow.c
//	from the Nightmare mudlib
//	code for allowing people to follow
//	created by Descartes of Borg 15 february 1993
//  Updated and made more effecient -Ares 6/18/06

#include "std.h"


static private string *allowed_to_follow = ({});
static private object *followers=({});
static private object following;

object *query_followers() { followers = distinct_array(followers); followers -= ({ 0 }); return followers; }
object query_following() { return following; }
object *query_allowed()  { return allowed_to_follow; }

void set_following(object f) { following = f; }


int set_followers(object *f) 
{
    int i;

    if(!f) return 0;
    if(member_array( TO, f ) != -1 ) { return 0; }
    if(following && member_array(following, f) != -1) { return 0; }
    followers = f;
    for(i=0; i<sizeof(f); i++) 
    {
        if(!f[i]) { followers -= ({ f[i] }); }
        else { f[i]->set_following(TO); }
    }
    return 1;
}


int add_follower(object f) 
{
    if( f == this_object() ) return 0;
    if( f == following ) return 0;

    if(!followers) 
    {
	    followers = ({ f });
	    f->set_following(TO);
	    return 1;
    }

    f->set_following(TO);
    followers = followers + ({ f });
    return 1;
}


void remove_follower(object ob) 
{
    if(followers && member_array(ob, followers) == -1) { return; }
    followers -= ({ ob });
    ob->set_following(0);
    return;
}


void clear_followers() 
{
    int i;

    if(!followers) return;
    for(i=0; i<sizeof(followers); i++) 
    {
        if(followers[i]) { followers[i]->set_following(0); }
    }
    followers = ({});
}

void move_followers(object prev) 
{
    object *tmp;
    int i;

    tmp = ({});
    
    for(i=0; i<sizeof(followers); i++) 
    {
        if(!objectp(followers[i])) continue;
	    if(!environment(followers[i])) continue;
	    if(environment(followers[i]) != prev) 
        {
            if (!followers[i]->query_true_invis())
	        {
		        tell_object(TO,"You have lost "+followers[i]->QCN+".\n");
	        }
	        tell_object(followers[i], TO->QCN+" has ditched you.\n");
	        followers[i]->set_following(0);
	    }
	    else 
        {
            if( followers[i]->follow(base_name(ETO))) { tmp += ({ followers[i] }); }
	    }
    }

    followers = tmp;
}


void follow_allow(string str) 
{ 
    str = lower_case(str);
    if(!pointerp(allowed_to_follow)) { allowed_to_follow = ({}); }
    allowed_to_follow += ({ str }); 
    allowed_to_follow = distinct_array(allowed_to_follow);
}


void unallow_follower(string str)
{
    if(member_array(str,allowed_to_follow) == -1) { return; }
    allowed_to_follow -= ({ str });
    return;
}        


int can_follow(string str) 
{ 
    if(member_array(str,allowed_to_follow) == -1) { return 0; }
    return 1;
}


int follow(string exit) 
{
    string cmd, dotc;
    if(!environment(this_object())) return 0;
    if(sscanf(exit,"%s.c",dotc)) { exit=dotc; }
    if((cmd = (string)ETO->query_direction(exit)) == "/d/shadowgate/void")
       if((cmd = (string)ETO->query_direction(exit+".c")) == "/d/shadowgate/void")
        return 0;
    command(cmd);
    return 1;
}
