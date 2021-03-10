//Coded by the one and only master of monsters...BANE//
#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"skuz","Skuz"}));
    set_name("Skuz");
    set_short("A slimy Skuz");
    set_long(
	"Perhaps the most feared of undead creatures, this monster "+
	"radiates pure negative energy. The thing appears as a slimy, "+
	"filmy coated pool of water. The beast is able to manipulate "+
	"its body into humaniod form making it easier to %^BOLD%^RED%^ "+
	"DESTROY%^RESET%^ those foolish enough to get near it!"
    );
    set_body_type("undead");
    set_race("skuz");
    set_gender("male");
    set_size(2);
    set_alignment(9);
    set_hd(15,40);
    set_hp(160);
    set_exp(15000);
    set_overall_ac(-1);
    set_mob_magic_resistance("average");
    set_property("alignment adjustment",5);
    set_property("swarm",1);
    add_money("gold",random(2500)+1500);
    set("aggressive",19);
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_base_damage_type("slashing");
    set_damage(2,6);
    set_hit_funcs( ([
	"right hand":(:TO,"drain":),
	"left hand":(:TO,"drain":)
    ]) );
}

void drain(object target)
{
    int round_duration = roll_dice(query_level(), 20);
    int power = roll_dice(1, 4);
    tell_object(target, "%^BOLD%^BLUE%^You feel your life force drain away!");
    tell_room(ETO, "%^BOLD%^BLUE%^" + target->query_cap_name() + "'s stumbles back weakly from the touch of the " + TO->query_name() + "!", target);
    "/std/effect/status/negative_level"->apply_effect(target, round_duration, power);
}
