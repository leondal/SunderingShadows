#include <std.h>
#include "../inherits/area_stuff.h"
inherit MONSTER;
int undead;

void create() 
{
    ::create();
    set_name("arag dyne");
    set_id(({"arag", "dyne", "arag dyne", "manipulator"}));
    set_gender("male");
    set_race("human");

    set_short("%^BOLD%^%^BLACK%^Ar%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^g Dyn%^BOLD%^"+
    "%^WHITE%^e%^BOLD%^%^BLACK%^, The Man%^BOLD%^%^WHITE%^i%^BOLD%^%^BLACK%^"+
    "pulator%^RESET%^");

    set_long("%^BOLD%^%^WHITE%^The man before you is short, barely "+
    "reaching five feet tall. He has an exceedingly tiny stature and "+
    "most of his visible body is quite pale, as if he has not seen the "+
    "sunlight in far too long. His %^RESET%^%^ORANGE%^dark brown%^BOLD%^"+
    "%^WHITE%^ hair is long and kept pulled back in a ponytail. He has "+
    "large ears that clash with his small beaky nose. His eyes are a "+
    "%^RESET%^%^GREEN%^deep emerald%^BOLD%^%^WHITE%^ and would almost be "+
    "pretty if not for the fact that they look %^BOLD%^%^BLACK%^hollow"+
    "%^BOLD%^%^WHITE%^ and lifeless. He wears a very dull black robe that "+
    "is covered with patches and holes where patches have worn off.%^RESET%^");
  
    set_body_type("human");
    set_alignment(9);
    set_size(2);
    set_class("sorcerer");
    set_level(34);
    set_guild_level("sorcerer", 34);
    set_mlevel("sorcerer", 35);
    set_stats("strength",17);
    set_stats("constitution",17);
    set_stats("wisdom",15);
    set_stats("intelligence",20);
    set_stats("dexterity",15);
    set_stats("charisma",25);
 
    set("aggressive",26);
    set_overall_ac(-25);

    set_mob_magic_resistance("average");
    set_property("weapon resistance", 3);

    set_hp(2500 + random(550));

    set_new_exp(32, "boss");

    set_spells(({"meteor swarm", "prismatic spray",
    "cone of cold"}));
    set_spell_chance(90);
    set_funcs(({"leech_life", "chaos"}));
    set_func_chance(70);
    set_property("no tripped", 1);
    set_monster_feats(({
        "perfect caster",
        "spell penetration",
        "greater spell penetration",
        "spell reflection",
    }));
    undead = 0;
}

void make_undead() 
{
    set_spell_chance(105);
    set_func_chance(5);

    tell_room(ETO, "%^BOLD%^%^MAGENTA%^All life in "+TO->query_short() + 
    "%^BOLD%^%^MAGENTA%^ withers away and all that is left is a rotting husk of flesh!%^RESET%^");  
    
    set_short("%^RESET%^%^ORANGE%^The rotting husk of "+
    "%^BOLD%^%^BLACK%^Ar%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^g Dyn%^BOLD%^"+
    "%^WHITE%^e%^RESET%^");

    set_long("%^RESET%^%^ORANGE%^The creature before you is tiny, "+
    "barely reaching five feet tall. His body is withered and broken, "+
    "pale flesh hanging loosely from his bones. His dark brown hair "+
    "has falling off of his head, save only a few loose strands. "+
    "The cartilage of his large ears is visible and has turned "+
    "black, his once beaky nose has rotted away, leaving a gooey "+
    "hole in its place. His %^RESET%^%^GREEN%^"+
    "dark emerald%^RESET%^%^ORANGE%^ eyes portray an immense fear, as if "+
    "his body is controlled by something other than his own mind. The "+
    "one dull black robe that adorned his body has melted to him, "+
    "becoming one with his own flesh.%^RESET%^%^ORANGE%^");

    undead = 1; 
}

void die(object ob) 
{
    if(!undead)
    {
        TO->set_hp(query_max_hp());
        all_inventory(ETO)->cease_all_attacks();
        tell_room(ETO, "%^BOLD%^%^BLACK%^Ar%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^g Dyn%^BOLD%^"+
        "%^WHITE%^e%^BOLD%^%^BLACK%^ cackles insanely before uttering%^RESET%^: "+
        "I will %^BOLD%^%^RED%^NEVER%^BOLD%^%^BLACK%^ die and when I raise "+
        "Au'rus Devar and make him my SERVANT I shall RULE THIS WORLD!!!%^RESET%^");
        tell_room(ETO, "%^BOLD%^%^BLACK%^Ar%^BOLD%^%^WHITE%^a%^BOLD%^%^BLACK%^g Dyn%^BOLD%^"+
        "%^WHITE%^e%^BOLD%^%^BLACK%^ %^BOLD%^%^CYAN%^blinks%^BOLD%^%^BLACK%^ out of "+
        "existence!%^RESET%^");
        TO->move("/d/shadowgate/void");     
        TO->remove();   
        return 0;
	}	
    ::die();
}

