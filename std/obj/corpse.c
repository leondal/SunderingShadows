// level hacking put in by Valodin to enable necromancy
// Modified by Vashkar to work with the animate dead spell.
/* added to copy_body & set_name to pick up description of what died for those who don't get a chance to see what something looked like before they killed it or if they come across a corpse.  *Styx*  2/15/03
*/

#include <std.h>
#include <move.h>

inherit BAG;

#define DECAY_TIME 600
string name, short;
int decay, hd, size, level, old_hp, inter, anim, origname, fingers, old_align, missing, skinned;
int old_ac;
int was_user = 0;
int maxl;
  /* indication of body type for the time being */
mapping body;
string *wielding_limbs, race, gender, *ids,true_name,desc;

void set_was_user(int i){ was_user = i;}
int get_was_user(){ return was_user;}


void init()
{
    ::init();
    add_action("rend","rend");
}


int rend(string str)
{
    string what, which;
    object limb;

    if (!str) 
    {
        return notify_fail("rend <limb> from corpse\n");
    }
    
    if(sscanf(str, "%s from %s",what, which) != 2)
    {
        return notify_fail("rend <limb> from corpse\n");
    }
    
    if (present(which, ETP) != TO && present(which, TP) != TO) 
    {
        return notify_fail("No such corpse.\n");
    }

    /*
    if (skinned) {
        return notify_fail("You can't take a limb from a skinned corpse.\n");
    }
    removed to allow eating of rended limbs from skinned corpses
    */
    
    limb = TO->rend_limb(what);
    
    if (objectp(limb)) 
    {
        if (limb->move(TP) != MOVE_OK) 
        {
            limb->move(ETP);
        }
        tell_object(TP,"%^BOLD%^You claim a grizzly prize, the "+limb->query_short()+".");
        tell_room(ETP,"%^BOLD%^"+TPQCN+" claims a grizzly prize, the "+limb->query_short()+".",TP);
        return 1;
    }

    tell_object(TP,"The corpse seems to be lacking that limb.");
    return 1;
}


object rend_limb(string limb)
{
    object part;
    if (member_array(limb, keys(body)) == -1) { return 0; }
    part = new ("/std/obj/body_part");
    part->set_limb(name,limb);
    map_delete(body,limb);
    set_long(query("long")+"\n %^YELLOW%^Its "+limb+" has been hacked off.\n");
    missing++;
    return part;
}         


int copy_body(object ob)
{
    string *limb_names;
    int i, lnsz;

    wielding_limbs = (string *)ob->query_wielding_limbs();
    body = ([]);
    limb_names = (string *)ob->query_limbs();
    for(i = 0, lnsz = sizeof(limb_names); i < lnsz; i++)
    {
       body[limb_names[i]] = ([ 
           "limb_ref": ob->query_reference(limb_names[i]),
           "max_dam": ob->query_max_dam(limb_names[i]),
           "damage": ob->query_dam(limb_names[i]),
           "ac": ob->query_ac(limb_names[i]) ]);
    }
    fingers = ob->query_fingers();
    old_hp = ob->query_max_hp();
    old_ac = ob->query_ac();
    level = ob->query_level();
    hd = ob->query_hd();
    maxl = ob->query_max_level();
    gender = ob->query_gender();
    race = ob->query("race");
    size = ob->query_size();
    ids = ob->query_id();
    origname = ob->query_property("origname");
    short = ob->query_short();
    old_align = ob->query_alignment();
    inter=0;
    if(ob->query_property("animated"))
        anim=1;
    else
        origname=ob->query_name();
    if(interactive(ob))
        inter=1;
    if(ob->query_description())
	desc = "The "+race+" "+ob->query_description();
//    tell_object(find_player("styx"), "Desc is "+desc+" at this point.");
    if(ob->is_monster())
	desc = ob->base_desc();
//    tell_object(find_player("styx"), "And now it's "+desc+"....");
// need this so it doesn't put a 0 for those (newbies esp.) without a description
    if(!desc) 
	desc = "There doesn't seem to be anything at all notable about this one.";
    set_long("%^BOLD%^%^RED%^This is the dead body of a "+gender+" "+race+".  In life it looked something like:%^RESET%^\n"+desc+"%^RESET%^\n");
}


