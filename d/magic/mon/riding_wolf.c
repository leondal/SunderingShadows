//wolf.c - adapted from /d/magic/obj/griffon.c.  Used for faithful_mount rather than dragon or griffon.  Circe 11/8/03
#include <std.h>

inherit "/std/riding_animal.c";

void create(){
    ::create();
    set_name("a riding wolf");
    set_short("wolf");
    set_id( ({"wolf", "riding wolf", "animal", "beast"}) );
    set_long(
      "This enormous wolf is much larger than his common kin.  He stands well "+
      "above a normal human's waist and is roughly the size of a horse.  His "+
      "deep gray fur is flecked with lighter spots which seem to shift with the "+
      "light, offering him concealment in the shadows.  His claws are stained with "+
      "blood, and his feral eyes seem to take in everything.  Anyone but his "+
      "master would be a fool to come too close."
    );
    set_level(10);
    set_value(0);
    set_race("wolf");
    set_gender("male");
    set_body_type("quadruped");
    set_attack_limbs( ({"right forepaw", "left forepaw"}) );
    set_size(3);
    set_max_hp(100);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
    set_max_distance(10);
    set_enter_room("rides in");
    set_exit_room("leaves riding a wolf.");
    set_vehicle_short("wolf");
    set_attacks_num(2);
    set_damage(2,6);
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
	tell_room(ETP, "The wolf won't allow "+TPQCN+" to mount!", TP);
	return notify_fail("That beast is not yours!\n");
    }

    set_level(lev*1/3);
    set_mlevel("fighter", lev*1/3);
    set_max_hp(temp*1/3);
    set_damage(2,6);
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}

int rangers(string str){
    tell_room(ETP, TPQCN+" just tried to handle this wolf, unsuccessfully.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}
