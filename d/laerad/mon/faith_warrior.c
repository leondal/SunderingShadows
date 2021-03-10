#include <std.h>
#define ASDIR "/d/laerad/parnelli/asgard/"
#define NOGOROOM ({ASDIR+"as56", ASDIR+"as57","/d/laerad/parnelli/forest/for081"})
#define FAITHS ({"kreysneothosies","lord shadow"})
#define CLASSES ({"fighter","paladin","ranger"})
#define EYES ({"%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^ha%^GREEN%^z%^ORANGE%^el","%^BOLD%^%^BLUE%^blue","%^RESET%^%^GREEN%^green"})
#define HAIR ({"%^RESET%^%^ORANGE%^brown","%^YELLOW%^blond","%^RESET%^%^RED%^red","%^BOLD%^%^BLACK%^black","%^RESET%^gray"})
#define HAIRTYPE ({"short","long","curly","chin-length"})

inherit MONSTER;

string theclass,faith;

void kill_em(object targ);

void create(){
    string poss,subj;
    object obj;
    theclass = CLASSES[random(sizeof(CLASSES))];
    faith = FAITHS[random(sizeof(FAITHS))];
    ::create();
    set_id(({"warrior","faith warrior",""+theclass+" of "+faith+"",""+theclass+" of "+capitalize(faith)+"",""+theclass+""}));
    set_name("A steadfast "+theclass+" of "+capitalize(faith)+"");
    set_short("%^RESET%^%^CYAN%^A steadfast %^RED%^"+theclass+" of %^ORANGE%^"+capitalize(faith)+"%^RESET%^");
    set_gender(!random(2)?"male":"female");
    switch(random(2)){
       case 0: set_gender("male");
               poss = "his";
               subj = "he";
               break;
       case 1: set_gender("female");
               poss = "her";
               subj = "she";
               break;
    }
    set_long("%^RESET%^%^CYAN%^This sharp-eyed warrior surveys "+poss+" "
       "surroundings with an air of wariness and confidence.  Dressed in "
       "well-crafted armor, "+subj+" wears a cloak embroidered with the "
       "holy symbol of "+capitalize(faith)+", professing "+poss+" faith "
       "proudly.  "+capitalize(poss)+" "+HAIRTYPE[random(sizeof(HAIRTYPE))]+" "
       ""+HAIR[random(sizeof(HAIR))]+" hair %^RESET%^%^CYAN%^is clean and well-groomed, "
       "making it clear that appearance is important to this soldier, while "
       ""+poss+" "+EYES[random(sizeof(EYES))]+" eyes %^RESET%^%^CYAN%^reveal "
       ""+poss+" intelligence and sense of duty.  "+capitalize(subj)+" spends "
       ""+poss+" time patrolling the ruins of Asgard, working to chase away "
       "intruders and opportunists.%^RESET%^");
    set_body_type("human");
    set_race("human");
    set_size(2);
    set_hd(20+(random(9)),6);
    set_max_hp(166+(random(72)));
    set_hp(TO->query_max_hp());
    set_max_level(27);
    set_overall_ac(-5);
    set_new_exp(24,"normal");
    set_alignment(1);
    switch(theclass){
       case "fighter": set_guild_level("fighter",24);
                       add_search_path("/cmds/fighter/");
                       obj = new("/d/common/obj/armour/chain");
                       obj->set_property("enchantment",3);
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/common/obj/armour/helm");
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj = new("/d/antioch/valley/obj/sunblade");
                       obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       command("wield sword");
                       break;
       case "paladin": set_guild_level("paladin",24);
                       set_guild_level("cleric",24);
                       add_search_path("/cmds/paladin/");
                       add_search_path("/cmds/cavalier/");
                       add_search_path("/cmds/spells/");
                       set_spells(({"call lightning","cause blindness","dispel magic"}));
                       set_spell_chance(20);
                       obj = new("/d/common/obj/armour/fullplate");
                       obj->set_property("enchantment",3);
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/common/obj/armour/helm");
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/common/obj/armour/shield");
                       obj->set_property("enchantment",3);
                       obj->set_long("This shield is crafted from a thin sheet "
                          "of %^BOLD%^metal %^RESET%^shaped into an oval and "
                          "gently curved to deflect blows.  The front has been "
                          "enameled with the holy symbol of %^BOLD%^"+capitalize(faith)+", "
                          "while the back has been fitted with a metal bar and %^ORANGE%^"
                          "straps %^RESET%^for ease of wearing.");
                       obj->set_short("%^RESET%^%^CYAN%^a shield embossed with the symbol of "+capitalize(faith)+"%^RESET%^");
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       call_out("horse_me",2);
                       break;
       case "ranger":  set_guild_level("ranger",24);
                       set_guild_level("cleric",24);
                       add_search_path("/cmds/ranger/");
                       add_search_path("/cmds/spells/");
                       set_spells(({"cause blindness","dispel magic","orders oath","seeking sword"}));
                       set_spell_chance(20);
                       obj = new("/d/common/obj/armour/hide");
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/common/obj/armour/coif_leather");
                       obj->set_property("enchantment",1);
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/common/obj/armour/bracers");
                       obj->set_property("enchantment",3);
                       if(random(5)) obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       obj = new("/d/antioch/valley/obj/sunblade");
                       obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       command("wield sword");
                       obj = new("/d/antioch/valley/obj/shining_sword");
                       obj->set_property("monsterweapon",1);
                       obj->move(TO);
                       command("wield sword");
                       break;
    }
    set_class(theclass);
    set_guild_level(theclass,24);
    set_stats("strength",22);
    set_stats("dexterity",20);
    set_stats("constitution",19);
    set_stats("charisma",18);
    set_mob_magic_resistance("average");
    set_property("add kits",20);
    if(!random(5)) new("/d/deku/armours/ring_p")->move(TO);
    obj = new("/d/shadow/obj/clothing/silkcloak");
    if(random(3)) obj->set_property("monsterweapon",1);
    obj->move(TO);
    command("wearall");
    set_property("swarm",1);
    set_property("full attacks",1);
    set("aggressive", "kill_em");
    set_emotes(5,({
       "%^RESET%^%^MAGENTA%^The "+theclass+" says:%^RESET%^ This land is no longer secure. Return to the mainland if you are concerned with your safety.",
        "The "+theclass+" patrols the ruins with an air of purpose.",
        "With a concerned frown, the "+theclass+" leans down to examine something on the ground.",
        "The "+theclass+" touches "+poss+" holy symbol of "+capitalize(faith)+" and whispers a brief prayer."
        }),0);
    set_emotes(2,({
       "%^BOLD%^%^MAGENTA%^The "+theclass+" yells:%^RESET%^ You dare to attack a "+theclass+" of "+capitalize(faith)+"?!",
       "%^YELLOW%^The "+theclass+" spins "+poss+" sword and readies for another attack!%^RESET%^",
       "%^BOLD%^The "+theclass+" calls out a prayer to "+capitalize(faith)+" and attacks!%^RESET%^"
       }),1);
//    set_funcs(({"headlock","kick"}));
//    set_func_chance(30);
    set_moving(1);
    set_speed(10);
}

