#include <std.h>
inherit "/std/riding_animal.c";

nosave private int healingStuff;

int is_warhorse() { return 1; }

void create(){
    ::create();
    set_id(({"war horse","horse","warhorse"}));
    set_name("war horse");
    set_short("war horse");
    set_long("This is a powerfully built, well trained war horse.  Obviously this belongs to someone very well trained and it would be dangerous for anyone lesser to try and ride it.");
    set_value(1000);
    set_race("horse");
    set_gender("male");
    set_body_type("equine");
    set_size(3);
    set_level(20);
    set_riding_level(20);
    set_mlevel("fighter",20);
    set_hd(20,10);
    set_max_hp(200);
    set_hp(200);
    set_overall_ac(6);
    set_exp(1);
    set_max_distance(1000);
    set_enter_room("rides in");
    set_exit_room("leaves riding a war horse.");
    set_vehicle_short("War horse");
    set_attack_limbs(({"right forehoof","left forehoof"}));
    set_attacks_num(2);
    set_damage(1,10);
    healingStuff = 1;
    set_stats("strength",18);
}

int restrict_mount_ok(object who)
{
    int lev, temp, hurt, newhp;
    lev = who->query_level();

    set_level(lev);          // this wasn't working for some reason so using mlevel
    set_riding_level(who->query_skill("athletics") - 10);
    set_mlevel("fighter", lev);
    set_hd(lev, 10);
    set_max_hp(20 * lev);
    set_hp(query_max_hp() - hurt);
    set_damage(1, lev / 2);

    if (healingStuff || query_max_hp() < query_hp()) {
        set_hp(query_max_hp());
        healingStuff = 0;
    }

    set_damage(1, 10);
    return 1;
}
