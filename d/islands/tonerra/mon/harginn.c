//harginn.c

#include <std.h>

inherit WEAPONLESS;

void create()
{
    object ob;
    ::create();

    set_name("harginn");
    set_id(({ "harginn", "Harginn", "flame", "horror", "flaming horror" }));
    set_short("Harginn, Flaming horror");
    set_long("This creature has a flaming torso and white flames for legs. You feel the heat radiate from him. He seems corporal but also seems to not be here.  He dances around you flaming and flickering like the flame he lives as.  He extinguishes in front of you only to appear behind you as a bon fire.");
    set_race("harginn");
    set_gender("male");
    set_class("fighter");
    set_hd(10 + random(5), 10);
    set_hp(query_hd() * 25);
    set_exp(850 * query_hd());
    set_new_exp(35, "very high");
    set_max_level(36);
    set_damage(1, 5);
    set_body_type("human");
    set_attack_limbs(({ "right hand", "left hand" }));
    set_hit_funcs((["right hand" : (: TO, "hitem" :), "left hand" : (: TO, "hitem" :)]));
    set_attacks_num(4);
    set_alignment(9);
    set_base_damage_type("bludgeoning");
    set_overall_ac(-5);
    set_funcs(({ "burst" }));
    set_func_chance(102);
    set_property("fire resistant", 1);
    set_property("magic", 1);
    set("aggressive", 25);
    add_money("gold", random(500));
    add_money("platinum", random(75));
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("tendril of flame");
        ob->move(TO);
    }
    set_resistance("fire", 15);
    set_resistance("cold", -15);
}

int hitem(object targ)
{
    if (!objectp(targ)) {
        return 1;
    }
    tell_object(targ, "%^RED%^The hands burn you horribly.");
    return roll_dice(2, 6);
}

void burst(object targ)
{
    int i, j;
    object* inven;

    tell_room(ETO, "%^RED%^The Harginn crumbles into a ball of flame and then quickly expands outward filling the room with flame.");
    inven = all_living(ETO);
    j = sizeof(inven);
    for (i = 0; i < j; i++) {
        if (!objectp(inven[i])) {
            continue;
        }
        if (inven[i]->query_property("fire resistant")) {
            continue;
        }
// added exclude true invis immortals *Styx*  9/20/03
        if (inven[i]->query_true_invis()) {
            continue;
        }

        inven[i]->do_damage("torso", roll_dice(2, 20));
    }
    set_func_chance(10);
}

/* removing this due to longer reboots until I think of a good way to make it wear off in a reasonable length of time and explain it so it doesn't look like a bug when they suddenly can't hit anything.  *Styx*  9/20/03
   int kill_ob(object victim,int which){
   int hold = ::kill_ob(victim,which);
   if(hold)
      victim->add_attack_bonus(-7);
   return hold;
   }
 */

int query_watched()
{
    return 35;
}
