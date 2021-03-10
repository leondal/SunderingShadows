// selune: travel domain, faithful mount. Nienne, 05/07.
#include <std.h>
inherit "/std/riding_animal";

void create(){
    ::create();
    ::create();
    set_name("horse");
    set_short("horse");
    set_id( ({"horse"}) );
    set_long("It's a horse. lawl.");
    set_level(10);
    set_value(0);
    set_race("horse");
    set_body_type("equine");
    set_attack_limbs( ({"right forehoof", "left forehoof"}) );
    set_size(3);
    set_max_hp(100);
    set_hd(10,1);
    set_hp(100);
    set_overall_ac(3);
    set_exp(1);
    set_max_distance(10);
    set_enter_room("rides in on a horse.");
    set_exit_room("leaves riding a horse.");
    set_vehicle_short("A horse");
    set_attacks_num(2);
    set_damage(2,6);
    set_name("gray mare");
    set_short("%^BOLD%^%^BLACK%^A gentle gray mare%^RESET%^");
    set_id( ({"horse","mare","gray mare","gentle mare","gentle gray mare","faithful mount"}) );
    set_long("%^ORANGE%^This mare is covered by a short coat of a pale "
"%^BOLD%^%^BLACK%^gray hue%^RESET%^%^ORANGE%^, with a glossy sheen that makes "
"it seem almost %^RESET%^si%^BOLD%^lve%^RESET%^ry %^ORANGE%^in places. She "
"looks gentle and rather docile, and has a %^RESET%^white star %^ORANGE%^"
"marked above her soft eyes. Her pale %^RESET%^si%^BOLD%^%^BLACK%^l%^RESET%^"
"ver-gr%^BOLD%^%^BLACK%^a%^RESET%^y %^ORANGE%^mane and tail hang loose, and "
"her hooves are carefully tended. A simple bridle and saddle of "
"%^BOLD%^%^BLACK%^jet-black leather %^RESET%^%^ORANGE%^mark her as a trained "
"beast, the latter of which is marked all around the edges with little "
"%^BOLD%^%^WHITE%^gl%^CYAN%^i%^WHITE%^tte%^CYAN%^r%^WHITE%^ing "
"%^RESET%^%^ORANGE%^stars.%^RESET%^");
    set_gender("female");
    set_enter_room("rides in on a gentle mare.");
    set_exit_room("leaves riding a gentle mare.");
    set_vehicle_short("%^BOLD%^%^BLACK%^A gentle gray mare%^RESET%^");
}

int enter(string str){
    int lev, temp;

    lev = TP->query_guild_level("cleric");
    temp = TP->query_max_hp();
    if(query_owner() != this_player()) {
        tell_room(ETP, ""+TPQCN+" seems unable to mount the horse!", TP);
        return notify_fail("The horse won't let you ride!\n");
    }

    set_level(lev*1/3);
    set_mlevel("fighter", lev*1/3);
    set_max_hp(temp*1/3);
    set_damage(2,6);
    set_hp(query_max_hp());
    return ::enter(str);
    return 1;
}

int handle_critter(string str) {
    tell_room(ETP,"The horse seems uninterested in "+TPQCN+"'s attempts to handle it.", TP);
    return notify_fail("You cannot handle this enchanted beast!\n");
}

int give_me_away(string str){
    return notify_fail("Your mount refuses to leave you!\n");
    return 0;
}
int save_me(string file) {return 0;}
int restore_me(string file) { TO->remove(); return 0;}

