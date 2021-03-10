#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int x;

void create() 
{
    ::create();
    set_name("fire imp");
    set_id( ({"imp", "fire imp", "saidedekufiremon"}) );
    set_gender("neuter");
    set_race("imp");
    set_short("%^RED%^F%^YELLOW%^i%^RESET%^%^RED%^r%^YELLOW%^e "+
    "%^YELLOW%^i%^RESET%^%^RED%^mp%^RESET%^");

    set_long("%^RED%^This small creature is composed a "+
    "%^BOLD%^%^BLACK%^darkened %^RESET%^%^RED%^almost sooty "+
    "%^BOLD%^%^BLACK%^black%^RESET%^%^RED%^ flesh.  Apart "+
    "from the odd color is the texture of its skin, which "+
    "appears to be almost like a rough leather hide.  "+
    "Its small body is gnarled and bent, its limbs "+
    "%^RESET%^bony%^RED%^ and its back hunched painfully, "+
    "with an almost completely round head.  Grotesque and equally "+
    "useless %^BOLD%^%^BLACK%^black wings%^RESET%^%^RED%^ sprout "+
    "out from its hunched back and hang lazily.  Inset into its "+
    "head are two p%^YELLOW%^u%^RESET%^%^RED%^ls%^YELLOW%^i"+
    "%^RESET%^%^RED%^ng %^RESET%^%^BLUE%^blue%^RED%^ orbs.  "+
    "A %^BOLD%^%^BLACK%^pentagram%^RESET%^%^RED%^ with a "+
    "large %^RESET%^skull%^RED%^ in the center has been "+
    "magically grafted into its torso.  In each small hand "+
    "it carries a dagger made of raging "+
    "fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RED%^s.%^RESET%^");
   
    set_body_type("human");
    set_size(1);
    set_alignment(9);
    add_money("gold", 150 + random(200));
    set_stats("strength",17);
    set_stats("intelligence",17);
    set_stats("constitution",12);
    set_stats("dexterity",10);
    set_stats("wisdom",15);
    set_stats("charisma",8);
    x = 22;
    set_class("thief");
    set_guild_level("thief",x);
    set_mlevel("thief", x);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_hp(235 + random(31));
    //set_exp(5000);
    set_new_exp(25, "normal");
    set_funcs(({"flames"}));
    set_func_chance(25);
    set_max_level(25);
    set("aggressive","kill_things");
    switch(random(2)) 
    {
        case 0:
            command("speech growl");
            break;
        case 1:
            command("speech scream loudly");
            break;
    }
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    new(DEKU_WEP"fire_dagger")->move(TO);
    command("wield dagger");
    set_speed(40 + random(41));
    set_overall_ac(-3);
    set_nogo(({FTUN_ROOMS"kinordas_chamber", FTUN_ROOMS"war_mongrels_tunnel10"}));
}

void flames(object targ) 
{
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    switch(random(5)) 
    {
        case 0..3:
            new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ,x,x,"mage");
            break;
        case 4:
            new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ,x,x,"mage");
            break;
    }
}
        

void kill_things() 
{
    if(!objectp(TO)) return;
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    if(TP->query_invis()) return;
    command("say NO ONE SHOULD BE HERE!!!");
    //TO->add_attack_bonus(3);
    if(!random(6))
    {
        if(!TP->query_property("fire_imp_stabbed") || to_int(TP->query_property("fire_imp_stabbed")) > (time() + 20))
        {
            command("stab "+TPQN);
            TP->set_property("fire_imp_stabbed", time());
        }
    }
    //TO->add_attack_bonus(-3);
    command("kill "+TPQN);
    return 1;           
}            
            
void die(object ob) 
{
    int x;
    object dag;
    if(ob != TO) return ::die(ob);
    x = 2;
    while(x) 
    {
        if(random(8)) 
        {
            if(objectp(dag = present("fire dagger",TO)))
            {
                tell_room(ETO,"%^RED%^The fire from the imps dagger "+
                "burns out and it ceases its humming.%^RESET%^");
                dag->remove();
                new("/d/common/obj/weapon/dagger")->move(TO);
            }
        }
        x--;
    }
    return ::die(ob);
}

