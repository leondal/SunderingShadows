#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("shard of darkness");
	set_id(({ "ring of protection", "ring", "ring of the void", "ring of darkness", "void ring" }));
	set_short("%^RESET%^%^BLUE%^R%^BOLD%^i%^BLACK%^n%^RESET%^%^BLUE%^g %^BOLD%^o%^RESET%^%^BLUE%^f t%^BOLD%^%^BLACK%^h%^RESET%^%^BLUE%^e V%^BOLD%^o%^BLACK%^i%^RESET%^%^BLUE%^d%^RESET%^");
	set_obvious_short("%^RESET%^%^BLUE%^a ring forged of d%^BOLD%^a%^BLACK%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^BLUE%^ss%^RESET%^");
	set_long("%^BOLD%^%^BLUE%^There is nothing to this ring, and yet you can feel it against your flesh.  Peering down into it, only the "
"faintest glimmer of %^RESET%^%^MAGENTA%^amethyst %^BOLD%^%^BLUE%^can be seen, so dark that it seems like a ring of blood buried deep within "
"the nothingness of the ring's %^RESET%^%^BLUE%^void%^BOLD%^.  Though you would expect it to be cold, the ring only leeches away all %^RESET%^"
"%^ORANGE%^feeling%^BOLD%^%^BLUE%^, leaving you with nothing.  Neither feeling, nor thought, but the single goal that laid within your mind "
"when you donned this bit of the %^RESET%^%^BLUE%^void.%^RESET%^");
	set_weight(5);
   set_value(0);
	set_lore("%^RED%^Remembered from an ancient journal:%^RESET%^  The light of the heavens snuffed out as the dark bolt struck the Golden "
"Stag, General ta'marni.  Above the battle, the witch Drutok'tre laughed and ordered her forces forward, sending bands of darkness down to "
"strengthen each in turn.  Though far fewer then began, the hoards of Dresttel surged with renewed vigor, but the anger and sorrow of the "
"Inomor, seeing their great leader dead, filled the very land with sorrow.  Such sorrow that even the vegetation felt their pain and rose up, "
"surrounding and trapping the Dresttel, dragging them down into the earth until nothing but the dark bands upon their hands remained to remind "
"the Inomor warriors where their enemies had once stood.");
	set_property("lore difficulty",23);
	set_type("ring");
	set_limbs(({ "right hand", "left hand" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("damage bonus",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_func()
{
	object *inven=({});
	int i;
	if(!objectp(ETO)) { return 0; }

	inven = ETO->all_armour();
	if(sizeof(inven))
	{
		for(i=0;i<sizeof(inven);i++)
		{
			if(!objectp(inven[i])) { continue; }
			if(inven[i]->id("ring of protection"))
			{
				tell_object(ETO,"%^RESET%^%^BOLD%^The magic of the ring already worn prevents you from wearing this one.");
				return 0;
			}
		}
	}
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^You slide the ring upon your finger and the void begins to fill you, casting aside all but the one thing that you seek.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLUE%^The world seems to come back into focus as though you were surfacing from a great depth.  As you draw in a deep breath you look down to see a small dark ring laying in your palm.  Where did that come from?%^RESET%^");
	return 1;
}