// updated to set_hd higher now that skills are based on level -Ares
int make_new_body(object ob, int bonus)
{
    int i, lnsz;
    string *limb_names, undeadtype;

    if(!hd) hd=level;
    if(!hd) hd=1;
   
    ob->set_max_level(maxl);
  
    if(inter)
    {
        if(hd > 1 && !anim)
        {
            if(anim) name=origname;
            ob->set_name("zombie "+name);
            //ob->set_hd(2);
            ob->set_hd(hd);
            if(race) 
            {
                if(skinned)
                {
                    ob->set_short("%^RESET%^%^CYAN%^A z%^GREEN%^o%^CYAN%^mb%^GREEN%^ie%^CYAN%^ "+race+"%^RESET%^");
                } 
                else 
                {
                    ob->set_short("%^RESET%^%^RED%^A sk%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^nless husk%^RESET%^");
                }
                ids = ({"undead","zombie","zombie "+race, race, "zombie "+name});
            }
            else
            {
                ob->set_short("%^RESET%^%^CYAN%^A z%^GREEN%^o%^CYAN%^mb%^GREEN%^ie%^CYAN%^");
                ids = ({"undead","zombie","zombie "+name});
            }
        }
        else
        {
            if(anim) { name=origname; }
            ob->set_name("skeleton of "+name);
            //ob->set_hd(1);
            ob->set_hd(hd);
            
            if(race)
            {
                ob->set_short("%^RESET%^A "+race+" s%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^on%^RESET%^");
                ids = ({"undead","skeleton",race+" skeleton", race, "skeleton of "+name});
            }
            else
            {
                ob->set_short("A s%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^on%^RESET%^");
                ids = ({"undead","skeleton","skeleton of "+name});
            }
        }
    }
  
    else
    {
        if(random(2) && !anim)
        {
            if(anim) name=origname;
            ob->set_name("zombie "+name);
            ob->set_hd(hd+roll_dice(1,6));
            ob->set_hp(ob->query_max_hp());
            if(!race)
                race="";
            ids += ({"undead","zombie","zombie "+race, "zombie "+name});            

            ob->set_short("%^RESET%^%^CYAN%^A z%^GREEN%^o%^CYAN%^mb%^GREEN%^ie%^CYAN%^ "+race);
        }
        else
        {
            if(anim) { name=origname; }
            ob->set_name("skeleton of "+name);
            ob->set_hd(hd);
            ob->set_hp(ob->query_max_hp());
            if(race)
            {
                ob->set_short("%^RESET%^%^WHITE%^A "+race+" s%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^on");
                ids += ({"undead","skeleton",race+" skeleton", race, "skeleton of "+name});
            }
            else
            {
                ob->set_short("%^RESET%^A s%^BOLD%^%^BLACK%^k%^RESET%^e%^BOLD%^%^BLACK%^l%^RESET%^e%^BOLD%^%^BLACK%^t%^RESET%^on");
                ids += ({"undead","skeleton","skeleton of "+name});
            }
        }
    }
  
    limb_names = keys(body);
    for(i = 0, lnsz = sizeof(limb_names); i < lnsz; i++)
    {
        ob->add_limb(limb_names[i], body[limb_names[i]]["limb_ref"],
        body[limb_names[i]]["max_dam"],
        body[limb_names[i]]["damage"], body[limb_names[i]]["ac"]);
    }
  
    if(fingers) { ob->set_fingers(fingers); }
    ob->set_wielding_limbs(wielding_limbs);
    ob->set_race(race);
    ob->set_gender(gender);
    ob->set_size(size);
    ob->set_id(ids);
    ob->set_property("origname", origname);
    if(!ob->query_property("animated")) ob->set_property("animated",1);
    ob->set_stats("strength",18);
    return ob->query_level();
}


