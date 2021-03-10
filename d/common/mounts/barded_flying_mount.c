//Added to allow for barded flying mounts off of the Knight swords
//from Demongate.  The appropriate flying mounts will be consistent
//with the normal barded horses - Octothorpe 7/6/11

#include <std.h>
inherit "/std/flying_mount.c";

nosave int healingStuff;

int is_warhorse() { return 1; }

void create(){
    ::create();
	add_limb("right foreleg","torso",0,0,0);
    add_limb("left foreleg","torso",0,0,0);
	add_limb("right rear leg","torso",0,0,0);
    add_limb("left rear leg","torso",0,0,0);
    add_limb("torso","torso",0,0,0);
    add_limb("head","torso",0,0,0);
    set_attack_limbs( ({"right leg","left leg"}) );
	set_damage(1,10);
	set_stats("strength",18);
    set_body_type("equine");
    set_level(20);
    set_mlevel("fighter",20);
    set_hd(20,10);
    set_max_hp(200);
    set_hp(200);
    set_overall_ac(6);
    set_exp(1);
    set_max_distance(200);
    set_flight_delay(300);
    set_flying_prof(25);
    set_ward_pass(25);
    new("/d/common/obj/armour/barding")->move(TO);
    command("wear barding");
}

int enter(string str){
      if(TP->is_class("paladin")) set_overall_ac(6 - (int)TP->query_class_level("paladin")/2);
      if(TP->is_class("cavalier")) set_overall_ac(6- (int)TP->query_class_level("cavalier")/2);
      if(TP->is_class("antipaladin")) set_overall_ac(6 - (int)TP->query_class_level("antipaladin")/2);
    return ::enter(str);
}

int restrict_mount_ok(object who) {
    int lev, temp, hurt, newhp;
    lev = who->query_level();

    if (who->is_class("paladin") || who->is_class("cavalier") || who->is_class("antipaladin")) {
        temp = query_hp();
	  hurt = query_max_hp() - temp;
        set_level(lev);  // this wasn't working for some reason so using mlevel
        set_riding_level(who->query_skill("athletics"));
        set_mlevel("fighter",lev);
        set_hd(lev,10);
        set_max_hp(20*lev);
        set_hp(query_max_hp() - hurt);
        set_damage(1,lev/2);
        set_stats("strength",20);
        if (healingStuff || query_max_hp() < query_hp()) {
            set_hp(query_max_hp());
            healingStuff = 0;
        }
        return 1;
    }
    set_level(20);
    set_riding_level(20);
    set_mlevel("fighter",20);
    set_hd(20,10);
    set_stats("strength",18);
    set_max_hp(200);
    if (healingStuff || query_max_hp() < query_hp()) {
       set_hp(query_max_hp());
       healingStuff = 0;
    }
    set_damage(1,10);
    return 1;
}
