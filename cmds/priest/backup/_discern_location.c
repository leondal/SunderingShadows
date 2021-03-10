//spell to allow a brief glimpse at a person's 
//location without a scrying device ~Circe~ 8/28/05
#include <priest.h>

inherit SPELL;
object dest,mytarg,myplace;

int send_living_name(object targ);
int long_look_room(object dest);
object find_miss(object play, object victim);

void create() 
{
    ::create();
    set_spell_name("discern location");
    set_spell_level(7);
    set_spell_type("priest");
    set_spell_sphere("divination");
    set_spell_domain("mentalism");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_peace_needed(1);
}

string query_cast_string() 
{
    tell_object(caster,"%^ORANGE%^Closing your eyes, you begin to chant"+
        " the words of your prayer through your mind.");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" closes "+caster->QP+" eyes"+
        " and concentrates.",caster);
    return "display";
}

void spell_effect(int prof) 
{
    string targ, real,*map_keys;
    object mytarg,myplace;
    int matches, i;
    mapping map;
    
    if(!arg)
    {
       tell_object(caster,"You must focus upon a target!");
       if(objectp(TO)) TO->remove();
       return 1;
    }

    targ = lower_case(arg);

    if(targ == (string)caster->QCN) 
    {
        tell_object(caster,"%^BOLD%^That won't work.  You should know your own location.");
        dest_effect();
        return;
    }

    if(caster->isKnown(targ) || ((string)caster->realName(targ) != "")) 
    {
        map = (mapping)caster->getRelationships();
        map_keys = keys(map);
        for(i=0;i<sizeof(map_keys);i++) 
        {
            if(lower_case(map[map_keys[i]]) == targ) 
            {
	            matches++;
                real = lower_case(map_keys[i]);
            }
        }
        if(!matches)
        {
	        tell_object(caster,"%^BOLD%^%^RED%^You do not recall a person called "+targ+"!");
	        dest_effect();
            return;
        }
        if(matches > 1)
        {
	        tell_object(caster,"%^BOLD%^RED%^You know too many people with the same name!");
            dest_effect();
	        return;
        }
        if(real == targ)
        {
            mytarg = find_player(real);
        }
        else
        {
            if((random(100)+1) < 50) 
            {
                mytarg = find_player(real);
            }
            else
            {
                tell_object(caster,"%^BOLD%^%^RED%^Your memory of this "+
                    "person is a little too fuzzy.  Try again.");
                dest_effect();
                return;
            }
        }
    } 
    else 
    {
        if(avatarp(caster) || !random(4)) 
        {
	        if (avatarp(caster)) 
            {
	            write("You know who you\'re looking for.");
	        }
	        mytarg = find_player(targ);
        } 
        else 
        {
    	    if (!random(3))
            {
    	        mytarg = find_miss(ETO,find_player(targ));
            }
        }
        if(!objectp(mytarg)) 
        {
            tell_object(caster,"%^BOLD%^%^RED%^The target of your power is not available!");
            dest_effect();
            return;
        }
        if (mytarg->query_true_invis()) 
        { 
            tell_object(caster,"%^BOLD%^%^RED%^The target of your power is not available!");
            dest_effect();
            return;
        }
        if(present("blockerx111", environment(mytarg))) 
        {
            tell_object(ETO,"%^BOLD%^RED%^There appears to be interference blocking "
		        "your location attempt in the vicinity of the target!");
        }
        dest_effect();
        return;
    }

    tell_object(CASTER, "%^ORANGE%^You turn your mind inward, "+
        "focusing upon "+capitalize(targ)+"'s location.");
    tell_object(CASTER,"%^YELLOW%^Your inner eye reveals "+capitalize(targ)+"'s location:");
    myplace = environment(mytarg);
    long_look_room(myplace);
    spell_successful();
    dest_effect();
}

void dest_effect()
{
    if(objectp(caster)) 
    {
        tell_object(caster,"%^ORANGE%^The image fades from your mind.");
    }
    ::dest_effect();
    TO->remove();
}

int long_look_room(object dest) 
{
    string file, desc;
    object *inv;
    int i,j;
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n", caster);
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"\n", caster);
    inv = all_inventory(dest);
    for(i=0;i<sizeof(inv);i++) 
    {
     	if(!objectp(inv[i])) continue;
     	if(inv[i]->query_invis()) continue;
    	if(!inv[i]->is_detectable()) continue;
    	TO->send_living_name(inv[i]);
    }
    return 1;
}

int send_living_name(object targ) 
{
	string known, str;
	int i,j;
	
    if(targ->is_monster()) 
    {
	    str = targ->query_short();
	    message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str,caster);
        return 1;
    }
    if(objectp(caster) && caster->knownAs(targ->query_true_name())) 
    {
	    known = caster->knownAs(targ->query_true_name());
    }
    str = targ->getWholeDescriptivePhrase();
    if(known)
    {
        str = capitalize(known)+", "+str;
    }
    message("living_item", "%^CYAN%^BOLD%^[S] %^RED%^"+str, caster);
    known = 0;
    return 1;
}

object find_miss(object play, object victim) 
{
    object *userarray;
    object randobj;

    userarray = users();
    userarray -= ({ 0,play,victim });
    if (!sizeof(userarray)) return 0;
    randobj = userarray[random(sizeof(userarray))];
    if (avatarp(randobj)) return 0;
    else return randobj;
}

int help(string str) 
{
    write(
@HELP
Spell  : Discern Location
Level  : 7th level
Sphere : Divination
Domain : Mentalism
Syntax : chant discern location on <target>

By calling upon the powers of the caster's own mind, 
the cleric is able to gain a brief glimpse at the 
location of the target.  The caster will not see or 
hear anything going on in the area, but he is granted 
with a vision simply showing where the target is.  
Anti-scrying magic will block this spell.

HELP
);
    return 1;
}
