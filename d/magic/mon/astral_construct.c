/*
  astral_construct.c
  
  Animal companion clone for shapers.
  
  -- Tlaloc --
*/

inherit WEAPONLESS;

#include <daemons.h>
#include "/d/magic/mon/summoned_monster.h"

#define SAVEDIR "/d/save/summons/" + owner->query_name() + "/construct/"

object owner;

string saved_short,
       saved_long;

int setup,
    bonus;

int set_owner(object ob) { owner = ob; return 1; }
object query_owner()     { return owner; }

void create(){
    ::create();
    set_name("companion");
    set_id(({"companion", "greater summon"}));
    set_short("%^BOLD%^%^CYAN%^Astral Construct%^RESET%^");
    set_long("%^RESET%^%^CYAN%^Crafted from some sort of transluscent material, " +
             "this creature seems to be an impressive mass of crystal given humanoid " +
             "shape.  Its shoulders are wide enough for any blacksmith, and its " +
             "hulking form seems to be perfectly balanced.  Its legs are thick and " +
             "strong, and raised ridges along its forearms appear almost like " +
             "blades.  A thick, curving horn rises from its forehead, completing " +
             "the menacing image.%^RESET%^");
    set_hd(4,1);
    set_hp(40);
    set_exp(1);
    set_damage(2, 6);
    set_size(2);
    set_gender("neuter");
    //set_funcs( ({ "special_attack" }) );
    //set_func_chance(35);
}

void init()
{
    ::init();
    
    if(this_player() != owner)
        return;
    
    saved_short = read_file(SAVEDIR + "short");
    saved_long = read_file(SAVEDIR + "long");
    
    //Used read_file here - don't want to save whole object for 2 variables
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
    
    add_action("construct_command", "construct");
}

