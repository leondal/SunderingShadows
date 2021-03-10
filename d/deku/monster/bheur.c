#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit MONSTER;

int natac,nstr,ndex,ncon,abon, chance, exps;
void size_change();
void failure();
void do_say();
void move_me();
int spell_okay();

void create() {
    object ob;
    ::create();
	set_name("hag");
	set_race("hag");
    set_body_type("humanoid");
    set_id(({"hag","crone","lady","elderly lady","old crone",
    "old lady"}));
	set_gender("female");
    set_short("An old crone with frost blue skin");
    set_long("%^BLUE%^This elderly lady has been utterly "+
    "ravished by the hands of time.  Her flesh is pulled "+
    "tight in some spots and hangs loose and wrinked in "+
    "others.  The surface color of her flesh offers a slight "+
    "sheen of almost frost blue that mixes with an "+
    "almost pale.  Her hair is long, thick, and tangled "+
    "together in a mess that is littered with all types "+
    "of debris.  Her eyes are a cold gray that appear almost "+
    "lifeless yet reflect a great intelligence.  An old and "+
    "ragged shawl is drapped lazily over her shoulders and "+
    "she grasps a long gray staff tightly in her blood stained "+
    "hands.%^RESET%^");

    	set_alignment(9);
    	set("aggressive","freeze_em");
    	set_class("mage");
    	set_class("cleric");
    	set_mlevel("mage",20);
	set_mlevel("cleric", 20);
    	set_guild_level("mage",query_level());
    	set_guild_level("cleric",query_level());
    
    	set_hp(355 + random(30));
	set_new_exp(20, "very high");
    //set_exp(10000);
    	set_stats("strength",15);
  	set_stats("intelligence",19 + random(3));
   	set_stats("wisdom",18 + random(3));
   	set_stats("charisma",14);
   	set_stats("dexterity",13);
   	set_stats("constitution",15);
    	set_spell_chance(40);
    	set_spells(({"frost breath",
    	"chill touch",
    	"frozen breath",
    	"chill touch",
    	"hypothermia",
    	"hypothermia",
    	}));
    	set_func_chance(85);
    	set_funcs(({"ice_spells"}));    

   	add_money("gold",1000 + random(501));
    	set_property("full attacks",1); 
    	set_mob_magic_resistance("average");
    	//set_property("no bows",1);
    	set_max_level(22);
    	set_overall_ac(-4 - random(4));
    
    	nstr = 13;
    	ncon = 15;
    	ndex = 13;
    	natac = query_attack_bonus();
    	abon = query_ac();
    	chance = 200;

    	if(!random(2))
	{
      	ob = new("/d/deku/weapons/winters_chill");
        	ob->move(TO);
    	}
    	if(!objectp(ob)) 
	{
        ob = new("/d/common/obj/weapon/quarter_staff");
        ob->set_short("A gnarled gray wood staff");
        ob->set_name("graystaff");
        ob->add_id("graystaff");
        ob->set_long("%^BOLD%^%^WHITE%^This staff spans almost "+
        "eight feet in length.  It is made from a thin and "+
        "gnarled piece of gray wood.  The origin of the "+
        "wood is a mystery, yet it is apparently sturdy enough to "+
        "negate the need for any of the common metal bands "+
        "known to quarter staffs.  Only the wood of this staff "+
        "affords it a unique appearance.%^RESET%^");
        ob->move(TO);
    	}
    	command("wield staff");  
    	FENC->fix_nogo(TO);
    set_property("not random monster", 1);
}

void heart_beat() 
{
    	object ob;
    	::heart_beat();
    	if(!objectp(TO)) return;
    	if(sizeof(TO->query_attackers()) < 1) {
        if(chance != 200) {
            chance = 200;
        }
        if(!objectp(ETO)) return;
        if(ob = present("corpse",ETO)) {
            if(!living(ob)) {
                TO->force_me("emote quickly devours the corpse "+
                "and then wipes her blood soaked mouth with her "+
                "hands.");
                TO->add_hp(20 + random(21));
                ob->remove();
            }
        }
    }
    	if(sizeof(TO->query_attackers()) > 0 && chance == 200) 
    	{
        	chance = random(21) + 20;
    	}
    	if(!random(chance)) 
	{
      	size_change();
        	return;
    	}
    	if(TO->query_hp() < ((int)TO->query_max_hp() / 2) && !random(21)) 
	{ 
      	move_me();
        	return;
    	}
    	if(!TO->query_stoneSkinned() && !random(40)) 
	{
      	if(!objectp(TO)) return;
        	new("/cmds/spells/s/_stoneskin.c")->use_spell(TO,TO,16,16,"mage");
        	return;
    	}
    	return;
}

