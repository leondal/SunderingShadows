//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/mclub.c";

void create(){
	::create();
	set_name("rod of frost");
	set_id(({ "rod", "frost rod" }));
	set_short("%^BOLD%^%^CYAN%^Rod of %^WHITE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^An %^WHITE%^ice%^CYAN%^ coated"+
		" rod");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^What appears to be an ice coated rod, your quickly realize is actually made entirely out of ice.  This slim rod is about a foot in length and very slender.  The ice has been shaped till it's smooth as glass, causing the light to refract off of it. The end of the ice rod has been rounded off.

AVATAR
	);
	set_weight(5);
	set_value(1100);
	set_lore(
@AVATAR
The Rod of Frost was first created by fanatical followers of Auril who wished to try to keep a portion of their goddess' winter chill with them where ever they went.  Since their perfection of keeping the ice from melting, these rods have found their hands into many bandits, thugs, and even a few priests.  Followers of Istishia find the rods interesting, because of the connection to their god's element.

AVATAR
	);
	set_property("lore",12);
	set_property("enchantment",3+random(2));
      set_item_bonus("attack bonus",1);
      set_item_bonus("damage bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" shivers.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^A chill travels down your spine as you wield the rod.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+" pauses to inspect "+ETO->query_possessive()+" hands.",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^After releasing the rod, you marvel at how the ice caused no damage to your hand.");
	return 1;
}
int hit_func(object targ)
{
	if(!objectp(TO)) return 1;
   	if(!objectp(ETO)) return 1;
   	if(!objectp(targ)) return 1;
    if(random(1000) < 200)
    {
        switch(random(65))
        {

            case 0..51:
                tell_room(environment(ETO),"%^BOLD%^%^CYAN%^The tempreture"+
                " suddenly drops as the air grows much colder.  "+ETO->QCN+""+
                " points towards "+targ->QCN+" and a blast of arctic frost"+
                " slams into "+targ->QS+".",({ETO,targ}));
                tell_object(ETO,"%^BOLD%^%^CYAN%^You manage to direct a chilling"+
                " beam of frost into "+targ->QCN+".");
                tell_object(targ,"%^BOLD%^%^CYAN%^The tempreture suddenly "+
                "drops as the air grows much colder.  "+ETO->QCN+" "+
                "points towards you, hitting you with a blast of arctic chill.");
                return roll_dice(2,4)+1;	
                break;
            case 52..60:
                tell_room(environment(ETO),"%^BOLD%^"+ETO->QP+" showers "+
                ""+targ->QCN+" with shards of ice.",({ETO,targ}));
                tell_object(ETO,"%^BOLD%^Shard of ice fly out of your rod"+
                " and into "+targ->QCN+".");
                tell_object(targ,"%^BOLD%^"+ETO->QCN+" showers you with shards of ice!");
                new("/cmds/spells/f/_frost_fingers")->use_spell(ETO,targ,20,100,"mage");
                break;
            case 61..64:
                tell_room(environment(ETO),"%^BOLD%^%^CYAN%^A whirling mass of snow"+
                " and ice shoots of out "+ETO->QCN+"'s rod, and slams "+
                "into "+targ->QCN+".",({ETO,targ}));
                tell_object(ETO,"%^BOLD%^%^CYAN%^A swirling mass of snow and ice"+
                " shoots out of your rod and slams into "+targ->QCN+".");
                tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+" shoots a swirling "+
                "mass of snow and ice out of "+ETO->QP+" rod, which slams into you!");
                new("/cmds/spells/c/_cone_of_cold")->use_spell(ETO,targ,20,100,"mage");
                break;
        }
    }
    return 0;
}
