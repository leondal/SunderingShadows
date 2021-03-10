#include <std.h>
#include "../inherits/area_stuff.h"
inherit WEAPONLESS;

object tangled;

void create()
{
    ::create();
    set_name("a monstrous living vine");

    set_id(({"vine", "living vine", "monstrous vine"}));

    set_short("%^RESET%^%^GREEN%^Monstrous living vine%^RESET%^");

    set_long("%^RESET%^%^GREEN%^This vine is massive, it is "+
    "nearly ten feet in length and close to four feet thick. "+
    "It is covered with what vicious looking %^BOLD%^%^BLACK%^barbs"+
    "%^RESET%^%^GREEN%^ that each come to an almost razor sharp "+
    "point. It is knotted and swollen with a thick layer of "+
    "bark that makes it incredibly durable. It has no apparent "+
    "means of life on its own, so whatever has animated it must be "+
    "quite powerful.%^RESET%^");

    set_hd(32,1);

	set_hp(410 + random(176));

    set_max_hp(query_hp());
    set_body_type("vine");
    set_damage(4,6);
    set_attacks_num(3);
    set_attack_limbs(({"vine"}));
    set_base_damage_type("bludgeoning");
    set_gender("male");
    set_race("vine");
    set_new_exp(32, "normal");
    set_alignment(5);
    set_overall_ac(-10);
    set("aggressive", 30);
    set_property("natural poisoner", 1);
    set_property("natural poison", "bloodroot");
    set_property("poison chance", 25);
    set_property("full attacks", 1);
    set_func_chance(25); 
    set_funcs(({"lash_out", "thorn_spray", "entangle"}));
    
    set_stats("strength",17);
    set_stats("intelligence",9);
    set_stats("wisdom",9);
    set_stats("dexterity",10);
    set_stats("charisma",8);
    set_stats("constitution",12);
    
}

void lash_out(object vic) 
{
    string tlim;
    int hits;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;
    hits = 2 + random(3);
	
    tell_object(vic, TO->query_short()+" %^BOLD%^%^GREEN%^lashes out at "+
    "your furiously in a series of attacks!%^RESET%^");
    
    tell_room(ETO, TO->query_short() + " %^BOLD%^%^GREEN%^lashes out "+
    "furiously at "+vic->QCN+"%^BOLD%^%^GREEN%^ in a series of attacks!%^RESET%^", vic);
    
    while(hits--)
    {
        if(vic->reflex_save(34)) 
        {
            tell_object(vic, "%^BOLD%^%^BLACK%^You quickly "+
            "%^BOLD%^%^RED%^dodge%^BOLD%^%^RED%^ one of the "+
            "incoming attacks!%^RESET%^");

            tell_room(ETO, vic->QCN+"%^BOLD%^%^BLACK%^ quickly "+
            "%^BOLD%^%^RED%^dodges%^BOLD%^%^RED%^ one of the "+
            "incoming attacks!%^RESET%^", vic);
            continue;
        }
        else
        {
            tlim = vic->return_target_limb();
            tell_object(vic, TO->query_short()+"%^BOLD%^%^BLACK%^ "+
            "slices %^BOLD%^%^RED%^DEEP%^BOLD%^%^BLACK%^ "+
            "into your "+tlim+" with one of its many barbs!%^RESET%^");
			
            tell_room(ETO, TO->query_short()+"%^BOLD%^%^BLACK%^ "+
            "slices %^BOLD%^%^RED%^DEEP%^BOLD%^%^BLACK%^ "+
            "into "+vic->QCN+"%^BOLD%^%^BlACK%^'s "+tlim+" with "+
            "one of its many barbs!%^RESET%^", vic);
		
            vic->cause_typed_damage(vic,tlim,roll_dice(8,8),"piercing");
            continue;
        }
    }
    return;
}
	
void thorn_spray(object vic)
{
    int dam;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;
		
    tell_object(vic, TO->query_short()+" %^BOLD%^%^RED%^releases a "+
    "spray of %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^A%^BOLD%^%^BLACK%^"+
    "R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^RED%^directly "+
    "at your chest!%^RESET%^");	
	
    tell_room(ETO, TO->query_short()+" %^BOLD%^%^RED%^releases a "+
    "spray of %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^A%^BOLD%^%^BLACK%^"+
    "R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^RED%^directly "+
    "at "+vic->QCN+"%^BOLD%^%^RED%^'s chest!%^RESET%^", vic);	

    dam = roll_dice(8, 12);

    if(vic->reflex_save(34))
    {
        tell_object(vic, "%^BOLD%^%^GREEN%^Miracously you are able "+
        "to move in time and the of %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^GREEN%^"+
        "only graze you!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^GREEN%^ is miracously "+ 
        "able to move out of the way in the time and the %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^GREEN%^"+
        "only graze "+vic->QO+"!%^RESET%^", vic);

        vic->cause_typed_damage(vic, "torso", (dam/2), "piercing");     
        return;
    }
    else
    {		
        tell_object(vic, "%^BOLD%^%^GREEN%^You are unable to move in time "+
        "and the %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^GREEN%^"+
        " imbed deep into your chest!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^GREEN%^ is unable to move "+
        "in time and the %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^%^GREEN%^"+
        "imbed deep into "+vic->QP+" chest!%^RESET%^", ETO);
		
        vic->cause_typed_damage(vic, "torso", dam, "piercing");
        return;
    }
}

