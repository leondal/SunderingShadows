//Updated description and mechanics - Octothorpe 11/1/09
//Coded by the one and only master of monsters...BANE//
// added laeradmon id and made a little tougher *Styx*  12/20/03

#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create(){
    ::create();
    set_id(({"cockatrice","Cockatrice", "laeradmon", "magical beast"}));
    set_name("cockatrice");
    set_short("%^RESET%^%^GREEN%^repulsive cockatrice%^RESET%^");
    set_long("%^RESET%^%^GREEN%^This repulsive hybrid of lizard, "+
	   "cock, and bat is about the size of a large turkey.  It has "+
	   "the head and body of a cock, with two bat-like wings and the "+
	   "long tail of a lizard tipped with a few feathers.  Infamous "+
	   "for its ability to turn living creatures to stone, most sane "+
	   "beings stay clear of them.%^RESET%^");
    set_body_type("fowl");
    set_race("cockatrice");
    set_gender("male");
    set_size(1);
    set_alignment(8);   // was 5
    set_hd(15,10);	// was 5,10
    set_max_level(20);  // was 15
    set_hp(150);	// was 50
    set_attack_bonus(1);
    set_exp(18000);
    set_overall_ac(-3);
    set("aggressive",7);
    set_attack_limbs(({"head"}));
    set_attacks_num(1);
    set_base_damage_type("piercing");
    set_damage(2,4);
    set_hit_funcs( (["head":(:TO,"stone":)]) );
    set_stats("strength",16);
    set_stats("dexterity",17);
    set_stats("intelligence",2);
    set_stats("wisdom",6);
    set_stats("constitution",8);
    set_stats("charisma",1);
	set_funcs(({"stone"}));
    set_func_chance(50);
	set_moving(1);
	set_speed(60);
	set_nogo(({"/d/laerad/wasteland/waste1"}));
    set_property("not random monster", 1);
}

int stone(object targ){
    string targ_name,targ_desc;
    if(!"/daemon/saving_throw_d.c"->fort_save(targ,-12)){
	   tell_object(targ,"%^BOLD%^RED%^The cockatrice bites you and "+
	      "causes immense pain as your flesh begins to harden into stone"+
		  "...oh, that's petrifying!");
	   tell_room(ETO,"%^BOLD%^RED%^"+targ->QCN+" doubles over in pain "+
	      "as the cockatrice bites "+targ->QO+", and "+targ->QCN+" "+
		  "begins to turn into stone!%^RESET%^",targ);
       set_property("magic",1);
       targ->add_hp(-666666); //I wonder if add_hp gets around damage resistance? - Octothorpe
       set_property("magic",-1);  // was remove_property which shouldn't really be used
	   call_out("make_statue",1,targ_name,targ_desc); //Borrwing statue making code from Medusa on Graez
       return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^You resist the bite of the "+
	   "cockatrice!%^RESET%^");
    tell_room(ETO,"%^BOLD%^RED%^"+targ->QCN+" resists the bite of the "+
	   "cockatrice!",targ);
	add_attack_bonus(query_attack_bonus()+1);
    return 1;
}

void make_statue(string str,string desc){
    object ob,statue;
    if(ob = present("corpse",ETO)){
       statue = new(OBJECT);
       statue->set_name("statue");
       statue->set_id(({"statue"}));
       statue->set_short("%^RESET%^A stone statue of a "+str);
       statue->set_weight(100000);
       statue->set_long("%^RESET%^This is a statue of "+str+".  In life it looked "
            "something like:\n"+str+" "+desc);
       statue->move(ETO);
       ob->remove();
    }
    return;
}
