//Added lore and flushed out the description a bit, also gave it an obvious short - Cythera 4/05\\
#include <std.h>
#include "../ruins.h"
inherit "/d/common/obj/weapon/lance.c";

int FLAG, OWNED;
string owner;

void create()
{
	::create();
	set_name("%^BOLD%^%^WHITE%^Pearl Lance%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Pearl Lance%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A white pearl lance%^RESET%^");
	set_id(({"lance","pearl lance","Pearl Lance"}));
	set_long(
	"%^BOLD%^%^BLUE%^This is a remarkable lance that is made entirely"+
		" out of %^WHITE%^pearl%^BLUE%^.  The lance shines in the "+
		"light, giving the room a %^WHITE%^white %^BLUE%^cast.  "+
		"Interwoven bands of %^WHITE%^white%^BLUE%^ and %^YELLOW%^"+
		"yellow%^BLUE%^ gold encircle the base of the lance.  This "+
		"noble looking lance is mounted onto a %^WHITE%^white gold%^BLUE%^"+
		" handle with %^WHITE%^pearl%^BLUE%^ inlays.  The hilt of the "+
		"lance's handle features a large %^WHITE%^pearl%^BLUE%^ that "+
		"shifts in hues of %^MAGENTA%^rose%^BLUE%^, %^WHITE%^white%^BLUE%^"+
		", %^CYAN%^sky blue%^BLUE%^, and %^YELLOW%^yellow%^BLUE%^."
	);
	set_lore("The Pearl Lance was once wielded by the Holy Lunar Knight"+
		" of Selune Yasmine Hathagard.  One of the first female knights,"+
		" Lady Yasmine found she not only had to overcome the forces of "+
		"darkness but also the misogynistic nature of most of her fellow "+
		"paladins.  Viewed as a lesser knight because of her gender and her"+
		" devotion to Selune, (who at that time was seen as a 'lesser deity'"+
		" among the Brotherhood of Paladins), Lady Yasmine had a very difficult"+
		" time trying to prove that women could be an effective knights."+
		"  If not for her devotion to Selune, who teaches her faithful about"+
		" the power of women, and her unbending will, Lady Yasmine might have"+
		" given up on her quest long ago.  For her dedication to her faith and "+
		"her mission, it is said that Selune herself blessed her favored knight"+
		" with a lance made of pearl.  In time Lady Yasmine was able to prove "+
		"herself a very capable paladin.  Though her respect was not granted "+
		"until she single handedly managed to rescue the Council of Twelve, "+
		"the leaders of the Paladin Council, from capture by the faiths of "+
		"Shar and Mask.  Though this tale is for another time. - The Power of"+
		" Women: The Teachings and Messages of Selune - Holly Golightly");
	set_property("lore",12);
	set_value(1000);
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_hit((:TO,"hitme":));
}

void init()
{
	::init();
	if(!interactive(ETO)) return;
	if(interactive(TP) && TP == environment(TO) && !OWNED) {
		owner = TPQN;
		OWNED = 1;
	}
}

int wieldme()
{
	if((string)TPQN != owner) {
		tell_object(ETO,"This lance does not belong to you.");
		return 0;
	}
   if(ETO->query_property("evil item")) {
      tell_object(ETO,"The lance refuses to be wielded while you are using such evil items!");
      return 0;
   }
	if(ETO->is_class("paladin")) {
		tell_object(ETO,"%^BOLD%^The Pearl Lance glows with a soft white light"+
		" as you wield it.");
		tell_room(environment(ETO),"%^BOLD%^The Pearl Lance glows with a soft"+
		" white light as "+ETO->QCN+" wields it.",ETO);
		FLAG = 1;
           ETO->set_property("magic",1);
      ETO->set_property("good item",1);
		return 1;
	}
	if(ETO->is_class("cavalier")) {
      ETO->set_property("good item",1);
		return 1;
	}
	tell_object(ETO,"This is a weapon for knights!");
	OWNED = 0;
	return 0;
}

