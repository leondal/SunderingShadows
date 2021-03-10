#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_name("Aerial Servant");
    set_short("Aerial Servant");
    set_id( ({"servant", "aerial servant", "aerial", "Aerial Servant"}) );
    set_long(
      "You can barely make out the features of this special elemental of the plane of air.  Shimmering before your eyes, it looks like a man made of clouds with hollow holes for eyes, and a slit for a mouth, but he keeps moving around, and easily fades from your view."
    );
    set_gender("neuter");
    set_race("servant");
    set_size(2);
    set_body_type("humanoid");
    set_hd(25, 1);
    set_hp(200+random(150));
    set_attacks_num(3);
    set_class("fighter");
    set_mlevel("fighter", query_hd());
    set_attack_limbs(({"right hand", "left hand"}));
    set_base_damage_type("bludgeoning");
   set_damage(2,6);
    set_overall_ac(-5);
    set("aggressive", 18);
    set_func_chance(30);
    set_funcs( ({"strangle"}) );
    set_invis();
}

void strangle(object targ){

    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
      tell_object(targ, "%^BOLD%^%^CYAN%^The Aerial Servant grabs you in its powerful hands and begins to slowly strangle you to death!");
      tell_room(ETO, "%^BOLD%^%^CYAN%^The Aerial Servant grabs "+targ->query_cap_name()+" and begins to slowly strangle "+targ->query_objective()+" to death!", targ);
      targ->do_damage("torso", roll_dice(8,4));
      targ->set_paralyzed(15, "You're struggling to break the grasp of the Servant.");
    } else {
      tell_object(targ, "%^BOLD%^%^CYAN%^The Aerial Servant tries to strangle you, but you are able to break its grasp.");
      tell_room(ETO, "%^BOLD%^%^CYAN%^The Aerial Servant starts to strangle "+targ->query_cap_name()+" but "+targ->query_cap_name()+" is able to break the Servant's grasp.", targ);
      targ->do_damage("torso", roll_dice(4,4));
    }
    return;
}