void leech_life(object targ)
{
    object *targs;
    string me, lim;
    int x, dam, myHeal = 0;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    me = TO->query_short();

    tell_room(ETO, me +"%^BOLD%^%^GREEN%^ opens his arms wide and "+
    "six %^BOLD%^%^BLACK%^withered tendrils%^BOLD%^%^GREEN%^ "+
    "shoot out from his chest!%^RESET%^");
	
    targs = all_living(ETO);
    targs -= ({TO});
    x = 2;

    while(x--)
    {
        targ = targs[random(sizeof(targs))];
        if(!objectp(targ)) continue;
        tell_object(targ, "%^BOLD%^%^BLACK%^One of the %^BOLD%^%^RED%^"+
        "withered tendrils%^BOLD%^%^BLACK%^ grasps at you!%^RESET%^");

        tell_room(ETO, "%^BOLD%^%^BLACK%^One of the %^BOLD%^%^RED%^"+
        "withered tendrils%^BOLD%^%^BLACK%^ grasps at "+targ->QCN+
        "%^BOLD%^%^BLACK%^!%^RESET%^", targ);
	
        if(targ->reflex_save(25)) 
        {
            tell_object(targ, "%^BOLD%^%^GREEN%^You move quickly and "+
            "are able to avoid the %^BOLD%^%^BLACK%^withered "+
            "tendril%^BOLD%^%^GREEN%^!%^RESET%^");

            tell_room(ETO, targ->QCN+"%^BOLD%^%^GREEN%^ moves quickly and "+
            "is able to avoid the %^BOLD%^%^BLACK%^withered "+
            "tendril%^BOLD%^%^GREEN%^!%^RESET%^", targ);
            continue;
        }
        lim = targ->return_target_limb();
        
        tell_object(targ, "%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^"+       
        "withered tendril%^BOLD%^%^RED%^ latches onto your "+
        lim+" for a brief moment and you can feel your "+
        "%^BOLD%^%^WHITE%^LIFE%^BOLD%^%^RED%^"+
        " drains some of your lifeforce!%^RESET%^");

        tell_room(ETO, "%^BOLD%^%^RED%^The %^BOLD%^%^BLACK%^"+
        "withered tendril%^BOLD%^%^RED%^ latches onto "+targ->QCN+
        "%^BOLD%^%^BLACK%^'s "+lim+" for a brief moment!%^RESET%^", targ);

        dam = roll_dice(8, 10)+10;
        set_property("noMissChance",1);
        targ->cause_typed_damage(targ, lim, dam, "negative energy");
        set_property("noMissChance", -1);
        myHeal += dam;	
        continue;
    }
    if(myHeal)
    {
        tell_room(ETO, me +"%^BOLD%^%^RED%^ cackles insanely as "+
        "the tendrils retract back into his chest, restoring his "+
        "a portion of his %^BOLD%^%^WHITE%^LIFEFORCE%^BOLD%^%^RED%^!%^RESET%^");
        TO->heal(myHeal);
    }
    return;
}

void chaos(object targ)
{
    int dam, x;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(!objectp(ETO)) return;
    if(base_name(ETO) != RROOMS+"23" || undead)
    {
        leech_life(targ);
        return;
    }
    me = TO->query_short();
    command("speak wizish");

    command("whisper "+targ->query_name()+" you will soon be dead and the "+
    "chaos that will ensue shall grip your entire world, until THERE IS "+
    "NOTHING left to stand in my way!!!");

    tell_room(ETO, me + "%^BOLD%^%^RED%^ cackles insanely before pointing "+
    "at "+targ->QCN+" and uttering a few words in an ancient "+
    "language!%^RESET%^", targ);

    tell_object(targ, me + "%^BOLD%^%^RED%^ cackles insanely before pointing "+
    "at you and uttering a few words in an ancient language!%^RESET%^");

    ETO->head_damage(targ, (1+random(4)));
    return;
}

void set_paralyzed(int time,string message){return;}

