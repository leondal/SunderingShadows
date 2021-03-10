//General difficulty increase Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit MONSTER; 
int xx;
void create() {
    :: create();
    set_name("knight");
    set_id(({
        "knight","my_knight"
    }));
    set_short("%^RESET%^%^RED%^Knight of the Order%^RESET%^");
    set_long(
	"The man before you is clad in full plate, shield and coif. He stands "
	"in a ready position wielding a glowing sword. A blazing holy "
	"aura surrounds him."
    );
    set_gender("male");
    set_class("paladin");
    set_level(40);
    set_hd(40,9);
    set_size(2);
    set_weight(80);
    set_property("alignment adjustment",-30);
    set_wielding_limbs(({"right hand","left hand"})); 
    set_overall_ac(-15);
    set_property("add kits",15);
    set_property("no bump",1);
    set_diety("tyr");
    set_property("no steal",1);
    set_body_type("human");
    set_race("human");
    set_guild_level("paladin",40);
    set_stats("strength",29);
    set_stats("constitution",30);
    set_stats("dexterity",30);
    set_stats("wisdom",35);
    set_stats("intelligence",40);
    set_stats("charisma",29);
    set_alignment(1);
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_exp(40000);
    set_max_level(36);
    set_max_hp(500);
    set_hp(500);
    add_money("gold",random(2000)+500);
    set_emotes(1,({
        "%^BLUE%^The knight stands unwavering before you.%^RESET%^",
	"%^RED%^The knight examines you carefully.",
        "%^MAGENTA%^Knight says: %^RESET%^Only the pentitent may pass!",
    }),0);	
    new( OPATH "avenger.c" )->move(TO);
    command("wield sword in left hand");
    new( OPATH "coif.c" )->move(TO);
    command("wear coif");
    new( OPATH "shield.c" )->move(TO);
    command("wear shield");
    new( OPATH "plate.c" )->move(TO);
    command("wear plate");
    set_funcs(({"special","bashit"}));
	set_monster_feats(({
	   "shieldbash",
	   "shieldwall",
	   "deflection",
	   "reflection",
	   "counter",
	   "parry",
   }));
   set_func_chance(50);  	
	
}
int special() {
    object ob = this_object();
    say("%^CYAN%^The knight concentrates on his wounds!\n%^YELLOW%^The knight heals!%^RESET%^"); 
    ob->add_hp(random(30)+20);
    return 1;
}	
void set_paralyzed(int time,string message){return 1;}

void bashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shieldbash "+targ->query_name());
}

/*
void heart_beat() {
    ::heart_beat();
    if(TO->query_hp() < 100) {
	TO->add_hp(random(1));
        return;
    } else {
        return;
    }
}
A random(1) won't ever add HP anyway, and this is bugging.
Taken out by Circe 1/25/05
*/
