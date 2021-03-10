#include <std.h>
#include "../theater.h"

inherit "std/monster";
void create(){
    object obj; 
    ::create();
	set_name("ivashka");
	set_id(({"ivashka","harpy","female","theater_mon"}));
	set_short("Ivashka, The Harpy");
	set_long("%^GREEN%^Unlike a typical harpy, Ivashka "+
		"differs greatly.  With the upper body of a human female"+
		" and the legs of a bird, Ivashka has a monstrous look to"+
		" her. Her long shaggy %^CYAN%^gray-blue%^GREEN%^ hair hangs"+
		" down her back, looking wild and untamed.  Her ample figure"+
		" is protected by a leather breastplate, almost making her "+
		"look voluptuous.  Her %^ORANGE%^tanned%^GREEN%^ skin is "+
		"sleek and taunt, showing off her muscled form well.  "+
		"Rising out  of her back are a pair of large feathered wings."+
		"  While most of the plumes are %^RESET%^gray%^GREEN%^, a"+
		" few other %^CYAN%^c%^BLUE%^o%^CYAN%^l%^BLUE%^o%^CYAN%^r%^BLUE%^s"+
		"%^GREEN%^ are intermixed within.  Similar feathers cover her"+
		" legs down to her talon bird-like 'feet'.  Her %^RED%^red eyes"+
		"%^GREEN%^ carry a cold glint to them, making her look almost "+
		"deranged and mad.%^RESET%^");
	set_race("harpy");
	set_gender("female");
	set_body_type("human");
	set_overall_ac(4);
// have dropped her from L24 to L20; the new stab mechanics have made her quite broken. N, 5/18.
	set_hd(20,0);
	set_class("fighter");
	set_class("thief");
	set_mlevel("fighter",20);
	set_mlevel("thief",20);
	set_level(20);
	set_guild_level("thief",20);
	set_guild_level("fighter",20);
	set_size(2);
	set_max_level(15);
	set_stats("strength",19);
	set_stats("intelligence",10);
	set_stats("dexterity",16);
	set_stats("charisma",12);
	set_stats("constitution",18);
	set_stats("wisdom",12);
	set_scrambling(1);
	set_alignment(6);
	set_mob_magic_resistance("average");
	set_property("full attacks",1);
	set_property("no dominate",1);
   //set_property("no rush",1); - I am editing this out because I see no point in punishing certain classes.  We might as well give this thing 100% mr and set a "no lower" property
	set_property("no trip",1);
	set_property("no bow",1);
   //set_property("no stab",1); - see my above note Ts 6-17-08
   //set_property("no charge",1);  edited out, see above notes
    set_property("add kits",5);
	add_search_path("/cmds/fighter");
	add_search_path("/cmds/thief");
	remove_limb("left foot");
    remove_limb("right foot");
    add_limb("left claw","left leg",0,0,0);
    add_limb("right claw","left leg",0,0,0);
    add_limb("left wing","torso",0,0,0);
    add_limb("right wing","torso",0,0,0);
	obj = new(OBJ"alignleather");
	obj->set_property("monsterweapon",1);
	obj->move(TO);
	switch(random(10)){
        case 0..5:
		    obj=new(OBJ"jadeclaws");
		    obj->move(TO);
		    obj=new(OBJ"jadeclaws");
		    obj->set_property("monsterweapon",1);
		    obj->move(TO);
			command("wield claws");
			command("wield claws 2");
            break;
        default:
		    obj=new(OBJ"runeaxe");
		    obj->move(TO);
			command("wield axe");
            break;
    }
	obj=new("/d/deku/armours/ring_p.c");
	obj->remove_property("enchantment");
	obj->set_property("enchantment",2);
	obj->move(TO);
    obj=new("/d/common/obj/rand/rand_leath_head.c");
    obj->remove_property("enchantment");
	obj->set_property("enchantment",1);
    obj->move(TO);
	force_me("wearall");
	add_money("electrum",random(400)+1000);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	set_max_hp(random(50)+550);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set("aggressive",25);
	set_funcs(({"rushit","flashit","flashit","sing"}));
	set_func_chance(30);
    set_exp(random(500)+6500);
	set_languages( ({ "common" }) );
	set_emotes(10,({"%^MAGENTA%^Ivashka says:%^CYAN%^Let me sing for you..","%^MAGENTA%^Ivashka says:%^CYAN%^They laugh at me.. those pretentious slags","%^MAGENTA%^Ivashka says:%^CYAN%^Do you think the sirens are getting fatter?","%^MAGENTA%^Ivashka says:%^CYAN%^No time..time..have all the time in the world","%^MAGENTA%^Ivashka says:%^CYAN%^Why did I let Mashiva talk me into this.  Trapped here.  All time."}),0);
	set_achats(10,({"%^MAGENTA%^Ivashka says:%^CYAN%^Those siren bitches sent you, didn't they!","%^MAGENTA%^Ivashka says:%^CYAN%^Fan? My fans have finally come!","%^MAGENTA%^Ivashka says:%^CYAN%^Mashiva will not have you, you are mine!"}));
	set_monster_feats(({
      "parry",
      "powerattack",
	  "shatter",
	  "sunder",
	  "rush",
	  "dodge",
      "mobility",
	  "evasion",
	  "scramble",
	  "combat reflexes"
    }));  
}
void rushit(object targ) {
	TO->force_me("rush "+targ->query_name());
}

void flashit(object targ) {
  	TO->force_me("flash "+targ->query_name());
}
/*
int scrambleit(){
	command("scramble");
	return 1;
}*/
void sing(object targ)
{
if(!"/daemon/saving_throw_d.c"->will_save(targ,-15)){
//if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")) {
    	tell_object(targ,"%^CYAN%^The harpy begins to sing a beautiful "+
		"song in a mesmerizing voice.  You find yourself wanting to stop"+
		" and listen to her tune.");
      tell_room(ETO,"%^CYAN%^The harpy begins to sing a beautiful song"+
		" in a mesmerizing voice. "+targ->QCN+" stops to listen "+
		"to the song.",targ);
    	targ->set_paralyzed(20,"%^BOLD%^%^CYAN%^You don't want to miss the"+
		" beautiful song!");
        		return 1;
}
else {
    	tell_object(targ,"%^CYAN%^The harpy begins to sing a beautiful"+
		" song in a mesmerizing voice.  For a  moment you almost want"+
		" to stop and listen to it.");
     	tell_room(ETO,"%^CYAN%^The harpy begins to sing a beautiful "+
		"song in a mesmerizing voice.  For a moment"+ 
      	" "+targ->QCN+", looks as if they want to stop and listen to"+
		" it.",targ);
    			return 1;
     }
}
void die(object obj) {
	new(OBJ"marblelyre")->move(TO); 
	if(!random(3)) {
		new(OBJ"alignleather")->move(TO);
    	}
	tell_room(ETO,"%^CYAN%^As Ivashka falls from the sky, her taloned"+
		" feet rip into the backdrops, giving a peak at a ladder"+
		" behind them, before it is covered up again.");
    	::die(obj);
}