int construct_command(string str)
{
    string *input;
    
    if(this_player() != owner)
        return 0;
    
    input = explode(str, " ");
    
    if(sizeof(input) < 1)
    {
        tell_object(this_player(), "Syntax : construct [long/short/follow].");
        return 1;
    }
    
    if(sizeof(input) < 2 && (input[0] == "long" || input[0] == "short"))
    {
        tell_object(this_player(), "Syntax : construct [long/short] [input].");
        return 1;
    }
    
    switch(input[0])
    {
        case "short":
        this_object()->set_short(implode(input[1..], " "));
        tell_object(this_player(), "Your Astral Construct will now be seen as: \n" + query_short());
        rm(SAVEDIR + "short");
        write_file(SAVEDIR + "short", query_short());
        break;
        case "long":
        this_object()->set_long(implode(input[1..], " "));
        tell_object(this_player(), "Your Astral Construct will now be described as: " + query_long());
        rm(SAVEDIR + "long");
        write_file(SAVEDIR + "long", query_long());
        break;
        case "command":
        command(implode(input[1..], " "));
        break;
        case "follow":
        tell_object(this_player(), "Your Astral Construct is now following you.");
        this_player()->add_follower(this_object());
        return 1;
        default:
        tell_object(this_player(), "Please select 'long', 'short', 'follow' or 'command' as options.");
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
    
    room = environment(this_object());
    
    if(!room || !objectp(room))
        return;
    
    //This should stay the same for anything using this template
    if(!objectp(owner) || owner->query_property("animal_companion") != this_object())
    {
        this_object()->remove();
        return;
    }
    
    //Faithful companion finds his master
    if(objectp(owner) && room != environment(owner))
    {
        this_object()->move(environment(owner));
        owner->add_follower(this_object());
    }
    
    //Companion hides if master is hiding
    if(!this_object()->query_invis())
    {
        if(owner->query_hidden() || owner->query_invis())
        {
            this_object()->set_invis(1);
            tell_object(owner, "Your astral construct glistens and fades from sight.");
        }
    }
    else
    {
        if(!owner->query_hidden() && !owner->query_invis())
            this_object()->set_invis(0);
    }
    
    attackers = owner->query_attackers();
    
    //Doesn't really do anything on this mob. Templated for cloning.
    this_object()->add_damage_bonus(-bonus);
    this_object()->add_attack_bonus(-bonus);
    
    if(sizeof(attackers))
    {
        foreach(object ob in attackers)
            this_object()->kill_ob(ob);
    }
    else
    {
        add_hp(query_max_hp() / 20);
        bonus = 0;
    }
    
    if(query_hp() < query_max_hp() / 2 && present("vial", this_object()))
        command("drink vial");
    
    //See above
    this_object()->add_damage_bonus(bonus);
    this_object()->add_attack_bonus(bonus);
    
    //Do the specials if the attacker is valid
    if(this_object()->query_current_attacker() && !random(3))
        special_attack(this_object()->query_current_attacker());
}

void special_attack(object target)
{
    string tname, aname, mess;
    object room;
    int scale, dam;
    mapping attacks;
    
    if(!target || !objectp(target))
        return;
    
    tname = target->query_name();
    aname = capitalize(this_object()->query_name());
    room = environment(this_object());
    
    if(environment(target) != room)
        return;
    
    scale = 1 + this_object()->query_level() / 10;
    attacks = ([  ]);
    
    //Construct special attacks are touch based (ectoplasm)
    if(!BONUS_D->process_hit(this_object(), target, 1, 0, 0, 1))
        return;
    
    tname = target->QCN;
    dam = scale * roll_dice(1, 6);
    dam = target->cause_typed_damage(target, target->return_target_limb(), dam, "force");
    
    if(!dam || !target)
        return;
    
    switch(random(5))
    {
        case 0:
        tell_room(room, "%^RESET%^%^CYAN%^The %^BOLD%^construct %^RESET%^%^CYAN%^rises up and a %^MAGENTA%^compartment %^CYAN%^opens in its chest. Strange %^MAGENTA%^gl%^BOLD%^owi%^WHITE%^ng %^RESET%^%^MAGENTA%^be%^BOLD%^am%^WHITE%^s %^RESET%^%^CYAN%^of %^MAGENTA%^ene%^BOLD%^rg%^WHITE%^y %^RESET%^%^CYAN%^flare out and strike %^WHITE%^" + tname + "%^BOLD%^%^CYAN%^!%^RESET%^", ({ target }));
        tell_object(target, "%^RESET%^%^CYAN%^The %^BOLD%^construct %^RESET%^%^CYAN%^rises up and a %^MAGENTA%^compartment %^CYAN%^opens in its chest. Strange %^MAGENTA%^gl%^BOLD%^owi%^WHITE%^ng %^RESET%^%^MAGENTA%^be%^BOLD%^am%^WHITE%^s %^RESET%^%^CYAN%^of %^MAGENTA%^ene%^BOLD%^rg%^WHITE%^y %^RESET%^%^CYAN%^flare out and strike %^WHITE%^you%^BOLD%^%^CYAN%^!%^RESET%^.");   
        break;
        case 1:
        tell_room(room, "%^RESET%^%^CYAN%^A %^MAGENTA%^g%^BOLD%^el%^RESET%^%^MAGENTA%^at%^BOLD%^ino%^RESET%^%^MAGENTA%^us a%^BOLD%^ur%^RESET%^%^MAGENTA%^a %^CYAN%^materializes around the %^BOLD%^construct%^RESET%^%^CYAN%^, and then lashes out at %^WHITE%^" + tname + "%^RESET%^%^CYAN%^like an %^MAGENTA%^e%^BOLD%^cto%^RESET%^%^MAGENTA%^pl%^BOLD%^as%^RESET%^%^MAGENTA%^m%^BOLD%^i%^RESET%^%^MAGENTA%^c %^BOLD%^whip%^CYAN%^!%^RESET%^", ({ target }));
        tell_object(target, "%^RESET%^%^CYAN%^A %^MAGENTA%^g%^BOLD%^el%^RESET%^%^MAGENTA%^at%^BOLD%^ino%^RESET%^%^MAGENTA%^us a%^BOLD%^ur%^RESET%^%^MAGENTA%^a %^CYAN%^materializes around the %^BOLD%^construct%^RESET%^%^CYAN%^, and then lashes out at %^WHITE%^you %^RESET%^%^CYAN%^like an %^MAGENTA%^e%^BOLD%^cto%^RESET%^%^MAGENTA%^pl%^BOLD%^as%^RESET%^%^MAGENTA%^m%^BOLD%^i%^RESET%^%^MAGENTA%^c %^BOLD%^whip%^CYAN%^!%^RESET%^"); 
        break;
        case 2:
        tell_room(room, "%^RESET%^%^CYAN%^Several %^GREEN%^ps%^BOLD%^ue%^RESET%^%^GREEN%^d%^BOLD%^o%^RESET%^%^GREEN%^p%^BOLD%^od%^RESET%^%^GREEN%^s %^CYAN%^of pure %^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^rg%^RESET%^%^GREEN%^y %^CYAN%^erupt from the %^BOLD%^construct %^RESET%^%^CYAN%^and %^RED%^pummel %^WHITE%^" + tname + "%^BOLD%^%^CYAN%^!%^RESET%^", ({ target }));
        tell_object(target, "%^RESET%^%^CYAN%^Several %^GREEN%^ps%^BOLD%^ue%^RESET%^%^GREEN%^d%^BOLD%^o%^RESET%^%^GREEN%^p%^BOLD%^od%^RESET%^%^GREEN%^s %^CYAN%^of pure %^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^e%^BOLD%^rg%^RESET%^%^GREEN%^y %^CYAN%^erupt from the %^BOLD%^construct %^RESET%^%^CYAN%^and %^RED%^pummel %^WHITE%^you%^BOLD%^%^CYAN%^!%^RESET%^"); 
        break;
        case 3:
        tell_room(room, "%^RESET%^%^CYAN%^The %^BOLD%^construct %^RESET%^%^CYAN%^curls in on itself while a %^BOLD%^%^BLUE%^wa%^RESET%^%^ORANGE%^r%^BOLD%^p%^BLUE%^in%^RESET%^%^ORANGE%^g %^BOLD%^e%^BLUE%^ne%^RESET%^%^ORANGE%^r%^BOLD%^g%^BLUE%^y %^RESET%^%^CYAN%^coalesces around its bulk, and it %^RED%^launches %^CYAN%^itself at %^WHITE%^" + tname + " %^RESET%^%^CYAN%^with force%^BOLD%^!%^RESET%^", ({ target }));
        tell_object(target, "%^RESET%^%^CYAN%^The %^BOLD%^construct %^RESET%^%^CYAN%^curls in on itself while a %^BOLD%^%^BLUE%^wa%^RESET%^%^ORANGE%^r%^BOLD%^p%^BLUE%^in%^RESET%^%^ORANGE%^g %^BOLD%^e%^BLUE%^ne%^RESET%^%^ORANGE%^r%^BOLD%^g%^BLUE%^y %^RESET%^%^CYAN%^coalesces around its bulk, and it %^RED%^launches %^CYAN%^itself at %^WHITE%^you %^RESET%^%^CYAN%^with force%^BOLD%^!%^RESET%^.");
        break;
        default:
        tell_room(room, "%^RESET%^%^CYAN%^Slowly, the %^BOLD%^construct %^RESET%^%^CYAN%^begins to %^BOLD%^%^BLACK%^v%^WHITE%^i%^BLACK%^b%^WHITE%^r%^BLACK%^a%^WHITE%^t%^BLACK%^e%^RESET%^%^CYAN%^, rising in volocity until %^RED%^erupting %^CYAN%^in multiple %^BOLD%^%^RED%^e%^MAGENTA%^e%^RED%^r%^MAGENTA%^ie %^RED%^p%^MAGENTA%^u%^RED%^l%^MAGENTA%^se%^RED%^s %^RESET%^%^CYAN%^of %^BOLD%^%^RED%^e%^MAGENTA%^ne%^RED%^r%^MAGENTA%^g%^RED%^y %^RESET%^%^CYAN%^that slam into %^WHITE%^%^BOLD%^" + tname + "%^CYAN%^!%^RESET%^", ({ target }));
        tell_object(target, "%^RESET%^%^CYAN%^Slowly, the %^BOLD%^construct %^RESET%^%^CYAN%^begins to %^BOLD%^%^BLACK%^v%^WHITE%^i%^BLACK%^b%^WHITE%^r%^BLACK%^a%^WHITE%^t%^BLACK%^e%^RESET%^%^CYAN%^, rising in volocity until %^RED%^erupting %^CYAN%^in multiple %^BOLD%^%^RED%^e%^MAGENTA%^e%^RED%^r%^MAGENTA%^ie %^RED%^p%^MAGENTA%^u%^RED%^l%^MAGENTA%^se%^RED%^s %^RESET%^%^CYAN%^of %^BOLD%^%^RED%^e%^MAGENTA%^ne%^RED%^r%^MAGENTA%^g%^RED%^y %^RESET%^%^CYAN%^that slam into %^WHITE%^you%^BOLD%^%^CYAN%^!%^RESET%^."); 
        break;
    }
    
    return;
}
    
void die(object ob)
{
    //"/daemon/yuck_d"->save_inventory(this_object(), SAVEDIR + "acompanion");
    owner && tell_object(owner, "%^RED%^Your astral construct seems to cave in on itself and it completely dissappates!%^RESET%^");
    owner && owner->remove_property("animal_companion");
    owner && owner->remove_property("has_elemental");
    remove();
}

int remove()
{
    //"/daemon/yuck_d"->save_inventory(this_object(), SAVEDIR + "acompanion");
    //all_inventory(this_object())->remove();
    owner && owner->remove_property("animal_companion");
    owner && owner->remove_property("has_elemental");
    ::remove();
}
