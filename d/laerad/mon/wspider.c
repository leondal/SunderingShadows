//Coded by the one and only master of monsters...BANE//
#include <std.h>
inherit WEAPONLESS;
void create()
{
    object ob;
    ::create();
    set_id(({ "spider", "whisper", "Whisper Spider", "forestmon" }));
    set_name("Whisper Spider");
    set_short("%^RESET%^A %^BLUE%^Whisper%^WHITE%^ Spider");
    set_long(
        "This Spider has a large plump abdomen, multiple eyes, and four "
        "pairs of segmented legs. Its body is covered with short, black "
        "bristles. Two gray stripes run the length of its back. Its eyes "
        "are bright red. The creature moves incredibly fast for a 15 foot "
        "long spider."
        );
    set_body_type("arachnid");
    set_race("spider");
    set_gender("male");
    set_size(3);
    set_alignment(5);
    set_hd(8, 16);
    set_hp(80);
    set_exp(1500);
    set_overall_ac(3);
    set("aggressive", 19);
    set_attack_limbs(({ "head" }));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(2, 6);
    set_hit_funcs((["head" : (: TO, "poison" :)]));
    set_funcs(({ "web" }));
    set_func_chance(20);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case
    if (!random(2)) {
        ob = new("/d/common/obj/brewing/herb_special_inherit");
        ob->set_herb_name("spiderweb");
        ob->move(TO);
    }
}
void poison(object targ)
{
    if (!"/daemon/saving_throw_d.c"->fort_save(targ, -(TO->query_level()))) {
        tell_object(targ, "%^BOLD%^RED%^The Spider's poison binds you tight!");
        tell_room(ETO, "%^BOLD%^RED%^The Spider sinks its jaws into " + targ->query_cap_name() + " binding " + targ->query_objective() + " tight!", targ);
        targ->set_paralyzed(8 * roll_dice(1, 4), "The spider holds you still.");
        return 1;
    }
    tell_object(targ, "%^BOLD%^RED%^The Spider's poison stiffens you a bit!");
    tell_room(ETO, "%^BOLD%^RED%^The Spider sinks its jaws into " + targ->query_cap_name() + " shaking " + targ->query_objective() + " up a bit!", targ);
    return 1;
}

void web(object targ)
{
    tell_object(targ, "%^BOLD%^BLUE%^The Spider fires a strand of web at you!");
    tell_room(ETO, "%^BOLD%^BLUE%^The Spider fires a strand of web at " + targ->query_cap_name() + "!", targ);
    if (!"/daemon/saving_throw_d.c"->reflex_save(targ, -(TO->query_level()))) {
        tell_object(targ, "\n%^BOLD%^BLUE%^You get caught in the Spider's web!");
        tell_room(ETO, "\n%^BOLD%^BLUE%^" + targ->query_cap_name() + " gets caught in the Spider's web!", targ);
        targ->set_tripped(roll_dice(1, 4));
        return 1;
    }
    tell_object(targ, "\n%^BOLD%^BLUE%^The strand of web flies past you!");
    tell_room(ETO, "\n%^BOLD%^BLUE%^The strand of web flies past " + targ->query_cap_name() + "!", targ);
    return 1;
}
