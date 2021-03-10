#include <std.h>
#include "../area_stuff.h"

inherit MONSTER;

int lev, heads;
string head_string, *possible_spells;

void create() 
{
    string *limbs;
    int x;
    ::create();
	set_race("hydra");
    set_name("desert hydra");
    set_id(({"hydra", "desert hydra", "eldebarocreature"}));    
    lev = 32 + random(9);
    possible_spells = ({"/cmds/spells/f/_fireball", "/cmds/spells/l/_lightning_bolt", "/cmds/spells/c/_cone_of_cold"});
    if(lev >= 35) possible_spells += ({"/cmds/spells/m/_meteor_swarm"});
    if(lev >= 36) possible_spells += ({"/cmds/spells/p/_prismatic_spray"});
    if(lev >= 39) possible_spells += ({"/cmds/spells/c/_chain_lightning"});
    
    heads = 4 + random(5);
    head_string = consolidate_number(heads);
    
    set_short("%^RESET%^%^ORANGE%^"+capitalize(head_string)+" headed d%^BOLD%^e%^RESET%^%^ORANGE%^s%^BOLD%^e%^RESET%^"+
    "%^ORANGE%^rt hydr%^BOLD%^a%^RESET%^%^ORANGE%^");
    
    set_long("%^RESET%^%^ORANGE%^This strange dragon-like creature is covered with %^BOLD%^%^CYAN%^"+
    "symbols%^RESET%^%^ORANGE%^, all of which look ancient and make no sense to you. The creature is "+
    "large, standing nearly twenty feet in the air. It has no wings, at least not anymore, it has spots on "+
    "either side of its large torso where it appears that wings were once at but bones portrude grotesquely "+
    "in their steed. Its tail also appears to have been 'clipped' for no better word, as if something literally "+
    "cut it off at its base. However, it has "+head_string+" heads which all look quite angry. Each one is smooth and bald "+
    "with a larger %^BOLD%^%^CYAN%^symbol%^RESET%^%^ORANGE%^ etched in almost the center of the forehead. Each head has "+
    "%^RESET%^%^GREEN%^em%^BOLD%^e%^RESET%^%^GREEN%^rald%^RESET%^%^ORANGE%^ colored eyes which portray an extreme "+
    "intellect.%^RESET%^");
    set_nogo(({DOCKROOM}));
    set_hd(lev, 50);
    set_body_type("dragon");
    set_size(4);
    set_hp(lev * 38);
    set_new_exp(lev, "high");
    
    set_stats("strength",22);
    set_stats("intelligence",25);
    set_stats("wisdom",25);
    set_stats("charisma",9);
    set_stats("constitution",20);
    set_stats("dexterity",12);
    set_alignment(9);
    set("aggressive",65);
    set_property("full attacks",1); 
    set_func_chance(75);
    set_funcs(({"spell_destroy"}));
    set_monster_feats(({"reflection"}));
    
    set_overall_ac(-25);
    
    for(x = 0;x < heads;x++) 
    {
        add_limb("head "+(x+1), "torso", 0, 0, 0);
        if(sizeof(limbs) < 1) 
        { 
            limbs = ({"head "+(x+1)});
            continue;
        }
        limbs += ({"head "+(x+1)});
    }
    set_attacks_num(heads);
    set_attack_limbs(limbs);
    set_damage(10,4);
}

void spell_destroy(object vic)
{
    string me, mySpell;
    int x;
    object *vics, targ;
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    vics = TO->query_attackers();
    if(!sizeof(vics)) return;
    me = TO->query_short();
    for(x = 0; x < heads;x++)
    {
        targ = vics[random(sizeof(vics))];
        if(!objectp(targ)) continue;
        
        tell_object(targ, "%^BOLD%^%^CYAN%^One of "+me+"%^BOLD%^%^CYAN%^'s heads begins chanting loudly "+
        "while focusing on you!%^RESET%^");
        
        tell_room(ETO, "%^BOLD%^%^CYAN%^One of "+me+"%^BOLD%^%^CYAN%^'s heads begins chanting loudly while "+
        "focusing on "+targ->QCN+"%^BOLD%^%^CYAN%^!!%^RESET%^", targ);
        
        if(random(2)) 
        {
            tell_room(ETO, "%^BOLD%^%^CYAN%^The chanting suddenly stops as the head simply snarls before "+
            "finishing!%^RESET%^");
            continue;
        }
        mySpell = possible_spells[random(sizeof(possible_spells))];
        if(!file_exists(mySpell) && !file_exists(mySpell+".c")) continue;
        else new(mySpell)->use_spell(TO, targ, 10 + random(lev-10), 100, "mage");
        continue;
    }
    return;
}

void heart_beat()
{
    object cor;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(objectp(cor = present("corpse", ETO)))
    {
        if(living(cor)) return;
        new("/cmds/spells/a/_animate_dead")->use_spell(TO, "", 100, 100, "cleric");
        return;
    }
}

void init()
{
    if(!objectp(TO)) { return; }
    if(!objectp(TP)) { return; }
    
    ::init();
    if(TP->query_true_invis()) return;
    if(!userp(TP)) return;
    if(TP->query_invis())
    {
        tell_object(TP, TO->query_short()+" sees through your invisibility!");
    }
    command("kill "+TPQN); 
}