void kill_em(object targ) {
    if(member_array("forestmon",TP->query_id()) != -1) {
       force_me("say %^BOLD%^Asgard will rise again! Be gone, foul creature!");
       force_me("kill "+TPQN);
    }
    return;
}

int cast_check(object obj)
{
    if(!objectp(obj)) { return 0; }
    if(obj->query_property("spell_casting")) { return 0; }
    return 1;
}

void headlock(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^GREEN%^The Commando slips in behind you and puts you in a painful headlock!");
	tell_room(ETO,"%^BOLD%^GREEN%^The Commando slips in behind "+targ->query_cap_name()+" and puts "+targ->query_objective()+" in a headlock!",targ);
	targ->set_paralyzed(30,"You are in a headlock.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The Commando attempts to slip in behind you but you cut him off!");
    tell_room(ETO,"%^BOLD%^GREEN%^The Commando attempts to slip in behind "+targ->query_cap_name()+" but "+targ->query_subjective()+" cuts him off!",targ);
    return 1;
}
void kick(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	tell_object(targ,"%^BOLD%^RED%^The Commando sends a bone crunching karate kick right to your throat!");
	tell_room(ETO,"%^BOLD%^RED%^The Commando sends a bone crunching karate kick right to "+targ->query_cap_name()+"'s throat!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(5,10)+10);
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^The Commando sends a karate kick towards you but you dodge out of the way!");
    tell_room(ETO,"%^BOLD%^RED%^The Commando sends a karate kick at "+targ->query_cap_name()+" but "+targ->query_subjective()+" dodges out of the way!",targ);
    return 1;
}

void init(){
    ::init();
    if((string)TP->query_race() == "troll"){
	   force_me("say You will not profit from the destruction of civilization!");
      force_me("kill troll");
    }
    if(member_array("forestmon",TP->query_id()) != -1) {
       force_me("say %^BOLD%^Asgard will rise again! Be gone, foul creature!");
       force_me("kill forestmon");
    }
}

//horse code stolen from shifters
void horse_me(){
    object ob;
    set_nwp("riding",50);
    ob = new("/d/common/mounts/war_horse");
    ob->set_owner(TO);
    ob->set_property("water breather",1);
    ob->set_level((int)TO->query_level());
    ob->move(ETO);
    TO->force_me("mount horse");
    if(objectp(ob) && objectp(TO)) { ob->add_protector(TO); }
    ob = new("/d/common/obj/weapon/lance");
    ob->set_property("enchantment",3);
    ob->set_property("monsterweapon",1);
    ob->move(TO);
    TO->force_me("wield lance");
    return;
}
