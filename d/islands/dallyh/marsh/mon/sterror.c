#include "/d/islands/dallyh/fways.h"

inherit MONSTER;

void create()
{
    object ob;
    ::create();
    set_id(({"soul terror","terror","soul", "abyssal soul terror", "dallyhallyevil"}));
    set_name("Abyssal Soul Terror");
    set_short("%^BOLD%^%^BLACK%^Abyss%^BOLD%^%^BLUE%^a%^BOLD%^%^BLACK%^l S%^BOLD%^%^BLUE%^ou%^BOLD%^%^BLACK%^l "+
    "T%^BOLD%^%^BLUE%^e%^BOLD%^%^BLACK%^rr%^BOLD%^%^BLUE%^o%^BOLD%^%^BLACK%^r%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^This strange creature is short, perhaps only four feet in height, and has an oblong head with a series of "+
    "%^BOLD%^%^BLACK%^deep black%^BOLD%^%^BLUE%^ eyes in approximately the center of it. The eyes stare ahead continually and are never "+
    "blinking. They reflect a darkness the likes of which is rarely encountered on this plane of existence. The body of the creature is "+
    "strangely %^BOLD%^%^GREEN%^deformed%^BOLD%^%^BLUE%^ but seems to be continually changing and shifting shapes. The appendages are many and "+
    "each is elongated. On its upper body all but two of the appendages appear useless, as if they are leftover remnants of some previous "+
    "form this creature assumed, seeming to serve no purpose any longer. It's lower body narrows and then splits into two appendages that "+
    "seem to serve as legs, with several other bizarrely mutated appendages jutting out from them and hanging loosely, but also seeming to "+
    "serve no purpose. The entire flesh of this creature is a strange %^RESET%^%^CYAN%^pale blue%^BOLD%^%^BLUE%^ but this coloration seems to "+
    "only add to the strangeness of it.%^RESET%^");

    set_body_type("human");
    set_race("demon");
    set_gender("female");
    set_class("thief", 55);
    set_class("fighter", 45);
    set_invis(1);
    add_search_path("/cmds/fighter");
    set_property("magic",2);
    set_property("full attacks",1);
    set_size(2);
    set("aggressive", 100);
    set_hd(58,8);
    set_max_hp(800+random(1000));
    set_hp(query_max_hp());
    set_alignment(9);
    set_overall_ac(-25);
    set_mob_magic_resistance("average");
    add_money("platinum",random(1000) + 2000);
    set_stats("strength", 25);
    set_stats("dexterity", 30);
    set_stats("wisdom", 22);
    set_stats("constitution", 30);
    set_stats("charisma", 15);
    ob = new(MOPATH"barbed");
    if(random(20)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger");
    ob = new(MOPATH"barbed");
    if(random(20)) ob->set_property("monsterweapon", 1);
    ob->move(TO);
    command("wield dagger");
    set_stats("intelligence", 15);
    set_monster_feats(({
      "ambidexterity",
      "whirl",
	  "two weapon fighting",
	  "improved two weapon fighting",
	  "greater two weapon fighting",
	  "two weapon defense",
	  "dodge",
	  "evasion",
	  "mobility",
	  "scramble",
	  "spring attack",
	  "expertise",
	  "knockdown",
	  "unassailable parry",
	  "combat reflexes"
    }));
    set_funcs(({"terrorize"}));
    set_func_chance(40);
    set_property("add kits",20);
    set_moving(1);
    set_speed(55);
    set_new_exp(45, "high");
}

void heart_beat()
{
    ::heart_beat();
    if(!objectp(TO)) return;
    DYN_UP_D->dynamic_update(TO);
    return;
}

void terrorize()
{
    object *vars;
    int i, mod;
    string me;
    me = TO->query_short();
    vars = all_living(ETO);
    if(!intp(mod = TO->query("damage mod")) || mod < 1) mod = 1;
    for(i=0;i<sizeof(vars);i++)
    {
        if(vars[i] == TO || vars[i]->id("dallyhallyevil") || vars[i]->query_true_invis()) continue;
        tell_object(vars[i],"%^BOLD%^%^CYAN%^The "+me+"%^BOLD%^%^CYAN%^ concentrates deeply on you.....%^RESET%^");
        if(!vars[i]->fort_save(45))
        {
            tell_object(vars[i],"%^BOLD%^%^CYAN%^The "+me+"%^BOLD%^%^CYAN%^ %^BOLD%^%^BLACK%^R"+
            "%^RESET%^%^RED%^I%^BOLD%^%^BLACK%^"+
            "PS%^BOLD%^%^CYAN%^ and %^RESET%^%^RED%^T%^BOLD%^%^BLACK%^EA%^RESET%^%^RED%^RS "+
            "%^BOLD%^%^CYAN%^at your "+
            "%^BOLD%^%^WHITE%^SOUL%^BOLD%^%^CYAN%^!%^RESET%^");

            vars[i]->do_damage(vars[i]->return_target_limb(),(roll_dice(20,6)*mod));
            vars[i]->set_paralyzed(12,"%^BOLD%^%^RED%^You are reeling from the damage to your soul!");
        }
        else
        {
            tell_object(vars[i],"%^BOLD%^%^CYAN%^The "+me+"%^BOLD%^%^CYAN%^ %^BOLD%^%^BLACK%^R"+
            "%^RESET%^%^RED%^I%^BOLD%^%^BLACK%^"+
            "PS%^BOLD%^%^CYAN%^ and %^RESET%^%^RED%^T%^BOLD%^%^BLACK%^EA%^RESET%^%^RED%^RS "+
            "%^BOLD%^%^CYAN%^ at your mind!%^RESET%^");
            vars[i]->do_damage(vars[i]->return_target_limb(),(roll_dice(10,6)*mod));
        }
        continue;
    }
    return;
}
