#include <std.h>
#include "../area_stuff.h"

inherit ELDEBARO_MONSTER;
int lev;

void create() 
{
    object ob;
    ::create();
    set_name("desert ogre");
    set_id( ({"ogre", "desert ogre", "eldebarocreature"}) );
    
    set_short("%^RESET%^%^ORANGE%^A massive and cr%^BOLD%^a%^RESET%^%^ORANGE%^z"+
    "%^BOLD%^ed %^RESET%^%^ORANGE%^ogre%^RESET%^");
    
    set_long("%^RESET%^%^ORANGE%^This massive ogre towers almost eleven feet in the air. "+
    "His face is set in a vicious %^BOLD%^%^RED%^scowl%^RESET%^%^ORANGE%^ almost constantly, as if "+
    "something has really pissed him off. Most of his body is coated with a thick layer of "+
    "sand, which creates the impression of his flesh being lined with thick and deep "+
    "%^BOLD%^cracks%^RESET%^%^ORANGE%^. His legs and arms are thick and meaty, rippling "+
    "with massive muscles and his torso appears almost swollen. He carries two vicious spiked "+
    "clubs which he swings about wildly. He is completely naked except for the thick coat of "+
    "sand. A dark %^BOLD%^%^BLACK%^shadow%^RESET%^%^ORANGE%^ "+
    "hangs heavily over him.%^RESET%^");
    
    set_gender("male");
    set_race("ogre");
    set_body_type("human");
    set_overall_ac(5);
    set_property("swarm",1);
    lev = 32 + random(9);
    set_class("fighter");
    set_mlevel("fighter", lev);
    set_guild_level("fighter", lev);
    set_new_exp(lev,"normal");
    
    
    set_overall_ac(-19);
    set_property("add kits",12);
    
    set_stats("strength",22);
    set_stats("dexterity",19);
    set_stats("constitution",22);
    set_stats("intelligence",1);
    set_stats("wisdom",1);
    set_stats("charisma",1);
    
    add_attack_bonus(roll_dice(1,10));
    add_damage_bonus(roll_dice(1,6));
    
    set("aggressive", 55);
    set_alignment(9);
    set_speed(20);
    set_nogo(({DOCKROOM}));
    set_size(3);
    set_max_hp(lev * 25);
    set_hp(query_max_hp());
    
    set_property("full attacks", 2);
    
    add_money("gold", 750 + random(601));

    set_monster_feats(({
      "ambidexterity",
      "unassailable parry",
      "whirl"
    }));
    
    set_funcs(({
	   "bow_before_me",
       "bow_before_me",
       "bow_before_me",
       "bow_before_me",
       "bow_before_me",
       "something_evil"
	}));
    set_func_chance(35);   
    set_nogo(({ELROOMSD+"51",ELROOMSD+"102",ELROOMSD+"178",ELROOMSD+"107"}));    
    ob = new("/d/common/obj/armour/studded");
    ob->move(TO);
    ob->set_property("enchantment",1);
    ob->set_property("size",3);
    ob->set_property("monsterweapon",1);
    command("wear studded");
    if(random(5))
    {
        ob = new("/d/common/obj/weapon/club_lg");
        ob->set_property("enchantment", 5);        
    }
    else { ob = new(ELOB+"violent_smasher"); }
    ob->move(TO);
    command("wield club");
    ob = new("/d/common/obj/weapon/club_lg");
    ob->set_property("enchantment", 5);  
    ob->move(TO);
    command("wield club");
}

void bow_before_me(object targ)
{
    string me;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(targ)) return;
    me = TO->query_short();
    
    tell_object(targ, me + "%^RESET%^%^ORANGE%^ turns to face you and %^BOLD%^%^RED%^SCREAMS"+
    "%^RESET%^%^ORANGE%^: BOW BEFORE ME!%^RESET%^");
    
    tell_room(ETO, me +"%^RESET%^%^ORANGE%^ turns to face "+targ->QCN+"%^RESET%^%^ORANGE%^ and "+
    "%^BOLD%^%^RED%^SCREAMS%^RESET%^%^ORANGE%^: BOW BEFORE ME!%^RESET%^", targ);
    
    if(targ->will_save(25))
    {
        tell_object(targ, "%^BOLD%^%^WHITE%^You feel something %^BOLD%^%^BLACK%^EATING%^BOLD%^%^WHITE%^ "+
        "at your mind but you manage to resist the influence!%^RESET%^");
        tell_room(ETO, targ->QCN +"%^BOLD%^%^WHITE%^ simply refuses "+me+"%^BOLD%^%^WHITE%^!%^RESET%^", targ);
        return;
    }
    
    tell_object(targ, "%^BOLD%^%^BLACK%^Almost inexplicably you feel yourself fall to your knees "+
    "before "+me+" and look up at him, awaiting his instruction as his massive spiked club "+
    "slams into your head!%^RESET%^");
    
    tell_room(ETO, targ->QCN+"%^BOLD%^%^BLACK%^ inexplicably falls to "+targ->QP+
    " knees before "+me+"%^BOLD%^%^BLACK%^ and looks up at him!! "+me+" slams his spiked club into "+
    targ->QCN+"%^BOLD%^%^BLACK%^'s head!%^RESET%^", targ);    
    
    targ->cause_typed_damage(targ, "head", roll_dice(12, 12), "bludgeoning");
    return;   
}

int query_watched() { return random(101); }
