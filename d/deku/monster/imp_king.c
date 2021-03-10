#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int x;

void create() 
{
    int y, i;
    ::create();
    set_name("imp king");
    set_id( ({"imp", "fire imp", "fire imp king","king",
    "daliigwin"}) );
    set_gender("neuter");
    set_race("imp");
    set_short("%^RED%^Daliigwin, %^YELLOW%^I%^RESET%^%^RED%^mp "+
    "K%^YELLOW%^i%^RESET%^%^RED%^ng%^RESET%^");
    
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
    "%^RESET%^%^RED%^ng %^RESET%^%^BLUE%^blue%^RED%^ orbs.  A "+
    "crown of fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^"+
    "%^RED%^s rests lazily atop its head.  "+
    "A %^BOLD%^%^BLACK%^pentagram%^RESET%^%^RED%^ with a "+
    "large %^RESET%^skull%^RED%^ in the center has been "+
    "magically grafted into its torso.  In each small hand "+
    "it carries a dagger made of raging "+
    "fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RED%^s.  Each "+
    "dagger is held by a glove made of fire.  A belt of "+
    "fl%^YELLOW%^a%^RESET%^%^RED%^m%^YELLOW%^e%^RESET%^%^RED%^"+
    "s is wrapped tightly around its waist.%^RESET%^");
   
    set_body_type("human");
    set_size(1);
    set_alignment(9);
    add_money("gold", 1500 + random(2800));
    x = 26;
    set_hd(x,1);
    set_stats("strength",19);
    set_stats("intelligence",17);
    set_stats("constitution",12);
    set_stats("dexterity",10);
    set_stats("wisdom",15);
    set_stats("charisma",8);
    set_class("mage");    
    set_mlevel("mage", x+1);
    set_class("thief");
    set_mlevel("thief",x+2);
    set_guild_level("mage",x+1);
    set_guild_level("thief",x+2);
    set_property("full attacks",1);
    set_mob_magic_resistance("average");
    set_spells(({"burning hands","fireball",
    "scorcher","wall of fire","magic missile","lower resistance"}));
    set_spell_chance(40);
    set_hp(400 + random(51));
    //set_exp(12000);
	set_new_exp(25, "very high");
    set_funcs(({"flames"}));
    set_func_chance(25);
    set_max_level(35);
    set("aggressive","kill_things");
    switch(random(2)) {
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
    set_overall_ac(-7);
    new(DEKU_ARM"fire_crown")->move(TO);    
    new(DEKU_ARM"fire_belt")->move(TO);    
    //new(DEKU_ARM"fire_gloves")->move(TO);    
    command("wearall");
    y = random(2);
    if(y) {
        present("crown")->set_property("monsterweapon",1);
        i++;
    }
    y = random(2);
    if(y && i) {
        present("belt")->set_property("monsterweapon",1);
    }
}

void heart_beat()
{
    object k, *atts;
    int y;
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    atts = TO->query_attackers();
    if(!sizeof(atts)) return;
    for(y = 0;y < sizeof(atts);y++) 
    {
        if(atts[y]->id("saidedekufiremon")) 
        {
            TO->remove_attacker(atts[y]);
            atts[y]->remove_attacker(TO);
            return;
        }
    }
}


void flames(object targ) 
{
    int spells;
    spells = 1 + random(2);
    if(!objectp(TO)) return;
    if(!objectp(targ)) return;
    if(targ->id("saidedekufiremon")) return;
    switch(random(5)) 
    {
        case 0..3:
            while(spells) 
            {
                spells--;
                new("/cmds/spells/m/_magic_missile")->use_spell(TO,targ,x-3,x,"mage");
            }
            break;
        case 4:
            while(spells) 
            {
                spells--;
                new("/cmds/spells/f/_fireball.c")->use_spell(TO,targ,x-3,x,"mage");
            }
            break;
    }
}        

void kill_things() 
{
    if(!objectp(TP)) return;
    if(TP->query_true_invis()) return;
    switch(random(12)) 
    {
        case 0..2:
            command("say NO ONE SHOULD BE HERE!!!");
	        TO->add_attack_bonus(6);
      	    command("stab "+TPQN);
            TO->add_attack_bonus(-6);
            command("kill "+TPQN);
            return 1;
        case 3..5:
            command("say burn, burn, burn!!!!");
            new("/cmds/spells/f/_fireball")->use_spell(TO,TP,x,x,"mage");
            return 1;
        case 6..9:
            command("yell ALL THINGS MUST BURN!!!");
            new("/cmds/spells/b/_burning_hands")->use_spell(TO,TP,x,x,"mage");
            return 1;
        case 10..11:
            command("say all things return to ash!!");
            command("kill "+TPQN);
            new("/cmds/spells/c/_conjure_elemental")->use_spell(TO,"fire",x,x,"mage");
            return 1;
    }
            
}            