void continue_squeeze()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(tangled)) return;
    tell_object(tangled, "%^BOLD%^%^RED%^You struggle desperately "+
    "against the tight grasp of the vine!%^RESET%^");

    tell_room(ETO, tangled->QCN+"%^BOLD%^%^RED%^ struggles "+
    "desperately against the tight grasp of the vine!%^RESET%^", ETO);

    if(tangled->reflex_save(32)) 
    {
        tell_object(tangled, "%^BOLD%^%^WHITE%^Finally you manage to "+
        "break free of the relentless grip!%^RESET%^");

        tangled->set_paralyzed(0);

        tell_room(ETO, tangled->QCN+"%^BOLD%^%^WHITE%^ breaks free of "+
        "the vines relentless grip!%^RESET%^", tangled);
        tangled->remove_property("already_entangled");
        tangled = 0;
        return;
    }
    else
    {
        tell_object(tangled, "%^BOLD%^%^RED%^You %^BOLD%^%^BLACK%^HOWL"+
        "%^BOLD%^%^RED%^ in %^BOLD%^%^YELLOW%^A%^BOLD%^%^GREEN%^G%^BOLD%^"+
        "%^YELLOW%^O%^BOLD%^%^GREEN%^N%^BOLD%^%^YELLOW%^Y%^BOLD%^%^RED%^ "+
        "as the vines vicious %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^"+
        "%^RED%^cut into you!%^RESET%^");

        tell_room(ETO, tangled->QCN+"%^BOLD%^%^RED%^ %^BOLD%^%^BLACK%^HOWLS"+
        "%^BOLD%^%^RED%^ in %^BOLD%^%^YELLOW%^A%^BOLD%^%^GREEN%^G%^BOLD%^"+
        "%^YELLOW%^O%^BOLD%^%^GREEN%^N%^BOLD%^%^YELLOW%^Y%^BOLD%^%^RED%^ "+
        "as the vines vicious %^BOLD%^%^BLACK%^B%^BOLD%^%^GREEN%^"+
        "A%^BOLD%^%^BLACK%^R%^BOLD%^%^GREEN%^B%^BOLD%^%^BLACK%^S %^BOLD%^"+
        "%^RED%^cut into "+tangled->QP+" flesh!%^RESET%^", tangled);

        tangled->cause_typed_damage(tangled, tangled->return_target_limb(), roll_dice(5, 6), "piercing");
        call_out("continue_squeeze", 5);
        return;
    }
}

void entangle(object vic)
{
    string tlim;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(!objectp(vic)) return;
    if(objectp(tangled) || vic->query_property("already_entangled")) 
    {
        if(random(2)) thorn_spray(vic);
        else lash_out(vic);
        return;
    }
	
    tell_object(vic, TO->query_short()+"%^BOLD%^%^RED%^ moves "+
    "with a sudden %^BOLD%^%^BLUE%^BURST%^BOLD%^%^RED%^ of speed, "+
    "trying to entangle you!%^RESET%^");

    tell_room(ETO, TO->query_short()+"%^BOLD%^%^RED%^ moves with "+
    "a sudden %^BOLD%^%^BLUE%^BURST%^BOLD%^%^RED%^ of speed, "+
    "trying to entangle "+vic->QCN+"%^BOLD%^%^RED%^!%^RESET%^", vic);

    if(vic->reflex_save(35)) 
    {
        tell_object(vic, "%^BOLD%^%^BLUE%^You barely manage to move "+
        "from the groping vines grasp and avoid becoming entangled!%^RESET%^");

        tell_room(ETO, vic->QCN+"%^BOLD%^%^BLUE%^ barely manages to "+
        "move from the groping vines grasp and avoids becoming "+
        "entangled!%^RESET%^", vic);
        return;
    }
    else
    {
        tangled = vic;
        tangled->set_property("already_entangled", 1);
        tell_object(vic, "%^BOLD%^%^BLUE%^You are %^BOLD%^%^RED%^UNABLE"+
        "%^BOLD%^%^BLUE%^ to move in time and the vine wraps itself "+
        "around you and begins %^BOLD%^%^RED%^SQUEEZING%^BOLD%^"+
        "%^BLUE%^!%^RESET%^");
		
        tell_room(ETO, vic->QCN+"%^BOLD%^%^BLUE%^ is %^BOLD%^%^RED%^UNABLE"+
        "%^BOLD%^%^BLUE%^ to move in time and the vine wraps itself "+
        "around "+vic->QO+" and begins %^BOLD%^%^RED%^SQUEEZING%^BOLD%^"+
        "%^BLUE%^!%^RESET%^", vic);
		
        vic->set_paralyzed(100, "%^BOLD%^%^BLUE%^You are being squeezed "+
        "by the vine!%^RESET%^");
        call_out("continue_squeeze", 5);
        return;
    }
}
		
void die(object ob)
{
    if(objectp(tangled)) tangled->set_paralyzed(0);
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    ::die(ob);
}