int removeme()
{
	if(ETO->is_class("paladin")) {
		tell_object(ETO,"The %^BOLD%^Pearl Lance%^RESET%^ ceases its comforting glow.");
		tell_room(environment(ETO),"The Pearl Lance ceases its soft glow as"+
		" "+ETO->QCN+" releases it.",ETO);
             ETO->set_property("magic",-1);
      ETO->set_property("good item",-1);
		return 1;
	}
   ETO->set_property("good item",-1);
	return 1;
}

int hitme(object targ)
{
	object obx;
   ::check(targ);
   if(!objectp(ETO)) return 0;
   if(!objectp(targ)) return 0;
	if(!random(4)) {
		tell_object(ETO,"%^BOLD%^The Pearl Lance pierces "+targ->QCN+""+
		" sharply!");
		tell_object(targ,"%^BOLD%^"+ETO->QCN+" pierces you sharply"+
		" with "+ETO->QP+" Pearl Lance!");
		tell_room(environment(ETO),"%^BOLD%^"+ETO->QCN+" pierces"+
		" "+targ->QCN+" sharply with "+ETO->QP+""+
		" Pearl Lance!",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(2)+4);
		remove_property("magic");
		return 1;
	}
	if(!random(8)) {
		tell_object(ETO,"%^YELLOW%^The Pearl Lance seems to lend you strength"+
		" as you charge into "+targ->QCN+".");
		tell_object(targ,"%^YELLOW%^"+ETO->QCN+" charges into you"+
		" with full force!");
		tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" charges into"+
		" "+targ->QCN+" with full force!",({ETO,targ}));
		set_property("magic",1);
		targ->do_damage("torso",random(5)+4);
		remove_property("magic");
		return 1;
	}
	if(!random(12)) {
		if(targ->query_invis()) {
			tell_object(ETO,"%^BOLD%^%^CYAN%^The Pearl Lance shines with an"+
			" angry blue glow as it strikes the dishonorable "+targ->QCN+"!");
			tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
			" shines with a blue glow as it strikes "+targ->QCN+".",({ETO,targ}));
			tell_object(targ,"%^BOLD%^%^CYAN%^"+ETO->QCN+"'s Pearl"+
			" Lance shines with a blue glow as it strikes you!");
			if(present("invisobx999",targ)) {
				obx = present("invisobx999",targ);
				obx->show_up();
			}
			if(present("TSR80",targ)) {
				obx = present("TSR80",targ);
				obx->cancel_inv();
			}
			else if(targ->query_invis() && !wizardp(targ)) {
				targ->set_invis();
			}
			set_property("magic",1);
			targ->do_damage("torso",random(5)+15);
			remove_property("magic");
			return 1;
		}
		tell_object(ETO,"%^CYAN%^You pierce "+targ->QCN+" with"+
		" your Pearl Lance!");
		tell_object(targ,"%^CYAN%^"+ETO->QCN+" pierces you with"+
		" "+ETO->QP+" Pearl Lance!");
		set_property("magic",1);
		targ->do_damage("torso",random(5)+15);
		remove_property("magic");
		return 1;
	}
	if(!random(20) && FLAG == 1) {
		tell_object(ETO,"%^BOLD%^%^MAGENTA%^The Pearl Lance glows with a rosy"+
		" hue, refreshing your tired spirit.");
		tell_room(environment(ETO),"%^BOLD%^%^MAGENTA%^"+ETO->QCN+"'s Pearl"+
		" Lance glows with a rosy hue.",ETO);
		set_property("magic",1);
		ETO->do_damage("torso",(-1)*(random(5)+5));
		return 1;
		remove_property("magic");
	}
}

void set_owner(string str)
{
	owner = str;
	OWNED = 1;
}

int query_size() {
   if(objectp(ETO) && living(ETO))
      return (int)ETO->query_size();
   return ::query_size();
}
