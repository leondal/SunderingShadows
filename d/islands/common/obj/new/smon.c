//added variable props based on player level and set as minion for perfect caster
//removed summoned monster id so that enter/exit messages process
//moved protect code from tasword.c and added player following
// Yves - 8/9/19

#include <std.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_name("A shadowy creature");
    set_property("MIN", "$N forms in the room.");
    set_property("MOUT", "$N breaks apart and disappears as it heads $D.");
    set_id(({"shadow","shadowy creature","creature","smon"}));
    set_short("%^BOLD%^%^BLACK%^A shadowy creature%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^It is difficult to discern exactly what this creature is as it constantly shifts and changes form, moving in and out of the darkness with a swift ease that is unlike anything else known to these lands.  Dark eyes %^MAGENTA%^glow %^BLACK%^from within the depths of the shadows that form this being, and while it takes on a slightly humanoid form, there is no mistaking the elongated claws that twist their way out of the darkness.");
    set_race("shadow");
    set_gender("male");
    set_body_type("human");
    set_exp(1);
    set_size(2);
    set_property("magic",1);
    set_property("magic",1);
    set_attacks_num(1);
    add_limb("left claws","left hand",0,0,0);
    add_limb(" right claws","right hand",0,0,0);
    set_attack_limbs(({"right claws", "left claws"}));
    set_base_damage_type("slashing");
}

void setup_shadow(object player)
{
    int num;

    if(!objectp(player)) return;
    if(!objectp(TO)) return;

    num = (int)player->query_base_character_level();

    add_id(""+(string)player->query_name()+" smon");
    set_level(num/2);
    set_hd(num/2,6);
    set_max_hp(roll_dice(2,num/2) + num);
    set_hp(query_max_hp());
    set_overall_ac(10-num);
    set_damage(1,(num/10));
    set_property("minion", player);
    player->add_protector(TO);
    player->add_follower(TO);

    return;
}