void move_me() {
    int x;
    string rstring, *list, *nlist, *nglist, room;
    nlist = INV_ROOMS;
    nglist = NOGO_ROOMS;
    for(x = 0;x < sizeof(nlist);x++) {
        nlist[x] = "dforest"+nlist[x]+".c";
    }
    for(x = 0;x < sizeof(nglist);x++) {
        nglist[x] = replace_string(nglist[x],"/d/deku/forest/","");
    }
    
    while(!room) {
        list = get_dir("/d/deku/forest/");
        list - ({"fire_tunnel"});
        list - ({replace_string(base_name(ETO) +".c","/d/deku/forest/","")});
        list - nglist;
        list - nlist;
        //if(sizeof(list) < 1) { tell_object(find_player("saide"),"You know...");
            //return 1;
        //}
        rstring = list[random(sizeof(list))];
        room = "/d/deku/forest/"+rstring;
    }
    tell_room(ETO,"%^RED%^The old crone cackles evilly and "+
    "moves her staff around in circles, before suddenly vanishing!"+
    "%^RESET%^");
    TO->move(room);
}

void size_change() {
    if(!objectp(TO)) return;
    if((int)TO->query_size() == 2) {
        TO->set_size(3);
        tell_room(ETO,"%^BLUE%^The old crone's body %^YELLOW%^grows"+
        "%^BLUE%^, her bones %^RED%^bending%^BLUE%^ and "+
        "%^RED%^twisting%^BLUE%^ unnaturally, until her body "+
        "has reached %^RED%^monstrous%^BLUE%^ proportions!%^RESET%^");

        TO->set_stats("strength",nstr + 8);
        TO->set_stats("constitution",ncon + 4);
        TO->set_stats("dexterity",ndex - 2);
        TO->add_attack_bonus(natac - 1);
        TO->set_ac(abon - 12);
        return;
    }
    if((int)TO->query_size() == 3) {
        TO->set_size(2);
        tell_room(ETO,"%^BLUE%^The old crone's body %^YELLOW%^shrinks"+
        "%^BLUE%^, her bones %^RED%^bending%^BLUE%^ and %^RED%^"+
        "popping%^BLUE%^ unnaturally, until her body has reverted "+
        "to its original size!%^RESET%^");
        TO->set_stats("strength",nstr);
        TO->set_stats("constitution",ncon);
        TO->set_stats("dexterity",ndex);
        TO->add_attack_bonus(natac + 1);
        TO->set_ac(abon); 
        return;
     }
}      

int spell_okay() {
    object wep;
    if(wep = present("graystaff",TO)) {
        if(!wep->query_wielded()) {
            command("wield graystaff");
        }
        if(wep->query_wielded()) {
            return 1;
        }
    }
    return 0;
}

void do_say() {
    switch(random(3)) {
        case 0:
            TO->force_me("speech %^RED%^h%^BLUE%^i%^RED%^s%^BLUE%^s"+
            "%^RED%^e%^BLUE%^ venomously%^RESET%^");
            TO->force_me("say YES!  YES!  COME, LET ME FEAST!");
            TO->force_me("cackle");
            break;
        case 1:
            TO->force_me("speech %^BOLD%^%^BLACK%^whi%^BOLD%^%^GREEN%^"+
            "sp%^BOLD%^%^BLACK%^er %^BLUE%^coldy%^RESET%^");
            TO->force_me("say welcome to my cold feast....");
            TO->force_me("emote cackles insanely and her gray "+
            "eyes momentarily flash a blood red");
            break;
        case 2:
            TO->force_me("speech %^CYAN%^ca%^RED%^ck%^CYAN%^le "+
            "%^RED%^evilly%^RESET%^");
            TO->force_me("say come, join in the feast of the "+
            "dead!");
            break;
    }
}

void failure() {
    TO->force_me("yell WHAT!! WHERE IS MY STAFF???!!??");
}

void freeze_em() {
    int lev;
    if(!objectp(TP)) return;
    if(TP->query_invis() && !random(3)) return;
    do_say();
    
    if(!spell_okay()) {
        failure();
        TO->force_me("kill "+TPQN);
        return;
    }

    lev = (int)TO->query_guild_level("mage");
    new("/cmds/spells/c/_cone_of_cold")->use_spell(TO,TP,lev,lev,"mage");
    return;
}

void ice_spells(object targ) {
    int lev;
    if(!objectp(TO) || !objectp(targ)) return;
    lev = (int)TO->query_guild_level("mage");
    if(!spell_okay()) {
        new("/cmds/spells/c/_chill_touch")->use_spell(TO,targ,lev,lev,"mage");
        TO->set_func_chance(0);
        return;
    }

    switch(random(10)) {
        case 0..7:
            new("/cmds/spells/c/_cone_of_cold")->use_spell(TO,targ,lev,lev,"mage");
            break;
        case 8..9:
            if(!ETO->query_property("iced")) {
                new("/cmds/spells/i/_ice_storm")->use_spell(TO,targ,lev,lev,"mage");
                break;
            }
            new("/cmds/spells/c/_cone_of_cold")->use_spell(TO,targ,lev,lev,"mage");
            break;
    }
}
