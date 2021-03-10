#include <std.h>

inherit WEAPONLESS;

void create(){
    ::create();
    set_property("swims", 1);
    set_name("ixitxachitl");
    set_short("Ixitxachitl");
    set_id( ({"Ixitxachitl", "ixitxachitl", "ixi", "ixit", "Ixi", "Ixit"}) );
    set_long(
      "This creature looks to be like a large manta ray, a thin beast with two long wing like flipper/arms, and with a long barbed tail."
    );
    set_race("ixitxachitl");
    set_gender("male");
    set_body_type("snake");
    add_limb("right fin", "torso", 0, 0, 0);
    add_limb("left fin", "torso", 0, 0, 0);
    set_hd(25, 2);
    set_class("fighter");
    set_mlevel("fighter", 25);
    set_base_damage_type("piercing");
    set_attack_limbs( ({"tail", "mouth"}) );
    set_attacks_num(2);
    set_damage(2,6);
    set_hit_funcs( (["tail":(:TO, "tail_hit":)]) );
    set_hp(150 + roll_dice(10,10));
    set_exp(2500);
    if(!random(4)){
      set_class("mage");
      set_mlevel("mage", 25);
      set_spells( ({"lightning bolt", "fireball", "magic missile", "cone of cold", "hideous laughter"}) );
      set_spell_chance(60);
      set_exp(5000);
    }
    add_money("gold", roll_dice(3,10));
    set_mob_magic_resistance("average");
}

int tail_hit(object targ){
    if(!objectp(targ)) return roll_dice(3,5);
    if(random(3)) return random(8);
    tell_object(targ, "%^BOLD%^%^BLUE%^The Ixitxachitl hits you with the stingers on its tail!  You can feel the poison seeping into your blood!");
    tell_room(ETO, "%^BOLD%^%^BLUE%^The Ixitxachitl hits "+targ->query_cap_name()+" with its barbed tail!", targ);
    targ->do_damage("torso", roll_dice(3,10));
    targ->add_poisoning(50);
    targ->set_paralyzed(5+random(15), "%^RED%^The poison burns painfully in your blood!");
}
