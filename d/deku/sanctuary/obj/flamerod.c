//Updated to bring in line with area difficulty - Octothorpe 4/15/10

#include <std.h>
inherit "/d/common/obj/weapon/club.c";

void create(){
	::create();
	set_name("flame rod");
	set_id(({ "rod", "flame rod" }));
	set_short("%^BOLD%^%^RED%^Fl%^YELLOW%^ame R%^RED%^od%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A %^BLACK%^scorched%^RED%^ piece of metal%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^This bit of %^BLACK%^scorched blackened%^RED%^ metal appears to once have been a rod, or sorts.  The warm metal of the rod seems warped and melted in some places.  The once brilliant steel is now black and scorched.  The rod still seems as if has enough heft to it to use in battle, bashing ones foes upside the head with  it.  The ends of the rod are nothing more than a lump of melted metal that has cooled.

AVATAR
	);
	set_weight(5);
	set_value(1100);
	set_lore(
@AVATAR
The Flame Rod was first crafted by an overambitious priest of Kossuuth.  Soon he flooded the lands with these rods.  Though they are quite powerful in combat, there was one serious flaw he overlooked.  The metal he used could not withstand the heat, and thus his rods are doomed to melt and warp after continuous use.

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
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" appears to be sweating slightly.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You can feel a warmth inside the metal rod.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->query_cap_name()+" pokes at a bit of slightly burnt flesh on "+ETO->query_possessive()+" hand.",ETO);
	tell_object(ETO,"%^RED%^You release your hold of the rod, noticing a slight burn on your hand.");
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
        default:
            tell_room(environment(ETO),"%^BOLD%^%^RED%^A burst of"+
                " flame envelops "+ETO->QCN+"'s metal rod, "+
                " scorching "+targ->QCN+".",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^The head of the rod suddenly"+
                " bursts out in flames, allowing you to add an extra"+
                " punch to your attack against "+targ->QCN+".");
            tell_object(targ,"%^RED%^"+ETO->QCN+" singes"+
                " you with the flames on the end of "+ETO->QP+" rod.");
            targ->do_damage("torso",random(5)+2);
            break;
        
        case 52..60:
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" "+
                "shoots a jet of flame out of "+ETO->QP+" rod, aiming"+
                " the flames at "+targ->QCN+".",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^Jets of flame shoot out of "+
                "your rod, covering "+targ->QCN+".");
            tell_object(targ,"%^RED%^"+ETO->QCN+" shoots a jet of flame "+
                "out of "+ETO->QP+" rod, covering you with the fires!");
            new("/cmds/spells/b/_burning_hands")->use_spell(ETO,targ,20,100,"mage");
            break;
        
        case 61..64:
            tell_room(environment(ETO),"%^BOLD%^%^RED%^"+ETO->QCN+" "+
                "blankets "+targ->QCN+" in a sheet of fire",({ETO,targ}));
            tell_object(ETO,"%^BOLD%^%^RED%^You blanket "+targ->QCN+" with"+
                " a sheet of fire.");
            tell_object(targ,"%^RED%^"+ETO->QCN+" blankets you with a"+
                " sheet of fire!");
            new("/cmds/cmds/s/_scorcher")->use_spell(ETO,targ,20,100,"mage");
            break;
        }
        return 1;
    }
}
