//Borrowed from Mercutio's Dream Area
#include <std.h>
inherit "/d/common/obj/weapon/mspear.c";

void create()
{
   ::create();
   set_name("smokey quartz spear");
   set_obvious_short("%^BOLD%^%^BLACK%^A smokey quartz tipped spear%^RESET%^");
	set_short("%^BOLD%^%^BLACK%^Shadowlancer Spear%^RESET%^");
   set_id(({"spear","smokey quartz spear","smokey quartz-tipped spear","medium spear"}));
   set_long("%^BLUE%^With its darkwood shaft, this spear takes"+
		" on a muted black color.  The darkwood shaft of the spear "+
		"has been carved with swirling bands that wrap from bottom "+
		"to top and polished smooth.  A %^MAGENTA%^darksteel%^BLUE%^"+
		" cap joins the shaft to the spearhead.  A diamond shaped chunk"+
		" of %^BOLD%^%^BLACK%^smokey quartz%^RESET%^%^BLUE%^ is fitted"+
		" inside the %^MAGENTA%^darksteel%^BLUE%^ cap, held tightly in "+
		"place.  The facets of the quartz have been sharpened with "+
		"skill, making an effective and deadly weapon.");
	set_lore("The Shadowlancer Spear was crafted for the play "+
		"'Piercing the Night'.  The play, written by an "+
		"anonymous author, centers around one young infantry "+
		"man moments before he heads into a battle.  As part "+
		"of the Night's Gloom Army, the young man Leopold tries"+
		" to search for the answers of why he is part of any army"+
		" posed to attack a citadel devoted to Lathander.  The "+
		"play on the surface level is a moral tale of how events in"+
		" each person's lives lead them on separate paths.  Though "+
		"searching deeper within the context of the play, some "+
		"scholars claim it contains a deeper and more disturbing "+
		"message. - Of Day and Night: Seven Plays - Virgil Ovid");
	set_property("lore",12);
   set_value(1000);
   set_hit((:TO,"hitme":));
   set_property("enchantment",2);
   set_item_bonus("attack bonus",1);
   set_item_bonus("damage bonus",1);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
}
int wield_func(string str) {
   if((int)ETO->query_level() < 13) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The spear seems far to heavy for you to lift.");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" can't even manage "+
		"to life the smokey quartz tip spear.");
	return 0;
}
   	tell_object(ETO,"%^MAGENTA%^The spear seems light and well balanced in your hand.");
   	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" lifts a smokey quartz tip "+
		"spear with ease.",ETO);
   	return 1;
}
int unwield_func(string str) {
   	tell_object(ETO,"%^MAGENTA%^You set your spear aside for now.");
   	tell_room(environment(ETO),"%^MAGENTA%^"+ETO->QCN+"'s "+
      	"fingers unwrap from the darkwood shaft of the spear.",ETO);
   	return 1;
}

int hitme(object targ)
{
   if(!random(8)) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^You thrust the tip of the spear into "+targ->QCN+".");
      tell_object(targ,"%^BOLD%^%^BLACK%^"+ETO->QCN+" thrusts the quartz tip"+
      	" of "+ETO->QP+" spear into you!");
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" thrusts the"+
      	" quartz tip of "+ETO->QP+" spear into "+targ->QCN+".",({ETO,targ}));
	  targ->cause_typed_damage(targ, "torso", roll_dice(1, 2) + 1, "piercing");
      return 1;
   }
   if(!random(16)) {
      tell_object(ETO,"%^MAGENTA%^The smokey quartz tip of the spear"+
		" glows with a %^BOLD%^%^BLACK%^dark aura%^RESET%^%^MAGENTA%^"+
		" as you pierce "+targ->QCN+"'s flesh.");
      tell_object(targ,"%^MAGENTA%^The smokey quartz tip of "+ETO->QCN+"'s"+
		" glows with a %^BOLD%^%^BLACK%^dark aura%^RESET%^%^MAGENTA%^"+
		" just before it pierces your flesh!\n%^BOLD%^%^BLACK%^You feel"+
		" the smokey quartz drain a portion of your life.");
      tell_room(environment(ETO),"%^MAGENTA%^The smokey quartz tip of "+
		""+ETO->QCN+"'s glows with a %^BOLD%^%^BLACK%^dark aura"+
		"%^RESET%^%^MAGENTA%^ just before it pierces "+targ->QCN+"'s"+
		" flesh.",({ETO,targ}));
	  targ->cause_typed_damage(targ, "torso", roll_dice(1, 5) + 1, "piercing");
  	return 1;
   }
}
