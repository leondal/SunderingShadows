//worker3.c - Generic workers to be introduced when making additions
//or changes to temples and other places.  Circe 12/31/03
#include <std.h>
inherit MONSTER;

int head_home;

void create()
{
	::create();
	set_name("gnomish worker");
	set_short("A gnomish craftsman");
	set_id(({"worker","gnomish worker","gnomish craftsman","craftsman"}));
	set_long(
         "This small gnome is outfitted in a garish ensemble that only a "+
         "gnome could love.  He wears brilliant yellow leggings underneath "+
         "a patchwork coat of every color known to gnomes.  Perched atop his "+
         "forehead is a pair of goggles he often pulls down as he examines the "+
         "stone around him.  He wears many jewels, set within all manner of "+
         "rings, necklaces, and bracelets.  He carries no tools with him, but "+
         "seems to have a keen memory."
	);
	set_gender("male");
	set_race("gnome");
	set_body_type("humanoid");
      set_size(1);
	set_hd(3,2);
	set_exp(10);
	set_emotes(2,({
	"The gnome mutters and nods, clearly speaking to himself.",
	"The gnomish craftsmen pauses in his work to enjoy a handful of berries.",
	"The gnome grins brightly to himself and nods rapidly as he studies a bit of stone.",
	"The gnomish craftsman lowers his goggles and studies the area thoughtfully.",	
	}),0);
	call_out("head_home",400+random(100));
}

int head_home()
{
	tell_room(ETO,"%^BOLD%^%^GREEN%^The gnomish craftsman grins and lowers his goggles before leaving.");
	TO->move("/d/shadowgate/void");
	destruct(TO);
	return 1;
}
