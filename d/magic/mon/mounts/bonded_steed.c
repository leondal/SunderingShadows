#include <std.h>
inherit "/d/common/mounts/barded_war_horse";

void create(){
    ::create();
    set_name("a magnificent steed trained for battle");
    set_id( ({"steed","horse","magnificent steed","bonded steed"}) );
    set_level(10);
    set_value(0);
    set_race("horse");
    if(random(2)) set_gender("female");
    else set_gender("male");
    set_body_type("equine");
    set_attack_limbs( ({"right forehoof", "left forehoof"}) );
    set_damage(2,6);
}

int enter(string str){
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" approaches the steed, but seems wary of trying to mount it!", TP);
        return notify_fail("The steed is far too fine a beast for you to ride!\n");
    }
    return ::enter(str);
    return 1;
}

int handle_critter(string str) {
    tell_room(ETP,"The steed seems uninterested in "+TPQCN+"'s attempts to handle it.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}
