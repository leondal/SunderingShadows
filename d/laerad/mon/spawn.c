//Coded by Bane//
#include <std.h>
#include <daemons.h>
//
// inherit "/d/laerad/mon/wander/illwander.c";
inherit WEAPONLESS;
void growth();
void mutate();
int flag, count, evolve, regen, oversized, atts, extras, ac, stoned, heal, tents, exploder, i;
object ob, *classes, *attlimbs;
void create(){
    ::create();
    set_id(({"spawn"}));
    set_name("baby spawn");
    set_short("A baby Spawn");
    set_long(
	"This is a baby spawn creature.  Similar to a dog in appearance, it stands "+
	"on four legs with nasty claws.  It's leathery skin wraps around its "+
	"bones.  A stubby tail pokes out from behind it.  Six eyes wrap half way "+
	"around its head and long fangs reach out of its mouth.  The creature is "+
	"surrounded in an erie green flame that doesnt appear to generate any "+
	"heat."
    );
    set_property("wandermon", 1);
    set_body_type("quadruped");
    set_race("spawn");
    set_gender("neuter");
    set_class("fighter");
    set_size(1);
    if(oversized) set_size(3);
    set_hd(random(5) + 5, 10);
    set_hp(random(40) + 60);
    if(oversized) set_hp(random(80) + 120);
    ac = 0;
    if(stoned) ac -= 2;
    set_overall_ac(ac);
    set_exp(query_hd() * 100);
    set_mob_magic_resistance("average");
    set("aggressive",10);
    set_stats("strength",19);
    set_base_damage_type("slashing");
    set_attack_limbs(({"right forepaw","left forepaw","head"}));
    attlimbs = (string *)TO->query_attack_limbs();
    if(tents) attlimbs += ({"right tentacle","left tentacle"});
    set_attack_limbs(attlimbs);
    atts = 3;
    if(extras) atts += 2;
    set_attacks_num(atts);
    set_damage(1,6);
    flag = 1;
    set_speed(15);
}
void reset()
{
    if(!objectp(TO)) { return; }
    if(!objectp(ETO)) { return; }
    ::reset();
    growth();
}
void growth(){
    switch(flag){
    case(0):
        flag = 1;
        break;
    case(1):
	tell_room(ETO,"The Spawn appears to grow in size.");
	set_name("small spawn");
	set_short("A small Spawn");
	set_long(
	    "This is a rather small spawn creature.  Similar to a dog in "+
	    "appearance, it stands on six legs with nasty claws.  It's leathery "+
	    "skin wraps around its bones.  A stubby tail pokes out from behind "+
	    "it.  Six eyes wrap half way around its head and long fangs "+
	    "reach out of its mouth.  The creature is surrounded in an erie "+
	    "flame that doesnt appear to generate any heat."
	);
	add_limb("right middle foreleg","torso",0,0,0);
	add_limb("left middle foreleg","torso",0,0,0);
	add_limb("right middle forepaw","right middle foreleg",0,0,0);
	add_limb("left middle forepaw","left middle foreleg",0,0,0);
	set_hd(random(5) + 10, 10);
	set_hp(random(40) + 90);
	if(oversized) set_hp(random(80) + 180);
	classes = TO->query_classes();
	for(i=0;i<sizeof(classes);i++){
	    set_mlevel(classes[i],query_hd());
	    set_guild_level(classes[i],query_hd());
	}
	ac = -3;
	if(stoned) ac -= 4;
	set_overall_ac(ac);
	set_exp(query_hd() * 150);
	set("aggressive",16);
	remove_property("magic resistance");
	set_mob_magic_resistance("average");
	atts = 4;
	if(extras) atts += 2;
	set_attacks_num(atts);
	set_attack_limbs(({"right forepaw","left forepaw","right middle forepaw","left middle forepaw","head"}));
        attlimbs = (string *)TO->query_attack_limbs();
        if(tents) attlimbs += ({"right tentacle","left tentacle"});
        set_attack_limbs(attlimbs);
	set_damage(1,8);
        flag = 2;
	break;
    case(2):
        tell_room(ETO,"The Spawn appears to grow in size.");
	set_name("mature spawn");
	set_short("A mature Spawn");
        set_long(
	    "This is a mature Spawn creature.  Similar to a dog in "+
	    "appearance, it stands on eight legs with nasty claws.  It's leathery "+
            "skin wraps around its bones.  A stubby tail pokes out from behind "+
            "it.  Six eyes wrap half way around its head and long fangs "+
            "reach out of its mouth.  The creature is surrounded in an erie "+
            "flame that doesnt appear to generate any heat."
        );
	add_limb("right hind leg","torso",0,0,0);
	add_limb("left hind leg","torso",0,0,0);
	add_limb("right hind paw","right hide leg",0,0,0);
	add_limb("left hind paw","left hind leg",0,0,0);
	set_hd(random(3) + 12, 10);
	set_hp(random(40) + 130);
	if(oversized) set_hp(random(80) + 260);
        classes = TO->query_classes();
        for(i=0;i<sizeof(classes);i++){
            set_mlevel(classes[i],query_hd());
            set_guild_level(classes[i],query_hd());
        }
	ac = -6;
	if(stoned) ac -= 4;
	set_overall_ac(ac);
	set_exp(query_hd() * 250);
	remove_property("magic resistance");
	set_mob_magic_resistance("average");
	set("aggressive",18);
	atts = 5;
	if(extras) atts += 2;
	set_attacks_num(atts);
	set_damage(1,10);
        flag = 3;
	break;
    case(3):
        tell_room(ETO,"The Spawn appears to grow in size.");
	set_name("adult spawn");
	set_short("An adult Spawn");
        set_long(
	    "This is an adult Spawn creature.  Similar to a dog in "+
	    "appearance, it stands on eight legs with nasty claws.  It's leathery "+
            "skin wraps around its bones.  A stubby tail pokes out from behind "+
            "it.  Six eyes wrap half way around its head and long fangs "+
            "reach out of its mouth.  The creature is surrounded in an erie "+
            "flame that doesnt appear to generate any heat."
        );
	set_hd(random(3) + 17, 10);
	set_hp(random(50) + 200);
	if(oversized) set_hp(random(100) + 400);
        classes = TO->query_classes();
        for(i=0;i<sizeof(classes);i++){
            set_mlevel(classes[i],query_hd());
            set_guild_level(classes[i],query_hd());
        }
	ac = -10;
	if(stoned) ac -= 5;
	set_overall_ac(ac);
	set_exp(query_hd() *  500);
	set("aggressive",20);
	remove_property("magic resistance");
	set_mob_magic_resistance("average");
	atts = 6;
	if(extras) atts += 2;
	set_attacks_num(atts);
	set_damage(1,12);
        flag = 4;
	break;
    case(4):
        tell_room(ETO,"The Spawn appears to grow in size.");
	set_name("old spawn");
	set_short("An old Spawn");
        set_long(
	    "This is an old Spawn creature.  Similar to a dog in "+
	    "appearance, it stands on eight legs with nasty claws.  It's leathery "+
            "skin wraps around its bones.  A stubby tail pokes out from behind "+
            "it.  Six eyes wrap half way around its head and long fangs "+
            "reach out of its mouth.  The creature is surrounded in an erie "+
            "flame that doesnt appear to generate any heat."
        );
        set_hd(random(5) + 10, 10);
        set_hp(random(40) + 90);
	if(oversized) set_hp(random(80) + 180);
        classes = TO->query_classes();
        for(i=0;i<sizeof(classes);i++){
            set_mlevel(classes[i],query_hd());
            set_guild_level(classes[i],query_hd());
        }
	ac = -3;
	if(stoned) ac -= 4;
	set_overall_ac(ac);
        set_exp(query_hd() * 150);
	remove_property("magic resistance");
	set_mob_magic_resistance("average");
	atts = 4;
	if(extras) atts += 2;
	set_attacks_num(atts);
	set_damage(1,6);
        flag = 5;
	break;
    case(5):
	tell_room(ETO,"The Spawn lies down and dies of old age.");
	TO->die();
	break;
    }
}
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return; // heart_beat error in debug, so added checks - Ares 
    if(regen == 1){
	if(TO->query_hp() < TO->query_max_hp()){
	    TO->add_hp(1);
	}
    }
    if(heal && TO->query_hp() < 50 && random(20) < 3){
	new("/cmds/spells/h/_heal")->use_spell(TO,TO,20,100,"mage");
    }
    if(flag == 3){
	if(count > 80){
	    if(random(20) < 5){
		tell_room(ETO,"The Spawn cries out in agony as it gives birth to new life.");
		ob = new("/d/laerad/mon/spawn");
		ob->move(ETO);
		ob->set_evolve(evolve + 1);
	    }
	    count = 0;
	}
	count++;
    }
}
void set_evolve(int x){
    evolve = x;
    if(evolve > 4){
	mutate();
    }
    if(evolve > 6){
	mutate();
    }
    if(evolve > 9){
	mutate();
    }
}
void mutate(){
    int mutations;
    mutations = random(10);
    switch(mutations){
	case(0):
	    add_limb("right tentacle","torso",0,0,0);
	    add_limb("left tentacle","torso",0,0,0);
            attlimbs = (string *)TO->query_attack_limbs();
            attlimbs += ({"left tentacle","right tentacle"});
            set_attack_limbs(attlimbs);
	    atts += 2;
	    set_attacks_num(atts);
	    extras = 1;
	    tents = 1;
	    break;
	case(1):
	    set_funcs(({"breath"}));
	    set_func_chance(25);
	    break;
	case(2):
	    set_attack_bonus(3);
	    break;
	case(3):
	    set_class("mage");
	    set_mlevel("mage",query_hd());
	    set_guild_level("mage",query_hd());
	    set_spells(({
		"lightning bolt",
		"fireball",
		"powerword stun",
		"prismatic spray",
		"magic missile",
	    }));
	    set_spell_chance(25);
	    break;
	case(4):
	    set_class("cleric");
	    set_mlevel("cleric",query_hd());
	    set_guild_level("cleric",query_hd());
	    set_spells(({
		"limb attack",
		"flamestrike",
	    }));
	    set_spell_chance(25);
	    break;
	case(5):
	    regen = 1;
	    break;
	case(6):
	    oversized = 1;
	    set_size(3);
	    break;
	case(7):
	    set_overall_ac(-2);
	    stoned = 1;
	    break;
	case(8):
	    heal = 1;
	    break;
	case(9):
	    exploder = 1;
	    break;
    }
}
void breath(object targ){
    tell_object(targ,"%^BOLD%^RED%^The Spawn breathes a cone of fire at you!");
    tell_room(ETO,"%^BOLD%^RED%^The Spawn breathes a cone of fire at "+targ->query_cap_name()+"!",targ);
    if(!SAVING_D->saving_throw(targ,"breath_weapon")){
	set_property("magic",1);
	targ->do_damage(targ->return_target_limb(),roll_dice(query_hd(),6));
	remove_property("magic");
	return 1;
	}
    set_property("magic",1);
    targ->do_damage(targ->return_target_limb(),roll_dice((query_hd()/2),6));
    remove_property("magic");
    return 1;
}
int query_evolve(){return evolve;}
void die(object ob){
    object *alive;
    alive = all_living(ETO);
    if(exploder){
	tell_room(ETO,"As the Spawn drops dead its body explodes!");
	for(i=0;i<sizeof(alive);i++){
	    set_property("magic",1);
	    alive[i]->do_damage(alive[i]->return_target_limb(),roll_dice(10,10));
	    alive[i]->add_attacker(TO);
	    remove_property("magic");
	}
    }
    return ::die(ob);
}
