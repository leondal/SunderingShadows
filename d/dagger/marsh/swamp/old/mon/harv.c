#include <std.h>
inherit "/std/monster";
int FLAG;
void create() {
    ::create();
    set_name("Cleric of sorrow");
    set_id( ({"cleric","sorrow cleric","sorrow_cleric","sorrow","madernun","harvester"}) );
    set_hd(15,4);
    set_gender("male");
    set_short("%^RESET%^%^CYAN%^Madernun, The Harvester%^RESET%^");
    set_long("The old, yet stout, man before you has a long beard and a "+
	"knowing look in his eyes. He must be a cleric of the Harvester "+
	"clan. The clan is a sorrowed filled clan of farmers and gatherers "+
	"who are very in tune with nature and have a mystical bond to the land.");
    set_race("human" );
    set_mob_magic_resistance("average");
    set_overall_ac(-3);
    set_alignment(5);
    set_stats("intelligence", 20);
    set_stats("wisdom", 20);
    set_stats("charisma",18);
    set_stats("strength", 18);
    set_stats("dexterity", 19);
    set_stats("constitution", 20);
    set_class("cleric");
    set_mlevel("cleric",15);
    set_guild_level("cleric",15);
    add_search_path("/cmds/cleric");
    set_hp((15 * 10) + random(41));
    set_exp(query_hp() * 50);

    FLAG = 0;
    new("/d/dagger/marsh/tower/obj/sorrow.c")->move(TO);
    command("wield staff");
    set_funcs(({"special"}));
    set_func_chance(25);    
    set_emotes(1,({
	"A deep sorrow fills your soul.",
	"You feel the nature around you watching all.",
	"The land seems to whisper it's sorrow.",
    }),1);	
    set_spells(({"call lightning","thornspray",
    "thornspray","sticks into snakes",
    "dispel magic","hold person"}));
    set_spell_chance(45);
    if(!random(3)) {
        new("/d/shadow/obj/clothing/silkcloak")->move(TO);
        command("wear cloak");
    }
    if(!random(2)) {
        new("/d/dagger/marsh/tower/obj/stag_leather.c")->move(TO);
        command("wear leather");
    }
}
void special(object targ) {
    if(FLAG > 2) return 1;
        command( "say Why must you attack me?!?");
	command( "say The land will heal my wounds!");
        command( "emote is healed by the lands!");
	add_hp(random(50)+50);
	FLAG = FLAG + 1;
        return 1;
}
void set_paralyzed(int time,string message){return 1;}

 
