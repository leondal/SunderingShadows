#include <std.h>
#include <daemons.h>
#include "../inherits/area_stuff.h"
#define GRACES ({"human", "half-orc", "half-elf", "halfling", "orc"})
inherit MONSTER;

void create() 
{
    int myLev;
    string me;
    object ob;
    ::create();
    set("aggressive",40);

    if(!random(2)) set_gender("male");
    else set_gender("female");

    set_id(({ "crazed", "guard", "hhcrazedguard"}));	
    set_race(GRACES[random(sizeof(GRACES))]);

    set_name("crazed "+query_gender() + " "+query_race()+" guard"); 
    
    set_short("%^BOLD%^%^RED%^"+query_race()+" with a crazed look in "+TO->QP+" eyes%^RESET%^");

    set_long("%^BOLD%^%^RED%^The "+query_race()+" before you looks "+
    "broken. "+capitalize(TO->QP)+" eyes dart about crazily and a look of "+
    "deep %^BOLD%^%^BLUE%^confusion%^BOLD%^%^RED%^ is projected "+
    "from them. "+capitalize(TO->QP)+" body is slumped over, "+TO->QP+" shoulders "+
    "shrugged, almost as if "+TO->QS+" has given up on life. "+
    capitalize(TO->QP) +" mouth is dry, far too dry, and "+TO->QS+ " manages to "+
    "slobber on "+TO->QO+"self sporadically. Many wounds crisscross "+
    "the exposed portions of "+TO->QP+" flesh and blood drips "+
    "freely from several. "+capitalize(TO->QP)+" hair is matted with thick "+
    "layers of dirt and "+TO->QS+" gives off an potent odor of "+
    "filth.%^RESET%^");

    myLev = 27 + random(3);
    set_hd(myLev,3);
    set_class("fighter");
    set_mlevel("fighter", myLev);
    set_monster_feats(({
        "parry",
    }));
    if(!random(2)) 
    {
        set_class("thief");
        set_mlevel("thief", myLev);
        set_monster_feats(({
            "parry",
            "scramble", 
            "flash"
        }));    
        set_invis();
    }
    else if(!random(4))
    {
        set_class("mage");
        set_mlevel("mage", myLev);
        set_monster_feats(({
            "perfect caster",
        }));	    
        set_spells(({"meteor warm", "prismatic spray", "lightning bolt", "fireball"}));
        set_spell_chance(60);
    }
    set_body_type("humanoid");
    set_alignment(9);
    set_stats("intelligence",8);
    set_stats("wisdom",8);
    set_stats("strength",18);
    set_stats("charisma",3);
    set_stats("dexterity",18);
    set_stats("constitution",18);

    set_overall_ac(-23);

    set_new_exp(28,"medium");
    set_max_hp((myLev*15) + random(30));    
    
    set_hp(query_max_hp());
    me = TO->query_short();
    me = capitalize(me);
    set_achats(4,({
        me +"%^BOLD%^%^BLUE%^ screams: %^RESET%^ LET ME OUT OF HERE!!", 
        me + "%^BOLD%^%^CYAN%^ begs: %^RESET%^ Please, someone save me....",
        me + "%^BOLD%^%^GREEN%^ pleads with no one in particular: %^RESET%^Why won't you let me go????",
        me + "%^BOLD%^%^BLUE%^ asks: %^RESET%^Where's that door out again????",
    }));
    set_emotes(4,({
        me +"%^BOLD%^%^WHITE%^ sighs loudly and then suddenly screams, looking around rapidly!%^RESET%^",
        me + "%^BOLD%^%^RED%^ runs into a wall and then stumbles, barely managing to regain "+TO->QP+" balance!%^RESET%^",
        me + "%^BOLD%^%^GREEN%^ kicks at some invisible creature, cursing under "+TO->QP+" breath.%^RESET%^",
        me + "%^BOLD%^%^BLUE%^ SCREAMS and covers "+TO->QP+" eyes!%^RESET%^",    		
    }),0);
  
    set_property("full attacks",1);
    add_search_path("/cmds/fighter");
    set_funcs(({"insanity", "rage"}));
    set_func_chance(35);
    set_moving(1);
    set_speed(45);
    set_nogo(({RROOMS+"3", BROOMS+"1"}));
    ob = new(AOITEMS+"midnights_edge");
    if(random(100)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield scimitar");
    ob = new(AOITEMS+"midnights_edge");
    ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield scimitar");
    //set_nogo(({FFTR"40", FFGTR"13", FFGTR"28"}));	
}

void rage(object targ)
{
    string tlim;
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    me = capitalize(me);
    tell_object(targ, me + " %^BOLD%^%^GREEN%^G%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
    "G%^BOLD%^%^YELLOW%^G%^BOLD%^%^GREEN%^L%^BOLD%^%^YELLOW%^E%^BOLD%^%^GREEN%^S"+
    "%^BOLD%^%^RED%^ insanely and charges at you, both of "+TO->QP+" weapons "+
    "swinging wildly!%^RESET%^");

    tell_room(ETO, me+" %^BOLD%^%^GREEN%^G%^BOLD%^%^YELLOW%^I%^BOLD%^%^GREEN%^"+
    "G%^BOLD%^%^YELLOW%^G%^BOLD%^%^GREEN%^L%^BOLD%^%^YELLOW%^E%^BOLD%^%^GREEN%^S"+
    "%^BOLD%^%^RED%^ insanely and charges at "+targ->QCN+"%^BOLD%^%^RED%^"+
    ", both of "+TO->QP+" weapons swinging wildly!%^RESET%^", targ);

    if(targ->reflex_save(25)) 
    {
        tell_object(targ, "%^BOLD%^%^CYAN%^You quickly step to the side "+
        "and "+me+"%^BOLD%^%^CYAN%^ spins wildly out of control, losing "+
        TO->QP+" balance!%^RESET%^");

        tell_room(ETO, targ->QCN+"%^BOLD%^%^CYAN%^ steps quickly to the "+
        "side and "+me+"%^BOLD%^%^CYAN%^ spins widly out of control, "+ 
        "losing "+TO->QP+ " balance!%^RESET%^", targ);
	
        TO->set_tripped(2, "You struggle to regain your balance!");
        return;
    }
    else
    {
        tlim = targ->return_target_limb();
		
        tell_object(targ, me+ "%^BOLD%^%^WHITE%^ slams into you, focusing "+TO->QP+
        " attacks on your "+tlim+", slicing deep into it!%^RESET%^");
	
        tell_room(ETO, me + "%^BOLD%^%^WHITE%^ slams into "+targ->QCN + 
        "%^BOLD%^%^WHITE%^, focusing "+TO->QP+" attacks on "+targ->QP + 
        " " +tlim+" and slices deep into it!%^RESET%^", targ);
        
        targ->set_paralyzed(8, "%^BOLD%^%^RED%^You are recovering from "+
        "the attack!%^RESET%^");

        TO->set_paralyzed(8, "%^BOLD%^%^RED%^You are recovering from "+
        "the attack!%^RESET%^");	
		
        targ->cause_typed_damage(targ, tlim, roll_dice(20, 6), "slashing");
        return;
    }
}

void insanity(object targ)
{
    string tlim;
    string me;
    int x;
    object *living;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    me = capitalize(me);
    living = all_living(ETO);
    living -= ({TO});
	
    tell_room(ETO, me +"%^BOLD%^%^GREEN%^ S%^BOLD%^%^RED%^C%^BOLD%^%^GREEN%^"+
    "R%^BOLD%^%^RED%^E%^BOLD%^%^GREEN%^A%^BOLD%^%^RED%^M%^BOLD%^%^GREEN%^S "+
    "%^RESET%^: "+targ->QCN+" is the REASON we are STUCK here, get "+targ->QO+
    "!%^RESET%^");
	
    for(x = 0;x < sizeof(living);x++)
    {
        if(!living[x]->id("hhcrazedguard")) continue;
		
        tell_room(ETO, living[x]->query_short()+" %^BOLD%^%^RED%^GROWLS "+
        "in %^BOLD%^%^YELLOW%^RAGE%^BOLD%^%^RED%^ and turns "+living[x]->QP+
        " attention toward "+targ->QCN+"!%^RESET%^", targ);

        tell_object(targ, living[x]->query_short()+" %^BOLD%^%^RED%^GROWLS "+
        "in %^BOLD%^%^YELLOW%^RAGE%^BOLD%^%^RED%^ and turns "+living[x]->QP+
        " attention toward you!%^RESET%^");

        living[x]->rage(targ);
        continue;
    }
    rage(targ);
}