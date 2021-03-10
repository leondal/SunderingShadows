#include <std.h>
#include "../ogres.h"

inherit WEAPONLESS;

void init() {
    ::init();
    if(TP->query_true_invis())   return;
    if(TP->query_invis()) {
      tell_room(ETO, "%^RESET%^RED%^The Zovvut glares in your direction. Power flares "+
"as it pulls you violently from your hiding.");
      TP->set_invis();
    }
    call_out("kill_ob", 5, TP, 1);
}

void create() {
    object ob;
    ::create();
    set_name("Zovvut");
    set_id( ({"demon", "zovvut demon", "Zovvut", "zovvut", "cavemon"}) );
    set_short("%^RESET%^%^BOLD%^%^BLACK%^Z%^RESET%^%^RED%^ov%^RESET%^%^BOLD%^%^BLACK%^v"+
"%^RESET%^%^RED%^u%^RESET%^%^BOLD%^%^BLACK%^t D%^RESET%^%^RED%^e%^RESET%^%^BOLD%^%^BLACK%^mon%^RESET%^");
    set_long(
      "%^RESET%^Almost angelic, it would be easy to mistake this creature for something "+
"g%^BOLD%^%^WHITE%^o%^RESET%^od and pu%^BOLD%^%^CYAN%^r%^RESET%^e, walking right into "+
"its' waiting grasp. Large %^BOLD%^%^WHITE%^whi%^RESET%^t%^BOLD%^%^WHITE%^e wi%^RESET%^"+
"n%^BOLD%^%^WHITE%^gs %^RESET%^extend from the back of this pale skinned creature. Though"+
" dappled with %^BOLD%^%^BLACK%^r%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^t %^RESET%^and %^BOLD%^"+
"%^BLACK%^rag%^RESET%^%^RED%^g%^BOLD%^%^BLACK%^ed%^RESET%^, the very appearance of something"+
" so %^BOLD%^%^WHITE%^b%^CYAN%^e%^WHITE%^nev%^CYAN%^ol%^WHITE%^ent %^RESET%^in a place such "+
"as this, is often to lead one astray. But the %^BOLD%^%^BLACK%^Z%^RESET%^%^RED%^ov%^BOLD%^"+
"%^BLACK%^v%^RESET%^%^RED%^u%^BOLD%^%^BLACK%^t %^RESET%^is hardly angelic. Its' muscular body"+
" is ribboned with lumpy %^BOLD%^%^BLACK%^mas%^RESET%^s%^BOLD%^%^BLACK%^es %^RESET%^of bundled"+
" flesh and the stench of %^RED%^br%^BOLD%^%^BLACK%^i%^RESET%^%^RED%^mst%^BOLD%^%^BLACK%^o"+
"%^RESET%^%^RED%^ne %^RESET%^hovers about it. Its maw is thick and square with jagged, misshapen"+
" teeth jutting from its lower lip. Three baleful %^RED%^r%^RESET%^e%^RED%^d ey%^RESET%^e%^RED%^"+
"s %^RESET%^crown its brow, with the third, center one, never blinking or looking away. Worse "+
"yet is the long sharp %^BOLD%^%^BLACK%^pi%^WHITE%^n%^BLACK%^cers %^RESET%^that serve as hands."+
" Over large and jagged, one snap of them and a body could be cut in two.%^RESET%^"
    );
    set_race("demon");
    set_body_type("human");
    set_gender("male");
    set_size(2);
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_hd(26,5);
    set_attack_bonus(6);
    set_max_hp(300+random(250));
    set_hp(query_max_hp());
    set_overall_ac(-34);
    add_limb("left wing","left wing",100,1,6);
    add_limb("right wing","right wing",100,1,6);
    add_limb("left pincer", "left pincer",50,1,8);
    add_limb("right pincer", "right pincer",50,1,8);
    add_limb("fangs", "fangs",25,1,7);
    set_attacks_num(4);
    set_attack_limbs( ({"right pincer", "left pincer", "fangs",
"right wing", "left wing"}) );
    set_base_damage_type("slashing");
    set_damage(5,7);
    set_property("swarm",1);
    set_stats("strength", 18);
   set("aggressive", 25);
    set_mob_magic_resistance("average");
    set_alignment(9);
    add_money("gold", random(1500));
    add_money("silver", random(4500));
    set_funcs(({"wings", "grab"}));
    set_func_chance(30);
   if(!random(15)) {
     ob = new("/d/common/obj/brewing/herb_special_inherit");
     ob->set_herb_name("patch of demonskin");
     ob->move(TO);
   }
    set_resistance("electricity",10);
    set_resistance("acid",5);
    set_resistance("cold",5);
    set_resistance("fire",5);
}

void wings(object targ) {

    tell_room(ETO, "%^RESET%^%^BOLD%^%^BLACK%^The demon spreads its%^RESET%^%^BOLD%^%^WHITE%^ g%^RESET%^%^WHITE%^i%^RESET%^%^BOLD%^%^WHITE%^ant whi%^RESET%^%^WHITE%^t%^RESET%^%^BOLD%^%^WHITE%^e wi%^RESET%^%^WHITE%^n%^RESET%^%^BOLD%^%^WHITE%^gs %^RESET%^%^BOLD%^%^BLACK%^and turns in your direction.%^RESET%^");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_object(targ, "%^RESET%^%^BOLD%^You stand in awe of the demon!");
      tell_room(ETO, "%^RESET%^%^BOLD%^"+targ->query_cap_name()+"%^RESET%^%^BOLD%^ stands motionless!");
      targ->set_paralyzed(random(20)+15, "%^RESET%^%^BOLD%^You are in awe of the demon!");
    } else {
      tell_room(ETO, "%^RED%^%^BOLD%^The demon screams in rage!%^RESET%^");
    }
}

void grab(object targ) {
    tell_room(ETO, "%^RED%^%^BOLD%^The demon dives at "+targ->query_cap_name()+"%^RED%^%^BOLD%^ trying to capture "+targ->query_objective()+" in their pincers!", targ);
    tell_object(targ, "%^RED%^%^BOLD%^The demon dives at you, grabbing you with giant pincers!%^RESET%^");

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
      tell_room(ETO, "%^RED%^%^BOLD%^"+targ->query_cap_name()+"%^RED%^%^BOLD%^ is grabbed by the demon and crushed by the pincers!%^RESET%^", targ);
      tell_object(targ, "%^RED%^%^BOLD%^The demon grabs you and crushes you in its pincers!%^RESET%^");
      targ->set_paralyzed(random(20)+15, "You are being crushed!!");
      targ->do_damage(targ->return_target_limb(),roll_dice(20,20));
      return 1;
    } else {
      tell_room(ETO, "%^GREEN%^"+targ->query_cap_name()+" escapes the pincers!", targ);
      tell_object(targ, "%^GREEN%^You dive out of the way of the demon!");
      return 1;
    }
}
