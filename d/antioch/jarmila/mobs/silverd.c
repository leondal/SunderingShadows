#include <std.h>
#include <daemons.h>


inherit MONSTER;


int count, flag;

void create()
{
    object obj;
    int i;
	
	
    ::create();
    set_name("Zykiero the Silver Terror");
    set_id(({ "dragon", "terror", "silver dragon", "Zykiero", "silver terror", "Zykiero the Silver Terror"
}));
    set_short("%^RESET%^%^BOLD%^Zyki%^CYAN%^e%^RESET%^%^BOLD%^ro the S%^RESET%^i%^RESET%^%^BOLD%^lver Ter%^CYAN%^r%^RESET%^%^BOLD%^or%^RESET%^");
	
    set_long("%^BOLD%^At a full length of two %^RESET%^hundred feet "+
	"long, %^BOLD%^this massive silver dragon is an %^BLACK%^awe "+
	"inspiring%^WHITE%^, or completely terrifying sight. Its "+
	"%^RESET%^%^CYAN%^serpentine %^BOLD%^%^WHITE%^body is covered "+
	"in a series of pale silver scales, each the size of a tower "+
	"shield. Massive %^RESET%^silver wings %^BOLD%^once spread would "+
	"easily cover three hundred feet and could knock over all but "+
	"the strongest of walls.%^RESET%^%^RESET%^");
    set_gender("male");
    set_race("dragon");
	
    set_body_type("dragon");
    set_attack_limbs(({ "right claw", "left claw", "mouth", "tail" }));
		
    set_alignment(1);
    set("aggressive", 2);
    set_size(3);
    set_hd(70, 8);
	
    set_class("mage");
	set_mlevel("mage",70);
    set_guild_level("mage", 70);

    set_class("cleric");
    set_mlevel("cleric",70);
    set_guild_level("cleric",70);
	
    set_overall_ac(-70);

    set_stats("intelligence", 30);
    set_stats("wisdom", 26);
    set_stats("strength", 26);
    set_stats("charisma", 12);
    set_stats("dexterity", 16);
    set_stats("constitution", 24);

    set_new_exp(70, "boss");
    set_mob_magic_resistance("high");

    set_property("spell damage resistance", 10);
    set_property("no death", 1);
    set_property("magic", 1);
    set_property("no animate", 1);
    set_property("no steal", 1);
    set_property("no bow", 1);
    set_property("weapon resistance", 5);
    set_property("function and attack", 1);
    set_monster_feats(({
        "spell focus",
        "spell penetration",
        "greater spell penetration",
        "spell power",
        "perfect caster",
        "blind fight",
        "spell reflection",
    }));

    set_max_hp(35000);
    set_hp(query_max_hp());
    set_property("add kits", 40);
    set_emotes(2,
               ({ "%^RESET%^%^BOLD%^The massive dragon curls up "+
			   "and drinks in the glow from above.%^RESET%^",
                  "%^RESET%^%^BOLD%^The dragon stretches his "+
				  "wings to their full spread%^RESET%^" }), 0);
    add_money("gold", 50000 + random(10000));

    set_funcs(({ "breath_cold",
                 "claw_swipe",
                 "tail_swipe" }));

    set_func_chance(30);

    set_spells(({ "holy orb",
                  "sunburst",
                  "cometfall",
                  "holy word",
                  "searing light",
                  "hypothermia",
                  "sunburst",
                  "dispel evil",
                  "celestial brilliance",
                  "greater dispel magic" })); 

    set_spell_chance(90);

}

int set_paralyzed(int num, string str)
{
    return 0;
}

int set_tripped(int num, string str)
{
    return 0;
}

void heart_beat(){
        ::heart_beat();

        if(!objectp(TO) || !objectp(ETO)) return;
        if(query_hp()< 1000 && present("vial",TO)){
            force_me("quaff vial");
            force_me("quaff vial");
            force_me("quaff vial");            
			force_me("quaff vial");
			force_me("quaff vial");
        }
}






void breath_cold(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, " .");
    tell_room(ETO, " .");
    if (!vic->will_save(35))
    {
        tell_object(vic, "%^RESET%^%^BOLD%^The dragon rears his head "+
		"back and with a mighty roar a massive cone of cold flies "+
		"from its maw.%^RESET%^");
        tell_room(ETO, "%^RESET%^%^BOLD%^The cone of cold floods "+
		"over" + vic->query_cap_name() + "%^RESET%^%^BOLD%^screams!", vic);
        //vic->do_damage(vic->return_target_limb(), roll_dice(5, 20));
        vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(5, 20), "cold");
    }
}

void claw_swipe(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^BLACK%^%^BOLD%^The massive silver dragon pounces forward "+
	"and attacks with a wicked swipe of his claws.%^RESET%^");
    if (!vic->fort_save(35)) {
        tell_object(vic, "%^BLACK%^%^BOLD%^The claws rip across your body!%^RESET%^");
        tell_room(ETO, "%^BLACK%^%^BOLD%^" + vic->query_cap_name() + "%^BLACK%^%^BOLD%^"+
		"is ravaged by the dragon's claws!%^RESET%^", vic);
        //vic->do_damage(vic->return_target_limb(), roll_dice(5, 20));
        vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(5, 20), "slashing");
    }
}

void tail_swipe(object vic)
{
    if (!objectp(vic)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }
    if (!objectp(ETO)) {
        return;
    }
    tell_room(ETO, "%^RESET%^%^RED%^The dragon turns and puts its "+
	"entire weight into attacking with its tail.%^RESET%^");
    if (!vic->will_save(35) {
        tell_object(vic, "%^RESET%^%^RED%^With a grunt, you feel "+
		"the tail slam against you and drop you to your knees!%^RESET%^");
        tell_room(ETO, "%^RESET%^%^RED%^" + vic->query_cap_name() + " "+
		"%^RESET%^%^RED%^is slammed to the ground by the dragons "+
		"tail, stealing the breath from " + vic->query_possessive() + "+ "+
		"%^RESET%^%^RED%^lungs", vic);
        //vic->do_damage(vic->return_target_limb(), roll_dice(4, 20));
        vic->cause_typed_damage(vic, vic->return_target_limb(), roll_dice(4, 20), "bludgeoning");
        vic->set_paralyzed(random(20) + 10, "You are still trying to get up.");
    }
}




void die(object ob) {
    int i;
    object *att;

    ETO->lockdown();
    tell_room(ETO, "%^RESET%^%^BOLD%^The silver dragon sheds some scales and flees.");
    message("broadcast", "   %^RESET%^%^BOLD%^A massive silver dragon takes to the skies with a bellow of holy rage%^RESET%^.", users());
    att = all_living(ETO);
    for(i=0;i<sizeof(att);i++){
      if(!interactive(att[i])) continue;
      att[i]->set_mini_quest("Faced the Silver Terror", 1000000,"%^RESET%^%^BOLD%^Faced the Silver Terror%^RESET%^.");
      tell_object(att[i], "   %^RESET%^%^BOLD%^Faced the Silver Terror%^RESET%^.\n");
    }
   TO->remove();
}

