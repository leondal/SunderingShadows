//Coded by Bane//
#include <std.h>
inherit MONSTER;
void create(){
    ::create();
    set_id(({"pixie","Pixie", "forestmon"}));
    set_name("Pixie");
    set_short("A tricky Pixie");
    set_long(
	"A beautiful little pixie.  She is only about 6 inches tall and she "+
	"moves around with such speed its hard to tell what she looks like.  "+
	"Her little wings flutter back and forth making a faint buzzing "+
	"noise.  Her hair is pink and she is dressed in tattered green rags."
    );
    set_body_type("human");
    set_race("pixie");
    set_gender("female");
    set_size(1);
    set_alignment(5);
    set_overall_ac(-1);
    set("aggressive",0);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_class("mage");
    set_guild_level("mage",15);
    set_hd(9,3);
    set_hp(75);
    set_exp(2100);
    set_spells(({
	"magic missile",
	"hold person",
	"cone of cold"
    }));
    set_spell_chance(50);
    add_limb("right wing","torso",0,0,0);
    add_limb("left wing","torso",0,0,0);
    set_wielding_limbs(({"right hand","left hand"}));
    new("/d/common/obj/weapon/dagger")->move(TO);
    command("wield dagger");
    add_money("gold",random(100)+300);
    add_money("silver",random(200)+200);
    set_funcs(({"back_stab","dust"}));
    set_func_chance(30);
    set_max_level(35); //added by Ares 3-31-05, they should be moving on long before now, but just in case

}
void back_stab(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^GREEN%^The Pixie slips in behind you and drives her dagger into your back!");
	tell_room(ETO,"%^GREEN%^The Pixie slips in behind "+targ->query_cap_name()+" and drives her dagger into "+targ->query_possessive()+" back!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(8,8));
	return 1;
    }
    tell_object(targ,"%^GREEN%^The Pixie tries to sneak behind you but she fails!");
    tell_room(ETO,"%^GREEN%^The Pixie tries to sneak in behind "+targ->query_cap_name()+" but she fails!",targ);
    return 1;
}
void dust(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"spell")){
	tell_object(targ,"%^BOLD%^CYAN%^The Pixie throws some glittering dust into your eyes!");
	tell_room(ETO,"%^BOLD%^CYAN%^The Pixie throws some glittering dust into "+targ->query_cap_name()+"'s eyes!",targ);
	targ->set_paralyzed(30,"You are coughing and choking on the dust.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^CYAN%^The Pixie throws some glittering dust at you but it misses your eyes!");
    tell_room(ETO,"%^BOLD%^CYAN%^The Pixie throws some glittering dust at "+targ->query_cap_name()+" but it misses "+targ->query_possessive()+" eyes!",targ);
    return 1;
}
void reset(){
    object ob;
    ::reset();
    if(!present("scroll") && !random(3)) {
        ob=new("/d/magic/scroll");
        ob->set_spell(6);
        ob->move(TO);
    }
}
