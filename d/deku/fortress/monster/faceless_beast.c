#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit WEAPONLESS;

int flag;

void create() 
{
    ::create();
    set_name("faceless beast");
    set_id(({"faceless","beast","faceless beast"}));
    set_gender("neuter");
    set_race("faceless beast");
    set_short("A faceless beast");
    set_long("%^RESET%^This massive beast is made from a smooth, sickly gray "+
    "flesh.  Its grotesque body reaches approximately ten "+
    "feet into the air.  There is no visible hair on it to speak "+
    "of and its face is flat, decorated only with two oblong "+
    "slits that serve for eye sockets.  The eyes resting inside of "+
    "sockets are a lifeless and dull %^BOLD%^%^BLACK%^"+
    "black%^RESET%^.  The torso of this creature is swollen to perhaps "+
    "quadrupal the thickness of the rest of its body and births "+
    "six appendages, instead of the normal two.  Just glancing at "+
    "this creature leaves you with a sick and disturbed feeling.");
  
    set_body_type("human");
    set_alignment(9);
    set_size(3);
    set_hd(24,2);
    set_stats("strength",18);
    set_stats("constitution",12);
    set_stats("wisdom",14);
    set_stats("intelligence",14);
    set_stats("dexterity",21);
    set_stats("charisma",4);
    add_limb("upper right arm","torso",0,0,0);
    add_limb("upper left arm","torso",0,0,0);
    add_limb("lower right arm","torso",0,0,0);
    add_limb("lower left arm","torso",0,0,0);
    add_limb("upper right hand","upper right arm",0,0,0);
    add_limb("upper left hand","upper left arm",0,0,0);
    add_limb("lower right hand","lower right arm",0,0,0);
    add_limb("lower left hand","lower left arm",0,0,0);
    set_attack_limbs(({
	"right hand",
    "left hand",
	"upper right hand",
    "upper left hand",
    "lower left hand",
    "lower right hand",
    }));
    set("aggressive","agg_func");
    set_overall_ac(-2);
    set_property("undead",1);
    set_property("weapon resistance",1);
    set_hp(700 + random(41));
    set_new_exp(20, "high");
    set_damage(2,6);
    set_attacks_num(6);
    set_base_damage_type("bludgeoning");
    set_funcs(({"rage"}));
    set_func_chance(45);
    set_max_level(25);
    if(!random(2)) 
    {
        new(GY_OBJS+"crimson_coif")->move(TO);
        command("wear coif");
    }
    else 
    {
        flag = 1;
    }

}

void die(object ob) 
{
    if(flag == 1) 
    {
        tell_room(ETO,"%^BOLD%^%^WHITE%^You catch glimpse of "+
        "something dull white on the corpse of the faceless "+
        "beast.%^RESET%^",TO);
        new(GY_OBJS+"ivory_bracers")->move(TO);
    }
    ::die();
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    if(TO->query_max_hp() > TO->query_hp()) 
    {
        TO->add_hp(roll_dice(1,20));
    }
}    

void rage(object targ)
{
    int x;
    string *which_hand;
    which_hand = ({"upper right","upper left","upper right","upper left"});
    command("kill "+targ->query_name());
    tell_object(targ,"%^RED%^The %^BOLD%^%^WHITE%^faceless beast%^RESET%^"+
    "%^RED%^ grabs you with its middle and lower hands and begins "+
    "pommeling you in the face with it's upper hands!%^RESET%^"); 

    tell_room(ETO,"%^RED%^The %^BOLD%^%^WHITE%^facless beast%^RESET%^"+
    "%^RED%^ grabs "+targ->QCN+"%^RED%^ with its middle and lower "+
    "hands and begins pommeling "+targ->QO+"%^RED%^ with its upper hands!%^RESET%^",targ);
    for(x = 0; x < 4;x++) 
    {
        tell_object(targ,"%^RED%^The %^BOLD%^%^WHITE%^faceless "+
        "beast%^RESET%^%^RED%^ slams you in the face with its %^BOLD%^"+
        "%^WHITE%^"+which_hand[x]+" hand%^RESET%^%^RED%^!%^RESET%^");
        tell_room(ETO,"%^RED%^The %^BOLD%^%^WHITE%^faceless beast%^RESET%^"+
        "%^RED%^ slams "+targ->QCN+"%^RED%^ in the face with its %^BOLD%^"+
        "%^WHITE%^"+which_hand[x]+" hand%^RESET%^%^RED%^!%^RESET%^",targ);
        targ->do_damage("head",roll_dice(3,12));
    }
   	if(targ->fort_save(28))
	{
        targ->set_paralyzed(roll_dice(4, 6),"%^RED%^You are momentarily stunned "+
        "from the pain!%^RESET%^");
    }
}
   

void agg_func() 
{
    if(!objectp(TP)) return;
    if(!TP->query_true_invis()) { rage(TP); }
}
