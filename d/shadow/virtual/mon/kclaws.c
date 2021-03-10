#include <std.h>
//updated to reflect weapon standardization
inherit "/d/common/obj/weapon/claw";
int max;

void create(){
    ::create();
    set_name("claw");
    set_id(({"claw","scaled claw","black claw","blackscale claw","kyjahs claw","kyjah's claw"}));
    set_short("%^BOLD%^%^BLACK%^K%^BLUE%^y%^BLACK%^jah%^BLUE%^'%^BLACK%^s Bl%^BLUE%^a%^BLACK%^cksc%^BLUE%^a%^BLACK%^le Cl%^BLUE%^a%^BLACK%^w%^RESET%^");
    set_obvious_short("%^BOLD%^%^BLACK%^sc%^BLUE%^a%^BLACK%^le ed%^BLUE%^g%^BLACK%^ed bl%^BLUE%^a%^BLACK%^ck cl%^BLUE%^a%^BLACK%^w%^RESET%^");
    set_long("%^BOLD%^%^BLUE%^A glove made of very thin leather form the basis "
"of this weapon. While likely %^RESET%^kid %^BOLD%^%^BLUE%^or %^RESET%^"
"%^ORANGE%^doeskin%^BOLD%^%^BLUE%^, the texture and pale, %^BLACK%^ashy color "
"%^BLUE%^of the material leaves you wondering if it might be something less "
"savory. Over this leather, small diamond shaped %^BLACK%^scales %^BLUE%^have "
"been sewn, mimicking a lizard-like appearance. From the second knuckle on, "
"though, the glove gives way to thick talons of %^BLACK%^blackened steel%^BLUE%^"
", hollowed in the core to allow for the ends of the fingers and potentially "
"long nails or claws to fit comfortably within. The talons themselves are "
"slightly curved and wickedly sharp, with a slight %^RED%^serration %^BLUE%^on "
"the underside that makes them especially dangerous.%^RESET%^");
    set_lore("Kyjah Blackenedscale holds a special place within the tales of "
"the kobolds of the Echo Mountains. A black scaled kobold that stood almost "
"human height and had both strength and intelligence to rival the greatest of "
"dwarves, Kyjah is a folk hero whose fame included raiding the elven ruins of "
"Kippensurthi, stealing the famed glass blade of a thousand lucky souls from "
"the temple of Tymora, and as any kobold child knows, is the sole reason for "
"why kobolds have such divine cuisine. Though most consider Kyjah a fantasy tale"
", there is speculation that some of the epic tales of his heroics may be based "
"in truth, including the tale about him having extremely long claws that were "
"as sharp as steel.");
    set_property("lore difficulty",8);
//    set_wc(2,4);
//    set_large_wc(2,5);
//    set_weight(5);
//    set_size(2);
    set_value(400);
    set_wield((:TO,"wield_me":));
    set_unwield((:TO,"unwield_me":));
    set_hit((:TO,"hit_em":));
}

int hit_em(object targ){
    if(!objectp(targ)) return 5;
    if(!random(10)) {
        tell_room(environment(targ),"%^BOLD%^"+ETO->query_cap_name()+" quickly slashes "+targ->query_cap_name()+".",({targ,ETO}));
	tell_object(targ,"%^BOLD%^"+ETO->query_cap_name()+" quickly slashes you.");
	tell_object(ETO,"%^BOLD%^You slash "+targ->query_cap_name()+"!");
	targ->do_damage("torso",random(10));
	return random(6);
    }
    return 1;
}

int wield_me(){
    if((string)ETO->query_race() != "kobold") return 1;

    if((int)ETO->query_highest_level() > 5){

        max = (int)TP->query_highest_level()/7;
	if(max > 4) max = 4;
//	set_wc(2,3+max);
//	set_large_wc(2,4+max);
	remove_property("enchantment");
// making it grow a little slower *Styx*  2/20/05
    max = (int)TP->query_lowest_level()/7;
    if(max > 5) max = 5;
    set_property("enchantment", max);
	while(query_property("enchantment") < 1){
	    remove_property("enchantment");
	    set_property("enchantment", max);
          // dealing with an endless loop if max < 1. *Lujke* 9/3/10
          if (max<1){
            remove_property("enchantment");
            break;
          }
	}
    }
    return 1;
}

int unwield_me(){
    remove_property("enchantment");
//    set_wc(2,4);
//    set_large_wc(2,5);
    return 1;
}

void init(){
    ::init();
    if(TP == ETO){
        if((string)TP->query_race()=="kobold") set_ac(1);
	else {
	    remove_property("enchantment");
	    set_ac(0);
	//    set_wc(2,4);
	//    set_large_wc(2,5);
	}
    }
}

int save_me(string file){
    ::save_me(file);
    return 1;
}
