// Ball Lightning
#include <spell.h>

inherit SPELL;

string element;


void create()
{
    ::create();
    set_author("cythera");
    set_spell_name("ball lightning");
    set_spell_level(([ "mage" : 5, "druid":4, "magus" : 4 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS ball lightning on TARGET");
    set_description("This spell allows for a mage to conjure forth at least three balls of lightning, which they can then "
        "hurl at a target. As the mage's power grows, she will find it easier to summon a greater number of lightning balls, "
        "increasing the damage potential of the spell. A versatile arcanist can manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([ "mage" : ([ "will o wisp essence" :1, "disc of bronze" :1, ]), ]));
}


string query_cast_string()
{
    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":
        tell_object(caster,"%^RESET%^%^GREEN%^As you chant rapidly, %^CYAN%^dr%^GREEN%^o%^CYAN%^p%^GREEN%^l%^CYAN%^ets %^GREEN%^of %^BOLD%^%^GREEN%^a%^YELLOW%^c%^GREEN%^id %^RESET%^%^GREEN%^begin to form in your hand.%^RESET%^");
        tell_room(place,"%^RESET%^%^GREEN%^"+caster->QCN+" chants rapidly, %^CYAN%^dr%^GREEN%^o%^CYAN%^p%^GREEN%^l%^CYAN%^ets %^GREEN%^of %^BOLD%^%^GREEN%^a%^YELLOW%^c%^GREEN%^id %^RESET%^%^GREEN%^beginning to form in "+caster->QP+" hand.",caster);
        set_immunities(({"acid"}));
        break;
    case "cold":
        tell_object(caster,"%^BOLD%^%^CYAN%^As you chant rapidly, a rime of frost forms across your fingers.%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" chants rapidly, and a rime of frost forms across "+caster->QP+" fingers.%^RESET%^",caster);
        set_immunities(({"cold"}));
        break;
    case "fire":
        tell_object(caster,"%^BOLD%^%^RED%^As you chant rapidly, your hands start to radiate with heat.%^RESET%^");
        tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+" chants rapidly, "+caster->QP+" hands start to radiate with heat.%^RESET%^",caster);
        set_immunities(({"fire"}));
        break;
    case "sonic":
        tell_object(caster,"%^CYAN%^You begin a %^BOLD%^m%^GREEN%^e%^RESET%^%^GREEN%^l%^BOLD%^%^MAGENTA%^o%^GREEN%^d%^CYAN%^i%^RESET%^%^GREEN%^c %^CYAN%^chant.%^RESET%^%^RESET%^");
        tell_room(place,"%^CYAN%^"+caster->QCN+" begins a %^BOLD%^m%^GREEN%^e%^RESET%^%^GREEN%^l%^BOLD%^%^MAGENTA%^o%^GREEN%^d%^CYAN%^i%^RESET%^%^GREEN%^c %^CYAN%^chant.%^RESET%^",caster);
        set_immunities(({"sonic"}));
        break;
    default:
        tell_object(caster,"%^BOLD%^%^CYAN%^As you chant rapidly, sparks of lightning begin to gather in your hand.%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^"+caster->QCN+" chants rapidly, gathering sparks of lightning into "+caster->QP+" hand.%^RESET%^",caster);
        set_immunities(({"electricity"}));
        break;
    }
    return "display";
}


void spell_effect(int prof)
{
    int num, numdarts;
    string hardness;

    if(!objectp(caster))
    {
        dest_effect();
        return;
    }

    spell_successful();

    if (interactive(caster))
    {
        switch(element)
        {
        case "acid":
            tell_object(caster,"%^RESET%^%^GREEN%^The %^CYAN%^dr%^GREEN%^o%^CYAN%^p%^GREEN%^l%^CYAN%^ets %^GREEN%^begin to form into spheres.%^RESET%^");
            tell_room(place,"%^RESET%^%^GREEN%^The %^CYAN%^dr%^GREEN%^o%^CYAN%^p%^GREEN%^l%^CYAN%^ets %^GREEN%^in "+caster->QCN+"'s hands form into spheres.%^RESET%^",caster);
            break;
        case "cold":
            tell_object(caster,"%^BOLD%^%^CYAN%^The rime crackles, chilling the air above your palms into balls of frost.%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^The rime crackles, chilling the air above "+caster->QCN+"'s palms into balls of frost.%^RESET%^",caster);
            break;
        case "fire":
            tell_object(caster,"%^BOLD%^%^CYAN%^The heat from your hands ignites the air, forming spheres of flame above your palms.%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^The heat from "+caster->QCN+"'s hands ignites the air, forming spheres of flame above "+caster->QP+" palms.%^RESET%^",caster);
            break;
        case "sonic":
            tell_object(caster,"%^BOLD%^%^WHITE%^W%^CYAN%^i%^WHITE%^sps %^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^r%^CYAN%^e%^BLACK%^s%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^a%^WHITE%^n%^BOLD%^%^BLACK%^t e%^WHITE%^n%^RESET%^e%^BOLD%^r%^RESET%^%^CYAN%^g%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^dance across your palm.%^RESET%^");
            tell_room(place,"%^BOLD%^%^WHITE%^W%^CYAN%^i%^WHITE%^sps %^RESET%^%^CYAN%^of %^BOLD%^%^BLACK%^r%^CYAN%^e%^BLACK%^s%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^n%^RESET%^%^CYAN%^a%^WHITE%^n%^BOLD%^%^BLACK%^t e%^WHITE%^n%^RESET%^e%^BOLD%^r%^RESET%^%^CYAN%^g%^BOLD%^%^BLACK%^y %^RESET%^%^CYAN%^dance across "+caster->QCN+"'s palm.%^RESET%^",caster);
            break;
        default:
            tell_object(caster,"%^BOLD%^%^CYAN%^The lightning begins to form into balls.%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^The sparks of lighting in "+caster->QCN+"'s hands form into balls.%^RESET%^",caster);
            break;
        }
    }

    if(clevel) { numdarts = (clevel+1) / 5; }
    else       { numdarts = (caster->query_guild_level("mage") + 1) / 5; }

    switch (1 + sdamage / numdarts)
    {
    case 2:  hardness = "stinging"; break;
    case 3:  hardness = "jolting";   break;
    case 4:  hardness = "shocking"; break;
    default: hardness = "blasting"; break;
    }

    if(numdarts > 1)
    {
        switch(element)
        {
        case "acid":
            tell_object(caster,"%^BOLD%^%^GREEN%^"+numdarts+" spheres of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from your hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng their deadly contents onto "+target->QCN+"!%^RESET%^");
            tell_object(target,"%^BOLD%^%^GREEN%^"+numdarts+" spheres of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from "+caster->QCN+"'s hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng their deadly contents onto you!%^RESET%^");
            tell_room(place,"%^BOLD%^%^GREEN%^"+numdarts+" spheres of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from "+caster->QCN+"'s hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng their deadly contents onto "+target->QCN+"!%^RESET%^",({caster, target}) );
            break;
        case "cold":
            tell_object(caster,"%^BOLD%^%^WHITE%^"+numdarts+" balls of frost fly from your hand, striking "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^"+numdarts+" balls of frost fly from "+caster->QCN+"'s hand, striking you!");
            tell_room(place,"%^BOLD%^%^WHITE%^"+numdarts+" balls of frost fly from "+caster->QCN+"'s hand, striking "+target->QCN+"!",({caster, target}) );
            break;
        case "fire":
            tell_object(caster,"%^BOLD%^%^WHITE%^"+numdarts+" spheres of flame fly from your hand, immolating "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^"+numdarts+" spheres of flame fly from "+caster->QCN+"'s hand, immolating you!");
            tell_room(place,"%^BOLD%^%^WHITE%^"+numdarts+" spheres of flame fly from "+caster->QCN+"'s hand, immolating "+target->QCN+"!",({caster, target}) );
            break;
        case "sonic":
            tell_object(caster,"%^CYAN%^"+numdarts+" %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^balls of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^fly from your hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^"+target->QCN+"!%^RESET%^");
            tell_object(target,"%^CYAN%^"+numdarts+" %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^balls of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^fly from "+caster->QCN+"'s hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^you!%^RESET%^");
            tell_room(place,"%^CYAN%^"+numdarts+" %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^balls of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^fly from "+caster->QCN+"'s hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^"+target->QCN+"!%^RESET%^",({caster, target}) );
            break;
        default:
            tell_object(caster,"%^BOLD%^%^WHITE%^"+numdarts+" balls of lighting fly from your hand, "+hardness+" "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^"+numdarts+" balls of lighting fly from "+caster->QCN+"'s hand, "+hardness+" you!");
            tell_room(place,"%^BOLD%^%^WHITE%^"+numdarts+" balls of lighting fly from "+caster->QCN+"'s hand, "+hardness+" "+target->QCN+"!",({caster, target}) );
            break;
        }
    }
    else
    {
        switch(element)
        {
        case "acid":
            tell_object(caster,"%^BOLD%^%^GREEN%^A sphere of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from your hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng its deadly contents onto "+target->QCN+"!%^RESET%^");
            tell_object(target,"%^BOLD%^%^GREEN%^A sphere of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from "+caster->QCN+"'s hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng its deadly contents onto you!%^RESET%^");
            tell_room(place,"%^BOLD%^%^GREEN%^A sphere of %^RESET%^%^RED%^corrosive %^BOLD%^%^GREEN%^ac%^YELLOW%^i%^GREEN%^d speed forward from "+caster->QCN+"'s hand, s%^RESET%^%^GREEN%^p%^BOLD%^%^GREEN%^l%^CYAN%^a%^GREEN%^sh%^YELLOW%^i%^GREEN%^ng its deadly contents onto "+target->QCN+"!%^RESET%^",({caster, target}) );
            break;
        case "cold":
            tell_object(caster,"%^BOLD%^%^WHITE%^A ball of frost flies from your hand, striking "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^A ball of frost flies from "+caster->QCN+"'s hand, striking you!");
            tell_room(place,"%^BOLD%^%^WHITE%^A ball of frost flies from "+caster->QCN+"'s hand, striking "+target->QCN+"!",({caster, target}) );
            break;
        case "fire":
            tell_object(caster,"%^BOLD%^%^WHITE%^A sphere of flame flies from your hand, immolating "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^A sphere of flame flies from "+caster->QCN+"'s hand, immolating you!");
            tell_room(place,"%^BOLD%^%^WHITE%^A sphere of flame flies from "+caster->QCN+"'s hand, immolating "+target->QCN+"!",({caster, target}) );
            break;
        case "sonic":
            tell_object(caster,"%^CYAN%^A %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^ball of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^flies from your hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^"+target->QCN+"!%^RESET%^");
            tell_object(target,"%^CYAN%^A %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^ball of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^flies from "+caster->QCN+"'s hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^you!%^RESET%^");
            tell_room(place,"%^CYAN%^A %^WHITE%^w%^BOLD%^h%^BLACK%^i%^RESET%^r%^BOLD%^r%^RESET%^i%^BOLD%^%^BLACK%^n%^RESET%^g %^CYAN%^ball of %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^o%^CYAN%^u%^BOLD%^n%^GREEN%^d %^RESET%^%^CYAN%^flies from "+caster->QCN+"'s hand, %^BOLD%^%^WHITE%^battering %^RESET%^%^CYAN%^"+target->QCN+"!%^RESET%^",({caster, target}) );
            break;
        default:
            tell_object(caster,"%^BOLD%^%^WHITE%^A ball of lighting flies from your hand, "+hardness+" "+target->QCN+"!");
            tell_object(target,"%^BOLD%^%^WHITE%^A ball of lighting flies from "+caster->QCN+"'s hand, "+hardness+" you!");
            tell_room(place,"%^BOLD%^%^WHITE%^A ball of lighting flies from "+caster->QCN+"'s hand, "+hardness+" "+target->QCN+"!",({caster, target}) );
            break;
        }
    }

    damage_targ(target, target->return_target_limb(), sdamage, element);
    dest_effect();
    return;
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
