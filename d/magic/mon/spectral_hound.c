#include <std.h>
#include <magic.h>
#include <daemons.h>
inherit WEAPONLESS;

object caster;
int power;

void create(){
  ::create();
  set_name("spectral hound");
  set_id(({"hound","spectral hound","faithful hound"}));
  set_short("%^RESET%^%^CYAN%^Spectral hound%^RESET%^");
  set_long("%^RESET%^%^CYAN%^This hound appears to be translucent, but otherwise normal dog. Its eyes are faithfully watching the place. It has fluffy floppy ears and snuggly appearance, but sadly is quite incorporeal.");
  set_hd(35,5);
  set_max_hp(25);
  set_hp(25);
  set_gender("male");
  set_race("dog");
  set_body_type("quadruped");
  set_ac(0);
  set_exp(1);
  set_property("magic",1);
  set_mob_magic_resistance("average");
  set_attacks_num(1);
  set_damage(1,3);
  set_invis();
  set_property("no detect",1);
  set_attack_limbs(({"torso"}));
  set_base_damage_type("slashing");
  set_property("knock unconscious",1);
}

void setup(invoker,clevel)
{
    caster = invoker;
    set_max_hp(clevel*30);
    set_hp(clevel*30);
    set_damage(clevel,2);
    power = clevel;
    call_out("be_doggy",ROUND_LENGTH);
}

void bark()
{
    if(objectp(caster))
        tell_room(caster,"%^CYAN%^Your hound conveys a telepathic bark to you.%^RESET%^");
}

void be_doggy()
{
    if(!objectp(caster))
    {
        if(objectp(query_property("spell")))
        {
            query_property("spell")->dest_effect();
            return;
        }
        remove_call_out("be_doggy");
        TO->remove();
    }
    else
    {
        object * livings;
        livings = all_living(ETO);
        livings -= ({TO});
        livings -= ({caster});
        livings = filter_array(livings, "is_non_immortal",FILTERS_D);
        if(sizeof(livings))
            bark();
        if(present(caster,ETO))
        {
            object * foes,foe;
            foes = caster -> query_attackers();
            foreach(foe in foes)
            {
                if(!objectp(foes))
                    continue;
                tell_oject(foe,"%^RESET%^%^CYAN%^Something bites you!%^RESET%^");
                foe->cause_typed_damage(foe,foe->return_target_lib(),roll_dice(power,2),"negative energy");
                if(objectp(foe))
                    foe->continue_attack();
            }
        }
    }
    call_out("be_doggy",ROUND_LENGTH);
}

int die()
{
    remove_hound();
}

void remove_hound()
{
    if(objectp(caster) &&
       objectp(ETO))
    {
        caster->remove_property("has_faithful_hound");
        tell_object(caster,"%^CYAN%^You concentration releases as your hound fades.%^RESET%^");
    }
    destruct(TO);
}
