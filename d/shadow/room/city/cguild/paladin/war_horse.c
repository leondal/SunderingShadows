#include <std.h>

// inherit "/std/riding_animal.c";  
// last change was 2/25/01
// changing per Garrett to use the common file to fix bugs *Styx* 10/18/03
inherit "/d/common/mounts/war_horse.c";

// private nosave int healingStuff;

void create(){
    ::create();
/* should be coming from the inherit now
    set_id(({"war horse","horse","warhorse"}));
    set_name("horse");
    set_short("war horse");
    set_long("This is a powerfully built, well trained war horse. Obviously this belongs to someone very trained, it would be dangerous to even try and ride it.");
    set_level(10);
    set_value(1000);
    set_race("horse");
    set_gender("male");
    set_body_type("equine");
    set_size(3);
    set_max_hp(10000);
    set_hd(10,2);
    set_hp(100);
    set_overall_ac(6);
    set_exp(1);
    set_max_distance(20);
    set_enter_room("rides in");
    set_exit_room("leaves riding a war horse.");
    set_vehicle_short("War horse");
    set_attack_limbs(({"right forehoof","left forehoof"}));
    set_attacks_num(2);
    set_damage(2,6);
    healingStuff = 1;
    set_stats("strength",18);
*/
}

/* let the inherit handle this now
int enter(string str){
    int lev, temp;

    lev = TP->query_level();

    if (TP->is_class("paladin") || TP->is_class("cavalier") || TP->is_class("antipaladin")) {
        temp = query_hp();
        set_level(lev);
        set_hp(temp);
        set_damage(1,lev/2);
        if (lev>100 )
            set_max_hp(100*lev);
        set_stats("strength",20);
        if (healingStuff || query_max_hp() < query_hp()) {
            set_hp(query_max_hp());
            healingStuff = 0;
        }
    } else {
        set_hd(10,2);
        set_level(10);
        set_stats("strength",18);
        set_max_hp(100);
        if (healingStuff || query_max_hp() < query_hp()) {
            set_hp(query_max_hp());
            healingStuff = 0;
        }
        set_damage(2,6);
    }
    if (!TP->is_class("paladin") && !TP->is_class("antipaladin") &&!TP->is_class("ranger") && !TP->is_class("druid") && !TP->is_class("cavalier"))
        return notify_fail("The horse will not let you mount it!\n");
    else
        return ::enter(str);
    return 1;
}

void set_level(int x){
    ::set_level(x);
    set_riding_level(x);
}
*/
