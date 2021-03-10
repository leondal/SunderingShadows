#include <std.h>
/* Removing this and the griffon from being used by the faithful_mount spell and replacing it with riding_wolf and riding_leopard Circe created.  A player had named his dragon "Emerald dragon" and we realized that especially being a Malar spell it would be better served to have more beastlike mounts.  Per T, dragons should be very rare and very deadly anyway.  *Styx*  11/8/03, last change was 10/30/00. */

inherit "/std/riding_animal.c";

void create(){
    ::create();
    set_name("a riding dragon");
    set_short("Dragon");
    set_id( ({"dragon", "animal", "riding dragon", "beast"}) );
    set_long(
   "This dragon is perfect in every way, except for the fact that it is quite small for a dragon.  As it looks at you lazily, you can see the saddle and stirrups on its back."
    );
    set_level(10);
    set_value(0);
    set_race("dragon");
    set_gender("male");
    set_body_type("dragon");
    set_size(3);
    set_max_hp(5000);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
   set_attack_limbs(({"right claw","left claw"}));
    set_max_distance(10);
    set_enter_room("rides in");
    set_exit_room("leaves riding a dragon.");
    set_vehicle_short("Dragon");
    set_attacks_num(2);
    set_damage(2,6);
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
	tell_room(ETP, "The Wyvern won't allow "+TPQCN+" to mount!", TP);
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
    tell_room(ETP, TPQCN+" just tried to handle this Dragon, unsuccessfully.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
