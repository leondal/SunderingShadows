// a large torc breastplate that has lively spikes -hades 4/11
#include <std.h>
#include <daemons.h>
inherit "/d/common/obj/armour/breastplate.c";


void create(){
    ::create();
    set_name("%^RESET%^%^GREEN%^d%^BOLD%^i%^RESET%^%^GREEN%^no breastplate");
    set_id(({ "breastplate", "armor","dino breastplate" }));
    set_short("%^RESET%^%^GREEN%^dino breastplate%^RESET%^");
    set_obvious_short("%^RESET%^%^GREEN%^spiked breastplate%^RESET%^");
    set_long("%^GREEN%^This strange armor looks "+
	"to be made from the hide of some huge "+
	"%^RESET%^dinosaur%^GREEN%^.  Bone %^RESET%^"+
	"spikes%^GREEN%^ protrude out of green scales"+
	" all across the chest and back of the huge "+
	"armor.  The base of the spikes have several"+
	" %^BOLD%^%^BLACK%^black runes%^RESET%^%^GREEN%^"+
	" carved all alone each one.  They almost seem "+
	"to move on their own.  Only a giant would be "+
	"able to wear such a large item of armor.%^RESET%^");
    set_value(5000);
    set_property("lore difficulty",30);
    set_lore("Harvested from dinosaurs, this breastplate"+
	" is crafted from mostly bone and scales.  The runes"+
	" on the spikes seem to be some kind of transmutation"+
	" magic.  It is almost as if this bit of bone and hide"+
	" is not completely dead, but still alive "+
	"in some magical fashion." );
    set_size(3);
    set_property("enchantment",3+random(2));
    set_wear((:TO,"wear_func":));
    set_remove((:TO,"remove_func":));
    set_struck((:TO,"strike_func":));
}
int wear_func(){
      if(!objectp(ETO)) return 1;
      if(!objectp(EETO)) return 1;
 
       tell_room(environment(ETO),"%^GREEN%^"
           +ETOQCN+" dons"+
        " the spiked armor making "+ETO->QO+""+
        " them look tribal.",ETO);
        tell_object(ETO,"%^GREEN%^you don the dino "+
        "breastplate around your body.");       
        return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^GREEN%^As "+ETOQCN+
        "removes "+ETO->QP+" scaled breastplate they look more civilized.",ETO);
        tell_object(ETO,"%^GREEN%^You remove your"+
                " armor and feel a little less barbaric.");
        return 1;
}
int strike_func(int damage, object what, object who){
if(!objectp(ETO)) return 1;
     
       if(random(500) < 100){
        tell_room(environment(query_worn()),"%^BOLD%^For"+
        " a moment "+who->QCN+" looks surprised"+
        " by "+ETOQCN+"'s armor, the spikes impale into "+
        who->QCN,({ETO,who}));
        tell_object(ETO,"%^BOLD%^The spikes on your armor extend"+
        " and impale"+
        " "+who->QCN+" when they get too close.");
        tell_object(who,"%^BOLD%^"+ETOQCN+"'s"+
        " extend and impale you!.");
        who->do_damage(random(6)+3);
         return 0;
      }
}
 int is_metal() { return 0; }//fer druish
