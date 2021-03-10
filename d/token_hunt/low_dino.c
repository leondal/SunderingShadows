#include <std.h>
#include "token_hunt.h"

inherit WEAPONLESS;

void cage(object targ, int num);

void create()
{
    ::create();
    set_id(({"dino","dinosaur","triceratops","Triceratops"}));
    set_name("Triceratops");
    set_short("A huge triceratops");
    set_long("%^RESET%^%^GREEN%^A thick, heavy hide stretches over the large body of "
        "this four legged dinosaur. Its dappled shade a mixture of %^ORANGE%^browns"
        "%^GREEN%^, %^RESET%^grays %^GREEN%^and %^BOLD%^greens%^RESET%^%^GREEN%^. "
        "Thick legs, as wide as tree trunks, propel it along at a steady, lumbering "
        "pace, that causes the fan-shapped, bonny %^RESET%^frill %^GREEN%^of his head "
        "to rock back and forth as his head sways. Two large %^ORANGE%^horns %^GREEN%^"
        "extend high above the head, jutting away from the ridge and over the eyes. "
        "While a third, smaller and thicker %^ORANGE%^horn %^GREEN%^can be seen "
        "jutting back from just above the large blunt nose. A hooked beak finishes "
        "the creature's head, allowing it to easily snap %^ORANGE%^branches %^GREEN%^or"
        "%^RESET%^ bones %^GREEN%^as needed. Though an %^BOLD%^herbivore%^RESET%^%^GREEN%^, "
        "the beast appears to favor his small gnomish master and would likely put up "
        "a fierce fight to protect him.%^RESET%^");

    set_body_type("dragon");
    set_race("triceratops");
    set_gender("male");
    set_size(4);
    set_hd(15,12);
    set_mlevel("fighter",15);
    set_hp(350+random(350));
    set_property("magic resistance",5);
    set_overall_ac(-9);
    set_attacks_num(3);
    set_damage(1,10);
    set_base_damage_type("piercing");
    set_property("full attacks",1);

    remove_limb("right wing");
    remove_limb("left wing");
    add_limb("horns","head",0,0,0);
    add_limb("spiked tail", "tail", 0, 0, 0);

    set_attack_limbs(({"spiked tail",
                       "horns",
                       "right foreclaw",
                       "left foreclaw",
                    }));

    set_funcs(({"trample"}));
    set_func_chance(50);
}

void heart_beat()
{
    object ob;
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    if(!objectp(ob=present("shopkeeper",ETO))) { return 0; }    
    if(member_array(TO,ob->query_protectors()) == -1)
    {
        ob->add_protector(TO);
    }
}
    

void trample()
{
    object *attackers =({});
    int i;

    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }

    attackers = TO->query_attackers();
    if(!sizeof(attackers)) { return; }
    tell_room(ETO,"%^RED%^The triceratops charges in a rage, trying to trample his enemies!");

    for(i=0;i<sizeof(attackers);i++)
    {
        if(!objectp(attackers[i])) { continue; }
        if(roll_dice(4,6) > (int)attackers[i]->query_stats("dexterity"))
        {
            tell_room(ETO,"%^MAGENTA%^The triceratops charges over "+attackers[i]->QCN+"!%^RESET%^",attackers[i]);
            attackers[i]->cause_typed_damage(attackers[i], attackers[i]->return_target_limb(), roll_dice(2, 20), "bludgeoning");
            tell_object(attackers[i],"%^MAGENTA%^The triceratops charges over you!%^RESET%^");
        }
        else
        {
            tell_object(attackers[i],"%^YELLOW%^You manage to avoid the charge!%^RESET%^");
        }
    }
}
