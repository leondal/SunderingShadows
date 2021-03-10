#include <std.h>
#include "../arctic.h"
inherit CREATURE;

int FLAG = 0;

void create() 
{
    ::create();
    set_name("Dire Shark");
    set_id(({"shark", "dire shark", "fish", "giant shark", "arcticmon"}));
    set_race("shark");
    set_body_type("snake");
    set_gender("male");
    set_size(5);
    set_short("A giant shark");
    set_long("This massive shark is over fifty feet long.  Its skin is a "
        "sleek, glistening gray and it moves with disturbing agility.  The "
        "massive dorsal fin along its back is the size of the sail on a small "
        "ship, and its jaws look as if they could swallow a full grown giant "
        "with ease.  The shark has huge black eyes that are absent any pupils.");
    set_hd(35,1);
    set_level(35);
    set_class("fighter");
    set_mlevel("fighter", 35);
    set_hp(1000);
    set_exp(30000);
    set_property("swarm", 1);
    set_property("water breather", 1);
    set_overall_ac(-5);
    set_stats("strength",25);
    set_stats("dexterity",22);
    set_stats("intelligence",4);
    set_stats("wisdom",6);
    set_stats("constitution",22);
    set_stats("charisma",5);
    set_attacks_num(1);
    set_damage(10,10);
    set_base_damage_type("piercing");
    add_limb("razor sharp teeth", "head", 0, 0, 0);
    set_attack_limbs(({"razor sharp teeth"}));
    set("aggressive", 25);
    set_funcs( ({"swallow"}) );
    set_func_chance(30);
}


void swallow()
{
    object *live;
    object *fodder;
    object targ,obj;
    int i;

    live = all_inventory(ETO);
    fodder = live;
    fodder = filter_array(fodder, "is_fodder", CREATURE);
    live = filter_array(live, "is_non_immortal_player", FILTERS_D);
    live += fodder;
    if(!sizeof(live)) { return; }
    i = sizeof(live);
    i = random(i);
    targ = live[i];

    if(!objectp(targ)) return;

    if(!ROLLSAVE(targ, PPD))
    {
        tell_object(targ,"%^RED%^The massive shark swims towards you "
            "impossibly fast and closes its great jaws around you "
            "trapping you inside!%^RESET%^");
        tell_room(ETO,"%^RED%^The massive shark swims towards "+targ->QCN+" "
            "impossibly fast and swallows "+targ->QO+" whole!%^RESET%^",targ);
        targ->do_damage("torso", roll_dice(10,10));
        targ->set_paralyzed(7, "%^BOLD%^%^GREEN%^You are being swallowed whole!%^RESET%^");
        if(!FLAG)
        {
            obj = new(MON"stomach_lining");
            obj->move(UW"shark_stomach");
            FLAG = 1;
        }
        targ->move(UW"shark_stomach");
        return;
    }

    tell_object(targ,"%^RED%^The massive shark swims towards you "
        "but you manage to move aside at the last instant!%^RESET%^");
    tell_room(ETO,"%^RED%^The massive shark swims towards "+targ->QCN+""
        "but "+targ->QS+" moves aside at the last instant!%^RESET%^",targ);
    targ->do_damage("torso", roll_dice(10,10)/2);

    return;

}

void die(mixed ob) 
{
    object *player,obj,obj1,*obj2;
    
    obj1 = find_object_or_load(UW+"shark_stomach");
    player = all_living(obj1);
    player = filter_array(player, "is_non_immortal_player", FILTERS_D);

    if(sizeof(player))
    {
        if(obj2=present("stomach lining",obj1)) { obj2->remove(); }
        tell_room(UW"shark_stomach", "%^RED%^The mangled stomach lining rips apart and "
            "a gash forms in the side of the shark!%^RESET%^");
        tell_room(ETO, "%^MAGENTA%^The shark thrashes madly about "
            "as if in great pain!\n%^RESET%^");
        tell_room(ETO, "%^RED%^A gash large enough to crawl into "
            "forms on the stomach of the shark as something inside cuts its "
            "way out!\n%^RESET%^");
        obj1->add_exit(UW"bottom", "gash");
        obj1->set_functions();
        ETO->add_exit(UW"shark_stomach", "crawl");
        ETO->set_invis_exits(({"crawl"}));
        ETO->set_functions();
        obj = new(OBJ"shark_corpse_gashed");
        obj->move(ETO);
    }
    

    else
    {
        if(obj2=present("stomach lining",obj1)) { obj2->remove(); }
        obj = new(OBJ"shark_corpse");
        obj->move(ETO);
    }
 
    tell_room(ETO, "%^RED%^Dire shark drops dead before you.%^RESET%^");
    remove();
}

