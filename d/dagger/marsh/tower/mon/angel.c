//General difficulty increase Octothorpe 5/25/09
#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
inherit MONSTER; 
int xx;
void create() {
    :: create();
    set_name("angel");
    set_id(({
        "angel","angel of death","antipaladin","knight"
    }));
    set_short("%^RESET%^%^BLUE%^Angel of death%^RESET%^");
    set_long(
	"The being before you is clad in full plate, shield and coif. He stands "
	"in a ready position wielding a glowing sword. A blazing unholy "
	"aura surrounds him."
    );
    set_gender("male");
   set_class("paladin");
//changed him to "paladin" since there are no more antipaladins
//~Circe~ 1/4/13
    set_level(40);
    set_hd(40,9);
    set_size(2);
    set_weight(80);
    set_wielding_limbs(({"right hand","left hand"})); 
    set_overall_ac(-15);
    set_property("no bump",1);
//    set_property("alignment adjustment",30);
//toning this down because the hit is huge ~Circe~ 7/12/05
    set_property("alignment adjustment",10);
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
    set_alignment(3);
    set_diety("shar");
//added deity to stop bug with querying the god on the unholy avenger
//Circe 1/25/05
    set_mob_magic_resistance("average");
    set_property("full attacks",1);
    set_exp(60000);
    set_max_hp(500);
    set_max_level(36);
    set_hp(500);
    add_money("gold",random(2000)+500);
    set_emotes(1,({
        "%^BLUE%^The Angel of death stands unwavering before you.%^RESET%^",
	"%^RED%^The Angel of death examines you carefully.",
        "%^MAGENTA%^Angel of death says: %^RESET%^Your soul will be mine!",
    }),0);	
    new( OPATH "unholy.c" )->move(TO);
    command("wield sword in left hand");
    new( OPATH "uncoif.c" )->move(TO);
    command("wear coif");
    new( OPATH "unshield.c" )->move(TO);
    command("wear shield");
    new( OPATH "unplate.c" )->move(TO);
    command("wear plate");
    set_funcs(({"special"}));
    set_func_chance(20);
    set_property("add kits",15);
	set_monster_feats(({
	   "shieldbash",
	   "shieldwall",
	   "deflection",
	   "reflection",
	   "counter",
	   "parry",
   }));
   set_funcs(({
      "bashit",
   }));
   set_func_chance(50);
    set_resistance("negative energy",15);
    set_resistance("positive energy",-15); 
}
int special() {
    object ob = this_object();
    say("%^RED%^The %^BLUE%^Angel of death%^RED%^ concentrates on "
	"his wounds!\n%^RED%^The %^BLUE%^Angel of death%^RED%^ "
	"heals!%^RESET%^"); 
    ob->add_hp(random(30)+20);
    return 1;
}	
void set_paralyzed(int time,string message){return 1;}

void heart_beat() {
    ::heart_beat();
    if(!objectp(TO)) { return; }
    if(TO->query_hp() < 100) {
	TO->add_hp(random(1));
        return;
    } else {
        return;
    }
}

void bashit(object targ){
   if(!objectp(targ)) return;
   if(!objectp(TO)) return;
   TO->force_me("shieldbash "+targ->query_name());
}