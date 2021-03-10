//For Summon Lion
#include <std.h>

inherit "/std/riding_animal.c";

void create(){
    ::create();
    set_name("a golden lion");
    set_short("lion");
    set_id( ({"lion", "animal", "riding lion", "beast", "cat"}) );
    set_long("The golden lion has a sleek coat and moves with"+
	" easy grace. His coat is glossy and every inch of him "+
	"is pure muscle. His golden eyes stare at you, watching"+
	" you closely. The lion has a golden tawny coat and mane,"+
	" thus earning him his name. You notice sharp teeth "+
	"protruding from his large mouth.");
    set_level(10);
    set_value(0);
    set_race("quadruped");
    set_gender("male");
    set_body_type("quadruped");
    set_size(3);
    set_max_hp(100);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(2);
    set_exp(1);
    set_attack_limbs(({"right forepaw","left forepaw"}));
    set_max_distance(10);
    set_enter_room("rides in");
    set_exit_room("leaves riding a golden lion.");
    set_vehicle_short("lion");
    set_attacks_num(2);
    set_damage(2,6);
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
	tell_room(ETP, "The lion won't allow "+TPQCN+" to mount!", TP);
	return notify_fail("That beast is not yours!\n");
    }

    set_level(lev*2/3);
    set_mlevel("fighter", lev*2/3);
    set_max_hp(temp*2/3);
    set_damage(2,6);
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}

int rangers(string str){
    tell_room(ETP, TPQCN+" just tried to handle this lion, unsuccessfully.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