int query_missing() { return missing; }
int query_level() { return level; }
void set_level(int lev) { level = lev; }
void set_old_ac(int x) { old_ac = x; }
int query_old_ac() { return old_ac; }
int query_old_hp() { return old_hp; }
void set_old_hp(int num) { old_hp = num; }
void set_fingers(int num) { fingers = num; }
int query_fingers() { return fingers; }
int query_size() { return size; }
int query_old_alignment() { return old_align; }
//int can_put_and_get() { return 1; }


int query_decay() 
{
    if(TO->query_property("no_decay")) { return 2; }
    return decay;
}


prevent_insert()
{
    write("The corpse is too big.");
    return 1;
}


void create()
{
    name = "noone";
    set_weight(100);
    decay = 2;
    set_id(({"corpse", "corpse of " + name, "remains"}));
    set_max_internal_encumbrance(400);
    level = 0;
    old_hp = 0;
    fingers = 0;
}


void set_name(string str) 
{
    name = str;
//    set_long("This is the dead body of " + name + "." );
// moved up into copy_body to avoid needing extra global variables *Styx*  2/15/03
    set_id( ({"corpse", "corpse of " + lower_case(name), "remains" }));
    call_out("decay", DECAY_TIME);
}


void remove_decay(){ remove_call_out("decay"); }


void decay()
{
    decay -= 1;
    if(decay >= 0 || TO->query_property("no_decay"))
    {
        call_out("decay", 20);
        return;
    }
    if(!get_was_user()) { remove(); }
    set_long("This "+race+" skeleton is devoid of any flesh or other identifying features.");
}


string query_short()
{
    if (skinned == -1) 
    {
        return "The skinless corpse of "+article(race?race:name)+" "+(race?race:name);
    } 
    else if (skinned) 
    {
        return "The partially skinned corpse of "+article(race?race:name)+" "+(race?race:name); 
    }
    if(decay == 2)
        return "the corpse of " + name;
    else if (decay == 1 || decay == 0)
        return "The somewhat decayed remains of " + name;
    else
        return "The skeletal remains of a " + race;
}


// corpses were buggy because MOVE_OK, MOVE_NOT_ALLOWED, and MOVE_NO_ROOM all return
// different values, and only MOVE_OK is 0
int remove()
{
//
    object *inv;
    object env, chambre;
    int i;

    // Since we're destructing this object, we can remove the call_outs...
    remove_decay();
    if(!(env = environment(this_object())))
        return ::remove();
    if(!(chambre = environment(env)))
        return ::remove();
    if(!(i=sizeof(inv=all_inventory(this_object()))))
        return ::remove();
    while(i--)
    {
        if(inv[i]->move(env) == MOVE_OK)
        {
            tell_object(env, "You drop "+
                (string)inv[i]->query_short()+" as "+query_short()+
                " rots into nothing.");
            tell_room(chambre, (string)env->query_cap_name()+
                " drops "+(string)inv[i]->query_short()+
                " from a rotting corpse.",environment(this_object()));
        }
        else if(inv[i]->move(chambre) == MOVE_OK)
        {
            tell_object(chambre,"You cannot carry "+
                inv[i]->query_short()+"!");
            tell_room(environment(chambre),
                (string)chambre->query_cap_name()+" drops "+
                (string)inv[i]->query_short()+" from a rotting "
                    "corpse.",chambre);
        }
    }
    return ::remove();
}

string query_name() { return name; }
int is_corpse() { return 1; }
string *query_limbs() { return keys(body); }
string query_race() { return race; }
string *query_wielding() { return wielding_limbs; }
string query_original_name() { return origname; }
string query_original_short() { return short; }
int query_skinned() { return skinned; }
void set_skinned(int i) { skinned = i; }


int save_me(string file)
{
    if(!get_was_user()) { return 1; }
    else { return ::save_me(file); }
}

int restore_me(string file) { return ::restore_me(file); }

void set_true_name(string str) { true_name = str; }
string query_true_name() { return true_name; }
