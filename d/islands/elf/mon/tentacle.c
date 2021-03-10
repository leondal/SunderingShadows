#include <std.h>
#include "../elf.h"
inherit WEAPONLESS;

#define VQCN vic->query_cap_name()


void create() 
{
    ::create();
    set_name("tentacle");
    set_id(({"tentacle","slimey tentacle","monster"}));
    set_short("%^RESET%^BLUE%^tentacle%^RESET%^");
    set_long("This is a huge tentacle  formed from an inky"+
        " purple-black flesh.  It reaches out "+
        "from the sea.  "+
        "The thing looks terrifying.");
    set_overall_ac(3);
    set_race("tentacle");
    set_property("swarm",1);
    set_body_type("snake");
	remove_limb("mouth");
	remove_limb("head");
	remove_limb("tail");
    add_limb("tentacle","torso",0,0,0);
    set_hd(15,8);
    set_max_hp(450);
    set_hp(450);
    set_size(2);
    set_stats("strength",18);
    set_attacks_num(2);
    set_attack_limbs(({"tentacle"}));
    set_damage(3,8);
    add_attack_bonus(15);
	set_property("damage resistance",6); 
	set_property("spell resistance",30);
    set_property("no dominate",1);
    set_alignment(5);
    set_base_damage_type("bludgeoning");
    set_emotes(9,({"The tentacle grasps for you!",
        "The tentacle tears at you!",}),1);
    set("aggressive","aggfunc");
	set_property("swarm",1);
	set_new_exp(31,"normal");
    set_max_level(35);
	set_base_damage_type("bludgeoning"); 
  
}
void aggfunc() 
{
    if(!objectp(TP)) { return; }
    if(TP->query_true_invis()) { return; }
    call_out("pull1",1,TP);
    //TO->kill_ob(TP,1); byuhaha
}
void pull1(object targ) 
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }    
    tell_object(targ,"%^BOLD%^%^BLUE%^The tentacles now have you firmly in their grasp!");
    tell_room(ETO,"%^BOLD%^%^BLUE%^The tentacles have seized "+targ->QCN+"'s ankles firmly!",targ);
    call_out("pull2",15,targ);
	targ->set_tripped(5,"%^ORANGE%^The tentacle has pulled you from your feet.");
}

void pull2(object targ) 
{

    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }
    tell_object(targ,"%^BOLD%^%^BLUE%^The tentacles are pulling you down "+
	"to the water!");
    tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" is being pulled"+
	" to the water!",targ);
    call_out("pull3",20,targ);
}

void pull3(object targ) 
{
    if(!objectp(targ))      { return; }
    if(!objectp(TO))        { return; }
    if(!present(targ,ETO))  { return; }
    tell_object(targ,"%^BOLD%^%^BLUE%^Suddenly you feel the cold of the sea under you"+
    ".The water begins to fill your lungs as you slowly fade"+
    " out.");
    tell_room(ETO,"%^BOLD%^%^BLUE%^"+targ->QCN+" is pulled beneath the surface of the sea!",targ);
    //targ->set_paralyzed(100,"You are under the water, you can't breathe!");
    targ->move_player(SHORE"water");
 
    return ;
}


void init()
{
    string *exits;
    int i,j;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(TP)) { return; }
    if(!interactive(TP)) { return; }
    if("/daemon/saving_throw_d.c"->reflex_save(TP,-25)) {return;}
    ::init();
    exits = ETO->query_exits();
    j = sizeof(exits);
	
    for(i=0;i<j;i++)
    add_action("noway",exits[i]);
}

int noway(string str)
{
    if (TO->query_hp() < 0 ) 
    {
        while (remove_call_out("pull1") != -1) ;
        while (remove_call_out("pull2") != -1) ;
        while (remove_call_out("pull3") != -1) ;
        TO->die();
        return 0;
    }

    write("%^CYAN%^You cannot escape the grip of the tentacle!");
    tell_room(ETO,"%^BOLD%^%^BLUE%^"+TPQCN+" struggles but cannot"+
	" escape the grip of the tentacle.",TP);
    return 1;
}
/*
int grab_func(object vic) {
   if(!"/daemon/saving_throw_d.c"->reflex_save(vic,-25)){
     vic->set_paralyzed(10+random(20),"%^BLUE%^The tentacle holds you fast.");
   tell_object(vic,"%^BLUE%^The tentacle grasps ahold of you as suction cups sink into your flesh!");
   tell_room(ETO,"%^BLUE%^The tentacle wraps "+VQCN+".",vic);
   return roll_dice(5,10);}
   else 
   tell_object(vic,"%^ORANGE%^You evade the tentacle's attempt to wrap around you.");
   return 0;
}
*/
void die(object ob) {
   tell_room(ETO,"%^BOLD%^%^BLUE%^The tentacle is cut clean through and pulls back down into the water!");
    TO->remove();
}