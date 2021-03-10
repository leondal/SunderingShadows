/* Removing this and the dragon from being used by the faithful_mount spell and replacing it with riding_wolf and riding_leopard Circe created.  A player had named his dragon "Emerald dragon" and we realized that especially being a Malar spell it would be better served to have more beastlike mounts.  Per T, dragons should be very rare and very deadly anyway.  *Styx*  11/8/03, last change was 6/16/01. */
#include <std.h>

inherit "/std/riding_animal.c";

void create(){
    ::create();
    set_name("a riding griffon");
    set_short("Griffon");
    set_id( ({"griffon", "riding griffon", "animal", "beast"}) );
    set_long(
      "This beautiful golden griffon stands before you, his wings curled back upon his body.  He opens his beak and screams to the sky, crying for his master."
    );
    set_level(10);
    set_value(0);
    set_race("griffon");
    set_gender("male");
    set_body_type("equine");
    remove_limb("right fore hoof");
    remove_limb("left fore hoof");
    add_limb("beak", "head", 0, 0, 0);
    add_limb("right claw", "torso", 0, 0, 0);
    add_limb("left claw", "torso", 0, 0, 0);
    add_limb("right wing", "torso", 0, 0, 0);
    add_limb("left wing", "torso", 0, 0, 0);
    set_attack_limbs( ({"beak", "right claw", "left claw"}) );
    set_size(3);
    set_max_hp(5000);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
    set_max_distance(10);
    set_enter_room("rides in");
    set_exit_room("leaves riding a griffon.");
    set_vehicle_short("Griffon");
    set_attacks_num(2);
    set_damage(2,6);
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
	tell_room(ETP, "The griffon won't allow "+TPQCN+" to mount!", TP);
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
    tell_room(ETP, TPQCN+" just tried to handle this Griffon, unsuccessfully.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}
