//Coded by Bane//
#include <std.h>
inherit WEAPON;
void create(){
    ::create();
    set_id(({"trident","trident of atlantis","atlantis"}));
    set_name("Trident of Atlantis");
    set_short("A Trident of Atlantis");
   set_obvious_short("A trident");
   set("lore",
	"This is a massive trident.  Forged of some indestructable ore, it "+
	"glitters like gold yet cuts through steel as though it was "+
	"paper.  The weapon is masterfully etched and carved with "+
	"ancient runes and designs."
    );
   set_long("  This three pronged spear looks very vicious.  The center tine is longer than the side two which are horribly barbed.");
    set_size(3);
    set_weight(20);
    set_value(5000);
    set_wc(1,6);
    set_large_wc(3,4);
    set_type("piercing");
    set_prof_type("fork");
    set_property("enchantment",4);
    set_hit( (:TO,"extra_hit":) );
}
int extra_hit(object ob){
    int roll;
    roll=random(100)+1;
    if(roll > 59 && roll < 71){
	tell_object(ob,"%^BOLD%^The trident guts you!");
        tell_room(environment(query_wielded()),"%^BOLD%^The trident guts "+ob->query_cap_name()+"!",ob);
	ob->do_damage(ob->return_target_limb(),roll_dice(1,8));
    }
    if(roll > 70 && roll < 91){
	tell_object(ob,"%^BLUE%^The trident slams into you with the power of a tsunami!");
        tell_room(environment(query_wielded()),"%^BLUE%^The trident slams into "+ob->query_cap_name()+" with the power of a tsunami!",ob);
	ob->do_damage(ob->return_target_limb(),roll_dice(1,10));
    }
    if(roll > 66 && roll < 74){
	tell_object(ob,"%^CYAN%^The trident sends a powerful poison into your body!");
        tell_room(environment(query_wielded()),"%^CYAN%^The trident stabs into "+ob->query_cap_name()+"!",ob);
	ob->set_paralyzed(20,"The poison holds your body stiff.");
    }
    if(roll > 96){
	tell_object(ob,"%^BOLD%^MAGENTA%^As the trident cuts into you it glows brightly and the sound of ancient chanting booms into your head!");
       tell_room(environment(query_wielded()),"%^BOLD%^MAGENTA%^As the trident cuts into "+ob->query_cap_name()+" the sound of ancient chanting booms into your head!",ob);
        new("/cmds/spells/c/_cone_of_cold")->use_spell(ETO,ob,10,100,"mage");
    }
}
