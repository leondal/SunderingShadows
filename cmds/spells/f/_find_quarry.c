//Essentially a reskin of clairvoyance
//except it shows specifically a ranger's quarry
#include <std.h>
#include <priest.h>

inherit SPELL;

object dest, myplace;

int clairvoyance_delay()
{
    return 60;
}

void create()
{
    ::create();
    set_spell_name("find quarry");
    set_spell_level(([ "ranger" : 4 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS find quarry");
    set_description("Using this spell, the ranger can know the location of their quarry. This spell works " +
                    "in a very similar way to a clairvoyance spell, except it can only show the ranger's " +
                    "currently designated quarry. It is also subject to all forms of scry protection." );
    set_verbal_comp();
    set_somatic_comp();
}


int preSpell()
{
    if(spell_type != "psion" && ((int)caster->query_property("clairvoyance time") + clairvoyance_delay()) > time())
    {
        tell_object(caster,"You need to take a moment's rest before you can try that again.");
        return 0;
    }
    return 1;
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^Seeking inner calm, you open your mind to the world around you and the target you seek.");
    tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" closes "+caster->QP+" eyes and takes on an expression of calm.");
    return "display";
}

void spell_effect(int prof)
{
    string targ, real,*map_keys;
    object mytarg, myplace,blockobj;
    int matches, i, bonus, scrypower, stop;
    mapping map;
    
    mytarg = caster->query_property("quarry");
    
    if(!mytarg || !objectp(mytarg))
    {
        tell_object(caster, "Your quarry doesn't exist.");
        if(objectp(this_object()))
            this_object()->remove();
        return 1;
    }

    if (mytarg->query_true_invis())
    {
        tell_object(caster,"%^BOLD%^%^RED%^The target of your power is not available!");
        dest_effect();
        return;
    }

    bonus = caster->query_stats(casting_stat);
    bonus = bonus-10;
    scrypower = CLEVEL + bonus + query_spell_level(spell_type) * 2;

    if(blockobj = present("blockerx111", environment(mytarg)) || blockobj = present("blockerx111",mytarg))
    {
        if(scrypower < blockobj->query_block_power())
        {
            tell_object(CASTER, "%^BOLD%^RED%^There appears to be "+
                "interference blocking your scrying attempt in the "+
                "vicinity of the target!%^RESET%^");
            dest_effect();
            return 1;
        }
    }

    tell_object(CASTER,"%^YELLOW%^A flash of insight reveals "+capitalize(mytarg->QCN)+"'s location:");
    caster->remove_property("clairvoyance time");
    caster->set_property("clairvoyance time",time());

    myplace = environment(mytarg);
    long_look_room(myplace);

    spell_successful();
    dest_effect();
}


void dest_effect()
{
    if(objectp(caster)) { tell_object(caster,"%^ORANGE%^The image fades from your mind."); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}


int long_look_room(object dest)
{
    string file, desc;
    object *inv;
    int i,j;
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_short()+"\n", caster);
    message("room_description","\n%^YELLOW%^[S] %^RESET%^"+(string)dest->query_long()+"\n", caster);
    inv = all_inventory(dest);

    /*
    for(i=0;i<sizeof(inv);i++)
    {
        if(!objectp(inv[i])) continue;
        if(inv[i]->query_invis()) continue;
        if(!inv[i]->is_detectable()) continue;
        TO->send_living_name(inv[i]);
    }
    */
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
    if(objectp(caster) && caster->knownAs(targ->query_true_name())) known = caster->knownAs(targ->query_true_name());
    str = targ->getWholeDescriptivePhrase();
    if(known) str = capitalize(known)+", "+str;
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
