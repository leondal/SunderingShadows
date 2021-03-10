/*
  acompanion.c
  
  Animal companion for rangers. Will be fleshed
  out more over time.
  
  -- Tlaloc --
*/

inherit WEAPONLESS;

#define SAVEDIR "/d/save/summons/" + owner->query_name() + "/animal/"

object owner;

string saved_short,
       saved_long;

int set_owner(object ob) { owner = ob; return 1; }
object query_owner()     { return owner; }

void create(){
    ::create();
    set_name("companion");
    set_id(({"companion", "greater summon"}));
    set_short("A generic animal companion");
    set_hd(4,1);
    set_hp(40);
    set_exp(1);
    set_size(2);
    set_gender("neuter");
}

void init()
{
    ::init();
      
    saved_short = read_file(SAVEDIR + "short");
    saved_long = read_file(SAVEDIR + "long");
    
    //Use read_file here - don't want to save whole object for 2 variables
    if(!strlen(saved_short) && !strlen(saved_long))
    {
        mkdir("/d/save/summons/" + this_player()->query_name());
        mkdir(SAVEDIR);
    }
    else
    {
        set_short(saved_short);
        set_long(saved_long);
    }
    
    add_action("set_animal_desc", "animal");
}

int set_animal_desc(string str)
{
    string *input;
    
    input = explode(str, " ");
    
    if(sizeof(input) < 2)
    {
        tell_object(this_player(), "Syntax : animal [long/short] [description].");
        return 1;
    }
    
    switch(input[0])
    {
        case "short":
        this_object()->set_short(implode(input[1..], " "));
        tell_object(this_player(), "Your Animal Companion will now be seen as: \n" + query_short());
        rm(SAVEDIR + "short");
        write_file(SAVEDIR + "short", query_short());
        break;
        case "long":
        this_object()->set_long(implode(input[1..], " "));
        tell_object(this_player(), "Your Animal Companion will now be described as: " + query_long());
        rm(SAVEDIR + "long");
        write_file(SAVEDIR + "long", query_long());
        break;
        default:
        tell_object(this_player(), "Please select 'long' or 'short' as options.");
        return 1;
        break;
    }
    
    return 1;
}
    

void heart_beat()
{

    object *attackers,
           room;
           
    ::heart_beat();
    
    if(!owner)
        return;
    
    if(!interactive(owner))
    {
        this_object()->remove();
        return;
    }
    
    room = environment(this_object());
    
    //Faithful companion finds his master
    if(living(owner) && room != environment(owner))
        this_object()->move(environment(owner));
    
    attackers = owner->query_attackers();
    
    if(sizeof(attackers))
    {
        foreach(object ob in attackers)
            this_object()->kill_ob(ob);
    }
    else
        add_hp(query_max_hp() / 25);
}

void die(object ob)
{
    owner && owner->remove_property("animal_companion");
    remove();
}

int remove()
{
    all_inventory(TO)->remove();
    ::remove();
    return 1;
}
