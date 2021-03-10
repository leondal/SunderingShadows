#include <std.h>
inherit WEAPONLESS; 
int xx,y;
void create() {
    :: create();
    set_name("mound");
    set_id(({ "mound","shambling mound","shambler" }));
    set_short("%^RESET%^%^ORANGE%^Shambling mound%^RESET%^");
    set_long(
      "%^RESET%^%^ORANGE%^The shambling mound is dressed in rotting robes "
      "and armour.  It stares through hollow eyes at its surroundings and "
      "seems to carry an aura of power that is stronger than the "
      "average creature.  It is composed entirely of swamp vegetation and "
	"smells horrible.%^RESET%^"
    );
    set_gender("male");
    set_level(14);
    set_weight(175);
    set_attacks_num(2); 
    set_damage(2,4);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"})); 
    set_overall_ac(0);
    set_stats("strength",19);
    set_stats("constitution",18);
    set_stats("dexterity",18);
    set_stats("wisdom",18);
    set_stats("intelligence",17);
    set_stats("charisma",10);
    set_alignment(6);
    set("race","humanoid");
    set_body_type("humanoid");
    set_class("fighter");
    this_object()->add_money("gold",random(500)+100);
    set_guild_level("fighter",14);
    set_hd(14,5);
    set_max_hp(130);
    set_hp(130);
    set_exp(2500);
    set_emotes(4, ({
        "%^RED%^The shambling mound lashes at your face!%^RESET%^",
        "%^RED%^%^BOLD%^The shambling mound claws at your face!%^RESET%^",
        "%^GREEN%^%^BOLD%^You feel sick and dizzy!%^RESET%^"
    }),1);
    set_funcs(({"special"}));
    set_func_chance(25);
}
int special(object vic) {
object me = this_object();
    xx=random(2)+1;
    switch(xx) {
    case 1:
        me->force_me("growl");
        me->add_hp(random(15)+5);
	say("%^GREEN%^Shambling Mound is revitalized by the marsh!%^RESET%^");
        return 1;
    case 2:
        if((int)me->query_hp() < 20) {
            return 1;
        }
        me->force_me("grin");
          tell_room(ETO,
            "%^BOLD%^%^GREEN%^The shambling mound covers "
              +vic->query_cap_name()+" with slime!%^RESET%^"
        ,({TP, vic}) );
        tell_object(vic,
            "%^BOLD%^%^GREEN%^The shambling mound covers you with "
	    "slime!%^RESET%^"
        );
        vic->do_damage(vic->return_target_limb(),random(20)+10);
        vic->set_paralyzed(random(8)+6,"You are weak from the slime!");
        return 1;
    }
}
int agg_fun(object ob) {
    if(TP->query_invis()) return 1; 
    if ((int)TP->query_level() > 200) {
        force_me ("bow "+TP->query_name());
        return 1;
    } else {
        force_me("kill "+TP->query_name());
        force_me("hug "+TP->query_name());
        tell_object(TP,"%^BOLD%^%^GREEN%^The shambling mound envelopes "
             "you!%^RESET%^"
        );
        TP->do_damage("torso",random(15)+2);
       TP->set_paralyzed(random(4)+1,"%^GREEN%^You are enveloped!%^RESET%^");
        return 1;
    }
}
